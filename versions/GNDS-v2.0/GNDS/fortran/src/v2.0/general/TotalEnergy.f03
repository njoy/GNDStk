
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalTotalEnergy
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function TotalEnergyDefaultConst() &
      bind(C, name='TotalEnergyDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: TotalEnergyDefaultConst
end function TotalEnergyDefaultConst

!! Create, default
function TotalEnergyDefault() &
      bind(C, name='TotalEnergyDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: TotalEnergyDefault
end function TotalEnergyDefault

!! Create, general, const
function TotalEnergyCreateConst( &
   polynomial1d &
) &
      bind(C, name='TotalEnergyCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: polynomial1d
   type(c_ptr) :: TotalEnergyCreateConst
end function TotalEnergyCreateConst

!! Create, general
function TotalEnergyCreate( &
   polynomial1d &
) &
      bind(C, name='TotalEnergyCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: polynomial1d
   type(c_ptr) :: TotalEnergyCreate
end function TotalEnergyCreate

!! Assign
subroutine TotalEnergyAssign(handleLHS, handleRHS) &
      bind(C, name='TotalEnergyAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine TotalEnergyAssign

!! Delete
subroutine TotalEnergyDelete(handle) &
      bind(C, name='TotalEnergyDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine TotalEnergyDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function TotalEnergyRead(handle, filename, filenameSize) &
      bind(C, name='TotalEnergyRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: TotalEnergyRead
end function TotalEnergyRead

!! Write to file
function TotalEnergyWrite(handle, filename, filenameSize) &
      bind(C, name='TotalEnergyWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: TotalEnergyWrite
end function TotalEnergyWrite

!! Print to standard output, in our prettyprinting format
function TotalEnergyPrint(handle) &
      bind(C, name='TotalEnergyPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TotalEnergyPrint
end function TotalEnergyPrint

!! Print to standard output, as XML
function TotalEnergyPrintXML(handle) &
      bind(C, name='TotalEnergyPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TotalEnergyPrintXML
end function TotalEnergyPrintXML

!! Print to standard output, as JSON
function TotalEnergyPrintJSON(handle) &
      bind(C, name='TotalEnergyPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TotalEnergyPrintJSON
end function TotalEnergyPrintJSON


!! -----------------------------------------------------------------------------
!! Child: polynomial1d
!! -----------------------------------------------------------------------------

!! Has
function TotalEnergyPolynomial1dHas(handle) &
      bind(C, name='TotalEnergyPolynomial1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: TotalEnergyPolynomial1dHas
end function TotalEnergyPolynomial1dHas

!! Get, const
function TotalEnergyPolynomial1dGetConst(handle) &
      bind(C, name='TotalEnergyPolynomial1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: TotalEnergyPolynomial1dGetConst
end function TotalEnergyPolynomial1dGetConst

!! Get
function TotalEnergyPolynomial1dGet(handle) &
      bind(C, name='TotalEnergyPolynomial1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: TotalEnergyPolynomial1dGet
end function TotalEnergyPolynomial1dGet

!! Set
subroutine TotalEnergyPolynomial1dSet(handle, fieldHandle) &
      bind(C, name='TotalEnergyPolynomial1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine TotalEnergyPolynomial1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalTotalEnergy
