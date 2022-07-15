
namespace detail {

// -----------------------------------------------------------------------------
// For handles: container, find
// -----------------------------------------------------------------------------

// getAllHandles<CPP>
// Returns a container
template<class CPP>
auto &getAllHandles()
{
   static std::set<std::shared_ptr<CPP>> pointers;
   return pointers;
}

// findHandle<CPP,C>
// Returns an iterator
template<class CPP, class C>
auto findHandle(const C *const ptr)
{
   auto &pointers = getAllHandles<CPP>();

   return std::find_if(
      pointers.begin(), pointers.end(),
      [ptr](const std::shared_ptr<CPP> &shared)
      {
         return shared.get() == reinterpret_cast<const CPP *>(ptr);
      }
   );
}


// -----------------------------------------------------------------------------
// get, delete
// -----------------------------------------------------------------------------

// getNewHandle<CPP,C>
template<class CPP, class C>
C *getNewHandle()
{
   const std::shared_ptr<CPP> ptr = std::make_shared<CPP>();
   return reinterpret_cast<C *>(&(**getAllHandles<CPP>().insert(ptr).first));
}

// deleteHandle<CPP,C>
template<class CPP, class C>
void deleteHandle(const C *const ptr)
{
   auto &pointers = getAllHandles<CPP>();
   const auto iter = findHandle<CPP>(ptr);

   if (iter != pointers.end())
      pointers.erase(iter);
   else {
      log::warning(
        "Ignoring call to delete handle {}.\n"
        "Handle is not valid, or was already deleted.",
         reinterpret_cast<const void *>(ptr)
      );
   }
}


// -----------------------------------------------------------------------------
// assign
// -----------------------------------------------------------------------------

// assignHandle<CPP,C>
template<class CPP, class C>
C *assignHandle(C *const lhs, const C *const rhs)
{
   auto &pointers = getAllHandles<CPP>();

   /*
   // todo
   // Think about reasonable ways of doing the following that are compatible
   // with C, which (unlike C++) doesn't have references. Sending &handle is
   // an obvious option, but we may or may not care about doing this.

   // lhs: should be null or valid (if null, we'll create)
   if (lhs == nullptr) {
      // note that we need to cast away const for this
      std::cout << "creating from nullptr..." << std::endl;
      *const_cast<C **>(&lhs) = getNewHandle<CPP,C>();
   } else
   */

   static const std::string remark =
      "\nIgnoring the assignment and continuing (but you should"
      "\nprobably look into this, and fix something).";

   // check lhs
   if (findHandle<CPP>(lhs) == pointers.end()) {
      log::error(
        "Unknown handle on left side of assignment {} = ...." + remark,
         reinterpret_cast<const void *>(lhs)
      );
      return lhs;
   }

   // check rhs
   if (findHandle<CPP>(rhs) == pointers.end()) {
      log::error(
        "Unknown handle on right side of assignment ... = {}." + remark,
         reinterpret_cast<const void *>(rhs)
      );
      return lhs;
   }

   reinterpret_cast<CPP &>(*lhs) = reinterpret_cast<const CPP &>(*rhs);
   return lhs;
}

} // namespace detail
