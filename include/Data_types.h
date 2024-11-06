#ifndef DATA_TYPES_H
#define DATA_TYPES_H

struct FSM_data
{
    int dev;
    bool ETIRPS;
    bool MEET;
};

struct machine_input{
    bool fsm_in[7];
    bool log;
    bool ok;
    bool exit;
};
struct log_data{
    //compra
    int dev;
    bool ETIRPS;
    bool MEET;
    //data_hora
    int dia,mes,ano,h,m,s;
};

struct date{
    int dia,mes,ano,h,m,s;
};

#endif  //DATA_TYPES_H