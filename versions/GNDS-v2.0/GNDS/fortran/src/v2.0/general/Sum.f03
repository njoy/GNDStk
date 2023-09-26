
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSum
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SumDefaultConst() &
      bind(C, name='SumDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SumDefaultConst
end function SumDefaultConst

!! Create, default
function SumDefault() &
      bind(C, name='SumDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SumDefault
end function SumDefault

!! Create, general, const
function SumCreateConst( &
   label, &
   domainMin, &
   domainMax, &
   domainUnit, &
   summand, summandSize, &
   labelSize, &
   domainUnitSize &
) &
      bind(C, name='SumCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   real(c_double), value, intent(in) :: domainMin
   real(c_double), value, intent(in) :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   integer(c_size_t), value :: summandSize
   type(c_ptr) :: summand(summandSize)
   type(c_ptr) :: SumCreateConst
end function SumCreateConst

!! Create, general
function SumCreate( &
   label, &
   domainMin, &
   domainMax, &
   domainUnit, &
   summand, summandSize, &
   labelSize, &
   domainUnitSize &
) &
      bind(C, name='SumCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   real(c_double), value, intent(in) :: domainMin
   real(c_double), value, intent(in) :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   integer(c_size_t), value :: summandSize
   type(c_ptr) :: summand(summandSize)
   type(c_ptr) :: SumCreate
end function SumCreate

!! Assign
subroutine SumAssign(handleLHS, handleRHS) &
      bind(C, name='SumAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine SumAssign

!! Delete
subroutine SumDelete(handle) &
      bind(C, name='SumDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SumDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SumRead(handle, filename, filenameSize) &
      bind(C, name='SumRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SumRead
end function SumRead

!! Write to file
function SumWrite(handle, filename, filenameSize) &
      bind(C, name='SumWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SumWrite
end function SumWrite

!! Print to standard output, in our prettyprinting format
function SumPrint(handle) &
      bind(C, name='SumPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumPrint
end function SumPrint

!! Print to standard output, as XML
function SumPrintXML(handle) &
      bind(C, name='SumPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumPrintXML
end function SumPrintXML

!! Print to standard output, as JSON
function SumPrintJSON(handle) &
      bind(C, name='SumPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumPrintJSON
end function SumPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function SumLabelHas(handle) &
      bind(C, name='SumLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumLabelHas
end function SumLabelHas

!! Get
function SumLabelGet(handle) &
      bind(C, name='SumLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SumLabelGet
end function SumLabelGet

!! Set
subroutine SumLabelSet(handle, label, labelSize) &
      bind(C, name='SumLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine SumLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainMin
!! -----------------------------------------------------------------------------

!! Has
function SumDomainMinHas(handle) &
      bind(C, name='SumDomainMinHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumDomainMinHas
end function SumDomainMinHas

!! Get
function SumDomainMinGet(handle) &
      bind(C, name='SumDomainMinGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: SumDomainMinGet
end function SumDomainMinGet

!! Set
subroutine SumDomainMinSet(handle, domainMin, domainMinSize) &
      bind(C, name='SumDomainMinSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainMinSize
   character(c_char), intent(in) :: domainMin(domainMinSize)
end subroutine SumDomainMinSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainMax
!! -----------------------------------------------------------------------------

!! Has
function SumDomainMaxHas(handle) &
      bind(C, name='SumDomainMaxHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumDomainMaxHas
end function SumDomainMaxHas

!! Get
function SumDomainMaxGet(handle) &
      bind(C, name='SumDomainMaxGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: SumDomainMaxGet
end function SumDomainMaxGet

!! Set
subroutine SumDomainMaxSet(handle, domainMax, domainMaxSize) &
      bind(C, name='SumDomainMaxSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainMaxSize
   character(c_char), intent(in) :: domainMax(domainMaxSize)
end subroutine SumDomainMaxSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainUnit
!! -----------------------------------------------------------------------------

!! Has
function SumDomainUnitHas(handle) &
      bind(C, name='SumDomainUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumDomainUnitHas
end function SumDomainUnitHas

!! Get
function SumDomainUnitGet(handle) &
      bind(C, name='SumDomainUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SumDomainUnitGet
end function SumDomainUnitGet

!! Set
subroutine SumDomainUnitSet(handle, domainUnit, domainUnitSize) &
      bind(C, name='SumDomainUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
end subroutine SumDomainUnitSet


!! -----------------------------------------------------------------------------
!! Child: summand
!! -----------------------------------------------------------------------------

!! Has
function SumSummandHas(handle) &
      bind(C, name='SumSummandHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumSummandHas
end function SumSummandHas

!! Clear
subroutine SumSummandClear(handle) &
      bind(C, name='SumSummandClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SumSummandClear

!! Size
function SumSummandSize(handle) &
      bind(C, name='SumSummandSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: SumSummandSize
end function SumSummandSize

!! Add
subroutine SumSummandAdd(handle, fieldHandle) &
      bind(C, name='SumSummandAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SumSummandAdd

!! Get, by index \in [0,size), const
function SumSummandGetConst(handle, index) &
      bind(C, name='SumSummandGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: SumSummandGetConst
end function SumSummandGetConst

!! Get, by index \in [0,size)
function SumSummandGet(handle, index) &
      bind(C, name='SumSummandGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: SumSummandGet
end function SumSummandGet

!! Set, by index \in [0,size)
subroutine SumSummandSet(handle, index, fieldHandle) &
      bind(C, name='SumSummandSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SumSummandSet

!! ------------------------
!! Re: metadatum ENDF_MFMT
!! ------------------------

!! Has, by ENDF_MFMT
function SumSummandHasByENDFMFMT(handle, meta, metaSize) &
      bind(C, name='SumSummandHasByENDFMFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: SumSummandHasByENDFMFMT
end function SumSummandHasByENDFMFMT

!! Get, by ENDF_MFMT, const
function SumSummandGetByENDFMFMTConst(handle, meta, metaSize) &
      bind(C, name='SumSummandGetByENDFMFMTConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SumSummandGetByENDFMFMTConst
end function SumSummandGetByENDFMFMTConst

!! Get, by ENDF_MFMT
function SumSummandGetByENDFMFMT(handle, meta, metaSize) &
      bind(C, name='SumSummandGetByENDFMFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SumSummandGetByENDFMFMT
end function SumSummandGetByENDFMFMT

!! Set, by ENDF_MFMT
subroutine SumSummandSetByENDFMFMT(handle, meta, metaSize, fieldHandle) &
      bind(C, name='SumSummandSetByENDFMFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SumSummandSetByENDFMFMT

!! ------------------------
!! Re: metadatum coefficient
!! ------------------------

!! Has, by coefficient
function SumSummandHasByCoefficient(handle, meta, metaSize) &
      bind(C, name='SumSummandHasByCoefficient')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: SumSummandHasByCoefficient
end function SumSummandHasByCoefficient

!! Get, by coefficient, const
function SumSummandGetByCoefficientConst(handle, meta, metaSize) &
      bind(C, name='SumSummandGetByCoefficientConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SumSummandGetByCoefficientConst
end function SumSummandGetByCoefficientConst

!! Get, by coefficient
function SumSummandGetByCoefficient(handle, meta, metaSize) &
      bind(C, name='SumSummandGetByCoefficient')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SumSummandGetByCoefficient
end function SumSummandGetByCoefficient

!! Set, by coefficient
subroutine SumSummandSetByCoefficient(handle, meta, metaSize, fieldHandle) &
      bind(C, name='SumSummandSetByCoefficient')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SumSummandSetByCoefficient

!! ------------------------
!! Re: metadatum href
!! ------------------------

!! Has, by href
function SumSummandHasByHref(handle, meta, metaSize) &
      bind(C, name='SumSummandHasByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: SumSummandHasByHref
end function SumSummandHasByHref

!! Get, by href, const
function SumSummandGetByHrefConst(handle, meta, metaSize) &
      bind(C, name='SumSummandGetByHrefConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SumSummandGetByHrefConst
end function SumSummandGetByHrefConst

!! Get, by href
function SumSummandGetByHref(handle, meta, metaSize) &
      bind(C, name='SumSummandGetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SumSummandGetByHref
end function SumSummandGetByHref

!! Set, by href
subroutine SumSummandSetByHref(handle, meta, metaSize, fieldHandle) &
      bind(C, name='SumSummandSetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SumSummandSetByHref


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSum
