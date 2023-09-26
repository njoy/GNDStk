
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSCTApproximation
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SCTApproximationDefaultConst() &
      bind(C, name='SCTApproximationDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function SCTApproximationDefaultConst

!! Create, default
function SCTApproximationDefault() &
      bind(C, name='SCTApproximationDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function SCTApproximationDefault

!! Create, general, const
function SCTApproximationCreateConst( &
) &
      bind(C, name='SCTApproximationCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function SCTApproximationCreateConst

!! Create, general
function SCTApproximationCreate( &
) &
      bind(C, name='SCTApproximationCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function SCTApproximationCreate

!! Assign
subroutine SCTApproximationAssign(handleLHS, handleRHS) &
      bind(C, name='SCTApproximationAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine SCTApproximationAssign

!! Delete
subroutine SCTApproximationDelete(handle) &
      bind(C, name='SCTApproximationDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SCTApproximationDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SCTApproximationRead(handle, filename, filenameSize) &
      bind(C, name='SCTApproximationRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function SCTApproximationRead

!! Write to file
function SCTApproximationWrite(handle, filename, filenameSize) &
      bind(C, name='SCTApproximationWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function SCTApproximationWrite

!! Print to standard output, in our prettyprinting format
function SCTApproximationPrint(handle) &
      bind(C, name='SCTApproximationPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function SCTApproximationPrint

!! Print to standard output, as XML
function SCTApproximationPrintXML(handle) &
      bind(C, name='SCTApproximationPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function SCTApproximationPrintXML

!! Print to standard output, as JSON
function SCTApproximationPrintJSON(handle) &
      bind(C, name='SCTApproximationPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function SCTApproximationPrintJSON


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSCTApproximation
