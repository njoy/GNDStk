
!! THIS FILE WAS AUTOGENERATED!
!! DO NOT MODIFY!

module generalNuclearAmplitudeExpansion
use iso_c_binding
interface


!! -----------------------------------------------------------------------------
!! Basics
!! Create, Assign, Delete
!! -----------------------------------------------------------------------------

!! Create, default, const
function NuclearAmplitudeExpansionDefaultConst() &
      bind(C, name='NuclearAmplitudeExpansionDefaultConst')
   use iso_c_binding
   implicit none
   type(c_ptr) :: NuclearAmplitudeExpansionDefaultConst
end function NuclearAmplitudeExpansionDefaultConst

!! Create, default
function NuclearAmplitudeExpansionDefault() &
      bind(C, name='NuclearAmplitudeExpansionDefault')
   use iso_c_binding
   implicit none
   type(c_ptr) :: NuclearAmplitudeExpansionDefault
end function NuclearAmplitudeExpansionDefault

!! Create, general, const
function NuclearAmplitudeExpansionCreateConst( &
   nuclearTerm, &
   realInterferenceTerm, &
   imaginaryInterferenceTerm &
) &
      bind(C, name='NuclearAmplitudeExpansionCreateConst')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: nuclearTerm
   type(c_ptr), value :: realInterferenceTerm
   type(c_ptr), value :: imaginaryInterferenceTerm
   type(c_ptr) :: NuclearAmplitudeExpansionCreateConst
end function NuclearAmplitudeExpansionCreateConst

!! Create, general
function NuclearAmplitudeExpansionCreate( &
   nuclearTerm, &
   realInterferenceTerm, &
   imaginaryInterferenceTerm &
) &
      bind(C, name='NuclearAmplitudeExpansionCreate')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: nuclearTerm
   type(c_ptr), value :: realInterferenceTerm
   type(c_ptr), value :: imaginaryInterferenceTerm
   type(c_ptr) :: NuclearAmplitudeExpansionCreate
end function NuclearAmplitudeExpansionCreate

!! Assign
subroutine NuclearAmplitudeExpansionAssign(handleLHS, handleRHS) &
      bind(C, name='NuclearAmplitudeExpansionAssign')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handleLHS, handleRHS
end subroutine NuclearAmplitudeExpansionAssign

!! Delete
subroutine NuclearAmplitudeExpansionDelete(handle) &
      bind(C, name='NuclearAmplitudeExpansionDelete')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
end subroutine NuclearAmplitudeExpansionDelete


!! -----------------------------------------------------------------------------
!! I/O
!! Read, Write, Print
!! Each returns 0 if failure, 1 if success.
!! -----------------------------------------------------------------------------

!! Read from file
function NuclearAmplitudeExpansionRead(handle, filename, filenameSize) &
      bind(C, name='NuclearAmplitudeExpansionRead')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: NuclearAmplitudeExpansionRead
end function NuclearAmplitudeExpansionRead

!! Write to file
function NuclearAmplitudeExpansionWrite(handle, filename, filenameSize) &
      bind(C, name='NuclearAmplitudeExpansionWrite')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_size_t), value :: filenameSize
   character(c_char), intent(in) :: filename(filenameSize)
   integer(c_int) :: NuclearAmplitudeExpansionWrite
end function NuclearAmplitudeExpansionWrite

!! Print to standard output, in our prettyprinting format
function NuclearAmplitudeExpansionPrint(handle) &
      bind(C, name='NuclearAmplitudeExpansionPrint')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: NuclearAmplitudeExpansionPrint
end function NuclearAmplitudeExpansionPrint

!! Print to standard output, as XML
function NuclearAmplitudeExpansionPrintXML(handle) &
      bind(C, name='NuclearAmplitudeExpansionPrintXML')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: NuclearAmplitudeExpansionPrintXML
end function NuclearAmplitudeExpansionPrintXML

!! Print to standard output, as JSON
function NuclearAmplitudeExpansionPrintJSON(handle) &
      bind(C, name='NuclearAmplitudeExpansionPrintJSON')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: NuclearAmplitudeExpansionPrintJSON
end function NuclearAmplitudeExpansionPrintJSON


!! -----------------------------------------------------------------------------
!! Child: nuclearTerm
!! -----------------------------------------------------------------------------

!! Has
function NuclearAmplitudeExpansionNuclearTermHas(handle) &
      bind(C, name='NuclearAmplitudeExpansionNuclearTermHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: NuclearAmplitudeExpansionNuclearTermHas
end function NuclearAmplitudeExpansionNuclearTermHas

!! Get, const
function NuclearAmplitudeExpansionNuclearTermGetConst(handle) &
      bind(C, name='NuclearAmplitudeExpansionNuclearTermGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: NuclearAmplitudeExpansionNuclearTermGetConst
end function NuclearAmplitudeExpansionNuclearTermGetConst

!! Get
function NuclearAmplitudeExpansionNuclearTermGet(handle) &
      bind(C, name='NuclearAmplitudeExpansionNuclearTermGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: NuclearAmplitudeExpansionNuclearTermGet
end function NuclearAmplitudeExpansionNuclearTermGet

!! Set
subroutine NuclearAmplitudeExpansionNuclearTermSet(handle, fieldHandle) &
      bind(C, name='NuclearAmplitudeExpansionNuclearTermSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine NuclearAmplitudeExpansionNuclearTermSet


!! -----------------------------------------------------------------------------
!! Child: realInterferenceTerm
!! -----------------------------------------------------------------------------

!! Has
function NuclearAmplitudeExpansionRealInterferenceTermHas(handle) &
      bind(C, name='NuclearAmplitudeExpansionRealInterferenceTermHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: NuclearAmplitudeExpansionRealInterferenceTermHas
end function NuclearAmplitudeExpansionRealInterferenceTermHas

!! Get, const
function NuclearAmplitudeExpansionRealInterferenceTermGetConst(handle) &
      bind(C, name='NuclearAmplitudeExpansionRealInterferenceTermGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: NuclearAmplitudeExpansionRealInterferenceTermGetConst
end function NuclearAmplitudeExpansionRealInterferenceTermGetConst

!! Get
function NuclearAmplitudeExpansionRealInterferenceTermGet(handle) &
      bind(C, name='NuclearAmplitudeExpansionRealInterferenceTermGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: NuclearAmplitudeExpansionRealInterferenceTermGet
end function NuclearAmplitudeExpansionRealInterferenceTermGet

!! Set
subroutine NuclearAmplitudeExpansionRealInterferenceTermSet(handle, fieldHandle) &
      bind(C, name='NuclearAmplitudeExpansionRealInterferenceTermSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine NuclearAmplitudeExpansionRealInterferenceTermSet


!! -----------------------------------------------------------------------------
!! Child: imaginaryInterferenceTerm
!! -----------------------------------------------------------------------------

!! Has
function NuclearAmplitudeExpansionImaginaryInterferenceTermHas(handle) &
      bind(C, name='NuclearAmplitudeExpansionImaginaryInterferenceTermHas')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   integer(c_int) :: NuclearAmplitudeExpansionImaginaryInterferenceTermHas
end function NuclearAmplitudeExpansionImaginaryInterferenceTermHas

!! Get, const
function NuclearAmplitudeExpansionImaginaryInterferenceTermGetConst(handle) &
      bind(C, name='NuclearAmplitudeExpansionImaginaryInterferenceTermGetConst')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: NuclearAmplitudeExpansionImaginaryInterferenceTermGetConst
end function NuclearAmplitudeExpansionImaginaryInterferenceTermGetConst

!! Get
function NuclearAmplitudeExpansionImaginaryInterferenceTermGet(handle) &
      bind(C, name='NuclearAmplitudeExpansionImaginaryInterferenceTermGet')
   use iso_c_binding
   implicit none
   type(c_ptr), intent(in), value :: handle
   type(c_ptr) :: NuclearAmplitudeExpansionImaginaryInterferenceTermGet
end function NuclearAmplitudeExpansionImaginaryInterferenceTermGet

!! Set
subroutine NuclearAmplitudeExpansionImaginaryInterferenceTermSet(handle, fieldHandle) &
      bind(C, name='NuclearAmplitudeExpansionImaginaryInterferenceTermSet')
   use iso_c_binding
   implicit none
   type(c_ptr), value :: handle
   type(c_ptr), value :: fieldHandle
end subroutine NuclearAmplitudeExpansionImaginaryInterferenceTermSet


!! -----------------------------------------------------------------------------
!! -----------------------------------------------------------------------------

end interface
end module generalNuclearAmplitudeExpansion
