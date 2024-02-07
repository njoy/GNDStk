
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalDecayData
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DecayDataDefaultConst() &
      bind(C, name='DecayDataDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DecayDataDefaultConst
end function DecayDataDefaultConst

!! Create, default, non-const
function DecayDataDefault() &
      bind(C, name='DecayDataDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DecayDataDefault
end function DecayDataDefault

!! Create, general, const
function DecayDataCreateConst( &
   decayModes, &
   averageEnergies &
) &
      bind(C, name='DecayDataCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: decayModes
   type(c_ptr), intent(in), value :: averageEnergies
   type(c_ptr) :: DecayDataCreateConst
end function DecayDataCreateConst

!! Create, general, non-const
function DecayDataCreate( &
   decayModes, &
   averageEnergies &
) &
      bind(C, name='DecayDataCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: decayModes
   type(c_ptr), intent(in), value :: averageEnergies
   type(c_ptr) :: DecayDataCreate
end function DecayDataCreate

!! Assign
subroutine DecayDataAssign(handleLHS, handleRHS) &
      bind(C, name='DecayDataAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine DecayDataAssign

!! Delete
subroutine DecayDataDelete(handle) &
      bind(C, name='DecayDataDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DecayDataDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function DecayDataRead(handle, filename, filenameSize) &
      bind(C, name='DecayDataRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DecayDataRead
end function DecayDataRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function DecayDataWrite(handle, filename, filenameSize) &
      bind(C, name='DecayDataWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DecayDataWrite
end function DecayDataWrite

!! Print to standard output, in our prettyprinting format
function DecayDataPrint(handle) &
      bind(C, name='DecayDataPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayDataPrint
end function DecayDataPrint

!! Print to standard output, as XML
function DecayDataPrintXML(handle) &
      bind(C, name='DecayDataPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayDataPrintXML
end function DecayDataPrintXML

!! Print to standard output, as JSON
function DecayDataPrintJSON(handle) &
      bind(C, name='DecayDataPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayDataPrintJSON
end function DecayDataPrintJSON


!! -----------------------------------------------------------------------------
!! Child: decayModes
!! -----------------------------------------------------------------------------

!! Has
function DecayDataDecayModesHas(handle) &
      bind(C, name='DecayDataDecayModesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayDataDecayModesHas
end function DecayDataDecayModesHas

!! Get, const
function DecayDataDecayModesGetConst(handle) &
      bind(C, name='DecayDataDecayModesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayDataDecayModesGetConst
end function DecayDataDecayModesGetConst

!! Get, non-const
function DecayDataDecayModesGet(handle) &
      bind(C, name='DecayDataDecayModesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayDataDecayModesGet
end function DecayDataDecayModesGet

!! Set
subroutine DecayDataDecayModesSet(handle, fieldHandle) &
      bind(C, name='DecayDataDecayModesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayDataDecayModesSet


!! -----------------------------------------------------------------------------
!! Child: averageEnergies
!! -----------------------------------------------------------------------------

!! Has
function DecayDataAverageEnergiesHas(handle) &
      bind(C, name='DecayDataAverageEnergiesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayDataAverageEnergiesHas
end function DecayDataAverageEnergiesHas

!! Get, const
function DecayDataAverageEnergiesGetConst(handle) &
      bind(C, name='DecayDataAverageEnergiesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayDataAverageEnergiesGetConst
end function DecayDataAverageEnergiesGetConst

!! Get, non-const
function DecayDataAverageEnergiesGet(handle) &
      bind(C, name='DecayDataAverageEnergiesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayDataAverageEnergiesGet
end function DecayDataAverageEnergiesGet

!! Set
subroutine DecayDataAverageEnergiesSet(handle, fieldHandle) &
      bind(C, name='DecayDataAverageEnergiesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayDataAverageEnergiesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalDecayData