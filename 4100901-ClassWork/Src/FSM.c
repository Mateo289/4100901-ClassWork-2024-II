#include "FSM.h"
#include "systick.h"
#include "GPIO.h"

volatile uint8_t button_pressed = 0; // Flag to indicate button press

void fsm_init(void)
{
    configure_systick_and_start();
    configure_gpio();
}

void run_fsm(void)
{
    uint8_t state = 0; // State of the FSM

    while (1) {
        switch (state) {
        case 0: // idle
            if (button_pressed != 0) { // If button is pressed
                state = 1;
            } else if (systick_GetTick() >= 500) { // Blink LED every 500 ms
                state = 2;
            }
            break;
        case 1: // button pressed
        {
            uint32_t button_is_released = is_button_released();
            if (button_is_released) { // If button is released
                button_pressed = 0; // Clear button pressed flag
                systick_reset(); // Reset counter
                state = 0;
            }
        }
            break;
        case 2: // led toggle
            toggle_led(); // Toggle LED
            systick_reset(); // Reset counter
            state = 0;
            break;
        default:
            break;
        }
    }
}
