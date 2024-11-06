#include "../include/MachinePC.h"

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
                delay(3);
                system("cls");
                //system(clear); //linux
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

            }else if (str == "exit"){
                input.exit = true;
            }else if (str == "" || str == " "){
                input.fsm_in[0] = true;
            }else if (str == "dev") {
                input.fsm_in[4] = true;
            } else if (str == "meet") {
                input.fsm_in[5] = true;
            } else if (str == "etirps") {
                input.fsm_in[6] = true;
            } else if (str == "log") {
                input.log = true;
            } else {
                cout << "Comando invalido! Use 'dev', 'meet', 'etirps' ou 'ok'." << endl;
                delay(3);
                system("cls");
                //system("clear"); linux
            }
        }

    return input;

}


void machinePC :: process_output(FSM_data output){

    printf("dev: %d, meet: %d, stierps:%d\n", output.dev , output.MEET, output.ETIRPS);

    delay(3); //bom delay

    //system("clear");

}


date machinePC :: data_hora(){

    clock_t inicio, fim;
    inicio = clock();
    int n = 999;

    // Temporização fictícia
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j);
    }
    fim = clock();
    int segundos = (fim - inicio) / CLOCKS_PER_SEC;

    // Obtém o horário atual
    time_t timer;
    time(&timer);
    struct tm* timeinfo = localtime(&timer);

    // Formata a data e hora como "DD/MM/YYYY HH:MM:SS"
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", timeinfo);
    std::cout << buffer << std::endl;


    date ret_date;
    ret_date.dia = timeinfo->tm_mday;
    ret_date.mes = timeinfo->tm_mon + 1;   // Ajuste porque tm_mon varia de 0 a 11
    ret_date.ano = timeinfo->tm_year + 1900;  // Ajuste porque tm_year é o número de anos desde 1900
    ret_date.h = timeinfo->tm_hour;
    ret_date.m = timeinfo->tm_min;
    ret_date.s = timeinfo->tm_sec;

    return ret_date;
}

//void whrite_log()

void machinePC :: run(){

    FSM fsm;
    Log log_system;

    FSM_data out_fsm;
    date date_log;
    log_data log;
    int i;

    while(1){

        while(machine_in.ok == false){

            system("cls"); //system("clear"); linux
            date_log = data_hora();

            for (i=0; i<=6; i++){
                machine_in.fsm_in[i] = false;
            };

            machine_in = process_input(machine_in);


            if (machine_in.ok == false){
                out_fsm = fsm.run(machine_in.fsm_in, false);
            }
            if(machine_in.log == true){
                log_system.showLogs();
                delay(15);
            }
        }
    //write output
    process_output(out_fsm);
    
    //write log
    log.ano = date_log.ano;
    log.mes = date_log.mes;
    log.dia = date_log.dia;
    log.h = date_log.h;
    log.m = date_log.m;
    log.s = date_log.s;

    log.dev = out_fsm.dev;
    log.MEET = out_fsm.MEET;
    log.ETIRPS = out_fsm.ETIRPS;

    log_system.addLog(log);

    fsm.run(machine_in.fsm_in, true); // reseta a fsm para um proximo usuario;
    machine_in.ok = false;

    }
}
