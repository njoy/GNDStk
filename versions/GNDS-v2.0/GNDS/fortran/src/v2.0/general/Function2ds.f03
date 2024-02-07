
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalFunction2ds
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function Function2dsDefaultConst() &
      bind(C, name='Function2dsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Function2dsDefaultConst
end function Function2dsDefaultConst

!! Create, default, non-const
function Function2dsDefault() &
      bind(C, name='Function2dsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Function2dsDefault
end function Function2dsDefault

!! Create, general, const
function Function2dsCreateConst( &
   XYs2d, XYs2dSize &
) &
      bind(C, name='Function2dsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: XYs2dSize
   type(c_ptr), intent(in) :: XYs2d(XYs2dSize)
   type(c_ptr) :: Function2dsCreateConst
end function Function2dsCreateConst

!! Create, general, non-const
function Function2dsCreate( &
   XYs2d, XYs2dSize &
) &
      bind(C, name='Function2dsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: XYs2dSize
   type(c_ptr), intent(in) :: XYs2d(XYs2dSize)
   type(c_ptr) :: Function2dsCreate
end function Function2dsCreate

!! Assign
subroutine Function2dsAssign(handleLHS, handleRHS) &
      bind(C, name='Function2dsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine Function2dsAssign

!! Delete
subroutine Function2dsDelete(handle) &
      bind(C, name='Function2dsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine Function2dsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function Function2dsRead(handle, filename, filenameSize) &
      bind(C, name='Function2dsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Function2dsRead
end function Function2dsRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function Function2dsWrite(handle, filename, filenameSize) &
      bind(C, name='Function2dsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Function2dsWrite
end function Function2dsWrite

!! Print to standard output, in our prettyprinting format
function Function2dsPrint(handle) &
      bind(C, name='Function2dsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function2dsPrint
end function Function2dsPrint

!! Print to standard output, as XML
function Function2dsPrintXML(handle) &
      bind(C, name='Function2dsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function2dsPrintXML
end function Function2dsPrintXML

!! Print to standard output, as JSON
function Function2dsPrintJSON(handle) &
      bind(C, name='Function2dsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function2dsPrintJSON
end function Function2dsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: XYs2d
!! -----------------------------------------------------------------------------

!! Has
function Function2dsXYs2dHas(handle) &
      bind(C, name='Function2dsXYs2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function2dsXYs2dHas
end function Function2dsXYs2dHas

!! Clear
subroutine Function2dsXYs2dClear(handle) &
      bind(C, name='Function2dsXYs2dClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine Function2dsXYs2dClear

!! Size
function Function2dsXYs2dSize(handle) &
      bind(C, name='Function2dsXYs2dSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: Function2dsXYs2dSize
end function Function2dsXYs2dSize

!! Add
subroutine Function2dsXYs2dAdd(handle, fieldHandle) &
      bind(C, name='Function2dsXYs2dAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function2dsXYs2dAdd

!! Get, by index \in [0,size), const
function Function2dsXYs2dGetConst(handle, index) &
      bind(C, name='Function2dsXYs2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: Function2dsXYs2dGetConst
end function Function2dsXYs2dGetConst

!! Get, by index \in [0,size), non-const
function Function2dsXYs2dGet(handle, index) &
      bind(C, name='Function2dsXYs2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: Function2dsXYs2dGet
end function Function2dsXYs2dGet

!! Set, by index \in [0,size)
subroutine Function2dsXYs2dSet(handle, index, fieldHandle) &
      bind(C, name='Function2dsXYs2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function2dsXYs2dSet

!! ------------------------
!! Re: metadatum index
!! ------------------------

!! Has, by index
function Function2dsXYs2dHasByIndex(handle, meta) &
      bind(C, name='Function2dsXYs2dHasByIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: Function2dsXYs2dHasByIndex
end function Function2dsXYs2dHasByIndex

!! Get, by index, const
function Function2dsXYs2dGetByIndexConst(handle, meta) &
      bind(C, name='Function2dsXYs2dGetByIndexConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: Function2dsXYs2dGetByIndexConst
end function Function2dsXYs2dGetByIndexConst

!! Get, by index, non-const
function Function2dsXYs2dGetByIndex(handle, meta) &
      bind(C, name='Function2dsXYs2dGetByIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: Function2dsXYs2dGetByIndex
end function Function2dsXYs2dGetByIndex

!! Set, by index
subroutine Function2dsXYs2dSetByIndex(handle, meta, fieldHandle) &
      bind(C, name='Function2dsXYs2dSetByIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function2dsXYs2dSetByIndex

!! ------------------------
!! Re: metadatum interpolation
!! ------------------------

!! Has, by interpolation
function Function2dsXYs2dHasByInterpolation(handle, meta, metaSize) &
      bind(C, name='Function2dsXYs2dHasByInterpolation')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: Function2dsXYs2dHasByInterpolation
end function Function2dsXYs2dHasByInterpolation

!! Get, by interpolation, const
function Function2dsXYs2dGetByInterpolationConst(handle, meta, metaSize) &
      bind(C, name='Function2dsXYs2dGetByInterpolationConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function2dsXYs2dGetByInterpolationConst
end function Function2dsXYs2dGetByInterpolationConst

!! Get, by interpolation, non-const
function Function2dsXYs2dGetByInterpolation(handle, meta, metaSize) &
      bind(C, name='Function2dsXYs2dGetByInterpolation')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function2dsXYs2dGetByInterpolation
end function Function2dsXYs2dGetByInterpolation

!! Set, by interpolation
subroutine Function2dsXYs2dSetByInterpolation(handle, meta, metaSize, fieldHandle) &
      bind(C, name='Function2dsXYs2dSetByInterpolation')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function2dsXYs2dSetByInterpolation

!! ------------------------
!! Re: metadatum interpolationQualifier
!! ------------------------

!! Has, by interpolationQualifier
function Function2dsXYs2dHasByInterpolationQualifier(handle, meta, metaSize) &
      bind(C, name='Function2dsXYs2dHasByInterpolationQualifier')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: Function2dsXYs2dHasByInterpolationQualifier
end function Function2dsXYs2dHasByInterpolationQualifier

!! Get, by interpolationQualifier, const
function Function2dsXYs2dGetByInterpolationQualifierConst(handle, meta, metaSize) &
      bind(C, name='Function2dsXYs2dGetByInterpolationQualifierConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function2dsXYs2dGetByInterpolationQualifierConst
end function Function2dsXYs2dGetByInterpolationQualifierConst

!! Get, by interpolationQualifier, non-const
function Function2dsXYs2dGetByInterpolationQualifier(handle, meta, metaSize) &
      bind(C, name='Function2dsXYs2dGetByInterpolationQualifier')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function2dsXYs2dGetByInterpolationQualifier
end function Function2dsXYs2dGetByInterpolationQualifier

!! Set, by interpolationQualifier
subroutine Function2dsXYs2dSetByInterpolationQualifier(handle, meta, metaSize, fieldHandle) &
      bind(C, name='Function2dsXYs2dSetByInterpolationQualifier')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function2dsXYs2dSetByInterpolationQualifier

!! ------------------------
!! Re: metadatum outerDomainValue
!! ------------------------

!! Has, by outerDomainValue
function Function2dsXYs2dHasByOuterDomainValue(handle, meta) &
      bind(C, name='Function2dsXYs2dHasByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), intent(in), value :: meta
   integer(c_int) :: Function2dsXYs2dHasByOuterDomainValue
end function Function2dsXYs2dHasByOuterDomainValue

!! Get, by outerDomainValue, const
function Function2dsXYs2dGetByOuterDomainValueConst(handle, meta) &
      bind(C, name='Function2dsXYs2dGetByOuterDomainValueConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr) :: Function2dsXYs2dGetByOuterDomainValueConst
end function Function2dsXYs2dGetByOuterDomainValueConst

!! Get, by outerDomainValue, non-const
function Function2dsXYs2dGetByOuterDomainValue(handle, meta) &
      bind(C, name='Function2dsXYs2dGetByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr) :: Function2dsXYs2dGetByOuterDomainValue
end function Function2dsXYs2dGetByOuterDomainValue

!! Set, by outerDomainValue
subroutine Function2dsXYs2dSetByOuterDomainValue(handle, meta, fieldHandle) &
      bind(C, name='Function2dsXYs2dSetByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function2dsXYs2dSetByOuterDomainValue


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalFunction2ds