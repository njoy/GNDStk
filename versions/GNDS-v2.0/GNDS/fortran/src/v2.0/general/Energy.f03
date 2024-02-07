
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalEnergy
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function EnergyDefaultConst() &
      bind(C, name='EnergyDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: EnergyDefaultConst
end function EnergyDefaultConst

!! Create, default, non-const
function EnergyDefault() &
      bind(C, name='EnergyDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: EnergyDefault
end function EnergyDefault

!! Create, general, const
function EnergyCreateConst( &
   value, &
   unit, &
   Double, &
   uncertainty, &
   NBodyPhaseSpace, &
   primaryGamma, &
   discreteGamma, &
   XYs2d, &
   generalEvaporation, &
   evaporation, &
   weightedFunctionals, &
   simpleMaxwellianFission, &
   MadlandNix, &
   unitSize &
) &
      bind(C, name='EnergyCreateConst')
   use iso_c_binding
   implicit none
   real(c_double), intent(in), value :: value
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr), intent(in), value :: Double
   type(c_ptr), intent(in), value :: uncertainty
   type(c_ptr), intent(in), value :: NBodyPhaseSpace
   type(c_ptr), intent(in), value :: primaryGamma
   type(c_ptr), intent(in), value :: discreteGamma
   type(c_ptr), intent(in), value :: XYs2d
   type(c_ptr), intent(in), value :: generalEvaporation
   type(c_ptr), intent(in), value :: evaporation
   type(c_ptr), intent(in), value :: weightedFunctionals
   type(c_ptr), intent(in), value :: simpleMaxwellianFission
   type(c_ptr), intent(in), value :: MadlandNix
   type(c_ptr) :: EnergyCreateConst
end function EnergyCreateConst

!! Create, general, non-const
function EnergyCreate( &
   value, &
   unit, &
   Double, &
   uncertainty, &
   NBodyPhaseSpace, &
   primaryGamma, &
   discreteGamma, &
   XYs2d, &
   generalEvaporation, &
   evaporation, &
   weightedFunctionals, &
   simpleMaxwellianFission, &
   MadlandNix, &
   unitSize &
) &
      bind(C, name='EnergyCreate')
   use iso_c_binding
   implicit none
   real(c_double), intent(in), value :: value
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr), intent(in), value :: Double
   type(c_ptr), intent(in), value :: uncertainty
   type(c_ptr), intent(in), value :: NBodyPhaseSpace
   type(c_ptr), intent(in), value :: primaryGamma
   type(c_ptr), intent(in), value :: discreteGamma
   type(c_ptr), intent(in), value :: XYs2d
   type(c_ptr), intent(in), value :: generalEvaporation
   type(c_ptr), intent(in), value :: evaporation
   type(c_ptr), intent(in), value :: weightedFunctionals
   type(c_ptr), intent(in), value :: simpleMaxwellianFission
   type(c_ptr), intent(in), value :: MadlandNix
   type(c_ptr) :: EnergyCreate
end function EnergyCreate

!! Assign
subroutine EnergyAssign(handleLHS, handleRHS) &
      bind(C, name='EnergyAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine EnergyAssign

!! Delete
subroutine EnergyDelete(handle) &
      bind(C, name='EnergyDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine EnergyDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function EnergyRead(handle, filename, filenameSize) &
      bind(C, name='EnergyRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: EnergyRead
end function EnergyRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function EnergyWrite(handle, filename, filenameSize) &
      bind(C, name='EnergyWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: EnergyWrite
end function EnergyWrite

!! Print to standard output, in our prettyprinting format
function EnergyPrint(handle) &
      bind(C, name='EnergyPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyPrint
end function EnergyPrint

!! Print to standard output, as XML
function EnergyPrintXML(handle) &
      bind(C, name='EnergyPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyPrintXML
end function EnergyPrintXML

!! Print to standard output, as JSON
function EnergyPrintJSON(handle) &
      bind(C, name='EnergyPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyPrintJSON
end function EnergyPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: value
!! -----------------------------------------------------------------------------

!! Has
function EnergyValueHas(handle) &
      bind(C, name='EnergyValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyValueHas
end function EnergyValueHas

!! Get
function EnergyValueGet(handle) &
      bind(C, name='EnergyValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: EnergyValueGet
end function EnergyValueGet

!! Set
subroutine EnergyValueSet(handle, value) &
      bind(C, name='EnergyValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: value
end subroutine EnergyValueSet


!! -----------------------------------------------------------------------------
!! Metadatum: unit
!! -----------------------------------------------------------------------------

!! Has
function EnergyUnitHas(handle) &
      bind(C, name='EnergyUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyUnitHas
end function EnergyUnitHas

!! Get
function EnergyUnitGet(handle) &
      bind(C, name='EnergyUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyUnitGet
end function EnergyUnitGet

!! Set
subroutine EnergyUnitSet(handle, unit, unitSize) &
      bind(C, name='EnergyUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
end subroutine EnergyUnitSet


!! -----------------------------------------------------------------------------
!! Child: Double
!! -----------------------------------------------------------------------------

!! Has
function EnergyDoubleHas(handle) &
      bind(C, name='EnergyDoubleHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyDoubleHas
end function EnergyDoubleHas

!! Get, const
function EnergyDoubleGetConst(handle) &
      bind(C, name='EnergyDoubleGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyDoubleGetConst
end function EnergyDoubleGetConst

!! Get, non-const
function EnergyDoubleGet(handle) &
      bind(C, name='EnergyDoubleGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyDoubleGet
end function EnergyDoubleGet

!! Set
subroutine EnergyDoubleSet(handle, fieldHandle) &
      bind(C, name='EnergyDoubleSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyDoubleSet


!! -----------------------------------------------------------------------------
!! Child: uncertainty
!! -----------------------------------------------------------------------------

!! Has
function EnergyUncertaintyHas(handle) &
      bind(C, name='EnergyUncertaintyHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyUncertaintyHas
end function EnergyUncertaintyHas

!! Get, const
function EnergyUncertaintyGetConst(handle) &
      bind(C, name='EnergyUncertaintyGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyUncertaintyGetConst
end function EnergyUncertaintyGetConst

!! Get, non-const
function EnergyUncertaintyGet(handle) &
      bind(C, name='EnergyUncertaintyGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyUncertaintyGet
end function EnergyUncertaintyGet

!! Set
subroutine EnergyUncertaintySet(handle, fieldHandle) &
      bind(C, name='EnergyUncertaintySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyUncertaintySet


!! -----------------------------------------------------------------------------
!! Child: NBodyPhaseSpace
!! -----------------------------------------------------------------------------

!! Has
function EnergyNBodyPhaseSpaceHas(handle) &
      bind(C, name='EnergyNBodyPhaseSpaceHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyNBodyPhaseSpaceHas
end function EnergyNBodyPhaseSpaceHas

!! Get, const
function EnergyNBodyPhaseSpaceGetConst(handle) &
      bind(C, name='EnergyNBodyPhaseSpaceGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyNBodyPhaseSpaceGetConst
end function EnergyNBodyPhaseSpaceGetConst

!! Get, non-const
function EnergyNBodyPhaseSpaceGet(handle) &
      bind(C, name='EnergyNBodyPhaseSpaceGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyNBodyPhaseSpaceGet
end function EnergyNBodyPhaseSpaceGet

!! Set
subroutine EnergyNBodyPhaseSpaceSet(handle, fieldHandle) &
      bind(C, name='EnergyNBodyPhaseSpaceSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyNBodyPhaseSpaceSet


!! -----------------------------------------------------------------------------
!! Child: primaryGamma
!! -----------------------------------------------------------------------------

!! Has
function EnergyPrimaryGammaHas(handle) &
      bind(C, name='EnergyPrimaryGammaHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyPrimaryGammaHas
end function EnergyPrimaryGammaHas

!! Get, const
function EnergyPrimaryGammaGetConst(handle) &
      bind(C, name='EnergyPrimaryGammaGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyPrimaryGammaGetConst
end function EnergyPrimaryGammaGetConst

!! Get, non-const
function EnergyPrimaryGammaGet(handle) &
      bind(C, name='EnergyPrimaryGammaGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyPrimaryGammaGet
end function EnergyPrimaryGammaGet

!! Set
subroutine EnergyPrimaryGammaSet(handle, fieldHandle) &
      bind(C, name='EnergyPrimaryGammaSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyPrimaryGammaSet


!! -----------------------------------------------------------------------------
!! Child: discreteGamma
!! -----------------------------------------------------------------------------

!! Has
function EnergyDiscreteGammaHas(handle) &
      bind(C, name='EnergyDiscreteGammaHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyDiscreteGammaHas
end function EnergyDiscreteGammaHas

!! Get, const
function EnergyDiscreteGammaGetConst(handle) &
      bind(C, name='EnergyDiscreteGammaGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyDiscreteGammaGetConst
end function EnergyDiscreteGammaGetConst

!! Get, non-const
function EnergyDiscreteGammaGet(handle) &
      bind(C, name='EnergyDiscreteGammaGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyDiscreteGammaGet
end function EnergyDiscreteGammaGet

!! Set
subroutine EnergyDiscreteGammaSet(handle, fieldHandle) &
      bind(C, name='EnergyDiscreteGammaSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyDiscreteGammaSet


!! -----------------------------------------------------------------------------
!! Child: XYs2d
!! -----------------------------------------------------------------------------

!! Has
function EnergyXYs2dHas(handle) &
      bind(C, name='EnergyXYs2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyXYs2dHas
end function EnergyXYs2dHas

!! Get, const
function EnergyXYs2dGetConst(handle) &
      bind(C, name='EnergyXYs2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyXYs2dGetConst
end function EnergyXYs2dGetConst

!! Get, non-const
function EnergyXYs2dGet(handle) &
      bind(C, name='EnergyXYs2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyXYs2dGet
end function EnergyXYs2dGet

!! Set
subroutine EnergyXYs2dSet(handle, fieldHandle) &
      bind(C, name='EnergyXYs2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyXYs2dSet


!! -----------------------------------------------------------------------------
!! Child: generalEvaporation
!! -----------------------------------------------------------------------------

!! Has
function EnergyGeneralEvaporationHas(handle) &
      bind(C, name='EnergyGeneralEvaporationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyGeneralEvaporationHas
end function EnergyGeneralEvaporationHas

!! Get, const
function EnergyGeneralEvaporationGetConst(handle) &
      bind(C, name='EnergyGeneralEvaporationGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyGeneralEvaporationGetConst
end function EnergyGeneralEvaporationGetConst

!! Get, non-const
function EnergyGeneralEvaporationGet(handle) &
      bind(C, name='EnergyGeneralEvaporationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyGeneralEvaporationGet
end function EnergyGeneralEvaporationGet

!! Set
subroutine EnergyGeneralEvaporationSet(handle, fieldHandle) &
      bind(C, name='EnergyGeneralEvaporationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyGeneralEvaporationSet


!! -----------------------------------------------------------------------------
!! Child: evaporation
!! -----------------------------------------------------------------------------

!! Has
function EnergyEvaporationHas(handle) &
      bind(C, name='EnergyEvaporationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyEvaporationHas
end function EnergyEvaporationHas

!! Get, const
function EnergyEvaporationGetConst(handle) &
      bind(C, name='EnergyEvaporationGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyEvaporationGetConst
end function EnergyEvaporationGetConst

!! Get, non-const
function EnergyEvaporationGet(handle) &
      bind(C, name='EnergyEvaporationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyEvaporationGet
end function EnergyEvaporationGet

!! Set
subroutine EnergyEvaporationSet(handle, fieldHandle) &
      bind(C, name='EnergyEvaporationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyEvaporationSet


!! -----------------------------------------------------------------------------
!! Child: weightedFunctionals
!! -----------------------------------------------------------------------------

!! Has
function EnergyWeightedFunctionalsHas(handle) &
      bind(C, name='EnergyWeightedFunctionalsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyWeightedFunctionalsHas
end function EnergyWeightedFunctionalsHas

!! Get, const
function EnergyWeightedFunctionalsGetConst(handle) &
      bind(C, name='EnergyWeightedFunctionalsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyWeightedFunctionalsGetConst
end function EnergyWeightedFunctionalsGetConst

!! Get, non-const
function EnergyWeightedFunctionalsGet(handle) &
      bind(C, name='EnergyWeightedFunctionalsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyWeightedFunctionalsGet
end function EnergyWeightedFunctionalsGet

!! Set
subroutine EnergyWeightedFunctionalsSet(handle, fieldHandle) &
      bind(C, name='EnergyWeightedFunctionalsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyWeightedFunctionalsSet


!! -----------------------------------------------------------------------------
!! Child: simpleMaxwellianFission
!! -----------------------------------------------------------------------------

!! Has
function EnergySimpleMaxwellianFissionHas(handle) &
      bind(C, name='EnergySimpleMaxwellianFissionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergySimpleMaxwellianFissionHas
end function EnergySimpleMaxwellianFissionHas

!! Get, const
function EnergySimpleMaxwellianFissionGetConst(handle) &
      bind(C, name='EnergySimpleMaxwellianFissionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergySimpleMaxwellianFissionGetConst
end function EnergySimpleMaxwellianFissionGetConst

!! Get, non-const
function EnergySimpleMaxwellianFissionGet(handle) &
      bind(C, name='EnergySimpleMaxwellianFissionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergySimpleMaxwellianFissionGet
end function EnergySimpleMaxwellianFissionGet

!! Set
subroutine EnergySimpleMaxwellianFissionSet(handle, fieldHandle) &
      bind(C, name='EnergySimpleMaxwellianFissionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergySimpleMaxwellianFissionSet


!! -----------------------------------------------------------------------------
!! Child: MadlandNix
!! -----------------------------------------------------------------------------

!! Has
function EnergyMadlandNixHas(handle) &
      bind(C, name='EnergyMadlandNixHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: EnergyMadlandNixHas
end function EnergyMadlandNixHas

!! Get, const
function EnergyMadlandNixGetConst(handle) &
      bind(C, name='EnergyMadlandNixGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: EnergyMadlandNixGetConst
end function EnergyMadlandNixGetConst

!! Get, non-const
function EnergyMadlandNixGet(handle) &
      bind(C, name='EnergyMadlandNixGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: EnergyMadlandNixGet
end function EnergyMadlandNixGet

!! Set
subroutine EnergyMadlandNixSet(handle, fieldHandle) &
      bind(C, name='EnergyMadlandNixSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine EnergyMadlandNixSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalEnergy