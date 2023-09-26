
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSums
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SumsDefaultConst() &
      bind(C, name='SumsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SumsDefaultConst
end function SumsDefaultConst

!! Create, default
function SumsDefault() &
      bind(C, name='SumsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SumsDefault
end function SumsDefault

!! Create, general, const
function SumsCreateConst( &
   crossSectionSums, &
   multiplicitySums &
) &
      bind(C, name='SumsCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: crossSectionSums
   type(c_ptr), value :: multiplicitySums
   type(c_ptr) :: SumsCreateConst
end function SumsCreateConst

!! Create, general
function SumsCreate( &
   crossSectionSums, &
   multiplicitySums &
) &
      bind(C, name='SumsCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: crossSectionSums
   type(c_ptr), value :: multiplicitySums
   type(c_ptr) :: SumsCreate
end function SumsCreate

!! Assign
subroutine SumsAssign(handleLHS, handleRHS) &
      bind(C, name='SumsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine SumsAssign

!! Delete
subroutine SumsDelete(handle) &
      bind(C, name='SumsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SumsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SumsRead(handle, filename, filenameSize) &
      bind(C, name='SumsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SumsRead
end function SumsRead

!! Write to file
function SumsWrite(handle, filename, filenameSize) &
      bind(C, name='SumsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SumsWrite
end function SumsWrite

!! Print to standard output, in our prettyprinting format
function SumsPrint(handle) &
      bind(C, name='SumsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumsPrint
end function SumsPrint

!! Print to standard output, as XML
function SumsPrintXML(handle) &
      bind(C, name='SumsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumsPrintXML
end function SumsPrintXML

!! Print to standard output, as JSON
function SumsPrintJSON(handle) &
      bind(C, name='SumsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumsPrintJSON
end function SumsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: crossSectionSums
!! -----------------------------------------------------------------------------

!! Has
function SumsCrossSectionSumsHas(handle) &
      bind(C, name='SumsCrossSectionSumsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumsCrossSectionSumsHas
end function SumsCrossSectionSumsHas

!! Get, const
function SumsCrossSectionSumsGetConst(handle) &
      bind(C, name='SumsCrossSectionSumsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SumsCrossSectionSumsGetConst
end function SumsCrossSectionSumsGetConst

!! Get
function SumsCrossSectionSumsGet(handle) &
      bind(C, name='SumsCrossSectionSumsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SumsCrossSectionSumsGet
end function SumsCrossSectionSumsGet

!! Set
subroutine SumsCrossSectionSumsSet(handle, fieldHandle) &
      bind(C, name='SumsCrossSectionSumsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine SumsCrossSectionSumsSet


!! -----------------------------------------------------------------------------
!! Child: multiplicitySums
!! -----------------------------------------------------------------------------

!! Has
function SumsMultiplicitySumsHas(handle) &
      bind(C, name='SumsMultiplicitySumsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SumsMultiplicitySumsHas
end function SumsMultiplicitySumsHas

!! Get, const
function SumsMultiplicitySumsGetConst(handle) &
      bind(C, name='SumsMultiplicitySumsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SumsMultiplicitySumsGetConst
end function SumsMultiplicitySumsGetConst

!! Get
function SumsMultiplicitySumsGet(handle) &
      bind(C, name='SumsMultiplicitySumsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SumsMultiplicitySumsGet
end function SumsMultiplicitySumsGet

!! Set
subroutine SumsMultiplicitySumsSet(handle, fieldHandle) &
      bind(C, name='SumsMultiplicitySumsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine SumsMultiplicitySumsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSums
