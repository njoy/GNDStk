
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalConfiguration
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ConfigurationDefaultConst() &
      bind(C, name='ConfigurationDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ConfigurationDefaultConst
end function ConfigurationDefaultConst

!! Create, default, non-const
function ConfigurationDefault() &
      bind(C, name='ConfigurationDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ConfigurationDefault
end function ConfigurationDefault

!! Create, general, const
function ConfigurationCreateConst( &
   subshell, &
   electronNumber, &
   bindingEnergy, &
   decayData, decayDataSize, &
   subshellSize &
) &
      bind(C, name='ConfigurationCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: subshellSize
   character(c_char), intent(in) :: subshell(subshellSize)
   real(c_double), intent(in), value :: electronNumber
   type(c_ptr), intent(in), value :: bindingEnergy
   integer(c_size_t), intent(in), value :: decayDataSize
   type(c_ptr), intent(in) :: decayData(decayDataSize)
   type(c_ptr) :: ConfigurationCreateConst
end function ConfigurationCreateConst

!! Create, general, non-const
function ConfigurationCreate( &
   subshell, &
   electronNumber, &
   bindingEnergy, &
   decayData, decayDataSize, &
   subshellSize &
) &
      bind(C, name='ConfigurationCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: subshellSize
   character(c_char), intent(in) :: subshell(subshellSize)
   real(c_double), intent(in), value :: electronNumber
   type(c_ptr), intent(in), value :: bindingEnergy
   integer(c_size_t), intent(in), value :: decayDataSize
   type(c_ptr), intent(in) :: decayData(decayDataSize)
   type(c_ptr) :: ConfigurationCreate
end function ConfigurationCreate

!! Assign
subroutine ConfigurationAssign(handleLHS, handleRHS) &
      bind(C, name='ConfigurationAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ConfigurationAssign

!! Delete
subroutine ConfigurationDelete(handle) &
      bind(C, name='ConfigurationDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ConfigurationDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ConfigurationRead(handle, filename, filenameSize) &
      bind(C, name='ConfigurationRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ConfigurationRead
end function ConfigurationRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ConfigurationWrite(handle, filename, filenameSize) &
      bind(C, name='ConfigurationWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ConfigurationWrite
end function ConfigurationWrite

!! Print to standard output, in our prettyprinting format
function ConfigurationPrint(handle) &
      bind(C, name='ConfigurationPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ConfigurationPrint
end function ConfigurationPrint

!! Print to standard output, as XML
function ConfigurationPrintXML(handle) &
      bind(C, name='ConfigurationPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ConfigurationPrintXML
end function ConfigurationPrintXML

!! Print to standard output, as JSON
function ConfigurationPrintJSON(handle) &
      bind(C, name='ConfigurationPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ConfigurationPrintJSON
end function ConfigurationPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: subshell
!! -----------------------------------------------------------------------------

!! Has
function ConfigurationSubshellHas(handle) &
      bind(C, name='ConfigurationSubshellHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ConfigurationSubshellHas
end function ConfigurationSubshellHas

!! Get
function ConfigurationSubshellGet(handle) &
      bind(C, name='ConfigurationSubshellGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ConfigurationSubshellGet
end function ConfigurationSubshellGet

!! Set
subroutine ConfigurationSubshellSet(handle, subshell, subshellSize) &
      bind(C, name='ConfigurationSubshellSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: subshellSize
   character(c_char), intent(in) :: subshell(subshellSize)
end subroutine ConfigurationSubshellSet


!! -----------------------------------------------------------------------------
!! Metadatum: electronNumber
!! -----------------------------------------------------------------------------

!! Has
function ConfigurationElectronNumberHas(handle) &
      bind(C, name='ConfigurationElectronNumberHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ConfigurationElectronNumberHas
end function ConfigurationElectronNumberHas

!! Get
function ConfigurationElectronNumberGet(handle) &
      bind(C, name='ConfigurationElectronNumberGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: ConfigurationElectronNumberGet
end function ConfigurationElectronNumberGet

!! Set
subroutine ConfigurationElectronNumberSet(handle, electronNumber) &
      bind(C, name='ConfigurationElectronNumberSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: electronNumber
end subroutine ConfigurationElectronNumberSet


!! -----------------------------------------------------------------------------
!! Child: bindingEnergy
!! -----------------------------------------------------------------------------

!! Has
function ConfigurationBindingEnergyHas(handle) &
      bind(C, name='ConfigurationBindingEnergyHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ConfigurationBindingEnergyHas
end function ConfigurationBindingEnergyHas

!! Get, const
function ConfigurationBindingEnergyGetConst(handle) &
      bind(C, name='ConfigurationBindingEnergyGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ConfigurationBindingEnergyGetConst
end function ConfigurationBindingEnergyGetConst

!! Get, non-const
function ConfigurationBindingEnergyGet(handle) &
      bind(C, name='ConfigurationBindingEnergyGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ConfigurationBindingEnergyGet
end function ConfigurationBindingEnergyGet

!! Set
subroutine ConfigurationBindingEnergySet(handle, fieldHandle) &
      bind(C, name='ConfigurationBindingEnergySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ConfigurationBindingEnergySet


!! -----------------------------------------------------------------------------
!! Child: decayData
!! -----------------------------------------------------------------------------

!! Has
function ConfigurationDecayDataHas(handle) &
      bind(C, name='ConfigurationDecayDataHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ConfigurationDecayDataHas
end function ConfigurationDecayDataHas

!! Clear
subroutine ConfigurationDecayDataClear(handle) &
      bind(C, name='ConfigurationDecayDataClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ConfigurationDecayDataClear

!! Size
function ConfigurationDecayDataSize(handle) &
      bind(C, name='ConfigurationDecayDataSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ConfigurationDecayDataSize
end function ConfigurationDecayDataSize

!! Add
subroutine ConfigurationDecayDataAdd(handle, fieldHandle) &
      bind(C, name='ConfigurationDecayDataAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ConfigurationDecayDataAdd

!! Get, by index \in [0,size), const
function ConfigurationDecayDataGetConst(handle, index) &
      bind(C, name='ConfigurationDecayDataGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ConfigurationDecayDataGetConst
end function ConfigurationDecayDataGetConst

!! Get, by index \in [0,size), non-const
function ConfigurationDecayDataGet(handle, index) &
      bind(C, name='ConfigurationDecayDataGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ConfigurationDecayDataGet
end function ConfigurationDecayDataGet

!! Set, by index \in [0,size)
subroutine ConfigurationDecayDataSet(handle, index, fieldHandle) &
      bind(C, name='ConfigurationDecayDataSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ConfigurationDecayDataSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalConfiguration