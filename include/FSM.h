#ifndef FSM_H
#define FSM_H
#include "data_types.h"

class FSM
{   unsigned char state;
    unsigned char next_state;
    int dev;
    int soda;
    public:
        FSM();
        virtual ~FSM();
        outFSM out;
        //void change_state(int input);
        //int see_state();
        void run(bool *input,bool reset);
};

#endif // FSM_H
