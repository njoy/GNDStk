
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalData
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DataDefaultConst() &
      bind(C, name='DataDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DataDefaultConst
end function DataDefaultConst

!! Create, default
function DataDefault() &
      bind(C, name='DataDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DataDefault
end function DataDefault

!! Create, general, const
function DataCreateConst( &
) &
      bind(C, name='DataCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DataCreateConst
end function DataCreateConst

!! Create, general
function DataCreate( &
) &
      bind(C, name='DataCreate')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DataCreate
end function DataCreate

!! Assign
subroutine DataAssign(handleLHS, handleRHS) &
      bind(C, name='DataAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine DataAssign

!! Delete
subroutine DataDelete(handle) &
      bind(C, name='DataDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DataDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function DataRead(handle, filename, filenameSize) &
      bind(C, name='DataRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DataRead
end function DataRead

!! Write to file
function DataWrite(handle, filename, filenameSize) &
      bind(C, name='DataWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DataWrite
end function DataWrite

!! Print to standard output, in our prettyprinting format
function DataPrint(handle) &
      bind(C, name='DataPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DataPrint
end function DataPrint

!! Print to standard output, as XML
function DataPrintXML(handle) &
      bind(C, name='DataPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DataPrintXML
end function DataPrintXML

!! Print to standard output, as JSON
function DataPrintJSON(handle) &
      bind(C, name='DataPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DataPrintJSON
end function DataPrintJSON


!! -----------------------------------------------------------------------------
!! Data vector
!! -----------------------------------------------------------------------------

!! Clear
subroutine DataDoublesClear(handle) &
      bind(C, name='DataDoublesClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DataDoublesClear

!! Get size
function DataDoublesSize(handle) &
      bind(C, name='DataDoublesSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: DataDoublesSize
end function DataDoublesSize

!! Get value
!! By index \in [0,size)
function DataDoublesGet(handle, arrayIndex) &
      bind(C, name='DataDoublesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_double) :: DataDoublesGet
end function DataDoublesGet

!! Set value
!! By index \in [0,size)
subroutine DataDoublesSet(handle, arrayIndex, valueAtIndex) &
      bind(C, name='DataDoublesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_double), intent(in), value :: valueAtIndex
end subroutine DataDoublesSet

!! Get pointer to existing values, const
function DataDoublesGetArrayConst(handle) &
      bind(C, name='DataDoublesGetArrayConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DataDoublesGetArrayConst
end function DataDoublesGetArrayConst

!! Get pointer to existing values
function DataDoublesGetArray(handle) &
      bind(C, name='DataDoublesGetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DataDoublesGetArray
end function DataDoublesGetArray

!! Set completely new values and size
subroutine DataDoublesSetArray(handle, values, valuesSize) &
      bind(C, name='DataDoublesSetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: valuesSize
   real(c_double), intent(in) :: values(valuesSize)
end subroutine DataDoublesSetArray


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalData
