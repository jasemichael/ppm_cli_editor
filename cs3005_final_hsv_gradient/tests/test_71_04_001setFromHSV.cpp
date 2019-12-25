#include "ColorTable.h"
#include "ColorTable.h" // Did you #ifndef your file?

#include "gtest/gtest.h"
#include <fstream>

class SetFromHSVTest : public ::testing::Test {
protected:
  SetFromHSVTest( )
    : color( 13, 17, 19 ) {
  }

  virtual void SetUp( ) {
  }

  virtual void TearDown( ) {
  }

  /* data members */
  Color color;
  double hue, sat, val;
  int expected_red;
  int expected_green;
  int expected_blue;
};

TEST_F( SetFromHSVTest, setsColorInHue60 ) {

  /* Setup */
  hue = 25.0;
  sat = 1.0;
  val = 0.6;
  expected_red = 153;
  expected_green = 63;
  expected_blue = 0;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}


TEST_F( SetFromHSVTest, setsColorInHue120 ) {

  /* Setup */
  hue = 115.0;
  sat = 0.9;
  val = 1.0;
  expected_red = 44;
  expected_green = 255;
  expected_blue = 25;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( SetFromHSVTest, setsColorInHue180 ) {

  /* Setup */
  hue = 125.0;
  sat = 0.67;
  val = 0.74;
  expected_red = 62;
  expected_green = 188;
  expected_blue = 72;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}


TEST_F( SetFromHSVTest, setsColorInHue240 ) {

  /* Setup */
  hue = 225.0;
  sat = 0.76;
  val = 0.7;
  expected_red = 42;
  expected_green = 76;
  expected_blue = 178;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( SetFromHSVTest, setsColorInHue300 ) {

  /* Setup */
  hue = 252.0;
  sat = 0.3;
  val = 0.9;
  expected_red = 174;
  expected_green = 160;
  expected_blue = 229;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}


TEST_F( SetFromHSVTest, setsColorInHue360 ) {

  /* Setup */
  hue = 343.0;
  sat = 0.7;
  val = 0.1;
  expected_red = 25;
  expected_green = 7;
  expected_blue = 12;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( SetFromHSVTest, setsColorWithValue0 ) {

  /* Setup */
  hue = 343.0;
  sat = 0.7;
  val = 0.0;
  expected_red = 0;
  expected_green = 0;
  expected_blue = 0;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( SetFromHSVTest, setsColorWithSaturation0 ) {

  /* Setup */
  hue = 343.0;
  sat = 0.0;
  val = 0.3;
  expected_red = 76;
  expected_green = 76;
  expected_blue = 76;


  /* Stimulus */
  color.setFromHSV( hue, sat, val );
  const Color& color_const = color;

  /* Comparison */
  EXPECT_EQ( expected_red, color_const.getRed( ) );
  EXPECT_EQ( expected_green, color_const.getGreen( ) );
  EXPECT_EQ( expected_blue, color_const.getBlue( ) );

  /* Tear-down */
  // Done automatically
}
