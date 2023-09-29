
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalUncertainty
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function UncertaintyDefaultConst() &
      bind(C, name='UncertaintyDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: UncertaintyDefaultConst
end function UncertaintyDefaultConst

!! Create, default
function UncertaintyDefault() &
      bind(C, name='UncertaintyDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: UncertaintyDefault
end function UncertaintyDefault

!! Create, general, const
function UncertaintyCreateConst( &
   covariance, &
   standard, &
   listOfCovariances, &
   polynomial1d &
) &
      bind(C, name='UncertaintyCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: covariance
   type(c_ptr), intent(in), value :: standard
   type(c_ptr), intent(in), value :: listOfCovariances
   type(c_ptr), intent(in), value :: polynomial1d
   type(c_ptr) :: UncertaintyCreateConst
end function UncertaintyCreateConst

!! Create, general
function UncertaintyCreate( &
   covariance, &
   standard, &
   listOfCovariances, &
   polynomial1d &
) &
      bind(C, name='UncertaintyCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: covariance
   type(c_ptr), intent(in), value :: standard
   type(c_ptr), intent(in), value :: listOfCovariances
   type(c_ptr), intent(in), value :: polynomial1d
   type(c_ptr) :: UncertaintyCreate
end function UncertaintyCreate

!! Assign
subroutine UncertaintyAssign(handleLHS, handleRHS) &
      bind(C, name='UncertaintyAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine UncertaintyAssign

!! Delete
subroutine UncertaintyDelete(handle) &
      bind(C, name='UncertaintyDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine UncertaintyDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function UncertaintyRead(handle, filename, filenameSize) &
      bind(C, name='UncertaintyRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: UncertaintyRead
end function UncertaintyRead

!! Write to file
function UncertaintyWrite(handle, filename, filenameSize) &
      bind(C, name='UncertaintyWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: UncertaintyWrite
end function UncertaintyWrite

!! Print to standard output, in our prettyprinting format
function UncertaintyPrint(handle) &
      bind(C, name='UncertaintyPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UncertaintyPrint
end function UncertaintyPrint

!! Print to standard output, as XML
function UncertaintyPrintXML(handle) &
      bind(C, name='UncertaintyPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UncertaintyPrintXML
end function UncertaintyPrintXML

!! Print to standard output, as JSON
function UncertaintyPrintJSON(handle) &
      bind(C, name='UncertaintyPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UncertaintyPrintJSON
end function UncertaintyPrintJSON


!! -----------------------------------------------------------------------------
!! Child: covariance
!! -----------------------------------------------------------------------------

!! Has
function UncertaintyCovarianceHas(handle) &
      bind(C, name='UncertaintyCovarianceHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UncertaintyCovarianceHas
end function UncertaintyCovarianceHas

!! Get, const
function UncertaintyCovarianceGetConst(handle) &
      bind(C, name='UncertaintyCovarianceGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: UncertaintyCovarianceGetConst
end function UncertaintyCovarianceGetConst

!! Get
function UncertaintyCovarianceGet(handle) &
      bind(C, name='UncertaintyCovarianceGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: UncertaintyCovarianceGet
end function UncertaintyCovarianceGet

!! Set
subroutine UncertaintyCovarianceSet(handle, fieldHandle) &
      bind(C, name='UncertaintyCovarianceSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine UncertaintyCovarianceSet


!! -----------------------------------------------------------------------------
!! Child: standard
!! -----------------------------------------------------------------------------

!! Has
function UncertaintyStandardHas(handle) &
      bind(C, name='UncertaintyStandardHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UncertaintyStandardHas
end function UncertaintyStandardHas

!! Get, const
function UncertaintyStandardGetConst(handle) &
      bind(C, name='UncertaintyStandardGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: UncertaintyStandardGetConst
end function UncertaintyStandardGetConst

!! Get
function UncertaintyStandardGet(handle) &
      bind(C, name='UncertaintyStandardGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: UncertaintyStandardGet
end function UncertaintyStandardGet

!! Set
subroutine UncertaintyStandardSet(handle, fieldHandle) &
      bind(C, name='UncertaintyStandardSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine UncertaintyStandardSet


!! -----------------------------------------------------------------------------
!! Child: listOfCovariances
!! -----------------------------------------------------------------------------

!! Has
function UncertaintyListOfCovariancesHas(handle) &
      bind(C, name='UncertaintyListOfCovariancesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UncertaintyListOfCovariancesHas
end function UncertaintyListOfCovariancesHas

!! Get, const
function UncertaintyListOfCovariancesGetConst(handle) &
      bind(C, name='UncertaintyListOfCovariancesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: UncertaintyListOfCovariancesGetConst
end function UncertaintyListOfCovariancesGetConst

!! Get
function UncertaintyListOfCovariancesGet(handle) &
      bind(C, name='UncertaintyListOfCovariancesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: UncertaintyListOfCovariancesGet
end function UncertaintyListOfCovariancesGet

!! Set
subroutine UncertaintyListOfCovariancesSet(handle, fieldHandle) &
      bind(C, name='UncertaintyListOfCovariancesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine UncertaintyListOfCovariancesSet


!! -----------------------------------------------------------------------------
!! Child: polynomial1d
!! -----------------------------------------------------------------------------

!! Has
function UncertaintyPolynomial1dHas(handle) &
      bind(C, name='UncertaintyPolynomial1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: UncertaintyPolynomial1dHas
end function UncertaintyPolynomial1dHas

!! Get, const
function UncertaintyPolynomial1dGetConst(handle) &
      bind(C, name='UncertaintyPolynomial1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: UncertaintyPolynomial1dGetConst
end function UncertaintyPolynomial1dGetConst

!! Get
function UncertaintyPolynomial1dGet(handle) &
      bind(C, name='UncertaintyPolynomial1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: UncertaintyPolynomial1dGet
end function UncertaintyPolynomial1dGet

!! Set
subroutine UncertaintyPolynomial1dSet(handle, fieldHandle) &
      bind(C, name='UncertaintyPolynomial1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine UncertaintyPolynomial1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalUncertainty
