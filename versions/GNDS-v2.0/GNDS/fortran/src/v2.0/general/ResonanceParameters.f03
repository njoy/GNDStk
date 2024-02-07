
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalResonanceParameters
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ResonanceParametersDefaultConst() &
      bind(C, name='ResonanceParametersDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ResonanceParametersDefaultConst
end function ResonanceParametersDefaultConst

!! Create, default, non-const
function ResonanceParametersDefault() &
      bind(C, name='ResonanceParametersDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ResonanceParametersDefault
end function ResonanceParametersDefault

!! Create, general, const
function ResonanceParametersCreateConst( &
   table &
) &
      bind(C, name='ResonanceParametersCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: table
   type(c_ptr) :: ResonanceParametersCreateConst
end function ResonanceParametersCreateConst

!! Create, general, non-const
function ResonanceParametersCreate( &
   table &
) &
      bind(C, name='ResonanceParametersCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: table
   type(c_ptr) :: ResonanceParametersCreate
end function ResonanceParametersCreate

!! Assign
subroutine ResonanceParametersAssign(handleLHS, handleRHS) &
      bind(C, name='ResonanceParametersAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ResonanceParametersAssign

!! Delete
subroutine ResonanceParametersDelete(handle) &
      bind(C, name='ResonanceParametersDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ResonanceParametersDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ResonanceParametersRead(handle, filename, filenameSize) &
      bind(C, name='ResonanceParametersRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ResonanceParametersRead
end function ResonanceParametersRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ResonanceParametersWrite(handle, filename, filenameSize) &
      bind(C, name='ResonanceParametersWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ResonanceParametersWrite
end function ResonanceParametersWrite

!! Print to standard output, in our prettyprinting format
function ResonanceParametersPrint(handle) &
      bind(C, name='ResonanceParametersPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceParametersPrint
end function ResonanceParametersPrint

!! Print to standard output, as XML
function ResonanceParametersPrintXML(handle) &
      bind(C, name='ResonanceParametersPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceParametersPrintXML
end function ResonanceParametersPrintXML

!! Print to standard output, as JSON
function ResonanceParametersPrintJSON(handle) &
      bind(C, name='ResonanceParametersPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceParametersPrintJSON
end function ResonanceParametersPrintJSON


!! -----------------------------------------------------------------------------
!! Child: table
!! -----------------------------------------------------------------------------

!! Has
function ResonanceParametersTableHas(handle) &
      bind(C, name='ResonanceParametersTableHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResonanceParametersTableHas
end function ResonanceParametersTableHas

!! Get, const
function ResonanceParametersTableGetConst(handle) &
      bind(C, name='ResonanceParametersTableGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ResonanceParametersTableGetConst
end function ResonanceParametersTableGetConst

!! Get, non-const
function ResonanceParametersTableGet(handle) &
      bind(C, name='ResonanceParametersTableGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ResonanceParametersTableGet
end function ResonanceParametersTableGet

!! Set
subroutine ResonanceParametersTableSet(handle, fieldHandle) &
      bind(C, name='ResonanceParametersTableSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResonanceParametersTableSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalResonanceParameters