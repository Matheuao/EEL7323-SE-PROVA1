#ifndef MACHINEPC_H
#define MACHINEPC_H
#include <iostream>
#include <sstream>
#include "io.h"
#include "FSM.h"
#include "data_types.h"
using namespace std;



class machinePC : public io{
    machine_input machine_in;
    outFSM machine_out;

    public:
        //erda a classe imput e output
        machinePC();
        virtual ~machinePC();
        
        //void data_hora() const override;
        machine_input process_input(machine_input input) override;
        void run();

};

#endif // MACHINEPC_H