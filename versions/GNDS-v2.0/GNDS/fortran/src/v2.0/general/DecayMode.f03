
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalDecayMode
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DecayModeDefaultConst() &
      bind(C, name='DecayModeDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DecayModeDefaultConst
end function DecayModeDefaultConst

!! Create, default
function DecayModeDefault() &
      bind(C, name='DecayModeDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DecayModeDefault
end function DecayModeDefault

!! Create, general, const
function DecayModeCreateConst( &
   label, &
   mode, &
   probability, &
   decayPath, &
   photonEmissionProbabilities, &
   Q, &
   spectra, &
   labelSize, &
   modeSize &
) &
      bind(C, name='DecayModeCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: modeSize
   character(c_char), intent(in) :: mode(modeSize)
   type(c_ptr), intent(in), value :: probability
   type(c_ptr), intent(in), value :: decayPath
   type(c_ptr), intent(in), value :: photonEmissionProbabilities
   type(c_ptr), intent(in), value :: Q
   type(c_ptr), intent(in), value :: spectra
   type(c_ptr) :: DecayModeCreateConst
end function DecayModeCreateConst

!! Create, general
function DecayModeCreate( &
   label, &
   mode, &
   probability, &
   decayPath, &
   photonEmissionProbabilities, &
   Q, &
   spectra, &
   labelSize, &
   modeSize &
) &
      bind(C, name='DecayModeCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: modeSize
   character(c_char), intent(in) :: mode(modeSize)
   type(c_ptr), intent(in), value :: probability
   type(c_ptr), intent(in), value :: decayPath
   type(c_ptr), intent(in), value :: photonEmissionProbabilities
   type(c_ptr), intent(in), value :: Q
   type(c_ptr), intent(in), value :: spectra
   type(c_ptr) :: DecayModeCreate
end function DecayModeCreate

!! Assign
subroutine DecayModeAssign(handleLHS, handleRHS) &
      bind(C, name='DecayModeAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine DecayModeAssign

!! Delete
subroutine DecayModeDelete(handle) &
      bind(C, name='DecayModeDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DecayModeDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function DecayModeRead(handle, filename, filenameSize) &
      bind(C, name='DecayModeRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DecayModeRead
end function DecayModeRead

!! Write to file
function DecayModeWrite(handle, filename, filenameSize) &
      bind(C, name='DecayModeWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DecayModeWrite
end function DecayModeWrite

!! Print to standard output, in our prettyprinting format
function DecayModePrint(handle) &
      bind(C, name='DecayModePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModePrint
end function DecayModePrint

!! Print to standard output, as XML
function DecayModePrintXML(handle) &
      bind(C, name='DecayModePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModePrintXML
end function DecayModePrintXML

!! Print to standard output, as JSON
function DecayModePrintJSON(handle) &
      bind(C, name='DecayModePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModePrintJSON
end function DecayModePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function DecayModeLabelHas(handle) &
      bind(C, name='DecayModeLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModeLabelHas
end function DecayModeLabelHas

!! Get
function DecayModeLabelGet(handle) &
      bind(C, name='DecayModeLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModeLabelGet
end function DecayModeLabelGet

!! Set
subroutine DecayModeLabelSet(handle, label, labelSize) &
      bind(C, name='DecayModeLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine DecayModeLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: mode
!! -----------------------------------------------------------------------------

!! Has
function DecayModeModeHas(handle) &
      bind(C, name='DecayModeModeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModeModeHas
end function DecayModeModeHas

!! Get
function DecayModeModeGet(handle) &
      bind(C, name='DecayModeModeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModeModeGet
end function DecayModeModeGet

!! Set
subroutine DecayModeModeSet(handle, mode, modeSize) &
      bind(C, name='DecayModeModeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: modeSize
   character(c_char), intent(in) :: mode(modeSize)
end subroutine DecayModeModeSet


!! -----------------------------------------------------------------------------
!! Child: probability
!! -----------------------------------------------------------------------------

!! Has
function DecayModeProbabilityHas(handle) &
      bind(C, name='DecayModeProbabilityHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModeProbabilityHas
end function DecayModeProbabilityHas

!! Get, const
function DecayModeProbabilityGetConst(handle) &
      bind(C, name='DecayModeProbabilityGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModeProbabilityGetConst
end function DecayModeProbabilityGetConst

!! Get
function DecayModeProbabilityGet(handle) &
      bind(C, name='DecayModeProbabilityGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayModeProbabilityGet
end function DecayModeProbabilityGet

!! Set
subroutine DecayModeProbabilitySet(handle, fieldHandle) &
      bind(C, name='DecayModeProbabilitySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayModeProbabilitySet


!! -----------------------------------------------------------------------------
!! Child: decayPath
!! -----------------------------------------------------------------------------

!! Has
function DecayModeDecayPathHas(handle) &
      bind(C, name='DecayModeDecayPathHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModeDecayPathHas
end function DecayModeDecayPathHas

!! Get, const
function DecayModeDecayPathGetConst(handle) &
      bind(C, name='DecayModeDecayPathGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModeDecayPathGetConst
end function DecayModeDecayPathGetConst

!! Get
function DecayModeDecayPathGet(handle) &
      bind(C, name='DecayModeDecayPathGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayModeDecayPathGet
end function DecayModeDecayPathGet

!! Set
subroutine DecayModeDecayPathSet(handle, fieldHandle) &
      bind(C, name='DecayModeDecayPathSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayModeDecayPathSet


!! -----------------------------------------------------------------------------
!! Child: photonEmissionProbabilities
!! -----------------------------------------------------------------------------

!! Has
function DecayModePhotonEmissionProbabilitiesHas(handle) &
      bind(C, name='DecayModePhotonEmissionProbabilitiesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModePhotonEmissionProbabilitiesHas
end function DecayModePhotonEmissionProbabilitiesHas

!! Get, const
function DecayModePhotonEmissionProbabilitiesGetConst(handle) &
      bind(C, name='DecayModePhotonEmissionProbabilitiesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModePhotonEmissionProbabilitiesGetConst
end function DecayModePhotonEmissionProbabilitiesGetConst

!! Get
function DecayModePhotonEmissionProbabilitiesGet(handle) &
      bind(C, name='DecayModePhotonEmissionProbabilitiesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayModePhotonEmissionProbabilitiesGet
end function DecayModePhotonEmissionProbabilitiesGet

!! Set
subroutine DecayModePhotonEmissionProbabilitiesSet(handle, fieldHandle) &
      bind(C, name='DecayModePhotonEmissionProbabilitiesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayModePhotonEmissionProbabilitiesSet


!! -----------------------------------------------------------------------------
!! Child: Q
!! -----------------------------------------------------------------------------

!! Has
function DecayModeQHas(handle) &
      bind(C, name='DecayModeQHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModeQHas
end function DecayModeQHas

!! Get, const
function DecayModeQGetConst(handle) &
      bind(C, name='DecayModeQGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModeQGetConst
end function DecayModeQGetConst

!! Get
function DecayModeQGet(handle) &
      bind(C, name='DecayModeQGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayModeQGet
end function DecayModeQGet

!! Set
subroutine DecayModeQSet(handle, fieldHandle) &
      bind(C, name='DecayModeQSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayModeQSet


!! -----------------------------------------------------------------------------
!! Child: spectra
!! -----------------------------------------------------------------------------

!! Has
function DecayModeSpectraHas(handle) &
      bind(C, name='DecayModeSpectraHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModeSpectraHas
end function DecayModeSpectraHas

!! Get, const
function DecayModeSpectraGetConst(handle) &
      bind(C, name='DecayModeSpectraGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModeSpectraGetConst
end function DecayModeSpectraGetConst

!! Get
function DecayModeSpectraGet(handle) &
      bind(C, name='DecayModeSpectraGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayModeSpectraGet
end function DecayModeSpectraGet

!! Set
subroutine DecayModeSpectraSet(handle, fieldHandle) &
      bind(C, name='DecayModeSpectraSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayModeSpectraSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalDecayMode
