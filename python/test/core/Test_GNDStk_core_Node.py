# standard imports
import unittest

# third party imports

# local imports
from GNDStk.core import Node

class Test_GNDStk_core_Node( unittest.TestCase ) :
    """Unit test for the Node class."""

    def test_constructors( self ) :

        n = Node()
        self.assertEqual( '', n.name )
        self.assertEqual( True, n.empty() )

        n = Node( Node() )
        self.assertEqual( '', n.name )
        self.assertEqual( True, n.empty() )

        n = Node( name = 'NodeName' )
        self.assertEqual( 'NodeName', n.name )
        self.assertEqual( False, n.empty() )

if __name__ == '__main__' :

    unittest.main()
