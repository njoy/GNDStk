
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
      bind(C, name='SCTApproximationDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SCTApproximationDefaultConst
end function SCTApproximationDefaultConst

!! Create, default
function SCTApproximationDefault() &
      bind(C, name='SCTApproximationDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SCTApproximationDefault
end function SCTApproximationDefault

!! Create, general, const
function SCTApproximationCreateConst( &
) &
      bind(C, name='SCTApproximationCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SCTApproximationCreateConst
end function SCTApproximationCreateConst

!! Create, general
function SCTApproximationCreate( &
) &
      bind(C, name='SCTApproximationCreate')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SCTApproximationCreate
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
      bind(C, name='SCTApproximationRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SCTApproximationRead
end function SCTApproximationRead

!! Write to file
function SCTApproximationWrite(handle, filename, filenameSize) &
      bind(C, name='SCTApproximationWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SCTApproximationWrite
end function SCTApproximationWrite

!! Print to standard output, in our prettyprinting format
function SCTApproximationPrint(handle) &
      bind(C, name='SCTApproximationPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SCTApproximationPrint
end function SCTApproximationPrint

!! Print to standard output, as XML
function SCTApproximationPrintXML(handle) &
      bind(C, name='SCTApproximationPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SCTApproximationPrintXML
end function SCTApproximationPrintXML

!! Print to standard output, as JSON
function SCTApproximationPrintJSON(handle) &
      bind(C, name='SCTApproximationPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SCTApproximationPrintJSON
end function SCTApproximationPrintJSON


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSCTApproximation
