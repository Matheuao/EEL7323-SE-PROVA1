#ifndef LOG_H
#define LOG_H

#include"../include/Queue.h"
#include<iostream>

class Log{   
    Queue logQueue;
    public:
        Log();
        virtual ~Log();

        void addLog(log_data data);
        void showLogs();
};

#endif // LOG_h