#ifndef MACHINEPC_H
#define MACHINEPC_H
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include "Io.h"
#include "FSM.h"
#include "Data_types.h"
#include "Log.h"
#include "utils.h"
using namespace std;



class machinePC : public io{
    machine_input machine_in;
    FSM_data machine_out;

    public:
        //erda a classe imput e output
        machinePC();
        virtual ~machinePC();
        
        //void data_hora() const override;
        machine_input process_input(machine_input input) override;
        void process_output(FSM_data output) override;
        date data_hora() override;
        void run();

};

#endif // MACHINEPC_H