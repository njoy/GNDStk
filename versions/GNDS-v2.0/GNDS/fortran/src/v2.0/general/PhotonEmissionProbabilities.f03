
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalPhotonEmissionProbabilities
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function PhotonEmissionProbabilitiesDefaultConst() &
      bind(C, name='PhotonEmissionProbabilitiesDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: PhotonEmissionProbabilitiesDefaultConst
end function PhotonEmissionProbabilitiesDefaultConst

!! Create, default, non-const
function PhotonEmissionProbabilitiesDefault() &
      bind(C, name='PhotonEmissionProbabilitiesDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: PhotonEmissionProbabilitiesDefault
end function PhotonEmissionProbabilitiesDefault

!! Create, general, const
function PhotonEmissionProbabilitiesCreateConst( &
   shell &
) &
      bind(C, name='PhotonEmissionProbabilitiesCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: shell
   type(c_ptr) :: PhotonEmissionProbabilitiesCreateConst
end function PhotonEmissionProbabilitiesCreateConst

!! Create, general, non-const
function PhotonEmissionProbabilitiesCreate( &
   shell &
) &
      bind(C, name='PhotonEmissionProbabilitiesCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: shell
   type(c_ptr) :: PhotonEmissionProbabilitiesCreate
end function PhotonEmissionProbabilitiesCreate

!! Assign
subroutine PhotonEmissionProbabilitiesAssign(handleLHS, handleRHS) &
      bind(C, name='PhotonEmissionProbabilitiesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine PhotonEmissionProbabilitiesAssign

!! Delete
subroutine PhotonEmissionProbabilitiesDelete(handle) &
      bind(C, name='PhotonEmissionProbabilitiesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine PhotonEmissionProbabilitiesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function PhotonEmissionProbabilitiesRead(handle, filename, filenameSize) &
      bind(C, name='PhotonEmissionProbabilitiesRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: PhotonEmissionProbabilitiesRead
end function PhotonEmissionProbabilitiesRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function PhotonEmissionProbabilitiesWrite(handle, filename, filenameSize) &
      bind(C, name='PhotonEmissionProbabilitiesWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: PhotonEmissionProbabilitiesWrite
end function PhotonEmissionProbabilitiesWrite

!! Print to standard output, in our prettyprinting format
function PhotonEmissionProbabilitiesPrint(handle) &
      bind(C, name='PhotonEmissionProbabilitiesPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PhotonEmissionProbabilitiesPrint
end function PhotonEmissionProbabilitiesPrint

!! Print to standard output, as XML
function PhotonEmissionProbabilitiesPrintXML(handle) &
      bind(C, name='PhotonEmissionProbabilitiesPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PhotonEmissionProbabilitiesPrintXML
end function PhotonEmissionProbabilitiesPrintXML

!! Print to standard output, as JSON
function PhotonEmissionProbabilitiesPrintJSON(handle) &
      bind(C, name='PhotonEmissionProbabilitiesPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PhotonEmissionProbabilitiesPrintJSON
end function PhotonEmissionProbabilitiesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: shell
!! -----------------------------------------------------------------------------

!! Has
function PhotonEmissionProbabilitiesShellHas(handle) &
      bind(C, name='PhotonEmissionProbabilitiesShellHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PhotonEmissionProbabilitiesShellHas
end function PhotonEmissionProbabilitiesShellHas

!! Get, const
function PhotonEmissionProbabilitiesShellGetConst(handle) &
      bind(C, name='PhotonEmissionProbabilitiesShellGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PhotonEmissionProbabilitiesShellGetConst
end function PhotonEmissionProbabilitiesShellGetConst

!! Get, non-const
function PhotonEmissionProbabilitiesShellGet(handle) &
      bind(C, name='PhotonEmissionProbabilitiesShellGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PhotonEmissionProbabilitiesShellGet
end function PhotonEmissionProbabilitiesShellGet

!! Set
subroutine PhotonEmissionProbabilitiesShellSet(handle, fieldHandle) &
      bind(C, name='PhotonEmissionProbabilitiesShellSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PhotonEmissionProbabilitiesShellSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalPhotonEmissionProbabilities
