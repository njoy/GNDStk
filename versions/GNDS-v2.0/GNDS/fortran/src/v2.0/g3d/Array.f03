
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module g3dArray
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ArrayDefaultConst() &
      bind(C, name='ArrayDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ArrayDefaultConst

!! Create, default
function ArrayDefault() &
      bind(C, name='ArrayDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ArrayDefault

!! Create, general, const
function ArrayCreateConst( &
   shape, &
   compression, &
   symmetry, &
   starts, &
   lengths, &
   values, &
   shapeSize, &
   compressionSize, &
   symmetrySize &
) &
      bind(C, name='ArrayCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: shapeSize
   character(c_char), intent(in) :: shape(shapeSize)
   integer(c_size_t), intent(in), value :: compressionSize
   character(c_char), intent(in) :: compression(compressionSize)
   integer(c_size_t), intent(in), value :: symmetrySize
   character(c_char), intent(in) :: symmetry(symmetrySize)
   type(c_ptr), value :: starts
   type(c_ptr), value :: lengths
   type(c_ptr), value :: values
   type(c_ptr) :: handle
end function ArrayCreateConst

!! Create, general
function ArrayCreate( &
   shape, &
   compression, &
   symmetry, &
   starts, &
   lengths, &
   values, &
   shapeSize, &
   compressionSize, &
   symmetrySize &
) &
      bind(C, name='ArrayCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: shapeSize
   character(c_char), intent(in) :: shape(shapeSize)
   integer(c_size_t), intent(in), value :: compressionSize
   character(c_char), intent(in) :: compression(compressionSize)
   integer(c_size_t), intent(in), value :: symmetrySize
   character(c_char), intent(in) :: symmetry(symmetrySize)
   type(c_ptr), value :: starts
   type(c_ptr), value :: lengths
   type(c_ptr), value :: values
   type(c_ptr) :: handle
end function ArrayCreate

!! Assign
subroutine ArrayAssign(handleLHS, handleRHS) &
      bind(C, name='ArrayAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ArrayAssign

!! Delete
subroutine ArrayDelete(handle) &
      bind(C, name='ArrayDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ArrayDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ArrayRead(handle, filename, filenameSize) &
      bind(C, name='ArrayRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ArrayRead

!! Write to file
function ArrayWrite(handle, filename, filenameSize) &
      bind(C, name='ArrayWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ArrayWrite

!! Print to standard output, in our prettyprinting format
function ArrayPrint(handle) &
      bind(C, name='ArrayPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ArrayPrint

!! Print to standard output, as XML
function ArrayPrintXML(handle) &
      bind(C, name='ArrayPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ArrayPrintXML

!! Print to standard output, as JSON
function ArrayPrintJSON(handle) &
      bind(C, name='ArrayPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ArrayPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: shape
!! -----------------------------------------------------------------------------

!! Has
function ArrayShapeHas(handle) &
      bind(C, name='ArrayShapeHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ArrayShapeHas

!! Get
function ArrayShapeGet(handle) &
      bind(C, name='ArrayShapeGet') &
      result(shape)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: shape
end function ArrayShapeGet

!! Set
subroutine ArrayShapeSet(handle, shape, shapeSize) &
      bind(C, name='ArrayShapeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: shapeSize
   character(c_char), intent(in) :: shape(shapeSize)
end subroutine ArrayShapeSet


!! -----------------------------------------------------------------------------
!! Metadatum: compression
!! -----------------------------------------------------------------------------

!! Has
function ArrayCompressionHas(handle) &
      bind(C, name='ArrayCompressionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ArrayCompressionHas

!! Get
function ArrayCompressionGet(handle) &
      bind(C, name='ArrayCompressionGet') &
      result(compression)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: compression
end function ArrayCompressionGet

!! Set
subroutine ArrayCompressionSet(handle, compression, compressionSize) &
      bind(C, name='ArrayCompressionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: compressionSize
   character(c_char), intent(in) :: compression(compressionSize)
end subroutine ArrayCompressionSet


!! -----------------------------------------------------------------------------
!! Metadatum: symmetry
!! -----------------------------------------------------------------------------

!! Has
function ArraySymmetryHas(handle) &
      bind(C, name='ArraySymmetryHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ArraySymmetryHas

!! Get
function ArraySymmetryGet(handle) &
      bind(C, name='ArraySymmetryGet') &
      result(symmetry)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: symmetry
end function ArraySymmetryGet

!! Set
subroutine ArraySymmetrySet(handle, symmetry, symmetrySize) &
      bind(C, name='ArraySymmetrySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: symmetrySize
   character(c_char), intent(in) :: symmetry(symmetrySize)
end subroutine ArraySymmetrySet


!! -----------------------------------------------------------------------------
!! Child: starts
!! -----------------------------------------------------------------------------

!! Has
function ArrayStartsHas(handle) &
      bind(C, name='ArrayStartsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ArrayStartsHas

!! Get, const
function ArrayStartsGetConst(handle) &
      bind(C, name='ArrayStartsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ArrayStartsGetConst

!! Get
function ArrayStartsGet(handle) &
      bind(C, name='ArrayStartsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ArrayStartsGet

!! Set
subroutine ArrayStartsSet(handle, fieldHandle) &
      bind(C, name='ArrayStartsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ArrayStartsSet


!! -----------------------------------------------------------------------------
!! Child: lengths
!! -----------------------------------------------------------------------------

!! Has
function ArrayLengthsHas(handle) &
      bind(C, name='ArrayLengthsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ArrayLengthsHas

!! Get, const
function ArrayLengthsGetConst(handle) &
      bind(C, name='ArrayLengthsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ArrayLengthsGetConst

!! Get
function ArrayLengthsGet(handle) &
      bind(C, name='ArrayLengthsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ArrayLengthsGet

!! Set
subroutine ArrayLengthsSet(handle, fieldHandle) &
      bind(C, name='ArrayLengthsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ArrayLengthsSet


!! -----------------------------------------------------------------------------
!! Child: values
!! -----------------------------------------------------------------------------

!! Has
function ArrayValuesHas(handle) &
      bind(C, name='ArrayValuesHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ArrayValuesHas

!! Get, const
function ArrayValuesGetConst(handle) &
      bind(C, name='ArrayValuesGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ArrayValuesGetConst

!! Get
function ArrayValuesGet(handle) &
      bind(C, name='ArrayValuesGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ArrayValuesGet

!! Set
subroutine ArrayValuesSet(handle, fieldHandle) &
      bind(C, name='ArrayValuesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ArrayValuesSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module g3dArray
