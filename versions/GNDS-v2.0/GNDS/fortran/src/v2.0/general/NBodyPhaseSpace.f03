
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalNBodyPhaseSpace
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function NBodyPhaseSpaceDefaultConst() &
      bind(C, name='NBodyPhaseSpaceDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function NBodyPhaseSpaceDefaultConst

!! Create, default
function NBodyPhaseSpaceDefault() &
      bind(C, name='NBodyPhaseSpaceDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function NBodyPhaseSpaceDefault

!! Create, general, const
function NBodyPhaseSpaceCreateConst( &
   numberOfProducts, &
   mass &
) &
      bind(C, name='NBodyPhaseSpaceCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: numberOfProducts
   type(c_ptr), value :: mass
   type(c_ptr) :: handle
end function NBodyPhaseSpaceCreateConst

!! Create, general
function NBodyPhaseSpaceCreate( &
   numberOfProducts, &
   mass &
) &
      bind(C, name='NBodyPhaseSpaceCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_int), value, intent(in) :: numberOfProducts
   type(c_ptr), value :: mass
   type(c_ptr) :: handle
end function NBodyPhaseSpaceCreate

!! Assign
subroutine NBodyPhaseSpaceAssign(handleLHS, handleRHS) &
      bind(C, name='NBodyPhaseSpaceAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine NBodyPhaseSpaceAssign

!! Delete
subroutine NBodyPhaseSpaceDelete(handle) &
      bind(C, name='NBodyPhaseSpaceDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine NBodyPhaseSpaceDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function NBodyPhaseSpaceRead(handle, filename, filenameSize) &
      bind(C, name='NBodyPhaseSpaceRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function NBodyPhaseSpaceRead

!! Write to file
function NBodyPhaseSpaceWrite(handle, filename, filenameSize) &
      bind(C, name='NBodyPhaseSpaceWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function NBodyPhaseSpaceWrite

!! Print to standard output, in our prettyprinting format
function NBodyPhaseSpacePrint(handle) &
      bind(C, name='NBodyPhaseSpacePrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NBodyPhaseSpacePrint

!! Print to standard output, as XML
function NBodyPhaseSpacePrintXML(handle) &
      bind(C, name='NBodyPhaseSpacePrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NBodyPhaseSpacePrintXML

!! Print to standard output, as JSON
function NBodyPhaseSpacePrintJSON(handle) &
      bind(C, name='NBodyPhaseSpacePrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function NBodyPhaseSpacePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: numberOfProducts
!! -----------------------------------------------------------------------------

!! Has
function NBodyPhaseSpaceNumberOfProductsHas(handle) &
      bind(C, name='NBodyPhaseSpaceNumberOfProductsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function NBodyPhaseSpaceNumberOfProductsHas

!! Get
function NBodyPhaseSpaceNumberOfProductsGet(handle) &
      bind(C, name='NBodyPhaseSpaceNumberOfProductsGet') &
      result(numberOfProducts)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: numberOfProducts
end function NBodyPhaseSpaceNumberOfProductsGet

!! Set
subroutine NBodyPhaseSpaceNumberOfProductsSet(handle, numberOfProducts, numberOfProductsSize) &
      bind(C, name='NBodyPhaseSpaceNumberOfProductsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: numberOfProductsSize
   character(c_char), intent(in) :: numberOfProducts(numberOfProductsSize)
end subroutine NBodyPhaseSpaceNumberOfProductsSet


!! -----------------------------------------------------------------------------
!! Child: mass
!! -----------------------------------------------------------------------------

!! Has
function NBodyPhaseSpaceMassHas(handle) &
      bind(C, name='NBodyPhaseSpaceMassHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function NBodyPhaseSpaceMassHas

!! Get, const
function NBodyPhaseSpaceMassGetConst(handle) &
      bind(C, name='NBodyPhaseSpaceMassGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function NBodyPhaseSpaceMassGetConst

!! Get
function NBodyPhaseSpaceMassGet(handle) &
      bind(C, name='NBodyPhaseSpaceMassGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function NBodyPhaseSpaceMassGet

!! Set
subroutine NBodyPhaseSpaceMassSet(handle, fieldHandle) &
      bind(C, name='NBodyPhaseSpaceMassSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine NBodyPhaseSpaceMassSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalNBodyPhaseSpace
