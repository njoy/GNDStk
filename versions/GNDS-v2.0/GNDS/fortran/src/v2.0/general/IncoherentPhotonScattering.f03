
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalIncoherentPhotonScattering
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function IncoherentPhotonScatteringDefaultConst() &
      bind(C, name='IncoherentPhotonScatteringDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function IncoherentPhotonScatteringDefaultConst

!! Create, default
function IncoherentPhotonScatteringDefault() &
      bind(C, name='IncoherentPhotonScatteringDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function IncoherentPhotonScatteringDefault

!! Create, general, const
function IncoherentPhotonScatteringCreateConst( &
   label, &
   href, &
   pid, &
   productFrame, &
   scatteringFactor, &
   labelSize, &
   hrefSize, &
   pidSize, &
   productFrameSize &
) &
      bind(C, name='IncoherentPhotonScatteringCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   type(c_ptr), value :: scatteringFactor
   type(c_ptr) :: handle
end function IncoherentPhotonScatteringCreateConst

!! Create, general
function IncoherentPhotonScatteringCreate( &
   label, &
   href, &
   pid, &
   productFrame, &
   scatteringFactor, &
   labelSize, &
   hrefSize, &
   pidSize, &
   productFrameSize &
) &
      bind(C, name='IncoherentPhotonScatteringCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   type(c_ptr), value :: scatteringFactor
   type(c_ptr) :: handle
end function IncoherentPhotonScatteringCreate

!! Assign
subroutine IncoherentPhotonScatteringAssign(handleLHS, handleRHS) &
      bind(C, name='IncoherentPhotonScatteringAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine IncoherentPhotonScatteringAssign

!! Delete
subroutine IncoherentPhotonScatteringDelete(handle) &
      bind(C, name='IncoherentPhotonScatteringDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine IncoherentPhotonScatteringDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function IncoherentPhotonScatteringRead(handle, filename, filenameSize) &
      bind(C, name='IncoherentPhotonScatteringRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function IncoherentPhotonScatteringRead

!! Write to file
function IncoherentPhotonScatteringWrite(handle, filename, filenameSize) &
      bind(C, name='IncoherentPhotonScatteringWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function IncoherentPhotonScatteringWrite

!! Print to standard output, in our prettyprinting format
function IncoherentPhotonScatteringPrint(handle) &
      bind(C, name='IncoherentPhotonScatteringPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function IncoherentPhotonScatteringPrint

!! Print to standard output, as XML
function IncoherentPhotonScatteringPrintXML(handle) &
      bind(C, name='IncoherentPhotonScatteringPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function IncoherentPhotonScatteringPrintXML

!! Print to standard output, as JSON
function IncoherentPhotonScatteringPrintJSON(handle) &
      bind(C, name='IncoherentPhotonScatteringPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function IncoherentPhotonScatteringPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function IncoherentPhotonScatteringLabelHas(handle) &
      bind(C, name='IncoherentPhotonScatteringLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function IncoherentPhotonScatteringLabelHas

!! Get
function IncoherentPhotonScatteringLabelGet(handle) &
      bind(C, name='IncoherentPhotonScatteringLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function IncoherentPhotonScatteringLabelGet

!! Set
subroutine IncoherentPhotonScatteringLabelSet(handle, label, labelSize) &
      bind(C, name='IncoherentPhotonScatteringLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine IncoherentPhotonScatteringLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function IncoherentPhotonScatteringHrefHas(handle) &
      bind(C, name='IncoherentPhotonScatteringHrefHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function IncoherentPhotonScatteringHrefHas

!! Get
function IncoherentPhotonScatteringHrefGet(handle) &
      bind(C, name='IncoherentPhotonScatteringHrefGet') &
      result(href)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: href
end function IncoherentPhotonScatteringHrefGet

!! Set
subroutine IncoherentPhotonScatteringHrefSet(handle, href, hrefSize) &
      bind(C, name='IncoherentPhotonScatteringHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine IncoherentPhotonScatteringHrefSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function IncoherentPhotonScatteringPidHas(handle) &
      bind(C, name='IncoherentPhotonScatteringPidHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function IncoherentPhotonScatteringPidHas

!! Get
function IncoherentPhotonScatteringPidGet(handle) &
      bind(C, name='IncoherentPhotonScatteringPidGet') &
      result(pid)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: pid
end function IncoherentPhotonScatteringPidGet

!! Set
subroutine IncoherentPhotonScatteringPidSet(handle, pid, pidSize) &
      bind(C, name='IncoherentPhotonScatteringPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine IncoherentPhotonScatteringPidSet


!! -----------------------------------------------------------------------------
!! Metadatum: productFrame
!! -----------------------------------------------------------------------------

!! Has
function IncoherentPhotonScatteringProductFrameHas(handle) &
      bind(C, name='IncoherentPhotonScatteringProductFrameHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function IncoherentPhotonScatteringProductFrameHas

!! Get
function IncoherentPhotonScatteringProductFrameGet(handle) &
      bind(C, name='IncoherentPhotonScatteringProductFrameGet') &
      result(productFrame)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: productFrame
end function IncoherentPhotonScatteringProductFrameGet

!! Set
subroutine IncoherentPhotonScatteringProductFrameSet(handle, productFrame, productFrameSize) &
      bind(C, name='IncoherentPhotonScatteringProductFrameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
end subroutine IncoherentPhotonScatteringProductFrameSet


!! -----------------------------------------------------------------------------
!! Child: scatteringFactor
!! -----------------------------------------------------------------------------

!! Has
function IncoherentPhotonScatteringScatteringFactorHas(handle) &
      bind(C, name='IncoherentPhotonScatteringScatteringFactorHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function IncoherentPhotonScatteringScatteringFactorHas

!! Get, const
function IncoherentPhotonScatteringScatteringFactorGetConst(handle) &
      bind(C, name='IncoherentPhotonScatteringScatteringFactorGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function IncoherentPhotonScatteringScatteringFactorGetConst

!! Get
function IncoherentPhotonScatteringScatteringFactorGet(handle) &
      bind(C, name='IncoherentPhotonScatteringScatteringFactorGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function IncoherentPhotonScatteringScatteringFactorGet

!! Set
subroutine IncoherentPhotonScatteringScatteringFactorSet(handle, fieldHandle) &
      bind(C, name='IncoherentPhotonScatteringScatteringFactorSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine IncoherentPhotonScatteringScatteringFactorSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalIncoherentPhotonScattering
