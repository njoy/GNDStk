
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalRecoil
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function RecoilDefaultConst() &
      bind(C, name='RecoilDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: RecoilDefaultConst
end function RecoilDefaultConst

!! Create, default
function RecoilDefault() &
      bind(C, name='RecoilDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: RecoilDefault
end function RecoilDefault

!! Create, general, const
function RecoilCreateConst( &
   href, &
   hrefSize &
) &
      bind(C, name='RecoilCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: RecoilCreateConst
end function RecoilCreateConst

!! Create, general
function RecoilCreate( &
   href, &
   hrefSize &
) &
      bind(C, name='RecoilCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: RecoilCreate
end function RecoilCreate

!! Assign
subroutine RecoilAssign(handleLHS, handleRHS) &
      bind(C, name='RecoilAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine RecoilAssign

!! Delete
subroutine RecoilDelete(handle) &
      bind(C, name='RecoilDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine RecoilDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function RecoilRead(handle, filename, filenameSize) &
      bind(C, name='RecoilRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: RecoilRead
end function RecoilRead

!! Write to file
function RecoilWrite(handle, filename, filenameSize) &
      bind(C, name='RecoilWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: RecoilWrite
end function RecoilWrite

!! Print to standard output, in our prettyprinting format
function RecoilPrint(handle) &
      bind(C, name='RecoilPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RecoilPrint
end function RecoilPrint

!! Print to standard output, as XML
function RecoilPrintXML(handle) &
      bind(C, name='RecoilPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RecoilPrintXML
end function RecoilPrintXML

!! Print to standard output, as JSON
function RecoilPrintJSON(handle) &
      bind(C, name='RecoilPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RecoilPrintJSON
end function RecoilPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function RecoilHrefHas(handle) &
      bind(C, name='RecoilHrefHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RecoilHrefHas
end function RecoilHrefHas

!! Get
function RecoilHrefGet(handle) &
      bind(C, name='RecoilHrefGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: RecoilHrefGet
end function RecoilHrefGet

!! Set
subroutine RecoilHrefSet(handle, href, hrefSize) &
      bind(C, name='RecoilHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine RecoilHrefSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalRecoil
