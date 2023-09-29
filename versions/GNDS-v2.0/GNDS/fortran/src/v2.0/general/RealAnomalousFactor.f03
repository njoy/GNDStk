
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalRealAnomalousFactor
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function RealAnomalousFactorDefaultConst() &
      bind(C, name='RealAnomalousFactorDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: RealAnomalousFactorDefaultConst
end function RealAnomalousFactorDefaultConst

!! Create, default, non-const
function RealAnomalousFactorDefault() &
      bind(C, name='RealAnomalousFactorDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: RealAnomalousFactorDefault
end function RealAnomalousFactorDefault

!! Create, general, const
function RealAnomalousFactorCreateConst( &
   XYs1d &
) &
      bind(C, name='RealAnomalousFactorCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: RealAnomalousFactorCreateConst
end function RealAnomalousFactorCreateConst

!! Create, general, non-const
function RealAnomalousFactorCreate( &
   XYs1d &
) &
      bind(C, name='RealAnomalousFactorCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: XYs1d
   type(c_ptr) :: RealAnomalousFactorCreate
end function RealAnomalousFactorCreate

!! Assign
subroutine RealAnomalousFactorAssign(handleLHS, handleRHS) &
      bind(C, name='RealAnomalousFactorAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine RealAnomalousFactorAssign

!! Delete
subroutine RealAnomalousFactorDelete(handle) &
      bind(C, name='RealAnomalousFactorDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine RealAnomalousFactorDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function RealAnomalousFactorRead(handle, filename, filenameSize) &
      bind(C, name='RealAnomalousFactorRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: RealAnomalousFactorRead
end function RealAnomalousFactorRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function RealAnomalousFactorWrite(handle, filename, filenameSize) &
      bind(C, name='RealAnomalousFactorWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: RealAnomalousFactorWrite
end function RealAnomalousFactorWrite

!! Print to standard output, in our prettyprinting format
function RealAnomalousFactorPrint(handle) &
      bind(C, name='RealAnomalousFactorPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RealAnomalousFactorPrint
end function RealAnomalousFactorPrint

!! Print to standard output, as XML
function RealAnomalousFactorPrintXML(handle) &
      bind(C, name='RealAnomalousFactorPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RealAnomalousFactorPrintXML
end function RealAnomalousFactorPrintXML

!! Print to standard output, as JSON
function RealAnomalousFactorPrintJSON(handle) &
      bind(C, name='RealAnomalousFactorPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RealAnomalousFactorPrintJSON
end function RealAnomalousFactorPrintJSON


!! -----------------------------------------------------------------------------
!! Child: XYs1d
!! -----------------------------------------------------------------------------

!! Has
function RealAnomalousFactorXYs1dHas(handle) &
      bind(C, name='RealAnomalousFactorXYs1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: RealAnomalousFactorXYs1dHas
end function RealAnomalousFactorXYs1dHas

!! Get, const
function RealAnomalousFactorXYs1dGetConst(handle) &
      bind(C, name='RealAnomalousFactorXYs1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: RealAnomalousFactorXYs1dGetConst
end function RealAnomalousFactorXYs1dGetConst

!! Get, non-const
function RealAnomalousFactorXYs1dGet(handle) &
      bind(C, name='RealAnomalousFactorXYs1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: RealAnomalousFactorXYs1dGet
end function RealAnomalousFactorXYs1dGet

!! Set
subroutine RealAnomalousFactorXYs1dSet(handle, fieldHandle) &
      bind(C, name='RealAnomalousFactorXYs1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine RealAnomalousFactorXYs1dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalRealAnomalousFactor
