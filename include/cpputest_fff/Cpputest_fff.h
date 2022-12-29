#ifndef D_Cpputest_fff_H
#define D_Cpputest_fff_H

/**********************************************************
 *
 * Cpputest_fff is responsible for ...
 *
 **********************************************************/

void Cpputest_fff_Create(void);
void Cpputest_fff_Destroy(void);

void UI_init();
void UI_write_line(char* message);
unsigned int Test_DISPLAY_get_line_capacity();
unsigned int Test_DISPLAY_get_line_insert_index();

#define MEANING_OF_LIFE 42
long my_custom_value_fake(void);

// fake function
void DISPLAY_init();
void DISPLAY_output(char* message);
unsigned int DISPLAY_get_line_capacity();
unsigned int DISPLAY_get_line_insert_index();

void voidfunc1outputparam_custom_fake1(char* a);
void voidfunc1outputparam_custom_fake2(char* a);
void voidfunc1outputparam_custom_fake3(char* a);


#endif  /* D_FakeCpputest_fff_H */
