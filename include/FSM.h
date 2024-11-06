#ifndef FSM_H
#define FSM_H
#include "Data_types.h"
#include <iostream>
using namespace std;

class FSM
{   unsigned char state;
    unsigned char next_state;
    FSM_data out;
    FSM_data in;

    public:
        FSM();
        virtual ~FSM();
        //void change_state(int input);
        //int see_state();
        FSM_data run(bool *input, bool reset);
        void setOutput(FSM_data newOutput);
        void reset_inout();
        FSM_data getOutput();
};

#endif // FSM_H
