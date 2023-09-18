
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalAverageEnergy
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AverageEnergyDefaultConst() &
      bind(C, name='AverageEnergyDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function AverageEnergyDefaultConst

!! Create, default
function AverageEnergyDefault() &
      bind(C, name='AverageEnergyDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function AverageEnergyDefault

!! Create, general, const
function AverageEnergyCreateConst( &
   label, &
   value, &
   unit, &
   uncertainty, &
   labelSize, &
   unitSize &
) &
      bind(C, name='AverageEnergyCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   real(c_double), value, intent(in) :: value
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr), value :: uncertainty
   type(c_ptr) :: handle
end function AverageEnergyCreateConst

!! Create, general
function AverageEnergyCreate( &
   label, &
   value, &
   unit, &
   uncertainty, &
   labelSize, &
   unitSize &
) &
      bind(C, name='AverageEnergyCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   real(c_double), value, intent(in) :: value
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr), value :: uncertainty
   type(c_ptr) :: handle
end function AverageEnergyCreate

!! Assign
subroutine AverageEnergyAssign(handleLHS, handleRHS) &
      bind(C, name='AverageEnergyAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine AverageEnergyAssign

!! Delete
subroutine AverageEnergyDelete(handle) &
      bind(C, name='AverageEnergyDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AverageEnergyDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function AverageEnergyRead(handle, filename, filenameSize) &
      bind(C, name='AverageEnergyRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function AverageEnergyRead

!! Write to file
function AverageEnergyWrite(handle, filename, filenameSize) &
      bind(C, name='AverageEnergyWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function AverageEnergyWrite

!! Print to standard output, in our prettyprinting format
function AverageEnergyPrint(handle) &
      bind(C, name='AverageEnergyPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function AverageEnergyPrint

!! Print to standard output, as XML
function AverageEnergyPrintXML(handle) &
      bind(C, name='AverageEnergyPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function AverageEnergyPrintXML

!! Print to standard output, as JSON
function AverageEnergyPrintJSON(handle) &
      bind(C, name='AverageEnergyPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function AverageEnergyPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function AverageEnergyLabelHas(handle) &
      bind(C, name='AverageEnergyLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function AverageEnergyLabelHas

!! Get
function AverageEnergyLabelGet(handle) &
      bind(C, name='AverageEnergyLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function AverageEnergyLabelGet

!! Set
subroutine AverageEnergyLabelSet(handle, label, labelSize) &
      bind(C, name='AverageEnergyLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine AverageEnergyLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: value
!! -----------------------------------------------------------------------------

!! Has
function AverageEnergyValueHas(handle) &
      bind(C, name='AverageEnergyValueHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function AverageEnergyValueHas

!! Get
function AverageEnergyValueGet(handle) &
      bind(C, name='AverageEnergyValueGet') &
      result(value)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: value
end function AverageEnergyValueGet

!! Set
subroutine AverageEnergyValueSet(handle, value, valueSize) &
      bind(C, name='AverageEnergyValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
end subroutine AverageEnergyValueSet


!! -----------------------------------------------------------------------------
!! Metadatum: unit
!! -----------------------------------------------------------------------------

!! Has
function AverageEnergyUnitHas(handle) &
      bind(C, name='AverageEnergyUnitHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function AverageEnergyUnitHas

!! Get
function AverageEnergyUnitGet(handle) &
      bind(C, name='AverageEnergyUnitGet') &
      result(unit)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: unit
end function AverageEnergyUnitGet

!! Set
subroutine AverageEnergyUnitSet(handle, unit, unitSize) &
      bind(C, name='AverageEnergyUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
end subroutine AverageEnergyUnitSet


!! -----------------------------------------------------------------------------
!! Child: uncertainty
!! -----------------------------------------------------------------------------

!! Has
function AverageEnergyUncertaintyHas(handle) &
      bind(C, name='AverageEnergyUncertaintyHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function AverageEnergyUncertaintyHas

!! Get, const
function AverageEnergyUncertaintyGetConst(handle) &
      bind(C, name='AverageEnergyUncertaintyGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function AverageEnergyUncertaintyGetConst

!! Get
function AverageEnergyUncertaintyGet(handle) &
      bind(C, name='AverageEnergyUncertaintyGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function AverageEnergyUncertaintyGet

!! Set
subroutine AverageEnergyUncertaintySet(handle, fieldHandle) &
      bind(C, name='AverageEnergyUncertaintySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine AverageEnergyUncertaintySet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalAverageEnergy
