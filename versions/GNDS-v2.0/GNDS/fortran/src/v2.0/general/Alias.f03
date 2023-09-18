
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalAlias
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AliasDefaultConst() &
      bind(C, name='AliasDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function AliasDefaultConst

!! Create, default
function AliasDefault() &
      bind(C, name='AliasDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function AliasDefault

!! Create, general, const
function AliasCreateConst( &
   id, &
   pid, &
   idSize, &
   pidSize &
) &
      bind(C, name='AliasCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   type(c_ptr) :: handle
end function AliasCreateConst

!! Create, general
function AliasCreate( &
   id, &
   pid, &
   idSize, &
   pidSize &
) &
      bind(C, name='AliasCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   type(c_ptr) :: handle
end function AliasCreate

!! Assign
subroutine AliasAssign(handleLHS, handleRHS) &
      bind(C, name='AliasAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine AliasAssign

!! Delete
subroutine AliasDelete(handle) &
      bind(C, name='AliasDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AliasDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function AliasRead(handle, filename, filenameSize) &
      bind(C, name='AliasRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function AliasRead

!! Write to file
function AliasWrite(handle, filename, filenameSize) &
      bind(C, name='AliasWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function AliasWrite

!! Print to standard output, in our prettyprinting format
function AliasPrint(handle) &
      bind(C, name='AliasPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function AliasPrint

!! Print to standard output, as XML
function AliasPrintXML(handle) &
      bind(C, name='AliasPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function AliasPrintXML

!! Print to standard output, as JSON
function AliasPrintJSON(handle) &
      bind(C, name='AliasPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function AliasPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: id
!! -----------------------------------------------------------------------------

!! Has
function AliasIdHas(handle) &
      bind(C, name='AliasIdHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function AliasIdHas

!! Get
function AliasIdGet(handle) &
      bind(C, name='AliasIdGet') &
      result(id)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: id
end function AliasIdGet

!! Set
subroutine AliasIdSet(handle, id, idSize) &
      bind(C, name='AliasIdSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
end subroutine AliasIdSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function AliasPidHas(handle) &
      bind(C, name='AliasPidHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function AliasPidHas

!! Get
function AliasPidGet(handle) &
      bind(C, name='AliasPidGet') &
      result(pid)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: pid
end function AliasPidGet

!! Set
subroutine AliasPidSet(handle, pid, pidSize) &
      bind(C, name='AliasPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine AliasPidSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalAlias
