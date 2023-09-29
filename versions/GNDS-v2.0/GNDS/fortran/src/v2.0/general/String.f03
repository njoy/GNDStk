
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalString
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function StringDefaultConst() &
      bind(C, name='StringDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: StringDefaultConst
end function StringDefaultConst

!! Create, default
function StringDefault() &
      bind(C, name='StringDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: StringDefault
end function StringDefault

!! Create, general, const
function StringCreateConst( &
   label, &
   value, &
   unit, &
   labelSize, &
   valueSize, &
   unitSize &
) &
      bind(C, name='StringCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr) :: StringCreateConst
end function StringCreateConst

!! Create, general
function StringCreate( &
   label, &
   value, &
   unit, &
   labelSize, &
   valueSize, &
   unitSize &
) &
      bind(C, name='StringCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr) :: StringCreate
end function StringCreate

!! Assign
subroutine StringAssign(handleLHS, handleRHS) &
      bind(C, name='StringAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine StringAssign

!! Delete
subroutine StringDelete(handle) &
      bind(C, name='StringDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine StringDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function StringRead(handle, filename, filenameSize) &
      bind(C, name='StringRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: StringRead
end function StringRead

!! Write to file
function StringWrite(handle, filename, filenameSize) &
      bind(C, name='StringWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: StringWrite
end function StringWrite

!! Print to standard output, in our prettyprinting format
function StringPrint(handle) &
      bind(C, name='StringPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StringPrint
end function StringPrint

!! Print to standard output, as XML
function StringPrintXML(handle) &
      bind(C, name='StringPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StringPrintXML
end function StringPrintXML

!! Print to standard output, as JSON
function StringPrintJSON(handle) &
      bind(C, name='StringPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StringPrintJSON
end function StringPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function StringLabelHas(handle) &
      bind(C, name='StringLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StringLabelHas
end function StringLabelHas

!! Get
function StringLabelGet(handle) &
      bind(C, name='StringLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: StringLabelGet
end function StringLabelGet

!! Set
subroutine StringLabelSet(handle, label, labelSize) &
      bind(C, name='StringLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine StringLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: value
!! -----------------------------------------------------------------------------

!! Has
function StringValueHas(handle) &
      bind(C, name='StringValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StringValueHas
end function StringValueHas

!! Get
function StringValueGet(handle) &
      bind(C, name='StringValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: StringValueGet
end function StringValueGet

!! Set
subroutine StringValueSet(handle, value, valueSize) &
      bind(C, name='StringValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
end subroutine StringValueSet


!! -----------------------------------------------------------------------------
!! Metadatum: unit
!! -----------------------------------------------------------------------------

!! Has
function StringUnitHas(handle) &
      bind(C, name='StringUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StringUnitHas
end function StringUnitHas

!! Get
function StringUnitGet(handle) &
      bind(C, name='StringUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: StringUnitGet
end function StringUnitGet

!! Set
subroutine StringUnitSet(handle, unit, unitSize) &
      bind(C, name='StringUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
end subroutine StringUnitSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalString
