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


//void DISPLAY_init();
//void DISPLAY_output(char* message);
