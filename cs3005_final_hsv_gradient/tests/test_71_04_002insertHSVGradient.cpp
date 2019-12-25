#include "ColorTable.h"
#include "ColorTable.h" // Did you #ifndef your file?

#include "gtest/gtest.h"
#include <fstream>

class ColorTableHSVGradientTest : public ::testing::Test {
protected:
  ColorTableHSVGradientTest( )
    : color_table( 8 ),
      expected_color_0{ 255, 254, 253 },
      expected_color_1{ 249, 248, 247 },
      expected_color_2{  20,  87,  24 },
      expected_color_3{  73, 105,  69 },
      expected_color_4{ 126, 123, 115 },
      expected_color_5{ 179, 141, 160 },
      expected_color_6{ 232, 159, 206 },
      expected_color_7{ 252, 251, 250 },
      h1( 123.456 ), s1( 0.765 ), v1( 0.345 ),
      h2( 321.654 ), s2( 0.314 ), v2( 0.912 ) {
  }

  virtual void SetUp( ) {
    color_table[ 0 ] = expected_color_0;
    color_table[ 1 ] = expected_color_1;
    color_table[ 2 ] = expected_color_1;
    color_table[ 3 ] = expected_color_1;
    color_table[ 4 ] = expected_color_1;
    color_table[ 5 ] = expected_color_1;
    color_table[ 6 ] = expected_color_1;
    color_table[ 7 ] = expected_color_7;
  }

  virtual void TearDown( ) {
  }

  /* data members */
  ColorTable color_table;
  Color expected_color_0;
  Color expected_color_1;
  Color expected_color_2;
  Color expected_color_3;
  Color expected_color_4;
  Color expected_color_5;
  Color expected_color_6;
  Color expected_color_7;
  double h1, s1, v1;
  double h2, s2, v2;
};

TEST_F( ColorTableHSVGradientTest, setsGradientColors ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  color_table.insertHSVGradient( h1, s1, v1, h2, s2, v2, 2, 6 );

  /* Comparison */
  EXPECT_EQ( expected_color_2, color_table[ 2 ] );
  EXPECT_EQ( expected_color_3, color_table[ 3 ] );
  EXPECT_EQ( expected_color_4, color_table[ 4 ] );
  EXPECT_EQ( expected_color_5, color_table[ 5 ] );
  EXPECT_EQ( expected_color_6, color_table[ 6 ] );

  /* Tear-down */
  // Done automatically
}

TEST_F( ColorTableHSVGradientTest, setsGradientColors2 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  color_table.insertHSVGradient( h2, s2, v2, h1, s1, v1, 2, 6 );

  /* Comparison */
  EXPECT_EQ( expected_color_6, color_table[ 2 ] );
  EXPECT_EQ( expected_color_5, color_table[ 3 ] );
  EXPECT_EQ( expected_color_4, color_table[ 4 ] );
  EXPECT_EQ( expected_color_3, color_table[ 5 ] );
  EXPECT_EQ( expected_color_2, color_table[ 6 ] );

  /* Tear-down */
  // Done automatically
}
