
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalNuclides
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function NuclidesDefaultConst() &
      bind(C, name='NuclidesDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function NuclidesDefaultConst

!! Create, default
function NuclidesDefault() &
      bind(C, name='NuclidesDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function NuclidesDefault

!! Create, general, const
function NuclidesCreateConst( &
   nuclide, nuclideSize &
) &
      bind(C, name='NuclidesCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: nuclideSize
   type(c_ptr) :: nuclide(nuclideSize)
   type(c_ptr) :: handle
end function NuclidesCreateConst

!! Create, general
function NuclidesCreate( &
   nuclide, nuclideSize &
) &
      bind(C, name='NuclidesCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: nuclideSize
   type(c_ptr) :: nuclide(nuclideSize)
   type(c_ptr) :: handle
end function NuclidesCreate

!! Assign
subroutine NuclidesAssign(handleLHS, handleRHS) &
      bind(C, name='NuclidesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine NuclidesAssign

!! Delete
subroutine NuclidesDelete(handle) &
      bind(C, name='NuclidesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine NuclidesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function NuclidesRead(handle, filename, filenameSize) &
      bind(C, name='NuclidesRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function NuclidesRead

!! Write to file
function NuclidesWrite(handle, filename, filenameSize) &
      bind(C, name='NuclidesWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function NuclidesWrite

!! Print to standard output, in our prettyprinting format
function NuclidesPrint(handle) &
      bind(C, name='NuclidesPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NuclidesPrint

!! Print to standard output, as XML
function NuclidesPrintXML(handle) &
      bind(C, name='NuclidesPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NuclidesPrintXML

!! Print to standard output, as JSON
function NuclidesPrintJSON(handle) &
      bind(C, name='NuclidesPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NuclidesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: nuclide
!! -----------------------------------------------------------------------------

!! Has
function NuclidesNuclideHas(handle) &
      bind(C, name='NuclidesNuclideHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function NuclidesNuclideHas

!! Clear
subroutine NuclidesNuclideClear(handle) &
      bind(C, name='NuclidesNuclideClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine NuclidesNuclideClear

!! Size
function NuclidesNuclideSize(handle) &
      bind(C, name='NuclidesNuclideSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function NuclidesNuclideSize

!! Add
subroutine NuclidesNuclideAdd(handle, fieldHandle) &
      bind(C, name='NuclidesNuclideAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine NuclidesNuclideAdd

!! Get, by index \in [0,size), const
function NuclidesNuclideGetConst(handle, index) &
      bind(C, name='NuclidesNuclideGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function NuclidesNuclideGetConst

!! Get, by index \in [0,size)
function NuclidesNuclideGet(handle, index) &
      bind(C, name='NuclidesNuclideGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function NuclidesNuclideGet

!! Set, by index \in [0,size)
subroutine NuclidesNuclideSet(handle, index, fieldHandle) &
      bind(C, name='NuclidesNuclideSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine NuclidesNuclideSet

!! ------------------------
!! Re: metadatum id
!! ------------------------

!! Has, by id
function NuclidesNuclideHasById(handle, meta, metaSize) &
      bind(C, name='NuclidesNuclideHasById') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function NuclidesNuclideHasById

!! Get, by id, const
function NuclidesNuclideGetByIdConst(handle, meta, metaSize) &
      bind(C, name='NuclidesNuclideGetByIdConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function NuclidesNuclideGetByIdConst

!! Get, by id
function NuclidesNuclideGetById(handle, meta, metaSize) &
      bind(C, name='NuclidesNuclideGetById') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function NuclidesNuclideGetById

!! Set, by id
subroutine NuclidesNuclideSetById(handle, meta, metaSize, fieldHandle) &
      bind(C, name='NuclidesNuclideSetById')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine NuclidesNuclideSetById


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalNuclides
