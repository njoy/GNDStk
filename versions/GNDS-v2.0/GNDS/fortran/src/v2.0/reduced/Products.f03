
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
      bind(C, name='ProductsDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ProductsDefaultConst

!! Create, default
function ProductsDefault() &
      bind(C, name='ProductsDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ProductsDefault

!! Create, general, const
function ProductsCreateConst( &
   product, productSize &
) &
      bind(C, name='ProductsCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: productSize
   type(c_ptr) :: product(productSize)
   type(c_ptr) :: handle
end function ProductsCreateConst

!! Create, general
function ProductsCreate( &
   product, productSize &
) &
      bind(C, name='ProductsCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: productSize
   type(c_ptr) :: product(productSize)
   type(c_ptr) :: handle
end function ProductsCreate

!! Assign
subroutine ProductsAssign(handleLHS, handleRHS) &
      bind(C, name='ProductsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
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
function ProductsRead(handle, filename, filenameSize) &
      bind(C, name='ProductsRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ProductsRead

!! Write to file
function ProductsWrite(handle, filename, filenameSize) &
      bind(C, name='ProductsWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ProductsWrite

!! Print to standard output, in our prettyprinting format
function ProductsPrint(handle) &
      bind(C, name='ProductsPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ProductsPrint

!! Print to standard output, as XML
function ProductsPrintXML(handle) &
      bind(C, name='ProductsPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ProductsPrintXML

!! Print to standard output, as JSON
function ProductsPrintJSON(handle) &
      bind(C, name='ProductsPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ProductsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: product
!! -----------------------------------------------------------------------------

!! Has
function ProductsProductHas(handle) &
      bind(C, name='ProductsProductHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
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
      bind(C, name='ProductsProductSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
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
      bind(C, name='ProductsProductGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ProductsProductGetConst

!! Get, by index \in [0,size)
function ProductsProductGet(handle, index) &
      bind(C, name='ProductsProductGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
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
      bind(C, name='ProductsProductHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ProductsProductHasByLabel

!! Get, by label, const
function ProductsProductGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ProductsProductGetByLabelConst

!! Get, by label
function ProductsProductGetByLabel(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ProductsProductGetByLabel

!! Set, by label
subroutine ProductsProductSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ProductsProductSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductsProductSetByLabel

!! ------------------------
!! Re: metadatum pid
!! ------------------------

!! Has, by pid
function ProductsProductHasByPid(handle, meta, metaSize) &
      bind(C, name='ProductsProductHasByPid') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ProductsProductHasByPid

!! Get, by pid, const
function ProductsProductGetByPidConst(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByPidConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ProductsProductGetByPidConst

!! Get, by pid
function ProductsProductGetByPid(handle, meta, metaSize) &
      bind(C, name='ProductsProductGetByPid') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ProductsProductGetByPid

!! Set, by pid
subroutine ProductsProductSetByPid(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ProductsProductSetByPid')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductsProductSetByPid


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module reducedProducts
