#ifndef IO_H
#define IO_H
#include"Data_types.h"

class io{
    public:
    virtual date data_hora() = 0;
    virtual machine_input process_input(machine_input input) = 0;
    virtual void process_output(FSM_data output) = 0;

    virtual ~io() {}
};

#endif // IO_H