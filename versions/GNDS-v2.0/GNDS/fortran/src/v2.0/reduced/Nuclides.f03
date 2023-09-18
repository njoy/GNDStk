
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module reducedNuclides
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function NuclidesDefaultConst() &
      bind(C, name='NuclidesDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function NuclidesDefaultConst

!! Create, default
function NuclidesDefault() &
      bind(C, name='NuclidesDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function NuclidesDefault

!! Create, general, const
function NuclidesCreateConst( &
   href, &
   hrefSize &
) &
      bind(C, name='NuclidesCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: handle
end function NuclidesCreateConst

!! Create, general
function NuclidesCreate( &
   href, &
   hrefSize &
) &
      bind(C, name='NuclidesCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: handle
end function NuclidesCreate

!! Assign
subroutine NuclidesAssign(handleLHS, handleRHS) &
      bind(C, name='NuclidesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine NuclidesAssign

!! Delete
subroutine NuclidesDelete(handle) &
      bind(C, name='NuclidesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine NuclidesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function NuclidesRead(handle, filename, filenameSize) &
      bind(C, name='NuclidesRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function NuclidesRead

!! Write to file
function NuclidesWrite(handle, filename, filenameSize) &
      bind(C, name='NuclidesWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function NuclidesWrite

!! Print to standard output, in our prettyprinting format
function NuclidesPrint(handle) &
      bind(C, name='NuclidesPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NuclidesPrint

!! Print to standard output, as XML
function NuclidesPrintXML(handle) &
      bind(C, name='NuclidesPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NuclidesPrintXML

!! Print to standard output, as JSON
function NuclidesPrintJSON(handle) &
      bind(C, name='NuclidesPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NuclidesPrintJSON


!! -----------------------------------------------------------------------------
!! Data vector
!! -----------------------------------------------------------------------------

!! Clear
subroutine NuclidesStd::stringsClear(handle) &
      bind(C, name='NuclidesStd::stringsClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine NuclidesStd::stringsClear

!! Get size
function NuclidesStd::stringsSize(handle) &
      bind(C, name='NuclidesStd::stringsSize') &
      result(arraySize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: arraySize
end function NuclidesStd::stringsSize

!! Get value
!! By index \in [0,size)
function NuclidesStd::stringsGet(handle, arrayIndex) &
      bind(C, name='NuclidesStd::stringsGet') &
      result(valueAtIndex)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_std::string) :: valueAtIndex
end function NuclidesStd::stringsGet

!! Set value
!! By index \in [0,size)
subroutine NuclidesStd::stringsSet(handle, arrayIndex, valueAtIndex) &
      bind(C, name='NuclidesStd::stringsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: arrayIndex
   real(c_std::string), intent(in), value :: valueAtIndex
end subroutine NuclidesStd::stringsSet

!! Get pointer to existing values, const
function NuclidesStd::stringsGetArrayConst(handle) &
      bind(C, name='NuclidesStd::stringsGetArrayConst') &
      result(ptrToArray)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ptrToArray
end function NuclidesStd::stringsGetArrayConst

!! Get pointer to existing values
function NuclidesStd::stringsGetArray(handle) &
      bind(C, name='NuclidesStd::stringsGetArray') &
      result(ptrToArray)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ptrToArray
end function NuclidesStd::stringsGetArray

!! Set completely new values and size
subroutine NuclidesStd::stringsSetArray(handle, values, valuesSize) &
      bind(C, name='NuclidesStd::stringsSetArray')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: valuesSize
   real(c_std::string), intent(in) :: values(valuesSize)
end subroutine NuclidesStd::stringsSetArray


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function NuclidesHrefHas(handle) &
      bind(C, name='NuclidesHrefHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function NuclidesHrefHas

!! Get
function NuclidesHrefGet(handle) &
      bind(C, name='NuclidesHrefGet') &
      result(href)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: href
end function NuclidesHrefGet

!! Set
subroutine NuclidesHrefSet(handle, href, hrefSize) &
      bind(C, name='NuclidesHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine NuclidesHrefSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module reducedNuclides
