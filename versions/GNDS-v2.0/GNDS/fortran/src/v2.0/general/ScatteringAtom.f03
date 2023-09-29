
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalScatteringAtom
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ScatteringAtomDefaultConst() &
      bind(C, name='ScatteringAtomDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ScatteringAtomDefaultConst
end function ScatteringAtomDefaultConst

!! Create, default, non-const
function ScatteringAtomDefault() &
      bind(C, name='ScatteringAtomDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ScatteringAtomDefault
end function ScatteringAtomDefault

!! Create, general, const
function ScatteringAtomCreateConst( &
   pid, &
   numberPerMolecule, &
   primaryScatterer, &
   mass, &
   e_critical, &
   e_max, &
   boundAtomCrossSection, &
   selfScatteringKernel, &
   T_effective, &
   pidSize &
) &
      bind(C, name='ScatteringAtomCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_int), intent(in), value :: numberPerMolecule
   logical(c_bool), intent(in), value :: primaryScatterer
   type(c_ptr), intent(in), value :: mass
   type(c_ptr), intent(in), value :: e_critical
   type(c_ptr), intent(in), value :: e_max
   type(c_ptr), intent(in), value :: boundAtomCrossSection
   type(c_ptr), intent(in), value :: selfScatteringKernel
   type(c_ptr), intent(in), value :: T_effective
   type(c_ptr) :: ScatteringAtomCreateConst
end function ScatteringAtomCreateConst

!! Create, general, non-const
function ScatteringAtomCreate( &
   pid, &
   numberPerMolecule, &
   primaryScatterer, &
   mass, &
   e_critical, &
   e_max, &
   boundAtomCrossSection, &
   selfScatteringKernel, &
   T_effective, &
   pidSize &
) &
      bind(C, name='ScatteringAtomCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_int), intent(in), value :: numberPerMolecule
   logical(c_bool), intent(in), value :: primaryScatterer
   type(c_ptr), intent(in), value :: mass
   type(c_ptr), intent(in), value :: e_critical
   type(c_ptr), intent(in), value :: e_max
   type(c_ptr), intent(in), value :: boundAtomCrossSection
   type(c_ptr), intent(in), value :: selfScatteringKernel
   type(c_ptr), intent(in), value :: T_effective
   type(c_ptr) :: ScatteringAtomCreate
end function ScatteringAtomCreate

!! Assign
subroutine ScatteringAtomAssign(handleLHS, handleRHS) &
      bind(C, name='ScatteringAtomAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ScatteringAtomAssign

!! Delete
subroutine ScatteringAtomDelete(handle) &
      bind(C, name='ScatteringAtomDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ScatteringAtomDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ScatteringAtomRead(handle, filename, filenameSize) &
      bind(C, name='ScatteringAtomRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ScatteringAtomRead
end function ScatteringAtomRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ScatteringAtomWrite(handle, filename, filenameSize) &
      bind(C, name='ScatteringAtomWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ScatteringAtomWrite
end function ScatteringAtomWrite

!! Print to standard output, in our prettyprinting format
function ScatteringAtomPrint(handle) &
      bind(C, name='ScatteringAtomPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomPrint
end function ScatteringAtomPrint

!! Print to standard output, as XML
function ScatteringAtomPrintXML(handle) &
      bind(C, name='ScatteringAtomPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomPrintXML
end function ScatteringAtomPrintXML

!! Print to standard output, as JSON
function ScatteringAtomPrintJSON(handle) &
      bind(C, name='ScatteringAtomPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomPrintJSON
end function ScatteringAtomPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomPidHas(handle) &
      bind(C, name='ScatteringAtomPidHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomPidHas
end function ScatteringAtomPidHas

!! Get
function ScatteringAtomPidGet(handle) &
      bind(C, name='ScatteringAtomPidGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ScatteringAtomPidGet
end function ScatteringAtomPidGet

!! Set
subroutine ScatteringAtomPidSet(handle, pid, pidSize) &
      bind(C, name='ScatteringAtomPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine ScatteringAtomPidSet


!! -----------------------------------------------------------------------------
!! Metadatum: numberPerMolecule
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomNumberPerMoleculeHas(handle) &
      bind(C, name='ScatteringAtomNumberPerMoleculeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomNumberPerMoleculeHas
end function ScatteringAtomNumberPerMoleculeHas

!! Get
function ScatteringAtomNumberPerMoleculeGet(handle) &
      bind(C, name='ScatteringAtomNumberPerMoleculeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomNumberPerMoleculeGet
end function ScatteringAtomNumberPerMoleculeGet

!! Set
subroutine ScatteringAtomNumberPerMoleculeSet(handle, numberPerMolecule) &
      bind(C, name='ScatteringAtomNumberPerMoleculeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: numberPerMolecule
end subroutine ScatteringAtomNumberPerMoleculeSet


!! -----------------------------------------------------------------------------
!! Metadatum: primaryScatterer
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomPrimaryScattererHas(handle) &
      bind(C, name='ScatteringAtomPrimaryScattererHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomPrimaryScattererHas
end function ScatteringAtomPrimaryScattererHas

!! Get
function ScatteringAtomPrimaryScattererGet(handle) &
      bind(C, name='ScatteringAtomPrimaryScattererGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   logical(c_bool) :: ScatteringAtomPrimaryScattererGet
end function ScatteringAtomPrimaryScattererGet

!! Set
subroutine ScatteringAtomPrimaryScattererSet(handle, primaryScatterer) &
      bind(C, name='ScatteringAtomPrimaryScattererSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   logical(c_bool), intent(in), value :: primaryScatterer
end subroutine ScatteringAtomPrimaryScattererSet


!! -----------------------------------------------------------------------------
!! Child: mass
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomMassHas(handle) &
      bind(C, name='ScatteringAtomMassHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomMassHas
end function ScatteringAtomMassHas

!! Get, const
function ScatteringAtomMassGetConst(handle) &
      bind(C, name='ScatteringAtomMassGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ScatteringAtomMassGetConst
end function ScatteringAtomMassGetConst

!! Get, non-const
function ScatteringAtomMassGet(handle) &
      bind(C, name='ScatteringAtomMassGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ScatteringAtomMassGet
end function ScatteringAtomMassGet

!! Set
subroutine ScatteringAtomMassSet(handle, fieldHandle) &
      bind(C, name='ScatteringAtomMassSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ScatteringAtomMassSet


!! -----------------------------------------------------------------------------
!! Child: e_critical
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomE_criticalHas(handle) &
      bind(C, name='ScatteringAtomE_criticalHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomE_criticalHas
end function ScatteringAtomE_criticalHas

!! Get, const
function ScatteringAtomE_criticalGetConst(handle) &
      bind(C, name='ScatteringAtomE_criticalGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ScatteringAtomE_criticalGetConst
end function ScatteringAtomE_criticalGetConst

!! Get, non-const
function ScatteringAtomE_criticalGet(handle) &
      bind(C, name='ScatteringAtomE_criticalGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ScatteringAtomE_criticalGet
end function ScatteringAtomE_criticalGet

!! Set
subroutine ScatteringAtomE_criticalSet(handle, fieldHandle) &
      bind(C, name='ScatteringAtomE_criticalSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ScatteringAtomE_criticalSet


!! -----------------------------------------------------------------------------
!! Child: e_max
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomE_maxHas(handle) &
      bind(C, name='ScatteringAtomE_maxHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomE_maxHas
end function ScatteringAtomE_maxHas

!! Get, const
function ScatteringAtomE_maxGetConst(handle) &
      bind(C, name='ScatteringAtomE_maxGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ScatteringAtomE_maxGetConst
end function ScatteringAtomE_maxGetConst

!! Get, non-const
function ScatteringAtomE_maxGet(handle) &
      bind(C, name='ScatteringAtomE_maxGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ScatteringAtomE_maxGet
end function ScatteringAtomE_maxGet

!! Set
subroutine ScatteringAtomE_maxSet(handle, fieldHandle) &
      bind(C, name='ScatteringAtomE_maxSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ScatteringAtomE_maxSet


!! -----------------------------------------------------------------------------
!! Child: boundAtomCrossSection
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomBoundAtomCrossSectionHas(handle) &
      bind(C, name='ScatteringAtomBoundAtomCrossSectionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomBoundAtomCrossSectionHas
end function ScatteringAtomBoundAtomCrossSectionHas

!! Get, const
function ScatteringAtomBoundAtomCrossSectionGetConst(handle) &
      bind(C, name='ScatteringAtomBoundAtomCrossSectionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ScatteringAtomBoundAtomCrossSectionGetConst
end function ScatteringAtomBoundAtomCrossSectionGetConst

!! Get, non-const
function ScatteringAtomBoundAtomCrossSectionGet(handle) &
      bind(C, name='ScatteringAtomBoundAtomCrossSectionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ScatteringAtomBoundAtomCrossSectionGet
end function ScatteringAtomBoundAtomCrossSectionGet

!! Set
subroutine ScatteringAtomBoundAtomCrossSectionSet(handle, fieldHandle) &
      bind(C, name='ScatteringAtomBoundAtomCrossSectionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ScatteringAtomBoundAtomCrossSectionSet


!! -----------------------------------------------------------------------------
!! Child: selfScatteringKernel
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomSelfScatteringKernelHas(handle) &
      bind(C, name='ScatteringAtomSelfScatteringKernelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomSelfScatteringKernelHas
end function ScatteringAtomSelfScatteringKernelHas

!! Get, const
function ScatteringAtomSelfScatteringKernelGetConst(handle) &
      bind(C, name='ScatteringAtomSelfScatteringKernelGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ScatteringAtomSelfScatteringKernelGetConst
end function ScatteringAtomSelfScatteringKernelGetConst

!! Get, non-const
function ScatteringAtomSelfScatteringKernelGet(handle) &
      bind(C, name='ScatteringAtomSelfScatteringKernelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ScatteringAtomSelfScatteringKernelGet
end function ScatteringAtomSelfScatteringKernelGet

!! Set
subroutine ScatteringAtomSelfScatteringKernelSet(handle, fieldHandle) &
      bind(C, name='ScatteringAtomSelfScatteringKernelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ScatteringAtomSelfScatteringKernelSet


!! -----------------------------------------------------------------------------
!! Child: T_effective
!! -----------------------------------------------------------------------------

!! Has
function ScatteringAtomT_effectiveHas(handle) &
      bind(C, name='ScatteringAtomT_effectiveHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ScatteringAtomT_effectiveHas
end function ScatteringAtomT_effectiveHas

!! Get, const
function ScatteringAtomT_effectiveGetConst(handle) &
      bind(C, name='ScatteringAtomT_effectiveGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ScatteringAtomT_effectiveGetConst
end function ScatteringAtomT_effectiveGetConst

!! Get, non-const
function ScatteringAtomT_effectiveGet(handle) &
      bind(C, name='ScatteringAtomT_effectiveGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ScatteringAtomT_effectiveGet
end function ScatteringAtomT_effectiveGet

!! Set
subroutine ScatteringAtomT_effectiveSet(handle, fieldHandle) &
      bind(C, name='ScatteringAtomT_effectiveSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ScatteringAtomT_effectiveSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalScatteringAtom
