#include "../include/FSM.h"
//#include <iostream>

FSM::FSM(){
    out.dev = 0;
    out.MEET = false;
    out.ETIRPS = false;

    in.dev = 0;
    in.MEET = 0;
    in.ETIRPS = 0;
    state = 0;
    next_state = 0;
};
FSM::~FSM(){};
//input[Nada,M025,M050,M100,DEV, MEET, ETIRPS]
//return soda e dev,

void FSM :: reset_inout(){
    out.ETIRPS = false;
    out.MEET = false;
    out.dev = 0;

    in.ETIRPS = false;
    in.MEET = false;
    in.dev = 0;
}
void FSM :: setOutput(FSM_data newOutput){
    out.ETIRPS = newOutput.ETIRPS;
    out.MEET = newOutput.MEET;
    out.dev = newOutput.dev;
}
FSM_data FSM :: getOutput(){
    return out;
}
FSM_data FSM::run(bool *input,bool reset){
    bool Nada,M025,M050,M0100,DEV, MEET, ETIRPS;


    //Garante memoria para meet etirps e dev assim 
    // não importa a ordem em que são prescionados 
    //acredito que isso é mais fidedigno de como funciona 
    //uma maquina de refrigerantes em um sistema embarcados

    if(reset == true){
        in.dev = false;
        in.ETIRPS = false;
        in.MEET = false;
    }
    else{
        if (input[4] == true){
            in.dev = true;
        }
        else if(input[5] == true){
            in.MEET = true;
        }
        else if(input[6] == true){
            in.ETIRPS = true;
        }
    }
    

    Nada = input[0];
    M025 = input[1];
    M050 = input[2];
    M0100 = input[3];
    DEV = in.dev;
    MEET = in.MEET;
    ETIRPS = in.ETIRPS;
   

    switch(state){
        case 0:

            if (reset == true){
                state = 0;
                next_state = 0;
                reset_inout();
            }
            else{

                if (Nada == true){
                    next_state = state;
                }
                if(M025 == true){
                    next_state = 25;
                }
                if(M050 == true){
                    next_state = 50;
                }
                if(M0100 == true){
                    next_state = 100;
                }
                if(DEV == true){
                    out.ETIRPS = false;
                    out.MEET = false;
                    out.dev = 0;
                    next_state = 0;
                }
                if(MEET == true){
                    out.MEET = false;
                    next_state = 0;
                    out.dev = 0;
                }
                if(ETIRPS == true){
                    out.ETIRPS = false;
                    next_state = 0;
                    out.dev = 0;
                }
            }
            state = next_state;
            break;

        case 25:
            if (reset == true){
                state = 0;
                next_state = 0;
                reset_inout();
            }
            else{

                if (Nada == true){
                    next_state = state;
                }
                if(M025 == true){
                    next_state = 50;
                }
                if(M050 == true){
                    next_state = 75;
                }
                if(M0100 == true){
                    next_state = 125;
                }
                if(DEV == true){
                    out.ETIRPS = false;
                    out.MEET = false;
                    out.dev = 25;
                    next_state = 0;
                }
                if(MEET == true){
                    out.MEET = false;
                    next_state = 0;
                    out.dev = 25;
                }
                if(ETIRPS == true){
                    out.ETIRPS = false;
                    next_state = 0;
                    out.dev = 25;
                }
            }

            state = next_state;
            break;

        case 50:
            if (reset == true){
                state = 0;
                next_state = 0;
                reset_inout();
            }
            else{
                if (Nada == true){
                    next_state = state;
                }
                if(M025 == true){
                    next_state = 75;
                }
                if(M050 == true){
                    next_state = 100;
                }
                if(M0100 == true){
                    next_state = 150;
                }
                if(DEV == true){
                    out.ETIRPS = false;
                    out.MEET = false;
                    out.dev = 50;
                    next_state = 0;
                }
                if(MEET == true){
                    out.MEET = false;
                    next_state = 0;
                    out.dev = 50;
                }
                if(ETIRPS == true){
                    out.ETIRPS = false;
                    next_state = 0;
                    out.dev = 50;
                }
            }
            state = next_state;
            break;

        case 75:
            if (reset == true){
                state = 0;
                next_state = 0;
                reset_inout();
            }
            else{
                if (Nada == true){
                    next_state = state;
                }
                if(M025 == true){
                    next_state = 100;
                }
                if(M050 == true){
                    next_state = 125;
                }
                if(M0100 == true){
                    next_state = 175;
                }
                if(DEV == true){
                    out.ETIRPS = false;
                    out.MEET = false;
                    out.dev = 75;
                    next_state = 0;
                }
                if(MEET == true){
                    out.MEET = false;
                    next_state = 0;
                    out.dev = 75;
                }
                if(ETIRPS == true){
                    out.ETIRPS = false;
                    next_state = 0;
                    out.dev = 75;
                }
            }
            state = next_state;

            break;
        case 100:
            if (reset == true){
                state = 0;
                next_state = 0;
                reset_inout();
            }
            else{
                if (Nada == true){
                    next_state = state;
                }
                if(M025 == true){
                    next_state = 125;
                }
                if(M050 == true){
                    next_state = 150;
                }
                if(M0100 == true){
                    next_state = 150;
                    out.dev = 50;
                }
                if(DEV == true){
                    out.ETIRPS = false;
                    out.MEET = false;
                    out.dev = 100;
                    next_state = 0;
                }
                if(MEET == true){
                    out.MEET = false;
                    next_state = 0;
                    out.dev = 100;
                }
                if(ETIRPS == true){
                    out.ETIRPS = false;
                    next_state = 0;
                    out.dev = 100;
                }
            }

            state = next_state;

            break;

        case 125:
            if (reset == true){
                state = 0;
                next_state = 0;
                reset_inout();
            }
            else{
                if (Nada == true){
                    next_state = state;
                }
                if(M025 == true){
                    next_state = 150;
                }
                if(M050 == true){
                    next_state = 150;
                    out.dev = 25;
                }
                if(M0100 == true){
                    next_state = 150;
                    out.dev = 75;
                }
                if(DEV == true){
                    out.ETIRPS = false;
                    out.MEET = false;
                    out.dev = 125;
                    next_state = 0;
                }
                if(MEET == true){
                    out.MEET = false;
                    next_state = 0;
                    out.dev = 125;
                }
                if(ETIRPS == true){
                    out.ETIRPS = false;
                    next_state = 0;
                    out.dev = 125;
                }
            }
            state = next_state;

            break;

        case 150:

            if (reset == true){
                state = 0;
                next_state = 0;
                reset_inout();
            }
            else{
                if (Nada == true){
                    next_state = state;
                }
                if(M025 == true){
                    next_state = 150;
                    out.dev =25;
                }
                if(M050 == true){
                    next_state = 150;
                    out.dev = 50;
                }
                if(M0100 == true){
                    next_state = 150;
                    out.dev = 100;
                }
                if(DEV == true){
                    out.dev = 150;
                    out.ETIRPS = false;
                    out.MEET = false;
                    next_state = 0;
                }
                if(MEET == true){
                    out.MEET = true;
                    next_state = 0;
                }
                if(ETIRPS == true){
                    out.ETIRPS = true;
                    next_state = 0;
                }
            }

            state = next_state;
            break;

        default :
            state = 0;
            next_state = 0;
    }

    return getOutput();


};
