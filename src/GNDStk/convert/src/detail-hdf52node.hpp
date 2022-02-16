
// -----------------------------------------------------------------------------
// HDF5attr2Node
// For HighFive::Attribute
// -----------------------------------------------------------------------------

// Helper: attrTYPE2node
template<class T, class NODE>
bool attrTYPE2node(const HighFive::Attribute &attr, NODE &node)
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

// HDF5attr2Node
template<class NODE>
bool HDF5attr2Node(const HighFive::Attribute &attr, NODE &node)
{
   // HighFive's documentation leaves much to be desired. I used what I found
   // in HighFive/include/highfive/bits/H5DataType_misc.hpp to get an idea of
   // what attribute *types* are allowed. That file also had some handling of
   // C-style fixed-length strings, as with char[length], and std::complex as
   // well. It didn't have long double, which I'd have liked, but that's fine.
   // I won't bother with fixed-length strings or with std::complex right now,
   // but will support the rest.
   if (attrTYPE2node<char              >(attr,node)) return true;
   if (attrTYPE2node<signed char       >(attr,node)) return true;
   if (attrTYPE2node<unsigned char     >(attr,node)) return true;
   if (attrTYPE2node<short             >(attr,node)) return true;
   if (attrTYPE2node<unsigned short    >(attr,node)) return true;
   if (attrTYPE2node<int               >(attr,node)) return true;
   if (attrTYPE2node<unsigned          >(attr,node)) return true;
   if (attrTYPE2node<long              >(attr,node)) return true;
   if (attrTYPE2node<unsigned long     >(attr,node)) return true;
   if (attrTYPE2node<long long         >(attr,node)) return true;
   if (attrTYPE2node<unsigned long long>(attr,node)) return true;
   if (attrTYPE2node<float             >(attr,node)) return true;
   if (attrTYPE2node<double            >(attr,node)) return true;
   if (attrTYPE2node<bool              >(attr,node)) return true;
   if (attrTYPE2node<std::string       >(attr,node)) return true;

   log::error(
     "HDF5 Attribute \"{}\"'s DataType \"{}\" is not handled at this time.",
      attr.getName(), attr.getDataType().string());
   log::function("HDF5attr2Node(HighFive::Attribute, Node)");

   return false;
}


// -----------------------------------------------------------------------------
// HDF5data2node
// For HighFive::DataSet
// -----------------------------------------------------------------------------

// Helper: dataTYPE2node
template<class T, class NODE>
bool dataTYPE2node(const HighFive::DataSet &data, NODE &node)
{
   if (data.getDataType() == HighFive::AtomicType<T>{}) {
      // Remarks as in the similar helper function attrTYPE2node()...
      const std::size_t dataSize = data.getElementCount();

      if (dataSize == 1) {
         T scalar;
         data.read(scalar);
         node.add("#pcdata").add("#text",scalar);
         return true;
      }

      if constexpr (!std::is_same_v<T,bool>) {
         std::vector<T> vector;
         vector.reserve(dataSize);
         data.read(vector);
         node.add("#pcdata").add("#text",vector);
         return true;
      }
   }

   return false;
}

// HDF5data2node
template<class NODE>
bool HDF5data2node(
   const HighFive::DataSet &data, const std::string &dataName,
   NODE &node
) {
   // node name
   node.name = dataName;

   // the data set's attributes
   for (auto &attrName : data.listAttributeNames())
      if (!HDF5attr2Node(data.getAttribute(attrName), node))
         return false;

   // the data set's data
   if (dataTYPE2node<char              >(data,node)) return true;
   if (dataTYPE2node<signed char       >(data,node)) return true;
   if (dataTYPE2node<unsigned char     >(data,node)) return true;
   if (dataTYPE2node<short             >(data,node)) return true;
   if (dataTYPE2node<unsigned short    >(data,node)) return true;
   if (dataTYPE2node<int               >(data,node)) return true;
   if (dataTYPE2node<unsigned          >(data,node)) return true;
   if (dataTYPE2node<long              >(data,node)) return true;
   if (dataTYPE2node<unsigned long     >(data,node)) return true;
   if (dataTYPE2node<long long         >(data,node)) return true;
   if (dataTYPE2node<unsigned long long>(data,node)) return true;
   if (dataTYPE2node<float             >(data,node)) return true;
   if (dataTYPE2node<double            >(data,node)) return true;
   if (dataTYPE2node<bool              >(data,node)) return true;
   if (dataTYPE2node<std::string       >(data,node)) return true;

   log::error(
     "HDF5 DataSet \"{}\"'s DataType \"{}\" is not handled at this time.",
      dataName, data.getDataType().string());
   log::function("HDF5data2node(HighFive::DataSet, dataName, Node)");

   return false;
}


// -----------------------------------------------------------------------------
// HDF52Node
// -----------------------------------------------------------------------------

// Helper: error_HDF52Node
inline void error_HDF52Node(const std::string &message)
{
   log::error(
     "Internal error in HDF52Node(HighFive::Group, std::string, Node):\n"
     "Message: \"{}\".",
      message
   );
   throw std::exception{};
}

// HDF52Node
template<class NODE>
bool HDF52Node(
   const HighFive::Group &group, const std::string &groupName,
   NODE &node, const bool requireEmpty = true
) {
   static const std::string context =
      "HDF52Node(HighFive::Group, std::string, Node)";

   // The node sent here should be fresh, ready to receive entries
   if (requireEmpty && !node.empty())
      error_HDF52Node("!node.empty()");

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

   // if "/" then attributes were handled, in a special way, by the caller
   if (groupName != "/")
      for (auto &attrName : group.listAttributeNames())
         if (!HDF5attr2Node(group.getAttribute(attrName), node))
            return false;

   // ------------------------
   // HDF5 sub-groups
   // ==> children
   // ------------------------

   for (auto &elemName : group.listObjectNames()) {
      switch (group.getObjectType(elemName)) {

         // File
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::File :
            error_HDF52Node("ObjectType \"File\" not expected here");
            break;

         // Group
         // ACTION: call the present function recursively
         case HighFive::ObjectType::Group :
            try {
               if (!HDF52Node(group.getGroup(elemName), elemName, node.add()))
                  return false;
            } catch (...) {
               log::function(context);
               throw;
            }
            break;

         // UserDataType
         // NOT HANDLED; perhaps we could provide something in the future
         case HighFive::ObjectType::UserDataType :
            error_HDF52Node("ObjectType \"UserDataType\" not handled");
            break;

         // DataSpace (not to be confused with Dataset)
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::DataSpace :
            error_HDF52Node("ObjectType \"DataSpace\" not expected here");
            break;

         // Dataset
         // ACTION: handle the DataSet's data
         case HighFive::ObjectType::Dataset :
            try {
               if (!HDF5data2node(
                  group.getDataSet(elemName),
                  elemName,
                  node.add()
               ))
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
            error_HDF52Node("ObjectType \"Attribute\" not expected here");
            break;

         // Other
         // NOT HANDLED; we're not sure when this would arise
         case HighFive::ObjectType::Other :
            error_HDF52Node("ObjectType \"Other\" not handled");
            break;

         // default
         // NOT HANDLED; presumably our switch has covered all bases already
         default:
            error_HDF52Node("ObjectType [unknown] not handled");
            break;

      } // switch
   } // for

   // done
   return true;
}
