
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalTime
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function TimeDefaultConst() &
      bind(C, name='TimeDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: TimeDefaultConst
end function TimeDefaultConst

!! Create, default, non-const
function TimeDefault() &
      bind(C, name='TimeDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: TimeDefault
end function TimeDefault

!! Create, general, const
function TimeCreateConst( &
   Double, &
   string &
) &
      bind(C, name='TimeCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: Double
   type(c_ptr), intent(in), value :: string
   type(c_ptr) :: TimeCreateConst
end function TimeCreateConst

!! Create, general, non-const
function TimeCreate( &
   Double, &
   string &
) &
      bind(C, name='TimeCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: Double
   type(c_ptr), intent(in), value :: string
   type(c_ptr) :: TimeCreate
end function TimeCreate

!! Assign
subroutine TimeAssign(handleLHS, handleRHS) &
      bind(C, name='TimeAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine TimeAssign

!! Delete
subroutine TimeDelete(handle) &
      bind(C, name='TimeDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine TimeDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function TimeRead(handle, filename, filenameSize) &
      bind(C, name='TimeRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: TimeRead
end function TimeRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function TimeWrite(handle, filename, filenameSize) &
      bind(C, name='TimeWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: TimeWrite
end function TimeWrite

!! Print to standard output, in our prettyprinting format
function TimePrint(handle) &
      bind(C, name='TimePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TimePrint
end function TimePrint

!! Print to standard output, as XML
function TimePrintXML(handle) &
      bind(C, name='TimePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TimePrintXML
end function TimePrintXML

!! Print to standard output, as JSON
function TimePrintJSON(handle) &
      bind(C, name='TimePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TimePrintJSON
end function TimePrintJSON


!! -----------------------------------------------------------------------------
!! Child: Double
!! -----------------------------------------------------------------------------

!! Has
function TimeDoubleHas(handle) &
      bind(C, name='TimeDoubleHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TimeDoubleHas
end function TimeDoubleHas

!! Get, const
function TimeDoubleGetConst(handle) &
      bind(C, name='TimeDoubleGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: TimeDoubleGetConst
end function TimeDoubleGetConst

!! Get, non-const
function TimeDoubleGet(handle) &
      bind(C, name='TimeDoubleGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: TimeDoubleGet
end function TimeDoubleGet

!! Set
subroutine TimeDoubleSet(handle, fieldHandle) &
      bind(C, name='TimeDoubleSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine TimeDoubleSet


!! -----------------------------------------------------------------------------
!! Child: string
!! -----------------------------------------------------------------------------

!! Has
function TimeStringHas(handle) &
      bind(C, name='TimeStringHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TimeStringHas
end function TimeStringHas

!! Get, const
function TimeStringGetConst(handle) &
      bind(C, name='TimeStringGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: TimeStringGetConst
end function TimeStringGetConst

!! Get, non-const
function TimeStringGet(handle) &
      bind(C, name='TimeStringGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: TimeStringGet
end function TimeStringGet

!! Set
subroutine TimeStringSet(handle, fieldHandle) &
      bind(C, name='TimeStringSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine TimeStringSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalTime
