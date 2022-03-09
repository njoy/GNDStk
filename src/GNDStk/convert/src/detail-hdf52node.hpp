
// Helper: error_hdf52node
inline void error_hdf52node(const std::string &message)
{
   log::error(
     "Internal error in hdf52node(HighFive::Group, std::string, Node):\n"
     "Message: \"{}\".",
      message
   );
   throw std::exception{};
}


// -----------------------------------------------------------------------------
// attr2node
// For HighFive::Attribute
// -----------------------------------------------------------------------------

// <T> helper
template<class T, class NODE>
bool attr2node(const HighFive::Attribute &attr, NODE &node)
{
   if (attr.getDataType() == HighFive::AtomicType<T>{}) {
      const std::string attrName = attr.getName();
      const std::size_t attrSize = attr.getSpace().getElementCount();

      // Scalar case. Includes bool.
      if (attrSize == 1) {
         T scalar;
         attr.read(scalar);
         node.add(attrName,scalar);
         return true;
      }

      // Vector case. EXcludes bool, as HighFive (perhaps HDF5 in general?)
      // doesn't appear to support it in this case. Indeed, the body of the
      // if-constexpr doesn't *compile* with bool. (Hence our if-constexpr.)
      if constexpr (!std::is_same_v<T,bool>) {
         std::vector<T> vector;
         vector.reserve(attrSize);
         attr.read(vector);
         node.add(attrName,vector);
         return true;
      }
   }

   return false;
}

// attr2node
template<class NODE>
bool attr2node(const HighFive::Attribute &attr, NODE &node)
{
   // HighFive's documentation leaves much to be desired. I used what I found
   // in HighFive/include/highfive/bits/H5DataType_misc.hpp to get an idea of
   // what attribute *types* are allowed. That file also had some handling of
   // C-style fixed-length strings, as with char[length], and std::complex as
   // well. It didn't have long double, which I'd have liked, but that's fine.
   // I won't bother with fixed-length strings or with std::complex right now,
   // but will support the rest.
   if (attr2node<char              >(attr,node)) return true;
   if (attr2node<signed char       >(attr,node)) return true;
   if (attr2node<unsigned char     >(attr,node)) return true;
   if (attr2node<short             >(attr,node)) return true;
   if (attr2node<unsigned short    >(attr,node)) return true;
   if (attr2node<int               >(attr,node)) return true;
   if (attr2node<unsigned          >(attr,node)) return true;
   if (attr2node<long              >(attr,node)) return true;
   if (attr2node<unsigned long     >(attr,node)) return true;
   if (attr2node<long long         >(attr,node)) return true;
   if (attr2node<unsigned long long>(attr,node)) return true;
   if (attr2node<float             >(attr,node)) return true;
   if (attr2node<double            >(attr,node)) return true;
   if (attr2node<bool              >(attr,node)) return true;
   if (attr2node<std::string       >(attr,node)) return true;

   log::error(
     "HDF5 Attribute \"{}\"'s DataType \"{}\" is not supported at this time.",
      attr.getName(), attr.getDataType().string());
   log::function("attr2node(HighFive::Attribute, Node)");

   return false;
}


// -----------------------------------------------------------------------------
// dset2node
// For HighFive::DataSet
// -----------------------------------------------------------------------------

// <T> helper
template<class T, class NODE>
bool dset2node(const HighFive::DataSet &dset, NODE &node)
{
   if (dset.getDataType() == HighFive::AtomicType<T>{}) {
      // Remarks as in the similar helper function attr2node()...
      const std::size_t dataSize = dset.getElementCount();

      if (dataSize == 1) {
         T scalar;
         dset.read(scalar);
         node.name == "#pcdata"
            ? node.add("#text",scalar)
            : node.add("#pcdata").add("#text",scalar);
         return true;
      }

      if constexpr (!std::is_same_v<T,bool>) {
         std::vector<T> vector;
         vector.reserve(dataSize);
         dset.read(vector);
         node.name == "#pcdata"
            ? node.add("#text",vector)
            : node.add("#pcdata").add("#text",vector);
         return true;
      }
   }

   return false;
}

// dset2node
template<class NODE>
bool dset2node(
   const HighFive::Group &group, const std::string &dsetName,
   NODE &parent
) {
   Node &node = parent.add(beginsin(dsetName,"#pcdata") ? "#pcdata" : dsetName);

   // the DataSet's attributes
   const HighFive::DataSet &dset = group.getDataSet(dsetName);
   for (const std::string &attrName : dset.listAttributeNames())
      if (!attr2node(dset.getAttribute(attrName), node))
         return false;

   // the DataSet's data
   if (dset2node<char              >(dset,node)) return true;
   if (dset2node<signed char       >(dset,node)) return true;
   if (dset2node<unsigned char     >(dset,node)) return true;
   if (dset2node<short             >(dset,node)) return true;
   if (dset2node<unsigned short    >(dset,node)) return true;
   if (dset2node<int               >(dset,node)) return true;
   if (dset2node<unsigned          >(dset,node)) return true;
   if (dset2node<long              >(dset,node)) return true;
   if (dset2node<unsigned long     >(dset,node)) return true;
   if (dset2node<long long         >(dset,node)) return true;
   if (dset2node<unsigned long long>(dset,node)) return true;
   if (dset2node<float             >(dset,node)) return true;
   if (dset2node<double            >(dset,node)) return true;
   if (dset2node<bool              >(dset,node)) return true;
   if (dset2node<std::string       >(dset,node)) return true;

   log::error(
     "HDF5 DataSet \"{}\"'s DataType \"{}\" is not supported at this time.",
      dsetName, dset.getDataType().string());
   log::function("dset2node(HighFive::DataSet, dsetName, Node)");

   return false;
}


// -----------------------------------------------------------------------------
// hdf52node
// -----------------------------------------------------------------------------

template<class NODE>
bool hdf52node(
   const HighFive::Group &group, const std::string &groupName,
   NODE &node, const bool requireEmpty = true
) {
   static const std::string context =
      "hdf52node(HighFive::Group, std::string, Node)";

   // the node sent here should be fresh, ready to receive entries...
   if (requireEmpty && !node.empty())
      error_hdf52node("!node.empty()");

   // ------------------------
   // HDF5 group name
   // ==> node name
   // ------------------------

   // if "/" then we're at the top-level node, which we call "" internally
   if (groupName != "/")
      node.name = groupName;

   // ------------------------
   // HDF5 attributes
   // ==> metadata
   // ------------------------

   // if "/", then attributes were handled, in a special way, by the caller
   if (groupName != "/") {
      for (const std::string &attrName : group.listAttributeNames()) {
         if (attrName == "#nodeName") {
            // #nodeName
            // Handled not as a regular attribute, but as the present node's
            // true name. The following line is basically a compressed version
            // of attr2node<std::string> (see early in this file). It assumes,
            // in short, that this #nodeName attribute is one (not a vector of)
            // T == std::string. And that's precisely what it should be, given
            // how GNDStk creates #nodeName attributes in the first place.
            group.getAttribute(attrName).read(node.name);
         } else if (beginsin(attrName,"#cdata")) {
            // #cdata, possibly with a numeric suffix
            // Expand into a child node #cdata with a #text attribute.
            std::string value;
            group.getAttribute(attrName).read(value);
            node.add("#cdata").add("#text",value);
         } else if (beginsin(attrName,"#comment")) {
            // #comment, possibly with a numeric suffix
            // Expand into a child node #comment with a #text attribute.
            std::string value;
            group.getAttribute(attrName).read(value);
            node.add("#comment").add("#text",value);
         } else {
            // Regular attribute
            // Create a metadatum. Note that this gives the correct result for
            // attributes with regular names, and also for attrName == "#text".
            if (!attr2node(group.getAttribute(attrName), node))
               return false;
         } // else if
      } // for
   } // if

   // ------------------------
   // HDF5 sub-groups
   // ==> children
   // ------------------------

   for (const std::string &elemName : group.listObjectNames()) {
      switch (group.getObjectType(elemName)) {

         // File
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::File :
            error_hdf52node("ObjectType \"File\" is not expected here");
            break;

         // Group
         // ACTION: Call the present function recursively
         case HighFive::ObjectType::Group :
            try {
               if (!hdf52node(group.getGroup(elemName), elemName, node.add()))
                  return false;
            } catch (...) {
               log::function(context);
               throw;
            }
            break;

         // UserDataType
         // NOT HANDLED; These may or may not ever be needed
         case HighFive::ObjectType::UserDataType :
            error_hdf52node("ObjectType \"UserDataType\" is not supported");
            break;

         // DataSpace (not to be confused with DataSet)
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::DataSpace :
            error_hdf52node("ObjectType \"DataSpace\" is not expected here");
            break;

         // DataSet
         // ACTION: Handle the DataSet's data
         // Note: HighFive actually calls the following Dataset (lower-case s),
         // not DataSet (upper-case S), but uses "DataSet" elsewhere. :-/
         case HighFive::ObjectType::Dataset :
            try {
               if (!dset2node(group,elemName,node))
                  return false;
            } catch (...) {
               log::function(context);
               throw;
            }
            break;

         // Attribute
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::Attribute :
            // group.listObjectNames() (used in the for-loop we're in right
            // now) apparently doesn't include attribute names - which is fine,
            // because we already handled attributes earlier. So, here, we just
            // produce an error if ObjectType::Attribute inexplicably made an
            // appearance here, where we don't expect it.
            error_hdf52node("ObjectType \"Attribute\" is not expected here");
            break;

         // Other
         // NOT HANDLED; We're not sure when this would arise
         case HighFive::ObjectType::Other :
            error_hdf52node("ObjectType \"Other\" is not supported");
            break;

         // default
         // NOT HANDLED; our switch() should have covered all bases
         default:
            error_hdf52node("ObjectType [unknown] is not supported");
            break;

      } // switch
   } // for

   // done
   return true;
}
