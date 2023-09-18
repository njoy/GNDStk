
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalThermalNeutronScatteringLaw
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ThermalNeutronScatteringLawDefaultConst() &
      bind(C, name='ThermalNeutronScatteringLawDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLawDefaultConst

!! Create, default
function ThermalNeutronScatteringLawDefault() &
      bind(C, name='ThermalNeutronScatteringLawDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLawDefault

!! Create, general, const
function ThermalNeutronScatteringLawCreateConst( &
   label, &
   href, &
   labelSize, &
   hrefSize &
) &
      bind(C, name='ThermalNeutronScatteringLawCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLawCreateConst

!! Create, general
function ThermalNeutronScatteringLawCreate( &
   label, &
   href, &
   labelSize, &
   hrefSize &
) &
      bind(C, name='ThermalNeutronScatteringLawCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLawCreate

!! Assign
subroutine ThermalNeutronScatteringLawAssign(handleLHS, handleRHS) &
      bind(C, name='ThermalNeutronScatteringLawAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ThermalNeutronScatteringLawAssign

!! Delete
subroutine ThermalNeutronScatteringLawDelete(handle) &
      bind(C, name='ThermalNeutronScatteringLawDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ThermalNeutronScatteringLawDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ThermalNeutronScatteringLawRead(handle, filename, filenameSize) &
      bind(C, name='ThermalNeutronScatteringLawRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ThermalNeutronScatteringLawRead

!! Write to file
function ThermalNeutronScatteringLawWrite(handle, filename, filenameSize) &
      bind(C, name='ThermalNeutronScatteringLawWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ThermalNeutronScatteringLawWrite

!! Print to standard output, in our prettyprinting format
function ThermalNeutronScatteringLawPrint(handle) &
      bind(C, name='ThermalNeutronScatteringLawPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ThermalNeutronScatteringLawPrint

!! Print to standard output, as XML
function ThermalNeutronScatteringLawPrintXML(handle) &
      bind(C, name='ThermalNeutronScatteringLawPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ThermalNeutronScatteringLawPrintXML

!! Print to standard output, as JSON
function ThermalNeutronScatteringLawPrintJSON(handle) &
      bind(C, name='ThermalNeutronScatteringLawPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ThermalNeutronScatteringLawPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLawLabelHas(handle) &
      bind(C, name='ThermalNeutronScatteringLawLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLawLabelHas

!! Get
function ThermalNeutronScatteringLawLabelGet(handle) &
      bind(C, name='ThermalNeutronScatteringLawLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function ThermalNeutronScatteringLawLabelGet

!! Set
subroutine ThermalNeutronScatteringLawLabelSet(handle, label, labelSize) &
      bind(C, name='ThermalNeutronScatteringLawLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ThermalNeutronScatteringLawLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLawHrefHas(handle) &
      bind(C, name='ThermalNeutronScatteringLawHrefHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLawHrefHas

!! Get
function ThermalNeutronScatteringLawHrefGet(handle) &
      bind(C, name='ThermalNeutronScatteringLawHrefGet') &
      result(href)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: href
end function ThermalNeutronScatteringLawHrefGet

!! Set
subroutine ThermalNeutronScatteringLawHrefSet(handle, href, hrefSize) &
      bind(C, name='ThermalNeutronScatteringLawHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine ThermalNeutronScatteringLawHrefSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalThermalNeutronScatteringLaw
