
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalJ
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function JDefaultConst() &
      bind(C, name='JDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: JDefaultConst
end function JDefaultConst

!! Create, default, non-const
function JDefault() &
      bind(C, name='JDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: JDefault
end function JDefault

!! Create, general, const
function JCreateConst( &
   label, &
   value, &
   levelSpacing, &
   widths, &
   labelSize &
) &
      bind(C, name='JCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), intent(in), value :: value
   type(c_ptr), intent(in), value :: levelSpacing
   type(c_ptr), intent(in), value :: widths
   type(c_ptr) :: JCreateConst
end function JCreateConst

!! Create, general, non-const
function JCreate( &
   label, &
   value, &
   levelSpacing, &
   widths, &
   labelSize &
) &
      bind(C, name='JCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), intent(in), value :: value
   type(c_ptr), intent(in), value :: levelSpacing
   type(c_ptr), intent(in), value :: widths
   type(c_ptr) :: JCreate
end function JCreate

!! Assign
subroutine JAssign(handleLHS, handleRHS) &
      bind(C, name='JAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine JAssign

!! Delete
subroutine JDelete(handle) &
      bind(C, name='JDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine JDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function JRead(handle, filename, filenameSize) &
      bind(C, name='JRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: JRead
end function JRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function JWrite(handle, filename, filenameSize) &
      bind(C, name='JWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: JWrite
end function JWrite

!! Print to standard output, in our prettyprinting format
function JPrint(handle) &
      bind(C, name='JPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JPrint
end function JPrint

!! Print to standard output, as XML
function JPrintXML(handle) &
      bind(C, name='JPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JPrintXML
end function JPrintXML

!! Print to standard output, as JSON
function JPrintJSON(handle) &
      bind(C, name='JPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JPrintJSON
end function JPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function JLabelHas(handle) &
      bind(C, name='JLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JLabelHas
end function JLabelHas

!! Get
function JLabelGet(handle) &
      bind(C, name='JLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: JLabelGet
end function JLabelGet

!! Set
subroutine JLabelSet(handle, label, labelSize) &
      bind(C, name='JLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine JLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: value
!! -----------------------------------------------------------------------------

!! Has
function JValueHas(handle) &
      bind(C, name='JValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JValueHas
end function JValueHas

!! Get
function JValueGet(handle) &
      bind(C, name='JValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JValueGet
end function JValueGet

!! Set
subroutine JValueSet(handle, value) &
      bind(C, name='JValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: value
end subroutine JValueSet


!! -----------------------------------------------------------------------------
!! Child: levelSpacing
!! -----------------------------------------------------------------------------

!! Has
function JLevelSpacingHas(handle) &
      bind(C, name='JLevelSpacingHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JLevelSpacingHas
end function JLevelSpacingHas

!! Get, const
function JLevelSpacingGetConst(handle) &
      bind(C, name='JLevelSpacingGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: JLevelSpacingGetConst
end function JLevelSpacingGetConst

!! Get, non-const
function JLevelSpacingGet(handle) &
      bind(C, name='JLevelSpacingGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: JLevelSpacingGet
end function JLevelSpacingGet

!! Set
subroutine JLevelSpacingSet(handle, fieldHandle) &
      bind(C, name='JLevelSpacingSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine JLevelSpacingSet


!! -----------------------------------------------------------------------------
!! Child: widths
!! -----------------------------------------------------------------------------

!! Has
function JWidthsHas(handle) &
      bind(C, name='JWidthsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: JWidthsHas
end function JWidthsHas

!! Get, const
function JWidthsGetConst(handle) &
      bind(C, name='JWidthsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: JWidthsGetConst
end function JWidthsGetConst

!! Get, non-const
function JWidthsGet(handle) &
      bind(C, name='JWidthsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: JWidthsGet
end function JWidthsGet

!! Set
subroutine JWidthsSet(handle, fieldHandle) &
      bind(C, name='JWidthsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine JWidthsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalJ