
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalBreitWigner
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function BreitWignerDefaultConst() &
      bind(C, name='BreitWignerDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function BreitWignerDefaultConst

!! Create, default
function BreitWignerDefault() &
      bind(C, name='BreitWignerDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function BreitWignerDefault

!! Create, general, const
function BreitWignerCreateConst( &
   label, &
   approximation, &
   calculateChannelRadius, &
   resonanceParameters, &
   PoPs, &
   scatteringRadius, &
   labelSize, &
   approximationSize &
) &
      bind(C, name='BreitWignerCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: approximationSize
   character(c_char), intent(in) :: approximation(approximationSize)
   integer(c_bool), value, intent(in) :: calculateChannelRadius
   type(c_ptr), value :: resonanceParameters
   type(c_ptr), value :: PoPs
   type(c_ptr), value :: scatteringRadius
   type(c_ptr) :: handle
end function BreitWignerCreateConst

!! Create, general
function BreitWignerCreate( &
   label, &
   approximation, &
   calculateChannelRadius, &
   resonanceParameters, &
   PoPs, &
   scatteringRadius, &
   labelSize, &
   approximationSize &
) &
      bind(C, name='BreitWignerCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: approximationSize
   character(c_char), intent(in) :: approximation(approximationSize)
   integer(c_bool), value, intent(in) :: calculateChannelRadius
   type(c_ptr), value :: resonanceParameters
   type(c_ptr), value :: PoPs
   type(c_ptr), value :: scatteringRadius
   type(c_ptr) :: handle
end function BreitWignerCreate

!! Assign
subroutine BreitWignerAssign(handleLHS, handleRHS) &
      bind(C, name='BreitWignerAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine BreitWignerAssign

!! Delete
subroutine BreitWignerDelete(handle) &
      bind(C, name='BreitWignerDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine BreitWignerDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function BreitWignerRead(handle, filename, filenameSize) &
      bind(C, name='BreitWignerRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function BreitWignerRead

!! Write to file
function BreitWignerWrite(handle, filename, filenameSize) &
      bind(C, name='BreitWignerWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function BreitWignerWrite

!! Print to standard output, in our prettyprinting format
function BreitWignerPrint(handle) &
      bind(C, name='BreitWignerPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function BreitWignerPrint

!! Print to standard output, as XML
function BreitWignerPrintXML(handle) &
      bind(C, name='BreitWignerPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function BreitWignerPrintXML

!! Print to standard output, as JSON
function BreitWignerPrintJSON(handle) &
      bind(C, name='BreitWignerPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function BreitWignerPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function BreitWignerLabelHas(handle) &
      bind(C, name='BreitWignerLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function BreitWignerLabelHas

!! Get
function BreitWignerLabelGet(handle) &
      bind(C, name='BreitWignerLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function BreitWignerLabelGet

!! Set
subroutine BreitWignerLabelSet(handle, label, labelSize) &
      bind(C, name='BreitWignerLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine BreitWignerLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: approximation
!! -----------------------------------------------------------------------------

!! Has
function BreitWignerApproximationHas(handle) &
      bind(C, name='BreitWignerApproximationHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function BreitWignerApproximationHas

!! Get
function BreitWignerApproximationGet(handle) &
      bind(C, name='BreitWignerApproximationGet') &
      result(approximation)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: approximation
end function BreitWignerApproximationGet

!! Set
subroutine BreitWignerApproximationSet(handle, approximation, approximationSize) &
      bind(C, name='BreitWignerApproximationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: approximationSize
   character(c_char), intent(in) :: approximation(approximationSize)
end subroutine BreitWignerApproximationSet


!! -----------------------------------------------------------------------------
!! Metadatum: calculateChannelRadius
!! -----------------------------------------------------------------------------

!! Has
function BreitWignerCalculateChannelRadiusHas(handle) &
      bind(C, name='BreitWignerCalculateChannelRadiusHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function BreitWignerCalculateChannelRadiusHas

!! Get
function BreitWignerCalculateChannelRadiusGet(handle) &
      bind(C, name='BreitWignerCalculateChannelRadiusGet') &
      result(calculateChannelRadius)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_bool) :: calculateChannelRadius
end function BreitWignerCalculateChannelRadiusGet

!! Set
subroutine BreitWignerCalculateChannelRadiusSet(handle, calculateChannelRadius, calculateChannelRadiusSize) &
      bind(C, name='BreitWignerCalculateChannelRadiusSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: calculateChannelRadiusSize
   character(c_char), intent(in) :: calculateChannelRadius(calculateChannelRadiusSize)
end subroutine BreitWignerCalculateChannelRadiusSet


!! -----------------------------------------------------------------------------
!! Child: resonanceParameters
!! -----------------------------------------------------------------------------

!! Has
function BreitWignerResonanceParametersHas(handle) &
      bind(C, name='BreitWignerResonanceParametersHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function BreitWignerResonanceParametersHas

!! Get, const
function BreitWignerResonanceParametersGetConst(handle) &
      bind(C, name='BreitWignerResonanceParametersGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function BreitWignerResonanceParametersGetConst

!! Get
function BreitWignerResonanceParametersGet(handle) &
      bind(C, name='BreitWignerResonanceParametersGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function BreitWignerResonanceParametersGet

!! Set
subroutine BreitWignerResonanceParametersSet(handle, fieldHandle) &
      bind(C, name='BreitWignerResonanceParametersSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine BreitWignerResonanceParametersSet


!! -----------------------------------------------------------------------------
!! Child: PoPs
!! -----------------------------------------------------------------------------

!! Has
function BreitWignerPoPsHas(handle) &
      bind(C, name='BreitWignerPoPsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function BreitWignerPoPsHas

!! Get, const
function BreitWignerPoPsGetConst(handle) &
      bind(C, name='BreitWignerPoPsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function BreitWignerPoPsGetConst

!! Get
function BreitWignerPoPsGet(handle) &
      bind(C, name='BreitWignerPoPsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function BreitWignerPoPsGet

!! Set
subroutine BreitWignerPoPsSet(handle, fieldHandle) &
      bind(C, name='BreitWignerPoPsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine BreitWignerPoPsSet


!! -----------------------------------------------------------------------------
!! Child: scatteringRadius
!! -----------------------------------------------------------------------------

!! Has
function BreitWignerScatteringRadiusHas(handle) &
      bind(C, name='BreitWignerScatteringRadiusHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function BreitWignerScatteringRadiusHas

!! Get, const
function BreitWignerScatteringRadiusGetConst(handle) &
      bind(C, name='BreitWignerScatteringRadiusGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function BreitWignerScatteringRadiusGetConst

!! Get
function BreitWignerScatteringRadiusGet(handle) &
      bind(C, name='BreitWignerScatteringRadiusGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function BreitWignerScatteringRadiusGet

!! Set
subroutine BreitWignerScatteringRadiusSet(handle, fieldHandle) &
      bind(C, name='BreitWignerScatteringRadiusSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine BreitWignerScatteringRadiusSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalBreitWigner
