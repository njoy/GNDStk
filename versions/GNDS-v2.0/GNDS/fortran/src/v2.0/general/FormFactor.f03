
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalFormFactor
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function FormFactorDefaultConst() &
      bind(C, name='FormFactorDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function FormFactorDefaultConst

!! Create, default
function FormFactorDefault() &
      bind(C, name='FormFactorDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function FormFactorDefault

!! Create, general, const
function FormFactorCreateConst( &
   XYs1d &
) &
      bind(C, name='FormFactorCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: XYs1d
   type(c_ptr) :: handle
end function FormFactorCreateConst

!! Create, general
function FormFactorCreate( &
   XYs1d &
) &
      bind(C, name='FormFactorCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: XYs1d
   type(c_ptr) :: handle
end function FormFactorCreate

!! Assign
subroutine FormFactorAssign(handleLHS, handleRHS) &
      bind(C, name='FormFactorAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine FormFactorAssign

!! Delete
subroutine FormFactorDelete(handle) &
      bind(C, name='FormFactorDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine FormFactorDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function FormFactorRead(handle, filename, filenameSize) &
      bind(C, name='FormFactorRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function FormFactorRead

!! Write to file
function FormFactorWrite(handle, filename, filenameSize) &
      bind(C, name='FormFactorWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function FormFactorWrite

!! Print to standard output, in our prettyprinting format
function FormFactorPrint(handle) &
      bind(C, name='FormFactorPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function FormFactorPrint

!! Print to standard output, as XML
function FormFactorPrintXML(handle) &
      bind(C, name='FormFactorPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function FormFactorPrintXML

!! Print to standard output, as JSON
function FormFactorPrintJSON(handle) &
      bind(C, name='FormFactorPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function FormFactorPrintJSON


!! -----------------------------------------------------------------------------
!! Child: XYs1d
!! -----------------------------------------------------------------------------

!! Has
function FormFactorXYs1dHas(handle) &
      bind(C, name='FormFactorXYs1dHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function FormFactorXYs1dHas

!! Get, const
function FormFactorXYs1dGetConst(handle) &
      bind(C, name='FormFactorXYs1dGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function FormFactorXYs1dGetConst

!! Get
function FormFactorXYs1dGet(handle) &
      bind(C, name='FormFactorXYs1dGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function FormFactorXYs1dGet

!! Set
subroutine FormFactorXYs1dSet(handle, fieldHandle) &
      bind(C, name='FormFactorXYs1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine FormFactorXYs1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalFormFactor
