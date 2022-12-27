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

// fake function
void DISPLAY_init();
void DISPLAY_output(char* message);

#endif  /* D_FakeCpputest_fff_H */
