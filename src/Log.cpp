#include "../include/Log.h"

Log::Log(){};
Log::~Log(){};


void Log::addLog(log_data data) {
    logQueue.enqueue(data);  // Adiciona o dado à fila de logs
    //std::cout << "Novo log adicionado." << std::endl;
}


void Log::showLogs() {
    std::cout << "Exibindo todos os logs:\n";
    logQueue.display();  // Chama a função display da fila para exibir os logs
}



