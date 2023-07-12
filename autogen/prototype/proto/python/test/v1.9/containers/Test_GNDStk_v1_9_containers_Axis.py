# standard imports
import unittest

# third party imports

# local imports
from GNDStk.v1_9.containers import Axis

class Test_GNDStk_v1_9_containers_Axis( unittest.TestCase ) :
    """Unit test for the Section class."""

    chunk = ( '<axis index="1" label="energy_in" unit="eV" />' )
    wrong = ( '<wrongName index="1" label="energy_in" unit="eV" />' )

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertTrue( None != chunk.index )
            self.assertTrue( None != chunk.label )
            self.assertTrue( None != chunk.unit )

            self.assertEqual( 1, chunk.index )
            self.assertEqual( 'energy_in', chunk.label )
            self.assertEqual( 'eV', chunk.unit )

            self.assertEqual( 1, chunk.index )
            self.assertEqual( 'energy_in', chunk.label )
            self.assertEqual( 'eV', chunk.unit )

            # verify string
            self.assertEqual( self.chunk, chunk.to_xml_string() )

        # the data are given explicitly
        chunk = Axis( index = 1, label = 'energy_in', unit = 'eV' )

        verify_chunk( self, chunk )

        # the data are read from a string
        chunk = Axis.from_string( self.chunk )

        verify_chunk( self, chunk )

        # the data are copied
        copy = Axis( chunk )

        verify_chunk( self, copy )

    def test_failures( self ) :

        print( '\n' )

        # wrong name
        with self.assertRaises( Exception ) :

            chunk = Axis.from_string( self.wrong )

if __name__ == '__main__' :

    unittest.main()
