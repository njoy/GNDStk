
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module reducedFunction1ds
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function Function1dsDefaultConst() &
      bind(C, name='Function1dsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Function1dsDefaultConst
end function Function1dsDefaultConst

!! Create, default
function Function1dsDefault() &
      bind(C, name='Function1dsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Function1dsDefault
end function Function1dsDefault

!! Create, general, const
function Function1dsCreateConst( &
   Legendre, LegendreSize, &
   XYs1d, XYs1dSize &
) &
      bind(C, name='Function1dsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: LegendreSize
   type(c_ptr), intent(in) :: Legendre(LegendreSize)
   integer(c_size_t), intent(in), value :: XYs1dSize
   type(c_ptr), intent(in) :: XYs1d(XYs1dSize)
   type(c_ptr) :: Function1dsCreateConst
end function Function1dsCreateConst

!! Create, general
function Function1dsCreate( &
   Legendre, LegendreSize, &
   XYs1d, XYs1dSize &
) &
      bind(C, name='Function1dsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: LegendreSize
   type(c_ptr), intent(in) :: Legendre(LegendreSize)
   integer(c_size_t), intent(in), value :: XYs1dSize
   type(c_ptr), intent(in) :: XYs1d(XYs1dSize)
   type(c_ptr) :: Function1dsCreate
end function Function1dsCreate

!! Assign
subroutine Function1dsAssign(handleLHS, handleRHS) &
      bind(C, name='Function1dsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine Function1dsAssign

!! Delete
subroutine Function1dsDelete(handle) &
      bind(C, name='Function1dsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine Function1dsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function Function1dsRead(handle, filename, filenameSize) &
      bind(C, name='Function1dsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Function1dsRead
end function Function1dsRead

!! Write to file
function Function1dsWrite(handle, filename, filenameSize) &
      bind(C, name='Function1dsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Function1dsWrite
end function Function1dsWrite

!! Print to standard output, in our prettyprinting format
function Function1dsPrint(handle) &
      bind(C, name='Function1dsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function1dsPrint
end function Function1dsPrint

!! Print to standard output, as XML
function Function1dsPrintXML(handle) &
      bind(C, name='Function1dsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function1dsPrintXML
end function Function1dsPrintXML

!! Print to standard output, as JSON
function Function1dsPrintJSON(handle) &
      bind(C, name='Function1dsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function1dsPrintJSON
end function Function1dsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: Legendre
!! -----------------------------------------------------------------------------

!! Has
function Function1dsLegendreHas(handle) &
      bind(C, name='Function1dsLegendreHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function1dsLegendreHas
end function Function1dsLegendreHas

!! Clear
subroutine Function1dsLegendreClear(handle) &
      bind(C, name='Function1dsLegendreClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine Function1dsLegendreClear

!! Size
function Function1dsLegendreSize(handle) &
      bind(C, name='Function1dsLegendreSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: Function1dsLegendreSize
end function Function1dsLegendreSize

!! Add
subroutine Function1dsLegendreAdd(handle, fieldHandle) &
      bind(C, name='Function1dsLegendreAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsLegendreAdd

!! Get, by index \in [0,size), const
function Function1dsLegendreGetConst(handle, index) &
      bind(C, name='Function1dsLegendreGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: Function1dsLegendreGetConst
end function Function1dsLegendreGetConst

!! Get, by index \in [0,size)
function Function1dsLegendreGet(handle, index) &
      bind(C, name='Function1dsLegendreGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: Function1dsLegendreGet
end function Function1dsLegendreGet

!! Set, by index \in [0,size)
subroutine Function1dsLegendreSet(handle, index, fieldHandle) &
      bind(C, name='Function1dsLegendreSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsLegendreSet

!! ------------------------
!! Re: metadatum outerDomainValue
!! ------------------------

!! Has, by outerDomainValue
function Function1dsLegendreHasByOuterDomainValue(handle, meta) &
      bind(C, name='Function1dsLegendreHasByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), intent(in), value :: meta
   integer(c_int) :: Function1dsLegendreHasByOuterDomainValue
end function Function1dsLegendreHasByOuterDomainValue

!! Get, by outerDomainValue, const
function Function1dsLegendreGetByOuterDomainValueConst(handle, meta) &
      bind(C, name='Function1dsLegendreGetByOuterDomainValueConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr) :: Function1dsLegendreGetByOuterDomainValueConst
end function Function1dsLegendreGetByOuterDomainValueConst

!! Get, by outerDomainValue
function Function1dsLegendreGetByOuterDomainValue(handle, meta) &
      bind(C, name='Function1dsLegendreGetByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr) :: Function1dsLegendreGetByOuterDomainValue
end function Function1dsLegendreGetByOuterDomainValue

!! Set, by outerDomainValue
subroutine Function1dsLegendreSetByOuterDomainValue(handle, meta, fieldHandle) &
      bind(C, name='Function1dsLegendreSetByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsLegendreSetByOuterDomainValue


!! -----------------------------------------------------------------------------
!! Child: XYs1d
!! -----------------------------------------------------------------------------

!! Has
function Function1dsXYs1dHas(handle) &
      bind(C, name='Function1dsXYs1dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Function1dsXYs1dHas
end function Function1dsXYs1dHas

!! Clear
subroutine Function1dsXYs1dClear(handle) &
      bind(C, name='Function1dsXYs1dClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine Function1dsXYs1dClear

!! Size
function Function1dsXYs1dSize(handle) &
      bind(C, name='Function1dsXYs1dSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: Function1dsXYs1dSize
end function Function1dsXYs1dSize

!! Add
subroutine Function1dsXYs1dAdd(handle, fieldHandle) &
      bind(C, name='Function1dsXYs1dAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsXYs1dAdd

!! Get, by index \in [0,size), const
function Function1dsXYs1dGetConst(handle, index) &
      bind(C, name='Function1dsXYs1dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: Function1dsXYs1dGetConst
end function Function1dsXYs1dGetConst

!! Get, by index \in [0,size)
function Function1dsXYs1dGet(handle, index) &
      bind(C, name='Function1dsXYs1dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: Function1dsXYs1dGet
end function Function1dsXYs1dGet

!! Set, by index \in [0,size)
subroutine Function1dsXYs1dSet(handle, index, fieldHandle) &
      bind(C, name='Function1dsXYs1dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsXYs1dSet

!! ------------------------
!! Re: metadatum label
!! ------------------------

!! Has, by label
function Function1dsXYs1dHasByLabel(handle, meta, metaSize) &
      bind(C, name='Function1dsXYs1dHasByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: Function1dsXYs1dHasByLabel
end function Function1dsXYs1dHasByLabel

!! Get, by label, const
function Function1dsXYs1dGetByLabelConst(handle, meta, metaSize) &
      bind(C, name='Function1dsXYs1dGetByLabelConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function1dsXYs1dGetByLabelConst
end function Function1dsXYs1dGetByLabelConst

!! Get, by label
function Function1dsXYs1dGetByLabel(handle, meta, metaSize) &
      bind(C, name='Function1dsXYs1dGetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function1dsXYs1dGetByLabel
end function Function1dsXYs1dGetByLabel

!! Set, by label
subroutine Function1dsXYs1dSetByLabel(handle, meta, metaSize, fieldHandle) &
      bind(C, name='Function1dsXYs1dSetByLabel')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsXYs1dSetByLabel

!! ------------------------
!! Re: metadatum index
!! ------------------------

!! Has, by index
function Function1dsXYs1dHasByIndex(handle, meta) &
      bind(C, name='Function1dsXYs1dHasByIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   integer(c_int) :: Function1dsXYs1dHasByIndex
end function Function1dsXYs1dHasByIndex

!! Get, by index, const
function Function1dsXYs1dGetByIndexConst(handle, meta) &
      bind(C, name='Function1dsXYs1dGetByIndexConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: Function1dsXYs1dGetByIndexConst
end function Function1dsXYs1dGetByIndexConst

!! Get, by index
function Function1dsXYs1dGetByIndex(handle, meta) &
      bind(C, name='Function1dsXYs1dGetByIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr) :: Function1dsXYs1dGetByIndex
end function Function1dsXYs1dGetByIndex

!! Set, by index
subroutine Function1dsXYs1dSetByIndex(handle, meta, fieldHandle) &
      bind(C, name='Function1dsXYs1dSetByIndex')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsXYs1dSetByIndex

!! ------------------------
!! Re: metadatum interpolation
!! ------------------------

!! Has, by interpolation
function Function1dsXYs1dHasByInterpolation(handle, meta, metaSize) &
      bind(C, name='Function1dsXYs1dHasByInterpolation')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: Function1dsXYs1dHasByInterpolation
end function Function1dsXYs1dHasByInterpolation

!! Get, by interpolation, const
function Function1dsXYs1dGetByInterpolationConst(handle, meta, metaSize) &
      bind(C, name='Function1dsXYs1dGetByInterpolationConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function1dsXYs1dGetByInterpolationConst
end function Function1dsXYs1dGetByInterpolationConst

!! Get, by interpolation
function Function1dsXYs1dGetByInterpolation(handle, meta, metaSize) &
      bind(C, name='Function1dsXYs1dGetByInterpolation')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: Function1dsXYs1dGetByInterpolation
end function Function1dsXYs1dGetByInterpolation

!! Set, by interpolation
subroutine Function1dsXYs1dSetByInterpolation(handle, meta, metaSize, fieldHandle) &
      bind(C, name='Function1dsXYs1dSetByInterpolation')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsXYs1dSetByInterpolation

!! ------------------------
!! Re: metadatum outerDomainValue
!! ------------------------

!! Has, by outerDomainValue
function Function1dsXYs1dHasByOuterDomainValue(handle, meta) &
      bind(C, name='Function1dsXYs1dHasByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), intent(in), value :: meta
   integer(c_int) :: Function1dsXYs1dHasByOuterDomainValue
end function Function1dsXYs1dHasByOuterDomainValue

!! Get, by outerDomainValue, const
function Function1dsXYs1dGetByOuterDomainValueConst(handle, meta) &
      bind(C, name='Function1dsXYs1dGetByOuterDomainValueConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr) :: Function1dsXYs1dGetByOuterDomainValueConst
end function Function1dsXYs1dGetByOuterDomainValueConst

!! Get, by outerDomainValue
function Function1dsXYs1dGetByOuterDomainValue(handle, meta) &
      bind(C, name='Function1dsXYs1dGetByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr) :: Function1dsXYs1dGetByOuterDomainValue
end function Function1dsXYs1dGetByOuterDomainValue

!! Set, by outerDomainValue
subroutine Function1dsXYs1dSetByOuterDomainValue(handle, meta, fieldHandle) &
      bind(C, name='Function1dsXYs1dSetByOuterDomainValue')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   real(c_double), intent(in), value :: meta
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine Function1dsXYs1dSetByOuterDomainValue


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module reducedFunction1ds
