/***********************************************************************
 * Header:
 *    TEST  ANGLE
 * Summary:
 *    All the unit tests for the Angle class
 * Author
 *    Br. Helfrich
 ************************************************************************/

#pragma once

#include "angle.h"
#include "unitTest.h"
#include <sstream>

 /************************************
  * TEST ANGLE
  ************************************/
class TestAngle : public UnitTest
{
public:
   void run()
   {
      reset();

      // get
      test_getRadians_0();
      test_getRadians_90();
      test_getRadians_180();
      test_getDegrees_0();
      test_getDegrees_90();
      test_getDegrees_180();

      // normalize
      test_normalize_0();
      test_normalize_typical();
      test_normalize_negative();
      test_normalize_positiveLap();
      test_normalize_positiveManyLaps();
      test_normalize_negativeLap();
      test_normalize_negativeManyLaps();

      // convert
      test_convertToDegrees_0();
      test_convertToDegrees_90();
      test_convertToDegrees_180();
      test_convertToDegrees_negative();
      test_convertToDegrees_negativeFourLaps();
      test_convertToDegrees_fourLaps();
      test_convertToRadians_0();
      test_convertToRadians_90();
      test_convertToRadians_180();
      test_convertToRadians_negative();
      test_convertToRadians_negativeFourLaps();
      test_convertToRadians_fourLaps();

      // set
      test_setRadians_0();
      test_setRadians_90();
      test_setRadians_180();
      test_setRadians_positiveLap();
      test_setRadians_negativeLap();
      test_setDegrees_0();
      test_setDegrees_90();
      test_setDegrees_180();
      test_setDegrees_positiveLap();
      test_setDegrees_negativeLap();

      // display
      test_display_0();
      test_display_90();
      test_display_180();
      test_display_359();



      report("Angle");
   }
private:

/***************************************
 * GET
 ***************************************/

   // get radians zero
   void test_getRadians_0()
   {  // setup
      Angle a;
      a.radians = 0.0;
      double result;
      // exercise
      result = a.getRadians();
      // verify
      assertValues(result,    0.0, 0.001);
      assertValues(a.radians, 0.0, 0.001);
   }  // teardown

   // get radians 90
   void test_getRadians_90()
   {  // setup
      Angle a;
      a.radians = 1.570795; // PI / 2
      double result;
      // exercise
      result = a.getRadians();
      // verify
      assertValues(result,    1.570795, 0.001);
      assertValues(a.radians, 1.570795, 0.001);
   }  // teardown
   
   // get radians 180
   void test_getRadians_180()
   {  // setup
      Angle a;
      a.radians = 3.14159;
      double result;
      // exercise
      result = a.getRadians();
      // verify
      assertValues(result,    3.14159, 0.001);
      assertValues(a.radians, 3.14159, 0.001);
   }  // teardown

   // get degrees zero
   void test_getDegrees_0()
   {  // setup
      Angle a;
      a.radians = 0.0;
      double result;
      // exercise
      result = a.getDegrees();
      // verify
      assertValues(result,    0.0, 0.001);
      assertValues(a.radians, 0.0, 0.001);
   }  // teardown

   // get degrees 90
   void test_getDegrees_90()
   {  // setup
      Angle a;
      a.radians = 1.570795; // PI / 2
      double result;
      // exercise
      result = a.getDegrees();
      // verify
      assertValues(result,    90.0,     0.001);
      assertValues(a.radians, 1.570795, 0.001);
   }  // teardown

   // get degrees 180
   void test_getDegrees_180()
   {  // setup
      Angle a;
      a.radians = 3.14159;
      double result;
      // exercise
      result = a.getDegrees();
      // verify
      assertValues(result,    180.0,   0.001);
      assertValues(a.radians, 3.14159, 0.001);
   }  // teardown

 /***************************************
  * NORMALIZE
  ***************************************/

   // normalize 0
   void test_normalize_0()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.normalize(0.0);
      // verify
      assertValues(result, 0.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // normalize typical value
   void test_normalize_typical()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.normalize(1.23);
      // verify
      assertValues(result, 1.23, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // normalize negative
   void test_normalize_negative()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.normalize(-1.0);
      // verify
      assertValues(result, 6.28318530717 - 1.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // normalize one lap in the positive direction
   void test_normalize_positiveLap()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.normalize(6.28318530717 + 1.234);
      // verify
      assertValues(result, 1.234, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // normalize ten laps in the positive direction
   void test_normalize_positiveManyLaps()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.normalize(6.28318530717 * 10.0 + 2.121);
      // verify
      assertValues(result, 2.121, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // normalize one lap in the negative direction
   void test_normalize_negativeLap()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.normalize(-2.0 * 6.28318530717 + 1.234);
      // verify
      assertValues(result, 1.234, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // normalize ten laps in the positive direction
   void test_normalize_negativeManyLaps()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.normalize(-11.0 * 6.28318530717 + 2.121);
      // verify
      assertValues(result, 2.121, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

/***************************************
 * CONVERT
 ***************************************/

 // convert 0 radians to degrees
   void test_convertToDegrees_0()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToDegrees(0.0);
      // verify
      assertValues(result, 0.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert PI/2 radians to degrees
   void test_convertToDegrees_90()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToDegrees(1.570795);  // PI / 2
      // verify
      assertValues(result, 90.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert PI radians to degrees
   void test_convertToDegrees_180()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToDegrees(3.14159);  // PI 
      // verify
      assertValues(result, 180.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert -3PI/2 radians to degrees
   void test_convertToDegrees_negative()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToDegrees(-4.7123889);  // -3PI/2 
      // verify
      assertValues(result, 90.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert -10PI + PI/2 radians to degrees
   void test_convertToDegrees_negativeFourLaps()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToDegrees(-10 * 3.1415926 + 3.1415926 / 2.0);  // -3PI/2 
      // verify
      assertValues(result, 90.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert 10PI - PI/2 radians to degrees
   void test_convertToDegrees_fourLaps()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToDegrees(10 * 3.1415926 - 3.1415926 / 2.0);  // -3PI/2 
      // verify
      assertValues(result, 270.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert 0 degrees to radians
   void test_convertToRadians_0()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToRadians(0.0);
      // verify
      assertValues(result, 0.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert 90 degrees to radians
   void test_convertToRadians_90()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToRadians(90.0);
      // verify
      assertValues(result, 1.570795, 0.001);  // PI / 2
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert 180 degrees to radians
   void test_convertToRadians_180()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToRadians(180.0);
      // verify
      assertValues(result, 3.14159, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert -90.0 degrees to radians
   void test_convertToRadians_negative()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToRadians(-90.0);
      // verify
      assertValues(result, 4.7123889, 0.001);  // 3PI/2 
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert four laps + 90 degrees to radians
   void test_convertToRadians_negativeFourLaps()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToRadians(-1350.0);  // -4.0 * 360.0 + 90.0
      // verify
      assertValues(result, 3.1415926 / 2.0, 0.001);
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown

   // convert 10PI - PI/2 radians to degrees
   void test_convertToRadians_fourLaps()
   {  // setup
      Angle a;
      a.radians = 99.9;
      double result;
      // exercise
      result = a.convertToRadians(1710.0);  // 5 *  360 - 90
      // verify
      assertValues(result, 4.7123889, 0.001);  // 3 PI / 2
      assertValues(a.radians, 99.9, 0.001);
   }  // teardown


/***************************************
 * SET
 ***************************************/

   // set radians zero
   void test_setRadians_0()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setRadians(0.0);
      // verify
      assertValues(a.radians, 0.0, 0.001);
   }  // teardown

   // set radians 90
   void test_setRadians_90()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setRadians(1.570795);  // PI / 2
      // verify
      assertValues(a.radians, 1.570795, 0.001);
   }  // teardown

   // set radians 180
   void test_setRadians_180()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setRadians(3.14159);
      // verify
      assertValues(a.radians, 3.14159, 0.001);
   }  // teardown

   // set radians 90 + 720 
   void test_setRadians_positiveLap()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setRadians(2.0 * 6.28318530717 + 1.234);
      // verify
      assertValues(a.radians, 1.234, 0.001);
   }  // teardown

   // set radians -720 + 90
   void test_setRadians_negativeLap()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setRadians(-2.0 * 6.28318530717 + 1.234);
      // verify
      assertValues(a.radians, 1.234, 0.001);
   }  // teardown

   // set degrees zero
   void test_setDegrees_0()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setDegrees(0.0);
      // verify
      assertValues(a.radians, 0.0, 0.001);
   }  // teardown

   // set degrees 90
   void test_setDegrees_90()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setDegrees(90.0); 
      // verify
      assertValues(a.radians, 1.570795, 0.001);   // PI / 2
   }  // teardown

   // set degrees 180
   void test_setDegrees_180()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setDegrees(180.0);
      // verify
      assertValues(a.radians, 3.14159, 0.001);
   }  // teardown

   // set radians 90 + 720 
   void test_setDegrees_positiveLap()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setDegrees(720.0 + 90.0);
      // verify
      assertValues(a.radians, 1.570795, 0.001);  // PI / 2
   }  // teardown

   // set radians -720 + 90
   void test_setDegrees_negativeLap()
   {  // setup
      Angle a;
      a.radians = 99.99;
      // exercise
      a.setDegrees(-720.0 + 90.0);
      // verify
      assertValues(a.radians, 1.570795, 0.001);  // PI / 2
   }  // teardown

/***************************************
 * DISPLAY
 ***************************************/

   // display zero
   void test_display_0()
   {  // setup
      Angle a;
      a.radians = 0.0;
      std::ostringstream out;
      // exercise
      a.display(out);
      // verify
      assertCondition(out.str() == string("0.0degrees"));
      assertValues(a.radians, 0.0, 0.001);
   }  // teardown

   // display 90
   void test_display_90()
   {  // setup
      Angle a;
      a.radians = 1.570795;  // PI / 2
      std::ostringstream out;
      // exercise
      a.display(out);
      // verify
      assertCondition(out.str() == string("90.0degrees"));
      assertValues(a.radians, 1.570795, 0.001);
   }  // teardown

   // display 180
   void test_display_180()
   {  // setup
      Angle a;
      a.radians = 3.14159;
      std::ostringstream out;
      // exercise
      a.display(out);
      // verify
      assertCondition(out.str() == string("180.0degrees"));
      assertValues(a.radians, 3.14159, 0.001);
   }  // teardown

   // display 359.9
   void test_display_359()
   {  // setup
      Angle a;
      a.radians = 6.27445866; // 359.5 / 360 * 2 PI
      std::ostringstream out;
      // exercise
      a.display(out);
      // verify
      assertCondition(out.str() == string("359.5degrees"));
      assertValues(a.radians, 6.27445866, 0.001);
   }  // teardown


};
