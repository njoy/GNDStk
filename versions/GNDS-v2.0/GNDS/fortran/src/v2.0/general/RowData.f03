
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalRowData
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function RowDataDefaultConst() &
      bind(C, name='RowDataDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function RowDataDefaultConst

!! Create, default
function RowDataDefault() &
      bind(C, name='RowDataDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function RowDataDefault

!! Create, general, const
function RowDataCreateConst( &
   ENDF_MFMT, &
   dimension, &
   href, &
   slices, &
   ENDF_MFMTSize, &
   hrefSize &
) &
      bind(C, name='RowDataCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: ENDF_MFMTSize
   character(c_char), intent(in) :: ENDF_MFMT(ENDF_MFMTSize)
   integer(c_int), value, intent(in) :: dimension
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr), value :: slices
   type(c_ptr) :: handle
end function RowDataCreateConst

!! Create, general
function RowDataCreate( &
   ENDF_MFMT, &
   dimension, &
   href, &
   slices, &
   ENDF_MFMTSize, &
   hrefSize &
) &
      bind(C, name='RowDataCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: ENDF_MFMTSize
   character(c_char), intent(in) :: ENDF_MFMT(ENDF_MFMTSize)
   integer(c_int), value, intent(in) :: dimension
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr), value :: slices
   type(c_ptr) :: handle
end function RowDataCreate

!! Assign
subroutine RowDataAssign(handleLHS, handleRHS) &
      bind(C, name='RowDataAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine RowDataAssign

!! Delete
subroutine RowDataDelete(handle) &
      bind(C, name='RowDataDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine RowDataDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function RowDataRead(handle, filename, filenameSize) &
      bind(C, name='RowDataRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function RowDataRead

!! Write to file
function RowDataWrite(handle, filename, filenameSize) &
      bind(C, name='RowDataWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function RowDataWrite

!! Print to standard output, in our prettyprinting format
function RowDataPrint(handle) &
      bind(C, name='RowDataPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function RowDataPrint

!! Print to standard output, as XML
function RowDataPrintXML(handle) &
      bind(C, name='RowDataPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function RowDataPrintXML

!! Print to standard output, as JSON
function RowDataPrintJSON(handle) &
      bind(C, name='RowDataPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function RowDataPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: ENDF_MFMT
!! -----------------------------------------------------------------------------

!! Has
function RowDataENDFMFMTHas(handle) &
      bind(C, name='RowDataENDFMFMTHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function RowDataENDFMFMTHas

!! Get
function RowDataENDFMFMTGet(handle) &
      bind(C, name='RowDataENDFMFMTGet') &
      result(ENDF_MFMT)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ENDF_MFMT
end function RowDataENDFMFMTGet

!! Set
subroutine RowDataENDFMFMTSet(handle, ENDF_MFMT, ENDF_MFMTSize) &
      bind(C, name='RowDataENDFMFMTSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: ENDF_MFMTSize
   character(c_char), intent(in) :: ENDF_MFMT(ENDF_MFMTSize)
end subroutine RowDataENDFMFMTSet


!! -----------------------------------------------------------------------------
!! Metadatum: dimension
!! -----------------------------------------------------------------------------

!! Has
function RowDataDimensionHas(handle) &
      bind(C, name='RowDataDimensionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function RowDataDimensionHas

!! Get
function RowDataDimensionGet(handle) &
      bind(C, name='RowDataDimensionGet') &
      result(dimension)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: dimension
end function RowDataDimensionGet

!! Set
subroutine RowDataDimensionSet(handle, dimension, dimensionSize) &
      bind(C, name='RowDataDimensionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: dimensionSize
   character(c_char), intent(in) :: dimension(dimensionSize)
end subroutine RowDataDimensionSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function RowDataHrefHas(handle) &
      bind(C, name='RowDataHrefHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function RowDataHrefHas

!! Get
function RowDataHrefGet(handle) &
      bind(C, name='RowDataHrefGet') &
      result(href)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: href
end function RowDataHrefGet

!! Set
subroutine RowDataHrefSet(handle, href, hrefSize) &
      bind(C, name='RowDataHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine RowDataHrefSet


!! -----------------------------------------------------------------------------
!! Child: slices
!! -----------------------------------------------------------------------------

!! Has
function RowDataSlicesHas(handle) &
      bind(C, name='RowDataSlicesHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function RowDataSlicesHas

!! Get, const
function RowDataSlicesGetConst(handle) &
      bind(C, name='RowDataSlicesGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function RowDataSlicesGetConst

!! Get
function RowDataSlicesGet(handle) &
      bind(C, name='RowDataSlicesGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function RowDataSlicesGet

!! Set
subroutine RowDataSlicesSet(handle, fieldHandle) &
      bind(C, name='RowDataSlicesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine RowDataSlicesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalRowData
