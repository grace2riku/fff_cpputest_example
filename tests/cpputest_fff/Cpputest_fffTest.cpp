// Want to keep the argument history for 13 calls
#define FFF_ARG_HISTORY_LEN 13
// Want to keep the call sequence history for 17 calls
#define FFF_CALL_HISTORY_LEN 17

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
FAKE_VOID_FUNC(voidfunc2, char, char);
FAKE_VALUE_FUNC(long, longfunc0);
FAKE_VOID_FUNC(voidfunc1outparam, char*);


TEST_GROUP(Cpputest_fff)
{
    void setup()
    {
      Cpputest_fff_Create();

      RESET_FAKE(DISPLAY_init);
      RESET_FAKE(voidfunc2);
      RESET_FAKE(longfunc0);
      RESET_FAKE(voidfunc1outparam);

      /* reset common FFF internal structures */
      FFF_RESET_HISTORY();      
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


TEST(Cpputest_fff, CallHistory)
{
//  FAIL("fail");
  longfunc0();
  voidfunc2('a', 'b');
  longfunc0();

  POINTERS_EQUAL(fff.call_history[0], (void*)longfunc0);
  POINTERS_EQUAL(fff.call_history[1], (void*)voidfunc2);
  POINTERS_EQUAL(fff.call_history[2], (void*)longfunc0);  
}

TEST(Cpputest_fff, DefaultArgumentHistory)
{
  voidfunc2('g', 'h');
  voidfunc2('i', 'j');


  CHECK_EQUAL('g', voidfunc2_fake.arg0_history[0]);
  CHECK_EQUAL('h', voidfunc2_fake.arg1_history[0]);
  CHECK_EQUAL('i', voidfunc2_fake.arg0_history[1]);
  CHECK_EQUAL('j', voidfunc2_fake.arg1_history[1]);
}


TEST(Cpputest_fff, when_fake_func_called_max_times_plus_one_then_one_argument_history_dropped)
{
    int i;
    for(i = 0; i < 13; i++)
    {
        voidfunc2('1'+i, '2'+i);
    }
    voidfunc2('1', '2');
    LONGS_EQUAL(1u, voidfunc2_fake.arg_histories_dropped);

    printf("\nvoidfunc2_fake.arg_history_len = %d, voidfunc2_fake.call_count = %d\n", 
      voidfunc2_fake.arg_history_len, voidfunc2_fake.call_count);

    CHECK(voidfunc2_fake.arg_history_len < voidfunc2_fake.call_count);
}


TEST(Cpputest_fff, FunctionReturnValueSequences)
{
  long myReturnVals[3] = {3, 7, 9};
  SET_RETURN_SEQ(longfunc0, myReturnVals, 3);

  LONGS_EQUAL(myReturnVals[0], longfunc0());

  LONGS_EQUAL(myReturnVals[1], longfunc0());

  LONGS_EQUAL(myReturnVals[2], longfunc0());
  LONGS_EQUAL(myReturnVals[2], longfunc0());
  LONGS_EQUAL(myReturnVals[2], longfunc0());
}


TEST(Cpputest_fff, CustomReturnValueDelegate)
{
  longfunc0_fake.custom_fake = my_custom_value_fake;
  long retval = longfunc0();
  LONGS_EQUAL(MEANING_OF_LIFE, retval);
}

TEST(Cpputest_fff, CustomReturnValueDelegateSequences)
{
  void (*custom_fake[])(char*) = {voidfunc1outputparam_custom_fake1,
                                  voidfunc1outputparam_custom_fake2,
                                  voidfunc1outputparam_custom_fake3};
  char a = 'a';

  SET_CUSTOM_FAKE_SEQ(voidfunc1outparam, custom_fake, 3);

  voidfunc1outparam(&a);
  CHECK_EQUAL('x', a);
  voidfunc1outparam(&a);
  CHECK_EQUAL('y', a);
  voidfunc1outparam(&a);
  CHECK_EQUAL('z', a);

  voidfunc1outparam(&a);
  CHECK_EQUAL('z', a);
}