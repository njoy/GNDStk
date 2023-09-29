
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalResolved
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ResolvedDefaultConst() &
      bind(C, name='ResolvedDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ResolvedDefaultConst
end function ResolvedDefaultConst

!! Create, default
function ResolvedDefault() &
      bind(C, name='ResolvedDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ResolvedDefault
end function ResolvedDefault

!! Create, general, const
function ResolvedCreateConst( &
   domainMin, &
   domainMax, &
   domainUnit, &
   BreitWigner, &
   RMatrix, &
   domainUnitSize &
) &
      bind(C, name='ResolvedCreateConst')
   use iso_c_binding
   implicit none
   real(c_double), intent(in), value :: domainMin
   real(c_double), intent(in), value :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   type(c_ptr), intent(in), value :: BreitWigner
   type(c_ptr), intent(in), value :: RMatrix
   type(c_ptr) :: ResolvedCreateConst
end function ResolvedCreateConst

!! Create, general
function ResolvedCreate( &
   domainMin, &
   domainMax, &
   domainUnit, &
   BreitWigner, &
   RMatrix, &
   domainUnitSize &
) &
      bind(C, name='ResolvedCreate')
   use iso_c_binding
   implicit none
   real(c_double), intent(in), value :: domainMin
   real(c_double), intent(in), value :: domainMax
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
   type(c_ptr), intent(in), value :: BreitWigner
   type(c_ptr), intent(in), value :: RMatrix
   type(c_ptr) :: ResolvedCreate
end function ResolvedCreate

!! Assign
subroutine ResolvedAssign(handleLHS, handleRHS) &
      bind(C, name='ResolvedAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ResolvedAssign

!! Delete
subroutine ResolvedDelete(handle) &
      bind(C, name='ResolvedDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ResolvedDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ResolvedRead(handle, filename, filenameSize) &
      bind(C, name='ResolvedRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ResolvedRead
end function ResolvedRead

!! Write to file
function ResolvedWrite(handle, filename, filenameSize) &
      bind(C, name='ResolvedWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ResolvedWrite
end function ResolvedWrite

!! Print to standard output, in our prettyprinting format
function ResolvedPrint(handle) &
      bind(C, name='ResolvedPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedPrint
end function ResolvedPrint

!! Print to standard output, as XML
function ResolvedPrintXML(handle) &
      bind(C, name='ResolvedPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedPrintXML
end function ResolvedPrintXML

!! Print to standard output, as JSON
function ResolvedPrintJSON(handle) &
      bind(C, name='ResolvedPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedPrintJSON
end function ResolvedPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: domainMin
!! -----------------------------------------------------------------------------

!! Has
function ResolvedDomainMinHas(handle) &
      bind(C, name='ResolvedDomainMinHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedDomainMinHas
end function ResolvedDomainMinHas

!! Get
function ResolvedDomainMinGet(handle) &
      bind(C, name='ResolvedDomainMinGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: ResolvedDomainMinGet
end function ResolvedDomainMinGet

!! Set
subroutine ResolvedDomainMinSet(handle, domainMin) &
      bind(C, name='ResolvedDomainMinSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: domainMin
end subroutine ResolvedDomainMinSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainMax
!! -----------------------------------------------------------------------------

!! Has
function ResolvedDomainMaxHas(handle) &
      bind(C, name='ResolvedDomainMaxHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedDomainMaxHas
end function ResolvedDomainMaxHas

!! Get
function ResolvedDomainMaxGet(handle) &
      bind(C, name='ResolvedDomainMaxGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double) :: ResolvedDomainMaxGet
end function ResolvedDomainMaxGet

!! Set
subroutine ResolvedDomainMaxSet(handle, domainMax) &
      bind(C, name='ResolvedDomainMaxSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: domainMax
end subroutine ResolvedDomainMaxSet


!! -----------------------------------------------------------------------------
!! Metadatum: domainUnit
!! -----------------------------------------------------------------------------

!! Has
function ResolvedDomainUnitHas(handle) &
      bind(C, name='ResolvedDomainUnitHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedDomainUnitHas
end function ResolvedDomainUnitHas

!! Get
function ResolvedDomainUnitGet(handle) &
      bind(C, name='ResolvedDomainUnitGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ResolvedDomainUnitGet
end function ResolvedDomainUnitGet

!! Set
subroutine ResolvedDomainUnitSet(handle, domainUnit, domainUnitSize) &
      bind(C, name='ResolvedDomainUnitSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: domainUnitSize
   character(c_char), intent(in) :: domainUnit(domainUnitSize)
end subroutine ResolvedDomainUnitSet


!! -----------------------------------------------------------------------------
!! Child: BreitWigner
!! -----------------------------------------------------------------------------

!! Has
function ResolvedBreitWignerHas(handle) &
      bind(C, name='ResolvedBreitWignerHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedBreitWignerHas
end function ResolvedBreitWignerHas

!! Get, const
function ResolvedBreitWignerGetConst(handle) &
      bind(C, name='ResolvedBreitWignerGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ResolvedBreitWignerGetConst
end function ResolvedBreitWignerGetConst

!! Get
function ResolvedBreitWignerGet(handle) &
      bind(C, name='ResolvedBreitWignerGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ResolvedBreitWignerGet
end function ResolvedBreitWignerGet

!! Set
subroutine ResolvedBreitWignerSet(handle, fieldHandle) &
      bind(C, name='ResolvedBreitWignerSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResolvedBreitWignerSet


!! -----------------------------------------------------------------------------
!! Child: RMatrix
!! -----------------------------------------------------------------------------

!! Has
function ResolvedRMatrixHas(handle) &
      bind(C, name='ResolvedRMatrixHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ResolvedRMatrixHas
end function ResolvedRMatrixHas

!! Get, const
function ResolvedRMatrixGetConst(handle) &
      bind(C, name='ResolvedRMatrixGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ResolvedRMatrixGetConst
end function ResolvedRMatrixGetConst

!! Get
function ResolvedRMatrixGet(handle) &
      bind(C, name='ResolvedRMatrixGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ResolvedRMatrixGet
end function ResolvedRMatrixGet

!! Set
subroutine ResolvedRMatrixSet(handle, fieldHandle) &
      bind(C, name='ResolvedRMatrixSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ResolvedRMatrixSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalResolved
