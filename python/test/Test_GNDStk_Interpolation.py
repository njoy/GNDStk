
# standard imports
import unittest

# local imports
from GNDStk.v2_0 import Interpolation

class Test_GNDStk_Interpolation( unittest.TestCase ) :
    """Unit test for the Interpolation enumerator."""

    def test_component( self ) :

        value = Interpolation.flat

        self.assertTrue( value == Interpolation.flat )
        self.assertFalse( value == Interpolation.linlin )
        self.assertFalse( value == Interpolation.linlog )
        self.assertFalse( value == Interpolation.loglin )
        self.assertFalse( value == Interpolation.loglog )
        self.assertFalse( value == Interpolation.chargedparticle )

        self.assertFalse( value != Interpolation.flat )
        self.assertTrue( value != Interpolation.linlin )
        self.assertTrue( value != Interpolation.linlog )
        self.assertTrue( value != Interpolation.loglin )
        self.assertTrue( value != Interpolation.loglog )
        self.assertTrue( value != Interpolation.chargedparticle )

        value = Interpolation.linlin

        self.assertFalse( value == Interpolation.flat )
        self.assertTrue( value == Interpolation.linlin )
        self.assertFalse( value == Interpolation.linlog )
        self.assertFalse( value == Interpolation.loglin )
        self.assertFalse( value == Interpolation.loglog )
        self.assertFalse( value == Interpolation.chargedparticle )

        self.assertTrue( value != Interpolation.flat )
        self.assertFalse( value != Interpolation.linlin )
        self.assertTrue( value != Interpolation.linlog )
        self.assertTrue( value != Interpolation.loglin )
        self.assertTrue( value != Interpolation.loglog )
        self.assertTrue( value != Interpolation.chargedparticle )

        value = Interpolation.linlog

        self.assertFalse( value == Interpolation.flat )
        self.assertFalse( value == Interpolation.linlin )
        self.assertTrue( value == Interpolation.linlog )
        self.assertFalse( value == Interpolation.loglin )
        self.assertFalse( value == Interpolation.loglog )
        self.assertFalse( value == Interpolation.chargedparticle )

        self.assertTrue( value != Interpolation.flat )
        self.assertTrue( value != Interpolation.linlin )
        self.assertFalse( value != Interpolation.linlog )
        self.assertTrue( value != Interpolation.loglin )
        self.assertTrue( value != Interpolation.loglog )
        self.assertTrue( value != Interpolation.chargedparticle )

        value = Interpolation.loglin

        self.assertFalse( value == Interpolation.flat )
        self.assertFalse( value == Interpolation.linlin )
        self.assertFalse( value == Interpolation.linlog )
        self.assertTrue( value == Interpolation.loglin )
        self.assertFalse( value == Interpolation.loglog )
        self.assertFalse( value == Interpolation.chargedparticle )

        self.assertTrue( value != Interpolation.flat )
        self.assertTrue( value != Interpolation.linlin )
        self.assertTrue( value != Interpolation.linlog )
        self.assertFalse( value != Interpolation.loglin )
        self.assertTrue( value != Interpolation.loglog )
        self.assertTrue( value != Interpolation.chargedparticle )

        value = Interpolation.loglog

        self.assertFalse( value == Interpolation.flat )
        self.assertFalse( value == Interpolation.linlin )
        self.assertFalse( value == Interpolation.linlog )
        self.assertFalse( value == Interpolation.loglin )
        self.assertTrue( value == Interpolation.loglog )
        self.assertFalse( value == Interpolation.chargedparticle )

        self.assertTrue( value != Interpolation.flat )
        self.assertTrue( value != Interpolation.linlin )
        self.assertTrue( value != Interpolation.linlog )
        self.assertTrue( value != Interpolation.loglin )
        self.assertFalse( value != Interpolation.loglog )
        self.assertTrue( value != Interpolation.chargedparticle )

        value = Interpolation.chargedparticle

        self.assertFalse( value == Interpolation.flat )
        self.assertFalse( value == Interpolation.linlin )
        self.assertFalse( value == Interpolation.linlog )
        self.assertFalse( value == Interpolation.loglin )
        self.assertFalse( value == Interpolation.loglog )
        self.assertTrue( value == Interpolation.chargedparticle )

        self.assertTrue( value != Interpolation.flat )
        self.assertTrue( value != Interpolation.linlin )
        self.assertTrue( value != Interpolation.linlog )
        self.assertTrue( value != Interpolation.loglin )
        self.assertTrue( value != Interpolation.loglog )
        self.assertFalse( value != Interpolation.chargedparticle )

if __name__ == '__main__' :

    unittest.main()
