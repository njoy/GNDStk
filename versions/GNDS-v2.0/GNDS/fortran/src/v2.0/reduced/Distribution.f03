
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module reducedDistribution
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DistributionDefaultConst() &
      bind(C, name='DistributionDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DistributionDefaultConst
end function DistributionDefaultConst

!! Create, default
function DistributionDefault() &
      bind(C, name='DistributionDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DistributionDefault
end function DistributionDefault

!! Create, general, const
function DistributionCreateConst( &
   thermalNeutronScatteringLaw, &
   uncorrelated, &
   unspecified, &
   XYs2d, &
   branching3d &
) &
      bind(C, name='DistributionCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: thermalNeutronScatteringLaw
   type(c_ptr), value :: uncorrelated
   type(c_ptr), value :: unspecified
   type(c_ptr), value :: XYs2d
   type(c_ptr), value :: branching3d
   type(c_ptr) :: DistributionCreateConst
end function DistributionCreateConst

!! Create, general
function DistributionCreate( &
   thermalNeutronScatteringLaw, &
   uncorrelated, &
   unspecified, &
   XYs2d, &
   branching3d &
) &
      bind(C, name='DistributionCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: thermalNeutronScatteringLaw
   type(c_ptr), value :: uncorrelated
   type(c_ptr), value :: unspecified
   type(c_ptr), value :: XYs2d
   type(c_ptr), value :: branching3d
   type(c_ptr) :: DistributionCreate
end function DistributionCreate

!! Assign
subroutine DistributionAssign(handleLHS, handleRHS) &
      bind(C, name='DistributionAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine DistributionAssign

!! Delete
subroutine DistributionDelete(handle) &
      bind(C, name='DistributionDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DistributionDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function DistributionRead(handle, filename, filenameSize) &
      bind(C, name='DistributionRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DistributionRead
end function DistributionRead

!! Write to file
function DistributionWrite(handle, filename, filenameSize) &
      bind(C, name='DistributionWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DistributionWrite
end function DistributionWrite

!! Print to standard output, in our prettyprinting format
function DistributionPrint(handle) &
      bind(C, name='DistributionPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionPrint
end function DistributionPrint

!! Print to standard output, as XML
function DistributionPrintXML(handle) &
      bind(C, name='DistributionPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionPrintXML
end function DistributionPrintXML

!! Print to standard output, as JSON
function DistributionPrintJSON(handle) &
      bind(C, name='DistributionPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionPrintJSON
end function DistributionPrintJSON


!! -----------------------------------------------------------------------------
!! Child: thermalNeutronScatteringLaw
!! -----------------------------------------------------------------------------

!! Has
function DistributionThermalNeutronScatteringLawHas(handle) &
      bind(C, name='DistributionThermalNeutronScatteringLawHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionThermalNeutronScatteringLawHas
end function DistributionThermalNeutronScatteringLawHas

!! Get, const
function DistributionThermalNeutronScatteringLawGetConst(handle) &
      bind(C, name='DistributionThermalNeutronScatteringLawGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionThermalNeutronScatteringLawGetConst
end function DistributionThermalNeutronScatteringLawGetConst

!! Get
function DistributionThermalNeutronScatteringLawGet(handle) &
      bind(C, name='DistributionThermalNeutronScatteringLawGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionThermalNeutronScatteringLawGet
end function DistributionThermalNeutronScatteringLawGet

!! Set
subroutine DistributionThermalNeutronScatteringLawSet(handle, fieldHandle) &
      bind(C, name='DistributionThermalNeutronScatteringLawSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine DistributionThermalNeutronScatteringLawSet


!! -----------------------------------------------------------------------------
!! Child: uncorrelated
!! -----------------------------------------------------------------------------

!! Has
function DistributionUncorrelatedHas(handle) &
      bind(C, name='DistributionUncorrelatedHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionUncorrelatedHas
end function DistributionUncorrelatedHas

!! Get, const
function DistributionUncorrelatedGetConst(handle) &
      bind(C, name='DistributionUncorrelatedGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionUncorrelatedGetConst
end function DistributionUncorrelatedGetConst

!! Get
function DistributionUncorrelatedGet(handle) &
      bind(C, name='DistributionUncorrelatedGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionUncorrelatedGet
end function DistributionUncorrelatedGet

!! Set
subroutine DistributionUncorrelatedSet(handle, fieldHandle) &
      bind(C, name='DistributionUncorrelatedSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine DistributionUncorrelatedSet


!! -----------------------------------------------------------------------------
!! Child: unspecified
!! -----------------------------------------------------------------------------

!! Has
function DistributionUnspecifiedHas(handle) &
      bind(C, name='DistributionUnspecifiedHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionUnspecifiedHas
end function DistributionUnspecifiedHas

!! Get, const
function DistributionUnspecifiedGetConst(handle) &
      bind(C, name='DistributionUnspecifiedGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionUnspecifiedGetConst
end function DistributionUnspecifiedGetConst

!! Get
function DistributionUnspecifiedGet(handle) &
      bind(C, name='DistributionUnspecifiedGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionUnspecifiedGet
end function DistributionUnspecifiedGet

!! Set
subroutine DistributionUnspecifiedSet(handle, fieldHandle) &
      bind(C, name='DistributionUnspecifiedSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine DistributionUnspecifiedSet


!! -----------------------------------------------------------------------------
!! Child: XYs2d
!! -----------------------------------------------------------------------------

!! Has
function DistributionXYs2dHas(handle) &
      bind(C, name='DistributionXYs2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionXYs2dHas
end function DistributionXYs2dHas

!! Get, const
function DistributionXYs2dGetConst(handle) &
      bind(C, name='DistributionXYs2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionXYs2dGetConst
end function DistributionXYs2dGetConst

!! Get
function DistributionXYs2dGet(handle) &
      bind(C, name='DistributionXYs2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionXYs2dGet
end function DistributionXYs2dGet

!! Set
subroutine DistributionXYs2dSet(handle, fieldHandle) &
      bind(C, name='DistributionXYs2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine DistributionXYs2dSet


!! -----------------------------------------------------------------------------
!! Child: branching3d
!! -----------------------------------------------------------------------------

!! Has
function DistributionBranching3dHas(handle) &
      bind(C, name='DistributionBranching3dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DistributionBranching3dHas
end function DistributionBranching3dHas

!! Get, const
function DistributionBranching3dGetConst(handle) &
      bind(C, name='DistributionBranching3dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionBranching3dGetConst
end function DistributionBranching3dGetConst

!! Get
function DistributionBranching3dGet(handle) &
      bind(C, name='DistributionBranching3dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DistributionBranching3dGet
end function DistributionBranching3dGet

!! Set
subroutine DistributionBranching3dSet(handle, fieldHandle) &
      bind(C, name='DistributionBranching3dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine DistributionBranching3dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module reducedDistribution
