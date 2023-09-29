/***********************************************************************
 * Header:
 *    UNIT TEST
 * Summary:
 *    The base class to all the unit test classes
 * Author:
 *    James Helfrich
 ************************************************************************/

#pragma once

#define assertCondition(condition)               assertUnitParameters(condition, #condition, __LINE__, __FUNCTION__)
#define assertValues(expect, actual, tolerance)  assertUnitParameters(expect, actual, tolerance, #expect, #actual, #tolerance, __LINE__, __FUNCTION__)

#include <iostream>  // for std::cerr
#include <string>    // for std::string
#include <vector>    // for std::vector
#include <map>       // for std::map

/***********************************************************************
 * UNIT TEST
 *    Base class for the unit test code. This will define custom asserts
 *    that collect failures and report them at the end.
 ************************************************************************/
class UnitTest
{
public:
   UnitTest() { reset(); }

private:
   // a test failure is a failure string and a line number
   struct Failure
   {
      std::string failure;
      int         lineNumber;
   };

   // each test has a name (the key) and the list of failures(value).
   std::map<std::string, std::vector<Failure>> tests;

protected:
   /*************************************************************
    * RESET
    * Reset the statistics
    *************************************************************/
   void reset()
   {
      tests.clear();
   }

   /*************************************************************
    * REPORT
    * Report the statistics
    *************************************************************/
   void report(const char* name)
   {
      // enumerate the failures, if there are any
      for (auto& test : tests)
         if (!test.second.empty())
         {
            std::cerr << "\t" << test.first << "()\n";
            for (auto& failure : test.second)
               std::cerr << "\t\tline:" << failure.lineNumber
               << " condition:" << failure.failure << "\n";
         }

      // Name the test case
      std::cerr << name << ":\t";

      // handle the no test case
      if (tests.empty())
      {
         std::cerr << "There were no tests]\n";
         return;
      }

      // determine the success rate
      int numSuccess = 0;
      for (auto& test : tests)
         numSuccess += (test.second.empty() ? 1 : 0);
      double successRate = (double)numSuccess / (double)tests.size();

      // display the summary
      std::cerr.setf(std::ios::fixed | std::ios::showpoint);
      std::cerr.precision(1);
      std::cerr << "There were "
         << tests.size()
         << " tests run for a success rate of: "
         << (successRate * 100.0) << "%\n";

   }

   /*************************************************************
    * ASSERT UNIT PARAMETERS
    * Custom assert code so we can see all the errors at once
    *************************************************************/
   void assertUnitParameters(bool condition, const char* conditionString,
      int line, const char* func)
   {
      std::string sFunc(func);

      if (!condition)
      {
         // add a failure to the list of failures
         Failure failure{ std::string(conditionString), line };
         tests[sFunc].push_back(failure);
      }
      else
      {
         // this ensures there is a placeholder for the successful test
         tests[sFunc];
      }
   }
   void assertUnitParameters(double expect, double actual, double tolerance, 
                             const char* expectString, const char* actualString, const char* toleranceString,
                             int line, const char* func)
   {
      std::string sFunc(func);

      if (expect + tolerance <= actual || expect - tolerance >= actual)
      {
         // add a failure to the list of failures
         Failure failure{ std::string(expectString) + std::string(" == ") + std::string(actualString), line };
         tests[sFunc].push_back(failure);
      }
      else
      {
         // this ensures there is a placeholder for the successful test
         tests[sFunc];
      }
   }
};
