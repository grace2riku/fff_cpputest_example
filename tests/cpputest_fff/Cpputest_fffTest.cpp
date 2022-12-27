extern "C"
{
#include "Cpputest_fff.h"
#include "fff.h"
}

#include "CppUTest/TestHarness.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(DISPLAY_init);
FAKE_VOID_FUNC(DISPLAY_output, char*);

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
  UI_init();
  LONGS_EQUAL(DISPLAY_init_fake.call_count, 1);
}

TEST(Cpputest_fff, CapturingArguments)
{
  char msg[] = "hello, world";

  UI_write_line(msg);
  LONGS_EQUAL(DISPLAY_output_fake.call_count, 1);
  STRCMP_EQUAL(DISPLAY_output_fake.arg0_val, "hello, world");   // こっちはテスト成功する
//  STRCMP_EQUAL(DISPLAY_output_fake.arg0_val, "hello, worl");  // こっちはテスト失敗する
}
