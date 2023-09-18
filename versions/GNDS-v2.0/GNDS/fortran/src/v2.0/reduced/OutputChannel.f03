
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module reducedOutputChannel
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function OutputChannelDefaultConst() &
      bind(C, name='OutputChannelDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function OutputChannelDefaultConst

!! Create, default
function OutputChannelDefault() &
      bind(C, name='OutputChannelDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function OutputChannelDefault

!! Create, general, const
function OutputChannelCreateConst( &
   genre, &
   process, &
   Q, &
   products, &
   genreSize, &
   processSize &
) &
      bind(C, name='OutputChannelCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: genreSize
   character(c_char), intent(in) :: genre(genreSize)
   integer(c_size_t), intent(in), value :: processSize
   character(c_char), intent(in) :: process(processSize)
   type(c_ptr), value :: Q
   type(c_ptr), value :: products
   type(c_ptr) :: handle
end function OutputChannelCreateConst

!! Create, general
function OutputChannelCreate( &
   genre, &
   process, &
   Q, &
   products, &
   genreSize, &
   processSize &
) &
      bind(C, name='OutputChannelCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: genreSize
   character(c_char), intent(in) :: genre(genreSize)
   integer(c_size_t), intent(in), value :: processSize
   character(c_char), intent(in) :: process(processSize)
   type(c_ptr), value :: Q
   type(c_ptr), value :: products
   type(c_ptr) :: handle
end function OutputChannelCreate

!! Assign
subroutine OutputChannelAssign(handleLHS, handleRHS) &
      bind(C, name='OutputChannelAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine OutputChannelAssign

!! Delete
subroutine OutputChannelDelete(handle) &
      bind(C, name='OutputChannelDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine OutputChannelDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function OutputChannelRead(handle, filename, filenameSize) &
      bind(C, name='OutputChannelRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function OutputChannelRead

!! Write to file
function OutputChannelWrite(handle, filename, filenameSize) &
      bind(C, name='OutputChannelWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function OutputChannelWrite

!! Print to standard output, in our prettyprinting format
function OutputChannelPrint(handle) &
      bind(C, name='OutputChannelPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function OutputChannelPrint

!! Print to standard output, as XML
function OutputChannelPrintXML(handle) &
      bind(C, name='OutputChannelPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function OutputChannelPrintXML

!! Print to standard output, as JSON
function OutputChannelPrintJSON(handle) &
      bind(C, name='OutputChannelPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function OutputChannelPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: genre
!! -----------------------------------------------------------------------------

!! Has
function OutputChannelGenreHas(handle) &
      bind(C, name='OutputChannelGenreHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function OutputChannelGenreHas

!! Get
function OutputChannelGenreGet(handle) &
      bind(C, name='OutputChannelGenreGet') &
      result(genre)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: genre
end function OutputChannelGenreGet

!! Set
subroutine OutputChannelGenreSet(handle, genre, genreSize) &
      bind(C, name='OutputChannelGenreSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: genreSize
   character(c_char), intent(in) :: genre(genreSize)
end subroutine OutputChannelGenreSet


!! -----------------------------------------------------------------------------
!! Metadatum: process
!! -----------------------------------------------------------------------------

!! Has
function OutputChannelProcessHas(handle) &
      bind(C, name='OutputChannelProcessHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function OutputChannelProcessHas

!! Get
function OutputChannelProcessGet(handle) &
      bind(C, name='OutputChannelProcessGet') &
      result(process)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: process
end function OutputChannelProcessGet

!! Set
subroutine OutputChannelProcessSet(handle, process, processSize) &
      bind(C, name='OutputChannelProcessSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: processSize
   character(c_char), intent(in) :: process(processSize)
end subroutine OutputChannelProcessSet


!! -----------------------------------------------------------------------------
!! Child: Q
!! -----------------------------------------------------------------------------

!! Has
function OutputChannelQHas(handle) &
      bind(C, name='OutputChannelQHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function OutputChannelQHas

!! Get, const
function OutputChannelQGetConst(handle) &
      bind(C, name='OutputChannelQGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function OutputChannelQGetConst

!! Get
function OutputChannelQGet(handle) &
      bind(C, name='OutputChannelQGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function OutputChannelQGet

!! Set
subroutine OutputChannelQSet(handle, fieldHandle) &
      bind(C, name='OutputChannelQSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine OutputChannelQSet


!! -----------------------------------------------------------------------------
!! Child: products
!! -----------------------------------------------------------------------------

!! Has
function OutputChannelProductsHas(handle) &
      bind(C, name='OutputChannelProductsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function OutputChannelProductsHas

!! Get, const
function OutputChannelProductsGetConst(handle) &
      bind(C, name='OutputChannelProductsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function OutputChannelProductsGetConst

!! Get
function OutputChannelProductsGet(handle) &
      bind(C, name='OutputChannelProductsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function OutputChannelProductsGet

!! Set
subroutine OutputChannelProductsSet(handle, fieldHandle) &
      bind(C, name='OutputChannelProductsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine OutputChannelProductsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module reducedOutputChannel
