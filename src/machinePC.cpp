#include "../include/machinePC.h"



machinePC::machinePC(){
    int i;

    for(i=0;i<=6;i++){
        machine_in.fsm_in[i]=false;
    };
    machine_in.ok = false;
    machine_in.exit = false;

    machine_out.dev = 0;
    machine_out.MEET = false;
    machine_out.ETIRPS = false;
 };

machinePC::~machinePC(){};

machine_input machinePC :: process_input(machine_input input){
    /* 
        input[0] = Nada; input[1] = M025; input[2] = M050; input[3] =M100;
         input[4] = DEV; input[5] =MEET; input[6] =ETIRPS; input[8] = exit;
        */
    int num,dinheiro,i;
    string str,in,check_dev,check_E_or_M ="";
    bool Nada,M025,M050,M100,DEV, MEET, ETIRPS;
    
    Nada = M025 = M050 = M100 = false;
    DEV = MEET = ETIRPS = false;

    cout <<"Entre com um input via teclado!"<<endl;
        getline(cin, in);
        stringstream ss(in);
       
        if (ss >> num) {
            // O input é um número
            dinheiro = num;

            // Verifica a quantidade de dinheiro
            if (dinheiro == 0) {
                input.fsm_in[0] = true;
            } else if (dinheiro == 25) {
                input.fsm_in[1] = true;
            } else if (dinheiro == 50) {
                input.fsm_in[2] = true;
            } else if (dinheiro == 100) {
                input.fsm_in[3] = true;
            } else {
                cout << "Valor invalido de dinheiro! Use 0, 25, 50 ou 100." << endl;
            }
        }

        else{
            // O input não é um número, então deve ser uma string (um comando)
            ss.clear();
            ss.str(in);  // Reseta o stringstream
            ss >> str;   // Agora lê como string 

            check_dev = str;
            check_E_or_M = str;
            
             if (str == "ok") {
                input.ok = true;
                cout << "Finalizando operacao..." << endl;
                
            } else if (str == "exit"){
                input.exit = true;
            }else if (str == "dev") {
                input.fsm_in[4] = true;
            } else if (str == "meet") {
                input.fsm_in[5] = true;
            } else if (str == "etirps") {
                input.fsm_in[6] = true;
            } else {
                cout << "Comando invalido! Use 'dev', 'meet', 'etirps' ou 'ok'." << endl;
            }
        }
        
    return input;

}

void machinePC :: run(){

    FSM fsm;
    outFSM out;
    int i;
    int dinheiro = 0;
    bool reset = false;
    
    while(1){

        while(machine_in.ok == false){

        machine_in = process_input(machine_in);
        

        fsm.run(machine_in.fsm_in, reset);

        for (i=0; i<=6 ; i++){
            machine_in.fsm_in[i] = false; 
        };
    }
     printf("dev: %d, meet: %d, stierps:%d", fsm.out.dev,fsm.out.MEET, fsm.out.ETIRPS);

     

    }

};