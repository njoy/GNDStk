
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module reducedProducts
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ProductsDefaultConst() &
      bind(C, name='ProductsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ProductsDefaultConst
end function ProductsDefaultConst

!! Create, default, non-const
function ProductsDefault() &
      bind(C, name='ProductsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ProductsDefault
end function ProductsDefault

!! Create, general, const
function ProductsCreateConst( &
   product, productSize &
) &
      bind(C, name='ProductsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: productSize
   type(c_ptr), intent(in) :: product(productSize)
   type(c_ptr) :: ProductsCreateConst
end function ProductsCreateConst

!! Create, general, non-const
function ProductsCreate( &
   product, productSize &
) &
      bind(C, name='ProductsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: productSize
   type(c_ptr), intent(in) :: product(productSize)
   type(c_ptr) :: ProductsCreate
end function ProductsCreate

!! Assign
subroutine ProductsAssign(handleLHS, handleRHS) &
      bind(C, name='ProductsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ProductsAssign

!! Delete
subroutine ProductsDelete(handle) &
      bind(C, name='ProductsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ProductsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ProductsRead(handle, filename, filenameSize) &
      bind(C, name='ProductsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ProductsRead
end function ProductsRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ProductsWrite(handle, filename, filenameSize) &
      bind(C, name='ProductsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ProductsWrite
end function ProductsWrite

!! Print to standard output, in our prettyprinting format
function ProductsPrint(handle) &
      bind(C, name='ProductsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductsPrint
end function ProductsPrint

!! Print to standard output, as XML
function ProductsPrintXML(handle) &
      bind(C, name='ProductsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductsPrintXML
end function ProductsPrintXML

!! Print to standard output, as JSON
function ProductsPrintJSON(handle) &
      bind(C, name='ProductsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductsPrintJSON
end function ProductsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: product
!! -----------------------------------------------------------------------------

!! Has
function ProductsProductHas(handle) &
      bind(C, name='ProductsProductHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductsProductHas
end function ProductsProductHas

!! Clear
subroutine ProductsProductClear(handle) &
      bind(C, name='ProductsProductClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ProductsProductClear

!! Size
function ProductsProductSize(handle) &
      bind(C, name='ProductsProductSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ProductsProductSize
end function ProductsProductSize

!! Add
subroutine ProductsProductAdd(handle, fieldHandle) &
      bind(C, name='ProductsProductAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductsProductAdd

!! Get, by index \in [0,size), const
function ProductsProductGetConst(handle, index) &
      bind(C, name='ProductsProductGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ProductsProductGetConst
end function ProductsProductGetConst

!! Get, by index \in [0,size), non-const
function ProductsProductGet(handle, index) &
      bind(C, name='ProductsProductGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ProductsProductGet
end function ProductsProductGet

!! Set, by index \in [0,size)
subroutine ProductsProductSet(handle, index, fieldHandle) &
      bind(C, name='ProductsProductSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductsProductSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ProductsProductHasByLabel(handle, meta, metaSize) &
      bind(C, name='ProductsProductHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ProductsProductHasByLabel
end function ProductsProductHasByLabel

!! Get, by label, const
function ProductsProductGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ProductsProductGetByLabelConst
end function ProductsProductGetByLabelConst

!! Get, by label, non-const
function ProductsProductGetByLabel(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ProductsProductGetByLabel
end function ProductsProductGetByLabel

!! Set, by label
subroutine ProductsProductSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ProductsProductSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductsProductSetByLabel

!! ------------------------
!! Re: metadatum pid
!! ------------------------

!! Has, by pid
function ProductsProductHasByPid(handle, meta, metaSize) &
      bind(C, name='ProductsProductHasByPid')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ProductsProductHasByPid
end function ProductsProductHasByPid

!! Get, by pid, const
function ProductsProductGetByPidConst(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByPidConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ProductsProductGetByPidConst
end function ProductsProductGetByPidConst

!! Get, by pid, non-const
function ProductsProductGetByPid(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByPid')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ProductsProductGetByPid
end function ProductsProductGetByPid

!! Set, by pid
subroutine ProductsProductSetByPid(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ProductsProductSetByPid')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductsProductSetByPid


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module reducedProducts