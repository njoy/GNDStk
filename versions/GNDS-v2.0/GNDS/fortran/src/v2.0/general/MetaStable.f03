
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
      bind(C, name='MetaStableDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: MetaStableDefaultConst
end function MetaStableDefaultConst

!! Create, default
function MetaStableDefault() &
      bind(C, name='MetaStableDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: MetaStableDefault
end function MetaStableDefault

!! Create, general, const
function MetaStableCreateConst( &
   id, &
   pid, &
   metaStableIndex, &
   idSize, &
   pidSize &
) &
      bind(C, name='MetaStableCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_int), intent(in), value :: metaStableIndex
   type(c_ptr) :: MetaStableCreateConst
end function MetaStableCreateConst

!! Create, general
function MetaStableCreate( &
   id, &
   pid, &
   metaStableIndex, &
   idSize, &
   pidSize &
) &
      bind(C, name='MetaStableCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_int), intent(in), value :: metaStableIndex
   type(c_ptr) :: MetaStableCreate
end function MetaStableCreate

!! Assign
subroutine MetaStableAssign(handleLHS, handleRHS) &
      bind(C, name='MetaStableAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
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
      bind(C, name='MetaStableRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: MetaStableRead
end function MetaStableRead

!! Write to file
function MetaStableWrite(handle, filename, filenameSize) &
      bind(C, name='MetaStableWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: MetaStableWrite
end function MetaStableWrite

!! Print to standard output, in our prettyprinting format
function MetaStablePrint(handle) &
      bind(C, name='MetaStablePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MetaStablePrint
end function MetaStablePrint

!! Print to standard output, as XML
function MetaStablePrintXML(handle) &
      bind(C, name='MetaStablePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MetaStablePrintXML
end function MetaStablePrintXML

!! Print to standard output, as JSON
function MetaStablePrintJSON(handle) &
      bind(C, name='MetaStablePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MetaStablePrintJSON
end function MetaStablePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: id
!! -----------------------------------------------------------------------------

!! Has
function MetaStableIdHas(handle) &
      bind(C, name='MetaStableIdHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MetaStableIdHas
end function MetaStableIdHas

!! Get
function MetaStableIdGet(handle) &
      bind(C, name='MetaStableIdGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: MetaStableIdGet
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
      bind(C, name='MetaStablePidHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MetaStablePidHas
end function MetaStablePidHas

!! Get
function MetaStablePidGet(handle) &
      bind(C, name='MetaStablePidGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: MetaStablePidGet
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
      bind(C, name='MetaStableMetaStableIndexHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MetaStableMetaStableIndexHas
end function MetaStableMetaStableIndexHas

!! Get
function MetaStableMetaStableIndexGet(handle) &
      bind(C, name='MetaStableMetaStableIndexGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MetaStableMetaStableIndexGet
end function MetaStableMetaStableIndexGet

!! Set
subroutine MetaStableMetaStableIndexSet(handle, metaStableIndex) &
      bind(C, name='MetaStableMetaStableIndexSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: metaStableIndex
end subroutine MetaStableMetaStableIndexSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalMetaStable
