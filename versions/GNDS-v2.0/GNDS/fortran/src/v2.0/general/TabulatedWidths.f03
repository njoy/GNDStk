
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalTabulatedWidths
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function TabulatedWidthsDefaultConst() &
      bind(C, name='TabulatedWidthsDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function TabulatedWidthsDefaultConst

!! Create, default
function TabulatedWidthsDefault() &
      bind(C, name='TabulatedWidthsDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function TabulatedWidthsDefault

!! Create, general, const
function TabulatedWidthsCreateConst( &
   label, &
   approximation, &
   useForSelfShieldingOnly, &
   resonanceReactions, &
   Ls, &
   PoPs, &
   scatteringRadius, &
   labelSize, &
   approximationSize &
) &
      bind(C, name='TabulatedWidthsCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: approximationSize
   character(c_char), intent(in) :: approximation(approximationSize)
   unknownType, value, intent(in) :: useForSelfShieldingOnly
   type(c_ptr), value :: resonanceReactions
   type(c_ptr), value :: Ls
   type(c_ptr), value :: PoPs
   type(c_ptr), value :: scatteringRadius
   type(c_ptr) :: handle
end function TabulatedWidthsCreateConst

!! Create, general
function TabulatedWidthsCreate( &
   label, &
   approximation, &
   useForSelfShieldingOnly, &
   resonanceReactions, &
   Ls, &
   PoPs, &
   scatteringRadius, &
   labelSize, &
   approximationSize &
) &
      bind(C, name='TabulatedWidthsCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: approximationSize
   character(c_char), intent(in) :: approximation(approximationSize)
   unknownType, value, intent(in) :: useForSelfShieldingOnly
   type(c_ptr), value :: resonanceReactions
   type(c_ptr), value :: Ls
   type(c_ptr), value :: PoPs
   type(c_ptr), value :: scatteringRadius
   type(c_ptr) :: handle
end function TabulatedWidthsCreate

!! Assign
subroutine TabulatedWidthsAssign(handleLHS, handleRHS) &
      bind(C, name='TabulatedWidthsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine TabulatedWidthsAssign

!! Delete
subroutine TabulatedWidthsDelete(handle) &
      bind(C, name='TabulatedWidthsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine TabulatedWidthsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function TabulatedWidthsRead(handle, filename, filenameSize) &
      bind(C, name='TabulatedWidthsRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function TabulatedWidthsRead

!! Write to file
function TabulatedWidthsWrite(handle, filename, filenameSize) &
      bind(C, name='TabulatedWidthsWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function TabulatedWidthsWrite

!! Print to standard output, in our prettyprinting format
function TabulatedWidthsPrint(handle) &
      bind(C, name='TabulatedWidthsPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function TabulatedWidthsPrint

!! Print to standard output, as XML
function TabulatedWidthsPrintXML(handle) &
      bind(C, name='TabulatedWidthsPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function TabulatedWidthsPrintXML

!! Print to standard output, as JSON
function TabulatedWidthsPrintJSON(handle) &
      bind(C, name='TabulatedWidthsPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function TabulatedWidthsPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function TabulatedWidthsLabelHas(handle) &
      bind(C, name='TabulatedWidthsLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TabulatedWidthsLabelHas

!! Get
function TabulatedWidthsLabelGet(handle) &
      bind(C, name='TabulatedWidthsLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function TabulatedWidthsLabelGet

!! Set
subroutine TabulatedWidthsLabelSet(handle, label, labelSize) &
      bind(C, name='TabulatedWidthsLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine TabulatedWidthsLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: approximation
!! -----------------------------------------------------------------------------

!! Has
function TabulatedWidthsApproximationHas(handle) &
      bind(C, name='TabulatedWidthsApproximationHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TabulatedWidthsApproximationHas

!! Get
function TabulatedWidthsApproximationGet(handle) &
      bind(C, name='TabulatedWidthsApproximationGet') &
      result(approximation)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: approximation
end function TabulatedWidthsApproximationGet

!! Set
subroutine TabulatedWidthsApproximationSet(handle, approximation, approximationSize) &
      bind(C, name='TabulatedWidthsApproximationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: approximationSize
   character(c_char), intent(in) :: approximation(approximationSize)
end subroutine TabulatedWidthsApproximationSet


!! -----------------------------------------------------------------------------
!! Metadatum: useForSelfShieldingOnly
!! -----------------------------------------------------------------------------

!! Has
function TabulatedWidthsUseForSelfShieldingOnlyHas(handle) &
      bind(C, name='TabulatedWidthsUseForSelfShieldingOnlyHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TabulatedWidthsUseForSelfShieldingOnlyHas

!! Get
function TabulatedWidthsUseForSelfShieldingOnlyGet(handle) &
      bind(C, name='TabulatedWidthsUseForSelfShieldingOnlyGet') &
      result(useForSelfShieldingOnly)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   unknownType :: useForSelfShieldingOnly
end function TabulatedWidthsUseForSelfShieldingOnlyGet

!! Set
subroutine TabulatedWidthsUseForSelfShieldingOnlySet(handle, useForSelfShieldingOnly, useForSelfShieldingOnlySize) &
      bind(C, name='TabulatedWidthsUseForSelfShieldingOnlySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: useForSelfShieldingOnlySize
   character(c_char), intent(in) :: useForSelfShieldingOnly(useForSelfShieldingOnlySize)
end subroutine TabulatedWidthsUseForSelfShieldingOnlySet


!! -----------------------------------------------------------------------------
!! Child: resonanceReactions
!! -----------------------------------------------------------------------------

!! Has
function TabulatedWidthsResonanceReactionsHas(handle) &
      bind(C, name='TabulatedWidthsResonanceReactionsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TabulatedWidthsResonanceReactionsHas

!! Get, const
function TabulatedWidthsResonanceReactionsGetConst(handle) &
      bind(C, name='TabulatedWidthsResonanceReactionsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsResonanceReactionsGetConst

!! Get
function TabulatedWidthsResonanceReactionsGet(handle) &
      bind(C, name='TabulatedWidthsResonanceReactionsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsResonanceReactionsGet

!! Set
subroutine TabulatedWidthsResonanceReactionsSet(handle, fieldHandle) &
      bind(C, name='TabulatedWidthsResonanceReactionsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine TabulatedWidthsResonanceReactionsSet


!! -----------------------------------------------------------------------------
!! Child: Ls
!! -----------------------------------------------------------------------------

!! Has
function TabulatedWidthsLsHas(handle) &
      bind(C, name='TabulatedWidthsLsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TabulatedWidthsLsHas

!! Get, const
function TabulatedWidthsLsGetConst(handle) &
      bind(C, name='TabulatedWidthsLsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsLsGetConst

!! Get
function TabulatedWidthsLsGet(handle) &
      bind(C, name='TabulatedWidthsLsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsLsGet

!! Set
subroutine TabulatedWidthsLsSet(handle, fieldHandle) &
      bind(C, name='TabulatedWidthsLsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine TabulatedWidthsLsSet


!! -----------------------------------------------------------------------------
!! Child: PoPs
!! -----------------------------------------------------------------------------

!! Has
function TabulatedWidthsPoPsHas(handle) &
      bind(C, name='TabulatedWidthsPoPsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TabulatedWidthsPoPsHas

!! Get, const
function TabulatedWidthsPoPsGetConst(handle) &
      bind(C, name='TabulatedWidthsPoPsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsPoPsGetConst

!! Get
function TabulatedWidthsPoPsGet(handle) &
      bind(C, name='TabulatedWidthsPoPsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsPoPsGet

!! Set
subroutine TabulatedWidthsPoPsSet(handle, fieldHandle) &
      bind(C, name='TabulatedWidthsPoPsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine TabulatedWidthsPoPsSet


!! -----------------------------------------------------------------------------
!! Child: scatteringRadius
!! -----------------------------------------------------------------------------

!! Has
function TabulatedWidthsScatteringRadiusHas(handle) &
      bind(C, name='TabulatedWidthsScatteringRadiusHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function TabulatedWidthsScatteringRadiusHas

!! Get, const
function TabulatedWidthsScatteringRadiusGetConst(handle) &
      bind(C, name='TabulatedWidthsScatteringRadiusGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsScatteringRadiusGetConst

!! Get
function TabulatedWidthsScatteringRadiusGet(handle) &
      bind(C, name='TabulatedWidthsScatteringRadiusGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function TabulatedWidthsScatteringRadiusGet

!! Set
subroutine TabulatedWidthsScatteringRadiusSet(handle, fieldHandle) &
      bind(C, name='TabulatedWidthsScatteringRadiusSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine TabulatedWidthsScatteringRadiusSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalTabulatedWidths
