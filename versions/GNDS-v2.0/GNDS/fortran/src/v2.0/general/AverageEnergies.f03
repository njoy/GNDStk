
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalAverageEnergies
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AverageEnergiesDefaultConst() &
      bind(C, name='AverageEnergiesDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AverageEnergiesDefaultConst
end function AverageEnergiesDefaultConst

!! Create, default
function AverageEnergiesDefault() &
      bind(C, name='AverageEnergiesDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AverageEnergiesDefault
end function AverageEnergiesDefault

!! Create, general, const
function AverageEnergiesCreateConst( &
   averageEnergy, averageEnergySize &
) &
      bind(C, name='AverageEnergiesCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: averageEnergySize
   type(c_ptr) :: averageEnergy(averageEnergySize)
   type(c_ptr) :: AverageEnergiesCreateConst
end function AverageEnergiesCreateConst

!! Create, general
function AverageEnergiesCreate( &
   averageEnergy, averageEnergySize &
) &
      bind(C, name='AverageEnergiesCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: averageEnergySize
   type(c_ptr) :: averageEnergy(averageEnergySize)
   type(c_ptr) :: AverageEnergiesCreate
end function AverageEnergiesCreate

!! Assign
subroutine AverageEnergiesAssign(handleLHS, handleRHS) &
      bind(C, name='AverageEnergiesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine AverageEnergiesAssign

!! Delete
subroutine AverageEnergiesDelete(handle) &
      bind(C, name='AverageEnergiesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AverageEnergiesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function AverageEnergiesRead(handle, filename, filenameSize) &
      bind(C, name='AverageEnergiesRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AverageEnergiesRead
end function AverageEnergiesRead

!! Write to file
function AverageEnergiesWrite(handle, filename, filenameSize) &
      bind(C, name='AverageEnergiesWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AverageEnergiesWrite
end function AverageEnergiesWrite

!! Print to standard output, in our prettyprinting format
function AverageEnergiesPrint(handle) &
      bind(C, name='AverageEnergiesPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageEnergiesPrint
end function AverageEnergiesPrint

!! Print to standard output, as XML
function AverageEnergiesPrintXML(handle) &
      bind(C, name='AverageEnergiesPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageEnergiesPrintXML
end function AverageEnergiesPrintXML

!! Print to standard output, as JSON
function AverageEnergiesPrintJSON(handle) &
      bind(C, name='AverageEnergiesPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageEnergiesPrintJSON
end function AverageEnergiesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: averageEnergy
!! -----------------------------------------------------------------------------

!! Has
function AverageEnergiesAverageEnergyHas(handle) &
      bind(C, name='AverageEnergiesAverageEnergyHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AverageEnergiesAverageEnergyHas
end function AverageEnergiesAverageEnergyHas

!! Clear
subroutine AverageEnergiesAverageEnergyClear(handle) &
      bind(C, name='AverageEnergiesAverageEnergyClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AverageEnergiesAverageEnergyClear

!! Size
function AverageEnergiesAverageEnergySize(handle) &
      bind(C, name='AverageEnergiesAverageEnergySize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: AverageEnergiesAverageEnergySize
end function AverageEnergiesAverageEnergySize

!! Add
subroutine AverageEnergiesAverageEnergyAdd(handle, fieldHandle) &
      bind(C, name='AverageEnergiesAverageEnergyAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AverageEnergiesAverageEnergyAdd

!! Get, by index \in [0,size), const
function AverageEnergiesAverageEnergyGetConst(handle, index) &
      bind(C, name='AverageEnergiesAverageEnergyGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: AverageEnergiesAverageEnergyGetConst
end function AverageEnergiesAverageEnergyGetConst

!! Get, by index \in [0,size)
function AverageEnergiesAverageEnergyGet(handle, index) &
      bind(C, name='AverageEnergiesAverageEnergyGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: AverageEnergiesAverageEnergyGet
end function AverageEnergiesAverageEnergyGet

!! Set, by index \in [0,size)
subroutine AverageEnergiesAverageEnergySet(handle, index, fieldHandle) &
      bind(C, name='AverageEnergiesAverageEnergySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AverageEnergiesAverageEnergySet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function AverageEnergiesAverageEnergyHasByLabel(handle, meta, metaSize) &
      bind(C, name='AverageEnergiesAverageEnergyHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: AverageEnergiesAverageEnergyHasByLabel
end function AverageEnergiesAverageEnergyHasByLabel

!! Get, by label, const
function AverageEnergiesAverageEnergyGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='AverageEnergiesAverageEnergyGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: AverageEnergiesAverageEnergyGetByLabelConst
end function AverageEnergiesAverageEnergyGetByLabelConst

!! Get, by label
function AverageEnergiesAverageEnergyGetByLabel(handle, meta, metaSize) &
      bind(C, name='AverageEnergiesAverageEnergyGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: AverageEnergiesAverageEnergyGetByLabel
end function AverageEnergiesAverageEnergyGetByLabel

!! Set, by label
subroutine AverageEnergiesAverageEnergySetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='AverageEnergiesAverageEnergySetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AverageEnergiesAverageEnergySetByLabel

!! ------------------------
!! Re: metadatum value
!! ------------------------

!! Has, by value
function AverageEnergiesAverageEnergyHasByValue(handle, meta) &
      bind(C, name='AverageEnergiesAverageEnergyHasByValue')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), value, intent(in) :: meta
   integer(c_int) :: AverageEnergiesAverageEnergyHasByValue
end function AverageEnergiesAverageEnergyHasByValue

!! Get, by value, const
function AverageEnergiesAverageEnergyGetByValueConst(handle, meta) &
      bind(C, name='AverageEnergiesAverageEnergyGetByValueConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), value, intent(in) :: meta
   type(c_ptr) :: AverageEnergiesAverageEnergyGetByValueConst
end function AverageEnergiesAverageEnergyGetByValueConst

!! Get, by value
function AverageEnergiesAverageEnergyGetByValue(handle, meta) &
      bind(C, name='AverageEnergiesAverageEnergyGetByValue')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), value, intent(in) :: meta
   type(c_ptr) :: AverageEnergiesAverageEnergyGetByValue
end function AverageEnergiesAverageEnergyGetByValue

!! Set, by value
subroutine AverageEnergiesAverageEnergySetByValue(handle, meta, fieldHandle) &
      bind(C, name='AverageEnergiesAverageEnergySetByValue')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), value, intent(in) :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AverageEnergiesAverageEnergySetByValue

!! ------------------------
!! Re: metadatum unit
!! ------------------------

!! Has, by unit
function AverageEnergiesAverageEnergyHasByUnit(handle, meta, metaSize) &
      bind(C, name='AverageEnergiesAverageEnergyHasByUnit')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: AverageEnergiesAverageEnergyHasByUnit
end function AverageEnergiesAverageEnergyHasByUnit

!! Get, by unit, const
function AverageEnergiesAverageEnergyGetByUnitConst(handle, meta, metaSize) &
      bind(C, name='AverageEnergiesAverageEnergyGetByUnitConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: AverageEnergiesAverageEnergyGetByUnitConst
end function AverageEnergiesAverageEnergyGetByUnitConst

!! Get, by unit
function AverageEnergiesAverageEnergyGetByUnit(handle, meta, metaSize) &
      bind(C, name='AverageEnergiesAverageEnergyGetByUnit')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: AverageEnergiesAverageEnergyGetByUnit
end function AverageEnergiesAverageEnergyGetByUnit

!! Set, by unit
subroutine AverageEnergiesAverageEnergySetByUnit(handle, meta, metaSize, fieldHandle) &
      bind(C, name='AverageEnergiesAverageEnergySetByUnit')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AverageEnergiesAverageEnergySetByUnit


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalAverageEnergies
