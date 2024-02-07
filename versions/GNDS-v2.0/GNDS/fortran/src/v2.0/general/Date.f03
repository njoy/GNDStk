
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalDate
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DateDefaultConst() &
      bind(C, name='DateDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DateDefaultConst
end function DateDefaultConst

!! Create, default, non-const
function DateDefault() &
      bind(C, name='DateDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DateDefault
end function DateDefault

!! Create, general, const
function DateCreateConst( &
   value, &
   dateType, &
   valueSize, &
   dateTypeSize &
) &
      bind(C, name='DateCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
   integer(c_size_t), intent(in), value :: dateTypeSize
   character(c_char), intent(in) :: dateType(dateTypeSize)
   type(c_ptr) :: DateCreateConst
end function DateCreateConst

!! Create, general, non-const
function DateCreate( &
   value, &
   dateType, &
   valueSize, &
   dateTypeSize &
) &
      bind(C, name='DateCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
   integer(c_size_t), intent(in), value :: dateTypeSize
   character(c_char), intent(in) :: dateType(dateTypeSize)
   type(c_ptr) :: DateCreate
end function DateCreate

!! Assign
subroutine DateAssign(handleLHS, handleRHS) &
      bind(C, name='DateAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine DateAssign

!! Delete
subroutine DateDelete(handle) &
      bind(C, name='DateDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DateDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function DateRead(handle, filename, filenameSize) &
      bind(C, name='DateRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DateRead
end function DateRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function DateWrite(handle, filename, filenameSize) &
      bind(C, name='DateWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DateWrite
end function DateWrite

!! Print to standard output, in our prettyprinting format
function DatePrint(handle) &
      bind(C, name='DatePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DatePrint
end function DatePrint

!! Print to standard output, as XML
function DatePrintXML(handle) &
      bind(C, name='DatePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DatePrintXML
end function DatePrintXML

!! Print to standard output, as JSON
function DatePrintJSON(handle) &
      bind(C, name='DatePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DatePrintJSON
end function DatePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: value
!! -----------------------------------------------------------------------------

!! Has
function DateValueHas(handle) &
      bind(C, name='DateValueHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DateValueHas
end function DateValueHas

!! Get
function DateValueGet(handle) &
      bind(C, name='DateValueGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DateValueGet
end function DateValueGet

!! Set
subroutine DateValueSet(handle, value, valueSize) &
      bind(C, name='DateValueSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: valueSize
   character(c_char), intent(in) :: value(valueSize)
end subroutine DateValueSet


!! -----------------------------------------------------------------------------
!! Metadatum: dateType
!! -----------------------------------------------------------------------------

!! Has
function DateDateTypeHas(handle) &
      bind(C, name='DateDateTypeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DateDateTypeHas
end function DateDateTypeHas

!! Get
function DateDateTypeGet(handle) &
      bind(C, name='DateDateTypeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DateDateTypeGet
end function DateDateTypeGet

!! Set
subroutine DateDateTypeSet(handle, dateType, dateTypeSize) &
      bind(C, name='DateDateTypeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: dateTypeSize
   character(c_char), intent(in) :: dateType(dateTypeSize)
end subroutine DateDateTypeSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalDate