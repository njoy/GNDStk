
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalParameters
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ParametersDefaultConst() &
      bind(C, name='ParametersDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ParametersDefaultConst
end function ParametersDefaultConst

!! Create, default, non-const
function ParametersDefault() &
      bind(C, name='ParametersDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ParametersDefault
end function ParametersDefault

!! Create, general, const
function ParametersCreateConst( &
   parameterLink, parameterLinkSize &
) &
      bind(C, name='ParametersCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: parameterLinkSize
   type(c_ptr), intent(in) :: parameterLink(parameterLinkSize)
   type(c_ptr) :: ParametersCreateConst
end function ParametersCreateConst

!! Create, general, non-const
function ParametersCreate( &
   parameterLink, parameterLinkSize &
) &
      bind(C, name='ParametersCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: parameterLinkSize
   type(c_ptr), intent(in) :: parameterLink(parameterLinkSize)
   type(c_ptr) :: ParametersCreate
end function ParametersCreate

!! Assign
subroutine ParametersAssign(handleLHS, handleRHS) &
      bind(C, name='ParametersAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ParametersAssign

!! Delete
subroutine ParametersDelete(handle) &
      bind(C, name='ParametersDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ParametersDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ParametersRead(handle, filename, filenameSize) &
      bind(C, name='ParametersRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ParametersRead
end function ParametersRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ParametersWrite(handle, filename, filenameSize) &
      bind(C, name='ParametersWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ParametersWrite
end function ParametersWrite

!! Print to standard output, in our prettyprinting format
function ParametersPrint(handle) &
      bind(C, name='ParametersPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParametersPrint
end function ParametersPrint

!! Print to standard output, as XML
function ParametersPrintXML(handle) &
      bind(C, name='ParametersPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParametersPrintXML
end function ParametersPrintXML

!! Print to standard output, as JSON
function ParametersPrintJSON(handle) &
      bind(C, name='ParametersPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParametersPrintJSON
end function ParametersPrintJSON


!! -----------------------------------------------------------------------------
!! Child: parameterLink
!! -----------------------------------------------------------------------------

!! Has
function ParametersParameterLinkHas(handle) &
      bind(C, name='ParametersParameterLinkHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParametersParameterLinkHas
end function ParametersParameterLinkHas

!! Clear
subroutine ParametersParameterLinkClear(handle) &
      bind(C, name='ParametersParameterLinkClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ParametersParameterLinkClear

!! Size
function ParametersParameterLinkSize(handle) &
      bind(C, name='ParametersParameterLinkSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ParametersParameterLinkSize
end function ParametersParameterLinkSize

!! Add
subroutine ParametersParameterLinkAdd(handle, fieldHandle) &
      bind(C, name='ParametersParameterLinkAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParametersParameterLinkAdd

!! Get, by index \in [0,size), const
function ParametersParameterLinkGetConst(handle, index) &
      bind(C, name='ParametersParameterLinkGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ParametersParameterLinkGetConst
end function ParametersParameterLinkGetConst

!! Get, by index \in [0,size), non-const
function ParametersParameterLinkGet(handle, index) &
      bind(C, name='ParametersParameterLinkGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ParametersParameterLinkGet
end function ParametersParameterLinkGet

!! Set, by index \in [0,size)
subroutine ParametersParameterLinkSet(handle, index, fieldHandle) &
      bind(C, name='ParametersParameterLinkSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParametersParameterLinkSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ParametersParameterLinkHasByLabel(handle, meta, metaSize) &
      bind(C, name='ParametersParameterLinkHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ParametersParameterLinkHasByLabel
end function ParametersParameterLinkHasByLabel

!! Get, by label, const
function ParametersParameterLinkGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ParametersParameterLinkGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ParametersParameterLinkGetByLabelConst
end function ParametersParameterLinkGetByLabelConst

!! Get, by label, non-const
function ParametersParameterLinkGetByLabel(handle, meta, metaSize) &
      bind(C, name='ParametersParameterLinkGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ParametersParameterLinkGetByLabel
end function ParametersParameterLinkGetByLabel

!! Set, by label
subroutine ParametersParameterLinkSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ParametersParameterLinkSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParametersParameterLinkSetByLabel

!! ------------------------
!! Re: metadatum href
!! ------------------------

!! Has, by href
function ParametersParameterLinkHasByHref(handle, meta, metaSize) &
      bind(C, name='ParametersParameterLinkHasByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ParametersParameterLinkHasByHref
end function ParametersParameterLinkHasByHref

!! Get, by href, const
function ParametersParameterLinkGetByHrefConst(handle, meta, metaSize) &
      bind(C, name='ParametersParameterLinkGetByHrefConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ParametersParameterLinkGetByHrefConst
end function ParametersParameterLinkGetByHrefConst

!! Get, by href, non-const
function ParametersParameterLinkGetByHref(handle, meta, metaSize) &
      bind(C, name='ParametersParameterLinkGetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ParametersParameterLinkGetByHref
end function ParametersParameterLinkGetByHref

!! Set, by href
subroutine ParametersParameterLinkSetByHref(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ParametersParameterLinkSetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParametersParameterLinkSetByHref

!! ------------------------
!! Re: metadatum nParameters
!! ------------------------

!! Has, by nParameters
function ParametersParameterLinkHasByNParameters(handle, meta) &
      bind(C, name='ParametersParameterLinkHasByNParameters')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: ParametersParameterLinkHasByNParameters
end function ParametersParameterLinkHasByNParameters

!! Get, by nParameters, const
function ParametersParameterLinkGetByNParametersConst(handle, meta) &
      bind(C, name='ParametersParameterLinkGetByNParametersConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ParametersParameterLinkGetByNParametersConst
end function ParametersParameterLinkGetByNParametersConst

!! Get, by nParameters, non-const
function ParametersParameterLinkGetByNParameters(handle, meta) &
      bind(C, name='ParametersParameterLinkGetByNParameters')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ParametersParameterLinkGetByNParameters
end function ParametersParameterLinkGetByNParameters

!! Set, by nParameters
subroutine ParametersParameterLinkSetByNParameters(handle, meta, fieldHandle) &
      bind(C, name='ParametersParameterLinkSetByNParameters')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParametersParameterLinkSetByNParameters

!! ------------------------
!! Re: metadatum matrixStartIndex
!! ------------------------

!! Has, by matrixStartIndex
function ParametersParameterLinkHasByMatrixStartIndex(handle, meta) &
      bind(C, name='ParametersParameterLinkHasByMatrixStartIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: ParametersParameterLinkHasByMatrixStartIndex
end function ParametersParameterLinkHasByMatrixStartIndex

!! Get, by matrixStartIndex, const
function ParametersParameterLinkGetByMatrixStartIndexConst(handle, meta) &
      bind(C, name='ParametersParameterLinkGetByMatrixStartIndexConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ParametersParameterLinkGetByMatrixStartIndexConst
end function ParametersParameterLinkGetByMatrixStartIndexConst

!! Get, by matrixStartIndex, non-const
function ParametersParameterLinkGetByMatrixStartIndex(handle, meta) &
      bind(C, name='ParametersParameterLinkGetByMatrixStartIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: ParametersParameterLinkGetByMatrixStartIndex
end function ParametersParameterLinkGetByMatrixStartIndex

!! Set, by matrixStartIndex
subroutine ParametersParameterLinkSetByMatrixStartIndex(handle, meta, fieldHandle) &
      bind(C, name='ParametersParameterLinkSetByMatrixStartIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParametersParameterLinkSetByMatrixStartIndex


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalParameters