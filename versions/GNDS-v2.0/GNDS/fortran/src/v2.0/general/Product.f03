
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalProduct
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ProductDefaultConst() &
      bind(C, name='ProductDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ProductDefaultConst
end function ProductDefaultConst

!! Create, default, non-const
function ProductDefault() &
      bind(C, name='ProductDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ProductDefault
end function ProductDefault

!! Create, general, const
function ProductCreateConst( &
   label, &
   pid, &
   multiplicity, &
   distribution, &
   outputChannel, &
   averageProductEnergy, &
   labelSize, &
   pidSize &
) &
      bind(C, name='ProductCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   type(c_ptr), intent(in), value :: multiplicity
   type(c_ptr), intent(in), value :: distribution
   type(c_ptr), intent(in), value :: outputChannel
   type(c_ptr), intent(in), value :: averageProductEnergy
   type(c_ptr) :: ProductCreateConst
end function ProductCreateConst

!! Create, general, non-const
function ProductCreate( &
   label, &
   pid, &
   multiplicity, &
   distribution, &
   outputChannel, &
   averageProductEnergy, &
   labelSize, &
   pidSize &
) &
      bind(C, name='ProductCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   type(c_ptr), intent(in), value :: multiplicity
   type(c_ptr), intent(in), value :: distribution
   type(c_ptr), intent(in), value :: outputChannel
   type(c_ptr), intent(in), value :: averageProductEnergy
   type(c_ptr) :: ProductCreate
end function ProductCreate

!! Assign
subroutine ProductAssign(handleLHS, handleRHS) &
      bind(C, name='ProductAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ProductAssign

!! Delete
subroutine ProductDelete(handle) &
      bind(C, name='ProductDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ProductDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ProductRead(handle, filename, filenameSize) &
      bind(C, name='ProductRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ProductRead
end function ProductRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ProductWrite(handle, filename, filenameSize) &
      bind(C, name='ProductWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ProductWrite
end function ProductWrite

!! Print to standard output, in our prettyprinting format
function ProductPrint(handle) &
      bind(C, name='ProductPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductPrint
end function ProductPrint

!! Print to standard output, as XML
function ProductPrintXML(handle) &
      bind(C, name='ProductPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductPrintXML
end function ProductPrintXML

!! Print to standard output, as JSON
function ProductPrintJSON(handle) &
      bind(C, name='ProductPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductPrintJSON
end function ProductPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ProductLabelHas(handle) &
      bind(C, name='ProductLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductLabelHas
end function ProductLabelHas

!! Get
function ProductLabelGet(handle) &
      bind(C, name='ProductLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ProductLabelGet
end function ProductLabelGet

!! Set
subroutine ProductLabelSet(handle, label, labelSize) &
      bind(C, name='ProductLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ProductLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function ProductPidHas(handle) &
      bind(C, name='ProductPidHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductPidHas
end function ProductPidHas

!! Get
function ProductPidGet(handle) &
      bind(C, name='ProductPidGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ProductPidGet
end function ProductPidGet

!! Set
subroutine ProductPidSet(handle, pid, pidSize) &
      bind(C, name='ProductPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine ProductPidSet


!! -----------------------------------------------------------------------------
!! Child: multiplicity
!! -----------------------------------------------------------------------------

!! Has
function ProductMultiplicityHas(handle) &
      bind(C, name='ProductMultiplicityHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductMultiplicityHas
end function ProductMultiplicityHas

!! Get, const
function ProductMultiplicityGetConst(handle) &
      bind(C, name='ProductMultiplicityGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ProductMultiplicityGetConst
end function ProductMultiplicityGetConst

!! Get, non-const
function ProductMultiplicityGet(handle) &
      bind(C, name='ProductMultiplicityGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ProductMultiplicityGet
end function ProductMultiplicityGet

!! Set
subroutine ProductMultiplicitySet(handle, fieldHandle) &
      bind(C, name='ProductMultiplicitySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductMultiplicitySet


!! -----------------------------------------------------------------------------
!! Child: distribution
!! -----------------------------------------------------------------------------

!! Has
function ProductDistributionHas(handle) &
      bind(C, name='ProductDistributionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductDistributionHas
end function ProductDistributionHas

!! Get, const
function ProductDistributionGetConst(handle) &
      bind(C, name='ProductDistributionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ProductDistributionGetConst
end function ProductDistributionGetConst

!! Get, non-const
function ProductDistributionGet(handle) &
      bind(C, name='ProductDistributionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ProductDistributionGet
end function ProductDistributionGet

!! Set
subroutine ProductDistributionSet(handle, fieldHandle) &
      bind(C, name='ProductDistributionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductDistributionSet


!! -----------------------------------------------------------------------------
!! Child: outputChannel
!! -----------------------------------------------------------------------------

!! Has
function ProductOutputChannelHas(handle) &
      bind(C, name='ProductOutputChannelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductOutputChannelHas
end function ProductOutputChannelHas

!! Get, const
function ProductOutputChannelGetConst(handle) &
      bind(C, name='ProductOutputChannelGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ProductOutputChannelGetConst
end function ProductOutputChannelGetConst

!! Get, non-const
function ProductOutputChannelGet(handle) &
      bind(C, name='ProductOutputChannelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ProductOutputChannelGet
end function ProductOutputChannelGet

!! Set
subroutine ProductOutputChannelSet(handle, fieldHandle) &
      bind(C, name='ProductOutputChannelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductOutputChannelSet


!! -----------------------------------------------------------------------------
!! Child: averageProductEnergy
!! -----------------------------------------------------------------------------

!! Has
function ProductAverageProductEnergyHas(handle) &
      bind(C, name='ProductAverageProductEnergyHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ProductAverageProductEnergyHas
end function ProductAverageProductEnergyHas

!! Get, const
function ProductAverageProductEnergyGetConst(handle) &
      bind(C, name='ProductAverageProductEnergyGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ProductAverageProductEnergyGetConst
end function ProductAverageProductEnergyGetConst

!! Get, non-const
function ProductAverageProductEnergyGet(handle) &
      bind(C, name='ProductAverageProductEnergyGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ProductAverageProductEnergyGet
end function ProductAverageProductEnergyGet

!! Set
subroutine ProductAverageProductEnergySet(handle, fieldHandle) &
      bind(C, name='ProductAverageProductEnergySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ProductAverageProductEnergySet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalProduct