extern "C"
{
#include "Cpputest_fff.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Cpputest_fff)
{
    void setup()
    {
      Cpputest_fff_Create();
    }

    void teardown()
    {
       Cpputest_fff_Destroy();
    }
};

TEST(Cpputest_fff, Create)
{
  FAIL("Start here");
}

