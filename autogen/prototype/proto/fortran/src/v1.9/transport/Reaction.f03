
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module transportReaction
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ReactionDefaultConst() &
      bind(C, name='ReactionDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ReactionDefaultConst
end function ReactionDefaultConst

!! Create, default
function ReactionDefault() &
      bind(C, name='ReactionDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ReactionDefault
end function ReactionDefault

!! Create, general, const
function ReactionCreateConst( &
   ENDF_MT, &
   fissionGenre, &
   label, &
   crossSection, &
   fissionGenreSize, &
   labelSize &
) &
      bind(C, name='ReactionCreateConst')
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: ENDF_MT
   integer(c_size_t), intent(in), value :: fissionGenreSize
   character(c_char), intent(in) :: fissionGenre(fissionGenreSize)
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr), value :: crossSection
   type(c_ptr) :: ReactionCreateConst
end function ReactionCreateConst

!! Create, general
function ReactionCreate( &
   ENDF_MT, &
   fissionGenre, &
   label, &
   crossSection, &
   fissionGenreSize, &
   labelSize &
) &
      bind(C, name='ReactionCreate')
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: ENDF_MT
   integer(c_size_t), intent(in), value :: fissionGenreSize
   character(c_char), intent(in) :: fissionGenre(fissionGenreSize)
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr), value :: crossSection
   type(c_ptr) :: ReactionCreate
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
      bind(C, name='ReactionRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ReactionRead
end function ReactionRead

!! Write to file
function ReactionWrite(handle, filename, filenameSize) &
      bind(C, name='ReactionWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ReactionWrite
end function ReactionWrite

!! Print to standard output, in our prettyprinting format
function ReactionPrint(handle) &
      bind(C, name='ReactionPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionPrint
end function ReactionPrint

!! Print to standard output, as XML
function ReactionPrintXML(handle) &
      bind(C, name='ReactionPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionPrintXML
end function ReactionPrintXML

!! Print to standard output, as JSON
function ReactionPrintJSON(handle) &
      bind(C, name='ReactionPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionPrintJSON
end function ReactionPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: ENDF_MT
!! -----------------------------------------------------------------------------

!! Has
function ReactionENDFMTHas(handle) &
      bind(C, name='ReactionENDFMTHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionENDFMTHas
end function ReactionENDFMTHas

!! Get
function ReactionENDFMTGet(handle) &
      bind(C, name='ReactionENDFMTGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionENDFMTGet
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
      bind(C, name='ReactionFissionGenreHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionFissionGenreHas
end function ReactionFissionGenreHas

!! Get
function ReactionFissionGenreGet(handle) &
      bind(C, name='ReactionFissionGenreGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ReactionFissionGenreGet
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
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ReactionLabelHas(handle) &
      bind(C, name='ReactionLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionLabelHas
end function ReactionLabelHas

!! Get
function ReactionLabelGet(handle) &
      bind(C, name='ReactionLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ReactionLabelGet
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
!! Child: crossSection
!! -----------------------------------------------------------------------------

!! Has
function ReactionCrossSectionHas(handle) &
      bind(C, name='ReactionCrossSectionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReactionCrossSectionHas
end function ReactionCrossSectionHas

!! Get, const
function ReactionCrossSectionGetConst(handle) &
      bind(C, name='ReactionCrossSectionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ReactionCrossSectionGetConst
end function ReactionCrossSectionGetConst

!! Get
function ReactionCrossSectionGet(handle) &
      bind(C, name='ReactionCrossSectionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ReactionCrossSectionGet
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
!! -----------------------------------------------------------------------------

end interface
end module transportReaction
