
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalParameterCovariances
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ParameterCovariancesDefaultConst() &
      bind(C, name='ParameterCovariancesDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ParameterCovariancesDefaultConst

!! Create, default
function ParameterCovariancesDefault() &
      bind(C, name='ParameterCovariancesDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function ParameterCovariancesDefault

!! Create, general, const
function ParameterCovariancesCreateConst( &
   parameterCovariance, parameterCovarianceSize, &
   averageParameterCovariance, averageParameterCovarianceSize &
) &
      bind(C, name='ParameterCovariancesCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: parameterCovarianceSize
   type(c_ptr) :: parameterCovariance(parameterCovarianceSize)
   integer(c_size_t), value :: averageParameterCovarianceSize
   type(c_ptr) :: averageParameterCovariance(averageParameterCovarianceSize)
   type(c_ptr) :: handle
end function ParameterCovariancesCreateConst

!! Create, general
function ParameterCovariancesCreate( &
   parameterCovariance, parameterCovarianceSize, &
   averageParameterCovariance, averageParameterCovarianceSize &
) &
      bind(C, name='ParameterCovariancesCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), value :: parameterCovarianceSize
   type(c_ptr) :: parameterCovariance(parameterCovarianceSize)
   integer(c_size_t), value :: averageParameterCovarianceSize
   type(c_ptr) :: averageParameterCovariance(averageParameterCovarianceSize)
   type(c_ptr) :: handle
end function ParameterCovariancesCreate

!! Assign
subroutine ParameterCovariancesAssign(handleLHS, handleRHS) &
      bind(C, name='ParameterCovariancesAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ParameterCovariancesAssign

!! Delete
subroutine ParameterCovariancesDelete(handle) &
      bind(C, name='ParameterCovariancesDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ParameterCovariancesDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ParameterCovariancesRead(handle, filename, filenameSize) &
      bind(C, name='ParameterCovariancesRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ParameterCovariancesRead

!! Write to file
function ParameterCovariancesWrite(handle, filename, filenameSize) &
      bind(C, name='ParameterCovariancesWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function ParameterCovariancesWrite

!! Print to standard output, in our prettyprinting format
function ParameterCovariancesPrint(handle) &
      bind(C, name='ParameterCovariancesPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ParameterCovariancesPrint

!! Print to standard output, as XML
function ParameterCovariancesPrintXML(handle) &
      bind(C, name='ParameterCovariancesPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ParameterCovariancesPrintXML

!! Print to standard output, as JSON
function ParameterCovariancesPrintJSON(handle) &
      bind(C, name='ParameterCovariancesPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function ParameterCovariancesPrintJSON


!! -----------------------------------------------------------------------------
!! Child: parameterCovariance
!! -----------------------------------------------------------------------------

!! Has
function ParameterCovariancesParameterCovarianceHas(handle) &
      bind(C, name='ParameterCovariancesParameterCovarianceHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ParameterCovariancesParameterCovarianceHas

!! Clear
subroutine ParameterCovariancesParameterCovarianceClear(handle) &
      bind(C, name='ParameterCovariancesParameterCovarianceClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ParameterCovariancesParameterCovarianceClear

!! Size
function ParameterCovariancesParameterCovarianceSize(handle) &
      bind(C, name='ParameterCovariancesParameterCovarianceSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function ParameterCovariancesParameterCovarianceSize

!! Add
subroutine ParameterCovariancesParameterCovarianceAdd(handle, fieldHandle) &
      bind(C, name='ParameterCovariancesParameterCovarianceAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParameterCovariancesParameterCovarianceAdd

!! Get, by index \in [0,size), const
function ParameterCovariancesParameterCovarianceGetConst(handle, index) &
      bind(C, name='ParameterCovariancesParameterCovarianceGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ParameterCovariancesParameterCovarianceGetConst

!! Get, by index \in [0,size)
function ParameterCovariancesParameterCovarianceGet(handle, index) &
      bind(C, name='ParameterCovariancesParameterCovarianceGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ParameterCovariancesParameterCovarianceGet

!! Set, by index \in [0,size)
subroutine ParameterCovariancesParameterCovarianceSet(handle, index, fieldHandle) &
      bind(C, name='ParameterCovariancesParameterCovarianceSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParameterCovariancesParameterCovarianceSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ParameterCovariancesParameterCovarianceHasByLabel(handle, meta, metaSize) &
      bind(C, name='ParameterCovariancesParameterCovarianceHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ParameterCovariancesParameterCovarianceHasByLabel

!! Get, by label, const
function ParameterCovariancesParameterCovarianceGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ParameterCovariancesParameterCovarianceGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ParameterCovariancesParameterCovarianceGetByLabelConst

!! Get, by label
function ParameterCovariancesParameterCovarianceGetByLabel(handle, meta, metaSize) &
      bind(C, name='ParameterCovariancesParameterCovarianceGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ParameterCovariancesParameterCovarianceGetByLabel

!! Set, by label
subroutine ParameterCovariancesParameterCovarianceSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ParameterCovariancesParameterCovarianceSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParameterCovariancesParameterCovarianceSetByLabel


!! -----------------------------------------------------------------------------
!! Child: averageParameterCovariance
!! -----------------------------------------------------------------------------

!! Has
function ParameterCovariancesAverageParameterCovarianceHas(handle) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function ParameterCovariancesAverageParameterCovarianceHas

!! Clear
subroutine ParameterCovariancesAverageParameterCovarianceClear(handle) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ParameterCovariancesAverageParameterCovarianceClear

!! Size
function ParameterCovariancesAverageParameterCovarianceSize(handle) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceSize') &
      result(vectorSize)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: vectorSize
end function ParameterCovariancesAverageParameterCovarianceSize

!! Add
subroutine ParameterCovariancesAverageParameterCovarianceAdd(handle, fieldHandle) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParameterCovariancesAverageParameterCovarianceAdd

!! Get, by index \in [0,size), const
function ParameterCovariancesAverageParameterCovarianceGetConst(handle, index) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ParameterCovariancesAverageParameterCovarianceGetConst

!! Get, by index \in [0,size)
function ParameterCovariancesAverageParameterCovarianceGet(handle, index) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: resultHandle
end function ParameterCovariancesAverageParameterCovarianceGet

!! Set, by index \in [0,size)
subroutine ParameterCovariancesAverageParameterCovarianceSet(handle, index, fieldHandle) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParameterCovariancesAverageParameterCovarianceSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function ParameterCovariancesAverageParameterCovarianceHasByLabel(handle, meta, metaSize) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceHasByLabel') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: has
end function ParameterCovariancesAverageParameterCovarianceHasByLabel

!! Get, by label, const
function ParameterCovariancesAverageParameterCovarianceGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceGetByLabelConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ParameterCovariancesAverageParameterCovarianceGetByLabelConst

!! Get, by label
function ParameterCovariancesAverageParameterCovarianceGetByLabel(handle, meta, metaSize) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceGetByLabel') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: resultHandle
end function ParameterCovariancesAverageParameterCovarianceGetByLabel

!! Set, by label
subroutine ParameterCovariancesAverageParameterCovarianceSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParameterCovariancesAverageParameterCovarianceSetByLabel

!! ------------------------
!! Re: metadatum crossTerm
!! ------------------------

!! Has, by crossTerm
function ParameterCovariancesAverageParameterCovarianceHasByCrossTerm(handle, meta) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceHasByCrossTerm') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   unknownType, value, intent(in) :: meta
   integer(c_int) :: has
end function ParameterCovariancesAverageParameterCovarianceHasByCrossTerm

!! Get, by crossTerm, const
function ParameterCovariancesAverageParameterCovarianceGetByCrossTermConst(handle, meta) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceGetByCrossTermConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   unknownType, value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function ParameterCovariancesAverageParameterCovarianceGetByCrossTermConst

!! Get, by crossTerm
function ParameterCovariancesAverageParameterCovarianceGetByCrossTerm(handle, meta) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceGetByCrossTerm') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   unknownType, value, intent(in) :: meta
   type(c_ptr) :: resultHandle
end function ParameterCovariancesAverageParameterCovarianceGetByCrossTerm

!! Set, by crossTerm
subroutine ParameterCovariancesAverageParameterCovarianceSetByCrossTerm(handle, meta, fieldHandle) &
      bind(C, name='ParameterCovariancesAverageParameterCovarianceSetByCrossTerm')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   unknownType, value, intent(in) :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ParameterCovariancesAverageParameterCovarianceSetByCrossTerm


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalParameterCovariances
