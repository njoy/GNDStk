
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSpectrum
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SpectrumDefaultConst() &
      bind(C, name='SpectrumDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function SpectrumDefaultConst

!! Create, default
function SpectrumDefault() &
      bind(C, name='SpectrumDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function SpectrumDefault

!! Create, general, const
function SpectrumCreateConst( &
   label, &
   pid, &
   discrete, discreteSize, &
   continuum, &
   labelSize, &
   pidSize &
) &
      bind(C, name='SpectrumCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), value :: discreteSize
   type(c_ptr) :: discrete(discreteSize)
   type(c_ptr), value :: continuum
   type(c_ptr) :: handle
end function SpectrumCreateConst

!! Create, general
function SpectrumCreate( &
   label, &
   pid, &
   discrete, discreteSize, &
   continuum, &
   labelSize, &
   pidSize &
) &
      bind(C, name='SpectrumCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
   integer(c_size_t), value :: discreteSize
   type(c_ptr) :: discrete(discreteSize)
   type(c_ptr), value :: continuum
   type(c_ptr) :: handle
end function SpectrumCreate

!! Assign
subroutine SpectrumAssign(handleLHS, handleRHS) &
      bind(C, name='SpectrumAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine SpectrumAssign

!! Delete
subroutine SpectrumDelete(handle) &
      bind(C, name='SpectrumDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SpectrumDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function SpectrumRead(handle, filename, filenameSize) &
      bind(C, name='SpectrumRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function SpectrumRead

!! Write to file
function SpectrumWrite(handle, filename, filenameSize) &
      bind(C, name='SpectrumWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function SpectrumWrite

!! Print to standard output, in our prettyprinting format
function SpectrumPrint(handle) &
      bind(C, name='SpectrumPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function SpectrumPrint

!! Print to standard output, as XML
function SpectrumPrintXML(handle) &
      bind(C, name='SpectrumPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function SpectrumPrintXML

!! Print to standard output, as JSON
function SpectrumPrintJSON(handle) &
      bind(C, name='SpectrumPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function SpectrumPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function SpectrumLabelHas(handle) &
      bind(C, name='SpectrumLabelHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function SpectrumLabelHas

!! Get
function SpectrumLabelGet(handle) &
      bind(C, name='SpectrumLabelGet') &
      result(label)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: label
end function SpectrumLabelGet

!! Set
subroutine SpectrumLabelSet(handle, label, labelSize) &
      bind(C, name='SpectrumLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine SpectrumLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: pid
!! -----------------------------------------------------------------------------

!! Has
function SpectrumPidHas(handle) &
      bind(C, name='SpectrumPidHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function SpectrumPidHas

!! Get
function SpectrumPidGet(handle) &
      bind(C, name='SpectrumPidGet') &
      result(pid)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: pid
end function SpectrumPidGet

!! Set
subroutine SpectrumPidSet(handle, pid, pidSize) &
      bind(C, name='SpectrumPidSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: pidSize
   character(c_char), intent(in) :: pid(pidSize)
end subroutine SpectrumPidSet


!! -----------------------------------------------------------------------------
!! Child: discrete
!! -----------------------------------------------------------------------------

!! Has
function SpectrumDiscreteHas(handle) &
      bind(C, name='SpectrumDiscreteHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function SpectrumDiscreteHas

!! Clear
subroutine SpectrumDiscreteClear(handle) &
      bind(C, name='SpectrumDiscreteClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SpectrumDiscreteClear

!! Size
function SpectrumDiscreteSize(handle) &
      bind(C, name='SpectrumDiscreteSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function SpectrumDiscreteSize

!! Add
subroutine SpectrumDiscreteAdd(handle, fieldHandle) &
      bind(C, name='SpectrumDiscreteAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SpectrumDiscreteAdd

!! Get, by index \in [0,size), const
function SpectrumDiscreteGetConst(handle, index) &
      bind(C, name='SpectrumDiscreteGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function SpectrumDiscreteGetConst

!! Get, by index \in [0,size)
function SpectrumDiscreteGet(handle, index) &
      bind(C, name='SpectrumDiscreteGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function SpectrumDiscreteGet

!! Set, by index \in [0,size)
subroutine SpectrumDiscreteSet(handle, index, fieldHandle) &
      bind(C, name='SpectrumDiscreteSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SpectrumDiscreteSet

!! ------------------------
!! Re: metadatum type
!! ------------------------

!! Has, by type
function SpectrumDiscreteHasByType(handle, meta, metaSize) &
      bind(C, name='SpectrumDiscreteHasByType') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function SpectrumDiscreteHasByType

!! Get, by type, const
function SpectrumDiscreteGetByTypeConst(handle, meta, metaSize) &
      bind(C, name='SpectrumDiscreteGetByTypeConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function SpectrumDiscreteGetByTypeConst

!! Get, by type
function SpectrumDiscreteGetByType(handle, meta, metaSize) &
      bind(C, name='SpectrumDiscreteGetByType') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function SpectrumDiscreteGetByType

!! Set, by type
subroutine SpectrumDiscreteSetByType(handle, meta, metaSize, fieldHandle) &
      bind(C, name='SpectrumDiscreteSetByType')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SpectrumDiscreteSetByType


!! -----------------------------------------------------------------------------
!! Child: continuum
!! -----------------------------------------------------------------------------

!! Has
function SpectrumContinuumHas(handle) &
      bind(C, name='SpectrumContinuumHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function SpectrumContinuumHas

!! Get, const
function SpectrumContinuumGetConst(handle) &
      bind(C, name='SpectrumContinuumGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function SpectrumContinuumGetConst

!! Get
function SpectrumContinuumGet(handle) &
      bind(C, name='SpectrumContinuumGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function SpectrumContinuumGet

!! Set
subroutine SpectrumContinuumSet(handle, fieldHandle) &
      bind(C, name='SpectrumContinuumSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine SpectrumContinuumSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSpectrum
