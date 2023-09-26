
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalAverageProductEnergy
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AverageProductEnergyDefaultConst() &
      bind(C, name='AverageProductEnergyDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AverageProductEnergyDefaultConst
end function AverageProductEnergyDefaultConst

!! Create, default
function AverageProductEnergyDefault() &
      bind(C, name='AverageProductEnergyDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AverageProductEnergyDefault
end function AverageProductEnergyDefault

!! Create, general, const
function AverageProductEnergyCreateConst( &
   XYs1d &
) &
      bind(C, name='AverageProductEnergyCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: XYs1d
   type(c_ptr) :: AverageProductEnergyCreateConst
end function AverageProductEnergyCreateConst

!! Create, general
function AverageProductEnergyCreate( &
   XYs1d &
) &
      bind(C, name='AverageProductEnergyCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: XYs1d
   type(c_ptr) :: AverageProductEnergyCreate
end function AverageProductEnergyCreate

!! Assign
subroutine AverageProductEnergyAssign(handleLHS, handleRHS) &
      bind(C, name='AverageProductEnergyAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine AverageProductEnergyAssign

!! Delete
subroutine AverageProductEnergyDelete(handle) &
      bind(C, name='AverageProductEnergyDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AverageProductEnergyDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function AverageProductEnergyRead(handle, filename, filenameSize) &
      bind(C, name='AverageProductEnergyRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AverageProductEnergyRead
end function AverageProductEnergyRead

!! Write to file
function AverageProductEnergyWrite(handle, filename, filenameSize) &
      bind(C, name='AverageProductEnergyWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AverageProductEnergyWrite
end function AverageProductEnergyWrite

!! Print to standard output, in our prettyprinting format
function AverageProductEnergyPrint(handle) &
      bind(C, name='AverageProductEnergyPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageProductEnergyPrint
end function AverageProductEnergyPrint

!! Print to standard output, as XML
function AverageProductEnergyPrintXML(handle) &
      bind(C, name='AverageProductEnergyPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageProductEnergyPrintXML
end function AverageProductEnergyPrintXML

!! Print to standard output, as JSON
function AverageProductEnergyPrintJSON(handle) &
      bind(C, name='AverageProductEnergyPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageProductEnergyPrintJSON
end function AverageProductEnergyPrintJSON


!! -----------------------------------------------------------------------------
!! Child: XYs1d
!! -----------------------------------------------------------------------------

!! Has
function AverageProductEnergyXYs1dHas(handle) &
      bind(C, name='AverageProductEnergyXYs1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageProductEnergyXYs1dHas
end function AverageProductEnergyXYs1dHas

!! Get, const
function AverageProductEnergyXYs1dGetConst(handle) &
      bind(C, name='AverageProductEnergyXYs1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AverageProductEnergyXYs1dGetConst
end function AverageProductEnergyXYs1dGetConst

!! Get
function AverageProductEnergyXYs1dGet(handle) &
      bind(C, name='AverageProductEnergyXYs1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AverageProductEnergyXYs1dGet
end function AverageProductEnergyXYs1dGet

!! Set
subroutine AverageProductEnergyXYs1dSet(handle, fieldHandle) &
      bind(C, name='AverageProductEnergyXYs1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine AverageProductEnergyXYs1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalAverageProductEnergy
