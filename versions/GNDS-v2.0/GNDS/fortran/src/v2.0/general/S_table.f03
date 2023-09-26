
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalS_table
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function S_tableDefaultConst() &
      bind(C, name='S_tableDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: S_tableDefaultConst
end function S_tableDefaultConst

!! Create, default
function S_tableDefault() &
      bind(C, name='S_tableDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: S_tableDefault
end function S_tableDefault

!! Create, general, const
function S_tableCreateConst( &
   gridded2d &
) &
      bind(C, name='S_tableCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: gridded2d
   type(c_ptr) :: S_tableCreateConst
end function S_tableCreateConst

!! Create, general
function S_tableCreate( &
   gridded2d &
) &
      bind(C, name='S_tableCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: gridded2d
   type(c_ptr) :: S_tableCreate
end function S_tableCreate

!! Assign
subroutine S_tableAssign(handleLHS, handleRHS) &
      bind(C, name='S_tableAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine S_tableAssign

!! Delete
subroutine S_tableDelete(handle) &
      bind(C, name='S_tableDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine S_tableDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function S_tableRead(handle, filename, filenameSize) &
      bind(C, name='S_tableRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: S_tableRead
end function S_tableRead

!! Write to file
function S_tableWrite(handle, filename, filenameSize) &
      bind(C, name='S_tableWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: S_tableWrite
end function S_tableWrite

!! Print to standard output, in our prettyprinting format
function S_tablePrint(handle) &
      bind(C, name='S_tablePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: S_tablePrint
end function S_tablePrint

!! Print to standard output, as XML
function S_tablePrintXML(handle) &
      bind(C, name='S_tablePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: S_tablePrintXML
end function S_tablePrintXML

!! Print to standard output, as JSON
function S_tablePrintJSON(handle) &
      bind(C, name='S_tablePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: S_tablePrintJSON
end function S_tablePrintJSON


!! -----------------------------------------------------------------------------
!! Child: gridded2d
!! -----------------------------------------------------------------------------

!! Has
function S_tableGridded2dHas(handle) &
      bind(C, name='S_tableGridded2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: S_tableGridded2dHas
end function S_tableGridded2dHas

!! Get, const
function S_tableGridded2dGetConst(handle) &
      bind(C, name='S_tableGridded2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: S_tableGridded2dGetConst
end function S_tableGridded2dGetConst

!! Get
function S_tableGridded2dGet(handle) &
      bind(C, name='S_tableGridded2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: S_tableGridded2dGet
end function S_tableGridded2dGet

!! Set
subroutine S_tableGridded2dSet(handle, fieldHandle) &
      bind(C, name='S_tableGridded2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine S_tableGridded2dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalS_table
