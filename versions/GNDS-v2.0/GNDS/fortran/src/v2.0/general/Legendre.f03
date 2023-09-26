
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalLegendre
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function LegendreDefaultConst() &
      bind(C, name='LegendreDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LegendreDefaultConst
end function LegendreDefaultConst

!! Create, default
function LegendreDefault() &
      bind(C, name='LegendreDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LegendreDefault
end function LegendreDefault

!! Create, general, const
function LegendreCreateConst( &
   outerDomainValue, &
   values &
) &
      bind(C, name='LegendreCreateConst')
   use iso_c_binding
   implicit none
   real(c_double), value, intent(in) :: outerDomainValue
   type(c_ptr), value :: values
   type(c_ptr) :: LegendreCreateConst
end function LegendreCreateConst

!! Create, general
function LegendreCreate( &
   outerDomainValue, &
   values &
) &
      bind(C, name='LegendreCreate')
   use iso_c_binding
   implicit none
   real(c_double), value, intent(in) :: outerDomainValue
   type(c_ptr), value :: values
   type(c_ptr) :: LegendreCreate
end function LegendreCreate

!! Assign
subroutine LegendreAssign(handleLHS, handleRHS) &
      bind(C, name='LegendreAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine LegendreAssign

!! Delete
subroutine LegendreDelete(handle) &
      bind(C, name='LegendreDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine LegendreDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function LegendreRead(handle, filename, filenameSize) &
      bind(C, name='LegendreRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LegendreRead
end function LegendreRead

!! Write to file
function LegendreWrite(handle, filename, filenameSize) &
      bind(C, name='LegendreWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LegendreWrite
end function LegendreWrite

!! Print to standard output, in our prettyprinting format
function LegendrePrint(handle) &
      bind(C, name='LegendrePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LegendrePrint
end function LegendrePrint

!! Print to standard output, as XML
function LegendrePrintXML(handle) &
      bind(C, name='LegendrePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LegendrePrintXML
end function LegendrePrintXML

!! Print to standard output, as JSON
function LegendrePrintJSON(handle) &
      bind(C, name='LegendrePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LegendrePrintJSON
end function LegendrePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: outerDomainValue
!! -----------------------------------------------------------------------------

!! Has
function LegendreOuterDomainValueHas(handle) &
      bind(C, name='LegendreOuterDomainValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LegendreOuterDomainValueHas
end function LegendreOuterDomainValueHas

!! Get
function LegendreOuterDomainValueGet(handle) &
      bind(C, name='LegendreOuterDomainValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: LegendreOuterDomainValueGet
end function LegendreOuterDomainValueGet

!! Set
subroutine LegendreOuterDomainValueSet(handle, outerDomainValue, outerDomainValueSize) &
      bind(C, name='LegendreOuterDomainValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: outerDomainValueSize
   character(c_char), intent(in) :: outerDomainValue(outerDomainValueSize)
end subroutine LegendreOuterDomainValueSet


!! -----------------------------------------------------------------------------
!! Child: values
!! -----------------------------------------------------------------------------

!! Has
function LegendreValuesHas(handle) &
      bind(C, name='LegendreValuesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LegendreValuesHas
end function LegendreValuesHas

!! Get, const
function LegendreValuesGetConst(handle) &
      bind(C, name='LegendreValuesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LegendreValuesGetConst
end function LegendreValuesGetConst

!! Get
function LegendreValuesGet(handle) &
      bind(C, name='LegendreValuesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LegendreValuesGet
end function LegendreValuesGet

!! Set
subroutine LegendreValuesSet(handle, fieldHandle) &
      bind(C, name='LegendreValuesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine LegendreValuesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalLegendre
