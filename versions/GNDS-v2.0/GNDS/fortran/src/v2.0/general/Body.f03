
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalBody
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function BodyDefaultConst() &
      bind(C, name='BodyDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function BodyDefaultConst

!! Create, default
function BodyDefault() &
      bind(C, name='BodyDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function BodyDefault

!! Create, general, const
function BodyCreateConst( &
) &
      bind(C, name='BodyCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function BodyCreateConst

!! Create, general
function BodyCreate( &
) &
      bind(C, name='BodyCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function BodyCreate

!! Assign
subroutine BodyAssign(handleLHS, handleRHS) &
      bind(C, name='BodyAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine BodyAssign

!! Delete
subroutine BodyDelete(handle) &
      bind(C, name='BodyDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine BodyDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function BodyRead(handle, filename, filenameSize) &
      bind(C, name='BodyRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function BodyRead

!! Write to file
function BodyWrite(handle, filename, filenameSize) &
      bind(C, name='BodyWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function BodyWrite

!! Print to standard output, in our prettyprinting format
function BodyPrint(handle) &
      bind(C, name='BodyPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function BodyPrint

!! Print to standard output, as XML
function BodyPrintXML(handle) &
      bind(C, name='BodyPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function BodyPrintXML

!! Print to standard output, as JSON
function BodyPrintJSON(handle) &
      bind(C, name='BodyPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function BodyPrintJSON


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalBody
