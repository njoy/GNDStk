
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
      bind(C, name='PoPsDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: PoPsDefaultConst
end function PoPsDefaultConst

!! Create, default
function PoPsDefault() &
      bind(C, name='PoPsDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: PoPsDefault
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
      bind(C, name='PoPsCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
   integer(c_size_t), intent(in), value :: formatSize
   character(c_char), intent(in) :: format(formatSize)
   type(c_ptr), intent(in), value :: aliases
   type(c_ptr), intent(in), value :: baryons
   type(c_ptr), intent(in), value :: chemicalElements
   type(c_ptr), intent(in), value :: styles
   type(c_ptr), intent(in), value :: unorthodoxes
   type(c_ptr), intent(in), value :: gaugeBosons
   type(c_ptr), intent(in), value :: leptons
   type(c_ptr) :: PoPsCreateConst
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
      bind(C, name='PoPsCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: nameSize
   character(c_char), intent(in) :: name(nameSize)
   integer(c_size_t), intent(in), value :: versionSize
   character(c_char), intent(in) :: version(versionSize)
   integer(c_size_t), intent(in), value :: formatSize
   character(c_char), intent(in) :: format(formatSize)
   type(c_ptr), intent(in), value :: aliases
   type(c_ptr), intent(in), value :: baryons
   type(c_ptr), intent(in), value :: chemicalElements
   type(c_ptr), intent(in), value :: styles
   type(c_ptr), intent(in), value :: unorthodoxes
   type(c_ptr), intent(in), value :: gaugeBosons
   type(c_ptr), intent(in), value :: leptons
   type(c_ptr) :: PoPsCreate
end function PoPsCreate

!! Assign
subroutine PoPsAssign(handleLHS, handleRHS) &
      bind(C, name='PoPsAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS
   type(c_ptr), intent(in), value :: handleRHS
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
      bind(C, name='PoPsRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: PoPsRead
end function PoPsRead

!! Write to file
function PoPsWrite(handle, filename, filenameSize) &
      bind(C, name='PoPsWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), intent(in), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: PoPsWrite
end function PoPsWrite

!! Print to standard output, in our prettyprinting format
function PoPsPrint(handle) &
      bind(C, name='PoPsPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsPrint
end function PoPsPrint

!! Print to standard output, as XML
function PoPsPrintXML(handle) &
      bind(C, name='PoPsPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsPrintXML
end function PoPsPrintXML

!! Print to standard output, as JSON
function PoPsPrintJSON(handle) &
      bind(C, name='PoPsPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsPrintJSON
end function PoPsPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: name
!! -----------------------------------------------------------------------------

!! Has
function PoPsNameHas(handle) &
      bind(C, name='PoPsNameHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsNameHas
end function PoPsNameHas

!! Get
function PoPsNameGet(handle) &
      bind(C, name='PoPsNameGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsNameGet
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
      bind(C, name='PoPsVersionHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsVersionHas
end function PoPsVersionHas

!! Get
function PoPsVersionGet(handle) &
      bind(C, name='PoPsVersionGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsVersionGet
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
      bind(C, name='PoPsFormatHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsFormatHas
end function PoPsFormatHas

!! Get
function PoPsFormatGet(handle) &
      bind(C, name='PoPsFormatGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsFormatGet
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
      bind(C, name='PoPsAliasesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsAliasesHas
end function PoPsAliasesHas

!! Get, const
function PoPsAliasesGetConst(handle) &
      bind(C, name='PoPsAliasesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsAliasesGetConst
end function PoPsAliasesGetConst

!! Get
function PoPsAliasesGet(handle) &
      bind(C, name='PoPsAliasesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PoPsAliasesGet
end function PoPsAliasesGet

!! Set
subroutine PoPsAliasesSet(handle, fieldHandle) &
      bind(C, name='PoPsAliasesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PoPsAliasesSet


!! -----------------------------------------------------------------------------
!! Child: baryons
!! -----------------------------------------------------------------------------

!! Has
function PoPsBaryonsHas(handle) &
      bind(C, name='PoPsBaryonsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsBaryonsHas
end function PoPsBaryonsHas

!! Get, const
function PoPsBaryonsGetConst(handle) &
      bind(C, name='PoPsBaryonsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsBaryonsGetConst
end function PoPsBaryonsGetConst

!! Get
function PoPsBaryonsGet(handle) &
      bind(C, name='PoPsBaryonsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PoPsBaryonsGet
end function PoPsBaryonsGet

!! Set
subroutine PoPsBaryonsSet(handle, fieldHandle) &
      bind(C, name='PoPsBaryonsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PoPsBaryonsSet


!! -----------------------------------------------------------------------------
!! Child: chemicalElements
!! -----------------------------------------------------------------------------

!! Has
function PoPsChemicalElementsHas(handle) &
      bind(C, name='PoPsChemicalElementsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsChemicalElementsHas
end function PoPsChemicalElementsHas

!! Get, const
function PoPsChemicalElementsGetConst(handle) &
      bind(C, name='PoPsChemicalElementsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsChemicalElementsGetConst
end function PoPsChemicalElementsGetConst

!! Get
function PoPsChemicalElementsGet(handle) &
      bind(C, name='PoPsChemicalElementsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PoPsChemicalElementsGet
end function PoPsChemicalElementsGet

!! Set
subroutine PoPsChemicalElementsSet(handle, fieldHandle) &
      bind(C, name='PoPsChemicalElementsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PoPsChemicalElementsSet


!! -----------------------------------------------------------------------------
!! Child: styles
!! -----------------------------------------------------------------------------

!! Has
function PoPsStylesHas(handle) &
      bind(C, name='PoPsStylesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsStylesHas
end function PoPsStylesHas

!! Get, const
function PoPsStylesGetConst(handle) &
      bind(C, name='PoPsStylesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsStylesGetConst
end function PoPsStylesGetConst

!! Get
function PoPsStylesGet(handle) &
      bind(C, name='PoPsStylesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PoPsStylesGet
end function PoPsStylesGet

!! Set
subroutine PoPsStylesSet(handle, fieldHandle) &
      bind(C, name='PoPsStylesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PoPsStylesSet


!! -----------------------------------------------------------------------------
!! Child: unorthodoxes
!! -----------------------------------------------------------------------------

!! Has
function PoPsUnorthodoxesHas(handle) &
      bind(C, name='PoPsUnorthodoxesHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsUnorthodoxesHas
end function PoPsUnorthodoxesHas

!! Get, const
function PoPsUnorthodoxesGetConst(handle) &
      bind(C, name='PoPsUnorthodoxesGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsUnorthodoxesGetConst
end function PoPsUnorthodoxesGetConst

!! Get
function PoPsUnorthodoxesGet(handle) &
      bind(C, name='PoPsUnorthodoxesGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PoPsUnorthodoxesGet
end function PoPsUnorthodoxesGet

!! Set
subroutine PoPsUnorthodoxesSet(handle, fieldHandle) &
      bind(C, name='PoPsUnorthodoxesSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PoPsUnorthodoxesSet


!! -----------------------------------------------------------------------------
!! Child: gaugeBosons
!! -----------------------------------------------------------------------------

!! Has
function PoPsGaugeBosonsHas(handle) &
      bind(C, name='PoPsGaugeBosonsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsGaugeBosonsHas
end function PoPsGaugeBosonsHas

!! Get, const
function PoPsGaugeBosonsGetConst(handle) &
      bind(C, name='PoPsGaugeBosonsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsGaugeBosonsGetConst
end function PoPsGaugeBosonsGetConst

!! Get
function PoPsGaugeBosonsGet(handle) &
      bind(C, name='PoPsGaugeBosonsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PoPsGaugeBosonsGet
end function PoPsGaugeBosonsGet

!! Set
subroutine PoPsGaugeBosonsSet(handle, fieldHandle) &
      bind(C, name='PoPsGaugeBosonsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PoPsGaugeBosonsSet


!! -----------------------------------------------------------------------------
!! Child: leptons
!! -----------------------------------------------------------------------------

!! Has
function PoPsLeptonsHas(handle) &
      bind(C, name='PoPsLeptonsHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: PoPsLeptonsHas
end function PoPsLeptonsHas

!! Get, const
function PoPsLeptonsGetConst(handle) &
      bind(C, name='PoPsLeptonsGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: PoPsLeptonsGetConst
end function PoPsLeptonsGetConst

!! Get
function PoPsLeptonsGet(handle) &
      bind(C, name='PoPsLeptonsGet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr) :: PoPsLeptonsGet
end function PoPsLeptonsGet

!! Set
subroutine PoPsLeptonsSet(handle, fieldHandle) &
      bind(C, name='PoPsLeptonsSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), intent(in), value :: fieldHandle
end subroutine PoPsLeptonsSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module topPoPs
