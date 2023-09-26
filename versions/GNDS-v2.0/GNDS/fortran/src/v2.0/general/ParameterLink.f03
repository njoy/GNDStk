
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalParameterLink
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ParameterLinkDefaultConst() &
      bind(C, name='ParameterLinkDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ParameterLinkDefaultConst
end function ParameterLinkDefaultConst

!! Create, default
function ParameterLinkDefault() &
      bind(C, name='ParameterLinkDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ParameterLinkDefault
end function ParameterLinkDefault

!! Create, general, const
function ParameterLinkCreateConst( &
   label, &
   href, &
   nParameters, &
   matrixStartIndex, &
   labelSize, &
   hrefSize &
) &
      bind(C, name='ParameterLinkCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_int), value, intent(in) :: nParameters
   integer(c_int), value, intent(in) :: matrixStartIndex
   type(c_ptr) :: ParameterLinkCreateConst
end function ParameterLinkCreateConst

!! Create, general
function ParameterLinkCreate( &
   label, &
   href, &
   nParameters, &
   matrixStartIndex, &
   labelSize, &
   hrefSize &
) &
      bind(C, name='ParameterLinkCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   integer(c_int), value, intent(in) :: nParameters
   integer(c_int), value, intent(in) :: matrixStartIndex
   type(c_ptr) :: ParameterLinkCreate
end function ParameterLinkCreate

!! Assign
subroutine ParameterLinkAssign(handleLHS, handleRHS) &
      bind(C, name='ParameterLinkAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine ParameterLinkAssign

!! Delete
subroutine ParameterLinkDelete(handle) &
      bind(C, name='ParameterLinkDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ParameterLinkDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ParameterLinkRead(handle, filename, filenameSize) &
      bind(C, name='ParameterLinkRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ParameterLinkRead
end function ParameterLinkRead

!! Write to file
function ParameterLinkWrite(handle, filename, filenameSize) &
      bind(C, name='ParameterLinkWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ParameterLinkWrite
end function ParameterLinkWrite

!! Print to standard output, in our prettyprinting format
function ParameterLinkPrint(handle) &
      bind(C, name='ParameterLinkPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkPrint
end function ParameterLinkPrint

!! Print to standard output, as XML
function ParameterLinkPrintXML(handle) &
      bind(C, name='ParameterLinkPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkPrintXML
end function ParameterLinkPrintXML

!! Print to standard output, as JSON
function ParameterLinkPrintJSON(handle) &
      bind(C, name='ParameterLinkPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkPrintJSON
end function ParameterLinkPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ParameterLinkLabelHas(handle) &
      bind(C, name='ParameterLinkLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkLabelHas
end function ParameterLinkLabelHas

!! Get
function ParameterLinkLabelGet(handle) &
      bind(C, name='ParameterLinkLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ParameterLinkLabelGet
end function ParameterLinkLabelGet

!! Set
subroutine ParameterLinkLabelSet(handle, label, labelSize) &
      bind(C, name='ParameterLinkLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ParameterLinkLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function ParameterLinkHrefHas(handle) &
      bind(C, name='ParameterLinkHrefHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkHrefHas
end function ParameterLinkHrefHas

!! Get
function ParameterLinkHrefGet(handle) &
      bind(C, name='ParameterLinkHrefGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ParameterLinkHrefGet
end function ParameterLinkHrefGet

!! Set
subroutine ParameterLinkHrefSet(handle, href, hrefSize) &
      bind(C, name='ParameterLinkHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine ParameterLinkHrefSet


!! -----------------------------------------------------------------------------
!! Metadatum: nParameters
!! -----------------------------------------------------------------------------

!! Has
function ParameterLinkNParametersHas(handle) &
      bind(C, name='ParameterLinkNParametersHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkNParametersHas
end function ParameterLinkNParametersHas

!! Get
function ParameterLinkNParametersGet(handle) &
      bind(C, name='ParameterLinkNParametersGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkNParametersGet
end function ParameterLinkNParametersGet

!! Set
subroutine ParameterLinkNParametersSet(handle, nParameters, nParametersSize) &
      bind(C, name='ParameterLinkNParametersSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: nParametersSize
   character(c_char), intent(in) :: nParameters(nParametersSize)
end subroutine ParameterLinkNParametersSet


!! -----------------------------------------------------------------------------
!! Metadatum: matrixStartIndex
!! -----------------------------------------------------------------------------

!! Has
function ParameterLinkMatrixStartIndexHas(handle) &
      bind(C, name='ParameterLinkMatrixStartIndexHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkMatrixStartIndexHas
end function ParameterLinkMatrixStartIndexHas

!! Get
function ParameterLinkMatrixStartIndexGet(handle) &
      bind(C, name='ParameterLinkMatrixStartIndexGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ParameterLinkMatrixStartIndexGet
end function ParameterLinkMatrixStartIndexGet

!! Set
subroutine ParameterLinkMatrixStartIndexSet(handle, matrixStartIndex, matrixStartIndexSize) &
      bind(C, name='ParameterLinkMatrixStartIndexSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: matrixStartIndexSize
   character(c_char), intent(in) :: matrixStartIndex(matrixStartIndexSize)
end subroutine ParameterLinkMatrixStartIndexSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalParameterLink
