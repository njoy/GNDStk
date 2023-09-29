
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalThermalNeutronScatteringLaw_incoherentElastic
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ThermalNeutronScatteringLaw_incoherentElasticDefaultConst() &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticDefaultConst
end function ThermalNeutronScatteringLaw_incoherentElasticDefaultConst

!! Create, default
function ThermalNeutronScatteringLaw_incoherentElasticDefault() &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticDefault
end function ThermalNeutronScatteringLaw_incoherentElasticDefault

!! Create, general, const
function ThermalNeutronScatteringLaw_incoherentElasticCreateConst( &
   label, &
   pid, &
   productFrame, &
   boundAtomCrossSection, &
   DebyeWallerIntegral, &
   labelSize, &
   pidSize, &
   productFrameSize &
) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   type(c_ptr), intent(in), value :: boundAtomCrossSection
   type(c_ptr), intent(in), value :: DebyeWallerIntegral
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticCreateConst
end function ThermalNeutronScatteringLaw_incoherentElasticCreateConst

!! Create, general
function ThermalNeutronScatteringLaw_incoherentElasticCreate( &
   label, &
   pid, &
   productFrame, &
   boundAtomCrossSection, &
   DebyeWallerIntegral, &
   labelSize, &
   pidSize, &
   productFrameSize &
) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   type(c_ptr), intent(in), value :: boundAtomCrossSection
   type(c_ptr), intent(in), value :: DebyeWallerIntegral
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticCreate
end function ThermalNeutronScatteringLaw_incoherentElasticCreate

!! Assign
subroutine ThermalNeutronScatteringLaw_incoherentElasticAssign(handleLHS, handleRHS) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ThermalNeutronScatteringLaw_incoherentElasticAssign

!! Delete
subroutine ThermalNeutronScatteringLaw_incoherentElasticDelete(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ThermalNeutronScatteringLaw_incoherentElasticDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ThermalNeutronScatteringLaw_incoherentElasticRead(handle, filename, filenameSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticRead
end function ThermalNeutronScatteringLaw_incoherentElasticRead

!! Write to file
function ThermalNeutronScatteringLaw_incoherentElasticWrite(handle, filename, filenameSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticWrite
end function ThermalNeutronScatteringLaw_incoherentElasticWrite

!! Print to standard output, in our prettyprinting format
function ThermalNeutronScatteringLaw_incoherentElasticPrint(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticPrint
end function ThermalNeutronScatteringLaw_incoherentElasticPrint

!! Print to standard output, as XML
function ThermalNeutronScatteringLaw_incoherentElasticPrintXML(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticPrintXML
end function ThermalNeutronScatteringLaw_incoherentElasticPrintXML

!! Print to standard output, as JSON
function ThermalNeutronScatteringLaw_incoherentElasticPrintJSON(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticPrintJSON
end function ThermalNeutronScatteringLaw_incoherentElasticPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentElasticLabelHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticLabelHas
end function ThermalNeutronScatteringLaw_incoherentElasticLabelHas

!! Get
function ThermalNeutronScatteringLaw_incoherentElasticLabelGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticLabelGet
end function ThermalNeutronScatteringLaw_incoherentElasticLabelGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentElasticLabelSet(handle, label, labelSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ThermalNeutronScatteringLaw_incoherentElasticLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentElasticPidHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticPidHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticPidHas
end function ThermalNeutronScatteringLaw_incoherentElasticPidHas

!! Get
function ThermalNeutronScatteringLaw_incoherentElasticPidGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticPidGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticPidGet
end function ThermalNeutronScatteringLaw_incoherentElasticPidGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentElasticPidSet(handle, pid, pidSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine ThermalNeutronScatteringLaw_incoherentElasticPidSet


!! -----------------------------------------------------------------------------
!! Metadatum: productFrame
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentElasticProductFrameHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticProductFrameHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticProductFrameHas
end function ThermalNeutronScatteringLaw_incoherentElasticProductFrameHas

!! Get
function ThermalNeutronScatteringLaw_incoherentElasticProductFrameGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticProductFrameGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticProductFrameGet
end function ThermalNeutronScatteringLaw_incoherentElasticProductFrameGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentElasticProductFrameSet(handle, productFrame, productFrameSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticProductFrameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
end subroutine ThermalNeutronScatteringLaw_incoherentElasticProductFrameSet


!! -----------------------------------------------------------------------------
!! Child: boundAtomCrossSection
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionHas
end function ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionHas

!! Get, const
function ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGetConst(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGetConst
end function ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGetConst

!! Get
function ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGet
end function ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionSet(handle, fieldHandle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionSet


!! -----------------------------------------------------------------------------
!! Child: DebyeWallerIntegral
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralHas
end function ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralHas

!! Get, const
function ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGetConst(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGetConst
end function ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGetConst

!! Get
function ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGet
end function ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralSet(handle, fieldHandle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalThermalNeutronScatteringLaw_incoherentElastic
