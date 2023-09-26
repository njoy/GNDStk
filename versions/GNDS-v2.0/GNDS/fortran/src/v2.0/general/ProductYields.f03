
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalProductYields
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ProductYieldsDefaultConst() &
      bind(C, name='ProductYieldsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ProductYieldsDefaultConst
end function ProductYieldsDefaultConst

!! Create, default
function ProductYieldsDefault() &
      bind(C, name='ProductYieldsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ProductYieldsDefault
end function ProductYieldsDefault

!! Create, general, const
function ProductYieldsCreateConst( &
   productYield, productYieldSize &
) &
      bind(C, name='ProductYieldsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: productYieldSize
   type(c_ptr) :: productYield(productYieldSize)
   type(c_ptr) :: ProductYieldsCreateConst
end function ProductYieldsCreateConst

!! Create, general
function ProductYieldsCreate( &
   productYield, productYieldSize &
) &
      bind(C, name='ProductYieldsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: productYieldSize
   type(c_ptr) :: productYield(productYieldSize)
   type(c_ptr) :: ProductYieldsCreate
end function ProductYieldsCreate

!! Assign
subroutine ProductYieldsAssign(handleLHS, handleRHS) &
      bind(C, name='ProductYieldsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ProductYieldsAssign

!! Delete
subroutine ProductYieldsDelete(handle) &
      bind(C, name='ProductYieldsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ProductYieldsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ProductYieldsRead(handle, filename, filenameSize) &
      bind(C, name='ProductYieldsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ProductYieldsRead
end function ProductYieldsRead

!! Write to file
function ProductYieldsWrite(handle, filename, filenameSize) &
      bind(C, name='ProductYieldsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ProductYieldsWrite
end function ProductYieldsWrite

!! Print to standard output, in our prettyprinting format
function ProductYieldsPrint(handle) &
      bind(C, name='ProductYieldsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductYieldsPrint
end function ProductYieldsPrint

!! Print to standard output, as XML
function ProductYieldsPrintXML(handle) &
      bind(C, name='ProductYieldsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductYieldsPrintXML
end function ProductYieldsPrintXML

!! Print to standard output, as JSON
function ProductYieldsPrintJSON(handle) &
      bind(C, name='ProductYieldsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductYieldsPrintJSON
end function ProductYieldsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: productYield
!! -----------------------------------------------------------------------------

!! Has
function ProductYieldsProductYieldHas(handle) &
      bind(C, name='ProductYieldsProductYieldHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductYieldsProductYieldHas
end function ProductYieldsProductYieldHas

!! Clear
subroutine ProductYieldsProductYieldClear(handle) &
      bind(C, name='ProductYieldsProductYieldClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ProductYieldsProductYieldClear

!! Size
function ProductYieldsProductYieldSize(handle) &
      bind(C, name='ProductYieldsProductYieldSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ProductYieldsProductYieldSize
end function ProductYieldsProductYieldSize

!! Add
subroutine ProductYieldsProductYieldAdd(handle, fieldHandle) &
      bind(C, name='ProductYieldsProductYieldAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductYieldsProductYieldAdd

!! Get, by index \in [0,size), const
function ProductYieldsProductYieldGetConst(handle, index) &
      bind(C, name='ProductYieldsProductYieldGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ProductYieldsProductYieldGetConst
end function ProductYieldsProductYieldGetConst

!! Get, by index \in [0,size)
function ProductYieldsProductYieldGet(handle, index) &
      bind(C, name='ProductYieldsProductYieldGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ProductYieldsProductYieldGet
end function ProductYieldsProductYieldGet

!! Set, by index \in [0,size)
subroutine ProductYieldsProductYieldSet(handle, index, fieldHandle) &
      bind(C, name='ProductYieldsProductYieldSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductYieldsProductYieldSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ProductYieldsProductYieldHasByLabel(handle, meta, metaSize) &
      bind(C, name='ProductYieldsProductYieldHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ProductYieldsProductYieldHasByLabel
end function ProductYieldsProductYieldHasByLabel

!! Get, by label, const
function ProductYieldsProductYieldGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ProductYieldsProductYieldGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ProductYieldsProductYieldGetByLabelConst
end function ProductYieldsProductYieldGetByLabelConst

!! Get, by label
function ProductYieldsProductYieldGetByLabel(handle, meta, metaSize) &
      bind(C, name='ProductYieldsProductYieldGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ProductYieldsProductYieldGetByLabel
end function ProductYieldsProductYieldGetByLabel

!! Set, by label
subroutine ProductYieldsProductYieldSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ProductYieldsProductYieldSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductYieldsProductYieldSetByLabel


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalProductYields
