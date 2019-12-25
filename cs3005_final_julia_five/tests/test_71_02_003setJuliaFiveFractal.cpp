#include "image_menu.h"
#include "image_menu.h" // Did you #ifndef your file?

#include "gtest/gtest.h"
#include <fstream>

class setJuliaFiveFractalTest : public ::testing::Test {
protected:

  virtual void SetUp( ) {
    mGrid = new JuliaSet( );
    mExpectedOutput = "";
    mInputStream.str( "" );
    mOutputStream.str( "" );
  }

  virtual void TearDown( ) {
    if( mGrid != 0 ) {
      delete mGrid;
      mGrid = 0;
    }
  }

  /* data members */
  std::string mExpectedOutput;
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
  NumberGrid *mGrid;
};

TEST_F( setJuliaFiveFractalTest, hasNoOutput ) {

  /* Setup */
  // Automatic

  /* Stimulus */
  setJuliaFiveFractal( mInputStream, mOutputStream, mGrid );

  /* Comparison */
  EXPECT_EQ( mExpectedOutput, mOutputStream.str( ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( setJuliaFiveFractalTest, doesNotDeleteNullPointer ) {

  /* Setup */
  // Automatic
  delete mGrid;
  mGrid = 0;

  /* Stimulus */
  setJuliaFiveFractal( mInputStream, mOutputStream, mGrid );

  /* Comparison */
  EXPECT_EQ( mExpectedOutput, mOutputStream.str( ) );

  /* Tear-down */
  // Done automatically
}

TEST_F( setJuliaFiveFractalTest, allocatesJuliaSetFive ) {

  /* Setup */
  // Automatic

  /* Stimulus */
  setJuliaFiveFractal( mInputStream, mOutputStream, mGrid );
  JuliaSetFive *ptr = dynamic_cast< JuliaSetFive * >( mGrid );

  /* Comparison */
  EXPECT_EQ( mExpectedOutput, mOutputStream.str( ) );
  EXPECT_NE( (void*)0, ptr );

  /* Tear-down */
  // Done automatically
}
