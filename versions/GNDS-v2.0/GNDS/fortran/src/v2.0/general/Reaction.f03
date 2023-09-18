
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalReaction
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ReactionDefaultConst() &
      bind(C, name='ReactionDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ReactionDefaultConst

!! Create, default
function ReactionDefault() &
      bind(C, name='ReactionDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ReactionDefault

!! Create, general, const
function ReactionCreateConst( &
   label, &
   ENDF_MT, &
   fissionGenre, &
   crossSection, &
   outputChannel, &
   doubleDifferentialCrossSection, &
   labelSize, &
   fissionGenreSize &
) &
      bind(C, name='ReactionCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), value, intent(in) :: ENDF_MT
   integer(c_size_t), intent(in), value :: fissionGenreSize
   character(c_char), intent(in) :: fissionGenre(fissionGenreSize)
   type(c_ptr), value :: crossSection
   type(c_ptr), value :: outputChannel
   type(c_ptr), value :: doubleDifferentialCrossSection
   type(c_ptr) :: handle
end function ReactionCreateConst

!! Create, general
function ReactionCreate( &
   label, &
   ENDF_MT, &
   fissionGenre, &
   crossSection, &
   outputChannel, &
   doubleDifferentialCrossSection, &
   labelSize, &
   fissionGenreSize &
) &
      bind(C, name='ReactionCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), value, intent(in) :: ENDF_MT
   integer(c_size_t), intent(in), value :: fissionGenreSize
   character(c_char), intent(in) :: fissionGenre(fissionGenreSize)
   type(c_ptr), value :: crossSection
   type(c_ptr), value :: outputChannel
   type(c_ptr), value :: doubleDifferentialCrossSection
   type(c_ptr) :: handle
end function ReactionCreate

!! Assign
subroutine ReactionAssign(handleLHS, handleRHS) &
      bind(C, name='ReactionAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ReactionAssign

!! Delete
subroutine ReactionDelete(handle) &
      bind(C, name='ReactionDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ReactionDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ReactionRead(handle, filename, filenameSize) &
      bind(C, name='ReactionRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ReactionRead

!! Write to file
function ReactionWrite(handle, filename, filenameSize) &
      bind(C, name='ReactionWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ReactionWrite

!! Print to standard output, in our prettyprinting format
function ReactionPrint(handle) &
      bind(C, name='ReactionPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ReactionPrint

!! Print to standard output, as XML
function ReactionPrintXML(handle) &
      bind(C, name='ReactionPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ReactionPrintXML

!! Print to standard output, as JSON
function ReactionPrintJSON(handle) &
      bind(C, name='ReactionPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ReactionPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ReactionLabelHas(handle) &
      bind(C, name='ReactionLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ReactionLabelHas

!! Get
function ReactionLabelGet(handle) &
      bind(C, name='ReactionLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function ReactionLabelGet

!! Set
subroutine ReactionLabelSet(handle, label, labelSize) &
      bind(C, name='ReactionLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ReactionLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: ENDF_MT
!! -----------------------------------------------------------------------------

!! Has
function ReactionENDFMTHas(handle) &
      bind(C, name='ReactionENDFMTHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ReactionENDFMTHas

!! Get
function ReactionENDFMTGet(handle) &
      bind(C, name='ReactionENDFMTGet') &
      result(ENDF_MT)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDF_MT
end function ReactionENDFMTGet

!! Set
subroutine ReactionENDFMTSet(handle, ENDF_MT, ENDF_MTSize) &
      bind(C, name='ReactionENDFMTSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: ENDF_MTSize
   character(c_char), intent(in) :: ENDF_MT(ENDF_MTSize)
end subroutine ReactionENDFMTSet


!! -----------------------------------------------------------------------------
!! Metadatum: fissionGenre
!! -----------------------------------------------------------------------------

!! Has
function ReactionFissionGenreHas(handle) &
      bind(C, name='ReactionFissionGenreHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ReactionFissionGenreHas

!! Get
function ReactionFissionGenreGet(handle) &
      bind(C, name='ReactionFissionGenreGet') &
      result(fissionGenre)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: fissionGenre
end function ReactionFissionGenreGet

!! Set
subroutine ReactionFissionGenreSet(handle, fissionGenre, fissionGenreSize) &
      bind(C, name='ReactionFissionGenreSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: fissionGenreSize
   character(c_char), intent(in) :: fissionGenre(fissionGenreSize)
end subroutine ReactionFissionGenreSet


!! -----------------------------------------------------------------------------
!! Child: crossSection
!! -----------------------------------------------------------------------------

!! Has
function ReactionCrossSectionHas(handle) &
      bind(C, name='ReactionCrossSectionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ReactionCrossSectionHas

!! Get, const
function ReactionCrossSectionGetConst(handle) &
      bind(C, name='ReactionCrossSectionGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ReactionCrossSectionGetConst

!! Get
function ReactionCrossSectionGet(handle) &
      bind(C, name='ReactionCrossSectionGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ReactionCrossSectionGet

!! Set
subroutine ReactionCrossSectionSet(handle, fieldHandle) &
      bind(C, name='ReactionCrossSectionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ReactionCrossSectionSet


!! -----------------------------------------------------------------------------
!! Child: outputChannel
!! -----------------------------------------------------------------------------

!! Has
function ReactionOutputChannelHas(handle) &
      bind(C, name='ReactionOutputChannelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ReactionOutputChannelHas

!! Get, const
function ReactionOutputChannelGetConst(handle) &
      bind(C, name='ReactionOutputChannelGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ReactionOutputChannelGetConst

!! Get
function ReactionOutputChannelGet(handle) &
      bind(C, name='ReactionOutputChannelGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ReactionOutputChannelGet

!! Set
subroutine ReactionOutputChannelSet(handle, fieldHandle) &
      bind(C, name='ReactionOutputChannelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ReactionOutputChannelSet


!! -----------------------------------------------------------------------------
!! Child: doubleDifferentialCrossSection
!! -----------------------------------------------------------------------------

!! Has
function ReactionDoubleDifferentialCrossSectionHas(handle) &
      bind(C, name='ReactionDoubleDifferentialCrossSectionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ReactionDoubleDifferentialCrossSectionHas

!! Get, const
function ReactionDoubleDifferentialCrossSectionGetConst(handle) &
      bind(C, name='ReactionDoubleDifferentialCrossSectionGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ReactionDoubleDifferentialCrossSectionGetConst

!! Get
function ReactionDoubleDifferentialCrossSectionGet(handle) &
      bind(C, name='ReactionDoubleDifferentialCrossSectionGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ReactionDoubleDifferentialCrossSectionGet

!! Set
subroutine ReactionDoubleDifferentialCrossSectionSet(handle, fieldHandle) &
      bind(C, name='ReactionDoubleDifferentialCrossSectionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ReactionDoubleDifferentialCrossSectionSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalReaction
