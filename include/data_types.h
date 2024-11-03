#ifndef DATA_TYPES_H
#define DATA_TYPES_H

struct outFSM
{
    int dev;
    bool ETIRPS;
    bool MEET;
};

struct machine_input{
    bool fsm_in[7];
    bool ok;
    bool exit;
};

#endif  //DATA_TYPES_H