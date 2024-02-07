
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalMultiplicitySums
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function MultiplicitySumsDefaultConst() &
      bind(C, name='MultiplicitySumsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: MultiplicitySumsDefaultConst
end function MultiplicitySumsDefaultConst

!! Create, default, non-const
function MultiplicitySumsDefault() &
      bind(C, name='MultiplicitySumsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: MultiplicitySumsDefault
end function MultiplicitySumsDefault

!! Create, general, const
function MultiplicitySumsCreateConst( &
   multiplicitySum, multiplicitySumSize &
) &
      bind(C, name='MultiplicitySumsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: multiplicitySumSize
   type(c_ptr), intent(in) :: multiplicitySum(multiplicitySumSize)
   type(c_ptr) :: MultiplicitySumsCreateConst
end function MultiplicitySumsCreateConst

!! Create, general, non-const
function MultiplicitySumsCreate( &
   multiplicitySum, multiplicitySumSize &
) &
      bind(C, name='MultiplicitySumsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: multiplicitySumSize
   type(c_ptr), intent(in) :: multiplicitySum(multiplicitySumSize)
   type(c_ptr) :: MultiplicitySumsCreate
end function MultiplicitySumsCreate

!! Assign
subroutine MultiplicitySumsAssign(handleLHS, handleRHS) &
      bind(C, name='MultiplicitySumsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine MultiplicitySumsAssign

!! Delete
subroutine MultiplicitySumsDelete(handle) &
      bind(C, name='MultiplicitySumsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine MultiplicitySumsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function MultiplicitySumsRead(handle, filename, filenameSize) &
      bind(C, name='MultiplicitySumsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: MultiplicitySumsRead
end function MultiplicitySumsRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function MultiplicitySumsWrite(handle, filename, filenameSize) &
      bind(C, name='MultiplicitySumsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: MultiplicitySumsWrite
end function MultiplicitySumsWrite

!! Print to standard output, in our prettyprinting format
function MultiplicitySumsPrint(handle) &
      bind(C, name='MultiplicitySumsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumsPrint
end function MultiplicitySumsPrint

!! Print to standard output, as XML
function MultiplicitySumsPrintXML(handle) &
      bind(C, name='MultiplicitySumsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumsPrintXML
end function MultiplicitySumsPrintXML

!! Print to standard output, as JSON
function MultiplicitySumsPrintJSON(handle) &
      bind(C, name='MultiplicitySumsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumsPrintJSON
end function MultiplicitySumsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: multiplicitySum
!! -----------------------------------------------------------------------------

!! Has
function MultiplicitySumsMultiplicitySumHas(handle) &
      bind(C, name='MultiplicitySumsMultiplicitySumHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumsMultiplicitySumHas
end function MultiplicitySumsMultiplicitySumHas

!! Clear
subroutine MultiplicitySumsMultiplicitySumClear(handle) &
      bind(C, name='MultiplicitySumsMultiplicitySumClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine MultiplicitySumsMultiplicitySumClear

!! Size
function MultiplicitySumsMultiplicitySumSize(handle) &
      bind(C, name='MultiplicitySumsMultiplicitySumSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: MultiplicitySumsMultiplicitySumSize
end function MultiplicitySumsMultiplicitySumSize

!! Add
subroutine MultiplicitySumsMultiplicitySumAdd(handle, fieldHandle) &
      bind(C, name='MultiplicitySumsMultiplicitySumAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine MultiplicitySumsMultiplicitySumAdd

!! Get, by index \in [0,size), const
function MultiplicitySumsMultiplicitySumGetConst(handle, index) &
      bind(C, name='MultiplicitySumsMultiplicitySumGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: MultiplicitySumsMultiplicitySumGetConst
end function MultiplicitySumsMultiplicitySumGetConst

!! Get, by index \in [0,size), non-const
function MultiplicitySumsMultiplicitySumGet(handle, index) &
      bind(C, name='MultiplicitySumsMultiplicitySumGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: MultiplicitySumsMultiplicitySumGet
end function MultiplicitySumsMultiplicitySumGet

!! Set, by index \in [0,size)
subroutine MultiplicitySumsMultiplicitySumSet(handle, index, fieldHandle) &
      bind(C, name='MultiplicitySumsMultiplicitySumSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine MultiplicitySumsMultiplicitySumSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function MultiplicitySumsMultiplicitySumHasByLabel(handle, meta, metaSize) &
      bind(C, name='MultiplicitySumsMultiplicitySumHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: MultiplicitySumsMultiplicitySumHasByLabel
end function MultiplicitySumsMultiplicitySumHasByLabel

!! Get, by label, const
function MultiplicitySumsMultiplicitySumGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='MultiplicitySumsMultiplicitySumGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: MultiplicitySumsMultiplicitySumGetByLabelConst
end function MultiplicitySumsMultiplicitySumGetByLabelConst

!! Get, by label, non-const
function MultiplicitySumsMultiplicitySumGetByLabel(handle, meta, metaSize) &
      bind(C, name='MultiplicitySumsMultiplicitySumGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: MultiplicitySumsMultiplicitySumGetByLabel
end function MultiplicitySumsMultiplicitySumGetByLabel

!! Set, by label
subroutine MultiplicitySumsMultiplicitySumSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='MultiplicitySumsMultiplicitySumSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine MultiplicitySumsMultiplicitySumSetByLabel

!! ------------------------
!! Re: metadatum ENDF_MT
!! ------------------------

!! Has, by ENDF_MT
function MultiplicitySumsMultiplicitySumHasByENDFMT(handle, meta) &
      bind(C, name='MultiplicitySumsMultiplicitySumHasByENDFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: MultiplicitySumsMultiplicitySumHasByENDFMT
end function MultiplicitySumsMultiplicitySumHasByENDFMT

!! Get, by ENDF_MT, const
function MultiplicitySumsMultiplicitySumGetByENDFMTConst(handle, meta) &
      bind(C, name='MultiplicitySumsMultiplicitySumGetByENDFMTConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: MultiplicitySumsMultiplicitySumGetByENDFMTConst
end function MultiplicitySumsMultiplicitySumGetByENDFMTConst

!! Get, by ENDF_MT, non-const
function MultiplicitySumsMultiplicitySumGetByENDFMT(handle, meta) &
      bind(C, name='MultiplicitySumsMultiplicitySumGetByENDFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: MultiplicitySumsMultiplicitySumGetByENDFMT
end function MultiplicitySumsMultiplicitySumGetByENDFMT

!! Set, by ENDF_MT
subroutine MultiplicitySumsMultiplicitySumSetByENDFMT(handle, meta, fieldHandle) &
      bind(C, name='MultiplicitySumsMultiplicitySumSetByENDFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine MultiplicitySumsMultiplicitySumSetByENDFMT


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalMultiplicitySums
