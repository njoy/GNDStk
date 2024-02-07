
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalGrid
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function GridDefaultConst() &
      bind(C, name='GridDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: GridDefaultConst
end function GridDefaultConst

!! Create, default, non-const
function GridDefault() &
      bind(C, name='GridDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: GridDefault
end function GridDefault

!! Create, general, const
function GridCreateConst( &
   index, &
   label, &
   unit, &
   style, &
   interpolation, &
   link, &
   values, &
   labelSize, &
   unitSize, &
   styleSize, &
   interpolationSize &
) &
      bind(C, name='GridCreateConst')
   use iso_c_binding
   implicit none
   integer(c_int), intent(in), value :: index
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   integer(c_size_t), intent(in), value :: styleSize
   character(c_char), intent(in) :: style(styleSize)
   integer(c_size_t), intent(in), value :: interpolationSize
   character(c_char), intent(in) :: interpolation(interpolationSize)
   type(c_ptr), intent(in), value :: link
   type(c_ptr), intent(in), value :: values
   type(c_ptr) :: GridCreateConst
end function GridCreateConst

!! Create, general, non-const
function GridCreate( &
   index, &
   label, &
   unit, &
   style, &
   interpolation, &
   link, &
   values, &
   labelSize, &
   unitSize, &
   styleSize, &
   interpolationSize &
) &
      bind(C, name='GridCreate')
   use iso_c_binding
   implicit none
   integer(c_int), intent(in), value :: index
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   integer(c_size_t), intent(in), value :: styleSize
   character(c_char), intent(in) :: style(styleSize)
   integer(c_size_t), intent(in), value :: interpolationSize
   character(c_char), intent(in) :: interpolation(interpolationSize)
   type(c_ptr), intent(in), value :: link
   type(c_ptr), intent(in), value :: values
   type(c_ptr) :: GridCreate
end function GridCreate

!! Assign
subroutine GridAssign(handleLHS, handleRHS) &
      bind(C, name='GridAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine GridAssign

!! Delete
subroutine GridDelete(handle) &
      bind(C, name='GridDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine GridDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function GridRead(handle, filename, filenameSize) &
      bind(C, name='GridRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: GridRead
end function GridRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function GridWrite(handle, filename, filenameSize) &
      bind(C, name='GridWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: GridWrite
end function GridWrite

!! Print to standard output, in our prettyprinting format
function GridPrint(handle) &
      bind(C, name='GridPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridPrint
end function GridPrint

!! Print to standard output, as XML
function GridPrintXML(handle) &
      bind(C, name='GridPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridPrintXML
end function GridPrintXML

!! Print to standard output, as JSON
function GridPrintJSON(handle) &
      bind(C, name='GridPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridPrintJSON
end function GridPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: index
!! -----------------------------------------------------------------------------

!! Has
function GridIndexHas(handle) &
      bind(C, name='GridIndexHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridIndexHas
end function GridIndexHas

!! Get
function GridIndexGet(handle) &
      bind(C, name='GridIndexGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridIndexGet
end function GridIndexGet

!! Set
subroutine GridIndexSet(handle, index) &
      bind(C, name='GridIndexSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: index
end subroutine GridIndexSet


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function GridLabelHas(handle) &
      bind(C, name='GridLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridLabelHas
end function GridLabelHas

!! Get
function GridLabelGet(handle) &
      bind(C, name='GridLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: GridLabelGet
end function GridLabelGet

!! Set
subroutine GridLabelSet(handle, label, labelSize) &
      bind(C, name='GridLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine GridLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: unit
!! -----------------------------------------------------------------------------

!! Has
function GridUnitHas(handle) &
      bind(C, name='GridUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridUnitHas
end function GridUnitHas

!! Get
function GridUnitGet(handle) &
      bind(C, name='GridUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: GridUnitGet
end function GridUnitGet

!! Set
subroutine GridUnitSet(handle, unit, unitSize) &
      bind(C, name='GridUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
end subroutine GridUnitSet


!! -----------------------------------------------------------------------------
!! Metadatum: style
!! -----------------------------------------------------------------------------

!! Has
function GridStyleHas(handle) &
      bind(C, name='GridStyleHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridStyleHas
end function GridStyleHas

!! Get
function GridStyleGet(handle) &
      bind(C, name='GridStyleGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: GridStyleGet
end function GridStyleGet

!! Set
subroutine GridStyleSet(handle, style, styleSize) &
      bind(C, name='GridStyleSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: styleSize
   character(c_char), intent(in) :: style(styleSize)
end subroutine GridStyleSet


!! -----------------------------------------------------------------------------
!! Metadatum: interpolation
!! -----------------------------------------------------------------------------

!! Has
function GridInterpolationHas(handle) &
      bind(C, name='GridInterpolationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridInterpolationHas
end function GridInterpolationHas

!! Get
function GridInterpolationGet(handle) &
      bind(C, name='GridInterpolationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: GridInterpolationGet
end function GridInterpolationGet

!! Set
subroutine GridInterpolationSet(handle, interpolation, interpolationSize) &
      bind(C, name='GridInterpolationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: interpolationSize
   character(c_char), intent(in) :: interpolation(interpolationSize)
end subroutine GridInterpolationSet


!! -----------------------------------------------------------------------------
!! Child: link
!! -----------------------------------------------------------------------------

!! Has
function GridLinkHas(handle) &
      bind(C, name='GridLinkHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridLinkHas
end function GridLinkHas

!! Get, const
function GridLinkGetConst(handle) &
      bind(C, name='GridLinkGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: GridLinkGetConst
end function GridLinkGetConst

!! Get, non-const
function GridLinkGet(handle) &
      bind(C, name='GridLinkGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: GridLinkGet
end function GridLinkGet

!! Set
subroutine GridLinkSet(handle, fieldHandle) &
      bind(C, name='GridLinkSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine GridLinkSet


!! -----------------------------------------------------------------------------
!! Child: values
!! -----------------------------------------------------------------------------

!! Has
function GridValuesHas(handle) &
      bind(C, name='GridValuesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: GridValuesHas
end function GridValuesHas

!! Get, const
function GridValuesGetConst(handle) &
      bind(C, name='GridValuesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: GridValuesGetConst
end function GridValuesGetConst

!! Get, non-const
function GridValuesGet(handle) &
      bind(C, name='GridValuesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: GridValuesGet
end function GridValuesGet

!! Set
subroutine GridValuesSet(handle, fieldHandle) &
      bind(C, name='GridValuesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine GridValuesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalGrid