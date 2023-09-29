
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalApplicationData
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function ApplicationDataDefaultConst() &
      bind(C, name='ApplicationDataDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ApplicationDataDefaultConst
end function ApplicationDataDefaultConst

!! Create, default
function ApplicationDataDefault() &
      bind(C, name='ApplicationDataDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: ApplicationDataDefault
end function ApplicationDataDefault

!! Create, general, const
function ApplicationDataCreateConst( &
   institution &
) &
      bind(C, name='ApplicationDataCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: institution
   type(c_ptr) :: ApplicationDataCreateConst
end function ApplicationDataCreateConst

!! Create, general
function ApplicationDataCreate( &
   institution &
) &
      bind(C, name='ApplicationDataCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: institution
   type(c_ptr) :: ApplicationDataCreate
end function ApplicationDataCreate

!! Assign
subroutine ApplicationDataAssign(handleLHS, handleRHS) &
      bind(C, name='ApplicationDataAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine ApplicationDataAssign

!! Delete
subroutine ApplicationDataDelete(handle) &
      bind(C, name='ApplicationDataDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine ApplicationDataDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function ApplicationDataRead(handle, filename, filenameSize) &
      bind(C, name='ApplicationDataRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ApplicationDataRead
end function ApplicationDataRead

!! Write to file
function ApplicationDataWrite(handle, filename, filenameSize) &
      bind(C, name='ApplicationDataWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: ApplicationDataWrite
end function ApplicationDataWrite

!! Print to standard output, in our prettyprinting format
function ApplicationDataPrint(handle) &
      bind(C, name='ApplicationDataPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ApplicationDataPrint
end function ApplicationDataPrint

!! Print to standard output, as XML
function ApplicationDataPrintXML(handle) &
      bind(C, name='ApplicationDataPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ApplicationDataPrintXML
end function ApplicationDataPrintXML

!! Print to standard output, as JSON
function ApplicationDataPrintJSON(handle) &
      bind(C, name='ApplicationDataPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ApplicationDataPrintJSON
end function ApplicationDataPrintJSON


!! -----------------------------------------------------------------------------
!! Child: institution
!! -----------------------------------------------------------------------------

!! Has
function ApplicationDataInstitutionHas(handle) &
      bind(C, name='ApplicationDataInstitutionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: ApplicationDataInstitutionHas
end function ApplicationDataInstitutionHas

!! Get, const
function ApplicationDataInstitutionGetConst(handle) &
      bind(C, name='ApplicationDataInstitutionGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: ApplicationDataInstitutionGetConst
end function ApplicationDataInstitutionGetConst

!! Get
function ApplicationDataInstitutionGet(handle) &
      bind(C, name='ApplicationDataInstitutionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: ApplicationDataInstitutionGet
end function ApplicationDataInstitutionGet

!! Set
subroutine ApplicationDataInstitutionSet(handle, fieldHandle) &
      bind(C, name='ApplicationDataInstitutionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine ApplicationDataInstitutionSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalApplicationData
