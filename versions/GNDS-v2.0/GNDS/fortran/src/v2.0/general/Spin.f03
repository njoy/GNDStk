
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSpin
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SpinDefaultConst() &
      bind(C, name='SpinDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SpinDefaultConst
end function SpinDefaultConst

!! Create, default
function SpinDefault() &
      bind(C, name='SpinDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SpinDefault
end function SpinDefault

!! Create, general, const
function SpinCreateConst( &
   fraction &
) &
      bind(C, name='SpinCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: fraction
   type(c_ptr) :: SpinCreateConst
end function SpinCreateConst

!! Create, general
function SpinCreate( &
   fraction &
) &
      bind(C, name='SpinCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: fraction
   type(c_ptr) :: SpinCreate
end function SpinCreate

!! Assign
subroutine SpinAssign(handleLHS, handleRHS) &
      bind(C, name='SpinAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine SpinAssign

!! Delete
subroutine SpinDelete(handle) &
      bind(C, name='SpinDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SpinDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SpinRead(handle, filename, filenameSize) &
      bind(C, name='SpinRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SpinRead
end function SpinRead

!! Write to file
function SpinWrite(handle, filename, filenameSize) &
      bind(C, name='SpinWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SpinWrite
end function SpinWrite

!! Print to standard output, in our prettyprinting format
function SpinPrint(handle) &
      bind(C, name='SpinPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpinPrint
end function SpinPrint

!! Print to standard output, as XML
function SpinPrintXML(handle) &
      bind(C, name='SpinPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpinPrintXML
end function SpinPrintXML

!! Print to standard output, as JSON
function SpinPrintJSON(handle) &
      bind(C, name='SpinPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpinPrintJSON
end function SpinPrintJSON


!! -----------------------------------------------------------------------------
!! Child: fraction
!! -----------------------------------------------------------------------------

!! Has
function SpinFractionHas(handle) &
      bind(C, name='SpinFractionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpinFractionHas
end function SpinFractionHas

!! Get, const
function SpinFractionGetConst(handle) &
      bind(C, name='SpinFractionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SpinFractionGetConst
end function SpinFractionGetConst

!! Get
function SpinFractionGet(handle) &
      bind(C, name='SpinFractionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SpinFractionGet
end function SpinFractionGet

!! Set
subroutine SpinFractionSet(handle, fieldHandle) &
      bind(C, name='SpinFractionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine SpinFractionSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSpin
