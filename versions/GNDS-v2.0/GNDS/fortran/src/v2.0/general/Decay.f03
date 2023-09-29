
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalDecay
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DecayDefaultConst() &
      bind(C, name='DecayDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DecayDefaultConst
end function DecayDefaultConst

!! Create, default
function DecayDefault() &
      bind(C, name='DecayDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DecayDefault
end function DecayDefault

!! Create, general, const
function DecayCreateConst( &
   index, &
   mode, &
   complete, &
   products, &
   modeSize &
) &
      bind(C, name='DecayCreateConst')
   use iso_c_binding
   implicit none
   integer(c_int), intent(in), value :: index
   integer(c_size_t), intent(in), value :: modeSize
   character(c_char), intent(in) :: mode(modeSize)
   logical(c_bool), intent(in), value :: complete
   type(c_ptr), intent(in), value :: products
   type(c_ptr) :: DecayCreateConst
end function DecayCreateConst

!! Create, general
function DecayCreate( &
   index, &
   mode, &
   complete, &
   products, &
   modeSize &
) &
      bind(C, name='DecayCreate')
   use iso_c_binding
   implicit none
   integer(c_int), intent(in), value :: index
   integer(c_size_t), intent(in), value :: modeSize
   character(c_char), intent(in) :: mode(modeSize)
   logical(c_bool), intent(in), value :: complete
   type(c_ptr), intent(in), value :: products
   type(c_ptr) :: DecayCreate
end function DecayCreate

!! Assign
subroutine DecayAssign(handleLHS, handleRHS) &
      bind(C, name='DecayAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine DecayAssign

!! Delete
subroutine DecayDelete(handle) &
      bind(C, name='DecayDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DecayDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function DecayRead(handle, filename, filenameSize) &
      bind(C, name='DecayRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DecayRead
end function DecayRead

!! Write to file
function DecayWrite(handle, filename, filenameSize) &
      bind(C, name='DecayWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DecayWrite
end function DecayWrite

!! Print to standard output, in our prettyprinting format
function DecayPrint(handle) &
      bind(C, name='DecayPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayPrint
end function DecayPrint

!! Print to standard output, as XML
function DecayPrintXML(handle) &
      bind(C, name='DecayPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayPrintXML
end function DecayPrintXML

!! Print to standard output, as JSON
function DecayPrintJSON(handle) &
      bind(C, name='DecayPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayPrintJSON
end function DecayPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: index
!! -----------------------------------------------------------------------------

!! Has
function DecayIndexHas(handle) &
      bind(C, name='DecayIndexHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayIndexHas
end function DecayIndexHas

!! Get
function DecayIndexGet(handle) &
      bind(C, name='DecayIndexGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayIndexGet
end function DecayIndexGet

!! Set
subroutine DecayIndexSet(handle, index) &
      bind(C, name='DecayIndexSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: index
end subroutine DecayIndexSet


!! -----------------------------------------------------------------------------
!! Metadatum: mode
!! -----------------------------------------------------------------------------

!! Has
function DecayModeHas(handle) &
      bind(C, name='DecayModeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayModeHas
end function DecayModeHas

!! Get
function DecayModeGet(handle) &
      bind(C, name='DecayModeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayModeGet
end function DecayModeGet

!! Set
subroutine DecayModeSet(handle, mode, modeSize) &
      bind(C, name='DecayModeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: modeSize
   character(c_char), intent(in) :: mode(modeSize)
end subroutine DecayModeSet


!! -----------------------------------------------------------------------------
!! Metadatum: complete
!! -----------------------------------------------------------------------------

!! Has
function DecayCompleteHas(handle) &
      bind(C, name='DecayCompleteHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayCompleteHas
end function DecayCompleteHas

!! Get
function DecayCompleteGet(handle) &
      bind(C, name='DecayCompleteGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   logical(c_bool) :: DecayCompleteGet
end function DecayCompleteGet

!! Set
subroutine DecayCompleteSet(handle, complete) &
      bind(C, name='DecayCompleteSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   logical(c_bool), intent(in), value :: complete
end subroutine DecayCompleteSet


!! -----------------------------------------------------------------------------
!! Child: products
!! -----------------------------------------------------------------------------

!! Has
function DecayProductsHas(handle) &
      bind(C, name='DecayProductsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DecayProductsHas
end function DecayProductsHas

!! Get, const
function DecayProductsGetConst(handle) &
      bind(C, name='DecayProductsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DecayProductsGetConst
end function DecayProductsGetConst

!! Get
function DecayProductsGet(handle) &
      bind(C, name='DecayProductsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DecayProductsGet
end function DecayProductsGet

!! Set
subroutine DecayProductsSet(handle, fieldHandle) &
      bind(C, name='DecayProductsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DecayProductsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalDecay
