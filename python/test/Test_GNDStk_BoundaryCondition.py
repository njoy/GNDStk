# standard imports
import unittest

# third party imports

# local imports
from GNDStk import BoundaryCondition

class Test_GNDStk_BoundaryCondition( unittest.TestCase ) :
    """Unit test for the BoundaryCondition enumerator."""

    def test_component( self ) :

        value = BoundaryCondition.EliminateShiftFunction

        self.assertTrue( value == BoundaryCondition.EliminateShiftFunction )
        self.assertFalse( value == BoundaryCondition.NegativeOrbitalMomentum )
        self.assertFalse( value == BoundaryCondition.Brune )
        self.assertFalse( value == BoundaryCondition.Given )

        self.assertFalse( value != BoundaryCondition.EliminateShiftFunction )
        self.assertTrue( value != BoundaryCondition.NegativeOrbitalMomentum )
        self.assertTrue( value != BoundaryCondition.Brune )
        self.assertTrue( value != BoundaryCondition.Given )

        value = BoundaryCondition.NegativeOrbitalMomentum

        self.assertFalse( value == BoundaryCondition.EliminateShiftFunction )
        self.assertTrue( value == BoundaryCondition.NegativeOrbitalMomentum )
        self.assertFalse( value == BoundaryCondition.Brune )
        self.assertFalse( value == BoundaryCondition.Given )

        self.assertTrue( value != BoundaryCondition.EliminateShiftFunction )
        self.assertFalse( value != BoundaryCondition.NegativeOrbitalMomentum )
        self.assertTrue( value != BoundaryCondition.Brune )
        self.assertTrue( value != BoundaryCondition.Given )

        value = BoundaryCondition.Brune

        self.assertFalse( value == BoundaryCondition.EliminateShiftFunction )
        self.assertFalse( value == BoundaryCondition.NegativeOrbitalMomentum )
        self.assertTrue( value == BoundaryCondition.Brune )
        self.assertFalse( value == BoundaryCondition.Given )

        self.assertTrue( value != BoundaryCondition.EliminateShiftFunction )
        self.assertTrue( value != BoundaryCondition.NegativeOrbitalMomentum )
        self.assertFalse( value != BoundaryCondition.Brune )
        self.assertTrue( value != BoundaryCondition.Given )

        value = BoundaryCondition.Given

        self.assertFalse( value == BoundaryCondition.EliminateShiftFunction )
        self.assertFalse( value == BoundaryCondition.NegativeOrbitalMomentum )
        self.assertFalse( value == BoundaryCondition.Brune )
        self.assertTrue( value == BoundaryCondition.Given )

        self.assertTrue( value != BoundaryCondition.EliminateShiftFunction )
        self.assertTrue( value != BoundaryCondition.NegativeOrbitalMomentum )
        self.assertTrue( value != BoundaryCondition.Brune )
        self.assertFalse( value != BoundaryCondition.Given )

if __name__ == '__main__' :

    unittest.main()
