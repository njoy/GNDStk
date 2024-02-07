
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalSpectra
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function SpectraDefaultConst() &
      bind(C, name='SpectraDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SpectraDefaultConst
end function SpectraDefaultConst

!! Create, default, non-const
function SpectraDefault() &
      bind(C, name='SpectraDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: SpectraDefault
end function SpectraDefault

!! Create, general, const
function SpectraCreateConst( &
   spectrum, spectrumSize &
) &
      bind(C, name='SpectraCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: spectrumSize
   type(c_ptr), intent(in) :: spectrum(spectrumSize)
   type(c_ptr) :: SpectraCreateConst
end function SpectraCreateConst

!! Create, general, non-const
function SpectraCreate( &
   spectrum, spectrumSize &
) &
      bind(C, name='SpectraCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: spectrumSize
   type(c_ptr), intent(in) :: spectrum(spectrumSize)
   type(c_ptr) :: SpectraCreate
end function SpectraCreate

!! Assign
subroutine SpectraAssign(handleLHS, handleRHS) &
      bind(C, name='SpectraAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine SpectraAssign

!! Delete
subroutine SpectraDelete(handle) &
      bind(C, name='SpectraDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SpectraDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function SpectraRead(handle, filename, filenameSize) &
      bind(C, name='SpectraRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SpectraRead
end function SpectraRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function SpectraWrite(handle, filename, filenameSize) &
      bind(C, name='SpectraWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: SpectraWrite
end function SpectraWrite

!! Print to standard output, in our prettyprinting format
function SpectraPrint(handle) &
      bind(C, name='SpectraPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpectraPrint
end function SpectraPrint

!! Print to standard output, as XML
function SpectraPrintXML(handle) &
      bind(C, name='SpectraPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpectraPrintXML
end function SpectraPrintXML

!! Print to standard output, as JSON
function SpectraPrintJSON(handle) &
      bind(C, name='SpectraPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpectraPrintJSON
end function SpectraPrintJSON


!! -----------------------------------------------------------------------------
!! Child: spectrum
!! -----------------------------------------------------------------------------

!! Has
function SpectraSpectrumHas(handle) &
      bind(C, name='SpectraSpectrumHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: SpectraSpectrumHas
end function SpectraSpectrumHas

!! Clear
subroutine SpectraSpectrumClear(handle) &
      bind(C, name='SpectraSpectrumClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine SpectraSpectrumClear

!! Size
function SpectraSpectrumSize(handle) &
      bind(C, name='SpectraSpectrumSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: SpectraSpectrumSize
end function SpectraSpectrumSize

!! Add
subroutine SpectraSpectrumAdd(handle, fieldHandle) &
      bind(C, name='SpectraSpectrumAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SpectraSpectrumAdd

!! Get, by index \in [0,size), const
function SpectraSpectrumGetConst(handle, index) &
      bind(C, name='SpectraSpectrumGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: SpectraSpectrumGetConst
end function SpectraSpectrumGetConst

!! Get, by index \in [0,size), non-const
function SpectraSpectrumGet(handle, index) &
      bind(C, name='SpectraSpectrumGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: SpectraSpectrumGet
end function SpectraSpectrumGet

!! Set, by index \in [0,size)
subroutine SpectraSpectrumSet(handle, index, fieldHandle) &
      bind(C, name='SpectraSpectrumSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SpectraSpectrumSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function SpectraSpectrumHasByLabel(handle, meta, metaSize) &
      bind(C, name='SpectraSpectrumHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: SpectraSpectrumHasByLabel
end function SpectraSpectrumHasByLabel

!! Get, by label, const
function SpectraSpectrumGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='SpectraSpectrumGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SpectraSpectrumGetByLabelConst
end function SpectraSpectrumGetByLabelConst

!! Get, by label, non-const
function SpectraSpectrumGetByLabel(handle, meta, metaSize) &
      bind(C, name='SpectraSpectrumGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SpectraSpectrumGetByLabel
end function SpectraSpectrumGetByLabel

!! Set, by label
subroutine SpectraSpectrumSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='SpectraSpectrumSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SpectraSpectrumSetByLabel

!! ------------------------
!! Re: metadatum pid
!! ------------------------

!! Has, by pid
function SpectraSpectrumHasByPid(handle, meta, metaSize) &
      bind(C, name='SpectraSpectrumHasByPid')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: SpectraSpectrumHasByPid
end function SpectraSpectrumHasByPid

!! Get, by pid, const
function SpectraSpectrumGetByPidConst(handle, meta, metaSize) &
      bind(C, name='SpectraSpectrumGetByPidConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SpectraSpectrumGetByPidConst
end function SpectraSpectrumGetByPidConst

!! Get, by pid, non-const
function SpectraSpectrumGetByPid(handle, meta, metaSize) &
      bind(C, name='SpectraSpectrumGetByPid')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: SpectraSpectrumGetByPid
end function SpectraSpectrumGetByPid

!! Set, by pid
subroutine SpectraSpectrumSetByPid(handle, meta, metaSize, fieldHandle) &
      bind(C, name='SpectraSpectrumSetByPid')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine SpectraSpectrumSetByPid


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalSpectra