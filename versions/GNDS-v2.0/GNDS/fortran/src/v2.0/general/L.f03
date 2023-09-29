
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalL
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function LDefaultConst() &
      bind(C, name='LDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LDefaultConst
end function LDefaultConst

!! Create, default, non-const
function LDefault() &
      bind(C, name='LDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LDefault
end function LDefault

!! Create, general, const
function LCreateConst( &
   label, &
   value, &
   Js, &
   labelSize &
) &
      bind(C, name='LCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), intent(in), value :: value
   type(c_ptr), intent(in), value :: Js
   type(c_ptr) :: LCreateConst
end function LCreateConst

!! Create, general, non-const
function LCreate( &
   label, &
   value, &
   Js, &
   labelSize &
) &
      bind(C, name='LCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), intent(in), value :: value
   type(c_ptr), intent(in), value :: Js
   type(c_ptr) :: LCreate
end function LCreate

!! Assign
subroutine LAssign(handleLHS, handleRHS) &
      bind(C, name='LAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine LAssign

!! Delete
subroutine LDelete(handle) &
      bind(C, name='LDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine LDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function LRead(handle, filename, filenameSize) &
      bind(C, name='LRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LRead
end function LRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function LWrite(handle, filename, filenameSize) &
      bind(C, name='LWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LWrite
end function LWrite

!! Print to standard output, in our prettyprinting format
function LPrint(handle) &
      bind(C, name='LPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LPrint
end function LPrint

!! Print to standard output, as XML
function LPrintXML(handle) &
      bind(C, name='LPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LPrintXML
end function LPrintXML

!! Print to standard output, as JSON
function LPrintJSON(handle) &
      bind(C, name='LPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LPrintJSON
end function LPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function LLabelHas(handle) &
      bind(C, name='LLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LLabelHas
end function LLabelHas

!! Get
function LLabelGet(handle) &
      bind(C, name='LLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LLabelGet
end function LLabelGet

!! Set
subroutine LLabelSet(handle, label, labelSize) &
      bind(C, name='LLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine LLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: value
!! -----------------------------------------------------------------------------

!! Has
function LValueHas(handle) &
      bind(C, name='LValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LValueHas
end function LValueHas

!! Get
function LValueGet(handle) &
      bind(C, name='LValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LValueGet
end function LValueGet

!! Set
subroutine LValueSet(handle, value) &
      bind(C, name='LValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: value
end subroutine LValueSet


!! -----------------------------------------------------------------------------
!! Child: Js
!! -----------------------------------------------------------------------------

!! Has
function LJsHas(handle) &
      bind(C, name='LJsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LJsHas
end function LJsHas

!! Get, const
function LJsGetConst(handle) &
      bind(C, name='LJsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LJsGetConst
end function LJsGetConst

!! Get, non-const
function LJsGet(handle) &
      bind(C, name='LJsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: LJsGet
end function LJsGet

!! Set
subroutine LJsSet(handle, fieldHandle) &
      bind(C, name='LJsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine LJsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalL
