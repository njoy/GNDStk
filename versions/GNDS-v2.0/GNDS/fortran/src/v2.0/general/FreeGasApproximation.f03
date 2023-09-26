
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalFreeGasApproximation
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function FreeGasApproximationDefaultConst() &
      bind(C, name='FreeGasApproximationDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function FreeGasApproximationDefaultConst

!! Create, default
function FreeGasApproximationDefault() &
      bind(C, name='FreeGasApproximationDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function FreeGasApproximationDefault

!! Create, general, const
function FreeGasApproximationCreateConst( &
) &
      bind(C, name='FreeGasApproximationCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function FreeGasApproximationCreateConst

!! Create, general
function FreeGasApproximationCreate( &
) &
      bind(C, name='FreeGasApproximationCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function FreeGasApproximationCreate

!! Assign
subroutine FreeGasApproximationAssign(handleLHS, handleRHS) &
      bind(C, name='FreeGasApproximationAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine FreeGasApproximationAssign

!! Delete
subroutine FreeGasApproximationDelete(handle) &
      bind(C, name='FreeGasApproximationDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine FreeGasApproximationDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function FreeGasApproximationRead(handle, filename, filenameSize) &
      bind(C, name='FreeGasApproximationRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function FreeGasApproximationRead

!! Write to file
function FreeGasApproximationWrite(handle, filename, filenameSize) &
      bind(C, name='FreeGasApproximationWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function FreeGasApproximationWrite

!! Print to standard output, in our prettyprinting format
function FreeGasApproximationPrint(handle) &
      bind(C, name='FreeGasApproximationPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function FreeGasApproximationPrint

!! Print to standard output, as XML
function FreeGasApproximationPrintXML(handle) &
      bind(C, name='FreeGasApproximationPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function FreeGasApproximationPrintXML

!! Print to standard output, as JSON
function FreeGasApproximationPrintJSON(handle) &
      bind(C, name='FreeGasApproximationPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function FreeGasApproximationPrintJSON


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalFreeGasApproximation
