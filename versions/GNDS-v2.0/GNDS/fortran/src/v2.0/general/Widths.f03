
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalWidths
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function WidthsDefaultConst() &
      bind(C, name='WidthsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: WidthsDefaultConst
end function WidthsDefaultConst

!! Create, default, non-const
function WidthsDefault() &
      bind(C, name='WidthsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: WidthsDefault
end function WidthsDefault

!! Create, general, const
function WidthsCreateConst( &
   width, widthSize &
) &
      bind(C, name='WidthsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: widthSize
   type(c_ptr), intent(in) :: width(widthSize)
   type(c_ptr) :: WidthsCreateConst
end function WidthsCreateConst

!! Create, general, non-const
function WidthsCreate( &
   width, widthSize &
) &
      bind(C, name='WidthsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: widthSize
   type(c_ptr), intent(in) :: width(widthSize)
   type(c_ptr) :: WidthsCreate
end function WidthsCreate

!! Assign
subroutine WidthsAssign(handleLHS, handleRHS) &
      bind(C, name='WidthsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine WidthsAssign

!! Delete
subroutine WidthsDelete(handle) &
      bind(C, name='WidthsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine WidthsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function WidthsRead(handle, filename, filenameSize) &
      bind(C, name='WidthsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: WidthsRead
end function WidthsRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function WidthsWrite(handle, filename, filenameSize) &
      bind(C, name='WidthsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: WidthsWrite
end function WidthsWrite

!! Print to standard output, in our prettyprinting format
function WidthsPrint(handle) &
      bind(C, name='WidthsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: WidthsPrint
end function WidthsPrint

!! Print to standard output, as XML
function WidthsPrintXML(handle) &
      bind(C, name='WidthsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: WidthsPrintXML
end function WidthsPrintXML

!! Print to standard output, as JSON
function WidthsPrintJSON(handle) &
      bind(C, name='WidthsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: WidthsPrintJSON
end function WidthsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: width
!! -----------------------------------------------------------------------------

!! Has
function WidthsWidthHas(handle) &
      bind(C, name='WidthsWidthHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: WidthsWidthHas
end function WidthsWidthHas

!! Clear
subroutine WidthsWidthClear(handle) &
      bind(C, name='WidthsWidthClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine WidthsWidthClear

!! Size
function WidthsWidthSize(handle) &
      bind(C, name='WidthsWidthSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: WidthsWidthSize
end function WidthsWidthSize

!! Add
subroutine WidthsWidthAdd(handle, fieldHandle) &
      bind(C, name='WidthsWidthAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine WidthsWidthAdd

!! Get, by index \in [0,size), const
function WidthsWidthGetConst(handle, index) &
      bind(C, name='WidthsWidthGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: WidthsWidthGetConst
end function WidthsWidthGetConst

!! Get, by index \in [0,size), non-const
function WidthsWidthGet(handle, index) &
      bind(C, name='WidthsWidthGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: WidthsWidthGet
end function WidthsWidthGet

!! Set, by index \in [0,size)
subroutine WidthsWidthSet(handle, index, fieldHandle) &
      bind(C, name='WidthsWidthSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine WidthsWidthSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function WidthsWidthHasByLabel(handle, meta, metaSize) &
      bind(C, name='WidthsWidthHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: WidthsWidthHasByLabel
end function WidthsWidthHasByLabel

!! Get, by label, const
function WidthsWidthGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='WidthsWidthGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: WidthsWidthGetByLabelConst
end function WidthsWidthGetByLabelConst

!! Get, by label, non-const
function WidthsWidthGetByLabel(handle, meta, metaSize) &
      bind(C, name='WidthsWidthGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: WidthsWidthGetByLabel
end function WidthsWidthGetByLabel

!! Set, by label
subroutine WidthsWidthSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='WidthsWidthSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine WidthsWidthSetByLabel

!! ------------------------
!! Re: metadatum resonanceReaction
!! ------------------------

!! Has, by resonanceReaction
function WidthsWidthHasByResonanceReaction(handle, meta, metaSize) &
      bind(C, name='WidthsWidthHasByResonanceReaction')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: WidthsWidthHasByResonanceReaction
end function WidthsWidthHasByResonanceReaction

!! Get, by resonanceReaction, const
function WidthsWidthGetByResonanceReactionConst(handle, meta, metaSize) &
      bind(C, name='WidthsWidthGetByResonanceReactionConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: WidthsWidthGetByResonanceReactionConst
end function WidthsWidthGetByResonanceReactionConst

!! Get, by resonanceReaction, non-const
function WidthsWidthGetByResonanceReaction(handle, meta, metaSize) &
      bind(C, name='WidthsWidthGetByResonanceReaction')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: WidthsWidthGetByResonanceReaction
end function WidthsWidthGetByResonanceReaction

!! Set, by resonanceReaction
subroutine WidthsWidthSetByResonanceReaction(handle, meta, metaSize, fieldHandle) &
      bind(C, name='WidthsWidthSetByResonanceReaction')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine WidthsWidthSetByResonanceReaction

!! ------------------------
!! Re: metadatum degreesOfFreedom
!! ------------------------

!! Has, by degreesOfFreedom
function WidthsWidthHasByDegreesOfFreedom(handle, meta) &
      bind(C, name='WidthsWidthHasByDegreesOfFreedom')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: WidthsWidthHasByDegreesOfFreedom
end function WidthsWidthHasByDegreesOfFreedom

!! Get, by degreesOfFreedom, const
function WidthsWidthGetByDegreesOfFreedomConst(handle, meta) &
      bind(C, name='WidthsWidthGetByDegreesOfFreedomConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: WidthsWidthGetByDegreesOfFreedomConst
end function WidthsWidthGetByDegreesOfFreedomConst

!! Get, by degreesOfFreedom, non-const
function WidthsWidthGetByDegreesOfFreedom(handle, meta) &
      bind(C, name='WidthsWidthGetByDegreesOfFreedom')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: WidthsWidthGetByDegreesOfFreedom
end function WidthsWidthGetByDegreesOfFreedom

!! Set, by degreesOfFreedom
subroutine WidthsWidthSetByDegreesOfFreedom(handle, meta, fieldHandle) &
      bind(C, name='WidthsWidthSetByDegreesOfFreedom')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine WidthsWidthSetByDegreesOfFreedom


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalWidths
