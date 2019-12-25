#include "image_menu.h"
#include "image_menu.h" // Did you #ifndef your file?

#include "gtest/gtest.h"
#include <fstream>
#include <string>

class JuliaSetFiveTakeActionTest : public ::testing::Test {
protected:
  JuliaSetFiveTakeActionTest( )
    : color_table( 8 ) {
  }

  virtual void SetUp( ) {
    mExpected = "";
    mInputStream.str( "" );
    mOutputStream.str( "" );

    input_image1.setHeight( 1 );
    input_image1.setWidth( 2 );
    input_image1.setMaxColorValue( 3 );
    input_image1.setPixel( 0, 0, 1, 2, 3 );
    input_image1.setPixel( 0, 1, 2, 1, 0 );

    input_image2.setHeight( 2 );
    input_image2.setWidth( 1 );
    input_image2.setMaxColorValue( 4 );
    input_image2.setPixel( 0, 0, 4, 2, 0 );
    input_image2.setPixel( 1, 0, 0, 1, 2 );

    output_image.setHeight( 1 );
    output_image.setWidth( 1 );
    output_image.setMaxColorValue( 5 );
    output_image.setPixel( 0, 0, 5, 3, 1 );

    grid.setGridSize( 3, 2 );
    grid.setMaxNumber( 111 );
    grid.setNumber( 0, 0, 10 );
    grid.setNumber( 0, 1, 20 );
    grid.setNumber( 1, 0, 30 );
    grid.setNumber( 1, 1, 40 );
    grid.setNumber( 2, 0, 50 );
    grid.setNumber( 2, 1, 60 );

  }

  virtual void TearDown( ) {
  }

  /* data members */
  std::string mChoice;
  std::string mExpected;
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
  PPM input_image1, input_image2, output_image;
  JuliaSet grid;
  ColorTable color_table;
};

TEST_F( JuliaSetFiveTakeActionTest, acceptsJuliaFiveCommand ) {

  /* Setup */
  mExpected = "";
  mInputStream.str( "" );
  mChoice = "julia-five";

  /* Stimulus */
  takeAction( mInputStream, mOutputStream, mChoice, input_image1, input_image2, output_image, grid, color_table );
  const JuliaSet& grid_const = grid;

  /* Comparison */
  // Grid should be updated
  EXPECT_EQ( mExpected, mOutputStream.str( ) );
  EXPECT_EQ( 3, grid_const.getHeight( ) );
  EXPECT_EQ( 2, grid_const.getWidth( ) );
  EXPECT_EQ( 111, grid_const.getMaxNumber( ) );
  EXPECT_EQ(  10,  grid_const.getNumber( 0, 0 ) );
  EXPECT_EQ(  20,  grid_const.getNumber( 0, 1 ) );
  EXPECT_EQ(  30,  grid_const.getNumber( 1, 0 ) );
  EXPECT_EQ(  40,  grid_const.getNumber( 1, 1 ) );
  EXPECT_EQ(  50,  grid_const.getNumber( 2, 0 ) );
  EXPECT_EQ(  60,  grid_const.getNumber( 2, 1 ) );

  // images should not have changed
  EXPECT_EQ( 1, input_image1.getHeight( ) );
  EXPECT_EQ( 2, input_image1.getWidth( ) );
  EXPECT_EQ( 3, input_image1.getMaxColorValue( ) );
  EXPECT_EQ( 1, input_image1.getChannel( 0, 0, 0 ) );
  EXPECT_EQ( 2, input_image1.getChannel( 0, 0, 1 ) );
  EXPECT_EQ( 3, input_image1.getChannel( 0, 0, 2 ) );
  EXPECT_EQ( 2, input_image1.getChannel( 0, 1, 0 ) );
  EXPECT_EQ( 1, input_image1.getChannel( 0, 1, 1 ) );
  EXPECT_EQ( 0, input_image1.getChannel( 0, 1, 2 ) );

  EXPECT_EQ( 2, input_image2.getHeight( ) );
  EXPECT_EQ( 1, input_image2.getWidth( ) );
  EXPECT_EQ( 4, input_image2.getMaxColorValue( ) );
  EXPECT_EQ( 4, input_image2.getChannel( 0, 0, 0 ) );
  EXPECT_EQ( 2, input_image2.getChannel( 0, 0, 1 ) );
  EXPECT_EQ( 0, input_image2.getChannel( 0, 0, 2 ) );
  EXPECT_EQ( 0, input_image2.getChannel( 1, 0, 0 ) );
  EXPECT_EQ( 1, input_image2.getChannel( 1, 0, 1 ) );
  EXPECT_EQ( 2, input_image2.getChannel( 1, 0, 2 ) );

  EXPECT_EQ( 1, output_image.getHeight( ) );
  EXPECT_EQ( 1, output_image.getWidth( ) );
  EXPECT_EQ( 5, output_image.getMaxColorValue( ) );
  EXPECT_EQ( 5, output_image.getChannel( 0, 0, 0 ) );
  EXPECT_EQ( 3, output_image.getChannel( 0, 0, 1 ) );
  EXPECT_EQ( 1, output_image.getChannel( 0, 0, 2 ) );

  /* Tear-down */
  // Done automatically
}
