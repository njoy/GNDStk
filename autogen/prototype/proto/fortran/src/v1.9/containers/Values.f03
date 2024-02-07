
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module containersValues
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ValuesDefaultConst() &
      bind(C, name='ValuesDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ValuesDefaultConst
end function ValuesDefaultConst

!! Create, default
function ValuesDefault() &
      bind(C, name='ValuesDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ValuesDefault
end function ValuesDefault

!! Create, general, const
function ValuesCreateConst( &
   valueType, &
   start, &
   length, &
   valueTypeSize &
) &
      bind(C, name='ValuesCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: valueTypeSize
   character(c_char), intent(in) :: valueType(valueTypeSize)
   integer(c_int), value, intent(in) :: start
   integer(c_int), value, intent(in) :: length
   type(c_ptr) :: ValuesCreateConst
end function ValuesCreateConst

!! Create, general
function ValuesCreate( &
   valueType, &
   start, &
   length, &
   valueTypeSize &
) &
      bind(C, name='ValuesCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: valueTypeSize
   character(c_char), intent(in) :: valueType(valueTypeSize)
   integer(c_int), value, intent(in) :: start
   integer(c_int), value, intent(in) :: length
   type(c_ptr) :: ValuesCreate
end function ValuesCreate

!! Assign
subroutine ValuesAssign(handleLHS, handleRHS) &
      bind(C, name='ValuesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ValuesAssign

!! Delete
subroutine ValuesDelete(handle) &
      bind(C, name='ValuesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ValuesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ValuesRead(handle, filename, filenameSize) &
      bind(C, name='ValuesRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ValuesRead
end function ValuesRead

!! Write to file
function ValuesWrite(handle, filename, filenameSize) &
      bind(C, name='ValuesWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ValuesWrite
end function ValuesWrite

!! Print to standard output, in our prettyprinting format
function ValuesPrint(handle) &
      bind(C, name='ValuesPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesPrint
end function ValuesPrint

!! Print to standard output, as XML
function ValuesPrintXML(handle) &
      bind(C, name='ValuesPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesPrintXML
end function ValuesPrintXML

!! Print to standard output, as JSON
function ValuesPrintJSON(handle) &
      bind(C, name='ValuesPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesPrintJSON
end function ValuesPrintJSON


!! -----------------------------------------------------------------------------
!! Data vector
!! -----------------------------------------------------------------------------

!! ------------------------
!! int
!! ------------------------

!! Clear
subroutine ValuesIntsClear(handle) &
      bind(C, name='ValuesIntsClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ValuesIntsClear

!! Get size
function ValuesIntsSize(handle) &
      bind(C, name='ValuesIntsSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ValuesIntsSize
end function ValuesIntsSize

!! Get value
!! By index \in [0,size)
function ValuesIntsGet(handle, arrayIndex) &
      bind(C, name='ValuesIntsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   integer(c_int) :: ValuesIntsGet
end function ValuesIntsGet

!! Set value
!! By index \in [0,size)
subroutine ValuesIntsSet(handle, arrayIndex, valueAtIndex) &
      bind(C, name='ValuesIntsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   integer(c_int), intent(in), value :: valueAtIndex
end subroutine ValuesIntsSet

!! Get pointer to existing values, const
function ValuesIntsGetArrayConst(handle) &
      bind(C, name='ValuesIntsGetArrayConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ValuesIntsGetArrayConst
end function ValuesIntsGetArrayConst

!! Get pointer to existing values
function ValuesIntsGetArray(handle) &
      bind(C, name='ValuesIntsGetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ValuesIntsGetArray
end function ValuesIntsGetArray

!! Set completely new values and size
subroutine ValuesIntsSetArray(handle, values, valuesSize) &
      bind(C, name='ValuesIntsSetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: valuesSize
   integer(c_int), intent(in) :: values(valuesSize)
end subroutine ValuesIntsSetArray

!! ------------------------
!! unsigned
!! ------------------------

!! Clear
subroutine ValuesUnsignedsClear(handle) &
      bind(C, name='ValuesUnsignedsClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ValuesUnsignedsClear

!! Get size
function ValuesUnsignedsSize(handle) &
      bind(C, name='ValuesUnsignedsSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ValuesUnsignedsSize
end function ValuesUnsignedsSize

!! Get value
!! By index \in [0,size)
function ValuesUnsignedsGet(handle, arrayIndex) &
      bind(C, name='ValuesUnsignedsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   integer(c_unsigned) :: ValuesUnsignedsGet
end function ValuesUnsignedsGet

!! Set value
!! By index \in [0,size)
subroutine ValuesUnsignedsSet(handle, arrayIndex, valueAtIndex) &
      bind(C, name='ValuesUnsignedsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   integer(c_unsigned), intent(in), value :: valueAtIndex
end subroutine ValuesUnsignedsSet

!! Get pointer to existing values, const
function ValuesUnsignedsGetArrayConst(handle) &
      bind(C, name='ValuesUnsignedsGetArrayConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ValuesUnsignedsGetArrayConst
end function ValuesUnsignedsGetArrayConst

!! Get pointer to existing values
function ValuesUnsignedsGetArray(handle) &
      bind(C, name='ValuesUnsignedsGetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ValuesUnsignedsGetArray
end function ValuesUnsignedsGetArray

!! Set completely new values and size
subroutine ValuesUnsignedsSetArray(handle, values, valuesSize) &
      bind(C, name='ValuesUnsignedsSetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: valuesSize
   integer(c_unsigned), intent(in) :: values(valuesSize)
end subroutine ValuesUnsignedsSetArray

!! ------------------------
!! float
!! ------------------------

!! Clear
subroutine ValuesFloatsClear(handle) &
      bind(C, name='ValuesFloatsClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ValuesFloatsClear

!! Get size
function ValuesFloatsSize(handle) &
      bind(C, name='ValuesFloatsSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ValuesFloatsSize
end function ValuesFloatsSize

!! Get value
!! By index \in [0,size)
function ValuesFloatsGet(handle, arrayIndex) &
      bind(C, name='ValuesFloatsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_float) :: ValuesFloatsGet
end function ValuesFloatsGet

!! Set value
!! By index \in [0,size)
subroutine ValuesFloatsSet(handle, arrayIndex, valueAtIndex) &
      bind(C, name='ValuesFloatsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_float), intent(in), value :: valueAtIndex
end subroutine ValuesFloatsSet

!! Get pointer to existing values, const
function ValuesFloatsGetArrayConst(handle) &
      bind(C, name='ValuesFloatsGetArrayConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ValuesFloatsGetArrayConst
end function ValuesFloatsGetArrayConst

!! Get pointer to existing values
function ValuesFloatsGetArray(handle) &
      bind(C, name='ValuesFloatsGetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ValuesFloatsGetArray
end function ValuesFloatsGetArray

!! Set completely new values and size
subroutine ValuesFloatsSetArray(handle, values, valuesSize) &
      bind(C, name='ValuesFloatsSetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: valuesSize
   real(c_float), intent(in) :: values(valuesSize)
end subroutine ValuesFloatsSetArray

!! ------------------------
!! double
!! ------------------------

!! Clear
subroutine ValuesDoublesClear(handle) &
      bind(C, name='ValuesDoublesClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ValuesDoublesClear

!! Get size
function ValuesDoublesSize(handle) &
      bind(C, name='ValuesDoublesSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ValuesDoublesSize
end function ValuesDoublesSize

!! Get value
!! By index \in [0,size)
function ValuesDoublesGet(handle, arrayIndex) &
      bind(C, name='ValuesDoublesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_double) :: ValuesDoublesGet
end function ValuesDoublesGet

!! Set value
!! By index \in [0,size)
subroutine ValuesDoublesSet(handle, arrayIndex, valueAtIndex) &
      bind(C, name='ValuesDoublesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_double), intent(in), value :: valueAtIndex
end subroutine ValuesDoublesSet

!! Get pointer to existing values, const
function ValuesDoublesGetArrayConst(handle) &
      bind(C, name='ValuesDoublesGetArrayConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ValuesDoublesGetArrayConst
end function ValuesDoublesGetArrayConst

!! Get pointer to existing values
function ValuesDoublesGetArray(handle) &
      bind(C, name='ValuesDoublesGetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ValuesDoublesGetArray
end function ValuesDoublesGetArray

!! Set completely new values and size
subroutine ValuesDoublesSetArray(handle, values, valuesSize) &
      bind(C, name='ValuesDoublesSetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: valuesSize
   real(c_double), intent(in) :: values(valuesSize)
end subroutine ValuesDoublesSetArray


!! -----------------------------------------------------------------------------
!! Metadatum: valueType
!! -----------------------------------------------------------------------------

!! Has
function ValuesValueTypeHas(handle) &
      bind(C, name='ValuesValueTypeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesValueTypeHas
end function ValuesValueTypeHas

!! Get
function ValuesValueTypeGet(handle) &
      bind(C, name='ValuesValueTypeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ValuesValueTypeGet
end function ValuesValueTypeGet

!! Set
subroutine ValuesValueTypeSet(handle, valueType, valueTypeSize) &
      bind(C, name='ValuesValueTypeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: valueTypeSize
   character(c_char), intent(in) :: valueType(valueTypeSize)
end subroutine ValuesValueTypeSet


!! -----------------------------------------------------------------------------
!! Metadatum: start
!! -----------------------------------------------------------------------------

!! Has
function ValuesStartHas(handle) &
      bind(C, name='ValuesStartHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesStartHas
end function ValuesStartHas

!! Get
function ValuesStartGet(handle) &
      bind(C, name='ValuesStartGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesStartGet
end function ValuesStartGet

!! Set
subroutine ValuesStartSet(handle, start, startSize) &
      bind(C, name='ValuesStartSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: startSize
   character(c_char), intent(in) :: start(startSize)
end subroutine ValuesStartSet


!! -----------------------------------------------------------------------------
!! Metadatum: length
!! -----------------------------------------------------------------------------

!! Has
function ValuesLengthHas(handle) &
      bind(C, name='ValuesLengthHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesLengthHas
end function ValuesLengthHas

!! Get
function ValuesLengthGet(handle) &
      bind(C, name='ValuesLengthGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ValuesLengthGet
end function ValuesLengthGet

!! Set
subroutine ValuesLengthSet(handle, length, lengthSize) &
      bind(C, name='ValuesLengthSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: lengthSize
   character(c_char), intent(in) :: length(lengthSize)
end subroutine ValuesLengthSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module containersValues