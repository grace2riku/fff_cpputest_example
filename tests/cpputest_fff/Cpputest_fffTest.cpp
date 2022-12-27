extern "C"
{
#include "Cpputest_fff.h"
#include "fff.h"
}

#include "CppUTest/TestHarness.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(DISPLAY_init);
FAKE_VOID_FUNC(DISPLAY_output, char*);
FAKE_VALUE_FUNC(unsigned int, DISPLAY_get_line_capacity);
FAKE_VALUE_FUNC(unsigned int, DISPLAY_get_line_insert_index);


TEST_GROUP(Cpputest_fff)
{
    void setup()
    {
      Cpputest_fff_Create();

      RESET_FAKE(DISPLAY_init);
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

TEST(Cpputest_fff, ReturnValues)
{
  DISPLAY_get_line_insert_index_fake.return_val = 2;
  DISPLAY_get_line_capacity_fake.return_val = 3;

  LONGS_EQUAL(Test_DISPLAY_get_line_insert_index(), 2);
  LONGS_EQUAL(Test_DISPLAY_get_line_capacity(), 3);
}

TEST(Cpputest_fff, Resetting_a_Fake)
{
  UI_init();
  LONGS_EQUAL(DISPLAY_init_fake.call_count, 1);
}
