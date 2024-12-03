#include "FSM.h"

int main(void)
{
    fsm_init();  // Inicializa el SysTick, GPIO y otros recursos necesarios.
    run_fsm();   // Corre la máquina de estados.
    
    return 0; // Aunque nunca se llegará aquí, el return es necesario para evitar advertencias.
}
