
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalColumn
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ColumnDefaultConst() &
      bind(C, name='ColumnDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ColumnDefaultConst
end function ColumnDefaultConst

!! Create, default, non-const
function ColumnDefault() &
      bind(C, name='ColumnDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ColumnDefault
end function ColumnDefault

!! Create, general, const
function ColumnCreateConst( &
   index, &
   name, &
   unit, &
   nameSize, &
   unitSize &
) &
      bind(C, name='ColumnCreateConst')
   use iso_c_binding
   implicit none
   integer(c_int), intent(in), value :: index
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr) :: ColumnCreateConst
end function ColumnCreateConst

!! Create, general, non-const
function ColumnCreate( &
   index, &
   name, &
   unit, &
   nameSize, &
   unitSize &
) &
      bind(C, name='ColumnCreate')
   use iso_c_binding
   implicit none
   integer(c_int), intent(in), value :: index
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
   type(c_ptr) :: ColumnCreate
end function ColumnCreate

!! Assign
subroutine ColumnAssign(handleLHS, handleRHS) &
      bind(C, name='ColumnAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ColumnAssign

!! Delete
subroutine ColumnDelete(handle) &
      bind(C, name='ColumnDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ColumnDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ColumnRead(handle, filename, filenameSize) &
      bind(C, name='ColumnRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ColumnRead
end function ColumnRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ColumnWrite(handle, filename, filenameSize) &
      bind(C, name='ColumnWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ColumnWrite
end function ColumnWrite

!! Print to standard output, in our prettyprinting format
function ColumnPrint(handle) &
      bind(C, name='ColumnPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ColumnPrint
end function ColumnPrint

!! Print to standard output, as XML
function ColumnPrintXML(handle) &
      bind(C, name='ColumnPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ColumnPrintXML
end function ColumnPrintXML

!! Print to standard output, as JSON
function ColumnPrintJSON(handle) &
      bind(C, name='ColumnPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ColumnPrintJSON
end function ColumnPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: index
!! -----------------------------------------------------------------------------

!! Has
function ColumnIndexHas(handle) &
      bind(C, name='ColumnIndexHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ColumnIndexHas
end function ColumnIndexHas

!! Get
function ColumnIndexGet(handle) &
      bind(C, name='ColumnIndexGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ColumnIndexGet
end function ColumnIndexGet

!! Set
subroutine ColumnIndexSet(handle, index) &
      bind(C, name='ColumnIndexSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: index
end subroutine ColumnIndexSet


!! -----------------------------------------------------------------------------
!! Metadatum: name
!! -----------------------------------------------------------------------------

!! Has
function ColumnNameHas(handle) &
      bind(C, name='ColumnNameHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ColumnNameHas
end function ColumnNameHas

!! Get
function ColumnNameGet(handle) &
      bind(C, name='ColumnNameGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ColumnNameGet
end function ColumnNameGet

!! Set
subroutine ColumnNameSet(handle, name, nameSize) &
      bind(C, name='ColumnNameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
end subroutine ColumnNameSet


!! -----------------------------------------------------------------------------
!! Metadatum: unit
!! -----------------------------------------------------------------------------

!! Has
function ColumnUnitHas(handle) &
      bind(C, name='ColumnUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ColumnUnitHas
end function ColumnUnitHas

!! Get
function ColumnUnitGet(handle) &
      bind(C, name='ColumnUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ColumnUnitGet
end function ColumnUnitGet

!! Set
subroutine ColumnUnitSet(handle, unit, unitSize) &
      bind(C, name='ColumnUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: unitSize
   character(c_char), intent(in) :: unit(unitSize)
end subroutine ColumnUnitSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalColumn
