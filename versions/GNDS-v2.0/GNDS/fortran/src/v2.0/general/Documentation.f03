
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalDocumentation
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function DocumentationDefaultConst() &
      bind(C, name='DocumentationDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DocumentationDefaultConst
end function DocumentationDefaultConst

!! Create, default, non-const
function DocumentationDefault() &
      bind(C, name='DocumentationDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: DocumentationDefault
end function DocumentationDefault

!! Create, general, const
function DocumentationCreateConst( &
   authors, &
   dates, &
   title, &
   body, &
   endfCompatible &
) &
      bind(C, name='DocumentationCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: authors
   type(c_ptr), intent(in), value :: dates
   type(c_ptr), intent(in), value :: title
   type(c_ptr), intent(in), value :: body
   type(c_ptr), intent(in), value :: endfCompatible
   type(c_ptr) :: DocumentationCreateConst
end function DocumentationCreateConst

!! Create, general, non-const
function DocumentationCreate( &
   authors, &
   dates, &
   title, &
   body, &
   endfCompatible &
) &
      bind(C, name='DocumentationCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: authors
   type(c_ptr), intent(in), value :: dates
   type(c_ptr), intent(in), value :: title
   type(c_ptr), intent(in), value :: body
   type(c_ptr), intent(in), value :: endfCompatible
   type(c_ptr) :: DocumentationCreate
end function DocumentationCreate

!! Assign
subroutine DocumentationAssign(handleLHS, handleRHS) &
      bind(C, name='DocumentationAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine DocumentationAssign

!! Delete
subroutine DocumentationDelete(handle) &
      bind(C, name='DocumentationDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine DocumentationDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function DocumentationRead(handle, filename, filenameSize) &
      bind(C, name='DocumentationRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DocumentationRead
end function DocumentationRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function DocumentationWrite(handle, filename, filenameSize) &
      bind(C, name='DocumentationWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: DocumentationWrite
end function DocumentationWrite

!! Print to standard output, in our prettyprinting format
function DocumentationPrint(handle) &
      bind(C, name='DocumentationPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationPrint
end function DocumentationPrint

!! Print to standard output, as XML
function DocumentationPrintXML(handle) &
      bind(C, name='DocumentationPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationPrintXML
end function DocumentationPrintXML

!! Print to standard output, as JSON
function DocumentationPrintJSON(handle) &
      bind(C, name='DocumentationPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationPrintJSON
end function DocumentationPrintJSON


!! -----------------------------------------------------------------------------
!! Child: authors
!! -----------------------------------------------------------------------------

!! Has
function DocumentationAuthorsHas(handle) &
      bind(C, name='DocumentationAuthorsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationAuthorsHas
end function DocumentationAuthorsHas

!! Get, const
function DocumentationAuthorsGetConst(handle) &
      bind(C, name='DocumentationAuthorsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DocumentationAuthorsGetConst
end function DocumentationAuthorsGetConst

!! Get, non-const
function DocumentationAuthorsGet(handle) &
      bind(C, name='DocumentationAuthorsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DocumentationAuthorsGet
end function DocumentationAuthorsGet

!! Set
subroutine DocumentationAuthorsSet(handle, fieldHandle) &
      bind(C, name='DocumentationAuthorsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DocumentationAuthorsSet


!! -----------------------------------------------------------------------------
!! Child: dates
!! -----------------------------------------------------------------------------

!! Has
function DocumentationDatesHas(handle) &
      bind(C, name='DocumentationDatesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationDatesHas
end function DocumentationDatesHas

!! Get, const
function DocumentationDatesGetConst(handle) &
      bind(C, name='DocumentationDatesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DocumentationDatesGetConst
end function DocumentationDatesGetConst

!! Get, non-const
function DocumentationDatesGet(handle) &
      bind(C, name='DocumentationDatesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DocumentationDatesGet
end function DocumentationDatesGet

!! Set
subroutine DocumentationDatesSet(handle, fieldHandle) &
      bind(C, name='DocumentationDatesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DocumentationDatesSet


!! -----------------------------------------------------------------------------
!! Child: title
!! -----------------------------------------------------------------------------

!! Has
function DocumentationTitleHas(handle) &
      bind(C, name='DocumentationTitleHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationTitleHas
end function DocumentationTitleHas

!! Get, const
function DocumentationTitleGetConst(handle) &
      bind(C, name='DocumentationTitleGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DocumentationTitleGetConst
end function DocumentationTitleGetConst

!! Get, non-const
function DocumentationTitleGet(handle) &
      bind(C, name='DocumentationTitleGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DocumentationTitleGet
end function DocumentationTitleGet

!! Set
subroutine DocumentationTitleSet(handle, fieldHandle) &
      bind(C, name='DocumentationTitleSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DocumentationTitleSet


!! -----------------------------------------------------------------------------
!! Child: body
!! -----------------------------------------------------------------------------

!! Has
function DocumentationBodyHas(handle) &
      bind(C, name='DocumentationBodyHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationBodyHas
end function DocumentationBodyHas

!! Get, const
function DocumentationBodyGetConst(handle) &
      bind(C, name='DocumentationBodyGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DocumentationBodyGetConst
end function DocumentationBodyGetConst

!! Get, non-const
function DocumentationBodyGet(handle) &
      bind(C, name='DocumentationBodyGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DocumentationBodyGet
end function DocumentationBodyGet

!! Set
subroutine DocumentationBodySet(handle, fieldHandle) &
      bind(C, name='DocumentationBodySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DocumentationBodySet


!! -----------------------------------------------------------------------------
!! Child: endfCompatible
!! -----------------------------------------------------------------------------

!! Has
function DocumentationEndfCompatibleHas(handle) &
      bind(C, name='DocumentationEndfCompatibleHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: DocumentationEndfCompatibleHas
end function DocumentationEndfCompatibleHas

!! Get, const
function DocumentationEndfCompatibleGetConst(handle) &
      bind(C, name='DocumentationEndfCompatibleGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: DocumentationEndfCompatibleGetConst
end function DocumentationEndfCompatibleGetConst

!! Get, non-const
function DocumentationEndfCompatibleGet(handle) &
      bind(C, name='DocumentationEndfCompatibleGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: DocumentationEndfCompatibleGet
end function DocumentationEndfCompatibleGet

!! Set
subroutine DocumentationEndfCompatibleSet(handle, fieldHandle) &
      bind(C, name='DocumentationEndfCompatibleSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine DocumentationEndfCompatibleSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalDocumentation
