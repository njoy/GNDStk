
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalExternalFiles
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ExternalFilesDefaultConst() &
      bind(C, name='ExternalFilesDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ExternalFilesDefaultConst
end function ExternalFilesDefaultConst

!! Create, default
function ExternalFilesDefault() &
      bind(C, name='ExternalFilesDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ExternalFilesDefault
end function ExternalFilesDefault

!! Create, general, const
function ExternalFilesCreateConst( &
   externalFile, externalFileSize &
) &
      bind(C, name='ExternalFilesCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: externalFileSize
   type(c_ptr), intent(in) :: externalFile(externalFileSize)
   type(c_ptr) :: ExternalFilesCreateConst
end function ExternalFilesCreateConst

!! Create, general
function ExternalFilesCreate( &
   externalFile, externalFileSize &
) &
      bind(C, name='ExternalFilesCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: externalFileSize
   type(c_ptr), intent(in) :: externalFile(externalFileSize)
   type(c_ptr) :: ExternalFilesCreate
end function ExternalFilesCreate

!! Assign
subroutine ExternalFilesAssign(handleLHS, handleRHS) &
      bind(C, name='ExternalFilesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ExternalFilesAssign

!! Delete
subroutine ExternalFilesDelete(handle) &
      bind(C, name='ExternalFilesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ExternalFilesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ExternalFilesRead(handle, filename, filenameSize) &
      bind(C, name='ExternalFilesRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ExternalFilesRead
end function ExternalFilesRead

!! Write to file
function ExternalFilesWrite(handle, filename, filenameSize) &
      bind(C, name='ExternalFilesWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ExternalFilesWrite
end function ExternalFilesWrite

!! Print to standard output, in our prettyprinting format
function ExternalFilesPrint(handle) &
      bind(C, name='ExternalFilesPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ExternalFilesPrint
end function ExternalFilesPrint

!! Print to standard output, as XML
function ExternalFilesPrintXML(handle) &
      bind(C, name='ExternalFilesPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ExternalFilesPrintXML
end function ExternalFilesPrintXML

!! Print to standard output, as JSON
function ExternalFilesPrintJSON(handle) &
      bind(C, name='ExternalFilesPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ExternalFilesPrintJSON
end function ExternalFilesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: externalFile
!! -----------------------------------------------------------------------------

!! Has
function ExternalFilesExternalFileHas(handle) &
      bind(C, name='ExternalFilesExternalFileHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ExternalFilesExternalFileHas
end function ExternalFilesExternalFileHas

!! Clear
subroutine ExternalFilesExternalFileClear(handle) &
      bind(C, name='ExternalFilesExternalFileClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ExternalFilesExternalFileClear

!! Size
function ExternalFilesExternalFileSize(handle) &
      bind(C, name='ExternalFilesExternalFileSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ExternalFilesExternalFileSize
end function ExternalFilesExternalFileSize

!! Add
subroutine ExternalFilesExternalFileAdd(handle, fieldHandle) &
      bind(C, name='ExternalFilesExternalFileAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ExternalFilesExternalFileAdd

!! Get, by index \in [0,size), const
function ExternalFilesExternalFileGetConst(handle, index) &
      bind(C, name='ExternalFilesExternalFileGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ExternalFilesExternalFileGetConst
end function ExternalFilesExternalFileGetConst

!! Get, by index \in [0,size)
function ExternalFilesExternalFileGet(handle, index) &
      bind(C, name='ExternalFilesExternalFileGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ExternalFilesExternalFileGet
end function ExternalFilesExternalFileGet

!! Set, by index \in [0,size)
subroutine ExternalFilesExternalFileSet(handle, index, fieldHandle) &
      bind(C, name='ExternalFilesExternalFileSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ExternalFilesExternalFileSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ExternalFilesExternalFileHasByLabel(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ExternalFilesExternalFileHasByLabel
end function ExternalFilesExternalFileHasByLabel

!! Get, by label, const
function ExternalFilesExternalFileGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByLabelConst
end function ExternalFilesExternalFileGetByLabelConst

!! Get, by label
function ExternalFilesExternalFileGetByLabel(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByLabel
end function ExternalFilesExternalFileGetByLabel

!! Set, by label
subroutine ExternalFilesExternalFileSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ExternalFilesExternalFileSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ExternalFilesExternalFileSetByLabel

!! ------------------------
!! Re: metadatum path
!! ------------------------

!! Has, by path
function ExternalFilesExternalFileHasByPath(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileHasByPath')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ExternalFilesExternalFileHasByPath
end function ExternalFilesExternalFileHasByPath

!! Get, by path, const
function ExternalFilesExternalFileGetByPathConst(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByPathConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByPathConst
end function ExternalFilesExternalFileGetByPathConst

!! Get, by path
function ExternalFilesExternalFileGetByPath(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByPath')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByPath
end function ExternalFilesExternalFileGetByPath

!! Set, by path
subroutine ExternalFilesExternalFileSetByPath(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ExternalFilesExternalFileSetByPath')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ExternalFilesExternalFileSetByPath

!! ------------------------
!! Re: metadatum checksum
!! ------------------------

!! Has, by checksum
function ExternalFilesExternalFileHasByChecksum(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileHasByChecksum')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ExternalFilesExternalFileHasByChecksum
end function ExternalFilesExternalFileHasByChecksum

!! Get, by checksum, const
function ExternalFilesExternalFileGetByChecksumConst(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByChecksumConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByChecksumConst
end function ExternalFilesExternalFileGetByChecksumConst

!! Get, by checksum
function ExternalFilesExternalFileGetByChecksum(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByChecksum')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByChecksum
end function ExternalFilesExternalFileGetByChecksum

!! Set, by checksum
subroutine ExternalFilesExternalFileSetByChecksum(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ExternalFilesExternalFileSetByChecksum')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ExternalFilesExternalFileSetByChecksum

!! ------------------------
!! Re: metadatum algorithm
!! ------------------------

!! Has, by algorithm
function ExternalFilesExternalFileHasByAlgorithm(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileHasByAlgorithm')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ExternalFilesExternalFileHasByAlgorithm
end function ExternalFilesExternalFileHasByAlgorithm

!! Get, by algorithm, const
function ExternalFilesExternalFileGetByAlgorithmConst(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByAlgorithmConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByAlgorithmConst
end function ExternalFilesExternalFileGetByAlgorithmConst

!! Get, by algorithm
function ExternalFilesExternalFileGetByAlgorithm(handle, meta, metaSize) &
      bind(C, name='ExternalFilesExternalFileGetByAlgorithm')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ExternalFilesExternalFileGetByAlgorithm
end function ExternalFilesExternalFileGetByAlgorithm

!! Set, by algorithm
subroutine ExternalFilesExternalFileSetByAlgorithm(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ExternalFilesExternalFileSetByAlgorithm')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ExternalFilesExternalFileSetByAlgorithm


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalExternalFiles
