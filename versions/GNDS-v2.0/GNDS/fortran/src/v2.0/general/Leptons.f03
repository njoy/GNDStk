
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalLeptons
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function LeptonsDefaultConst() &
      bind(C, name='LeptonsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LeptonsDefaultConst
end function LeptonsDefaultConst

!! Create, default
function LeptonsDefault() &
      bind(C, name='LeptonsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LeptonsDefault
end function LeptonsDefault

!! Create, general, const
function LeptonsCreateConst( &
   lepton, leptonSize &
) &
      bind(C, name='LeptonsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: leptonSize
   type(c_ptr) :: lepton(leptonSize)
   type(c_ptr) :: LeptonsCreateConst
end function LeptonsCreateConst

!! Create, general
function LeptonsCreate( &
   lepton, leptonSize &
) &
      bind(C, name='LeptonsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: leptonSize
   type(c_ptr) :: lepton(leptonSize)
   type(c_ptr) :: LeptonsCreate
end function LeptonsCreate

!! Assign
subroutine LeptonsAssign(handleLHS, handleRHS) &
      bind(C, name='LeptonsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine LeptonsAssign

!! Delete
subroutine LeptonsDelete(handle) &
      bind(C, name='LeptonsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine LeptonsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function LeptonsRead(handle, filename, filenameSize) &
      bind(C, name='LeptonsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LeptonsRead
end function LeptonsRead

!! Write to file
function LeptonsWrite(handle, filename, filenameSize) &
      bind(C, name='LeptonsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LeptonsWrite
end function LeptonsWrite

!! Print to standard output, in our prettyprinting format
function LeptonsPrint(handle) &
      bind(C, name='LeptonsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonsPrint
end function LeptonsPrint

!! Print to standard output, as XML
function LeptonsPrintXML(handle) &
      bind(C, name='LeptonsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonsPrintXML
end function LeptonsPrintXML

!! Print to standard output, as JSON
function LeptonsPrintJSON(handle) &
      bind(C, name='LeptonsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonsPrintJSON
end function LeptonsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: lepton
!! -----------------------------------------------------------------------------

!! Has
function LeptonsLeptonHas(handle) &
      bind(C, name='LeptonsLeptonHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonsLeptonHas
end function LeptonsLeptonHas

!! Clear
subroutine LeptonsLeptonClear(handle) &
      bind(C, name='LeptonsLeptonClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine LeptonsLeptonClear

!! Size
function LeptonsLeptonSize(handle) &
      bind(C, name='LeptonsLeptonSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: LeptonsLeptonSize
end function LeptonsLeptonSize

!! Add
subroutine LeptonsLeptonAdd(handle, fieldHandle) &
      bind(C, name='LeptonsLeptonAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine LeptonsLeptonAdd

!! Get, by index \in [0,size), const
function LeptonsLeptonGetConst(handle, index) &
      bind(C, name='LeptonsLeptonGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: LeptonsLeptonGetConst
end function LeptonsLeptonGetConst

!! Get, by index \in [0,size)
function LeptonsLeptonGet(handle, index) &
      bind(C, name='LeptonsLeptonGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: LeptonsLeptonGet
end function LeptonsLeptonGet

!! Set, by index \in [0,size)
subroutine LeptonsLeptonSet(handle, index, fieldHandle) &
      bind(C, name='LeptonsLeptonSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine LeptonsLeptonSet

!! ------------------------
!! Re: metadatum id
!! ------------------------

!! Has, by id
function LeptonsLeptonHasById(handle, meta, metaSize) &
      bind(C, name='LeptonsLeptonHasById')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: LeptonsLeptonHasById
end function LeptonsLeptonHasById

!! Get, by id, const
function LeptonsLeptonGetByIdConst(handle, meta, metaSize) &
      bind(C, name='LeptonsLeptonGetByIdConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: LeptonsLeptonGetByIdConst
end function LeptonsLeptonGetByIdConst

!! Get, by id
function LeptonsLeptonGetById(handle, meta, metaSize) &
      bind(C, name='LeptonsLeptonGetById')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: LeptonsLeptonGetById
end function LeptonsLeptonGetById

!! Set, by id
subroutine LeptonsLeptonSetById(handle, meta, metaSize, fieldHandle) &
      bind(C, name='LeptonsLeptonSetById')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine LeptonsLeptonSetById

!! ------------------------
!! Re: metadatum generation
!! ------------------------

!! Has, by generation
function LeptonsLeptonHasByGeneration(handle, meta, metaSize) &
      bind(C, name='LeptonsLeptonHasByGeneration')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: LeptonsLeptonHasByGeneration
end function LeptonsLeptonHasByGeneration

!! Get, by generation, const
function LeptonsLeptonGetByGenerationConst(handle, meta, metaSize) &
      bind(C, name='LeptonsLeptonGetByGenerationConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: LeptonsLeptonGetByGenerationConst
end function LeptonsLeptonGetByGenerationConst

!! Get, by generation
function LeptonsLeptonGetByGeneration(handle, meta, metaSize) &
      bind(C, name='LeptonsLeptonGetByGeneration')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: LeptonsLeptonGetByGeneration
end function LeptonsLeptonGetByGeneration

!! Set, by generation
subroutine LeptonsLeptonSetByGeneration(handle, meta, metaSize, fieldHandle) &
      bind(C, name='LeptonsLeptonSetByGeneration')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine LeptonsLeptonSetByGeneration


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalLeptons
