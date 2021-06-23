# standard imports
import unittest

# third party imports

# local imports
from GNDStk.v1_9.containers import Values

class Test_GNDStk_v1_9_containers_Values( unittest.TestCase ) :
    """Unit test for the Section class."""

    chunk = ( '<values length="4" start="0" valueType="Float64">2500 8.9172 2550 8.9155</values>\n' )
    wrong = ( '<wrongName length="4" start="0" valueType="Float64">2500 8.9172 2550 8.9155</wrongName>\n' )

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertEqual( 4, chunk.length )
            self.assertEqual( 0, chunk.start )
            self.assertEqual( "Float64", chunk.value_type )

            self.assertEqual( 4, len( chunk.doubles ) )

            self.assertAlmostEqual( 2500., chunk.doubles[0] )
            self.assertAlmostEqual( 8.9172, chunk.doubles[1] )
            self.assertAlmostEqual( 2550., chunk.doubles[2] )
            self.assertAlmostEqual( 8.9155, chunk.doubles[3] )

            # verify string
            self.assertEqual( self.chunk, chunk.to_xml_string() )

        # the data is given explicitly (fully specified)
        chunk = Values( length = 4, start = 0, value_type = "Float64",
                        values = [ 2500., 8.9172, 2550., 8.9155 ] )

        verify_chunk( self, chunk )

        # the data is given explicitly (only values)
        chunk = Values( values = [ 2500., 8.9172, 2550., 8.9155 ] )

        verify_chunk( self, chunk )

        # the data is read from a string
        chunk = Values.from_string( self.chunk )

        verify_chunk( self, chunk )

        # the data is copied
        copy = Values( chunk )

        verify_chunk( self, copy )

    def test_failures( self ) :

        print( '\n' )

        # wrong name
        with self.assertRaises( Exception ) :

            chunk = Values.from_string( self.wrong )

if __name__ == '__main__' :

    unittest.main()
