
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalDelayedNeutron
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DelayedNeutronDefaultConst() &
      bind(C, name='DelayedNeutronDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DelayedNeutronDefaultConst
end function DelayedNeutronDefaultConst

!! Create, default
function DelayedNeutronDefault() &
      bind(C, name='DelayedNeutronDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DelayedNeutronDefault
end function DelayedNeutronDefault

!! Create, general, const
function DelayedNeutronCreateConst( &
   label, &
   rate, &
   product, &
   labelSize &
) &
      bind(C, name='DelayedNeutronCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr), intent(in), value :: rate
   type(c_ptr), intent(in), value :: product
   type(c_ptr) :: DelayedNeutronCreateConst
end function DelayedNeutronCreateConst

!! Create, general
function DelayedNeutronCreate( &
   label, &
   rate, &
   product, &
   labelSize &
) &
      bind(C, name='DelayedNeutronCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr), intent(in), value :: rate
   type(c_ptr), intent(in), value :: product
   type(c_ptr) :: DelayedNeutronCreate
end function DelayedNeutronCreate

!! Assign
subroutine DelayedNeutronAssign(handleLHS, handleRHS) &
      bind(C, name='DelayedNeutronAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine DelayedNeutronAssign

!! Delete
subroutine DelayedNeutronDelete(handle) &
      bind(C, name='DelayedNeutronDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DelayedNeutronDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function DelayedNeutronRead(handle, filename, filenameSize) &
      bind(C, name='DelayedNeutronRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DelayedNeutronRead
end function DelayedNeutronRead

!! Write to file
function DelayedNeutronWrite(handle, filename, filenameSize) &
      bind(C, name='DelayedNeutronWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DelayedNeutronWrite
end function DelayedNeutronWrite

!! Print to standard output, in our prettyprinting format
function DelayedNeutronPrint(handle) &
      bind(C, name='DelayedNeutronPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronPrint
end function DelayedNeutronPrint

!! Print to standard output, as XML
function DelayedNeutronPrintXML(handle) &
      bind(C, name='DelayedNeutronPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronPrintXML
end function DelayedNeutronPrintXML

!! Print to standard output, as JSON
function DelayedNeutronPrintJSON(handle) &
      bind(C, name='DelayedNeutronPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronPrintJSON
end function DelayedNeutronPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function DelayedNeutronLabelHas(handle) &
      bind(C, name='DelayedNeutronLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronLabelHas
end function DelayedNeutronLabelHas

!! Get
function DelayedNeutronLabelGet(handle) &
      bind(C, name='DelayedNeutronLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DelayedNeutronLabelGet
end function DelayedNeutronLabelGet

!! Set
subroutine DelayedNeutronLabelSet(handle, label, labelSize) &
      bind(C, name='DelayedNeutronLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine DelayedNeutronLabelSet


!! -----------------------------------------------------------------------------
!! Child: rate
!! -----------------------------------------------------------------------------

!! Has
function DelayedNeutronRateHas(handle) &
      bind(C, name='DelayedNeutronRateHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronRateHas
end function DelayedNeutronRateHas

!! Get, const
function DelayedNeutronRateGetConst(handle) &
      bind(C, name='DelayedNeutronRateGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DelayedNeutronRateGetConst
end function DelayedNeutronRateGetConst

!! Get
function DelayedNeutronRateGet(handle) &
      bind(C, name='DelayedNeutronRateGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DelayedNeutronRateGet
end function DelayedNeutronRateGet

!! Set
subroutine DelayedNeutronRateSet(handle, fieldHandle) &
      bind(C, name='DelayedNeutronRateSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DelayedNeutronRateSet


!! -----------------------------------------------------------------------------
!! Child: product
!! -----------------------------------------------------------------------------

!! Has
function DelayedNeutronProductHas(handle) &
      bind(C, name='DelayedNeutronProductHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DelayedNeutronProductHas
end function DelayedNeutronProductHas

!! Get, const
function DelayedNeutronProductGetConst(handle) &
      bind(C, name='DelayedNeutronProductGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DelayedNeutronProductGetConst
end function DelayedNeutronProductGetConst

!! Get
function DelayedNeutronProductGet(handle) &
      bind(C, name='DelayedNeutronProductGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DelayedNeutronProductGet
end function DelayedNeutronProductGet

!! Set
subroutine DelayedNeutronProductSet(handle, fieldHandle) &
      bind(C, name='DelayedNeutronProductSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DelayedNeutronProductSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalDelayedNeutron
