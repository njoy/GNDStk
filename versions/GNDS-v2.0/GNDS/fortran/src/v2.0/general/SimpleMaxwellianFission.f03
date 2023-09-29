
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSimpleMaxwellianFission
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SimpleMaxwellianFissionDefaultConst() &
      bind(C, name='SimpleMaxwellianFissionDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SimpleMaxwellianFissionDefaultConst
end function SimpleMaxwellianFissionDefaultConst

!! Create, default
function SimpleMaxwellianFissionDefault() &
      bind(C, name='SimpleMaxwellianFissionDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SimpleMaxwellianFissionDefault
end function SimpleMaxwellianFissionDefault

!! Create, general, const
function SimpleMaxwellianFissionCreateConst( &
   U, &
   theta &
) &
      bind(C, name='SimpleMaxwellianFissionCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: U
   type(c_ptr), intent(in), value :: theta
   type(c_ptr) :: SimpleMaxwellianFissionCreateConst
end function SimpleMaxwellianFissionCreateConst

!! Create, general
function SimpleMaxwellianFissionCreate( &
   U, &
   theta &
) &
      bind(C, name='SimpleMaxwellianFissionCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: U
   type(c_ptr), intent(in), value :: theta
   type(c_ptr) :: SimpleMaxwellianFissionCreate
end function SimpleMaxwellianFissionCreate

!! Assign
subroutine SimpleMaxwellianFissionAssign(handleLHS, handleRHS) &
      bind(C, name='SimpleMaxwellianFissionAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine SimpleMaxwellianFissionAssign

!! Delete
subroutine SimpleMaxwellianFissionDelete(handle) &
      bind(C, name='SimpleMaxwellianFissionDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SimpleMaxwellianFissionDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SimpleMaxwellianFissionRead(handle, filename, filenameSize) &
      bind(C, name='SimpleMaxwellianFissionRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SimpleMaxwellianFissionRead
end function SimpleMaxwellianFissionRead

!! Write to file
function SimpleMaxwellianFissionWrite(handle, filename, filenameSize) &
      bind(C, name='SimpleMaxwellianFissionWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SimpleMaxwellianFissionWrite
end function SimpleMaxwellianFissionWrite

!! Print to standard output, in our prettyprinting format
function SimpleMaxwellianFissionPrint(handle) &
      bind(C, name='SimpleMaxwellianFissionPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SimpleMaxwellianFissionPrint
end function SimpleMaxwellianFissionPrint

!! Print to standard output, as XML
function SimpleMaxwellianFissionPrintXML(handle) &
      bind(C, name='SimpleMaxwellianFissionPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SimpleMaxwellianFissionPrintXML
end function SimpleMaxwellianFissionPrintXML

!! Print to standard output, as JSON
function SimpleMaxwellianFissionPrintJSON(handle) &
      bind(C, name='SimpleMaxwellianFissionPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SimpleMaxwellianFissionPrintJSON
end function SimpleMaxwellianFissionPrintJSON


!! -----------------------------------------------------------------------------
!! Child: U
!! -----------------------------------------------------------------------------

!! Has
function SimpleMaxwellianFissionUHas(handle) &
      bind(C, name='SimpleMaxwellianFissionUHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SimpleMaxwellianFissionUHas
end function SimpleMaxwellianFissionUHas

!! Get, const
function SimpleMaxwellianFissionUGetConst(handle) &
      bind(C, name='SimpleMaxwellianFissionUGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SimpleMaxwellianFissionUGetConst
end function SimpleMaxwellianFissionUGetConst

!! Get
function SimpleMaxwellianFissionUGet(handle) &
      bind(C, name='SimpleMaxwellianFissionUGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: SimpleMaxwellianFissionUGet
end function SimpleMaxwellianFissionUGet

!! Set
subroutine SimpleMaxwellianFissionUSet(handle, fieldHandle) &
      bind(C, name='SimpleMaxwellianFissionUSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SimpleMaxwellianFissionUSet


!! -----------------------------------------------------------------------------
!! Child: theta
!! -----------------------------------------------------------------------------

!! Has
function SimpleMaxwellianFissionThetaHas(handle) &
      bind(C, name='SimpleMaxwellianFissionThetaHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SimpleMaxwellianFissionThetaHas
end function SimpleMaxwellianFissionThetaHas

!! Get, const
function SimpleMaxwellianFissionThetaGetConst(handle) &
      bind(C, name='SimpleMaxwellianFissionThetaGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SimpleMaxwellianFissionThetaGetConst
end function SimpleMaxwellianFissionThetaGetConst

!! Get
function SimpleMaxwellianFissionThetaGet(handle) &
      bind(C, name='SimpleMaxwellianFissionThetaGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: SimpleMaxwellianFissionThetaGet
end function SimpleMaxwellianFissionThetaGet

!! Set
subroutine SimpleMaxwellianFissionThetaSet(handle, fieldHandle) &
      bind(C, name='SimpleMaxwellianFissionThetaSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SimpleMaxwellianFissionThetaSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSimpleMaxwellianFission
