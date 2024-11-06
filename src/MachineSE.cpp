#include "../include/machineSE.h"
#include <iostream>

volatile unsigned int *data = (volatile unsigned int *)0x80000a00; // Endereço dos botões e switches
volatile unsigned int *output = (volatile unsigned int *)0x80000a04; // Endereço dos LEDs
volatile unsigned int *direction = (volatile unsigned int *)0x80000a08; // Endereço de direção

// Limite de contagem para debouncing (ajustar conforme necessário)
const int debounce_limit = 10;  

machineSE::machineSE() {
    for (int i = 0; i <= 6; i++) {
        machine_in.fsm_in[i] = false;
    }
    machine_in.ok = false;
    machine_in.exit = false;

    machine_out.dev = 0;
    machine_out.MEET = false;
    machine_out.ETIRPS = false;

    *direction = 0xffffffff; // Configura todos os pinos como saída

    last_gpio_val = 0;
}

machineSE::~machineSE() {}

machine_input machineSE::process_input(machine_input input) {

    unsigned int current_val = *data;
    int debounce_counter = 0;

    // Se o valor atual de `data` for igual ao último valor lido, incrementa o contador de debounce
    if (current_val == last_gpio_val) {
        debounce_counter++;
    } else {
        debounce_counter = 0;  // Reseta o contador se o valor mudou
    }

     last_gpio_val = current_val; 

    // Somente processa a entrada se o contador de debounce ultrapassar o limite

    if (debounce_counter > debounce_limit) {
        last_gpio_val = current_val; 

        // Define valores monetários com base nos switches
        if (current_val & 0x000)       // não há nada sendo selecionado
            input.fsm_in[0] = true;
        else if (current_val & 0x200)  // SW1: Valor 25
            input.fsm_in[1] = true;
        else if (current_val & 0x400)  // SW2: Valor 50
            input.fsm_in[2] = true;
        else if (current_val & 0x800)  // SW3: Valor 100
            input.fsm_in[3] = true;
        else
            input.fsm_in[0] = true;    // Default: nenhum valor

        // Define comandos com base nos botões
        if (current_val & 0x100000) // Botão central: "ok"
            input.ok = true;
        if (current_val & 0x20000)  // Botão esquerdo: "dev"
            input.fsm_in[4] = true;
        if (current_val & 0x10000)  // Botão superior: "meet"
            input.fsm_in[5] = true;
        if (current_val & 0x40000)  // Botão inferior: "etirps"
            input.fsm_in[6] = true;
        if (current_val & 0x80000)  // Botão direito: "exit"
            input.exit = true;
    }

    return input;
}

void machineSE::process_output(FSM_data output) {
    unsigned int led_output = 0;

    if (output.dev)
        led_output |= 0x01;    // LD0 aceso se dev ativo
    if (output.MEET)
        led_output |= 0x02;    // LD1 aceso se MEET ativo
    if (output.ETIRPS)
        led_output |= 0x04;    // LD2 aceso se ETIRPS ativo

    //*output = led_output;      // Atualiza LEDs conforme o estado

    //std::cout << "LEDs set to: 0x" << std::hex << led_output << std::endl;
}



date machineSE :: data_hora(){
   // supondo que a biblioteca time.h vá funcionar no sistema embarcado
   // algo que é razoavel dado que há exemplos disso no site do professor

    int counter = 0;
    clock_t lastIncrement = 0;

    clock_t inicio, fim;
    inicio = clock();
    int n = 999;

    // Temporização fictícia
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j);
    }
    fim = clock();
    int segundos = (fim - inicio) / CLOCKS_PER_SEC;

    // Obtém o horário atual
    time_t timer;
    time(&timer);
    struct tm* timeinfo = localtime(&timer);

    date ret_date;
    ret_date.dia = timeinfo->tm_mday;
    ret_date.mes = timeinfo->tm_mon + 1;   // Ajuste porque tm_mon varia de 0 a 11
    ret_date.ano = timeinfo->tm_year + 1900;  // Ajuste porque tm_year é o número de anos desde 1900
    ret_date.h = timeinfo->tm_hour;
    ret_date.m = timeinfo->tm_min;
    ret_date.s = timeinfo->tm_sec;

    // escrever esses dados no oled
    
    /* teste da lógica usando iostream
    cout << Data: " << data.dia << "/" 
            << data.mes << "/" << data.ano << " " 
            << data.h << ":" << data.m << ":" << data.s << endl;
    
    */


    return ret_date;
}

//void whrite_log()

void machineSE :: run(){

    FSM fsm;
    Log log_system;

    FSM_data out_fsm;
    date date_log;
    log_data log;
    int i;

    while(1){

        while(machine_in.ok == false){
            date_log = data_hora();

            for (i=0; i<=6; i++){
                machine_in.fsm_in[i] = false;
            };

            machine_in = process_input(machine_in);


            if (machine_in.ok == false){
                out_fsm = fsm.run(machine_in.fsm_in, false);
            }
        }
    //write output
    process_output(out_fsm);
    
    //write log
    log.ano = date_log.ano;
    log.mes = date_log.mes;
    log.dia = date_log.dia;
    log.h = date_log.h;
    log.m = date_log.m;
    log.s = date_log.s;

    log.dev = out_fsm.dev;
    log.MEET = out_fsm.MEET;
    log.ETIRPS = out_fsm.ETIRPS;

    log_system.addLog(log);

    fsm.run(machine_in.fsm_in, true); // reseta a fsm para um proximo usuario;
    machine_in.ok = false;

    }
}
