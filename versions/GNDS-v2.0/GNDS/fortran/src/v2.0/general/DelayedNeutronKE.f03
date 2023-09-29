
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalDelayedNeutronKE
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DelayedNeutronKEDefaultConst() &
      bind(C, name='DelayedNeutronKEDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DelayedNeutronKEDefaultConst
end function DelayedNeutronKEDefaultConst

!! Create, default
function DelayedNeutronKEDefault() &
      bind(C, name='DelayedNeutronKEDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DelayedNeutronKEDefault
end function DelayedNeutronKEDefault

!! Create, general, const
function DelayedNeutronKECreateConst( &
   polynomial1d, &
   XYs1d &
) &
      bind(C, name='DelayedNeutronKECreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: polynomial1d
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: DelayedNeutronKECreateConst
end function DelayedNeutronKECreateConst

!! Create, general
function DelayedNeutronKECreate( &
   polynomial1d, &
   XYs1d &
) &
      bind(C, name='DelayedNeutronKECreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: polynomial1d
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: DelayedNeutronKECreate
end function DelayedNeutronKECreate

!! Assign
subroutine DelayedNeutronKEAssign(handleLHS, handleRHS) &
      bind(C, name='DelayedNeutronKEAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine DelayedNeutronKEAssign

!! Delete
subroutine DelayedNeutronKEDelete(handle) &
      bind(C, name='DelayedNeutronKEDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DelayedNeutronKEDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function DelayedNeutronKERead(handle, filename, filenameSize) &
      bind(C, name='DelayedNeutronKERead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DelayedNeutronKERead
end function DelayedNeutronKERead

!! Write to file
function DelayedNeutronKEWrite(handle, filename, filenameSize) &
      bind(C, name='DelayedNeutronKEWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DelayedNeutronKEWrite
end function DelayedNeutronKEWrite

!! Print to standard output, in our prettyprinting format
function DelayedNeutronKEPrint(handle) &
      bind(C, name='DelayedNeutronKEPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronKEPrint
end function DelayedNeutronKEPrint

!! Print to standard output, as XML
function DelayedNeutronKEPrintXML(handle) &
      bind(C, name='DelayedNeutronKEPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronKEPrintXML
end function DelayedNeutronKEPrintXML

!! Print to standard output, as JSON
function DelayedNeutronKEPrintJSON(handle) &
      bind(C, name='DelayedNeutronKEPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronKEPrintJSON
end function DelayedNeutronKEPrintJSON


!! -----------------------------------------------------------------------------
!! Child: polynomial1d
!! -----------------------------------------------------------------------------

!! Has
function DelayedNeutronKEPolynomial1dHas(handle) &
      bind(C, name='DelayedNeutronKEPolynomial1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronKEPolynomial1dHas
end function DelayedNeutronKEPolynomial1dHas

!! Get, const
function DelayedNeutronKEPolynomial1dGetConst(handle) &
      bind(C, name='DelayedNeutronKEPolynomial1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DelayedNeutronKEPolynomial1dGetConst
end function DelayedNeutronKEPolynomial1dGetConst

!! Get
function DelayedNeutronKEPolynomial1dGet(handle) &
      bind(C, name='DelayedNeutronKEPolynomial1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DelayedNeutronKEPolynomial1dGet
end function DelayedNeutronKEPolynomial1dGet

!! Set
subroutine DelayedNeutronKEPolynomial1dSet(handle, fieldHandle) &
      bind(C, name='DelayedNeutronKEPolynomial1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DelayedNeutronKEPolynomial1dSet


!! -----------------------------------------------------------------------------
!! Child: XYs1d
!! -----------------------------------------------------------------------------

!! Has
function DelayedNeutronKEXYs1dHas(handle) &
      bind(C, name='DelayedNeutronKEXYs1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronKEXYs1dHas
end function DelayedNeutronKEXYs1dHas

!! Get, const
function DelayedNeutronKEXYs1dGetConst(handle) &
      bind(C, name='DelayedNeutronKEXYs1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DelayedNeutronKEXYs1dGetConst
end function DelayedNeutronKEXYs1dGetConst

!! Get
function DelayedNeutronKEXYs1dGet(handle) &
      bind(C, name='DelayedNeutronKEXYs1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DelayedNeutronKEXYs1dGet
end function DelayedNeutronKEXYs1dGet

!! Set
subroutine DelayedNeutronKEXYs1dSet(handle, fieldHandle) &
      bind(C, name='DelayedNeutronKEXYs1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DelayedNeutronKEXYs1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalDelayedNeutronKE
