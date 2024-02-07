
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module containersAxes
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AxesDefaultConst() &
      bind(C, name='AxesDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AxesDefaultConst
end function AxesDefaultConst

!! Create, default
function AxesDefault() &
      bind(C, name='AxesDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AxesDefault
end function AxesDefault

!! Create, general, const
function AxesCreateConst( &
   href, &
   hrefSize &
) &
      bind(C, name='AxesCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: AxesCreateConst
end function AxesCreateConst

!! Create, general
function AxesCreate( &
   href, &
   hrefSize &
) &
      bind(C, name='AxesCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: AxesCreate
end function AxesCreate

!! Assign
subroutine AxesAssign(handleLHS, handleRHS) &
      bind(C, name='AxesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine AxesAssign

!! Delete
subroutine AxesDelete(handle) &
      bind(C, name='AxesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AxesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function AxesRead(handle, filename, filenameSize) &
      bind(C, name='AxesRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AxesRead
end function AxesRead

!! Write to file
function AxesWrite(handle, filename, filenameSize) &
      bind(C, name='AxesWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AxesWrite
end function AxesWrite

!! Print to standard output, in our prettyprinting format
function AxesPrint(handle) &
      bind(C, name='AxesPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AxesPrint
end function AxesPrint

!! Print to standard output, as XML
function AxesPrintXML(handle) &
      bind(C, name='AxesPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AxesPrintXML
end function AxesPrintXML

!! Print to standard output, as JSON
function AxesPrintJSON(handle) &
      bind(C, name='AxesPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AxesPrintJSON
end function AxesPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function AxesHrefHas(handle) &
      bind(C, name='AxesHrefHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AxesHrefHas
end function AxesHrefHas

!! Get
function AxesHrefGet(handle) &
      bind(C, name='AxesHrefGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AxesHrefGet
end function AxesHrefGet

!! Set
subroutine AxesHrefSet(handle, href, hrefSize) &
      bind(C, name='AxesHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine AxesHrefSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module containersAxes