# standard imports
import unittest

# third party imports

# local imports
from GNDStk import GridStyle

class Test_GNDStk_GridStyle( unittest.TestCase ) :
    """Unit test for the GridStyle enumerator."""

    def test_component( self ) :

        value = GridStyle.none

        self.assertTrue( value == GridStyle.none )
        self.assertFalse( value == GridStyle.points )
        self.assertFalse( value == GridStyle.boundaries )
        self.assertFalse( value == GridStyle.parameters )

        self.assertFalse( value != GridStyle.none )
        self.assertTrue( value != GridStyle.points )
        self.assertTrue( value != GridStyle.boundaries )
        self.assertTrue( value != GridStyle.parameters )

        value = GridStyle.points

        self.assertFalse( value == GridStyle.none )
        self.assertTrue( value == GridStyle.points )
        self.assertFalse( value == GridStyle.boundaries )
        self.assertFalse( value == GridStyle.parameters )

        self.assertTrue( value != GridStyle.none )
        self.assertFalse( value != GridStyle.points )
        self.assertTrue( value != GridStyle.boundaries )
        self.assertTrue( value != GridStyle.parameters )

        value = GridStyle.boundaries

        self.assertFalse( value == GridStyle.none )
        self.assertFalse( value == GridStyle.points )
        self.assertTrue( value == GridStyle.boundaries )
        self.assertFalse( value == GridStyle.parameters )

        self.assertTrue( value != GridStyle.none )
        self.assertTrue( value != GridStyle.points )
        self.assertFalse( value != GridStyle.boundaries )
        self.assertTrue( value != GridStyle.parameters )

        value = GridStyle.parameters

        self.assertFalse( value == GridStyle.none )
        self.assertFalse( value == GridStyle.points )
        self.assertFalse( value == GridStyle.boundaries )
        self.assertTrue( value == GridStyle.parameters )

        self.assertTrue( value != GridStyle.none )
        self.assertTrue( value != GridStyle.points )
        self.assertTrue( value != GridStyle.boundaries )
        self.assertFalse( value != GridStyle.parameters )

if __name__ == '__main__' :

    unittest.main()
