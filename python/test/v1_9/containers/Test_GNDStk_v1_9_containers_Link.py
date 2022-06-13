# standard imports
import unittest

# third party imports

# local imports
from GNDStk.v1_9.containers import Link

class Test_GNDStk_v1_9_containers_Link( unittest.TestCase ) :
    """Unit test for the Section class."""

    chunk = ( '<link href="../../grid[@index=\'2\']/values" />' )
    wrong = ( '<wrongName href="../../grid[@index=\'2\']/values" />' )

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertEqual( '../../grid[@index=\'2\']/values', chunk.href )

            # verify string
            self.assertEqual( self.chunk, chunk.to_xml_string() )

        # the data are given explicitly
        chunk = Link( href = '../../grid[@index=\'2\']/values' )

        verify_chunk( self, chunk )

        # the data are read from a string
        chunk = Link.from_string( self.chunk )

        verify_chunk( self, chunk )

        # the data are copied
        copy = Link( chunk )

        verify_chunk( self, copy )

    def test_failures( self ) :

        print( '\n' )

        # wrong name
        with self.assertRaises( Exception ) :

            chunk = Link.from_string( self.wrong )

if __name__ == '__main__' :

    unittest.main()
