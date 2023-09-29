
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalF
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function FDefaultConst() &
      bind(C, name='FDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: FDefaultConst
end function FDefaultConst

!! Create, default
function FDefault() &
      bind(C, name='FDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: FDefault
end function FDefault

!! Create, general, const
function FCreateConst( &
   XYs2d &
) &
      bind(C, name='FCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: XYs2d
   type(c_ptr) :: FCreateConst
end function FCreateConst

!! Create, general
function FCreate( &
   XYs2d &
) &
      bind(C, name='FCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: XYs2d
   type(c_ptr) :: FCreate
end function FCreate

!! Assign
subroutine FAssign(handleLHS, handleRHS) &
      bind(C, name='FAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine FAssign

!! Delete
subroutine FDelete(handle) &
      bind(C, name='FDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine FDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function FRead(handle, filename, filenameSize) &
      bind(C, name='FRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: FRead
end function FRead

!! Write to file
function FWrite(handle, filename, filenameSize) &
      bind(C, name='FWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: FWrite
end function FWrite

!! Print to standard output, in our prettyprinting format
function FPrint(handle) &
      bind(C, name='FPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FPrint
end function FPrint

!! Print to standard output, as XML
function FPrintXML(handle) &
      bind(C, name='FPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FPrintXML
end function FPrintXML

!! Print to standard output, as JSON
function FPrintJSON(handle) &
      bind(C, name='FPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FPrintJSON
end function FPrintJSON


!! -----------------------------------------------------------------------------
!! Child: XYs2d
!! -----------------------------------------------------------------------------

!! Has
function FXYs2dHas(handle) &
      bind(C, name='FXYs2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FXYs2dHas
end function FXYs2dHas

!! Get, const
function FXYs2dGetConst(handle) &
      bind(C, name='FXYs2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: FXYs2dGetConst
end function FXYs2dGetConst

!! Get
function FXYs2dGet(handle) &
      bind(C, name='FXYs2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: FXYs2dGet
end function FXYs2dGet

!! Set
subroutine FXYs2dSet(handle, fieldHandle) &
      bind(C, name='FXYs2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine FXYs2dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalF
