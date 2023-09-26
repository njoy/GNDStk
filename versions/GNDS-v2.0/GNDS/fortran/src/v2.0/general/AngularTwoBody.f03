
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalAngularTwoBody
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AngularTwoBodyDefaultConst() &
      bind(C, name='AngularTwoBodyDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AngularTwoBodyDefaultConst
end function AngularTwoBodyDefaultConst

!! Create, default
function AngularTwoBodyDefault() &
      bind(C, name='AngularTwoBodyDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AngularTwoBodyDefault
end function AngularTwoBodyDefault

!! Create, general, const
function AngularTwoBodyCreateConst( &
   label, &
   productFrame, &
   XYs2d, &
   regions2d, &
   recoil, &
   isotropic2d, &
   labelSize, &
   productFrameSize &
) &
      bind(C, name='AngularTwoBodyCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   type(c_ptr), value :: XYs2d
   type(c_ptr), value :: regions2d
   type(c_ptr), value :: recoil
   type(c_ptr), value :: isotropic2d
   type(c_ptr) :: AngularTwoBodyCreateConst
end function AngularTwoBodyCreateConst

!! Create, general
function AngularTwoBodyCreate( &
   label, &
   productFrame, &
   XYs2d, &
   regions2d, &
   recoil, &
   isotropic2d, &
   labelSize, &
   productFrameSize &
) &
      bind(C, name='AngularTwoBodyCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   type(c_ptr), value :: XYs2d
   type(c_ptr), value :: regions2d
   type(c_ptr), value :: recoil
   type(c_ptr), value :: isotropic2d
   type(c_ptr) :: AngularTwoBodyCreate
end function AngularTwoBodyCreate

!! Assign
subroutine AngularTwoBodyAssign(handleLHS, handleRHS) &
      bind(C, name='AngularTwoBodyAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine AngularTwoBodyAssign

!! Delete
subroutine AngularTwoBodyDelete(handle) &
      bind(C, name='AngularTwoBodyDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AngularTwoBodyDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function AngularTwoBodyRead(handle, filename, filenameSize) &
      bind(C, name='AngularTwoBodyRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AngularTwoBodyRead
end function AngularTwoBodyRead

!! Write to file
function AngularTwoBodyWrite(handle, filename, filenameSize) &
      bind(C, name='AngularTwoBodyWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AngularTwoBodyWrite
end function AngularTwoBodyWrite

!! Print to standard output, in our prettyprinting format
function AngularTwoBodyPrint(handle) &
      bind(C, name='AngularTwoBodyPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyPrint
end function AngularTwoBodyPrint

!! Print to standard output, as XML
function AngularTwoBodyPrintXML(handle) &
      bind(C, name='AngularTwoBodyPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyPrintXML
end function AngularTwoBodyPrintXML

!! Print to standard output, as JSON
function AngularTwoBodyPrintJSON(handle) &
      bind(C, name='AngularTwoBodyPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyPrintJSON
end function AngularTwoBodyPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function AngularTwoBodyLabelHas(handle) &
      bind(C, name='AngularTwoBodyLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyLabelHas
end function AngularTwoBodyLabelHas

!! Get
function AngularTwoBodyLabelGet(handle) &
      bind(C, name='AngularTwoBodyLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyLabelGet
end function AngularTwoBodyLabelGet

!! Set
subroutine AngularTwoBodyLabelSet(handle, label, labelSize) &
      bind(C, name='AngularTwoBodyLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine AngularTwoBodyLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: productFrame
!! -----------------------------------------------------------------------------

!! Has
function AngularTwoBodyProductFrameHas(handle) &
      bind(C, name='AngularTwoBodyProductFrameHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyProductFrameHas
end function AngularTwoBodyProductFrameHas

!! Get
function AngularTwoBodyProductFrameGet(handle) &
      bind(C, name='AngularTwoBodyProductFrameGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyProductFrameGet
end function AngularTwoBodyProductFrameGet

!! Set
subroutine AngularTwoBodyProductFrameSet(handle, productFrame, productFrameSize) &
      bind(C, name='AngularTwoBodyProductFrameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
end subroutine AngularTwoBodyProductFrameSet


!! -----------------------------------------------------------------------------
!! Child: XYs2d
!! -----------------------------------------------------------------------------

!! Has
function AngularTwoBodyXYs2dHas(handle) &
      bind(C, name='AngularTwoBodyXYs2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyXYs2dHas
end function AngularTwoBodyXYs2dHas

!! Get, const
function AngularTwoBodyXYs2dGetConst(handle) &
      bind(C, name='AngularTwoBodyXYs2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyXYs2dGetConst
end function AngularTwoBodyXYs2dGetConst

!! Get
function AngularTwoBodyXYs2dGet(handle) &
      bind(C, name='AngularTwoBodyXYs2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyXYs2dGet
end function AngularTwoBodyXYs2dGet

!! Set
subroutine AngularTwoBodyXYs2dSet(handle, fieldHandle) &
      bind(C, name='AngularTwoBodyXYs2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine AngularTwoBodyXYs2dSet


!! -----------------------------------------------------------------------------
!! Child: regions2d
!! -----------------------------------------------------------------------------

!! Has
function AngularTwoBodyRegions2dHas(handle) &
      bind(C, name='AngularTwoBodyRegions2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyRegions2dHas
end function AngularTwoBodyRegions2dHas

!! Get, const
function AngularTwoBodyRegions2dGetConst(handle) &
      bind(C, name='AngularTwoBodyRegions2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyRegions2dGetConst
end function AngularTwoBodyRegions2dGetConst

!! Get
function AngularTwoBodyRegions2dGet(handle) &
      bind(C, name='AngularTwoBodyRegions2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyRegions2dGet
end function AngularTwoBodyRegions2dGet

!! Set
subroutine AngularTwoBodyRegions2dSet(handle, fieldHandle) &
      bind(C, name='AngularTwoBodyRegions2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine AngularTwoBodyRegions2dSet


!! -----------------------------------------------------------------------------
!! Child: recoil
!! -----------------------------------------------------------------------------

!! Has
function AngularTwoBodyRecoilHas(handle) &
      bind(C, name='AngularTwoBodyRecoilHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyRecoilHas
end function AngularTwoBodyRecoilHas

!! Get, const
function AngularTwoBodyRecoilGetConst(handle) &
      bind(C, name='AngularTwoBodyRecoilGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyRecoilGetConst
end function AngularTwoBodyRecoilGetConst

!! Get
function AngularTwoBodyRecoilGet(handle) &
      bind(C, name='AngularTwoBodyRecoilGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyRecoilGet
end function AngularTwoBodyRecoilGet

!! Set
subroutine AngularTwoBodyRecoilSet(handle, fieldHandle) &
      bind(C, name='AngularTwoBodyRecoilSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine AngularTwoBodyRecoilSet


!! -----------------------------------------------------------------------------
!! Child: isotropic2d
!! -----------------------------------------------------------------------------

!! Has
function AngularTwoBodyIsotropic2dHas(handle) &
      bind(C, name='AngularTwoBodyIsotropic2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AngularTwoBodyIsotropic2dHas
end function AngularTwoBodyIsotropic2dHas

!! Get, const
function AngularTwoBodyIsotropic2dGetConst(handle) &
      bind(C, name='AngularTwoBodyIsotropic2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyIsotropic2dGetConst
end function AngularTwoBodyIsotropic2dGetConst

!! Get
function AngularTwoBodyIsotropic2dGet(handle) &
      bind(C, name='AngularTwoBodyIsotropic2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: AngularTwoBodyIsotropic2dGet
end function AngularTwoBodyIsotropic2dGet

!! Set
subroutine AngularTwoBodyIsotropic2dSet(handle, fieldHandle) &
      bind(C, name='AngularTwoBodyIsotropic2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine AngularTwoBodyIsotropic2dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalAngularTwoBody
