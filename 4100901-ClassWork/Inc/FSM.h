#ifndef FSM_H
#define FSM_H

#include <stdint.h>

extern volatile uint8_t button_pressed;

void fsm_init(void);
void run_fsm(void);

#endif // FSM_H

