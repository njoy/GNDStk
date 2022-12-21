
namespace detail {

// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// ------------------------
// tocpp
// ------------------------

// const
template<class CPP, class C>
const CPP &tocpp(const C *const This)
{
   if (This == nullptr) {
      log::error(
         "detail::tocpp(pointer to const): pointer is null; "
         "it cannot be dereferenced"
      );
      throw std::exception{};
   }
   return reinterpret_cast<const CPP &>(*This);
}

// non-const
template<class CPP, class C>
CPP &tocpp(C *const This)
{
   if (This == nullptr) {
      log::error(
         "detail::tocpp(pointer): pointer is null; "
         "it cannot be dereferenced"
      );
      throw std::exception{};
   }
   return reinterpret_cast<CPP &>(*This);
}

// ------------------------
// getAllHandles
// findHandle
// ------------------------

// getAllHandles<CPP>
// Returns a container
template<class CPP>
auto &getAllHandles()
{
   try {
      static std::set<std::shared_ptr<CPP>> pointers;
      return pointers;
   } catch (...) {
      log::error("Exception thrown in detail::getAllHandles()");
      throw;
   }
}

// findHandle<CPP,C>
// Returns an iterator
template<class CPP, class C>
auto findHandle(const C *const want)
{
   try {
      auto &pointers = getAllHandles<CPP>();
      return std::find_if(
         pointers.begin(), pointers.end(),
         [want](const std::shared_ptr<CPP> &have)
         {
            return have.get() == &tocpp<CPP>(want);
         }
      );
   } catch (...) {
      log::error("Exception thrown in detail::findHandle()");
      throw;
   }
}


// -----------------------------------------------------------------------------
// create, assign, delete
// -----------------------------------------------------------------------------

// createHandle<CPP,C>
template<class CPP, class C, class... ARGS>
C *createHandle(
   const std::string &classname,
   const std::string &funname,
   ARGS &&...args
) {
   try {
      return reinterpret_cast<C *>(
         &(**getAllHandles<CPP>().insert(
              std::make_shared<CPP>(std::forward<ARGS>(args)...)
         ).first)
      );
   } catch (...) {
      log::error("Unable to create {} handle", classname);
      log::function("{}", funname);
      return nullptr;
   }
}

// assignHandle<CPP,C>
template<class CPP, class C>
void assignHandle(
   const std::string &classname,
   const std::string &funname,
   C *const lhs, const C *const rhs
) {
   static const std::string remark =
      "\nIgnoring the assignment and continuing (but you should"
      "\nprobably look into this, and fix something).";

   static const std::string
      bothNull  = "The \"to\" and \"from\" {} handles are null." + remark,
      leftNull  = "The \"to\" {} handle is null." + remark,
      rightNull = "The \"from\" {} handle is null." + remark,
      leftUnk   = "Unknown \"to\" {} handle {}." + remark,
      rightUnk  = "Unknown \"from\" {} handle {}." + remark;

   try {
      auto &pointers = getAllHandles<CPP>();
      bool good = true;

      // nullptr anywhere?
      if (lhs == nullptr && rhs == nullptr) {
         good = false; log::error(bothNull,  classname);
      } else if (lhs == nullptr) {
         good = false; log::error(leftNull,  classname);
      } else if (rhs == nullptr) {
         good = false; log::error(rightNull, classname);
      }

      // check lhs
      if (lhs && findHandle<CPP>(lhs) == pointers.end()) {
         log::error(leftUnk,  classname, reinterpret_cast<const void *>(lhs));
         good = false;
      }

      // check rhs
      if (rhs && findHandle<CPP>(rhs) == pointers.end()) {
         log::error(rightUnk, classname, reinterpret_cast<const void *>(rhs));
         good = false;
      }

      if (!good)
         throw std::exception{};

      tocpp<CPP>(lhs) = tocpp<CPP>(rhs);

   } catch (...) {
      log::function("{}(to,from)", funname);
   }
}

// deleteHandle<CPP,C>
template<class CPP, class C>
void deleteHandle(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr
) {
   static const std::string ignore = "Ignoring call to delete {} handle {}.";

   if (ptr == nullptr) {
      log::warning(
         ignore + "\nHandle is null.",
         classname, reinterpret_cast<const void *>(ptr)
      );
      return;
   }

   try {
      auto &pointers = getAllHandles<CPP>();
      const auto iter = findHandle<CPP>(ptr);

      if (iter != pointers.end()) {
         pointers.erase(iter);
      } else {
         log::warning(
            ignore + "\nHandle is unknown, or was already deleted.",
            classname, reinterpret_cast<const void *>(ptr)
         );
      }
   } catch (...) {
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
   }
}


// -----------------------------------------------------------------------------
// read, write, print
// -----------------------------------------------------------------------------

// readHandle<CPP,C>
template<class CPP, class C>
int readHandle(
   const std::string &classname,
   const std::string &funname,
   C *const ptr, const std::string &filename
) {
   try {
      tocpp<CPP>(ptr).baseComponent().read(filename);
      return 1; // success
   } catch (...) {
      log::context(
         "C function for reading {} from file. "
         "File name is \"{}\".", classname, filename
      );
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
      return 0; // failure
   }
}

// writeHandle<CPP,C>
template<class CPP, class C>
int writeHandle(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr, const std::string &filename
) {
   try {
      tocpp<CPP>(ptr).baseComponent().write(filename);
      return 1; // success
   } catch (...) {
      log::context(
         "C function for writing {} to file.\n"
         "File name is \"{}\".", classname, filename
      );
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
      return 0; // failure
   }
}

// printHandle<CPP,C>
template<class CPP, class C>
int printHandle(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr, const std::string &format = ""
) {
   try {
      if (format == "") {
         tocpp<CPP>(ptr).baseComponent().print();
         // Component's print() already prints a newline
      } else {
         tocpp<CPP>(ptr).baseComponent().write(std::cout,format);
         // Component's write() intentionally doesn't already print a newline.
         // For this print(), for our C language interface, print one.
         std::cout << std::endl;
      }
      return 1; // success
   } catch (...) {
      if (format == "") {
         log::context(
            "C function for printing {}.", classname);
      } else {
         log::context(
            "C function for printing {} in {} format.", classname, format);
      }
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
      return 0; // failure
   }
}


// -----------------------------------------------------------------------------
// has, get, set
// -----------------------------------------------------------------------------

// hasField
template<class CPP, class C, class EXTRACT>
bool hasField(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr,
   const EXTRACT &extract
) {
   try {
      const auto &field = *extract(tocpp<CPP>(ptr));
      return field.has();
   } catch (...) {
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
      return false;
   }
}

// getField
template<class CPP, class HANDLE = void, class C, class EXTRACT>
auto getField(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr,
   const EXTRACT &extract
) {
   using T = std::decay_t<decltype(extract(tocpp<CPP>(ptr))->value())>;

   try {
      const auto &field = *extract(tocpp<CPP>(ptr));
      const T &ret = field.value(); // .value() gets us into any std::optional
      if constexpr (std::is_same_v<HANDLE,void>) {
         // metadatum
         if constexpr (std::is_same_v<T,std::string>) {
            return ret.c_str();
         } else {
            return ret;
         }
      } else {
         // child
         return (HANDLE)(&ret);
      }
   } catch (...) {
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
      if constexpr (std::is_same_v<HANDLE,void>) {
         // metadatum
         if constexpr (std::is_same_v<T,std::string>) {
            return "";
         } else {
            return T{};
         }
      } else {
         // child
         return (HANDLE)nullptr;
      }
   }
}

// setField
template<class CPP, class CLASS = void, class C, class EXTRACT, class T>
void setField(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const EXTRACT &extract,
   const T &newvalue
) {
   try {
      auto &field = *extract(tocpp<CPP>(ptr));
      if constexpr (std::is_same_v<CLASS,void>) {
         // metadatum
         field.replace(newvalue);
      } else {
         // child
         field.replace(tocpp<CLASS>(newvalue));
      }
   } catch (...) {
      log::function(
         "{}({} handle = {}, value)", funname, classname, (void *)ptr);
   }
}


// -----------------------------------------------------------------------------
// clear, size
// -----------------------------------------------------------------------------

// clearContainer
template<class CPP, class C, class EXTRACT>
void clearContainer(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const EXTRACT &extract
) {
   try {
      auto &container = (*extract(tocpp<CPP>(ptr)))();
      if constexpr (isOptional<decltype(container)>) {
         if (container)
            container->clear();
      } else
         container.clear();
   } catch (...) {
      log::error("Exception thrown in detail::clearContainer");
      log::function(
         "{}({} handle = {})", funname, classname, (void *)ptr);
   }
}

// sizeOfContainer
template<class CPP, class C, class EXTRACT>
size_t sizeOfContainer(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const EXTRACT &extract
) {
   try {
      auto &container = (*extract(tocpp<CPP>(ptr)))();
      if constexpr (isOptional<decltype(container)>)
         return container ? container->size() : 0;
      else
         return container.size();
   } catch (...) {
      log::error("Exception thrown in detail::sizeOfContainer");
      log::function(
         "{}({} handle = {})", funname, classname, (void *)ptr);
      return 0;
   }
}


// -----------------------------------------------------------------------------
// add
// -----------------------------------------------------------------------------

// addToContainer
template<class CPP, class CLASS, class C, class EXTRACT, class T>
void addToContainer(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const EXTRACT &extract,
   const T &value
) {
   try {
      auto &field = *extract(tocpp<CPP>(ptr));
      field.add(tocpp<CLASS>(value));
   } catch (...) {
      log::error("Exception thrown in detail::addToContainer");
      log::function(
         "{}({} handle = {}, value)", funname, classname, (void *)ptr);
   }
}


// -----------------------------------------------------------------------------
// getByIndex
// setByIndex
// -----------------------------------------------------------------------------

// getByIndex
template<class CPP, class HANDLE, class C, class EXTRACT>
HANDLE getByIndex(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr,
   const EXTRACT &extract,
   const size_t index
) {
   try {
      const auto &field = *extract(tocpp<CPP>(ptr));
      return (HANDLE)&field(index);
   } catch (...) {
      log::function(
         "{}({} handle = {}, index = {})", funname, classname,
         (void *)ptr, index
      );
      return (HANDLE)nullptr;
   }
}

// setByIndex
template<class CPP, class CLASS, class C, class EXTRACT, class V>
void setByIndex(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const EXTRACT &extract,
   const size_t index,
   const V *const newvalue
) {
   try {
      auto &field = *extract(tocpp<CPP>(ptr));
      field.replace(index,tocpp<CLASS>(newvalue));
   } catch (...) {
      log::function(
         "{}({} handle = {}, value)", funname, classname, (void *)ptr);
   }
}


// -----------------------------------------------------------------------------
// hasByMetadatum
// getByMetadatum
// setByMetadatum
// -----------------------------------------------------------------------------

// hasByMetadatum
template<class CPP, class C, class EXTRACT, class META, class T>
bool hasByMetadatum(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr,
   const EXTRACT &extract,
   const META &meta,
   const T &value
) {
   try {
      const auto &field = *extract(tocpp<CPP>(ptr));
      return field.has(meta(value));
   } catch (...) {
      log::function("{}({} handle = {}, value)", funname, classname,
                    (void *)ptr);
      return false;
   }
}

// getByMetadatum
template<class CPP, class HANDLE, class C, class EXTRACT, class META, class T>
HANDLE getByMetadatum(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr,
   const EXTRACT &extract,
   const META &meta,
   const T &value
) {
   try {
      const auto &field = *extract(tocpp<CPP>(ptr));
      return (HANDLE)&field(meta(value));
   } catch (...) {
      log::function(
         "{}({} handle = {}, value)", funname, classname, (void *)ptr);
      return (HANDLE)nullptr;
   }
}

// setByMetadatum
template<
   class CPP, class CLASS, class C,
   class EXTRACT, class META, class V, class T
>
void setByMetadatum(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const EXTRACT &extract,
   const META &meta,
   const T &value,
   const V *const newvalue
) {
   try {
      auto &field = *extract(tocpp<CPP>(ptr));
      field.replace(meta(value),tocpp<CLASS>(newvalue));
   } catch (...) {
      log::function(
         "{}({} handle = {}, value)", funname, classname, (void *)ptr);
   }
}


// -----------------------------------------------------------------------------
// Re: data vectors
// For when a Component-derived class has BlockData
// -----------------------------------------------------------------------------

// ------------------------
// clear, size
// ------------------------

// clear
template<class CPP, class C>
void vectorClear(
   const std::string &classname,
   const std::string &funname,
   C *const ptr
) {
   try {
      tocpp<CPP>(ptr).clear();
   } catch (...) {
      log::error("Exception thrown in detail::vectorClear");
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
   }
}

// size
template<class CPP, class C>
size_t vectorSize(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr
) {
   try {
      return tocpp<CPP>(ptr).size();
   } catch (...) {
      log::error("Exception thrown in detail::vectorSize");
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
      return 0;
   }
}

// ------------------------
// get, set
// One value
// ------------------------

// get
template<class CPP, class T, class C>
T vectorGet(
   const std::string &classname,
   const std::string &funname,
   const C *const ptr,
   const size_t index
) {
   using VECTOR = std::vector<T>;
   bool rangeErr = false;

   try {
      const VECTOR &vec = tocpp<CPP>(ptr).template get<VECTOR>();
      if (index < vec.size())
         return vec[index];

      rangeErr = true;
      log::error(
        "Vector index {} not in range 0..size-1 (0..{})",
         index, vec.size()-1
      );
      throw std::exception{};
   } catch (...) {
      if (!rangeErr) // else error was already printed
         log::error("Exception thrown in detail::vectorGet");
      log::function(
        "{}({} handle = {}, index = {})",
         funname, classname, (void *)ptr, index
      );
      return T{};
   }
}

// set
template<class CPP, class T, class C>
void vectorSet(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const size_t index,
   const T &value
) {
   using VECTOR = std::vector<T>;
   bool rangeErr = false;

   try {
      VECTOR &vec = tocpp<CPP>(ptr).template get<VECTOR>();
      if (index < vec.size())
         vec[index] = value;
      else {
         rangeErr = true;
         log::error(
           "Vector index {} not in range 0..size-1 (0..{})",
            index, vec.size()-1
         );
         throw std::exception{};
      }
   } catch (...) {
      if (!rangeErr) // else error was already printed
         log::error("Exception thrown in detail::vectorSet");
      log::function(
        "{}({} handle = {}, index = {}, value)",
         funname, classname, (void *)ptr, index
      );
   }
}

// ------------------------
// get, set
// All values
// ------------------------

// get
template<class CPP, class T, class C>
auto *vectorGet(
   const std::string &classname,
   const std::string &funname,
   C *const ptr
) {
   using VECTOR = std::vector<T>;
   using RETURN = decltype(&(tocpp<CPP>(ptr).template get<VECTOR>())[0]);

   try {
      auto &vec = tocpp<CPP>(ptr).template get<VECTOR>();
      return vec.size() ? &vec[0] : nullptr;
   } catch (...) {
      log::error("Exception thrown in detail::vectorGet");
      log::function("{}({} handle = {})", funname, classname, (void *)ptr);
      return RETURN(nullptr);
   }
}

// set
template<class CPP, class T, class C>
void vectorSet(
   const std::string &classname,
   const std::string &funname,
   C *const ptr,
   const size_t size,
   const T *const values
) {
   using VECTOR = std::vector<T>;

   try {
      tocpp<CPP>(ptr).template get<VECTOR>().assign(values,values+size);
   } catch (...) {
      log::error("Exception thrown in detail::vectorSet");
      log::function(
        "{}({} handle = {}, size = {}, values*)",
         funname, classname, (void *)ptr, size
      );
   }
}

} // namespace detail
