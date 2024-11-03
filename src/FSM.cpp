#include "../include/FSM.h"
//#include <iostream>

FSM::FSM(){
    out.dev = 0;
    out.MEET = false;
    out.ETIRPS = false;
    state = 0;
    next_state = 0; 
};
FSM::~FSM(){};
//input[Nada,M025,M050,M100,DEV, MEET, ETIRPS]
//return soda e dev
void FSM::run(bool *input,bool reset){
    bool Nada,M025,M050,M0100,DEV, MEET, ETIRPS;
    
    //using char state;

    Nada = input[0];
    M025 = input[1];
    M050 = input[2];
    M0100 = input[3];
    DEV = input[4];
    MEET = input[5];
    ETIRPS = input[6];

    switch(state){
        case 0: 
            out.dev = 0;
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

            if(reset == false){
                state = next_state;
            }
            else {
                state = 0;
            }

        case 25:
            out.dev = 0;
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

            if(reset == false){
                state = next_state;
            }
            else {
                state = 0;
            }

        case 50:
            out.dev = 0;
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

            if(reset == false){
                state = next_state;
            }
            else {
                state = 0;
            }

        case 75:
            out.dev = 0;
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

           if(reset == false){
                state = next_state;
            }
            else {
                state = 0;
            }
        case 100:
            out.dev = 0;
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

            if(reset == false){
                state = next_state;
            }
            else {
                state = 0;
            }

        case 125:
            out.dev = 0;
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

            if(reset == false){
                state = next_state;
            }
            else {
                state = 0;
            }

        case 150:
            out.dev = 0;
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

            if(reset == false){
                state = next_state;
            }
            else {
                state = 0;
            }

        default : state = 0;
    }

    
};