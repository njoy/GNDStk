
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalAtomic
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AtomicDefaultConst() &
      bind(C, name='AtomicDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AtomicDefaultConst
end function AtomicDefaultConst

!! Create, default
function AtomicDefault() &
      bind(C, name='AtomicDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AtomicDefault
end function AtomicDefault

!! Create, general, const
function AtomicCreateConst( &
   configurations &
) &
      bind(C, name='AtomicCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: configurations
   type(c_ptr) :: AtomicCreateConst
end function AtomicCreateConst

!! Create, general
function AtomicCreate( &
   configurations &
) &
      bind(C, name='AtomicCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: configurations
   type(c_ptr) :: AtomicCreate
end function AtomicCreate

!! Assign
subroutine AtomicAssign(handleLHS, handleRHS) &
      bind(C, name='AtomicAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine AtomicAssign

!! Delete
subroutine AtomicDelete(handle) &
      bind(C, name='AtomicDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AtomicDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function AtomicRead(handle, filename, filenameSize) &
      bind(C, name='AtomicRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AtomicRead
end function AtomicRead

!! Write to file
function AtomicWrite(handle, filename, filenameSize) &
      bind(C, name='AtomicWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AtomicWrite
end function AtomicWrite

!! Print to standard output, in our prettyprinting format
function AtomicPrint(handle) &
      bind(C, name='AtomicPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AtomicPrint
end function AtomicPrint

!! Print to standard output, as XML
function AtomicPrintXML(handle) &
      bind(C, name='AtomicPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AtomicPrintXML
end function AtomicPrintXML

!! Print to standard output, as JSON
function AtomicPrintJSON(handle) &
      bind(C, name='AtomicPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AtomicPrintJSON
end function AtomicPrintJSON


!! -----------------------------------------------------------------------------
!! Child: configurations
!! -----------------------------------------------------------------------------

!! Has
function AtomicConfigurationsHas(handle) &
      bind(C, name='AtomicConfigurationsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AtomicConfigurationsHas
end function AtomicConfigurationsHas

!! Get, const
function AtomicConfigurationsGetConst(handle) &
      bind(C, name='AtomicConfigurationsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AtomicConfigurationsGetConst
end function AtomicConfigurationsGetConst

!! Get
function AtomicConfigurationsGet(handle) &
      bind(C, name='AtomicConfigurationsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: AtomicConfigurationsGet
end function AtomicConfigurationsGet

!! Set
subroutine AtomicConfigurationsSet(handle, fieldHandle) &
      bind(C, name='AtomicConfigurationsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AtomicConfigurationsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalAtomic
