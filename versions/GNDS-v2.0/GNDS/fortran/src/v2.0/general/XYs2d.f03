
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalXYs2d
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function XYs2dDefaultConst() &
      bind(C, name='XYs2dDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: XYs2dDefaultConst
end function XYs2dDefaultConst

!! Create, default
function XYs2dDefault() &
      bind(C, name='XYs2dDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: XYs2dDefault
end function XYs2dDefault

!! Create, general, const
function XYs2dCreateConst( &
   index, &
   interpolation, &
   interpolationQualifier, &
   outerDomainValue, &
   axes, &
   function1ds, &
   uncertainty, &
   interpolationSize, &
   interpolationQualifierSize &
) &
      bind(C, name='XYs2dCreateConst')
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: index
   integer(c_size_t), intent(in), value :: interpolationSize
   character(c_char), intent(in) :: interpolation(interpolationSize)
   integer(c_size_t), intent(in), value :: interpolationQualifierSize
   character(c_char), intent(in) :: interpolationQualifier(interpolationQualifierSize)
   real(c_double), value, intent(in) :: outerDomainValue
   type(c_ptr), value :: axes
   type(c_ptr), value :: function1ds
   type(c_ptr), value :: uncertainty
   type(c_ptr) :: XYs2dCreateConst
end function XYs2dCreateConst

!! Create, general
function XYs2dCreate( &
   index, &
   interpolation, &
   interpolationQualifier, &
   outerDomainValue, &
   axes, &
   function1ds, &
   uncertainty, &
   interpolationSize, &
   interpolationQualifierSize &
) &
      bind(C, name='XYs2dCreate')
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: index
   integer(c_size_t), intent(in), value :: interpolationSize
   character(c_char), intent(in) :: interpolation(interpolationSize)
   integer(c_size_t), intent(in), value :: interpolationQualifierSize
   character(c_char), intent(in) :: interpolationQualifier(interpolationQualifierSize)
   real(c_double), value, intent(in) :: outerDomainValue
   type(c_ptr), value :: axes
   type(c_ptr), value :: function1ds
   type(c_ptr), value :: uncertainty
   type(c_ptr) :: XYs2dCreate
end function XYs2dCreate

!! Assign
subroutine XYs2dAssign(handleLHS, handleRHS) &
      bind(C, name='XYs2dAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine XYs2dAssign

!! Delete
subroutine XYs2dDelete(handle) &
      bind(C, name='XYs2dDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine XYs2dDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function XYs2dRead(handle, filename, filenameSize) &
      bind(C, name='XYs2dRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: XYs2dRead
end function XYs2dRead

!! Write to file
function XYs2dWrite(handle, filename, filenameSize) &
      bind(C, name='XYs2dWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: XYs2dWrite
end function XYs2dWrite

!! Print to standard output, in our prettyprinting format
function XYs2dPrint(handle) &
      bind(C, name='XYs2dPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dPrint
end function XYs2dPrint

!! Print to standard output, as XML
function XYs2dPrintXML(handle) &
      bind(C, name='XYs2dPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dPrintXML
end function XYs2dPrintXML

!! Print to standard output, as JSON
function XYs2dPrintJSON(handle) &
      bind(C, name='XYs2dPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dPrintJSON
end function XYs2dPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: index
!! -----------------------------------------------------------------------------

!! Has
function XYs2dIndexHas(handle) &
      bind(C, name='XYs2dIndexHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dIndexHas
end function XYs2dIndexHas

!! Get
function XYs2dIndexGet(handle) &
      bind(C, name='XYs2dIndexGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dIndexGet
end function XYs2dIndexGet

!! Set
subroutine XYs2dIndexSet(handle, index, indexSize) &
      bind(C, name='XYs2dIndexSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: indexSize
   character(c_char), intent(in) :: index(indexSize)
end subroutine XYs2dIndexSet


!! -----------------------------------------------------------------------------
!! Metadatum: interpolation
!! -----------------------------------------------------------------------------

!! Has
function XYs2dInterpolationHas(handle) &
      bind(C, name='XYs2dInterpolationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dInterpolationHas
end function XYs2dInterpolationHas

!! Get
function XYs2dInterpolationGet(handle) &
      bind(C, name='XYs2dInterpolationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dInterpolationGet
end function XYs2dInterpolationGet

!! Set
subroutine XYs2dInterpolationSet(handle, interpolation, interpolationSize) &
      bind(C, name='XYs2dInterpolationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: interpolationSize
   character(c_char), intent(in) :: interpolation(interpolationSize)
end subroutine XYs2dInterpolationSet


!! -----------------------------------------------------------------------------
!! Metadatum: interpolationQualifier
!! -----------------------------------------------------------------------------

!! Has
function XYs2dInterpolationQualifierHas(handle) &
      bind(C, name='XYs2dInterpolationQualifierHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dInterpolationQualifierHas
end function XYs2dInterpolationQualifierHas

!! Get
function XYs2dInterpolationQualifierGet(handle) &
      bind(C, name='XYs2dInterpolationQualifierGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dInterpolationQualifierGet
end function XYs2dInterpolationQualifierGet

!! Set
subroutine XYs2dInterpolationQualifierSet(handle, interpolationQualifier, interpolationQualifierSize) &
      bind(C, name='XYs2dInterpolationQualifierSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: interpolationQualifierSize
   character(c_char), intent(in) :: interpolationQualifier(interpolationQualifierSize)
end subroutine XYs2dInterpolationQualifierSet


!! -----------------------------------------------------------------------------
!! Metadatum: outerDomainValue
!! -----------------------------------------------------------------------------

!! Has
function XYs2dOuterDomainValueHas(handle) &
      bind(C, name='XYs2dOuterDomainValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dOuterDomainValueHas
end function XYs2dOuterDomainValueHas

!! Get
function XYs2dOuterDomainValueGet(handle) &
      bind(C, name='XYs2dOuterDomainValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: XYs2dOuterDomainValueGet
end function XYs2dOuterDomainValueGet

!! Set
subroutine XYs2dOuterDomainValueSet(handle, outerDomainValue, outerDomainValueSize) &
      bind(C, name='XYs2dOuterDomainValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: outerDomainValueSize
   character(c_char), intent(in) :: outerDomainValue(outerDomainValueSize)
end subroutine XYs2dOuterDomainValueSet


!! -----------------------------------------------------------------------------
!! Child: axes
!! -----------------------------------------------------------------------------

!! Has
function XYs2dAxesHas(handle) &
      bind(C, name='XYs2dAxesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dAxesHas
end function XYs2dAxesHas

!! Get, const
function XYs2dAxesGetConst(handle) &
      bind(C, name='XYs2dAxesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dAxesGetConst
end function XYs2dAxesGetConst

!! Get
function XYs2dAxesGet(handle) &
      bind(C, name='XYs2dAxesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dAxesGet
end function XYs2dAxesGet

!! Set
subroutine XYs2dAxesSet(handle, fieldHandle) &
      bind(C, name='XYs2dAxesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine XYs2dAxesSet


!! -----------------------------------------------------------------------------
!! Child: function1ds
!! -----------------------------------------------------------------------------

!! Has
function XYs2dFunction1dsHas(handle) &
      bind(C, name='XYs2dFunction1dsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dFunction1dsHas
end function XYs2dFunction1dsHas

!! Get, const
function XYs2dFunction1dsGetConst(handle) &
      bind(C, name='XYs2dFunction1dsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dFunction1dsGetConst
end function XYs2dFunction1dsGetConst

!! Get
function XYs2dFunction1dsGet(handle) &
      bind(C, name='XYs2dFunction1dsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dFunction1dsGet
end function XYs2dFunction1dsGet

!! Set
subroutine XYs2dFunction1dsSet(handle, fieldHandle) &
      bind(C, name='XYs2dFunction1dsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine XYs2dFunction1dsSet


!! -----------------------------------------------------------------------------
!! Child: uncertainty
!! -----------------------------------------------------------------------------

!! Has
function XYs2dUncertaintyHas(handle) &
      bind(C, name='XYs2dUncertaintyHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: XYs2dUncertaintyHas
end function XYs2dUncertaintyHas

!! Get, const
function XYs2dUncertaintyGetConst(handle) &
      bind(C, name='XYs2dUncertaintyGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dUncertaintyGetConst
end function XYs2dUncertaintyGetConst

!! Get
function XYs2dUncertaintyGet(handle) &
      bind(C, name='XYs2dUncertaintyGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: XYs2dUncertaintyGet
end function XYs2dUncertaintyGet

!! Set
subroutine XYs2dUncertaintySet(handle, fieldHandle) &
      bind(C, name='XYs2dUncertaintySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine XYs2dUncertaintySet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalXYs2d
