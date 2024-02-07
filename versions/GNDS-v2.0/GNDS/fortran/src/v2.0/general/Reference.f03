
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalReference
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ReferenceDefaultConst() &
      bind(C, name='ReferenceDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ReferenceDefaultConst
end function ReferenceDefaultConst

!! Create, default, non-const
function ReferenceDefault() &
      bind(C, name='ReferenceDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ReferenceDefault
end function ReferenceDefault

!! Create, general, const
function ReferenceCreateConst( &
   label, &
   href, &
   labelSize, &
   hrefSize &
) &
      bind(C, name='ReferenceCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: ReferenceCreateConst
end function ReferenceCreateConst

!! Create, general, non-const
function ReferenceCreate( &
   label, &
   href, &
   labelSize, &
   hrefSize &
) &
      bind(C, name='ReferenceCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
   type(c_ptr) :: ReferenceCreate
end function ReferenceCreate

!! Assign
subroutine ReferenceAssign(handleLHS, handleRHS) &
      bind(C, name='ReferenceAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ReferenceAssign

!! Delete
subroutine ReferenceDelete(handle) &
      bind(C, name='ReferenceDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ReferenceDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function ReferenceRead(handle, filename, filenameSize) &
      bind(C, name='ReferenceRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ReferenceRead
end function ReferenceRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function ReferenceWrite(handle, filename, filenameSize) &
      bind(C, name='ReferenceWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ReferenceWrite
end function ReferenceWrite

!! Print to standard output, in our prettyprinting format
function ReferencePrint(handle) &
      bind(C, name='ReferencePrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReferencePrint
end function ReferencePrint

!! Print to standard output, as XML
function ReferencePrintXML(handle) &
      bind(C, name='ReferencePrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReferencePrintXML
end function ReferencePrintXML

!! Print to standard output, as JSON
function ReferencePrintJSON(handle) &
      bind(C, name='ReferencePrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReferencePrintJSON
end function ReferencePrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function ReferenceLabelHas(handle) &
      bind(C, name='ReferenceLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReferenceLabelHas
end function ReferenceLabelHas

!! Get
function ReferenceLabelGet(handle) &
      bind(C, name='ReferenceLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ReferenceLabelGet
end function ReferenceLabelGet

!! Set
subroutine ReferenceLabelSet(handle, label, labelSize) &
      bind(C, name='ReferenceLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine ReferenceLabelSet


!! -----------------------------------------------------------------------------
!! Metadatum: href
!! -----------------------------------------------------------------------------

!! Has
function ReferenceHrefHas(handle) &
      bind(C, name='ReferenceHrefHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ReferenceHrefHas
end function ReferenceHrefHas

!! Get
function ReferenceHrefGet(handle) &
      bind(C, name='ReferenceHrefGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ReferenceHrefGet
end function ReferenceHrefGet

!! Set
subroutine ReferenceHrefSet(handle, href, hrefSize) &
      bind(C, name='ReferenceHrefSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: hrefSize
   character(c_char), intent(in) :: href(hrefSize)
end subroutine ReferenceHrefSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalReference