#ifndef IO_H
#define IO_H
#include"data_types.h"

class io{
    public:
    //virtual void data_hora() const = 0;
    virtual machine_input process_input(machine_input input) = 0;
    //virtual bool* process_output(bool* output) = 0;

    virtual ~io() {}
};

#endif // IO_H