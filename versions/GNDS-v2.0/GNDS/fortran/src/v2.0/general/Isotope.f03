
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalIsotope
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function IsotopeDefaultConst() &
      bind(C, name='IsotopeDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: IsotopeDefaultConst
end function IsotopeDefaultConst

!! Create, default, non-const
function IsotopeDefault() &
      bind(C, name='IsotopeDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: IsotopeDefault
end function IsotopeDefault

!! Create, general, const
function IsotopeCreateConst( &
   symbol, &
   A, &
   nuclides, &
   symbolSize &
) &
      bind(C, name='IsotopeCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: symbolSize
   character(c_char), intent(in) :: symbol(symbolSize)
   integer(c_int), intent(in), value :: A
   type(c_ptr), intent(in), value :: nuclides
   type(c_ptr) :: IsotopeCreateConst
end function IsotopeCreateConst

!! Create, general, non-const
function IsotopeCreate( &
   symbol, &
   A, &
   nuclides, &
   symbolSize &
) &
      bind(C, name='IsotopeCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: symbolSize
   character(c_char), intent(in) :: symbol(symbolSize)
   integer(c_int), intent(in), value :: A
   type(c_ptr), intent(in), value :: nuclides
   type(c_ptr) :: IsotopeCreate
end function IsotopeCreate

!! Assign
subroutine IsotopeAssign(handleLHS, handleRHS) &
      bind(C, name='IsotopeAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine IsotopeAssign

!! Delete
subroutine IsotopeDelete(handle) &
      bind(C, name='IsotopeDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine IsotopeDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function IsotopeRead(handle, filename, filenameSize) &
      bind(C, name='IsotopeRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: IsotopeRead
end function IsotopeRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function IsotopeWrite(handle, filename, filenameSize) &
      bind(C, name='IsotopeWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: IsotopeWrite
end function IsotopeWrite

!! Print to standard output, in our prettyprinting format
function IsotopePrint(handle) &
      bind(C, name='IsotopePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: IsotopePrint
end function IsotopePrint

!! Print to standard output, as XML
function IsotopePrintXML(handle) &
      bind(C, name='IsotopePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: IsotopePrintXML
end function IsotopePrintXML

!! Print to standard output, as JSON
function IsotopePrintJSON(handle) &
      bind(C, name='IsotopePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: IsotopePrintJSON
end function IsotopePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: symbol
!! -----------------------------------------------------------------------------

!! Has
function IsotopeSymbolHas(handle) &
      bind(C, name='IsotopeSymbolHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: IsotopeSymbolHas
end function IsotopeSymbolHas

!! Get
function IsotopeSymbolGet(handle) &
      bind(C, name='IsotopeSymbolGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: IsotopeSymbolGet
end function IsotopeSymbolGet

!! Set
subroutine IsotopeSymbolSet(handle, symbol, symbolSize) &
      bind(C, name='IsotopeSymbolSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: symbolSize
   character(c_char), intent(in) :: symbol(symbolSize)
end subroutine IsotopeSymbolSet


!! -----------------------------------------------------------------------------
!! Metadatum: A
!! -----------------------------------------------------------------------------

!! Has
function IsotopeAHas(handle) &
      bind(C, name='IsotopeAHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: IsotopeAHas
end function IsotopeAHas

!! Get
function IsotopeAGet(handle) &
      bind(C, name='IsotopeAGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: IsotopeAGet
end function IsotopeAGet

!! Set
subroutine IsotopeASet(handle, A) &
      bind(C, name='IsotopeASet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: A
end subroutine IsotopeASet


!! -----------------------------------------------------------------------------
!! Child: nuclides
!! -----------------------------------------------------------------------------

!! Has
function IsotopeNuclidesHas(handle) &
      bind(C, name='IsotopeNuclidesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: IsotopeNuclidesHas
end function IsotopeNuclidesHas

!! Get, const
function IsotopeNuclidesGetConst(handle) &
      bind(C, name='IsotopeNuclidesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: IsotopeNuclidesGetConst
end function IsotopeNuclidesGetConst

!! Get, non-const
function IsotopeNuclidesGet(handle) &
      bind(C, name='IsotopeNuclidesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: IsotopeNuclidesGet
end function IsotopeNuclidesGet

!! Set
subroutine IsotopeNuclidesSet(handle, fieldHandle) &
      bind(C, name='IsotopeNuclidesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine IsotopeNuclidesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalIsotope