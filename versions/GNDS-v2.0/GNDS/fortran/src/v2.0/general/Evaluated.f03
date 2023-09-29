
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalEvaluated
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function EvaluatedDefaultConst() &
      bind(C, name='EvaluatedDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: EvaluatedDefaultConst
end function EvaluatedDefaultConst

!! Create, default
function EvaluatedDefault() &
      bind(C, name='EvaluatedDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: EvaluatedDefault
end function EvaluatedDefault

!! Create, general, const
function EvaluatedCreateConst( &
   label, &
   date, &
   library, &
   version, &
   documentation, &
   temperature, &
   projectileEnergyDomain, &
   labelSize, &
   dateSize, &
   librarySize, &
   versionSize &
) &
      bind(C, name='EvaluatedCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: dateSize
   character(c_char), intent(in) :: date(dateSize)
   integer(c_size_t), intent(in), value :: librarySize
   character(c_char), intent(in) :: library(librarySize)
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
   type(c_ptr), intent(in), value :: documentation
   type(c_ptr), intent(in), value :: temperature
   type(c_ptr), intent(in), value :: projectileEnergyDomain
   type(c_ptr) :: EvaluatedCreateConst
end function EvaluatedCreateConst

!! Create, general
function EvaluatedCreate( &
   label, &
   date, &
   library, &
   version, &
   documentation, &
   temperature, &
   projectileEnergyDomain, &
   labelSize, &
   dateSize, &
   librarySize, &
   versionSize &
) &
      bind(C, name='EvaluatedCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: dateSize
   character(c_char), intent(in) :: date(dateSize)
   integer(c_size_t), intent(in), value :: librarySize
   character(c_char), intent(in) :: library(librarySize)
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
   type(c_ptr), intent(in), value :: documentation
   type(c_ptr), intent(in), value :: temperature
   type(c_ptr), intent(in), value :: projectileEnergyDomain
   type(c_ptr) :: EvaluatedCreate
end function EvaluatedCreate

!! Assign
subroutine EvaluatedAssign(handleLHS, handleRHS) &
      bind(C, name='EvaluatedAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine EvaluatedAssign

!! Delete
subroutine EvaluatedDelete(handle) &
      bind(C, name='EvaluatedDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine EvaluatedDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function EvaluatedRead(handle, filename, filenameSize) &
      bind(C, name='EvaluatedRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: EvaluatedRead
end function EvaluatedRead

!! Write to file
function EvaluatedWrite(handle, filename, filenameSize) &
      bind(C, name='EvaluatedWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: EvaluatedWrite
end function EvaluatedWrite

!! Print to standard output, in our prettyprinting format
function EvaluatedPrint(handle) &
      bind(C, name='EvaluatedPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedPrint
end function EvaluatedPrint

!! Print to standard output, as XML
function EvaluatedPrintXML(handle) &
      bind(C, name='EvaluatedPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedPrintXML
end function EvaluatedPrintXML

!! Print to standard output, as JSON
function EvaluatedPrintJSON(handle) &
      bind(C, name='EvaluatedPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedPrintJSON
end function EvaluatedPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function EvaluatedLabelHas(handle) &
      bind(C, name='EvaluatedLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedLabelHas
end function EvaluatedLabelHas

!! Get
function EvaluatedLabelGet(handle) &
      bind(C, name='EvaluatedLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EvaluatedLabelGet
end function EvaluatedLabelGet

!! Set
subroutine EvaluatedLabelSet(handle, label, labelSize) &
      bind(C, name='EvaluatedLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine EvaluatedLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: date
!! -----------------------------------------------------------------------------

!! Has
function EvaluatedDateHas(handle) &
      bind(C, name='EvaluatedDateHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedDateHas
end function EvaluatedDateHas

!! Get
function EvaluatedDateGet(handle) &
      bind(C, name='EvaluatedDateGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EvaluatedDateGet
end function EvaluatedDateGet

!! Set
subroutine EvaluatedDateSet(handle, date, dateSize) &
      bind(C, name='EvaluatedDateSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: dateSize
   character(c_char), intent(in) :: date(dateSize)
end subroutine EvaluatedDateSet


!! -----------------------------------------------------------------------------
!! Metadatum: library
!! -----------------------------------------------------------------------------

!! Has
function EvaluatedLibraryHas(handle) &
      bind(C, name='EvaluatedLibraryHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedLibraryHas
end function EvaluatedLibraryHas

!! Get
function EvaluatedLibraryGet(handle) &
      bind(C, name='EvaluatedLibraryGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EvaluatedLibraryGet
end function EvaluatedLibraryGet

!! Set
subroutine EvaluatedLibrarySet(handle, library, librarySize) &
      bind(C, name='EvaluatedLibrarySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: librarySize
   character(c_char), intent(in) :: library(librarySize)
end subroutine EvaluatedLibrarySet


!! -----------------------------------------------------------------------------
!! Metadatum: version
!! -----------------------------------------------------------------------------

!! Has
function EvaluatedVersionHas(handle) &
      bind(C, name='EvaluatedVersionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedVersionHas
end function EvaluatedVersionHas

!! Get
function EvaluatedVersionGet(handle) &
      bind(C, name='EvaluatedVersionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EvaluatedVersionGet
end function EvaluatedVersionGet

!! Set
subroutine EvaluatedVersionSet(handle, version, versionSize) &
      bind(C, name='EvaluatedVersionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
end subroutine EvaluatedVersionSet


!! -----------------------------------------------------------------------------
!! Child: documentation
!! -----------------------------------------------------------------------------

!! Has
function EvaluatedDocumentationHas(handle) &
      bind(C, name='EvaluatedDocumentationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedDocumentationHas
end function EvaluatedDocumentationHas

!! Get, const
function EvaluatedDocumentationGetConst(handle) &
      bind(C, name='EvaluatedDocumentationGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EvaluatedDocumentationGetConst
end function EvaluatedDocumentationGetConst

!! Get
function EvaluatedDocumentationGet(handle) &
      bind(C, name='EvaluatedDocumentationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EvaluatedDocumentationGet
end function EvaluatedDocumentationGet

!! Set
subroutine EvaluatedDocumentationSet(handle, fieldHandle) &
      bind(C, name='EvaluatedDocumentationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EvaluatedDocumentationSet


!! -----------------------------------------------------------------------------
!! Child: temperature
!! -----------------------------------------------------------------------------

!! Has
function EvaluatedTemperatureHas(handle) &
      bind(C, name='EvaluatedTemperatureHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedTemperatureHas
end function EvaluatedTemperatureHas

!! Get, const
function EvaluatedTemperatureGetConst(handle) &
      bind(C, name='EvaluatedTemperatureGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EvaluatedTemperatureGetConst
end function EvaluatedTemperatureGetConst

!! Get
function EvaluatedTemperatureGet(handle) &
      bind(C, name='EvaluatedTemperatureGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EvaluatedTemperatureGet
end function EvaluatedTemperatureGet

!! Set
subroutine EvaluatedTemperatureSet(handle, fieldHandle) &
      bind(C, name='EvaluatedTemperatureSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EvaluatedTemperatureSet


!! -----------------------------------------------------------------------------
!! Child: projectileEnergyDomain
!! -----------------------------------------------------------------------------

!! Has
function EvaluatedProjectileEnergyDomainHas(handle) &
      bind(C, name='EvaluatedProjectileEnergyDomainHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EvaluatedProjectileEnergyDomainHas
end function EvaluatedProjectileEnergyDomainHas

!! Get, const
function EvaluatedProjectileEnergyDomainGetConst(handle) &
      bind(C, name='EvaluatedProjectileEnergyDomainGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EvaluatedProjectileEnergyDomainGetConst
end function EvaluatedProjectileEnergyDomainGetConst

!! Get
function EvaluatedProjectileEnergyDomainGet(handle) &
      bind(C, name='EvaluatedProjectileEnergyDomainGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EvaluatedProjectileEnergyDomainGet
end function EvaluatedProjectileEnergyDomainGet

!! Set
subroutine EvaluatedProjectileEnergyDomainSet(handle, fieldHandle) &
      bind(C, name='EvaluatedProjectileEnergyDomainSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EvaluatedProjectileEnergyDomainSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalEvaluated
