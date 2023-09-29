
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalStandard
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function StandardDefaultConst() &
      bind(C, name='StandardDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: StandardDefaultConst
end function StandardDefaultConst

!! Create, default
function StandardDefault() &
      bind(C, name='StandardDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: StandardDefault
end function StandardDefault

!! Create, general, const
function StandardCreateConst( &
   Double &
) &
      bind(C, name='StandardCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: Double
   type(c_ptr) :: StandardCreateConst
end function StandardCreateConst

!! Create, general
function StandardCreate( &
   Double &
) &
      bind(C, name='StandardCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: Double
   type(c_ptr) :: StandardCreate
end function StandardCreate

!! Assign
subroutine StandardAssign(handleLHS, handleRHS) &
      bind(C, name='StandardAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine StandardAssign

!! Delete
subroutine StandardDelete(handle) &
      bind(C, name='StandardDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine StandardDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function StandardRead(handle, filename, filenameSize) &
      bind(C, name='StandardRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: StandardRead
end function StandardRead

!! Write to file
function StandardWrite(handle, filename, filenameSize) &
      bind(C, name='StandardWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: StandardWrite
end function StandardWrite

!! Print to standard output, in our prettyprinting format
function StandardPrint(handle) &
      bind(C, name='StandardPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StandardPrint
end function StandardPrint

!! Print to standard output, as XML
function StandardPrintXML(handle) &
      bind(C, name='StandardPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StandardPrintXML
end function StandardPrintXML

!! Print to standard output, as JSON
function StandardPrintJSON(handle) &
      bind(C, name='StandardPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StandardPrintJSON
end function StandardPrintJSON


!! -----------------------------------------------------------------------------
!! Child: Double
!! -----------------------------------------------------------------------------

!! Has
function StandardDoubleHas(handle) &
      bind(C, name='StandardDoubleHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: StandardDoubleHas
end function StandardDoubleHas

!! Get, const
function StandardDoubleGetConst(handle) &
      bind(C, name='StandardDoubleGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: StandardDoubleGetConst
end function StandardDoubleGetConst

!! Get
function StandardDoubleGet(handle) &
      bind(C, name='StandardDoubleGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: StandardDoubleGet
end function StandardDoubleGet

!! Set
subroutine StandardDoubleSet(handle, fieldHandle) &
      bind(C, name='StandardDoubleSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine StandardDoubleSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalStandard
