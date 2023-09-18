
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalMetaStable
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function MetaStableDefaultConst() &
      bind(C, name='MetaStableDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function MetaStableDefaultConst

!! Create, default
function MetaStableDefault() &
      bind(C, name='MetaStableDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function MetaStableDefault

!! Create, general, const
function MetaStableCreateConst( &
   id, &
   pid, &
   metaStableIndex, &
   idSize, &
   pidSize &
) &
      bind(C, name='MetaStableCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_int), value, intent(in) :: metaStableIndex
   type(c_ptr) :: handle
end function MetaStableCreateConst

!! Create, general
function MetaStableCreate( &
   id, &
   pid, &
   metaStableIndex, &
   idSize, &
   pidSize &
) &
      bind(C, name='MetaStableCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_int), value, intent(in) :: metaStableIndex
   type(c_ptr) :: handle
end function MetaStableCreate

!! Assign
subroutine MetaStableAssign(handleLHS, handleRHS) &
      bind(C, name='MetaStableAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine MetaStableAssign

!! Delete
subroutine MetaStableDelete(handle) &
      bind(C, name='MetaStableDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine MetaStableDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function MetaStableRead(handle, filename, filenameSize) &
      bind(C, name='MetaStableRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function MetaStableRead

!! Write to file
function MetaStableWrite(handle, filename, filenameSize) &
      bind(C, name='MetaStableWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function MetaStableWrite

!! Print to standard output, in our prettyprinting format
function MetaStablePrint(handle) &
      bind(C, name='MetaStablePrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function MetaStablePrint

!! Print to standard output, as XML
function MetaStablePrintXML(handle) &
      bind(C, name='MetaStablePrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function MetaStablePrintXML

!! Print to standard output, as JSON
function MetaStablePrintJSON(handle) &
      bind(C, name='MetaStablePrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function MetaStablePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: id
!! -----------------------------------------------------------------------------

!! Has
function MetaStableIdHas(handle) &
      bind(C, name='MetaStableIdHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function MetaStableIdHas

!! Get
function MetaStableIdGet(handle) &
      bind(C, name='MetaStableIdGet') &
      result(id)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: id
end function MetaStableIdGet

!! Set
subroutine MetaStableIdSet(handle, id, idSize) &
      bind(C, name='MetaStableIdSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
end subroutine MetaStableIdSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function MetaStablePidHas(handle) &
      bind(C, name='MetaStablePidHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function MetaStablePidHas

!! Get
function MetaStablePidGet(handle) &
      bind(C, name='MetaStablePidGet') &
      result(pid)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: pid
end function MetaStablePidGet

!! Set
subroutine MetaStablePidSet(handle, pid, pidSize) &
      bind(C, name='MetaStablePidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine MetaStablePidSet


!! -----------------------------------------------------------------------------
!! Metadatum: metaStableIndex
!! -----------------------------------------------------------------------------

!! Has
function MetaStableMetaStableIndexHas(handle) &
      bind(C, name='MetaStableMetaStableIndexHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function MetaStableMetaStableIndexHas

!! Get
function MetaStableMetaStableIndexGet(handle) &
      bind(C, name='MetaStableMetaStableIndexGet') &
      result(metaStableIndex)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: metaStableIndex
end function MetaStableMetaStableIndexGet

!! Set
subroutine MetaStableMetaStableIndexSet(handle, metaStableIndex, metaStableIndexSize) &
      bind(C, name='MetaStableMetaStableIndexSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaStableIndexSize
   character(c_char), intent(in) :: metaStableIndex(metaStableIndexSize)
end subroutine MetaStableMetaStableIndexSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalMetaStable
