
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSlice
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SliceDefaultConst() &
      bind(C, name='SliceDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SliceDefaultConst
end function SliceDefaultConst

!! Create, default
function SliceDefault() &
      bind(C, name='SliceDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SliceDefault
end function SliceDefault

!! Create, general, const
function SliceCreateConst( &
   dimension, &
   domainValue, &
   domainMin, &
   domainMax, &
   domainUnit, &
   domainUnitSize &
) &
      bind(C, name='SliceCreateConst')
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: dimension
   integer(c_int), value, intent(in) :: domainValue
   real(c_double), value, intent(in) :: domainMin
   real(c_double), value, intent(in) :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   type(c_ptr) :: SliceCreateConst
end function SliceCreateConst

!! Create, general
function SliceCreate( &
   dimension, &
   domainValue, &
   domainMin, &
   domainMax, &
   domainUnit, &
   domainUnitSize &
) &
      bind(C, name='SliceCreate')
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: dimension
   integer(c_int), value, intent(in) :: domainValue
   real(c_double), value, intent(in) :: domainMin
   real(c_double), value, intent(in) :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   type(c_ptr) :: SliceCreate
end function SliceCreate

!! Assign
subroutine SliceAssign(handleLHS, handleRHS) &
      bind(C, name='SliceAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine SliceAssign

!! Delete
subroutine SliceDelete(handle) &
      bind(C, name='SliceDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SliceDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SliceRead(handle, filename, filenameSize) &
      bind(C, name='SliceRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SliceRead
end function SliceRead

!! Write to file
function SliceWrite(handle, filename, filenameSize) &
      bind(C, name='SliceWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SliceWrite
end function SliceWrite

!! Print to standard output, in our prettyprinting format
function SlicePrint(handle) &
      bind(C, name='SlicePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SlicePrint
end function SlicePrint

!! Print to standard output, as XML
function SlicePrintXML(handle) &
      bind(C, name='SlicePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SlicePrintXML
end function SlicePrintXML

!! Print to standard output, as JSON
function SlicePrintJSON(handle) &
      bind(C, name='SlicePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SlicePrintJSON
end function SlicePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: dimension
!! -----------------------------------------------------------------------------

!! Has
function SliceDimensionHas(handle) &
      bind(C, name='SliceDimensionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SliceDimensionHas
end function SliceDimensionHas

!! Get
function SliceDimensionGet(handle) &
      bind(C, name='SliceDimensionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SliceDimensionGet
end function SliceDimensionGet

!! Set
subroutine SliceDimensionSet(handle, dimension, dimensionSize) &
      bind(C, name='SliceDimensionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: dimensionSize
   character(c_char), intent(in) :: dimension(dimensionSize)
end subroutine SliceDimensionSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainValue
!! -----------------------------------------------------------------------------

!! Has
function SliceDomainValueHas(handle) &
      bind(C, name='SliceDomainValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SliceDomainValueHas
end function SliceDomainValueHas

!! Get
function SliceDomainValueGet(handle) &
      bind(C, name='SliceDomainValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SliceDomainValueGet
end function SliceDomainValueGet

!! Set
subroutine SliceDomainValueSet(handle, domainValue, domainValueSize) &
      bind(C, name='SliceDomainValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainValueSize
   character(c_char), intent(in) :: domainValue(domainValueSize)
end subroutine SliceDomainValueSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainMin
!! -----------------------------------------------------------------------------

!! Has
function SliceDomainMinHas(handle) &
      bind(C, name='SliceDomainMinHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SliceDomainMinHas
end function SliceDomainMinHas

!! Get
function SliceDomainMinGet(handle) &
      bind(C, name='SliceDomainMinGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: SliceDomainMinGet
end function SliceDomainMinGet

!! Set
subroutine SliceDomainMinSet(handle, domainMin, domainMinSize) &
      bind(C, name='SliceDomainMinSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainMinSize
   character(c_char), intent(in) :: domainMin(domainMinSize)
end subroutine SliceDomainMinSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainMax
!! -----------------------------------------------------------------------------

!! Has
function SliceDomainMaxHas(handle) &
      bind(C, name='SliceDomainMaxHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SliceDomainMaxHas
end function SliceDomainMaxHas

!! Get
function SliceDomainMaxGet(handle) &
      bind(C, name='SliceDomainMaxGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: SliceDomainMaxGet
end function SliceDomainMaxGet

!! Set
subroutine SliceDomainMaxSet(handle, domainMax, domainMaxSize) &
      bind(C, name='SliceDomainMaxSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainMaxSize
   character(c_char), intent(in) :: domainMax(domainMaxSize)
end subroutine SliceDomainMaxSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainUnit
!! -----------------------------------------------------------------------------

!! Has
function SliceDomainUnitHas(handle) &
      bind(C, name='SliceDomainUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SliceDomainUnitHas
end function SliceDomainUnitHas

!! Get
function SliceDomainUnitGet(handle) &
      bind(C, name='SliceDomainUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SliceDomainUnitGet
end function SliceDomainUnitGet

!! Set
subroutine SliceDomainUnitSet(handle, domainUnit, domainUnitSize) &
      bind(C, name='SliceDomainUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
end subroutine SliceDomainUnitSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSlice
