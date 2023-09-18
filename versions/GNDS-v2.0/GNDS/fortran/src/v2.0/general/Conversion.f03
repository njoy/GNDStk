
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalConversion
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ConversionDefaultConst() &
      bind(C, name='ConversionDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ConversionDefaultConst

!! Create, default
function ConversionDefault() &
      bind(C, name='ConversionDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ConversionDefault

!! Create, general, const
function ConversionCreateConst( &
   flags, &
   href, &
   flagsSize, &
   hrefSize &
) &
      bind(C, name='ConversionCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: flagsSize
   character(c_char), intent(in) :: flags(flagsSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: handle
end function ConversionCreateConst

!! Create, general
function ConversionCreate( &
   flags, &
   href, &
   flagsSize, &
   hrefSize &
) &
      bind(C, name='ConversionCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: flagsSize
   character(c_char), intent(in) :: flags(flagsSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: handle
end function ConversionCreate

!! Assign
subroutine ConversionAssign(handleLHS, handleRHS) &
      bind(C, name='ConversionAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ConversionAssign

!! Delete
subroutine ConversionDelete(handle) &
      bind(C, name='ConversionDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ConversionDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ConversionRead(handle, filename, filenameSize) &
      bind(C, name='ConversionRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ConversionRead

!! Write to file
function ConversionWrite(handle, filename, filenameSize) &
      bind(C, name='ConversionWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ConversionWrite

!! Print to standard output, in our prettyprinting format
function ConversionPrint(handle) &
      bind(C, name='ConversionPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ConversionPrint

!! Print to standard output, as XML
function ConversionPrintXML(handle) &
      bind(C, name='ConversionPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ConversionPrintXML

!! Print to standard output, as JSON
function ConversionPrintJSON(handle) &
      bind(C, name='ConversionPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ConversionPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: flags
!! -----------------------------------------------------------------------------

!! Has
function ConversionFlagsHas(handle) &
      bind(C, name='ConversionFlagsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ConversionFlagsHas

!! Get
function ConversionFlagsGet(handle) &
      bind(C, name='ConversionFlagsGet') &
      result(flags)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: flags
end function ConversionFlagsGet

!! Set
subroutine ConversionFlagsSet(handle, flags, flagsSize) &
      bind(C, name='ConversionFlagsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: flagsSize
   character(c_char), intent(in) :: flags(flagsSize)
end subroutine ConversionFlagsSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function ConversionHrefHas(handle) &
      bind(C, name='ConversionHrefHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ConversionHrefHas

!! Get
function ConversionHrefGet(handle) &
      bind(C, name='ConversionHrefGet') &
      result(href)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: href
end function ConversionHrefGet

!! Set
subroutine ConversionHrefSet(handle, href, hrefSize) &
      bind(C, name='ConversionHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine ConversionHrefSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalConversion
