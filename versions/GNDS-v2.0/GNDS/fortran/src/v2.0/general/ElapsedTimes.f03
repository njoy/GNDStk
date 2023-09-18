
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalElapsedTimes
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ElapsedTimesDefaultConst() &
      bind(C, name='ElapsedTimesDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ElapsedTimesDefaultConst

!! Create, default
function ElapsedTimesDefault() &
      bind(C, name='ElapsedTimesDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ElapsedTimesDefault

!! Create, general, const
function ElapsedTimesCreateConst( &
   elapsedTime, elapsedTimeSize &
) &
      bind(C, name='ElapsedTimesCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: elapsedTimeSize
   type(c_ptr) :: elapsedTime(elapsedTimeSize)
   type(c_ptr) :: handle
end function ElapsedTimesCreateConst

!! Create, general
function ElapsedTimesCreate( &
   elapsedTime, elapsedTimeSize &
) &
      bind(C, name='ElapsedTimesCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: elapsedTimeSize
   type(c_ptr) :: elapsedTime(elapsedTimeSize)
   type(c_ptr) :: handle
end function ElapsedTimesCreate

!! Assign
subroutine ElapsedTimesAssign(handleLHS, handleRHS) &
      bind(C, name='ElapsedTimesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ElapsedTimesAssign

!! Delete
subroutine ElapsedTimesDelete(handle) &
      bind(C, name='ElapsedTimesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ElapsedTimesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ElapsedTimesRead(handle, filename, filenameSize) &
      bind(C, name='ElapsedTimesRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ElapsedTimesRead

!! Write to file
function ElapsedTimesWrite(handle, filename, filenameSize) &
      bind(C, name='ElapsedTimesWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ElapsedTimesWrite

!! Print to standard output, in our prettyprinting format
function ElapsedTimesPrint(handle) &
      bind(C, name='ElapsedTimesPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ElapsedTimesPrint

!! Print to standard output, as XML
function ElapsedTimesPrintXML(handle) &
      bind(C, name='ElapsedTimesPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ElapsedTimesPrintXML

!! Print to standard output, as JSON
function ElapsedTimesPrintJSON(handle) &
      bind(C, name='ElapsedTimesPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ElapsedTimesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: elapsedTime
!! -----------------------------------------------------------------------------

!! Has
function ElapsedTimesElapsedTimeHas(handle) &
      bind(C, name='ElapsedTimesElapsedTimeHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ElapsedTimesElapsedTimeHas

!! Clear
subroutine ElapsedTimesElapsedTimeClear(handle) &
      bind(C, name='ElapsedTimesElapsedTimeClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ElapsedTimesElapsedTimeClear

!! Size
function ElapsedTimesElapsedTimeSize(handle) &
      bind(C, name='ElapsedTimesElapsedTimeSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function ElapsedTimesElapsedTimeSize

!! Add
subroutine ElapsedTimesElapsedTimeAdd(handle, fieldHandle) &
      bind(C, name='ElapsedTimesElapsedTimeAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ElapsedTimesElapsedTimeAdd

!! Get, by index \in [0,size), const
function ElapsedTimesElapsedTimeGetConst(handle, index) &
      bind(C, name='ElapsedTimesElapsedTimeGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ElapsedTimesElapsedTimeGetConst

!! Get, by index \in [0,size)
function ElapsedTimesElapsedTimeGet(handle, index) &
      bind(C, name='ElapsedTimesElapsedTimeGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ElapsedTimesElapsedTimeGet

!! Set, by index \in [0,size)
subroutine ElapsedTimesElapsedTimeSet(handle, index, fieldHandle) &
      bind(C, name='ElapsedTimesElapsedTimeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ElapsedTimesElapsedTimeSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ElapsedTimesElapsedTimeHasByLabel(handle, meta, metaSize) &
      bind(C, name='ElapsedTimesElapsedTimeHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ElapsedTimesElapsedTimeHasByLabel

!! Get, by label, const
function ElapsedTimesElapsedTimeGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ElapsedTimesElapsedTimeGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ElapsedTimesElapsedTimeGetByLabelConst

!! Get, by label
function ElapsedTimesElapsedTimeGetByLabel(handle, meta, metaSize) &
      bind(C, name='ElapsedTimesElapsedTimeGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ElapsedTimesElapsedTimeGetByLabel

!! Set, by label
subroutine ElapsedTimesElapsedTimeSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ElapsedTimesElapsedTimeSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ElapsedTimesElapsedTimeSetByLabel


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalElapsedTimes
