#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <pthread.h>
#include <time.h>
//#include "fileRead.h"
//#include "ioSystem.h"
//#include "cpuScheduler.h"
#include "process_block.h"
#define FIFO_PARAM "FIFO\0"
#define RR_PARAM "RR\0"
#define PR_PARAM "PR\0"
#define SJF_PARAM "SJF\0"
#define SUCCESS_FLAG 0
#define FAIL_FLAG 1
#define VALID_PARAM_COUNT_1 5
#define VALID_PARAM_COUNT_2 7
#define ALG_FLAG "-alg\0"
#define INPUT_FLAG "-input\0"
#define QUANT_FLAG "-quantum\0"
#define HELP_FLAG "-help\0"

typedef struct RUNTIME_METRICS{
        int processTime;
}metrics;

enum algorithm{
        fifo = 0,
        sjf,
        pr,
        rr
};

char* parseParams(int argc, char** argv);
void printHelp();
void* fileReadThread(void* arg);
void* cpuSchedulerThread(void* arg);
void* ioSystemThread(void* arg);