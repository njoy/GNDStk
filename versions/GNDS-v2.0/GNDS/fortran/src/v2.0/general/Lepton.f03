
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalLepton
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function LeptonDefaultConst() &
      bind(C, name='LeptonDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LeptonDefaultConst
end function LeptonDefaultConst

!! Create, default
function LeptonDefault() &
      bind(C, name='LeptonDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: LeptonDefault
end function LeptonDefault

!! Create, general, const
function LeptonCreateConst( &
   id, &
   generation, &
   mass, &
   spin, &
   parity, &
   charge, &
   halflife, &
   idSize, &
   generationSize &
) &
      bind(C, name='LeptonCreateConst')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: generationSize
   character(c_char), intent(in) :: generation(generationSize)
   type(c_ptr), value :: mass
   type(c_ptr), value :: spin
   type(c_ptr), value :: parity
   type(c_ptr), value :: charge
   type(c_ptr), value :: halflife
   type(c_ptr) :: LeptonCreateConst
end function LeptonCreateConst

!! Create, general
function LeptonCreate( &
   id, &
   generation, &
   mass, &
   spin, &
   parity, &
   charge, &
   halflife, &
   idSize, &
   generationSize &
) &
      bind(C, name='LeptonCreate')
   use iso_c_binding
   implicit none
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
   integer(c_size_t), intent(in), value :: generationSize
   character(c_char), intent(in) :: generation(generationSize)
   type(c_ptr), value :: mass
   type(c_ptr), value :: spin
   type(c_ptr), value :: parity
   type(c_ptr), value :: charge
   type(c_ptr), value :: halflife
   type(c_ptr) :: LeptonCreate
end function LeptonCreate

!! Assign
subroutine LeptonAssign(handleLHS, handleRHS) &
      bind(C, name='LeptonAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine LeptonAssign

!! Delete
subroutine LeptonDelete(handle) &
      bind(C, name='LeptonDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine LeptonDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function LeptonRead(handle, filename, filenameSize) &
      bind(C, name='LeptonRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LeptonRead
end function LeptonRead

!! Write to file
function LeptonWrite(handle, filename, filenameSize) &
      bind(C, name='LeptonWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: LeptonWrite
end function LeptonWrite

!! Print to standard output, in our prettyprinting format
function LeptonPrint(handle) &
      bind(C, name='LeptonPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonPrint
end function LeptonPrint

!! Print to standard output, as XML
function LeptonPrintXML(handle) &
      bind(C, name='LeptonPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonPrintXML
end function LeptonPrintXML

!! Print to standard output, as JSON
function LeptonPrintJSON(handle) &
      bind(C, name='LeptonPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonPrintJSON
end function LeptonPrintJSON


!! -----------------------------------------------------------------------------
!! Metadatum: id
!! -----------------------------------------------------------------------------

!! Has
function LeptonIdHas(handle) &
      bind(C, name='LeptonIdHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonIdHas
end function LeptonIdHas

!! Get
function LeptonIdGet(handle) &
      bind(C, name='LeptonIdGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonIdGet
end function LeptonIdGet

!! Set
subroutine LeptonIdSet(handle, id, idSize) &
      bind(C, name='LeptonIdSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: idSize
   character(c_char), intent(in) :: id(idSize)
end subroutine LeptonIdSet


!! -----------------------------------------------------------------------------
!! Metadatum: generation
!! -----------------------------------------------------------------------------

!! Has
function LeptonGenerationHas(handle) &
      bind(C, name='LeptonGenerationHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonGenerationHas
end function LeptonGenerationHas

!! Get
function LeptonGenerationGet(handle) &
      bind(C, name='LeptonGenerationGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonGenerationGet
end function LeptonGenerationGet

!! Set
subroutine LeptonGenerationSet(handle, generation, generationSize) &
      bind(C, name='LeptonGenerationSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), intent(in), value :: generationSize
   character(c_char), intent(in) :: generation(generationSize)
end subroutine LeptonGenerationSet


!! -----------------------------------------------------------------------------
!! Child: mass
!! -----------------------------------------------------------------------------

!! Has
function LeptonMassHas(handle) &
      bind(C, name='LeptonMassHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonMassHas
end function LeptonMassHas

!! Get, const
function LeptonMassGetConst(handle) &
      bind(C, name='LeptonMassGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonMassGetConst
end function LeptonMassGetConst

!! Get
function LeptonMassGet(handle) &
      bind(C, name='LeptonMassGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonMassGet
end function LeptonMassGet

!! Set
subroutine LeptonMassSet(handle, fieldHandle) &
      bind(C, name='LeptonMassSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine LeptonMassSet


!! -----------------------------------------------------------------------------
!! Child: spin
!! -----------------------------------------------------------------------------

!! Has
function LeptonSpinHas(handle) &
      bind(C, name='LeptonSpinHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonSpinHas
end function LeptonSpinHas

!! Get, const
function LeptonSpinGetConst(handle) &
      bind(C, name='LeptonSpinGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonSpinGetConst
end function LeptonSpinGetConst

!! Get
function LeptonSpinGet(handle) &
      bind(C, name='LeptonSpinGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonSpinGet
end function LeptonSpinGet

!! Set
subroutine LeptonSpinSet(handle, fieldHandle) &
      bind(C, name='LeptonSpinSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine LeptonSpinSet


!! -----------------------------------------------------------------------------
!! Child: parity
!! -----------------------------------------------------------------------------

!! Has
function LeptonParityHas(handle) &
      bind(C, name='LeptonParityHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonParityHas
end function LeptonParityHas

!! Get, const
function LeptonParityGetConst(handle) &
      bind(C, name='LeptonParityGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonParityGetConst
end function LeptonParityGetConst

!! Get
function LeptonParityGet(handle) &
      bind(C, name='LeptonParityGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonParityGet
end function LeptonParityGet

!! Set
subroutine LeptonParitySet(handle, fieldHandle) &
      bind(C, name='LeptonParitySet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine LeptonParitySet


!! -----------------------------------------------------------------------------
!! Child: charge
!! -----------------------------------------------------------------------------

!! Has
function LeptonChargeHas(handle) &
      bind(C, name='LeptonChargeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonChargeHas
end function LeptonChargeHas

!! Get, const
function LeptonChargeGetConst(handle) &
      bind(C, name='LeptonChargeGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonChargeGetConst
end function LeptonChargeGetConst

!! Get
function LeptonChargeGet(handle) &
      bind(C, name='LeptonChargeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonChargeGet
end function LeptonChargeGet

!! Set
subroutine LeptonChargeSet(handle, fieldHandle) &
      bind(C, name='LeptonChargeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine LeptonChargeSet


!! -----------------------------------------------------------------------------
!! Child: halflife
!! -----------------------------------------------------------------------------

!! Has
function LeptonHalflifeHas(handle) &
      bind(C, name='LeptonHalflifeHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: LeptonHalflifeHas
end function LeptonHalflifeHas

!! Get, const
function LeptonHalflifeGetConst(handle) &
      bind(C, name='LeptonHalflifeGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonHalflifeGetConst
end function LeptonHalflifeGetConst

!! Get
function LeptonHalflifeGet(handle) &
      bind(C, name='LeptonHalflifeGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: LeptonHalflifeGet
end function LeptonHalflifeGet

!! Set
subroutine LeptonHalflifeSet(handle, fieldHandle) &
      bind(C, name='LeptonHalflifeSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine LeptonHalflifeSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalLepton
