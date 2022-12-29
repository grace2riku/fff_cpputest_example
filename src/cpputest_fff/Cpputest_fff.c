#include "Cpputest_fff.h"

void Cpputest_fff_Create(void)
{
}

void Cpputest_fff_Destroy(void)
{
}

void UI_init() {
    DISPLAY_init();
}

void UI_write_line(char* message){
    DISPLAY_output(message);
}

unsigned int Test_DISPLAY_get_line_capacity() {
    return DISPLAY_get_line_capacity();
}

unsigned int Test_DISPLAY_get_line_insert_index() {
    return DISPLAY_get_line_insert_index();
}

long my_custom_value_fake(void) {
    return MEANING_OF_LIFE;
}

void voidfunc1outputparam_custom_fake1(char* a){
    *a = 'x';
}

void voidfunc1outputparam_custom_fake2(char* a){
    *a = 'y';
}

void voidfunc1outputparam_custom_fake3(char* a){
    *a = 'z';
}
