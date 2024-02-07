
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalUnresolved
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function UnresolvedDefaultConst() &
      bind(C, name='UnresolvedDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: UnresolvedDefaultConst
end function UnresolvedDefaultConst

!! Create, default, non-const
function UnresolvedDefault() &
      bind(C, name='UnresolvedDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: UnresolvedDefault
end function UnresolvedDefault

!! Create, general, const
function UnresolvedCreateConst( &
   domainMin, &
   domainMax, &
   domainUnit, &
   tabulatedWidths, &
   domainUnitSize &
) &
      bind(C, name='UnresolvedCreateConst')
   use iso_c_binding
   implicit none
   real(c_double), intent(in), value :: domainMin
   real(c_double), intent(in), value :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   type(c_ptr), intent(in), value :: tabulatedWidths
   type(c_ptr) :: UnresolvedCreateConst
end function UnresolvedCreateConst

!! Create, general, non-const
function UnresolvedCreate( &
   domainMin, &
   domainMax, &
   domainUnit, &
   tabulatedWidths, &
   domainUnitSize &
) &
      bind(C, name='UnresolvedCreate')
   use iso_c_binding
   implicit none
   real(c_double), intent(in), value :: domainMin
   real(c_double), intent(in), value :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   type(c_ptr), intent(in), value :: tabulatedWidths
   type(c_ptr) :: UnresolvedCreate
end function UnresolvedCreate

!! Assign
subroutine UnresolvedAssign(handleLHS, handleRHS) &
      bind(C, name='UnresolvedAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine UnresolvedAssign

!! Delete
subroutine UnresolvedDelete(handle) &
      bind(C, name='UnresolvedDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine UnresolvedDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function UnresolvedRead(handle, filename, filenameSize) &
      bind(C, name='UnresolvedRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: UnresolvedRead
end function UnresolvedRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function UnresolvedWrite(handle, filename, filenameSize) &
      bind(C, name='UnresolvedWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: UnresolvedWrite
end function UnresolvedWrite

!! Print to standard output, in our prettyprinting format
function UnresolvedPrint(handle) &
      bind(C, name='UnresolvedPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UnresolvedPrint
end function UnresolvedPrint

!! Print to standard output, as XML
function UnresolvedPrintXML(handle) &
      bind(C, name='UnresolvedPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UnresolvedPrintXML
end function UnresolvedPrintXML

!! Print to standard output, as JSON
function UnresolvedPrintJSON(handle) &
      bind(C, name='UnresolvedPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UnresolvedPrintJSON
end function UnresolvedPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: domainMin
!! -----------------------------------------------------------------------------

!! Has
function UnresolvedDomainMinHas(handle) &
      bind(C, name='UnresolvedDomainMinHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UnresolvedDomainMinHas
end function UnresolvedDomainMinHas

!! Get
function UnresolvedDomainMinGet(handle) &
      bind(C, name='UnresolvedDomainMinGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: UnresolvedDomainMinGet
end function UnresolvedDomainMinGet

!! Set
subroutine UnresolvedDomainMinSet(handle, domainMin) &
      bind(C, name='UnresolvedDomainMinSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: domainMin
end subroutine UnresolvedDomainMinSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainMax
!! -----------------------------------------------------------------------------

!! Has
function UnresolvedDomainMaxHas(handle) &
      bind(C, name='UnresolvedDomainMaxHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UnresolvedDomainMaxHas
end function UnresolvedDomainMaxHas

!! Get
function UnresolvedDomainMaxGet(handle) &
      bind(C, name='UnresolvedDomainMaxGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: UnresolvedDomainMaxGet
end function UnresolvedDomainMaxGet

!! Set
subroutine UnresolvedDomainMaxSet(handle, domainMax) &
      bind(C, name='UnresolvedDomainMaxSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: domainMax
end subroutine UnresolvedDomainMaxSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainUnit
!! -----------------------------------------------------------------------------

!! Has
function UnresolvedDomainUnitHas(handle) &
      bind(C, name='UnresolvedDomainUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UnresolvedDomainUnitHas
end function UnresolvedDomainUnitHas

!! Get
function UnresolvedDomainUnitGet(handle) &
      bind(C, name='UnresolvedDomainUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: UnresolvedDomainUnitGet
end function UnresolvedDomainUnitGet

!! Set
subroutine UnresolvedDomainUnitSet(handle, domainUnit, domainUnitSize) &
      bind(C, name='UnresolvedDomainUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
end subroutine UnresolvedDomainUnitSet


!! -----------------------------------------------------------------------------
!! Child: tabulatedWidths
!! -----------------------------------------------------------------------------

!! Has
function UnresolvedTabulatedWidthsHas(handle) &
      bind(C, name='UnresolvedTabulatedWidthsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UnresolvedTabulatedWidthsHas
end function UnresolvedTabulatedWidthsHas

!! Get, const
function UnresolvedTabulatedWidthsGetConst(handle) &
      bind(C, name='UnresolvedTabulatedWidthsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: UnresolvedTabulatedWidthsGetConst
end function UnresolvedTabulatedWidthsGetConst

!! Get, non-const
function UnresolvedTabulatedWidthsGet(handle) &
      bind(C, name='UnresolvedTabulatedWidthsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: UnresolvedTabulatedWidthsGet
end function UnresolvedTabulatedWidthsGet

!! Set
subroutine UnresolvedTabulatedWidthsSet(handle, fieldHandle) &
      bind(C, name='UnresolvedTabulatedWidthsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine UnresolvedTabulatedWidthsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalUnresolved