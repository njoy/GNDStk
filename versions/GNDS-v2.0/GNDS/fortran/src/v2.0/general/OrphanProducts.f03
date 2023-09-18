
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalOrphanProducts
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function OrphanProductsDefaultConst() &
      bind(C, name='OrphanProductsDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function OrphanProductsDefaultConst

!! Create, default
function OrphanProductsDefault() &
      bind(C, name='OrphanProductsDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function OrphanProductsDefault

!! Create, general, const
function OrphanProductsCreateConst( &
   orphanProduct, orphanProductSize &
) &
      bind(C, name='OrphanProductsCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: orphanProductSize
   type(c_ptr) :: orphanProduct(orphanProductSize)
   type(c_ptr) :: handle
end function OrphanProductsCreateConst

!! Create, general
function OrphanProductsCreate( &
   orphanProduct, orphanProductSize &
) &
      bind(C, name='OrphanProductsCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: orphanProductSize
   type(c_ptr) :: orphanProduct(orphanProductSize)
   type(c_ptr) :: handle
end function OrphanProductsCreate

!! Assign
subroutine OrphanProductsAssign(handleLHS, handleRHS) &
      bind(C, name='OrphanProductsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine OrphanProductsAssign

!! Delete
subroutine OrphanProductsDelete(handle) &
      bind(C, name='OrphanProductsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine OrphanProductsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function OrphanProductsRead(handle, filename, filenameSize) &
      bind(C, name='OrphanProductsRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function OrphanProductsRead

!! Write to file
function OrphanProductsWrite(handle, filename, filenameSize) &
      bind(C, name='OrphanProductsWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function OrphanProductsWrite

!! Print to standard output, in our prettyprinting format
function OrphanProductsPrint(handle) &
      bind(C, name='OrphanProductsPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function OrphanProductsPrint

!! Print to standard output, as XML
function OrphanProductsPrintXML(handle) &
      bind(C, name='OrphanProductsPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function OrphanProductsPrintXML

!! Print to standard output, as JSON
function OrphanProductsPrintJSON(handle) &
      bind(C, name='OrphanProductsPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function OrphanProductsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: orphanProduct
!! -----------------------------------------------------------------------------

!! Has
function OrphanProductsOrphanProductHas(handle) &
      bind(C, name='OrphanProductsOrphanProductHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function OrphanProductsOrphanProductHas

!! Clear
subroutine OrphanProductsOrphanProductClear(handle) &
      bind(C, name='OrphanProductsOrphanProductClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine OrphanProductsOrphanProductClear

!! Size
function OrphanProductsOrphanProductSize(handle) &
      bind(C, name='OrphanProductsOrphanProductSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function OrphanProductsOrphanProductSize

!! Add
subroutine OrphanProductsOrphanProductAdd(handle, fieldHandle) &
      bind(C, name='OrphanProductsOrphanProductAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine OrphanProductsOrphanProductAdd

!! Get, by index \in [0,size), const
function OrphanProductsOrphanProductGetConst(handle, index) &
      bind(C, name='OrphanProductsOrphanProductGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function OrphanProductsOrphanProductGetConst

!! Get, by index \in [0,size)
function OrphanProductsOrphanProductGet(handle, index) &
      bind(C, name='OrphanProductsOrphanProductGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function OrphanProductsOrphanProductGet

!! Set, by index \in [0,size)
subroutine OrphanProductsOrphanProductSet(handle, index, fieldHandle) &
      bind(C, name='OrphanProductsOrphanProductSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine OrphanProductsOrphanProductSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function OrphanProductsOrphanProductHasByLabel(handle, meta, metaSize) &
      bind(C, name='OrphanProductsOrphanProductHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function OrphanProductsOrphanProductHasByLabel

!! Get, by label, const
function OrphanProductsOrphanProductGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='OrphanProductsOrphanProductGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function OrphanProductsOrphanProductGetByLabelConst

!! Get, by label
function OrphanProductsOrphanProductGetByLabel(handle, meta, metaSize) &
      bind(C, name='OrphanProductsOrphanProductGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function OrphanProductsOrphanProductGetByLabel

!! Set, by label
subroutine OrphanProductsOrphanProductSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='OrphanProductsOrphanProductSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine OrphanProductsOrphanProductSetByLabel

!! ------------------------
!! Re: metadatum ENDF_MT
!! ------------------------

!! Has, by ENDF_MT
function OrphanProductsOrphanProductHasByENDFMT(handle, meta) &
      bind(C, name='OrphanProductsOrphanProductHasByENDFMT') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   integer(c_int) :: has
end function OrphanProductsOrphanProductHasByENDFMT

!! Get, by ENDF_MT, const
function OrphanProductsOrphanProductGetByENDFMTConst(handle, meta) &
      bind(C, name='OrphanProductsOrphanProductGetByENDFMTConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function OrphanProductsOrphanProductGetByENDFMTConst

!! Get, by ENDF_MT
function OrphanProductsOrphanProductGetByENDFMT(handle, meta) &
      bind(C, name='OrphanProductsOrphanProductGetByENDFMT') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function OrphanProductsOrphanProductGetByENDFMT

!! Set, by ENDF_MT
subroutine OrphanProductsOrphanProductSetByENDFMT(handle, meta, fieldHandle) &
      bind(C, name='OrphanProductsOrphanProductSetByENDFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine OrphanProductsOrphanProductSetByENDFMT


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalOrphanProducts
