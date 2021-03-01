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
        self.assertEqual( 0, len( n.metadata ) )
        self.assertEqual( 0, len( n.children ) )
        self.assertEqual( True, n.empty() )
        self.assertEqual( '', n.to_string() )

        n = Node( Node() )
        self.assertEqual( '', n.name )
        self.assertEqual( 0, len( n.metadata ) )
        self.assertEqual( 0, len( n.children ) )
        self.assertEqual( True, n.empty() )
        self.assertEqual( '', n.to_string() )

        n = Node( name = 'NodeName' )
        self.assertEqual( 'NodeName', n.name )
        self.assertEqual( 0, len( n.metadata ) )
        self.assertEqual( 0, len( n.children ) )
        self.assertEqual( False, n.empty() )
        self.assertEqual( 'NodeName:', n.to_string() )

    def test_add( self ) :

        n = Node( 'name' )

        n.add( 'one', 'two' )
        self.assertEqual( 1, len( n.metadata ) )
        self.assertEqual( [ ( 'one', 'two' ) ], n.metadata )

        n.add( '1', '2' )
        self.assertEqual( 2, len( n.metadata ) )
        self.assertEqual( [ ( 'one', 'two' ), ( '1', '2' ) ], n.metadata )

        pair = n.add( 'foobar', 'foo bar' )
        self.assertEqual( 3, len( n.metadata ) )
        self.assertEqual( [ ( 'one', 'two' ), ( '1', '2' ),
                            ( 'foobar', 'foo bar' ) ],
                          n.metadata )

        self.assertEqual( ( 'foobar', 'foo bar' ), pair )

        n.add( '3', 4 )
        self.assertEqual( 4, len( n.metadata ) )
        self.assertEqual( [ ( 'one', 'two' ), ( '1', '2' ),
                            ( 'foobar', 'foo bar' ),
                            ( '3', '4' ) ], n.metadata )

        n.add( '5', 6.01 )
        self.assertEqual( 5, len( n.metadata ) )
        self.assertEqual( [ ( 'one', 'two' ), ( '1', '2' ),
                            ( 'foobar', 'foo bar' ),
                            ( '3', '4' ), ( '5', '6.01' ) ], n.metadata )

    def test_clear( self ) :

        n = Node()
        ref = n.clear()

        # verifies that ref and n are still the same object
        self.assertEqual( True, ref is n )

        # ref and n are empty nodes
        self.assertEqual( '', n.name )
        self.assertEqual( 0, len( n.metadata ) )
        self.assertEqual( 0, len( ref.children ) )
        self.assertEqual( True, n.empty() )
        self.assertEqual( '', n.to_string() )
        self.assertEqual( '', ref.name )
        self.assertEqual( 0, len( ref.metadata ) )
        self.assertEqual( 0, len( ref.children ) )
        self.assertEqual( True, ref.empty() )
        self.assertEqual( '', ref.to_string() )

if __name__ == '__main__' :

    unittest.main()
