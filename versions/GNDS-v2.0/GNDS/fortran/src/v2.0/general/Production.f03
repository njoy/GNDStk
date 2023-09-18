
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalProduction
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ProductionDefaultConst() &
      bind(C, name='ProductionDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ProductionDefaultConst

!! Create, default
function ProductionDefault() &
      bind(C, name='ProductionDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ProductionDefault

!! Create, general, const
function ProductionCreateConst( &
   label, &
   ENDF_MT, &
   crossSection, &
   outputChannel, &
   labelSize &
) &
      bind(C, name='ProductionCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), value, intent(in) :: ENDF_MT
   type(c_ptr), value :: crossSection
   type(c_ptr), value :: outputChannel
   type(c_ptr) :: handle
end function ProductionCreateConst

!! Create, general
function ProductionCreate( &
   label, &
   ENDF_MT, &
   crossSection, &
   outputChannel, &
   labelSize &
) &
      bind(C, name='ProductionCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), value, intent(in) :: ENDF_MT
   type(c_ptr), value :: crossSection
   type(c_ptr), value :: outputChannel
   type(c_ptr) :: handle
end function ProductionCreate

!! Assign
subroutine ProductionAssign(handleLHS, handleRHS) &
      bind(C, name='ProductionAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ProductionAssign

!! Delete
subroutine ProductionDelete(handle) &
      bind(C, name='ProductionDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ProductionDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ProductionRead(handle, filename, filenameSize) &
      bind(C, name='ProductionRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ProductionRead

!! Write to file
function ProductionWrite(handle, filename, filenameSize) &
      bind(C, name='ProductionWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ProductionWrite

!! Print to standard output, in our prettyprinting format
function ProductionPrint(handle) &
      bind(C, name='ProductionPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ProductionPrint

!! Print to standard output, as XML
function ProductionPrintXML(handle) &
      bind(C, name='ProductionPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ProductionPrintXML

!! Print to standard output, as JSON
function ProductionPrintJSON(handle) &
      bind(C, name='ProductionPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ProductionPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ProductionLabelHas(handle) &
      bind(C, name='ProductionLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ProductionLabelHas

!! Get
function ProductionLabelGet(handle) &
      bind(C, name='ProductionLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function ProductionLabelGet

!! Set
subroutine ProductionLabelSet(handle, label, labelSize) &
      bind(C, name='ProductionLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ProductionLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: ENDF_MT
!! -----------------------------------------------------------------------------

!! Has
function ProductionENDFMTHas(handle) &
      bind(C, name='ProductionENDFMTHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ProductionENDFMTHas

!! Get
function ProductionENDFMTGet(handle) &
      bind(C, name='ProductionENDFMTGet') &
      result(ENDF_MT)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDF_MT
end function ProductionENDFMTGet

!! Set
subroutine ProductionENDFMTSet(handle, ENDF_MT, ENDF_MTSize) &
      bind(C, name='ProductionENDFMTSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: ENDF_MTSize
   character(c_char), intent(in) :: ENDF_MT(ENDF_MTSize)
end subroutine ProductionENDFMTSet


!! -----------------------------------------------------------------------------
!! Child: crossSection
!! -----------------------------------------------------------------------------

!! Has
function ProductionCrossSectionHas(handle) &
      bind(C, name='ProductionCrossSectionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ProductionCrossSectionHas

!! Get, const
function ProductionCrossSectionGetConst(handle) &
      bind(C, name='ProductionCrossSectionGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ProductionCrossSectionGetConst

!! Get
function ProductionCrossSectionGet(handle) &
      bind(C, name='ProductionCrossSectionGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ProductionCrossSectionGet

!! Set
subroutine ProductionCrossSectionSet(handle, fieldHandle) &
      bind(C, name='ProductionCrossSectionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ProductionCrossSectionSet


!! -----------------------------------------------------------------------------
!! Child: outputChannel
!! -----------------------------------------------------------------------------

!! Has
function ProductionOutputChannelHas(handle) &
      bind(C, name='ProductionOutputChannelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ProductionOutputChannelHas

!! Get, const
function ProductionOutputChannelGetConst(handle) &
      bind(C, name='ProductionOutputChannelGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ProductionOutputChannelGetConst

!! Get
function ProductionOutputChannelGet(handle) &
      bind(C, name='ProductionOutputChannelGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ProductionOutputChannelGet

!! Set
subroutine ProductionOutputChannelSet(handle, fieldHandle) &
      bind(C, name='ProductionOutputChannelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ProductionOutputChannelSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalProduction
