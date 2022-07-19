
namespace detail {

// -----------------------------------------------------------------------------
// Helpers
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
// create, delete
// -----------------------------------------------------------------------------

// createHandle<CPP,C>
template<class CPP, class C, class... ARGS>
C *createHandle(ARGS &&...args)
{
   return reinterpret_cast<C *>(
      &(**getAllHandles<CPP>().insert(
           std::make_shared<CPP>(std::forward<ARGS>(args)...)
      ).first)
   );
}

// deleteHandle<CPP,C>
template<class CPP, class C>
void deleteHandle(
   const std::string &classname,
   const C *const ptr
) {
   auto &pointers = getAllHandles<CPP>();
   const auto iter = findHandle<CPP>(ptr);

   if (iter != pointers.end())
      pointers.erase(iter);
   else {
      log::warning(
        "Ignoring call to delete {} handle {}.\n"
        "Handle is not valid, or was already deleted.",
         classname, reinterpret_cast<const void *>(ptr)
      );
   }
}


// -----------------------------------------------------------------------------
// assign
// -----------------------------------------------------------------------------

// assignHandle<CPP,C>
template<class CPP, class C>
void assignHandle(
   const std::string &classname,
   C *const lhs, const C *const rhs
) {
   auto &pointers = getAllHandles<CPP>();

   /*
   // qqq
   // Think about reasonable ways of doing the following that are compatible
   // with C, which (unlike C++) doesn't have references. Sending &handle is
   // an obvious option, but we may or may not care about doing this.

   // lhs: should be null or valid (if null, we'll create)
   if (lhs == nullptr) {
      // note that we need to cast away const for this
      std::cout << "creating from nullptr..." << std::endl;
      *const_cast<C **>(&lhs) = createHandle<CPP,C>();
   } else
   */

   static const std::string remark =
      "\nIgnoring the assignment and continuing (but you should"
      "\nprobably look into this, and fix something).";

   // check lhs
   if (findHandle<CPP>(lhs) == pointers.end()) {
      log::error(
        "Unknown handle on left side of {} assignment {} = ...." + remark,
         classname, reinterpret_cast<const void *>(lhs)
      );
      return;
   }

   // check rhs
   if (findHandle<CPP>(rhs) == pointers.end()) {
      log::error(
        "Unknown handle on right side of {} assignment ... = {}." + remark,
         classname, reinterpret_cast<const void *>(rhs)
      );
      return;
   }

   reinterpret_cast<CPP &>(*lhs) = reinterpret_cast<const CPP &>(*rhs);
}


// -----------------------------------------------------------------------------
// read, write, print
// -----------------------------------------------------------------------------

// readHandle<CPP,C>
template<class CPP, class C>
int readHandle(
   const std::string &classname,
   C *const ptr, const std::string &filename
) {
   try {
      reinterpret_cast<CPP &>(*ptr).baseComponent().read(filename);
      return 1; // success
   } catch (...) {
      log::context(
        "C language function for reading {} from file. "
        "File name is \"{}\".", classname, filename
      );
      return 0; // failure
   }
}

// writeHandle<CPP,C>
template<class CPP, class C>
int writeHandle(
   const std::string &classname,
   const C *const ptr, const std::string &filename
) {
   try {
      reinterpret_cast<const CPP &>(*ptr).baseComponent().write(filename);
      return 1; // success
   } catch (...) {
      log::context(
         "C language function for writing {} to file.\n"
         "File name is \"{}\".", classname, filename
      );
      return 0; // failure
   }
}

// printHandle<CPP,C>
template<class CPP, class C>
int printHandle(
   const std::string &classname,
   const C *const ptr, const std::string &format = ""
) {
   try {
      if (format == "") {
         reinterpret_cast<const CPP &>(*ptr).
            baseComponent().print();
         // Component's print() already prints a newline
      } else {
         reinterpret_cast<const CPP &>(*ptr).
            baseComponent().write(std::cout,format);
         // Component's write() intentionally doesn't already print a newline.
         // For this print(), for our C language interface, print one.
         std::cout << std::endl;
      }
      return 1; // success
   } catch (...) {
      if (format == "")
         log::context(
           "C language function for printing {}.",
            classname);
      else
         log::context(
            "C language function for printing {} in {} format.",
            classname, format);
      return 0; // failure
   }
}

} // namespace detail
