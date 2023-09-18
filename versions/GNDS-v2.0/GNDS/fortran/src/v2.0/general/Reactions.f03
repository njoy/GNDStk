
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalReactions
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ReactionsDefaultConst() &
      bind(C, name='ReactionsDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ReactionsDefaultConst

!! Create, default
function ReactionsDefault() &
      bind(C, name='ReactionsDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ReactionsDefault

!! Create, general, const
function ReactionsCreateConst( &
   reaction, reactionSize &
) &
      bind(C, name='ReactionsCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: reactionSize
   type(c_ptr) :: reaction(reactionSize)
   type(c_ptr) :: handle
end function ReactionsCreateConst

!! Create, general
function ReactionsCreate( &
   reaction, reactionSize &
) &
      bind(C, name='ReactionsCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: reactionSize
   type(c_ptr) :: reaction(reactionSize)
   type(c_ptr) :: handle
end function ReactionsCreate

!! Assign
subroutine ReactionsAssign(handleLHS, handleRHS) &
      bind(C, name='ReactionsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ReactionsAssign

!! Delete
subroutine ReactionsDelete(handle) &
      bind(C, name='ReactionsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ReactionsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ReactionsRead(handle, filename, filenameSize) &
      bind(C, name='ReactionsRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ReactionsRead

!! Write to file
function ReactionsWrite(handle, filename, filenameSize) &
      bind(C, name='ReactionsWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ReactionsWrite

!! Print to standard output, in our prettyprinting format
function ReactionsPrint(handle) &
      bind(C, name='ReactionsPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ReactionsPrint

!! Print to standard output, as XML
function ReactionsPrintXML(handle) &
      bind(C, name='ReactionsPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ReactionsPrintXML

!! Print to standard output, as JSON
function ReactionsPrintJSON(handle) &
      bind(C, name='ReactionsPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ReactionsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: reaction
!! -----------------------------------------------------------------------------

!! Has
function ReactionsReactionHas(handle) &
      bind(C, name='ReactionsReactionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ReactionsReactionHas

!! Clear
subroutine ReactionsReactionClear(handle) &
      bind(C, name='ReactionsReactionClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ReactionsReactionClear

!! Size
function ReactionsReactionSize(handle) &
      bind(C, name='ReactionsReactionSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function ReactionsReactionSize

!! Add
subroutine ReactionsReactionAdd(handle, fieldHandle) &
      bind(C, name='ReactionsReactionAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ReactionsReactionAdd

!! Get, by index \in [0,size), const
function ReactionsReactionGetConst(handle, index) &
      bind(C, name='ReactionsReactionGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ReactionsReactionGetConst

!! Get, by index \in [0,size)
function ReactionsReactionGet(handle, index) &
      bind(C, name='ReactionsReactionGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ReactionsReactionGet

!! Set, by index \in [0,size)
subroutine ReactionsReactionSet(handle, index, fieldHandle) &
      bind(C, name='ReactionsReactionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ReactionsReactionSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ReactionsReactionHasByLabel(handle, meta, metaSize) &
      bind(C, name='ReactionsReactionHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ReactionsReactionHasByLabel

!! Get, by label, const
function ReactionsReactionGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ReactionsReactionGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ReactionsReactionGetByLabelConst

!! Get, by label
function ReactionsReactionGetByLabel(handle, meta, metaSize) &
      bind(C, name='ReactionsReactionGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ReactionsReactionGetByLabel

!! Set, by label
subroutine ReactionsReactionSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ReactionsReactionSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ReactionsReactionSetByLabel

!! ------------------------
!! Re: metadatum ENDF_MT
!! ------------------------

!! Has, by ENDF_MT
function ReactionsReactionHasByENDFMT(handle, meta) &
      bind(C, name='ReactionsReactionHasByENDFMT') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   integer(c_int) :: has
end function ReactionsReactionHasByENDFMT

!! Get, by ENDF_MT, const
function ReactionsReactionGetByENDFMTConst(handle, meta) &
      bind(C, name='ReactionsReactionGetByENDFMTConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function ReactionsReactionGetByENDFMTConst

!! Get, by ENDF_MT
function ReactionsReactionGetByENDFMT(handle, meta) &
      bind(C, name='ReactionsReactionGetByENDFMT') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function ReactionsReactionGetByENDFMT

!! Set, by ENDF_MT
subroutine ReactionsReactionSetByENDFMT(handle, meta, fieldHandle) &
      bind(C, name='ReactionsReactionSetByENDFMT')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), value, intent(in) :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ReactionsReactionSetByENDFMT

!! ------------------------
!! Re: metadatum fissionGenre
!! ------------------------

!! Has, by fissionGenre
function ReactionsReactionHasByFissionGenre(handle, meta, metaSize) &
      bind(C, name='ReactionsReactionHasByFissionGenre') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ReactionsReactionHasByFissionGenre

!! Get, by fissionGenre, const
function ReactionsReactionGetByFissionGenreConst(handle, meta, metaSize) &
      bind(C, name='ReactionsReactionGetByFissionGenreConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ReactionsReactionGetByFissionGenreConst

!! Get, by fissionGenre
function ReactionsReactionGetByFissionGenre(handle, meta, metaSize) &
      bind(C, name='ReactionsReactionGetByFissionGenre') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ReactionsReactionGetByFissionGenre

!! Set, by fissionGenre
subroutine ReactionsReactionSetByFissionGenre(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ReactionsReactionSetByFissionGenre')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ReactionsReactionSetByFissionGenre


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalReactions
