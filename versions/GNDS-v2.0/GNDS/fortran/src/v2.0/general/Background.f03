
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalBackground
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function BackgroundDefaultConst() &
      bind(C, name='BackgroundDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: BackgroundDefaultConst
end function BackgroundDefaultConst

!! Create, default
function BackgroundDefault() &
      bind(C, name='BackgroundDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: BackgroundDefault
end function BackgroundDefault

!! Create, general, const
function BackgroundCreateConst( &
   resolvedRegion, &
   fastRegion, &
   unresolvedRegion &
) &
      bind(C, name='BackgroundCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: resolvedRegion
   type(c_ptr), intent(in), value :: fastRegion
   type(c_ptr), intent(in), value :: unresolvedRegion
   type(c_ptr) :: BackgroundCreateConst
end function BackgroundCreateConst

!! Create, general
function BackgroundCreate( &
   resolvedRegion, &
   fastRegion, &
   unresolvedRegion &
) &
      bind(C, name='BackgroundCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: resolvedRegion
   type(c_ptr), intent(in), value :: fastRegion
   type(c_ptr), intent(in), value :: unresolvedRegion
   type(c_ptr) :: BackgroundCreate
end function BackgroundCreate

!! Assign
subroutine BackgroundAssign(handleLHS, handleRHS) &
      bind(C, name='BackgroundAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine BackgroundAssign

!! Delete
subroutine BackgroundDelete(handle) &
      bind(C, name='BackgroundDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine BackgroundDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function BackgroundRead(handle, filename, filenameSize) &
      bind(C, name='BackgroundRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: BackgroundRead
end function BackgroundRead

!! Write to file
function BackgroundWrite(handle, filename, filenameSize) &
      bind(C, name='BackgroundWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: BackgroundWrite
end function BackgroundWrite

!! Print to standard output, in our prettyprinting format
function BackgroundPrint(handle) &
      bind(C, name='BackgroundPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: BackgroundPrint
end function BackgroundPrint

!! Print to standard output, as XML
function BackgroundPrintXML(handle) &
      bind(C, name='BackgroundPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: BackgroundPrintXML
end function BackgroundPrintXML

!! Print to standard output, as JSON
function BackgroundPrintJSON(handle) &
      bind(C, name='BackgroundPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: BackgroundPrintJSON
end function BackgroundPrintJSON


!! -----------------------------------------------------------------------------
!! Child: resolvedRegion
!! -----------------------------------------------------------------------------

!! Has
function BackgroundResolvedRegionHas(handle) &
      bind(C, name='BackgroundResolvedRegionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: BackgroundResolvedRegionHas
end function BackgroundResolvedRegionHas

!! Get, const
function BackgroundResolvedRegionGetConst(handle) &
      bind(C, name='BackgroundResolvedRegionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: BackgroundResolvedRegionGetConst
end function BackgroundResolvedRegionGetConst

!! Get
function BackgroundResolvedRegionGet(handle) &
      bind(C, name='BackgroundResolvedRegionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: BackgroundResolvedRegionGet
end function BackgroundResolvedRegionGet

!! Set
subroutine BackgroundResolvedRegionSet(handle, fieldHandle) &
      bind(C, name='BackgroundResolvedRegionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine BackgroundResolvedRegionSet


!! -----------------------------------------------------------------------------
!! Child: fastRegion
!! -----------------------------------------------------------------------------

!! Has
function BackgroundFastRegionHas(handle) &
      bind(C, name='BackgroundFastRegionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: BackgroundFastRegionHas
end function BackgroundFastRegionHas

!! Get, const
function BackgroundFastRegionGetConst(handle) &
      bind(C, name='BackgroundFastRegionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: BackgroundFastRegionGetConst
end function BackgroundFastRegionGetConst

!! Get
function BackgroundFastRegionGet(handle) &
      bind(C, name='BackgroundFastRegionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: BackgroundFastRegionGet
end function BackgroundFastRegionGet

!! Set
subroutine BackgroundFastRegionSet(handle, fieldHandle) &
      bind(C, name='BackgroundFastRegionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine BackgroundFastRegionSet


!! -----------------------------------------------------------------------------
!! Child: unresolvedRegion
!! -----------------------------------------------------------------------------

!! Has
function BackgroundUnresolvedRegionHas(handle) &
      bind(C, name='BackgroundUnresolvedRegionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: BackgroundUnresolvedRegionHas
end function BackgroundUnresolvedRegionHas

!! Get, const
function BackgroundUnresolvedRegionGetConst(handle) &
      bind(C, name='BackgroundUnresolvedRegionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: BackgroundUnresolvedRegionGetConst
end function BackgroundUnresolvedRegionGetConst

!! Get
function BackgroundUnresolvedRegionGet(handle) &
      bind(C, name='BackgroundUnresolvedRegionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: BackgroundUnresolvedRegionGet
end function BackgroundUnresolvedRegionGet

!! Set
subroutine BackgroundUnresolvedRegionSet(handle, fieldHandle) &
      bind(C, name='BackgroundUnresolvedRegionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine BackgroundUnresolvedRegionSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalBackground
