# standard imports
import unittest

# third party imports

# local imports
from GNDStk.v1_9.containers import Values

class Test_GNDStk_v1_9_containers_Values( unittest.TestCase ) :
    """Unit test for the Section class."""

    chunk_doubles = ( '<values>2500 8.9172 2550 8.9155</values>\n' )
    chunk_ints = ( '<values valueType="Integer32">2500 9 2550 9</values>\n' )
    chunk_strings = ( '<values valueType="UTF8Text">2500 8.9172 2550 8.9155</values>\n' )
    wrong = ( '<wrongName length="4" start="0" valueType="Float64">2500 8.9172 2550 8.9155</wrongName>\n' )

    def test_component( self ) :

        def verify_chunk_doubles( self, chunk ) :

            # verify content
            self.assertEqual( None, chunk.length )
            self.assertEqual( 0, chunk.start )
            self.assertEqual( "Float64", chunk.value_type )

            self.assertEqual( 4, len( chunk.doubles ) )

            self.assertAlmostEqual( 2500., chunk.doubles[0] )
            self.assertAlmostEqual( 8.9172, chunk.doubles[1] )
            self.assertAlmostEqual( 2550., chunk.doubles[2] )
            self.assertAlmostEqual( 8.9155, chunk.doubles[3] )

            # verify string
            self.assertEqual( self.chunk_doubles, chunk.to_xml_string() )

        def verify_chunk_ints( self, chunk ) :

            # verify content
            self.assertEqual( None, chunk.length )
            self.assertEqual( 0, chunk.start )
            self.assertEqual( "Integer32", chunk.value_type )

            self.assertEqual( 4, len( chunk.ints ) )

            self.assertEqual( 2500, chunk.ints[0] )
            self.assertEqual( 9, chunk.ints[1] )
            self.assertEqual( 2550, chunk.ints[2] )
            self.assertEqual( 9, chunk.ints[3] )

            # verify string
            self.assertEqual( self.chunk_ints, chunk.to_xml_string() )

        def verify_chunk_strings( self, chunk ) :

            # verify content
            self.assertEqual( None, chunk.length )
            self.assertEqual( 0, chunk.start )
            self.assertEqual( "UTF8Text", chunk.value_type )

            self.assertEqual( 4, len( chunk.strings ) )

            self.assertAlmostEqual( "2500", chunk.strings[0] )
            self.assertAlmostEqual( "8.9172", chunk.strings[1] )
            self.assertAlmostEqual( "2550", chunk.strings[2] )
            self.assertAlmostEqual( "8.9155", chunk.strings[3] )

            # verify string
            self.assertEqual( self.chunk_strings, chunk.to_xml_string() )

        # the data is given explicitly (doubles)
        chunk = Values( doubles = [ 2500., 8.9172, 2550., 8.9155 ] )

        verify_chunk_doubles( self, chunk )

        # the data is read from a string
        chunk = Values.from_string( self.chunk_doubles )

        verify_chunk_doubles( self, chunk )

        # the data is copied
        copy = Values( chunk )

        verify_chunk_doubles( self, copy )

        # the data is given explicitly (ints)
        chunk = Values( value_type = "Integer32", ints = [ 2500, 9, 2550, 9 ] )

        verify_chunk_ints( self, chunk )

        # the data is read from a string
        chunk = Values.from_string( self.chunk_ints )

        verify_chunk_ints( self, chunk )

        # the data is copied
        copy = Values( chunk )

        verify_chunk_ints( self, copy )

        # the data is given explicitly (strings)
        chunk = Values( value_type = "UTF8Text", strings = [ "2500", "8.9172", "2550", "8.9155" ] )

        verify_chunk_strings( self, chunk )

        # the data is read from a string
        chunk = Values.from_string( self.chunk_strings )

        verify_chunk_strings( self, chunk )

        # the data is copied
        copy = Values( chunk )

        verify_chunk_strings( self, copy )

    def test_failures( self ) :

        print( '\n' )

        # wrong name
        with self.assertRaises( Exception ) :

            chunk = Values.from_string( self.wrong )

if __name__ == '__main__' :

    unittest.main()
