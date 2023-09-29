
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalPromptProductKE
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function PromptProductKEDefaultConst() &
      bind(C, name='PromptProductKEDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: PromptProductKEDefaultConst
end function PromptProductKEDefaultConst

!! Create, default
function PromptProductKEDefault() &
      bind(C, name='PromptProductKEDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: PromptProductKEDefault
end function PromptProductKEDefault

!! Create, general, const
function PromptProductKECreateConst( &
   polynomial1d, &
   XYs1d &
) &
      bind(C, name='PromptProductKECreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: polynomial1d
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: PromptProductKECreateConst
end function PromptProductKECreateConst

!! Create, general
function PromptProductKECreate( &
   polynomial1d, &
   XYs1d &
) &
      bind(C, name='PromptProductKECreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: polynomial1d
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: PromptProductKECreate
end function PromptProductKECreate

!! Assign
subroutine PromptProductKEAssign(handleLHS, handleRHS) &
      bind(C, name='PromptProductKEAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine PromptProductKEAssign

!! Delete
subroutine PromptProductKEDelete(handle) &
      bind(C, name='PromptProductKEDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine PromptProductKEDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function PromptProductKERead(handle, filename, filenameSize) &
      bind(C, name='PromptProductKERead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: PromptProductKERead
end function PromptProductKERead

!! Write to file
function PromptProductKEWrite(handle, filename, filenameSize) &
      bind(C, name='PromptProductKEWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: PromptProductKEWrite
end function PromptProductKEWrite

!! Print to standard output, in our prettyprinting format
function PromptProductKEPrint(handle) &
      bind(C, name='PromptProductKEPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PromptProductKEPrint
end function PromptProductKEPrint

!! Print to standard output, as XML
function PromptProductKEPrintXML(handle) &
      bind(C, name='PromptProductKEPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PromptProductKEPrintXML
end function PromptProductKEPrintXML

!! Print to standard output, as JSON
function PromptProductKEPrintJSON(handle) &
      bind(C, name='PromptProductKEPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PromptProductKEPrintJSON
end function PromptProductKEPrintJSON


!! -----------------------------------------------------------------------------
!! Child: polynomial1d
!! -----------------------------------------------------------------------------

!! Has
function PromptProductKEPolynomial1dHas(handle) &
      bind(C, name='PromptProductKEPolynomial1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PromptProductKEPolynomial1dHas
end function PromptProductKEPolynomial1dHas

!! Get, const
function PromptProductKEPolynomial1dGetConst(handle) &
      bind(C, name='PromptProductKEPolynomial1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PromptProductKEPolynomial1dGetConst
end function PromptProductKEPolynomial1dGetConst

!! Get
function PromptProductKEPolynomial1dGet(handle) &
      bind(C, name='PromptProductKEPolynomial1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PromptProductKEPolynomial1dGet
end function PromptProductKEPolynomial1dGet

!! Set
subroutine PromptProductKEPolynomial1dSet(handle, fieldHandle) &
      bind(C, name='PromptProductKEPolynomial1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PromptProductKEPolynomial1dSet


!! -----------------------------------------------------------------------------
!! Child: XYs1d
!! -----------------------------------------------------------------------------

!! Has
function PromptProductKEXYs1dHas(handle) &
      bind(C, name='PromptProductKEXYs1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PromptProductKEXYs1dHas
end function PromptProductKEXYs1dHas

!! Get, const
function PromptProductKEXYs1dGetConst(handle) &
      bind(C, name='PromptProductKEXYs1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PromptProductKEXYs1dGetConst
end function PromptProductKEXYs1dGetConst

!! Get
function PromptProductKEXYs1dGet(handle) &
      bind(C, name='PromptProductKEXYs1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PromptProductKEXYs1dGet
end function PromptProductKEXYs1dGet

!! Set
subroutine PromptProductKEXYs1dSet(handle, fieldHandle) &
      bind(C, name='PromptProductKEXYs1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PromptProductKEXYs1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalPromptProductKE
