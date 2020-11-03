#ifndef _BUTTON_H_
#define _BUTTON_H_

void button_init(void);

void button_pressed(bool button_status, int *button_state);

bool is_button_pressed(int *button_state);
#endif 
