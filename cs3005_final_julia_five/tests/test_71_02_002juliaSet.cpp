#include "JuliaSet.h"
#include "JuliaSet.h" // Did you #ifndef your file?

#include "gtest/gtest.h"
#include <fstream>

class JuliaSetEscapeTest : public ::testing::Test {
protected:

  virtual void SetUp( ) {
    default_width = 400;
    default_height = 300;
    default_min_x = -2.0;
    default_max_x =  2.0;
    default_min_y = -1.5;
    default_max_y =  1.5;
    default_a = -0.650492;
    default_b = -0.478235;
    default_max_escape_count = 255;
    default_size = 120000;

    expected_width = 300;
    expected_height = 250;
    expected_min_x = -1.0;
    expected_max_x =  1.5;
    expected_min_y = -0.2;
    expected_max_y =  1.2;
    expected_a =  0.314;
    expected_b = -0.271;
    expected_max_escape_count = 123;
    expected_size = 75000;
    js.setGridSize( expected_width, expected_height );
    js.setPlaneSize( expected_min_x, expected_max_x,
                     expected_min_y, expected_max_y );
    js.setParameters( expected_a, expected_b );
    js.setMaxNumber( expected_max_escape_count );
  }

  virtual void TearDown( ) {
  }

  /* data members */
  JuliaSet js;
  int default_width, default_height;
  double default_min_x, default_max_x;
  double default_min_y, default_max_y;
  double default_a, default_b;
  int default_max_escape_count;
  int default_size;

  int expected_width, expected_height;
  double expected_min_x, expected_max_x;
  double expected_min_y, expected_max_y;
  double expected_a, expected_b;
  int expected_max_escape_count;
  int expected_size;
};




TEST_F( JuliaSetEscapeTest, calculatesNextPoint1 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0, x1, y1;
  x0 = 1.0;
  y0 = -1.0;
  double expected_x1 = x0*x0 - y0*y0 + expected_a;
  double expected_y1 = 2*x0*y0 + expected_b;
  js_const.calculateNextPoint( x0, y0, x1, y1 );

  /* Comparison */
  EXPECT_DOUBLE_EQ( expected_x1, x1 );
  EXPECT_DOUBLE_EQ( expected_y1, y1 );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesNextPoint2 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0, x1, y1;
  x0 = -1.0;
  y0 = 1.0;
  double expected_x1 = x0*x0 - y0*y0 + expected_a;
  double expected_y1 = 2*x0*y0 + expected_b;
  js_const.calculateNextPoint( x0, y0, x1, y1 );

  /* Comparison */
  EXPECT_DOUBLE_EQ( expected_x1, x1 );
  EXPECT_DOUBLE_EQ( expected_y1, y1 );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesNextPoint3 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0, x1, y1;
  x0 = -0.3;
  y0 = 0.2;
  double expected_x1 = x0*x0 - y0*y0 + expected_a;
  double expected_y1 = 2*x0*y0 + expected_b;
  js_const.calculateNextPoint( x0, y0, x1, y1 );

  /* Comparison */
  EXPECT_DOUBLE_EQ( expected_x1, x1 );
  EXPECT_DOUBLE_EQ( expected_y1, y1 );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesNextPoint4 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0, x1, y1;
  x0 = 3.1;
  y0 = 2.2;
  double expected_x1 = x0*x0 - y0*y0 + expected_a;
  double expected_y1 = 2*x0*y0 + expected_b;
  js_const.calculateNextPoint( x0, y0, x1, y1 );

  /* Comparison */
  EXPECT_DOUBLE_EQ( expected_x1, x1 );
  EXPECT_DOUBLE_EQ( expected_y1, y1 );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount0_0 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 = 0.1;
  y0 = 2.0;

  /* Comparison */
  EXPECT_EQ( 0, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount0_1 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 = 0.1;
  y0 = -2.0;

  /* Comparison */
  EXPECT_EQ( 0, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount0_2 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 = -2.0;
  y0 =  0.1;

  /* Comparison */
  EXPECT_EQ( 0, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount0_3 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 =  2.0;
  y0 =  0.1;

  /* Comparison */
  EXPECT_EQ( 0, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount1_0 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 = 0.0;
  y0 = 2.0;

  /* Comparison */
  EXPECT_EQ( 1, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount1_1 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 = 0.0;
  y0 = -2.0;

  /* Comparison */
  EXPECT_EQ( 1, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount1_2 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 = -2.0;
  y0 =  0.0;

  /* Comparison */
  EXPECT_EQ( 1, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount1_3 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 =  2.0;
  y0 =  0.0;

  /* Comparison */
  EXPECT_EQ( 1, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount1_4 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 =  1.0;
  y0 =  0.5;

  /* Comparison */
  EXPECT_EQ( 3, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCount1_5 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 =  -0.80;
  y0 =  -0.15;

  /* Comparison */
  EXPECT_EQ( 4, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( JuliaSetEscapeTest, calculatesPlaneEscapeCountMax_0 ) {

  /* Setup */
  // Done automatically

  /* Stimulus */
  const JuliaSet& js_const = js;
  double x0, y0;
  x0 =  0.0;
  y0 =  0.0;

  /* Comparison */
  EXPECT_EQ( expected_max_escape_count, js_const.calculatePlaneEscapeCount( x0, y0 ) );

  /* Tear-down */
  // Done automatically
}
