# standard imports
import unittest

# third party imports

# local imports
from GNDStk import GridStyle, Interpolation
from GNDStk.v1_9.containers import Values
from GNDStk.v1_9.containers import Grid

class Test_GNDStk_v1_9_containers_Grid( unittest.TestCase ) :
    """Unit test for the Section class."""

    chunk = ( '<grid index="2" label="row_energy_bounds" style="boundaries" unit="eV">\n'
              '   <values valueType="Float64" start="0" length="2">1e-05 2e+07</values>\n'
              '</grid>' )
    chunkWithLink = ( '<grid index="1" label="column_energy_bounds" style="link" unit="eV">\n'
                      '   <link href="../../grid[@index=\'2\']/values" />\n'
                      '</grid>' )
    wrong = ( '<wrongName index="2" label="row_energy_bounds" style="boundaries" unit="eV">\n'
              '   <values valueType="Float64" start="0" length="2">1e-05 2e+07</values>\n'
              '</wrongName>' )

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertTrue( None !=  chunk.index )
            self.assertTrue( None !=  chunk.label )
            self.assertTrue( None !=  chunk.style )
            self.assertTrue( None !=  chunk.unit )

            self.assertEqual( 2,  chunk.index )
            self.assertEqual( "row_energy_bounds",  chunk.label )
            self.assertEqual( "eV",  chunk.unit )
            self.assertEqual( GridStyle.boundaries,  chunk.style )

            self.assertEqual( 2,  chunk.index )
            self.assertEqual( "row_energy_bounds",  chunk.label )
            self.assertEqual( "eV",  chunk.unit )
            self.assertEqual( GridStyle.boundaries,  chunk.style )

            values =  chunk.link_values
            self.assertEqual( 2, values.length )
            self.assertEqual( 0, values.start )
            self.assertEqual( "Float64", values.value_type )

            #self.assertEqual( "1e-05 2e+07", values.string )

            #self.assertEqual( 2, values.size )
            self.assertEqual( 2, len( values.doubles ) )

            self.assertAlmostEqual( 1e-5, values.doubles[0] )
            self.assertAlmostEqual( 2e+7, values.doubles[1] )

            # verify string
            self.assertEqual( self.chunk, chunk.to_xml_string() )

        # the data are given explicitly
        chunk = Grid( index = 2, label = "row_energy_bounds",
                      unit = "eV", style = GridStyle.boundaries,
                      link_values = Values( [ 1e-5, 2e7 ] ) )

        verify_chunk( self, chunk )

        # the data are read from a string
        chunk = Grid.from_string( self.chunk )

        verify_chunk( self, chunk )

        # the data are copied
        copy = Grid( chunk )

        verify_chunk( self, copy )

    def test_failures( self ) :

        print( '\n' )

        # wrong name
        with self.assertRaises( Exception ) :

            chunk = Grid.from_string( self.wrong )

if __name__ == '__main__' :

    unittest.main()
