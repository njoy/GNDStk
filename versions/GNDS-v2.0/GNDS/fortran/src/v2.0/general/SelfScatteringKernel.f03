
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSelfScatteringKernel
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SelfScatteringKernelDefaultConst() &
      bind(C, name='SelfScatteringKernelDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SelfScatteringKernelDefaultConst
end function SelfScatteringKernelDefaultConst

!! Create, default, non-const
function SelfScatteringKernelDefault() &
      bind(C, name='SelfScatteringKernelDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SelfScatteringKernelDefault
end function SelfScatteringKernelDefault

!! Create, general, const
function SelfScatteringKernelCreateConst( &
   symmetric, &
   gridded3d, &
   SCTApproximation, &
   freeGasApproximation &
) &
      bind(C, name='SelfScatteringKernelCreateConst')
   use iso_c_binding
   implicit none
   logical(c_bool), intent(in), value :: symmetric
   type(c_ptr), intent(in), value :: gridded3d
   type(c_ptr), intent(in), value :: SCTApproximation
   type(c_ptr), intent(in), value :: freeGasApproximation
   type(c_ptr) :: SelfScatteringKernelCreateConst
end function SelfScatteringKernelCreateConst

!! Create, general, non-const
function SelfScatteringKernelCreate( &
   symmetric, &
   gridded3d, &
   SCTApproximation, &
   freeGasApproximation &
) &
      bind(C, name='SelfScatteringKernelCreate')
   use iso_c_binding
   implicit none
   logical(c_bool), intent(in), value :: symmetric
   type(c_ptr), intent(in), value :: gridded3d
   type(c_ptr), intent(in), value :: SCTApproximation
   type(c_ptr), intent(in), value :: freeGasApproximation
   type(c_ptr) :: SelfScatteringKernelCreate
end function SelfScatteringKernelCreate

!! Assign
subroutine SelfScatteringKernelAssign(handleLHS, handleRHS) &
      bind(C, name='SelfScatteringKernelAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine SelfScatteringKernelAssign

!! Delete
subroutine SelfScatteringKernelDelete(handle) &
      bind(C, name='SelfScatteringKernelDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SelfScatteringKernelDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function SelfScatteringKernelRead(handle, filename, filenameSize) &
      bind(C, name='SelfScatteringKernelRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SelfScatteringKernelRead
end function SelfScatteringKernelRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function SelfScatteringKernelWrite(handle, filename, filenameSize) &
      bind(C, name='SelfScatteringKernelWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SelfScatteringKernelWrite
end function SelfScatteringKernelWrite

!! Print to standard output, in our prettyprinting format
function SelfScatteringKernelPrint(handle) &
      bind(C, name='SelfScatteringKernelPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SelfScatteringKernelPrint
end function SelfScatteringKernelPrint

!! Print to standard output, as XML
function SelfScatteringKernelPrintXML(handle) &
      bind(C, name='SelfScatteringKernelPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SelfScatteringKernelPrintXML
end function SelfScatteringKernelPrintXML

!! Print to standard output, as JSON
function SelfScatteringKernelPrintJSON(handle) &
      bind(C, name='SelfScatteringKernelPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SelfScatteringKernelPrintJSON
end function SelfScatteringKernelPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: symmetric
!! -----------------------------------------------------------------------------

!! Has
function SelfScatteringKernelSymmetricHas(handle) &
      bind(C, name='SelfScatteringKernelSymmetricHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SelfScatteringKernelSymmetricHas
end function SelfScatteringKernelSymmetricHas

!! Get
function SelfScatteringKernelSymmetricGet(handle) &
      bind(C, name='SelfScatteringKernelSymmetricGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   logical(c_bool) :: SelfScatteringKernelSymmetricGet
end function SelfScatteringKernelSymmetricGet

!! Set
subroutine SelfScatteringKernelSymmetricSet(handle, symmetric) &
      bind(C, name='SelfScatteringKernelSymmetricSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   logical(c_bool), intent(in), value :: symmetric
end subroutine SelfScatteringKernelSymmetricSet


!! -----------------------------------------------------------------------------
!! Child: gridded3d
!! -----------------------------------------------------------------------------

!! Has
function SelfScatteringKernelGridded3dHas(handle) &
      bind(C, name='SelfScatteringKernelGridded3dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SelfScatteringKernelGridded3dHas
end function SelfScatteringKernelGridded3dHas

!! Get, const
function SelfScatteringKernelGridded3dGetConst(handle) &
      bind(C, name='SelfScatteringKernelGridded3dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SelfScatteringKernelGridded3dGetConst
end function SelfScatteringKernelGridded3dGetConst

!! Get, non-const
function SelfScatteringKernelGridded3dGet(handle) &
      bind(C, name='SelfScatteringKernelGridded3dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: SelfScatteringKernelGridded3dGet
end function SelfScatteringKernelGridded3dGet

!! Set
subroutine SelfScatteringKernelGridded3dSet(handle, fieldHandle) &
      bind(C, name='SelfScatteringKernelGridded3dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SelfScatteringKernelGridded3dSet


!! -----------------------------------------------------------------------------
!! Child: SCTApproximation
!! -----------------------------------------------------------------------------

!! Has
function SelfScatteringKernelSCTApproximationHas(handle) &
      bind(C, name='SelfScatteringKernelSCTApproximationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SelfScatteringKernelSCTApproximationHas
end function SelfScatteringKernelSCTApproximationHas

!! Get, const
function SelfScatteringKernelSCTApproximationGetConst(handle) &
      bind(C, name='SelfScatteringKernelSCTApproximationGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SelfScatteringKernelSCTApproximationGetConst
end function SelfScatteringKernelSCTApproximationGetConst

!! Get, non-const
function SelfScatteringKernelSCTApproximationGet(handle) &
      bind(C, name='SelfScatteringKernelSCTApproximationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: SelfScatteringKernelSCTApproximationGet
end function SelfScatteringKernelSCTApproximationGet

!! Set
subroutine SelfScatteringKernelSCTApproximationSet(handle, fieldHandle) &
      bind(C, name='SelfScatteringKernelSCTApproximationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SelfScatteringKernelSCTApproximationSet


!! -----------------------------------------------------------------------------
!! Child: freeGasApproximation
!! -----------------------------------------------------------------------------

!! Has
function SelfScatteringKernelFreeGasApproximationHas(handle) &
      bind(C, name='SelfScatteringKernelFreeGasApproximationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SelfScatteringKernelFreeGasApproximationHas
end function SelfScatteringKernelFreeGasApproximationHas

!! Get, const
function SelfScatteringKernelFreeGasApproximationGetConst(handle) &
      bind(C, name='SelfScatteringKernelFreeGasApproximationGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: SelfScatteringKernelFreeGasApproximationGetConst
end function SelfScatteringKernelFreeGasApproximationGetConst

!! Get, non-const
function SelfScatteringKernelFreeGasApproximationGet(handle) &
      bind(C, name='SelfScatteringKernelFreeGasApproximationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: SelfScatteringKernelFreeGasApproximationGet
end function SelfScatteringKernelFreeGasApproximationGet

!! Set
subroutine SelfScatteringKernelFreeGasApproximationSet(handle, fieldHandle) &
      bind(C, name='SelfScatteringKernelFreeGasApproximationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SelfScatteringKernelFreeGasApproximationSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSelfScatteringKernel