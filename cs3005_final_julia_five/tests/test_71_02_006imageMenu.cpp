#include "image_menu.h"
#include "image_menu.h" // Did you #ifndef your file?

#include "gtest/gtest.h"
#include <fstream>
#include <string>

class JuliaSetFiveImageMenuTest : public ::testing::Test {
protected:

  virtual void SetUp( ) {
    mInputStream.str( "" );
    mOutputStream.str( "" );
  }

  virtual void TearDown( ) {
  }

  /* data members */
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
};

TEST_F( JuliaSetFiveImageMenuTest, usesJuliaFiveCommand ) {

  /* Setup */
  mInputStream.str( "julia julia-five grid 250 300 123 julia-parameters 0.314 -0.271 fractal-plane-size -1.0 1.5 -0.2 1.2 fractal-calculate-single-thread grid-apply write julia-five-image.ppm quit" );

  /* Stimulus */
  imageMenu( mInputStream, mOutputStream );

  /* Comparison */
  PPM ppm_tmp;
  mInputStream.clear( );
  mInputStream.str( "julia-five-image.ppm" );
  readUserImage( mInputStream, mOutputStream, ppm_tmp );
  remove( "julia-five-image.ppm" );
  const PPM& ppm_const = ppm_tmp;

  EXPECT_EQ( 250, ppm_const.getHeight( ) );
  EXPECT_EQ( 300, ppm_const.getWidth( ) );
  EXPECT_EQ( 63, ppm_const.getMaxColorValue( ) );

  EXPECT_EQ( 63, ppm_const.getChannel( 0, 0, 0 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 0, 0, 1 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 0, 0, 2 ) );

  EXPECT_EQ( 63, ppm_const.getChannel( 249, 0, 0 ) );
  EXPECT_EQ( 63, ppm_const.getChannel( 249, 0, 1 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 249, 0, 2 ) );

  EXPECT_EQ( 63, ppm_const.getChannel( 0, 299, 0 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 0, 299, 1 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 0, 299, 2 ) );

  EXPECT_EQ( 63, ppm_const.getChannel( 249, 299, 0 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 249, 299, 1 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 249, 299, 2 ) );

  EXPECT_EQ( 63, ppm_const.getChannel( 125, 175, 0 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 125, 175, 1 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 125, 175, 2 ) );

  EXPECT_EQ( 63, ppm_const.getChannel( 162, 210, 0 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 162, 210, 1 ) );
  EXPECT_EQ( 31, ppm_const.getChannel( 162, 210, 2 ) );


  /* Tear-down */
  // Done automatically
}
