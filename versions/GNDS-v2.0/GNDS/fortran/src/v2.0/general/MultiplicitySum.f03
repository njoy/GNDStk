
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalMultiplicitySum
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function MultiplicitySumDefaultConst() &
      bind(C, name='MultiplicitySumDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: MultiplicitySumDefaultConst
end function MultiplicitySumDefaultConst

!! Create, default
function MultiplicitySumDefault() &
      bind(C, name='MultiplicitySumDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: MultiplicitySumDefault
end function MultiplicitySumDefault

!! Create, general, const
function MultiplicitySumCreateConst( &
   label, &
   ENDF_MT, &
   multiplicity, &
   summands, &
   labelSize &
) &
      bind(C, name='MultiplicitySumCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), intent(in), value :: ENDF_MT
   type(c_ptr), intent(in), value :: multiplicity
   type(c_ptr), intent(in), value :: summands
   type(c_ptr) :: MultiplicitySumCreateConst
end function MultiplicitySumCreateConst

!! Create, general
function MultiplicitySumCreate( &
   label, &
   ENDF_MT, &
   multiplicity, &
   summands, &
   labelSize &
) &
      bind(C, name='MultiplicitySumCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_int), intent(in), value :: ENDF_MT
   type(c_ptr), intent(in), value :: multiplicity
   type(c_ptr), intent(in), value :: summands
   type(c_ptr) :: MultiplicitySumCreate
end function MultiplicitySumCreate

!! Assign
subroutine MultiplicitySumAssign(handleLHS, handleRHS) &
      bind(C, name='MultiplicitySumAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine MultiplicitySumAssign

!! Delete
subroutine MultiplicitySumDelete(handle) &
      bind(C, name='MultiplicitySumDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine MultiplicitySumDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function MultiplicitySumRead(handle, filename, filenameSize) &
      bind(C, name='MultiplicitySumRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: MultiplicitySumRead
end function MultiplicitySumRead

!! Write to file
function MultiplicitySumWrite(handle, filename, filenameSize) &
      bind(C, name='MultiplicitySumWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: MultiplicitySumWrite
end function MultiplicitySumWrite

!! Print to standard output, in our prettyprinting format
function MultiplicitySumPrint(handle) &
      bind(C, name='MultiplicitySumPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumPrint
end function MultiplicitySumPrint

!! Print to standard output, as XML
function MultiplicitySumPrintXML(handle) &
      bind(C, name='MultiplicitySumPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumPrintXML
end function MultiplicitySumPrintXML

!! Print to standard output, as JSON
function MultiplicitySumPrintJSON(handle) &
      bind(C, name='MultiplicitySumPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumPrintJSON
end function MultiplicitySumPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function MultiplicitySumLabelHas(handle) &
      bind(C, name='MultiplicitySumLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumLabelHas
end function MultiplicitySumLabelHas

!! Get
function MultiplicitySumLabelGet(handle) &
      bind(C, name='MultiplicitySumLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: MultiplicitySumLabelGet
end function MultiplicitySumLabelGet

!! Set
subroutine MultiplicitySumLabelSet(handle, label, labelSize) &
      bind(C, name='MultiplicitySumLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine MultiplicitySumLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: ENDF_MT
!! -----------------------------------------------------------------------------

!! Has
function MultiplicitySumENDFMTHas(handle) &
      bind(C, name='MultiplicitySumENDFMTHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumENDFMTHas
end function MultiplicitySumENDFMTHas

!! Get
function MultiplicitySumENDFMTGet(handle) &
      bind(C, name='MultiplicitySumENDFMTGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumENDFMTGet
end function MultiplicitySumENDFMTGet

!! Set
subroutine MultiplicitySumENDFMTSet(handle, ENDF_MT) &
      bind(C, name='MultiplicitySumENDFMTSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_int), intent(in), value :: ENDF_MT
end subroutine MultiplicitySumENDFMTSet


!! -----------------------------------------------------------------------------
!! Child: multiplicity
!! -----------------------------------------------------------------------------

!! Has
function MultiplicitySumMultiplicityHas(handle) &
      bind(C, name='MultiplicitySumMultiplicityHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumMultiplicityHas
end function MultiplicitySumMultiplicityHas

!! Get, const
function MultiplicitySumMultiplicityGetConst(handle) &
      bind(C, name='MultiplicitySumMultiplicityGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: MultiplicitySumMultiplicityGetConst
end function MultiplicitySumMultiplicityGetConst

!! Get
function MultiplicitySumMultiplicityGet(handle) &
      bind(C, name='MultiplicitySumMultiplicityGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: MultiplicitySumMultiplicityGet
end function MultiplicitySumMultiplicityGet

!! Set
subroutine MultiplicitySumMultiplicitySet(handle, fieldHandle) &
      bind(C, name='MultiplicitySumMultiplicitySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine MultiplicitySumMultiplicitySet


!! -----------------------------------------------------------------------------
!! Child: summands
!! -----------------------------------------------------------------------------

!! Has
function MultiplicitySumSummandsHas(handle) &
      bind(C, name='MultiplicitySumSummandsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: MultiplicitySumSummandsHas
end function MultiplicitySumSummandsHas

!! Get, const
function MultiplicitySumSummandsGetConst(handle) &
      bind(C, name='MultiplicitySumSummandsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: MultiplicitySumSummandsGetConst
end function MultiplicitySumSummandsGetConst

!! Get
function MultiplicitySumSummandsGet(handle) &
      bind(C, name='MultiplicitySumSummandsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: MultiplicitySumSummandsGet
end function MultiplicitySumSummandsGet

!! Set
subroutine MultiplicitySumSummandsSet(handle, fieldHandle) &
      bind(C, name='MultiplicitySumSummandsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine MultiplicitySumSummandsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalMultiplicitySum
