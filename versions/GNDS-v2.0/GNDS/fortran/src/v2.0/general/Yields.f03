
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalYields
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function YieldsDefaultConst() &
      bind(C, name='YieldsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: YieldsDefaultConst
end function YieldsDefaultConst

!! Create, default
function YieldsDefault() &
      bind(C, name='YieldsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: YieldsDefault
end function YieldsDefault

!! Create, general, const
function YieldsCreateConst( &
   nuclides, &
   values, &
   uncertainty &
) &
      bind(C, name='YieldsCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: nuclides
   type(c_ptr), value :: values
   type(c_ptr), value :: uncertainty
   type(c_ptr) :: YieldsCreateConst
end function YieldsCreateConst

!! Create, general
function YieldsCreate( &
   nuclides, &
   values, &
   uncertainty &
) &
      bind(C, name='YieldsCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: nuclides
   type(c_ptr), value :: values
   type(c_ptr), value :: uncertainty
   type(c_ptr) :: YieldsCreate
end function YieldsCreate

!! Assign
subroutine YieldsAssign(handleLHS, handleRHS) &
      bind(C, name='YieldsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine YieldsAssign

!! Delete
subroutine YieldsDelete(handle) &
      bind(C, name='YieldsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine YieldsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function YieldsRead(handle, filename, filenameSize) &
      bind(C, name='YieldsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: YieldsRead
end function YieldsRead

!! Write to file
function YieldsWrite(handle, filename, filenameSize) &
      bind(C, name='YieldsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: YieldsWrite
end function YieldsWrite

!! Print to standard output, in our prettyprinting format
function YieldsPrint(handle) &
      bind(C, name='YieldsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: YieldsPrint
end function YieldsPrint

!! Print to standard output, as XML
function YieldsPrintXML(handle) &
      bind(C, name='YieldsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: YieldsPrintXML
end function YieldsPrintXML

!! Print to standard output, as JSON
function YieldsPrintJSON(handle) &
      bind(C, name='YieldsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: YieldsPrintJSON
end function YieldsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: nuclides
!! -----------------------------------------------------------------------------

!! Has
function YieldsNuclidesHas(handle) &
      bind(C, name='YieldsNuclidesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: YieldsNuclidesHas
end function YieldsNuclidesHas

!! Get, const
function YieldsNuclidesGetConst(handle) &
      bind(C, name='YieldsNuclidesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: YieldsNuclidesGetConst
end function YieldsNuclidesGetConst

!! Get
function YieldsNuclidesGet(handle) &
      bind(C, name='YieldsNuclidesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: YieldsNuclidesGet
end function YieldsNuclidesGet

!! Set
subroutine YieldsNuclidesSet(handle, fieldHandle) &
      bind(C, name='YieldsNuclidesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine YieldsNuclidesSet


!! -----------------------------------------------------------------------------
!! Child: values
!! -----------------------------------------------------------------------------

!! Has
function YieldsValuesHas(handle) &
      bind(C, name='YieldsValuesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: YieldsValuesHas
end function YieldsValuesHas

!! Get, const
function YieldsValuesGetConst(handle) &
      bind(C, name='YieldsValuesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: YieldsValuesGetConst
end function YieldsValuesGetConst

!! Get
function YieldsValuesGet(handle) &
      bind(C, name='YieldsValuesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: YieldsValuesGet
end function YieldsValuesGet

!! Set
subroutine YieldsValuesSet(handle, fieldHandle) &
      bind(C, name='YieldsValuesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine YieldsValuesSet


!! -----------------------------------------------------------------------------
!! Child: uncertainty
!! -----------------------------------------------------------------------------

!! Has
function YieldsUncertaintyHas(handle) &
      bind(C, name='YieldsUncertaintyHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: YieldsUncertaintyHas
end function YieldsUncertaintyHas

!! Get, const
function YieldsUncertaintyGetConst(handle) &
      bind(C, name='YieldsUncertaintyGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: YieldsUncertaintyGetConst
end function YieldsUncertaintyGetConst

!! Get
function YieldsUncertaintyGet(handle) &
      bind(C, name='YieldsUncertaintyGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: YieldsUncertaintyGet
end function YieldsUncertaintyGet

!! Set
subroutine YieldsUncertaintySet(handle, fieldHandle) &
      bind(C, name='YieldsUncertaintySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine YieldsUncertaintySet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalYields
