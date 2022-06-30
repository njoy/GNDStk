enum class FileType {
   guess, // Default, automagick, etc.
   debug, // <== DON't use this for reading; just writing
   // Generally use one of these:
   xml,  XML  = xml,
   json, JSON = json,
   hdf5, HDF5 = hdf5
};
