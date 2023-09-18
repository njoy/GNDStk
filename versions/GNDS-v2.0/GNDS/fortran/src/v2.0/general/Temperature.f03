
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalTemperature
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function TemperatureDefaultConst() &
      bind(C, name='TemperatureDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function TemperatureDefaultConst

!! Create, default
function TemperatureDefault() &
      bind(C, name='TemperatureDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function TemperatureDefault

!! Create, general, const
function TemperatureCreateConst( &
   value, &
   unit, &
   unitSize &
) &
      bind(C, name='TemperatureCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   real(c_double), value, intent(in) :: value
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr) :: handle
end function TemperatureCreateConst

!! Create, general
function TemperatureCreate( &
   value, &
   unit, &
   unitSize &
) &
      bind(C, name='TemperatureCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   real(c_double), value, intent(in) :: value
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr) :: handle
end function TemperatureCreate

!! Assign
subroutine TemperatureAssign(handleLHS, handleRHS) &
      bind(C, name='TemperatureAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine TemperatureAssign

!! Delete
subroutine TemperatureDelete(handle) &
      bind(C, name='TemperatureDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine TemperatureDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function TemperatureRead(handle, filename, filenameSize) &
      bind(C, name='TemperatureRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function TemperatureRead

!! Write to file
function TemperatureWrite(handle, filename, filenameSize) &
      bind(C, name='TemperatureWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function TemperatureWrite

!! Print to standard output, in our prettyprinting format
function TemperaturePrint(handle) &
      bind(C, name='TemperaturePrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function TemperaturePrint

!! Print to standard output, as XML
function TemperaturePrintXML(handle) &
      bind(C, name='TemperaturePrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function TemperaturePrintXML

!! Print to standard output, as JSON
function TemperaturePrintJSON(handle) &
      bind(C, name='TemperaturePrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function TemperaturePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: value
!! -----------------------------------------------------------------------------

!! Has
function TemperatureValueHas(handle) &
      bind(C, name='TemperatureValueHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TemperatureValueHas

!! Get
function TemperatureValueGet(handle) &
      bind(C, name='TemperatureValueGet') &
      result(value)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: value
end function TemperatureValueGet

!! Set
subroutine TemperatureValueSet(handle, value, valueSize) &
      bind(C, name='TemperatureValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
end subroutine TemperatureValueSet


!! -----------------------------------------------------------------------------
!! Metadatum: unit
!! -----------------------------------------------------------------------------

!! Has
function TemperatureUnitHas(handle) &
      bind(C, name='TemperatureUnitHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TemperatureUnitHas

!! Get
function TemperatureUnitGet(handle) &
      bind(C, name='TemperatureUnitGet') &
      result(unit)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: unit
end function TemperatureUnitGet

!! Set
subroutine TemperatureUnitSet(handle, unit, unitSize) &
      bind(C, name='TemperatureUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
end subroutine TemperatureUnitSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalTemperature
