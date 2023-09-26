
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalChemicalElement
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ChemicalElementDefaultConst() &
      bind(C, name='ChemicalElementDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ChemicalElementDefaultConst
end function ChemicalElementDefaultConst

!! Create, default
function ChemicalElementDefault() &
      bind(C, name='ChemicalElementDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ChemicalElementDefault
end function ChemicalElementDefault

!! Create, general, const
function ChemicalElementCreateConst( &
   symbol, &
   Z, &
   name, &
   atomic, &
   isotopes, &
   symbolSize, &
   nameSize &
) &
      bind(C, name='ChemicalElementCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: symbolSize
   character(c_char), intent(in) :: symbol(symbolSize)
   integer(c_int), value, intent(in) :: Z
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   type(c_ptr), value :: atomic
   type(c_ptr), value :: isotopes
   type(c_ptr) :: ChemicalElementCreateConst
end function ChemicalElementCreateConst

!! Create, general
function ChemicalElementCreate( &
   symbol, &
   Z, &
   name, &
   atomic, &
   isotopes, &
   symbolSize, &
   nameSize &
) &
      bind(C, name='ChemicalElementCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: symbolSize
   character(c_char), intent(in) :: symbol(symbolSize)
   integer(c_int), value, intent(in) :: Z
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   type(c_ptr), value :: atomic
   type(c_ptr), value :: isotopes
   type(c_ptr) :: ChemicalElementCreate
end function ChemicalElementCreate

!! Assign
subroutine ChemicalElementAssign(handleLHS, handleRHS) &
      bind(C, name='ChemicalElementAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ChemicalElementAssign

!! Delete
subroutine ChemicalElementDelete(handle) &
      bind(C, name='ChemicalElementDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ChemicalElementDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ChemicalElementRead(handle, filename, filenameSize) &
      bind(C, name='ChemicalElementRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ChemicalElementRead
end function ChemicalElementRead

!! Write to file
function ChemicalElementWrite(handle, filename, filenameSize) &
      bind(C, name='ChemicalElementWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ChemicalElementWrite
end function ChemicalElementWrite

!! Print to standard output, in our prettyprinting format
function ChemicalElementPrint(handle) &
      bind(C, name='ChemicalElementPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementPrint
end function ChemicalElementPrint

!! Print to standard output, as XML
function ChemicalElementPrintXML(handle) &
      bind(C, name='ChemicalElementPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementPrintXML
end function ChemicalElementPrintXML

!! Print to standard output, as JSON
function ChemicalElementPrintJSON(handle) &
      bind(C, name='ChemicalElementPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementPrintJSON
end function ChemicalElementPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: symbol
!! -----------------------------------------------------------------------------

!! Has
function ChemicalElementSymbolHas(handle) &
      bind(C, name='ChemicalElementSymbolHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementSymbolHas
end function ChemicalElementSymbolHas

!! Get
function ChemicalElementSymbolGet(handle) &
      bind(C, name='ChemicalElementSymbolGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ChemicalElementSymbolGet
end function ChemicalElementSymbolGet

!! Set
subroutine ChemicalElementSymbolSet(handle, symbol, symbolSize) &
      bind(C, name='ChemicalElementSymbolSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: symbolSize
   character(c_char), intent(in) :: symbol(symbolSize)
end subroutine ChemicalElementSymbolSet


!! -----------------------------------------------------------------------------
!! Metadatum: Z
!! -----------------------------------------------------------------------------

!! Has
function ChemicalElementZHas(handle) &
      bind(C, name='ChemicalElementZHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementZHas
end function ChemicalElementZHas

!! Get
function ChemicalElementZGet(handle) &
      bind(C, name='ChemicalElementZGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementZGet
end function ChemicalElementZGet

!! Set
subroutine ChemicalElementZSet(handle, Z, ZSize) &
      bind(C, name='ChemicalElementZSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: ZSize
   character(c_char), intent(in) :: Z(ZSize)
end subroutine ChemicalElementZSet


!! -----------------------------------------------------------------------------
!! Metadatum: name
!! -----------------------------------------------------------------------------

!! Has
function ChemicalElementNameHas(handle) &
      bind(C, name='ChemicalElementNameHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementNameHas
end function ChemicalElementNameHas

!! Get
function ChemicalElementNameGet(handle) &
      bind(C, name='ChemicalElementNameGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ChemicalElementNameGet
end function ChemicalElementNameGet

!! Set
subroutine ChemicalElementNameSet(handle, name, nameSize) &
      bind(C, name='ChemicalElementNameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
end subroutine ChemicalElementNameSet


!! -----------------------------------------------------------------------------
!! Child: atomic
!! -----------------------------------------------------------------------------

!! Has
function ChemicalElementAtomicHas(handle) &
      bind(C, name='ChemicalElementAtomicHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementAtomicHas
end function ChemicalElementAtomicHas

!! Get, const
function ChemicalElementAtomicGetConst(handle) &
      bind(C, name='ChemicalElementAtomicGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ChemicalElementAtomicGetConst
end function ChemicalElementAtomicGetConst

!! Get
function ChemicalElementAtomicGet(handle) &
      bind(C, name='ChemicalElementAtomicGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ChemicalElementAtomicGet
end function ChemicalElementAtomicGet

!! Set
subroutine ChemicalElementAtomicSet(handle, fieldHandle) &
      bind(C, name='ChemicalElementAtomicSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ChemicalElementAtomicSet


!! -----------------------------------------------------------------------------
!! Child: isotopes
!! -----------------------------------------------------------------------------

!! Has
function ChemicalElementIsotopesHas(handle) &
      bind(C, name='ChemicalElementIsotopesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ChemicalElementIsotopesHas
end function ChemicalElementIsotopesHas

!! Get, const
function ChemicalElementIsotopesGetConst(handle) &
      bind(C, name='ChemicalElementIsotopesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ChemicalElementIsotopesGetConst
end function ChemicalElementIsotopesGetConst

!! Get
function ChemicalElementIsotopesGet(handle) &
      bind(C, name='ChemicalElementIsotopesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ChemicalElementIsotopesGet
end function ChemicalElementIsotopesGet

!! Set
subroutine ChemicalElementIsotopesSet(handle, fieldHandle) &
      bind(C, name='ChemicalElementIsotopesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ChemicalElementIsotopesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalChemicalElement
