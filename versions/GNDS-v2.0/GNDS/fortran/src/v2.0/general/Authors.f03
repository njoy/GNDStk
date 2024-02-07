
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalAuthors
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function AuthorsDefaultConst() &
      bind(C, name='AuthorsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AuthorsDefaultConst
end function AuthorsDefaultConst

!! Create, default, non-const
function AuthorsDefault() &
      bind(C, name='AuthorsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: AuthorsDefault
end function AuthorsDefault

!! Create, general, const
function AuthorsCreateConst( &
   author, authorSize &
) &
      bind(C, name='AuthorsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: authorSize
   type(c_ptr), intent(in) :: author(authorSize)
   type(c_ptr) :: AuthorsCreateConst
end function AuthorsCreateConst

!! Create, general, non-const
function AuthorsCreate( &
   author, authorSize &
) &
      bind(C, name='AuthorsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: authorSize
   type(c_ptr), intent(in) :: author(authorSize)
   type(c_ptr) :: AuthorsCreate
end function AuthorsCreate

!! Assign
subroutine AuthorsAssign(handleLHS, handleRHS) &
      bind(C, name='AuthorsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
end subroutine AuthorsAssign

!! Delete
subroutine AuthorsDelete(handle) &
      bind(C, name='AuthorsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AuthorsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
!! File can be XML, JSON, or HDF5.
!! We'll examine the file's contents to determine its type automatically.
function AuthorsRead(handle, filename, filenameSize) &
      bind(C, name='AuthorsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AuthorsRead
end function AuthorsRead

!! Write to file
!! File can be XML, JSON, or HDF5.
!! We'll use filename's extension to determine the type you want written.
function AuthorsWrite(handle, filename, filenameSize) &
      bind(C, name='AuthorsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: AuthorsWrite
end function AuthorsWrite

!! Print to standard output, in our prettyprinting format
function AuthorsPrint(handle) &
      bind(C, name='AuthorsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AuthorsPrint
end function AuthorsPrint

!! Print to standard output, as XML
function AuthorsPrintXML(handle) &
      bind(C, name='AuthorsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AuthorsPrintXML
end function AuthorsPrintXML

!! Print to standard output, as JSON
function AuthorsPrintJSON(handle) &
      bind(C, name='AuthorsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AuthorsPrintJSON
end function AuthorsPrintJSON


!! -----------------------------------------------------------------------------
!! Child: author
!! -----------------------------------------------------------------------------

!! Has
function AuthorsAuthorHas(handle) &
      bind(C, name='AuthorsAuthorHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: AuthorsAuthorHas
end function AuthorsAuthorHas

!! Clear
subroutine AuthorsAuthorClear(handle) &
      bind(C, name='AuthorsAuthorClear')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine AuthorsAuthorClear

!! Size
function AuthorsAuthorSize(handle) &
      bind(C, name='AuthorsAuthorSize')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t) :: AuthorsAuthorSize
end function AuthorsAuthorSize

!! Add
subroutine AuthorsAuthorAdd(handle, fieldHandle) &
      bind(C, name='AuthorsAuthorAdd')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AuthorsAuthorAdd

!! Get, by index \in [0,size), const
function AuthorsAuthorGetConst(handle, index) &
      bind(C, name='AuthorsAuthorGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: AuthorsAuthorGetConst
end function AuthorsAuthorGetConst

!! Get, by index \in [0,size), non-const
function AuthorsAuthorGet(handle, index) &
      bind(C, name='AuthorsAuthorGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr) :: AuthorsAuthorGet
end function AuthorsAuthorGet

!! Set, by index \in [0,size)
subroutine AuthorsAuthorSet(handle, index, fieldHandle) &
      bind(C, name='AuthorsAuthorSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: index
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AuthorsAuthorSet

!! ------------------------
!! Re: metadatum name
!! ------------------------

!! Has, by name
function AuthorsAuthorHasByName(handle, meta, metaSize) &
      bind(C, name='AuthorsAuthorHasByName')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   integer(c_int) :: AuthorsAuthorHasByName
end function AuthorsAuthorHasByName

!! Get, by name, const
function AuthorsAuthorGetByNameConst(handle, meta, metaSize) &
      bind(C, name='AuthorsAuthorGetByNameConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: AuthorsAuthorGetByNameConst
end function AuthorsAuthorGetByNameConst

!! Get, by name, non-const
function AuthorsAuthorGetByName(handle, meta, metaSize) &
      bind(C, name='AuthorsAuthorGetByName')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr) :: AuthorsAuthorGetByName
end function AuthorsAuthorGetByName

!! Set, by name
subroutine AuthorsAuthorSetByName(handle, meta, metaSize, fieldHandle) &
      bind(C, name='AuthorsAuthorSetByName')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: metaSize
   character(c_char), intent(in) :: meta(metaSize)
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine AuthorsAuthorSetByName


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalAuthors