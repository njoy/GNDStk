
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module topPoPs
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function PoPsDefaultConst() &
      bind(C, name='PoPsDefaultConst') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function PoPsDefaultConst

!! Create, default
function PoPsDefault() &
      bind(C, name='PoPsDefault') &
      result(handle)
   use iso_c_binding
   implicit none
   type(c_ptr) :: handle
end function PoPsDefault

!! Create, general, const
function PoPsCreateConst( &
   name, &
   version, &
   format, &
   aliases, &
   baryons, &
   chemicalElements, &
   styles, &
   unorthodoxes, &
   gaugeBosons, &
   leptons, &
   nameSize, &
   versionSize, &
   formatSize &
) &
      bind(C, name='PoPsCreateConst') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
   integer(c_size_t), intent(in), value :: formatSize
   character(c_char), intent(in) :: format(formatSize)
   type(c_ptr), value :: aliases
   type(c_ptr), value :: baryons
   type(c_ptr), value :: chemicalElements
   type(c_ptr), value :: styles
   type(c_ptr), value :: unorthodoxes
   type(c_ptr), value :: gaugeBosons
   type(c_ptr), value :: leptons
   type(c_ptr) :: handle
end function PoPsCreateConst

!! Create, general
function PoPsCreate( &
   name, &
   version, &
   format, &
   aliases, &
   baryons, &
   chemicalElements, &
   styles, &
   unorthodoxes, &
   gaugeBosons, &
   leptons, &
   nameSize, &
   versionSize, &
   formatSize &
) &
      bind(C, name='PoPsCreate') &
      result(handle)
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
   integer(c_size_t), intent(in), value :: formatSize
   character(c_char), intent(in) :: format(formatSize)
   type(c_ptr), value :: aliases
   type(c_ptr), value :: baryons
   type(c_ptr), value :: chemicalElements
   type(c_ptr), value :: styles
   type(c_ptr), value :: unorthodoxes
   type(c_ptr), value :: gaugeBosons
   type(c_ptr), value :: leptons
   type(c_ptr) :: handle
end function PoPsCreate

!! Assign
subroutine PoPsAssign(handleLHS, handleRHS) &
      bind(C, name='PoPsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine PoPsAssign

!! Delete
subroutine PoPsDelete(handle) &
      bind(C, name='PoPsDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine PoPsDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function PoPsRead(handle, filename, filenameSize) &
      bind(C, name='PoPsRead') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function PoPsRead

!! Write to file
function PoPsWrite(handle, filename, filenameSize) &
      bind(C, name='PoPsWrite') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: success
end function PoPsWrite

!! Print to standard output, in our prettyprinting format
function PoPsPrint(handle) &
      bind(C, name='PoPsPrint') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function PoPsPrint

!! Print to standard output, as XML
function PoPsPrintXML(handle) &
      bind(C, name='PoPsPrintXML') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function PoPsPrintXML

!! Print to standard output, as JSON
function PoPsPrintJSON(handle) &
      bind(C, name='PoPsPrintJSON') &
      result(success)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: success
end function PoPsPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: name
!! -----------------------------------------------------------------------------

!! Has
function PoPsNameHas(handle) &
      bind(C, name='PoPsNameHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsNameHas

!! Get
function PoPsNameGet(handle) &
      bind(C, name='PoPsNameGet') &
      result(name)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: name
end function PoPsNameGet

!! Set
subroutine PoPsNameSet(handle, name, nameSize) &
      bind(C, name='PoPsNameSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
end subroutine PoPsNameSet


!! -----------------------------------------------------------------------------
!! Metadatum: version
!! -----------------------------------------------------------------------------

!! Has
function PoPsVersionHas(handle) &
      bind(C, name='PoPsVersionHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsVersionHas

!! Get
function PoPsVersionGet(handle) &
      bind(C, name='PoPsVersionGet') &
      result(version)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: version
end function PoPsVersionGet

!! Set
subroutine PoPsVersionSet(handle, version, versionSize) &
      bind(C, name='PoPsVersionSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
end subroutine PoPsVersionSet


!! -----------------------------------------------------------------------------
!! Metadatum: format
!! -----------------------------------------------------------------------------

!! Has
function PoPsFormatHas(handle) &
      bind(C, name='PoPsFormatHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsFormatHas

!! Get
function PoPsFormatGet(handle) &
      bind(C, name='PoPsFormatGet') &
      result(format)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: format
end function PoPsFormatGet

!! Set
subroutine PoPsFormatSet(handle, format, formatSize) &
      bind(C, name='PoPsFormatSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: formatSize
   character(c_char), intent(in) :: format(formatSize)
end subroutine PoPsFormatSet


!! -----------------------------------------------------------------------------
!! Child: aliases
!! -----------------------------------------------------------------------------

!! Has
function PoPsAliasesHas(handle) &
      bind(C, name='PoPsAliasesHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsAliasesHas

!! Get, const
function PoPsAliasesGetConst(handle) &
      bind(C, name='PoPsAliasesGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsAliasesGetConst

!! Get
function PoPsAliasesGet(handle) &
      bind(C, name='PoPsAliasesGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsAliasesGet

!! Set
subroutine PoPsAliasesSet(handle, fieldHandle) &
      bind(C, name='PoPsAliasesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine PoPsAliasesSet


!! -----------------------------------------------------------------------------
!! Child: baryons
!! -----------------------------------------------------------------------------

!! Has
function PoPsBaryonsHas(handle) &
      bind(C, name='PoPsBaryonsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsBaryonsHas

!! Get, const
function PoPsBaryonsGetConst(handle) &
      bind(C, name='PoPsBaryonsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsBaryonsGetConst

!! Get
function PoPsBaryonsGet(handle) &
      bind(C, name='PoPsBaryonsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsBaryonsGet

!! Set
subroutine PoPsBaryonsSet(handle, fieldHandle) &
      bind(C, name='PoPsBaryonsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine PoPsBaryonsSet


!! -----------------------------------------------------------------------------
!! Child: chemicalElements
!! -----------------------------------------------------------------------------

!! Has
function PoPsChemicalElementsHas(handle) &
      bind(C, name='PoPsChemicalElementsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsChemicalElementsHas

!! Get, const
function PoPsChemicalElementsGetConst(handle) &
      bind(C, name='PoPsChemicalElementsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsChemicalElementsGetConst

!! Get
function PoPsChemicalElementsGet(handle) &
      bind(C, name='PoPsChemicalElementsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsChemicalElementsGet

!! Set
subroutine PoPsChemicalElementsSet(handle, fieldHandle) &
      bind(C, name='PoPsChemicalElementsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine PoPsChemicalElementsSet


!! -----------------------------------------------------------------------------
!! Child: styles
!! -----------------------------------------------------------------------------

!! Has
function PoPsStylesHas(handle) &
      bind(C, name='PoPsStylesHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsStylesHas

!! Get, const
function PoPsStylesGetConst(handle) &
      bind(C, name='PoPsStylesGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsStylesGetConst

!! Get
function PoPsStylesGet(handle) &
      bind(C, name='PoPsStylesGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsStylesGet

!! Set
subroutine PoPsStylesSet(handle, fieldHandle) &
      bind(C, name='PoPsStylesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine PoPsStylesSet


!! -----------------------------------------------------------------------------
!! Child: unorthodoxes
!! -----------------------------------------------------------------------------

!! Has
function PoPsUnorthodoxesHas(handle) &
      bind(C, name='PoPsUnorthodoxesHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsUnorthodoxesHas

!! Get, const
function PoPsUnorthodoxesGetConst(handle) &
      bind(C, name='PoPsUnorthodoxesGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsUnorthodoxesGetConst

!! Get
function PoPsUnorthodoxesGet(handle) &
      bind(C, name='PoPsUnorthodoxesGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsUnorthodoxesGet

!! Set
subroutine PoPsUnorthodoxesSet(handle, fieldHandle) &
      bind(C, name='PoPsUnorthodoxesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine PoPsUnorthodoxesSet


!! -----------------------------------------------------------------------------
!! Child: gaugeBosons
!! -----------------------------------------------------------------------------

!! Has
function PoPsGaugeBosonsHas(handle) &
      bind(C, name='PoPsGaugeBosonsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsGaugeBosonsHas

!! Get, const
function PoPsGaugeBosonsGetConst(handle) &
      bind(C, name='PoPsGaugeBosonsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsGaugeBosonsGetConst

!! Get
function PoPsGaugeBosonsGet(handle) &
      bind(C, name='PoPsGaugeBosonsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsGaugeBosonsGet

!! Set
subroutine PoPsGaugeBosonsSet(handle, fieldHandle) &
      bind(C, name='PoPsGaugeBosonsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine PoPsGaugeBosonsSet


!! -----------------------------------------------------------------------------
!! Child: leptons
!! -----------------------------------------------------------------------------

!! Has
function PoPsLeptonsHas(handle) &
      bind(C, name='PoPsLeptonsHas') &
      result(has)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: has
end function PoPsLeptonsHas

!! Get, const
function PoPsLeptonsGetConst(handle) &
      bind(C, name='PoPsLeptonsGetConst') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsLeptonsGetConst

!! Get
function PoPsLeptonsGet(handle) &
      bind(C, name='PoPsLeptonsGet') &
      result(resultHandle)
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: resultHandle
end function PoPsLeptonsGet

!! Set
subroutine PoPsLeptonsSet(handle, fieldHandle) &
      bind(C, name='PoPsLeptonsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine PoPsLeptonsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module topPoPs
