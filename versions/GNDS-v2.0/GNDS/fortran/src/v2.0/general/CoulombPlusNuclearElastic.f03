
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalCoulombPlusNuclearElastic
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function CoulombPlusNuclearElasticDefaultConst() &
      bind(C, name='CoulombPlusNuclearElasticDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function CoulombPlusNuclearElasticDefaultConst

!! Create, default
function CoulombPlusNuclearElasticDefault() &
      bind(C, name='CoulombPlusNuclearElasticDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function CoulombPlusNuclearElasticDefault

!! Create, general, const
function CoulombPlusNuclearElasticCreateConst( &
   label, &
   href, &
   pid, &
   productFrame, &
   identicalParticles, &
   RutherfordScattering, &
   nuclearAmplitudeExpansion, &
   nuclearPlusInterference, &
   labelSize, &
   hrefSize, &
   pidSize, &
   productFrameSize &
) &
      bind(C, name='CoulombPlusNuclearElasticCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   integer(c_bool), value, intent(in) :: identicalParticles
   type(c_ptr), value :: RutherfordScattering
   type(c_ptr), value :: nuclearAmplitudeExpansion
   type(c_ptr), value :: nuclearPlusInterference
   type(c_ptr) :: handle
end function CoulombPlusNuclearElasticCreateConst

!! Create, general
function CoulombPlusNuclearElasticCreate( &
   label, &
   href, &
   pid, &
   productFrame, &
   identicalParticles, &
   RutherfordScattering, &
   nuclearAmplitudeExpansion, &
   nuclearPlusInterference, &
   labelSize, &
   hrefSize, &
   pidSize, &
   productFrameSize &
) &
      bind(C, name='CoulombPlusNuclearElasticCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   integer(c_bool), value, intent(in) :: identicalParticles
   type(c_ptr), value :: RutherfordScattering
   type(c_ptr), value :: nuclearAmplitudeExpansion
   type(c_ptr), value :: nuclearPlusInterference
   type(c_ptr) :: handle
end function CoulombPlusNuclearElasticCreate

!! Assign
subroutine CoulombPlusNuclearElasticAssign(handleLHS, handleRHS) &
      bind(C, name='CoulombPlusNuclearElasticAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine CoulombPlusNuclearElasticAssign

!! Delete
subroutine CoulombPlusNuclearElasticDelete(handle) &
      bind(C, name='CoulombPlusNuclearElasticDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine CoulombPlusNuclearElasticDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function CoulombPlusNuclearElasticRead(handle, filename, filenameSize) &
      bind(C, name='CoulombPlusNuclearElasticRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function CoulombPlusNuclearElasticRead

!! Write to file
function CoulombPlusNuclearElasticWrite(handle, filename, filenameSize) &
      bind(C, name='CoulombPlusNuclearElasticWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function CoulombPlusNuclearElasticWrite

!! Print to standard output, in our prettyprinting format
function CoulombPlusNuclearElasticPrint(handle) &
      bind(C, name='CoulombPlusNuclearElasticPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function CoulombPlusNuclearElasticPrint

!! Print to standard output, as XML
function CoulombPlusNuclearElasticPrintXML(handle) &
      bind(C, name='CoulombPlusNuclearElasticPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function CoulombPlusNuclearElasticPrintXML

!! Print to standard output, as JSON
function CoulombPlusNuclearElasticPrintJSON(handle) &
      bind(C, name='CoulombPlusNuclearElasticPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function CoulombPlusNuclearElasticPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticLabelHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticLabelHas

!! Get
function CoulombPlusNuclearElasticLabelGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function CoulombPlusNuclearElasticLabelGet

!! Set
subroutine CoulombPlusNuclearElasticLabelSet(handle, label, labelSize) &
      bind(C, name='CoulombPlusNuclearElasticLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine CoulombPlusNuclearElasticLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticHrefHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticHrefHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticHrefHas

!! Get
function CoulombPlusNuclearElasticHrefGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticHrefGet') &
      result(href)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: href
end function CoulombPlusNuclearElasticHrefGet

!! Set
subroutine CoulombPlusNuclearElasticHrefSet(handle, href, hrefSize) &
      bind(C, name='CoulombPlusNuclearElasticHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine CoulombPlusNuclearElasticHrefSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticPidHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticPidHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticPidHas

!! Get
function CoulombPlusNuclearElasticPidGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticPidGet') &
      result(pid)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: pid
end function CoulombPlusNuclearElasticPidGet

!! Set
subroutine CoulombPlusNuclearElasticPidSet(handle, pid, pidSize) &
      bind(C, name='CoulombPlusNuclearElasticPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine CoulombPlusNuclearElasticPidSet


!! -----------------------------------------------------------------------------
!! Metadatum: productFrame
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticProductFrameHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticProductFrameHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticProductFrameHas

!! Get
function CoulombPlusNuclearElasticProductFrameGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticProductFrameGet') &
      result(productFrame)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: productFrame
end function CoulombPlusNuclearElasticProductFrameGet

!! Set
subroutine CoulombPlusNuclearElasticProductFrameSet(handle, productFrame, productFrameSize) &
      bind(C, name='CoulombPlusNuclearElasticProductFrameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
end subroutine CoulombPlusNuclearElasticProductFrameSet


!! -----------------------------------------------------------------------------
!! Metadatum: identicalParticles
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticIdenticalParticlesHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticIdenticalParticlesHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticIdenticalParticlesHas

!! Get
function CoulombPlusNuclearElasticIdenticalParticlesGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticIdenticalParticlesGet') &
      result(identicalParticles)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_bool) :: identicalParticles
end function CoulombPlusNuclearElasticIdenticalParticlesGet

!! Set
subroutine CoulombPlusNuclearElasticIdenticalParticlesSet(handle, identicalParticles, identicalParticlesSize) &
      bind(C, name='CoulombPlusNuclearElasticIdenticalParticlesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: identicalParticlesSize
   character(c_char), intent(in) :: identicalParticles(identicalParticlesSize)
end subroutine CoulombPlusNuclearElasticIdenticalParticlesSet


!! -----------------------------------------------------------------------------
!! Child: RutherfordScattering
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticRutherfordScatteringHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticRutherfordScatteringHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticRutherfordScatteringHas

!! Get, const
function CoulombPlusNuclearElasticRutherfordScatteringGetConst(handle) &
      bind(C, name='CoulombPlusNuclearElasticRutherfordScatteringGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function CoulombPlusNuclearElasticRutherfordScatteringGetConst

!! Get
function CoulombPlusNuclearElasticRutherfordScatteringGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticRutherfordScatteringGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function CoulombPlusNuclearElasticRutherfordScatteringGet

!! Set
subroutine CoulombPlusNuclearElasticRutherfordScatteringSet(handle, fieldHandle) &
      bind(C, name='CoulombPlusNuclearElasticRutherfordScatteringSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine CoulombPlusNuclearElasticRutherfordScatteringSet


!! -----------------------------------------------------------------------------
!! Child: nuclearAmplitudeExpansion
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticNuclearAmplitudeExpansionHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearAmplitudeExpansionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticNuclearAmplitudeExpansionHas

!! Get, const
function CoulombPlusNuclearElasticNuclearAmplitudeExpansionGetConst(handle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearAmplitudeExpansionGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function CoulombPlusNuclearElasticNuclearAmplitudeExpansionGetConst

!! Get
function CoulombPlusNuclearElasticNuclearAmplitudeExpansionGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearAmplitudeExpansionGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function CoulombPlusNuclearElasticNuclearAmplitudeExpansionGet

!! Set
subroutine CoulombPlusNuclearElasticNuclearAmplitudeExpansionSet(handle, fieldHandle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearAmplitudeExpansionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine CoulombPlusNuclearElasticNuclearAmplitudeExpansionSet


!! -----------------------------------------------------------------------------
!! Child: nuclearPlusInterference
!! -----------------------------------------------------------------------------

!! Has
function CoulombPlusNuclearElasticNuclearPlusInterferenceHas(handle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearPlusInterferenceHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function CoulombPlusNuclearElasticNuclearPlusInterferenceHas

!! Get, const
function CoulombPlusNuclearElasticNuclearPlusInterferenceGetConst(handle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearPlusInterferenceGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function CoulombPlusNuclearElasticNuclearPlusInterferenceGetConst

!! Get
function CoulombPlusNuclearElasticNuclearPlusInterferenceGet(handle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearPlusInterferenceGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function CoulombPlusNuclearElasticNuclearPlusInterferenceGet

!! Set
subroutine CoulombPlusNuclearElasticNuclearPlusInterferenceSet(handle, fieldHandle) &
      bind(C, name='CoulombPlusNuclearElasticNuclearPlusInterferenceSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine CoulombPlusNuclearElasticNuclearPlusInterferenceSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalCoulombPlusNuclearElastic
