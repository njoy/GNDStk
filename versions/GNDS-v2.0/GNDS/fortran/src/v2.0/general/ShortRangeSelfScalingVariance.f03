
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalShortRangeSelfScalingVariance
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ShortRangeSelfScalingVarianceDefaultConst() &
      bind(C, name='ShortRangeSelfScalingVarianceDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ShortRangeSelfScalingVarianceDefaultConst
end function ShortRangeSelfScalingVarianceDefaultConst

!! Create, default, non-const
function ShortRangeSelfScalingVarianceDefault() &
      bind(C, name='ShortRangeSelfScalingVarianceDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ShortRangeSelfScalingVarianceDefault
end function ShortRangeSelfScalingVarianceDefault

!! Create, general, const
function ShortRangeSelfScalingVarianceCreateConst( &
   label, &
   type1, &
   dependenceOnProcessedGroupWidth, &
   gridded2d, &
   labelSize, &
   type1Size, &
   dependenceOnProcessedGroupWidthSize &
) &
      bind(C, name='ShortRangeSelfScalingVarianceCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: type1Size
   character(c_char), intent(in) :: type1(type1Size)
   integer(c_size_t), intent(in), value :: dependenceOnProcessedGroupWidthSize
   character(c_char), intent(in) :: dependenceOnProcessedGroupWidth(dependenceOnProcessedGroupWidthSize)
   type(c_ptr), intent(in), value :: gridded2d
   type(c_ptr) :: ShortRangeSelfScalingVarianceCreateConst
end function ShortRangeSelfScalingVarianceCreateConst

!! Create, general, non-const
function ShortRangeSelfScalingVarianceCreate( &
   label, &
   type1, &
   dependenceOnProcessedGroupWidth, &
   gridded2d, &
   labelSize, &
   type1Size, &
   dependenceOnProcessedGroupWidthSize &
) &
      bind(C, name='ShortRangeSelfScalingVarianceCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: type1Size
   character(c_char), intent(in) :: type1(type1Size)
   integer(c_size_t), intent(in), value :: dependenceOnProcessedGroupWidthSize
   character(c_char), intent(in) :: dependenceOnProcessedGroupWidth(dependenceOnProcessedGroupWidthSize)
   type(c_ptr), intent(in), value :: gridded2d
   type(c_ptr) :: ShortRangeSelfScalingVarianceCreate
end function ShortRangeSelfScalingVarianceCreate

!! Assign
subroutine ShortRangeSelfScalingVarianceAssign(handleLHS, handleRHS) &
      bind(C, name='ShortRangeSelfScalingVarianceAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ShortRangeSelfScalingVarianceAssign

!! Delete
subroutine ShortRangeSelfScalingVarianceDelete(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ShortRangeSelfScalingVarianceDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ShortRangeSelfScalingVarianceRead(handle, filename, filenameSize) &
      bind(C, name='ShortRangeSelfScalingVarianceRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ShortRangeSelfScalingVarianceRead
end function ShortRangeSelfScalingVarianceRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ShortRangeSelfScalingVarianceWrite(handle, filename, filenameSize) &
      bind(C, name='ShortRangeSelfScalingVarianceWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ShortRangeSelfScalingVarianceWrite
end function ShortRangeSelfScalingVarianceWrite

!! Print to standard output, in our prettyprinting format
function ShortRangeSelfScalingVariancePrint(handle) &
      bind(C, name='ShortRangeSelfScalingVariancePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ShortRangeSelfScalingVariancePrint
end function ShortRangeSelfScalingVariancePrint

!! Print to standard output, as XML
function ShortRangeSelfScalingVariancePrintXML(handle) &
      bind(C, name='ShortRangeSelfScalingVariancePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ShortRangeSelfScalingVariancePrintXML
end function ShortRangeSelfScalingVariancePrintXML

!! Print to standard output, as JSON
function ShortRangeSelfScalingVariancePrintJSON(handle) &
      bind(C, name='ShortRangeSelfScalingVariancePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ShortRangeSelfScalingVariancePrintJSON
end function ShortRangeSelfScalingVariancePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ShortRangeSelfScalingVarianceLabelHas(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ShortRangeSelfScalingVarianceLabelHas
end function ShortRangeSelfScalingVarianceLabelHas

!! Get
function ShortRangeSelfScalingVarianceLabelGet(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ShortRangeSelfScalingVarianceLabelGet
end function ShortRangeSelfScalingVarianceLabelGet

!! Set
subroutine ShortRangeSelfScalingVarianceLabelSet(handle, label, labelSize) &
      bind(C, name='ShortRangeSelfScalingVarianceLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ShortRangeSelfScalingVarianceLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: type
!! -----------------------------------------------------------------------------

!! Has
function ShortRangeSelfScalingVarianceTypeHas(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceTypeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ShortRangeSelfScalingVarianceTypeHas
end function ShortRangeSelfScalingVarianceTypeHas

!! Get
function ShortRangeSelfScalingVarianceTypeGet(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceTypeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ShortRangeSelfScalingVarianceTypeGet
end function ShortRangeSelfScalingVarianceTypeGet

!! Set
subroutine ShortRangeSelfScalingVarianceTypeSet(handle, type1, type1Size) &
      bind(C, name='ShortRangeSelfScalingVarianceTypeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: type1Size
   character(c_char), intent(in) :: type1(type1Size)
end subroutine ShortRangeSelfScalingVarianceTypeSet


!! -----------------------------------------------------------------------------
!! Metadatum: dependenceOnProcessedGroupWidth
!! -----------------------------------------------------------------------------

!! Has
function ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthHas(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthHas
end function ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthHas

!! Get
function ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthGet(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthGet
end function ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthGet

!! Set
subroutine ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthSet(handle, dependenceOnProcessedGroupWidth, dependenceOnProcessedGroupWidthSize) &
      bind(C, name='ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: dependenceOnProcessedGroupWidthSize
   character(c_char), intent(in) :: dependenceOnProcessedGroupWidth(dependenceOnProcessedGroupWidthSize)
end subroutine ShortRangeSelfScalingVarianceDependenceOnProcessedGroupWidthSet


!! -----------------------------------------------------------------------------
!! Child: gridded2d
!! -----------------------------------------------------------------------------

!! Has
function ShortRangeSelfScalingVarianceGridded2dHas(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceGridded2dHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ShortRangeSelfScalingVarianceGridded2dHas
end function ShortRangeSelfScalingVarianceGridded2dHas

!! Get, const
function ShortRangeSelfScalingVarianceGridded2dGetConst(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceGridded2dGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ShortRangeSelfScalingVarianceGridded2dGetConst
end function ShortRangeSelfScalingVarianceGridded2dGetConst

!! Get, non-const
function ShortRangeSelfScalingVarianceGridded2dGet(handle) &
      bind(C, name='ShortRangeSelfScalingVarianceGridded2dGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ShortRangeSelfScalingVarianceGridded2dGet
end function ShortRangeSelfScalingVarianceGridded2dGet

!! Set
subroutine ShortRangeSelfScalingVarianceGridded2dSet(handle, fieldHandle) &
      bind(C, name='ShortRangeSelfScalingVarianceGridded2dSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ShortRangeSelfScalingVarianceGridded2dSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalShortRangeSelfScalingVariance
