
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalT_M
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function T_MDefaultConst() &
      bind(C, name='T_MDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: T_MDefaultConst
end function T_MDefaultConst

!! Create, default, non-const
function T_MDefault() &
      bind(C, name='T_MDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: T_MDefault
end function T_MDefault

!! Create, general, const
function T_MCreateConst( &
   XYs1d &
) &
      bind(C, name='T_MCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: T_MCreateConst
end function T_MCreateConst

!! Create, general, non-const
function T_MCreate( &
   XYs1d &
) &
      bind(C, name='T_MCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: T_MCreate
end function T_MCreate

!! Assign
subroutine T_MAssign(handleLHS, handleRHS) &
      bind(C, name='T_MAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine T_MAssign

!! Delete
subroutine T_MDelete(handle) &
      bind(C, name='T_MDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine T_MDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function T_MRead(handle, filename, filenameSize) &
      bind(C, name='T_MRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: T_MRead
end function T_MRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function T_MWrite(handle, filename, filenameSize) &
      bind(C, name='T_MWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: T_MWrite
end function T_MWrite

!! Print to standard output, in our prettyprinting format
function T_MPrint(handle) &
      bind(C, name='T_MPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: T_MPrint
end function T_MPrint

!! Print to standard output, as XML
function T_MPrintXML(handle) &
      bind(C, name='T_MPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: T_MPrintXML
end function T_MPrintXML

!! Print to standard output, as JSON
function T_MPrintJSON(handle) &
      bind(C, name='T_MPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: T_MPrintJSON
end function T_MPrintJSON


!! -----------------------------------------------------------------------------
!! Child: XYs1d
!! -----------------------------------------------------------------------------

!! Has
function T_MXYs1dHas(handle) &
      bind(C, name='T_MXYs1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: T_MXYs1dHas
end function T_MXYs1dHas

!! Get, const
function T_MXYs1dGetConst(handle) &
      bind(C, name='T_MXYs1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: T_MXYs1dGetConst
end function T_MXYs1dGetConst

!! Get, non-const
function T_MXYs1dGet(handle) &
      bind(C, name='T_MXYs1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: T_MXYs1dGet
end function T_MXYs1dGet

!! Set
subroutine T_MXYs1dSet(handle, fieldHandle) &
      bind(C, name='T_MXYs1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine T_MXYs1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalT_M