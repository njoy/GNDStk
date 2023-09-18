
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalListOfCovariances
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ListOfCovariancesDefaultConst() &
      bind(C, name='ListOfCovariancesDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ListOfCovariancesDefaultConst

!! Create, default
function ListOfCovariancesDefault() &
      bind(C, name='ListOfCovariancesDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ListOfCovariancesDefault

!! Create, general, const
function ListOfCovariancesCreateConst( &
   covariance, covarianceSize &
) &
      bind(C, name='ListOfCovariancesCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: covarianceSize
   type(c_ptr) :: covariance(covarianceSize)
   type(c_ptr) :: handle
end function ListOfCovariancesCreateConst

!! Create, general
function ListOfCovariancesCreate( &
   covariance, covarianceSize &
) &
      bind(C, name='ListOfCovariancesCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: covarianceSize
   type(c_ptr) :: covariance(covarianceSize)
   type(c_ptr) :: handle
end function ListOfCovariancesCreate

!! Assign
subroutine ListOfCovariancesAssign(handleLHS, handleRHS) &
      bind(C, name='ListOfCovariancesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ListOfCovariancesAssign

!! Delete
subroutine ListOfCovariancesDelete(handle) &
      bind(C, name='ListOfCovariancesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ListOfCovariancesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ListOfCovariancesRead(handle, filename, filenameSize) &
      bind(C, name='ListOfCovariancesRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ListOfCovariancesRead

!! Write to file
function ListOfCovariancesWrite(handle, filename, filenameSize) &
      bind(C, name='ListOfCovariancesWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ListOfCovariancesWrite

!! Print to standard output, in our prettyprinting format
function ListOfCovariancesPrint(handle) &
      bind(C, name='ListOfCovariancesPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ListOfCovariancesPrint

!! Print to standard output, as XML
function ListOfCovariancesPrintXML(handle) &
      bind(C, name='ListOfCovariancesPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ListOfCovariancesPrintXML

!! Print to standard output, as JSON
function ListOfCovariancesPrintJSON(handle) &
      bind(C, name='ListOfCovariancesPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ListOfCovariancesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: covariance
!! -----------------------------------------------------------------------------

!! Has
function ListOfCovariancesCovarianceHas(handle) &
      bind(C, name='ListOfCovariancesCovarianceHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ListOfCovariancesCovarianceHas

!! Clear
subroutine ListOfCovariancesCovarianceClear(handle) &
      bind(C, name='ListOfCovariancesCovarianceClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ListOfCovariancesCovarianceClear

!! Size
function ListOfCovariancesCovarianceSize(handle) &
      bind(C, name='ListOfCovariancesCovarianceSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function ListOfCovariancesCovarianceSize

!! Add
subroutine ListOfCovariancesCovarianceAdd(handle, fieldHandle) &
      bind(C, name='ListOfCovariancesCovarianceAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ListOfCovariancesCovarianceAdd

!! Get, by index \in [0,size), const
function ListOfCovariancesCovarianceGetConst(handle, index) &
      bind(C, name='ListOfCovariancesCovarianceGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ListOfCovariancesCovarianceGetConst

!! Get, by index \in [0,size)
function ListOfCovariancesCovarianceGet(handle, index) &
      bind(C, name='ListOfCovariancesCovarianceGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ListOfCovariancesCovarianceGet

!! Set, by index \in [0,size)
subroutine ListOfCovariancesCovarianceSet(handle, index, fieldHandle) &
      bind(C, name='ListOfCovariancesCovarianceSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ListOfCovariancesCovarianceSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ListOfCovariancesCovarianceHasByLabel(handle, meta, metaSize) &
      bind(C, name='ListOfCovariancesCovarianceHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ListOfCovariancesCovarianceHasByLabel

!! Get, by label, const
function ListOfCovariancesCovarianceGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ListOfCovariancesCovarianceGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ListOfCovariancesCovarianceGetByLabelConst

!! Get, by label
function ListOfCovariancesCovarianceGetByLabel(handle, meta, metaSize) &
      bind(C, name='ListOfCovariancesCovarianceGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ListOfCovariancesCovarianceGetByLabel

!! Set, by label
subroutine ListOfCovariancesCovarianceSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ListOfCovariancesCovarianceSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ListOfCovariancesCovarianceSetByLabel

!! ------------------------
!! Re: metadatum href
!! ------------------------

!! Has, by href
function ListOfCovariancesCovarianceHasByHref(handle, meta, metaSize) &
      bind(C, name='ListOfCovariancesCovarianceHasByHref') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ListOfCovariancesCovarianceHasByHref

!! Get, by href, const
function ListOfCovariancesCovarianceGetByHrefConst(handle, meta, metaSize) &
      bind(C, name='ListOfCovariancesCovarianceGetByHrefConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ListOfCovariancesCovarianceGetByHrefConst

!! Get, by href
function ListOfCovariancesCovarianceGetByHref(handle, meta, metaSize) &
      bind(C, name='ListOfCovariancesCovarianceGetByHref') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ListOfCovariancesCovarianceGetByHref

!! Set, by href
subroutine ListOfCovariancesCovarianceSetByHref(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ListOfCovariancesCovarianceSetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ListOfCovariancesCovarianceSetByHref


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalListOfCovariances
