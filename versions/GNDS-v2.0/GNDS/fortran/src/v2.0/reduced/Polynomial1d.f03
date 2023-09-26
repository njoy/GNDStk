
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module reducedPolynomial1d
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function Polynomial1dDefaultConst() &
      bind(C, name='Polynomial1dDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Polynomial1dDefaultConst
end function Polynomial1dDefaultConst

!! Create, default
function Polynomial1dDefault() &
      bind(C, name='Polynomial1dDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Polynomial1dDefault
end function Polynomial1dDefault

!! Create, general, const
function Polynomial1dCreateConst( &
   domainMin, &
   domainMax, &
   axes, &
   values &
) &
      bind(C, name='Polynomial1dCreateConst')
   use iso_c_binding
   implicit none
   real(c_double), value, intent(in) :: domainMin
   real(c_double), value, intent(in) :: domainMax
   type(c_ptr), value :: axes
   type(c_ptr), value :: values
   type(c_ptr) :: Polynomial1dCreateConst
end function Polynomial1dCreateConst

!! Create, general
function Polynomial1dCreate( &
   domainMin, &
   domainMax, &
   axes, &
   values &
) &
      bind(C, name='Polynomial1dCreate')
   use iso_c_binding
   implicit none
   real(c_double), value, intent(in) :: domainMin
   real(c_double), value, intent(in) :: domainMax
   type(c_ptr), value :: axes
   type(c_ptr), value :: values
   type(c_ptr) :: Polynomial1dCreate
end function Polynomial1dCreate

!! Assign
subroutine Polynomial1dAssign(handleLHS, handleRHS) &
      bind(C, name='Polynomial1dAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine Polynomial1dAssign

!! Delete
subroutine Polynomial1dDelete(handle) &
      bind(C, name='Polynomial1dDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine Polynomial1dDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function Polynomial1dRead(handle, filename, filenameSize) &
      bind(C, name='Polynomial1dRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Polynomial1dRead
end function Polynomial1dRead

!! Write to file
function Polynomial1dWrite(handle, filename, filenameSize) &
      bind(C, name='Polynomial1dWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Polynomial1dWrite
end function Polynomial1dWrite

!! Print to standard output, in our prettyprinting format
function Polynomial1dPrint(handle) &
      bind(C, name='Polynomial1dPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Polynomial1dPrint
end function Polynomial1dPrint

!! Print to standard output, as XML
function Polynomial1dPrintXML(handle) &
      bind(C, name='Polynomial1dPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Polynomial1dPrintXML
end function Polynomial1dPrintXML

!! Print to standard output, as JSON
function Polynomial1dPrintJSON(handle) &
      bind(C, name='Polynomial1dPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Polynomial1dPrintJSON
end function Polynomial1dPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: domainMin
!! -----------------------------------------------------------------------------

!! Has
function Polynomial1dDomainMinHas(handle) &
      bind(C, name='Polynomial1dDomainMinHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Polynomial1dDomainMinHas
end function Polynomial1dDomainMinHas

!! Get
function Polynomial1dDomainMinGet(handle) &
      bind(C, name='Polynomial1dDomainMinGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: Polynomial1dDomainMinGet
end function Polynomial1dDomainMinGet

!! Set
subroutine Polynomial1dDomainMinSet(handle, domainMin, domainMinSize) &
      bind(C, name='Polynomial1dDomainMinSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainMinSize
   character(c_char), intent(in) :: domainMin(domainMinSize)
end subroutine Polynomial1dDomainMinSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainMax
!! -----------------------------------------------------------------------------

!! Has
function Polynomial1dDomainMaxHas(handle) &
      bind(C, name='Polynomial1dDomainMaxHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Polynomial1dDomainMaxHas
end function Polynomial1dDomainMaxHas

!! Get
function Polynomial1dDomainMaxGet(handle) &
      bind(C, name='Polynomial1dDomainMaxGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: Polynomial1dDomainMaxGet
end function Polynomial1dDomainMaxGet

!! Set
subroutine Polynomial1dDomainMaxSet(handle, domainMax, domainMaxSize) &
      bind(C, name='Polynomial1dDomainMaxSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainMaxSize
   character(c_char), intent(in) :: domainMax(domainMaxSize)
end subroutine Polynomial1dDomainMaxSet


!! -----------------------------------------------------------------------------
!! Child: axes
!! -----------------------------------------------------------------------------

!! Has
function Polynomial1dAxesHas(handle) &
      bind(C, name='Polynomial1dAxesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Polynomial1dAxesHas
end function Polynomial1dAxesHas

!! Get, const
function Polynomial1dAxesGetConst(handle) &
      bind(C, name='Polynomial1dAxesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: Polynomial1dAxesGetConst
end function Polynomial1dAxesGetConst

!! Get
function Polynomial1dAxesGet(handle) &
      bind(C, name='Polynomial1dAxesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: Polynomial1dAxesGet
end function Polynomial1dAxesGet

!! Set
subroutine Polynomial1dAxesSet(handle, fieldHandle) &
      bind(C, name='Polynomial1dAxesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine Polynomial1dAxesSet


!! -----------------------------------------------------------------------------
!! Child: values
!! -----------------------------------------------------------------------------

!! Has
function Polynomial1dValuesHas(handle) &
      bind(C, name='Polynomial1dValuesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Polynomial1dValuesHas
end function Polynomial1dValuesHas

!! Get, const
function Polynomial1dValuesGetConst(handle) &
      bind(C, name='Polynomial1dValuesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: Polynomial1dValuesGetConst
end function Polynomial1dValuesGetConst

!! Get
function Polynomial1dValuesGet(handle) &
      bind(C, name='Polynomial1dValuesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: Polynomial1dValuesGet
end function Polynomial1dValuesGet

!! Set
subroutine Polynomial1dValuesSet(handle, fieldHandle) &
      bind(C, name='Polynomial1dValuesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine Polynomial1dValuesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module reducedPolynomial1d
