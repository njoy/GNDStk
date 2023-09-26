
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalThermalNeutronScatteringLaw_incoherentInelastic
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ThermalNeutronScatteringLaw_incoherentInelasticDefaultConst() &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLaw_incoherentInelasticDefaultConst

!! Create, default
function ThermalNeutronScatteringLaw_incoherentInelasticDefault() &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLaw_incoherentInelasticDefault

!! Create, general, const
function ThermalNeutronScatteringLaw_incoherentInelasticCreateConst( &
   label, &
   pid, &
   productFrame, &
   primaryScatterer, &
   calculatedAtThermal, &
   scatteringAtoms, &
   labelSize, &
   pidSize, &
   productFrameSize, &
   primaryScattererSize &
) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   integer(c_size_t), intent(in), value :: primaryScattererSize
   character(c_char), intent(in) :: primaryScatterer(primaryScattererSize)
   logical(c_bool), value, intent(in) :: calculatedAtThermal
   type(c_ptr), value :: scatteringAtoms
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLaw_incoherentInelasticCreateConst

!! Create, general
function ThermalNeutronScatteringLaw_incoherentInelasticCreate( &
   label, &
   pid, &
   productFrame, &
   primaryScatterer, &
   calculatedAtThermal, &
   scatteringAtoms, &
   labelSize, &
   pidSize, &
   productFrameSize, &
   primaryScattererSize &
) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
   integer(c_size_t), intent(in), value :: primaryScattererSize
   character(c_char), intent(in) :: primaryScatterer(primaryScattererSize)
   logical(c_bool), value, intent(in) :: calculatedAtThermal
   type(c_ptr), value :: scatteringAtoms
   type(c_ptr) :: handle
end function ThermalNeutronScatteringLaw_incoherentInelasticCreate

!! Assign
subroutine ThermalNeutronScatteringLaw_incoherentInelasticAssign(handleLHS, handleRHS) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticAssign

!! Delete
subroutine ThermalNeutronScatteringLaw_incoherentInelasticDelete(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ThermalNeutronScatteringLaw_incoherentInelasticRead(handle, filename, filenameSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ThermalNeutronScatteringLaw_incoherentInelasticRead

!! Write to file
function ThermalNeutronScatteringLaw_incoherentInelasticWrite(handle, filename, filenameSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ThermalNeutronScatteringLaw_incoherentInelasticWrite

!! Print to standard output, in our prettyprinting format
function ThermalNeutronScatteringLaw_incoherentInelasticPrint(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ThermalNeutronScatteringLaw_incoherentInelasticPrint

!! Print to standard output, as XML
function ThermalNeutronScatteringLaw_incoherentInelasticPrintXML(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ThermalNeutronScatteringLaw_incoherentInelasticPrintXML

!! Print to standard output, as JSON
function ThermalNeutronScatteringLaw_incoherentInelasticPrintJSON(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ThermalNeutronScatteringLaw_incoherentInelasticPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentInelasticLabelHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLaw_incoherentInelasticLabelHas

!! Get
function ThermalNeutronScatteringLaw_incoherentInelasticLabelGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function ThermalNeutronScatteringLaw_incoherentInelasticLabelGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentInelasticLabelSet(handle, label, labelSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentInelasticPidHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPidHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLaw_incoherentInelasticPidHas

!! Get
function ThermalNeutronScatteringLaw_incoherentInelasticPidGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPidGet') &
      result(pid)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: pid
end function ThermalNeutronScatteringLaw_incoherentInelasticPidGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentInelasticPidSet(handle, pid, pidSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticPidSet


!! -----------------------------------------------------------------------------
!! Metadatum: productFrame
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentInelasticProductFrameHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticProductFrameHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLaw_incoherentInelasticProductFrameHas

!! Get
function ThermalNeutronScatteringLaw_incoherentInelasticProductFrameGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticProductFrameGet') &
      result(productFrame)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: productFrame
end function ThermalNeutronScatteringLaw_incoherentInelasticProductFrameGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentInelasticProductFrameSet(handle, productFrame, productFrameSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticProductFrameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: productFrameSize
   character(c_char), intent(in) :: productFrame(productFrameSize)
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticProductFrameSet


!! -----------------------------------------------------------------------------
!! Metadatum: primaryScatterer
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererHas

!! Get
function ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererGet') &
      result(primaryScatterer)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: primaryScatterer
end function ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererSet(handle, primaryScatterer, primaryScattererSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: primaryScattererSize
   character(c_char), intent(in) :: primaryScatterer(primaryScattererSize)
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticPrimaryScattererSet


!! -----------------------------------------------------------------------------
!! Metadatum: calculatedAtThermal
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalHas

!! Get
function ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalGet') &
      result(calculatedAtThermal)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   logical(c_bool) :: calculatedAtThermal
end function ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalSet(handle, calculatedAtThermal, calculatedAtThermalSize) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: calculatedAtThermalSize
   character(c_char), intent(in) :: calculatedAtThermal(calculatedAtThermalSize)
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticCalculatedAtThermalSet


!! -----------------------------------------------------------------------------
!! Child: scatteringAtoms
!! -----------------------------------------------------------------------------

!! Has
function ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsHas(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsHas

!! Get, const
function ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsGetConst(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsGetConst

!! Get
function ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsGet(handle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsGet

!! Set
subroutine ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsSet(handle, fieldHandle) &
      bind(C, name='ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine ThermalNeutronScatteringLaw_incoherentInelasticScatteringAtomsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalThermalNeutronScatteringLaw_incoherentInelastic
