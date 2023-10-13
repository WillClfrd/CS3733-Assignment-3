#include "assign3.h"

static enum algorithm algo;
static int quantum;
static metrics run_metrics;
static pcb_ll ready_queue;
static pcb_ll io_queue;

int main(int argc, char* argv[]){
        FILE* inFile;
        char* filename;

        filename = parseParams(argc, argv);
        
        if(filename == NULL){
                return FAIL_FLAG;
        }

        inFile = fopen(filename, "r");
        
        switch(algo){
                case fifo:
                        printf("\nFIRST IN FIRST OUT\nFile Name: %s\n\n", filename);
                        break;
                case sjf:
                        printf("\nSHORTEST JOB FIRST\nFile Name: %s\n\n", filename);
                        break;
                case pr:
                        printf("\nPRIORITY\nFile Name: %s\n\n", filename);
                        break;
                case rr:
                        printf("\nROUND ROBIN\nQuantum: %d\nFile Name: %s\n\n", quantum, filename);
                        break;
                default:
                        printf("Algo not assigned correctly\n");
                        break;
        }

        //pthread_t tids[3];

        //pthread_create(&tids[0], NULL, fileReadThread, NULL);
        //pthread_create(&tids[1], NULL, cpuSchedulerThread, NULL);
        //pthread_create(&tids[2], NULL, ioSystemThread, NULL);

        fclose(inFile);
        printf("Finished\n");
        return SUCCESS_FLAG;
}

char* parseParams(int argc, char** argv){
        if(argc == 1){
                fprintf(stderr, "No parameters detected at command line\n");
                printHelp();
                return NULL;
        }

        if(argc == 2 && strcmp(argv[1], HELP_FLAG) == 0){
                printHelp();
                return NULL;
        }
        else if(argc != VALID_PARAM_COUNT_1 && argc != VALID_PARAM_COUNT_2){
                fprintf(stderr, "Invalid number of command line parameters detected\n");
                printHelp();
                return NULL;
        }

        if(strcmp(argv[1], ALG_FLAG) == 0){
                if(strcmp(argv[2], FIFO_PARAM) == 0){
                        algo = fifo;
                }
                else if(strcmp(argv[2], SJF_PARAM) == 0){
                        algo = sjf;
                }
                else if(strcmp(argv[2], PR_PARAM) == 0){
                        algo = pr;
                }
                else if(strcmp(argv[2], RR_PARAM) == 0){
                        algo = rr;
                }
                else{
                        fprintf(stderr, "Invalid algorithm provided\n");
                        printHelp();
                        return NULL;
                }
        }
        else{
                fprintf(stderr, "Invalid command line input at parameter 1\n");
                return NULL;
        }

        if(strcmp(argv[3], INPUT_FLAG) == 0){
                quantum = 0;
                return argv[4];
        }
        else if(strcmp(argv[3], QUANT_FLAG) == 0){
                quantum = atoi(argv[4]);
                if(quantum == 0){
                        fprintf(stderr, "Unable to parse quantum time from command line\n");
                        return NULL;
                }
        }
        else{
                fprintf(stderr, "Invalid command line input at parameter 3\n");
                return NULL;
        }
        if(argc == VALID_PARAM_COUNT_2 && strcmp(argv[5], INPUT_FLAG) == 0){
                return argv[6];
        }

        fprintf(stderr, "Unexpected or invalid command line input detected\n");
        printHelp();
        return NULL;
}

void printHelp(){
        printf("Valid command line input formats are:\n\t-alg [FIFO|SJF|PR] -input [filename]\n\t-alg [RR] -quantum [quantum time] -input [filename]\n");
}

void* fileReadThread(void* arg){
        //read input file
        //create process structure
        //puts created process struct in ready queue
        return NULL;
}

void* cpuSchedulerThread(void* arg){
        //check for processes in ready queue
        //pick process struct from queue according to algorithm
        //holds cpu resource for given cpu burst time, or quantum time if rr
        //sleep for time where cpu is occupied
        //release cpu resource and send process to IO queue, or ready queue if rr is algorithm, or terminate if last cpu burst was processed
        return NULL;
}

void* ioSystemThread(void* arg){
        //check IO queue
        //if a process is in IO queue, pick the process and sleep for specified read/write time
        //after sleeping, put process back in read queue
        return NULL;
}