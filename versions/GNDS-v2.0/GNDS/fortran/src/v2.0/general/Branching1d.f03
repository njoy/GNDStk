
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalBranching1d
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function Branching1dDefaultConst() &
      bind(C, name='Branching1dDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Branching1dDefaultConst
end function Branching1dDefaultConst

!! Create, default
function Branching1dDefault() &
      bind(C, name='Branching1dDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: Branching1dDefault
end function Branching1dDefault

!! Create, general, const
function Branching1dCreateConst( &
   label, &
   labelSize &
) &
      bind(C, name='Branching1dCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr) :: Branching1dCreateConst
end function Branching1dCreateConst

!! Create, general
function Branching1dCreate( &
   label, &
   labelSize &
) &
      bind(C, name='Branching1dCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
   type(c_ptr) :: Branching1dCreate
end function Branching1dCreate

!! Assign
subroutine Branching1dAssign(handleLHS, handleRHS) &
      bind(C, name='Branching1dAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine Branching1dAssign

!! Delete
subroutine Branching1dDelete(handle) &
      bind(C, name='Branching1dDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine Branching1dDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function Branching1dRead(handle, filename, filenameSize) &
      bind(C, name='Branching1dRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Branching1dRead
end function Branching1dRead

!! Write to file
function Branching1dWrite(handle, filename, filenameSize) &
      bind(C, name='Branching1dWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: Branching1dWrite
end function Branching1dWrite

!! Print to standard output, in our prettyprinting format
function Branching1dPrint(handle) &
      bind(C, name='Branching1dPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Branching1dPrint
end function Branching1dPrint

!! Print to standard output, as XML
function Branching1dPrintXML(handle) &
      bind(C, name='Branching1dPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Branching1dPrintXML
end function Branching1dPrintXML

!! Print to standard output, as JSON
function Branching1dPrintJSON(handle) &
      bind(C, name='Branching1dPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Branching1dPrintJSON
end function Branching1dPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: label
!! -----------------------------------------------------------------------------

!! Has
function Branching1dLabelHas(handle) &
      bind(C, name='Branching1dLabelHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: Branching1dLabelHas
end function Branching1dLabelHas

!! Get
function Branching1dLabelGet(handle) &
      bind(C, name='Branching1dLabelGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: Branching1dLabelGet
end function Branching1dLabelGet

!! Set
subroutine Branching1dLabelSet(handle, label, labelSize) &
      bind(C, name='Branching1dLabelSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: labelSize
   character(c_char), intent(in) :: label(labelSize)
end subroutine Branching1dLabelSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalBranching1d
