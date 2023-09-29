
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalChannels
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ChannelsDefaultConst() &
      bind(C, name='ChannelsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ChannelsDefaultConst
end function ChannelsDefaultConst

!! Create, default
function ChannelsDefault() &
      bind(C, name='ChannelsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ChannelsDefault
end function ChannelsDefault

!! Create, general, const
function ChannelsCreateConst( &
   channel, channelSize &
) &
      bind(C, name='ChannelsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: channelSize
   type(c_ptr), intent(in) :: channel(channelSize)
   type(c_ptr) :: ChannelsCreateConst
end function ChannelsCreateConst

!! Create, general
function ChannelsCreate( &
   channel, channelSize &
) &
      bind(C, name='ChannelsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: channelSize
   type(c_ptr), intent(in) :: channel(channelSize)
   type(c_ptr) :: ChannelsCreate
end function ChannelsCreate

!! Assign
subroutine ChannelsAssign(handleLHS, handleRHS) &
      bind(C, name='ChannelsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ChannelsAssign

!! Delete
subroutine ChannelsDelete(handle) &
      bind(C, name='ChannelsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ChannelsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ChannelsRead(handle, filename, filenameSize) &
      bind(C, name='ChannelsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ChannelsRead
end function ChannelsRead

!! Write to file
function ChannelsWrite(handle, filename, filenameSize) &
      bind(C, name='ChannelsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ChannelsWrite
end function ChannelsWrite

!! Print to standard output, in our prettyprinting format
function ChannelsPrint(handle) &
      bind(C, name='ChannelsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChannelsPrint
end function ChannelsPrint

!! Print to standard output, as XML
function ChannelsPrintXML(handle) &
      bind(C, name='ChannelsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChannelsPrintXML
end function ChannelsPrintXML

!! Print to standard output, as JSON
function ChannelsPrintJSON(handle) &
      bind(C, name='ChannelsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChannelsPrintJSON
end function ChannelsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: channel
!! -----------------------------------------------------------------------------

!! Has
function ChannelsChannelHas(handle) &
      bind(C, name='ChannelsChannelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChannelsChannelHas
end function ChannelsChannelHas

!! Clear
subroutine ChannelsChannelClear(handle) &
      bind(C, name='ChannelsChannelClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ChannelsChannelClear

!! Size
function ChannelsChannelSize(handle) &
      bind(C, name='ChannelsChannelSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ChannelsChannelSize
end function ChannelsChannelSize

!! Add
subroutine ChannelsChannelAdd(handle, fieldHandle) &
      bind(C, name='ChannelsChannelAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ChannelsChannelAdd

!! Get, by index \in [0,size), const
function ChannelsChannelGetConst(handle, index) &
      bind(C, name='ChannelsChannelGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ChannelsChannelGetConst
end function ChannelsChannelGetConst

!! Get, by index \in [0,size)
function ChannelsChannelGet(handle, index) &
      bind(C, name='ChannelsChannelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ChannelsChannelGet
end function ChannelsChannelGet

!! Set, by index \in [0,size)
subroutine ChannelsChannelSet(handle, index, fieldHandle) &
      bind(C, name='ChannelsChannelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ChannelsChannelSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ChannelsChannelHasByLabel(handle, meta, metaSize) &
      bind(C, name='ChannelsChannelHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ChannelsChannelHasByLabel
end function ChannelsChannelHasByLabel

!! Get, by label, const
function ChannelsChannelGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ChannelsChannelGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ChannelsChannelGetByLabelConst
end function ChannelsChannelGetByLabelConst

!! Get, by label
function ChannelsChannelGetByLabel(handle, meta, metaSize) &
      bind(C, name='ChannelsChannelGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ChannelsChannelGetByLabel
end function ChannelsChannelGetByLabel

!! Set, by label
subroutine ChannelsChannelSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ChannelsChannelSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ChannelsChannelSetByLabel

!! ------------------------
!! Re: metadatum resonanceReaction
!! ------------------------

!! Has, by resonanceReaction
function ChannelsChannelHasByResonanceReaction(handle, meta, metaSize) &
      bind(C, name='ChannelsChannelHasByResonanceReaction')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ChannelsChannelHasByResonanceReaction
end function ChannelsChannelHasByResonanceReaction

!! Get, by resonanceReaction, const
function ChannelsChannelGetByResonanceReactionConst(handle, meta, metaSize) &
      bind(C, name='ChannelsChannelGetByResonanceReactionConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ChannelsChannelGetByResonanceReactionConst
end function ChannelsChannelGetByResonanceReactionConst

!! Get, by resonanceReaction
function ChannelsChannelGetByResonanceReaction(handle, meta, metaSize) &
      bind(C, name='ChannelsChannelGetByResonanceReaction')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ChannelsChannelGetByResonanceReaction
end function ChannelsChannelGetByResonanceReaction

!! Set, by resonanceReaction
subroutine ChannelsChannelSetByResonanceReaction(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ChannelsChannelSetByResonanceReaction')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ChannelsChannelSetByResonanceReaction

!! ------------------------
!! Re: metadatum L
!! ------------------------

!! Has, by L
function ChannelsChannelHasByL(handle, meta) &
      bind(C, name='ChannelsChannelHasByL')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: ChannelsChannelHasByL
end function ChannelsChannelHasByL

!! Get, by L, const
function ChannelsChannelGetByLConst(handle, meta) &
      bind(C, name='ChannelsChannelGetByLConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ChannelsChannelGetByLConst
end function ChannelsChannelGetByLConst

!! Get, by L
function ChannelsChannelGetByL(handle, meta) &
      bind(C, name='ChannelsChannelGetByL')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ChannelsChannelGetByL
end function ChannelsChannelGetByL

!! Set, by L
subroutine ChannelsChannelSetByL(handle, meta, fieldHandle) &
      bind(C, name='ChannelsChannelSetByL')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ChannelsChannelSetByL

!! ------------------------
!! Re: metadatum channelSpin
!! ------------------------

!! Has, by channelSpin
function ChannelsChannelHasByChannelSpin(handle, meta) &
      bind(C, name='ChannelsChannelHasByChannelSpin')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: ChannelsChannelHasByChannelSpin
end function ChannelsChannelHasByChannelSpin

!! Get, by channelSpin, const
function ChannelsChannelGetByChannelSpinConst(handle, meta) &
      bind(C, name='ChannelsChannelGetByChannelSpinConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ChannelsChannelGetByChannelSpinConst
end function ChannelsChannelGetByChannelSpinConst

!! Get, by channelSpin
function ChannelsChannelGetByChannelSpin(handle, meta) &
      bind(C, name='ChannelsChannelGetByChannelSpin')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ChannelsChannelGetByChannelSpin
end function ChannelsChannelGetByChannelSpin

!! Set, by channelSpin
subroutine ChannelsChannelSetByChannelSpin(handle, meta, fieldHandle) &
      bind(C, name='ChannelsChannelSetByChannelSpin')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ChannelsChannelSetByChannelSpin

!! ------------------------
!! Re: metadatum columnIndex
!! ------------------------

!! Has, by columnIndex
function ChannelsChannelHasByColumnIndex(handle, meta) &
      bind(C, name='ChannelsChannelHasByColumnIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: ChannelsChannelHasByColumnIndex
end function ChannelsChannelHasByColumnIndex

!! Get, by columnIndex, const
function ChannelsChannelGetByColumnIndexConst(handle, meta) &
      bind(C, name='ChannelsChannelGetByColumnIndexConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ChannelsChannelGetByColumnIndexConst
end function ChannelsChannelGetByColumnIndexConst

!! Get, by columnIndex
function ChannelsChannelGetByColumnIndex(handle, meta) &
      bind(C, name='ChannelsChannelGetByColumnIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ChannelsChannelGetByColumnIndex
end function ChannelsChannelGetByColumnIndex

!! Set, by columnIndex
subroutine ChannelsChannelSetByColumnIndex(handle, meta, fieldHandle) &
      bind(C, name='ChannelsChannelSetByColumnIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ChannelsChannelSetByColumnIndex


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalChannels
