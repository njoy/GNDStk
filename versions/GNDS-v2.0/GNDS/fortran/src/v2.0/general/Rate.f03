
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalRate
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function RateDefaultConst() &
      bind(C, name='RateDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function RateDefaultConst

!! Create, default
function RateDefault() &
      bind(C, name='RateDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function RateDefault

!! Create, general, const
function RateCreateConst( &
   Double &
) &
      bind(C, name='RateCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: Double
   type(c_ptr) :: handle
end function RateCreateConst

!! Create, general
function RateCreate( &
   Double &
) &
      bind(C, name='RateCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: Double
   type(c_ptr) :: handle
end function RateCreate

!! Assign
subroutine RateAssign(handleLHS, handleRHS) &
      bind(C, name='RateAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine RateAssign

!! Delete
subroutine RateDelete(handle) &
      bind(C, name='RateDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine RateDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function RateRead(handle, filename, filenameSize) &
      bind(C, name='RateRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function RateRead

!! Write to file
function RateWrite(handle, filename, filenameSize) &
      bind(C, name='RateWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function RateWrite

!! Print to standard output, in our prettyprinting format
function RatePrint(handle) &
      bind(C, name='RatePrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function RatePrint

!! Print to standard output, as XML
function RatePrintXML(handle) &
      bind(C, name='RatePrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function RatePrintXML

!! Print to standard output, as JSON
function RatePrintJSON(handle) &
      bind(C, name='RatePrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function RatePrintJSON


!! -----------------------------------------------------------------------------
!! Child: Double
!! -----------------------------------------------------------------------------

!! Has
function RateDoubleHas(handle) &
      bind(C, name='RateDoubleHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function RateDoubleHas

!! Get, const
function RateDoubleGetConst(handle) &
      bind(C, name='RateDoubleGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function RateDoubleGetConst

!! Get
function RateDoubleGet(handle) &
      bind(C, name='RateDoubleGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function RateDoubleGet

!! Set
subroutine RateDoubleSet(handle, fieldHandle) &
      bind(C, name='RateDoubleSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine RateDoubleSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalRate
