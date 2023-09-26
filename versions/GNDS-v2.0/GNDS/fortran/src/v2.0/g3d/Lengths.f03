
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module g3dLengths
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function LengthsDefaultConst() &
      bind(C, name='LengthsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LengthsDefaultConst
end function LengthsDefaultConst

!! Create, default
function LengthsDefault() &
      bind(C, name='LengthsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LengthsDefault
end function LengthsDefault

!! Create, general, const
function LengthsCreateConst( &
   valueType, &
   label, &
   valueTypeSize, &
   labelSize &
) &
      bind(C, name='LengthsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: valueTypeSize
   character(c_char), intent(in) :: valueType(valueTypeSize)
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr) :: LengthsCreateConst
end function LengthsCreateConst

!! Create, general
function LengthsCreate( &
   valueType, &
   label, &
   valueTypeSize, &
   labelSize &
) &
      bind(C, name='LengthsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: valueTypeSize
   character(c_char), intent(in) :: valueType(valueTypeSize)
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr) :: LengthsCreate
end function LengthsCreate

!! Assign
subroutine LengthsAssign(handleLHS, handleRHS) &
      bind(C, name='LengthsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine LengthsAssign

!! Delete
subroutine LengthsDelete(handle) &
      bind(C, name='LengthsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine LengthsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function LengthsRead(handle, filename, filenameSize) &
      bind(C, name='LengthsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LengthsRead
end function LengthsRead

!! Write to file
function LengthsWrite(handle, filename, filenameSize) &
      bind(C, name='LengthsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LengthsWrite
end function LengthsWrite

!! Print to standard output, in our prettyprinting format
function LengthsPrint(handle) &
      bind(C, name='LengthsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LengthsPrint
end function LengthsPrint

!! Print to standard output, as XML
function LengthsPrintXML(handle) &
      bind(C, name='LengthsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LengthsPrintXML
end function LengthsPrintXML

!! Print to standard output, as JSON
function LengthsPrintJSON(handle) &
      bind(C, name='LengthsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LengthsPrintJSON
end function LengthsPrintJSON


!! -----------------------------------------------------------------------------
!! Data vector
!! -----------------------------------------------------------------------------

!! Clear
subroutine LengthsIntsClear(handle) &
      bind(C, name='LengthsIntsClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine LengthsIntsClear

!! Get size
function LengthsIntsSize(handle) &
      bind(C, name='LengthsIntsSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: LengthsIntsSize
end function LengthsIntsSize

!! Get value
!! By index \in [0,size)
function LengthsIntsGet(handle, arrayIndex) &
      bind(C, name='LengthsIntsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   integer(c_int) :: LengthsIntsGet
end function LengthsIntsGet

!! Set value
!! By index \in [0,size)
subroutine LengthsIntsSet(handle, arrayIndex, valueAtIndex) &
      bind(C, name='LengthsIntsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   integer(c_int), intent(in), value :: valueAtIndex
end subroutine LengthsIntsSet

!! Get pointer to existing values, const
function LengthsIntsGetArrayConst(handle) &
      bind(C, name='LengthsIntsGetArrayConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LengthsIntsGetArrayConst
end function LengthsIntsGetArrayConst

!! Get pointer to existing values
function LengthsIntsGetArray(handle) &
      bind(C, name='LengthsIntsGetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: LengthsIntsGetArray
end function LengthsIntsGetArray

!! Set completely new values and size
subroutine LengthsIntsSetArray(handle, values, valuesSize) &
      bind(C, name='LengthsIntsSetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: valuesSize
   integer(c_int), intent(in) :: values(valuesSize)
end subroutine LengthsIntsSetArray


!! -----------------------------------------------------------------------------
!! Metadatum: valueType
!! -----------------------------------------------------------------------------

!! Has
function LengthsValueTypeHas(handle) &
      bind(C, name='LengthsValueTypeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LengthsValueTypeHas
end function LengthsValueTypeHas

!! Get
function LengthsValueTypeGet(handle) &
      bind(C, name='LengthsValueTypeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LengthsValueTypeGet
end function LengthsValueTypeGet

!! Set
subroutine LengthsValueTypeSet(handle, valueType, valueTypeSize) &
      bind(C, name='LengthsValueTypeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: valueTypeSize
   character(c_char), intent(in) :: valueType(valueTypeSize)
end subroutine LengthsValueTypeSet


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function LengthsLabelHas(handle) &
      bind(C, name='LengthsLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LengthsLabelHas
end function LengthsLabelHas

!! Get
function LengthsLabelGet(handle) &
      bind(C, name='LengthsLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LengthsLabelGet
end function LengthsLabelGet

!! Set
subroutine LengthsLabelSet(handle, label, labelSize) &
      bind(C, name='LengthsLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine LengthsLabelSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module g3dLengths
