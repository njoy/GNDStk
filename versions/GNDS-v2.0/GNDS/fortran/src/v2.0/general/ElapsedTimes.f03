
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
      bind(C, name='ElapsedTimesDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ElapsedTimesDefaultConst
end function ElapsedTimesDefaultConst

!! Create, default, non-const
function ElapsedTimesDefault() &
      bind(C, name='ElapsedTimesDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ElapsedTimesDefault
end function ElapsedTimesDefault

!! Create, general, const
function ElapsedTimesCreateConst( &
   elapsedTime, elapsedTimeSize &
) &
      bind(C, name='ElapsedTimesCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: elapsedTimeSize
   type(c_ptr), intent(in) :: elapsedTime(elapsedTimeSize)
   type(c_ptr) :: ElapsedTimesCreateConst
end function ElapsedTimesCreateConst

!! Create, general, non-const
function ElapsedTimesCreate( &
   elapsedTime, elapsedTimeSize &
) &
      bind(C, name='ElapsedTimesCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: elapsedTimeSize
   type(c_ptr), intent(in) :: elapsedTime(elapsedTimeSize)
   type(c_ptr) :: ElapsedTimesCreate
end function ElapsedTimesCreate

!! Assign
subroutine ElapsedTimesAssign(handleLHS, handleRHS) &
      bind(C, name='ElapsedTimesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
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
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ElapsedTimesRead(handle, filename, filenameSize) &
      bind(C, name='ElapsedTimesRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ElapsedTimesRead
end function ElapsedTimesRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ElapsedTimesWrite(handle, filename, filenameSize) &
      bind(C, name='ElapsedTimesWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ElapsedTimesWrite
end function ElapsedTimesWrite

!! Print to standard output, in our prettyprinting format
function ElapsedTimesPrint(handle) &
      bind(C, name='ElapsedTimesPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ElapsedTimesPrint
end function ElapsedTimesPrint

!! Print to standard output, as XML
function ElapsedTimesPrintXML(handle) &
      bind(C, name='ElapsedTimesPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ElapsedTimesPrintXML
end function ElapsedTimesPrintXML

!! Print to standard output, as JSON
function ElapsedTimesPrintJSON(handle) &
      bind(C, name='ElapsedTimesPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ElapsedTimesPrintJSON
end function ElapsedTimesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: elapsedTime
!! -----------------------------------------------------------------------------

!! Has
function ElapsedTimesElapsedTimeHas(handle) &
      bind(C, name='ElapsedTimesElapsedTimeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ElapsedTimesElapsedTimeHas
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
      bind(C, name='ElapsedTimesElapsedTimeSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ElapsedTimesElapsedTimeSize
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
      bind(C, name='ElapsedTimesElapsedTimeGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ElapsedTimesElapsedTimeGetConst
end function ElapsedTimesElapsedTimeGetConst

!! Get, by index \in [0,size), non-const
function ElapsedTimesElapsedTimeGet(handle, index) &
      bind(C, name='ElapsedTimesElapsedTimeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ElapsedTimesElapsedTimeGet
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
      bind(C, name='ElapsedTimesElapsedTimeHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ElapsedTimesElapsedTimeHasByLabel
end function ElapsedTimesElapsedTimeHasByLabel

!! Get, by label, const
function ElapsedTimesElapsedTimeGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ElapsedTimesElapsedTimeGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ElapsedTimesElapsedTimeGetByLabelConst
end function ElapsedTimesElapsedTimeGetByLabelConst

!! Get, by label, non-const
function ElapsedTimesElapsedTimeGetByLabel(handle, meta, metaSize) &
      bind(C, name='ElapsedTimesElapsedTimeGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ElapsedTimesElapsedTimeGetByLabel
end function ElapsedTimesElapsedTimeGetByLabel

!! Set, by label
subroutine ElapsedTimesElapsedTimeSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ElapsedTimesElapsedTimeSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ElapsedTimesElapsedTimeSetByLabel


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalElapsedTimes