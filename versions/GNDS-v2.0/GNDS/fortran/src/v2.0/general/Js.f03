
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalJs
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function JsDefaultConst() &
      bind(C, name='JsDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function JsDefaultConst

!! Create, default
function JsDefault() &
      bind(C, name='JsDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function JsDefault

!! Create, general, const
function JsCreateConst( &
   J, JSize &
) &
      bind(C, name='JsCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: JSize
   type(c_ptr) :: J(JSize)
   type(c_ptr) :: handle
end function JsCreateConst

!! Create, general
function JsCreate( &
   J, JSize &
) &
      bind(C, name='JsCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: JSize
   type(c_ptr) :: J(JSize)
   type(c_ptr) :: handle
end function JsCreate

!! Assign
subroutine JsAssign(handleLHS, handleRHS) &
      bind(C, name='JsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine JsAssign

!! Delete
subroutine JsDelete(handle) &
      bind(C, name='JsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine JsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function JsRead(handle, filename, filenameSize) &
      bind(C, name='JsRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function JsRead

!! Write to file
function JsWrite(handle, filename, filenameSize) &
      bind(C, name='JsWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function JsWrite

!! Print to standard output, in our prettyprinting format
function JsPrint(handle) &
      bind(C, name='JsPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function JsPrint

!! Print to standard output, as XML
function JsPrintXML(handle) &
      bind(C, name='JsPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function JsPrintXML

!! Print to standard output, as JSON
function JsPrintJSON(handle) &
      bind(C, name='JsPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function JsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: J
!! -----------------------------------------------------------------------------

!! Has
function JsJHas(handle) &
      bind(C, name='JsJHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function JsJHas

!! Clear
subroutine JsJClear(handle) &
      bind(C, name='JsJClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine JsJClear

!! Size
function JsJSize(handle) &
      bind(C, name='JsJSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function JsJSize

!! Add
subroutine JsJAdd(handle, fieldHandle) &
      bind(C, name='JsJAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine JsJAdd

!! Get, by index \in [0,size), const
function JsJGetConst(handle, index) &
      bind(C, name='JsJGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function JsJGetConst

!! Get, by index \in [0,size)
function JsJGet(handle, index) &
      bind(C, name='JsJGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function JsJGet

!! Set, by index \in [0,size)
subroutine JsJSet(handle, index, fieldHandle) &
      bind(C, name='JsJSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine JsJSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function JsJHasByLabel(handle, meta, metaSize) &
      bind(C, name='JsJHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function JsJHasByLabel

!! Get, by label, const
function JsJGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='JsJGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function JsJGetByLabelConst

!! Get, by label
function JsJGetByLabel(handle, meta, metaSize) &
      bind(C, name='JsJGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function JsJGetByLabel

!! Set, by label
subroutine JsJSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='JsJSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine JsJSetByLabel

!! ------------------------
!! Re: metadatum value
!! ------------------------

!! Has, by value
function JsJHasByValue(handle, meta) &
      bind(C, name='JsJHasByValue') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   integer(c_int) :: has
end function JsJHasByValue

!! Get, by value, const
function JsJGetByValueConst(handle, meta) &
      bind(C, name='JsJGetByValueConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function JsJGetByValueConst

!! Get, by value
function JsJGetByValue(handle, meta) &
      bind(C, name='JsJGetByValue') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function JsJGetByValue

!! Set, by value
subroutine JsJSetByValue(handle, meta, fieldHandle) &
      bind(C, name='JsJSetByValue')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine JsJSetByValue


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalJs
