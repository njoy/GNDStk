
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalFissionEnergyReleases
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function FissionEnergyReleasesDefaultConst() &
      bind(C, name='FissionEnergyReleasesDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: FissionEnergyReleasesDefaultConst
end function FissionEnergyReleasesDefaultConst

!! Create, default
function FissionEnergyReleasesDefault() &
      bind(C, name='FissionEnergyReleasesDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: FissionEnergyReleasesDefault
end function FissionEnergyReleasesDefault

!! Create, general, const
function FissionEnergyReleasesCreateConst( &
   fissionEnergyRelease, fissionEnergyReleaseSize &
) &
      bind(C, name='FissionEnergyReleasesCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: fissionEnergyReleaseSize
   type(c_ptr) :: fissionEnergyRelease(fissionEnergyReleaseSize)
   type(c_ptr) :: FissionEnergyReleasesCreateConst
end function FissionEnergyReleasesCreateConst

!! Create, general
function FissionEnergyReleasesCreate( &
   fissionEnergyRelease, fissionEnergyReleaseSize &
) &
      bind(C, name='FissionEnergyReleasesCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: fissionEnergyReleaseSize
   type(c_ptr) :: fissionEnergyRelease(fissionEnergyReleaseSize)
   type(c_ptr) :: FissionEnergyReleasesCreate
end function FissionEnergyReleasesCreate

!! Assign
subroutine FissionEnergyReleasesAssign(handleLHS, handleRHS) &
      bind(C, name='FissionEnergyReleasesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine FissionEnergyReleasesAssign

!! Delete
subroutine FissionEnergyReleasesDelete(handle) &
      bind(C, name='FissionEnergyReleasesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine FissionEnergyReleasesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function FissionEnergyReleasesRead(handle, filename, filenameSize) &
      bind(C, name='FissionEnergyReleasesRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: FissionEnergyReleasesRead
end function FissionEnergyReleasesRead

!! Write to file
function FissionEnergyReleasesWrite(handle, filename, filenameSize) &
      bind(C, name='FissionEnergyReleasesWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: FissionEnergyReleasesWrite
end function FissionEnergyReleasesWrite

!! Print to standard output, in our prettyprinting format
function FissionEnergyReleasesPrint(handle) &
      bind(C, name='FissionEnergyReleasesPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FissionEnergyReleasesPrint
end function FissionEnergyReleasesPrint

!! Print to standard output, as XML
function FissionEnergyReleasesPrintXML(handle) &
      bind(C, name='FissionEnergyReleasesPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FissionEnergyReleasesPrintXML
end function FissionEnergyReleasesPrintXML

!! Print to standard output, as JSON
function FissionEnergyReleasesPrintJSON(handle) &
      bind(C, name='FissionEnergyReleasesPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FissionEnergyReleasesPrintJSON
end function FissionEnergyReleasesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: fissionEnergyRelease
!! -----------------------------------------------------------------------------

!! Has
function FissionEnergyReleasesFissionEnergyReleaseHas(handle) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: FissionEnergyReleasesFissionEnergyReleaseHas
end function FissionEnergyReleasesFissionEnergyReleaseHas

!! Clear
subroutine FissionEnergyReleasesFissionEnergyReleaseClear(handle) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine FissionEnergyReleasesFissionEnergyReleaseClear

!! Size
function FissionEnergyReleasesFissionEnergyReleaseSize(handle) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: FissionEnergyReleasesFissionEnergyReleaseSize
end function FissionEnergyReleasesFissionEnergyReleaseSize

!! Add
subroutine FissionEnergyReleasesFissionEnergyReleaseAdd(handle, fieldHandle) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine FissionEnergyReleasesFissionEnergyReleaseAdd

!! Get, by index \in [0,size), const
function FissionEnergyReleasesFissionEnergyReleaseGetConst(handle, index) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: FissionEnergyReleasesFissionEnergyReleaseGetConst
end function FissionEnergyReleasesFissionEnergyReleaseGetConst

!! Get, by index \in [0,size)
function FissionEnergyReleasesFissionEnergyReleaseGet(handle, index) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: FissionEnergyReleasesFissionEnergyReleaseGet
end function FissionEnergyReleasesFissionEnergyReleaseGet

!! Set, by index \in [0,size)
subroutine FissionEnergyReleasesFissionEnergyReleaseSet(handle, index, fieldHandle) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine FissionEnergyReleasesFissionEnergyReleaseSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function FissionEnergyReleasesFissionEnergyReleaseHasByLabel(handle, meta, metaSize) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: FissionEnergyReleasesFissionEnergyReleaseHasByLabel
end function FissionEnergyReleasesFissionEnergyReleaseHasByLabel

!! Get, by label, const
function FissionEnergyReleasesFissionEnergyReleaseGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: FissionEnergyReleasesFissionEnergyReleaseGetByLabelConst
end function FissionEnergyReleasesFissionEnergyReleaseGetByLabelConst

!! Get, by label
function FissionEnergyReleasesFissionEnergyReleaseGetByLabel(handle, meta, metaSize) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: FissionEnergyReleasesFissionEnergyReleaseGetByLabel
end function FissionEnergyReleasesFissionEnergyReleaseGetByLabel

!! Set, by label
subroutine FissionEnergyReleasesFissionEnergyReleaseSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='FissionEnergyReleasesFissionEnergyReleaseSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine FissionEnergyReleasesFissionEnergyReleaseSetByLabel


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalFissionEnergyReleases
