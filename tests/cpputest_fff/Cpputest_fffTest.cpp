extern "C"
{
#include "Cpputest_fff.h"
#include "fff.h"
}

#include "CppUTest/TestHarness.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(DISPLAY_init);

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

IGNORE_TEST(Cpputest_fff, Create)
{
  FAIL("Start here");
}

TEST(Cpputest_fff, HelloFakeWorld)
{
//  FAIL("Start here");
  LONGS_EQUAL(DISPLAY_init_fake.call_count, 1);
}
