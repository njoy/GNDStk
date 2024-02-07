
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalResonanceReactions
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ResonanceReactionsDefaultConst() &
      bind(C, name='ResonanceReactionsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ResonanceReactionsDefaultConst
end function ResonanceReactionsDefaultConst

!! Create, default, non-const
function ResonanceReactionsDefault() &
      bind(C, name='ResonanceReactionsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ResonanceReactionsDefault
end function ResonanceReactionsDefault

!! Create, general, const
function ResonanceReactionsCreateConst( &
   resonanceReaction, resonanceReactionSize &
) &
      bind(C, name='ResonanceReactionsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: resonanceReactionSize
   type(c_ptr), intent(in) :: resonanceReaction(resonanceReactionSize)
   type(c_ptr) :: ResonanceReactionsCreateConst
end function ResonanceReactionsCreateConst

!! Create, general, non-const
function ResonanceReactionsCreate( &
   resonanceReaction, resonanceReactionSize &
) &
      bind(C, name='ResonanceReactionsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: resonanceReactionSize
   type(c_ptr), intent(in) :: resonanceReaction(resonanceReactionSize)
   type(c_ptr) :: ResonanceReactionsCreate
end function ResonanceReactionsCreate

!! Assign
subroutine ResonanceReactionsAssign(handleLHS, handleRHS) &
      bind(C, name='ResonanceReactionsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ResonanceReactionsAssign

!! Delete
subroutine ResonanceReactionsDelete(handle) &
      bind(C, name='ResonanceReactionsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ResonanceReactionsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ResonanceReactionsRead(handle, filename, filenameSize) &
      bind(C, name='ResonanceReactionsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ResonanceReactionsRead
end function ResonanceReactionsRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ResonanceReactionsWrite(handle, filename, filenameSize) &
      bind(C, name='ResonanceReactionsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ResonanceReactionsWrite
end function ResonanceReactionsWrite

!! Print to standard output, in our prettyprinting format
function ResonanceReactionsPrint(handle) &
      bind(C, name='ResonanceReactionsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceReactionsPrint
end function ResonanceReactionsPrint

!! Print to standard output, as XML
function ResonanceReactionsPrintXML(handle) &
      bind(C, name='ResonanceReactionsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceReactionsPrintXML
end function ResonanceReactionsPrintXML

!! Print to standard output, as JSON
function ResonanceReactionsPrintJSON(handle) &
      bind(C, name='ResonanceReactionsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceReactionsPrintJSON
end function ResonanceReactionsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: resonanceReaction
!! -----------------------------------------------------------------------------

!! Has
function ResonanceReactionsResonanceReactionHas(handle) &
      bind(C, name='ResonanceReactionsResonanceReactionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceReactionsResonanceReactionHas
end function ResonanceReactionsResonanceReactionHas

!! Clear
subroutine ResonanceReactionsResonanceReactionClear(handle) &
      bind(C, name='ResonanceReactionsResonanceReactionClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ResonanceReactionsResonanceReactionClear

!! Size
function ResonanceReactionsResonanceReactionSize(handle) &
      bind(C, name='ResonanceReactionsResonanceReactionSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ResonanceReactionsResonanceReactionSize
end function ResonanceReactionsResonanceReactionSize

!! Add
subroutine ResonanceReactionsResonanceReactionAdd(handle, fieldHandle) &
      bind(C, name='ResonanceReactionsResonanceReactionAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResonanceReactionsResonanceReactionAdd

!! Get, by index \in [0,size), const
function ResonanceReactionsResonanceReactionGetConst(handle, index) &
      bind(C, name='ResonanceReactionsResonanceReactionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ResonanceReactionsResonanceReactionGetConst
end function ResonanceReactionsResonanceReactionGetConst

!! Get, by index \in [0,size), non-const
function ResonanceReactionsResonanceReactionGet(handle, index) &
      bind(C, name='ResonanceReactionsResonanceReactionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ResonanceReactionsResonanceReactionGet
end function ResonanceReactionsResonanceReactionGet

!! Set, by index \in [0,size)
subroutine ResonanceReactionsResonanceReactionSet(handle, index, fieldHandle) &
      bind(C, name='ResonanceReactionsResonanceReactionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResonanceReactionsResonanceReactionSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ResonanceReactionsResonanceReactionHasByLabel(handle, meta, metaSize) &
      bind(C, name='ResonanceReactionsResonanceReactionHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ResonanceReactionsResonanceReactionHasByLabel
end function ResonanceReactionsResonanceReactionHasByLabel

!! Get, by label, const
function ResonanceReactionsResonanceReactionGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ResonanceReactionsResonanceReactionGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ResonanceReactionsResonanceReactionGetByLabelConst
end function ResonanceReactionsResonanceReactionGetByLabelConst

!! Get, by label, non-const
function ResonanceReactionsResonanceReactionGetByLabel(handle, meta, metaSize) &
      bind(C, name='ResonanceReactionsResonanceReactionGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ResonanceReactionsResonanceReactionGetByLabel
end function ResonanceReactionsResonanceReactionGetByLabel

!! Set, by label
subroutine ResonanceReactionsResonanceReactionSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ResonanceReactionsResonanceReactionSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResonanceReactionsResonanceReactionSetByLabel

!! ------------------------
!! Re: metadatum ejectile
!! ------------------------

!! Has, by ejectile
function ResonanceReactionsResonanceReactionHasByEjectile(handle, meta, metaSize) &
      bind(C, name='ResonanceReactionsResonanceReactionHasByEjectile')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ResonanceReactionsResonanceReactionHasByEjectile
end function ResonanceReactionsResonanceReactionHasByEjectile

!! Get, by ejectile, const
function ResonanceReactionsResonanceReactionGetByEjectileConst(handle, meta, metaSize) &
      bind(C, name='ResonanceReactionsResonanceReactionGetByEjectileConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ResonanceReactionsResonanceReactionGetByEjectileConst
end function ResonanceReactionsResonanceReactionGetByEjectileConst

!! Get, by ejectile, non-const
function ResonanceReactionsResonanceReactionGetByEjectile(handle, meta, metaSize) &
      bind(C, name='ResonanceReactionsResonanceReactionGetByEjectile')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ResonanceReactionsResonanceReactionGetByEjectile
end function ResonanceReactionsResonanceReactionGetByEjectile

!! Set, by ejectile
subroutine ResonanceReactionsResonanceReactionSetByEjectile(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ResonanceReactionsResonanceReactionSetByEjectile')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResonanceReactionsResonanceReactionSetByEjectile

!! ------------------------
!! Re: metadatum eliminated
!! ------------------------

!! Has, by eliminated
function ResonanceReactionsResonanceReactionHasByEliminated(handle, meta) &
      bind(C, name='ResonanceReactionsResonanceReactionHasByEliminated')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   logical(c_bool), intent(in), value :: meta
   integer(c_int) :: ResonanceReactionsResonanceReactionHasByEliminated
end function ResonanceReactionsResonanceReactionHasByEliminated

!! Get, by eliminated, const
function ResonanceReactionsResonanceReactionGetByEliminatedConst(handle, meta) &
      bind(C, name='ResonanceReactionsResonanceReactionGetByEliminatedConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   logical(c_bool), intent(in), value :: meta
   type(c_ptr) :: ResonanceReactionsResonanceReactionGetByEliminatedConst
end function ResonanceReactionsResonanceReactionGetByEliminatedConst

!! Get, by eliminated, non-const
function ResonanceReactionsResonanceReactionGetByEliminated(handle, meta) &
      bind(C, name='ResonanceReactionsResonanceReactionGetByEliminated')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   logical(c_bool), intent(in), value :: meta
   type(c_ptr) :: ResonanceReactionsResonanceReactionGetByEliminated
end function ResonanceReactionsResonanceReactionGetByEliminated

!! Set, by eliminated
subroutine ResonanceReactionsResonanceReactionSetByEliminated(handle, meta, fieldHandle) &
      bind(C, name='ResonanceReactionsResonanceReactionSetByEliminated')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   logical(c_bool), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResonanceReactionsResonanceReactionSetByEliminated


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalResonanceReactions
