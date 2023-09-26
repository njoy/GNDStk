
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSummands
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SummandsDefaultConst() &
      bind(C, name='SummandsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SummandsDefaultConst
end function SummandsDefaultConst

!! Create, default
function SummandsDefault() &
      bind(C, name='SummandsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SummandsDefault
end function SummandsDefault

!! Create, general, const
function SummandsCreateConst( &
   add, addSize &
) &
      bind(C, name='SummandsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: addSize
   type(c_ptr) :: add(addSize)
   type(c_ptr) :: SummandsCreateConst
end function SummandsCreateConst

!! Create, general
function SummandsCreate( &
   add, addSize &
) &
      bind(C, name='SummandsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: addSize
   type(c_ptr) :: add(addSize)
   type(c_ptr) :: SummandsCreate
end function SummandsCreate

!! Assign
subroutine SummandsAssign(handleLHS, handleRHS) &
      bind(C, name='SummandsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine SummandsAssign

!! Delete
subroutine SummandsDelete(handle) &
      bind(C, name='SummandsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SummandsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SummandsRead(handle, filename, filenameSize) &
      bind(C, name='SummandsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SummandsRead
end function SummandsRead

!! Write to file
function SummandsWrite(handle, filename, filenameSize) &
      bind(C, name='SummandsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SummandsWrite
end function SummandsWrite

!! Print to standard output, in our prettyprinting format
function SummandsPrint(handle) &
      bind(C, name='SummandsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SummandsPrint
end function SummandsPrint

!! Print to standard output, as XML
function SummandsPrintXML(handle) &
      bind(C, name='SummandsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SummandsPrintXML
end function SummandsPrintXML

!! Print to standard output, as JSON
function SummandsPrintJSON(handle) &
      bind(C, name='SummandsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SummandsPrintJSON
end function SummandsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: add
!! -----------------------------------------------------------------------------

!! Has
function SummandsAddHas(handle) &
      bind(C, name='SummandsAddHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SummandsAddHas
end function SummandsAddHas

!! Clear
subroutine SummandsAddClear(handle) &
      bind(C, name='SummandsAddClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SummandsAddClear

!! Size
function SummandsAddSize(handle) &
      bind(C, name='SummandsAddSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: SummandsAddSize
end function SummandsAddSize

!! Add
subroutine SummandsAddAdd(handle, fieldHandle) &
      bind(C, name='SummandsAddAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SummandsAddAdd

!! Get, by index \in [0,size), const
function SummandsAddGetConst(handle, index) &
      bind(C, name='SummandsAddGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: SummandsAddGetConst
end function SummandsAddGetConst

!! Get, by index \in [0,size)
function SummandsAddGet(handle, index) &
      bind(C, name='SummandsAddGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: SummandsAddGet
end function SummandsAddGet

!! Set, by index \in [0,size)
subroutine SummandsAddSet(handle, index, fieldHandle) &
      bind(C, name='SummandsAddSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SummandsAddSet

!! ------------------------
!! Re: metadatum href
!! ------------------------

!! Has, by href
function SummandsAddHasByHref(handle, meta, metaSize) &
      bind(C, name='SummandsAddHasByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: SummandsAddHasByHref
end function SummandsAddHasByHref

!! Get, by href, const
function SummandsAddGetByHrefConst(handle, meta, metaSize) &
      bind(C, name='SummandsAddGetByHrefConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SummandsAddGetByHrefConst
end function SummandsAddGetByHrefConst

!! Get, by href
function SummandsAddGetByHref(handle, meta, metaSize) &
      bind(C, name='SummandsAddGetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SummandsAddGetByHref
end function SummandsAddGetByHref

!! Set, by href
subroutine SummandsAddSetByHref(handle, meta, metaSize, fieldHandle) &
      bind(C, name='SummandsAddSetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SummandsAddSetByHref


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSummands
