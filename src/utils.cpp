#include"../include/utils.h"

void delay(double seconds) {
    // Captura o tempo atual
    clock_t start_time = clock();

    // Calcula o número de ticks que correspondem ao tempo em segundos
    clock_t wait_time = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);

    // Loop até que o tempo de espera tenha passado
    while (clock() < start_time + wait_time);
}