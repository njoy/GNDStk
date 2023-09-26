
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalENDFconversionFlags
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ENDFconversionFlagsDefaultConst() &
      bind(C, name='ENDFconversionFlagsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ENDFconversionFlagsDefaultConst
end function ENDFconversionFlagsDefaultConst

!! Create, default
function ENDFconversionFlagsDefault() &
      bind(C, name='ENDFconversionFlagsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ENDFconversionFlagsDefault
end function ENDFconversionFlagsDefault

!! Create, general, const
function ENDFconversionFlagsCreateConst( &
   flags, &
   href, &
   conversion, conversionSize, &
   flagsSize, &
   hrefSize &
) &
      bind(C, name='ENDFconversionFlagsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: flagsSize
   character(c_char), intent(in) :: flags(flagsSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_size_t), value :: conversionSize
   type(c_ptr) :: conversion(conversionSize)
   type(c_ptr) :: ENDFconversionFlagsCreateConst
end function ENDFconversionFlagsCreateConst

!! Create, general
function ENDFconversionFlagsCreate( &
   flags, &
   href, &
   conversion, conversionSize, &
   flagsSize, &
   hrefSize &
) &
      bind(C, name='ENDFconversionFlagsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: flagsSize
   character(c_char), intent(in) :: flags(flagsSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_size_t), value :: conversionSize
   type(c_ptr) :: conversion(conversionSize)
   type(c_ptr) :: ENDFconversionFlagsCreate
end function ENDFconversionFlagsCreate

!! Assign
subroutine ENDFconversionFlagsAssign(handleLHS, handleRHS) &
      bind(C, name='ENDFconversionFlagsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ENDFconversionFlagsAssign

!! Delete
subroutine ENDFconversionFlagsDelete(handle) &
      bind(C, name='ENDFconversionFlagsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ENDFconversionFlagsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ENDFconversionFlagsRead(handle, filename, filenameSize) &
      bind(C, name='ENDFconversionFlagsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ENDFconversionFlagsRead
end function ENDFconversionFlagsRead

!! Write to file
function ENDFconversionFlagsWrite(handle, filename, filenameSize) &
      bind(C, name='ENDFconversionFlagsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ENDFconversionFlagsWrite
end function ENDFconversionFlagsWrite

!! Print to standard output, in our prettyprinting format
function ENDFconversionFlagsPrint(handle) &
      bind(C, name='ENDFconversionFlagsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDFconversionFlagsPrint
end function ENDFconversionFlagsPrint

!! Print to standard output, as XML
function ENDFconversionFlagsPrintXML(handle) &
      bind(C, name='ENDFconversionFlagsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDFconversionFlagsPrintXML
end function ENDFconversionFlagsPrintXML

!! Print to standard output, as JSON
function ENDFconversionFlagsPrintJSON(handle) &
      bind(C, name='ENDFconversionFlagsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDFconversionFlagsPrintJSON
end function ENDFconversionFlagsPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: flags
!! -----------------------------------------------------------------------------

!! Has
function ENDFconversionFlagsFlagsHas(handle) &
      bind(C, name='ENDFconversionFlagsFlagsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDFconversionFlagsFlagsHas
end function ENDFconversionFlagsFlagsHas

!! Get
function ENDFconversionFlagsFlagsGet(handle) &
      bind(C, name='ENDFconversionFlagsFlagsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ENDFconversionFlagsFlagsGet
end function ENDFconversionFlagsFlagsGet

!! Set
subroutine ENDFconversionFlagsFlagsSet(handle, flags, flagsSize) &
      bind(C, name='ENDFconversionFlagsFlagsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: flagsSize
   character(c_char), intent(in) :: flags(flagsSize)
end subroutine ENDFconversionFlagsFlagsSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function ENDFconversionFlagsHrefHas(handle) &
      bind(C, name='ENDFconversionFlagsHrefHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDFconversionFlagsHrefHas
end function ENDFconversionFlagsHrefHas

!! Get
function ENDFconversionFlagsHrefGet(handle) &
      bind(C, name='ENDFconversionFlagsHrefGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ENDFconversionFlagsHrefGet
end function ENDFconversionFlagsHrefGet

!! Set
subroutine ENDFconversionFlagsHrefSet(handle, href, hrefSize) &
      bind(C, name='ENDFconversionFlagsHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine ENDFconversionFlagsHrefSet


!! -----------------------------------------------------------------------------
!! Child: conversion
!! -----------------------------------------------------------------------------

!! Has
function ENDFconversionFlagsConversionHas(handle) &
      bind(C, name='ENDFconversionFlagsConversionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ENDFconversionFlagsConversionHas
end function ENDFconversionFlagsConversionHas

!! Clear
subroutine ENDFconversionFlagsConversionClear(handle) &
      bind(C, name='ENDFconversionFlagsConversionClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ENDFconversionFlagsConversionClear

!! Size
function ENDFconversionFlagsConversionSize(handle) &
      bind(C, name='ENDFconversionFlagsConversionSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: ENDFconversionFlagsConversionSize
end function ENDFconversionFlagsConversionSize

!! Add
subroutine ENDFconversionFlagsConversionAdd(handle, fieldHandle) &
      bind(C, name='ENDFconversionFlagsConversionAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ENDFconversionFlagsConversionAdd

!! Get, by index \in [0,size), const
function ENDFconversionFlagsConversionGetConst(handle, index) &
      bind(C, name='ENDFconversionFlagsConversionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ENDFconversionFlagsConversionGetConst
end function ENDFconversionFlagsConversionGetConst

!! Get, by index \in [0,size)
function ENDFconversionFlagsConversionGet(handle, index) &
      bind(C, name='ENDFconversionFlagsConversionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: ENDFconversionFlagsConversionGet
end function ENDFconversionFlagsConversionGet

!! Set, by index \in [0,size)
subroutine ENDFconversionFlagsConversionSet(handle, index, fieldHandle) &
      bind(C, name='ENDFconversionFlagsConversionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ENDFconversionFlagsConversionSet

!! ------------------------
!! Re: metadatum flags
!! ------------------------

!! Has, by flags
function ENDFconversionFlagsConversionHasByFlags(handle, meta, metaSize) &
      bind(C, name='ENDFconversionFlagsConversionHasByFlags')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ENDFconversionFlagsConversionHasByFlags
end function ENDFconversionFlagsConversionHasByFlags

!! Get, by flags, const
function ENDFconversionFlagsConversionGetByFlagsConst(handle, meta, metaSize) &
      bind(C, name='ENDFconversionFlagsConversionGetByFlagsConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ENDFconversionFlagsConversionGetByFlagsConst
end function ENDFconversionFlagsConversionGetByFlagsConst

!! Get, by flags
function ENDFconversionFlagsConversionGetByFlags(handle, meta, metaSize) &
      bind(C, name='ENDFconversionFlagsConversionGetByFlags')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ENDFconversionFlagsConversionGetByFlags
end function ENDFconversionFlagsConversionGetByFlags

!! Set, by flags
subroutine ENDFconversionFlagsConversionSetByFlags(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ENDFconversionFlagsConversionSetByFlags')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ENDFconversionFlagsConversionSetByFlags

!! ------------------------
!! Re: metadatum href
!! ------------------------

!! Has, by href
function ENDFconversionFlagsConversionHasByHref(handle, meta, metaSize) &
      bind(C, name='ENDFconversionFlagsConversionHasByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: ENDFconversionFlagsConversionHasByHref
end function ENDFconversionFlagsConversionHasByHref

!! Get, by href, const
function ENDFconversionFlagsConversionGetByHrefConst(handle, meta, metaSize) &
      bind(C, name='ENDFconversionFlagsConversionGetByHrefConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ENDFconversionFlagsConversionGetByHrefConst
end function ENDFconversionFlagsConversionGetByHrefConst

!! Get, by href
function ENDFconversionFlagsConversionGetByHref(handle, meta, metaSize) &
      bind(C, name='ENDFconversionFlagsConversionGetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: ENDFconversionFlagsConversionGetByHref
end function ENDFconversionFlagsConversionGetByHref

!! Set, by href
subroutine ENDFconversionFlagsConversionSetByHref(handle, meta, metaSize, fieldHandle) &
      bind(C, name='ENDFconversionFlagsConversionSetByHref')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ENDFconversionFlagsConversionSetByHref


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalENDFconversionFlags
