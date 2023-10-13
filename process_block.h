#include <stdlib.h>
#include <stdio.h>

typedef struct PCB_Struct{
        pcb* next;
        pcb* prev;
        int processID;
        int processPriority;
        int cpuBurstCount;
        int ioBurstCount;
}pcb;

typedef struct PCB_Linked_List{
        pcb* head;
        pcb* tail;
}pcb_ll;

void enqueue(pcb add); //used to insert pcb into linked list
int equals(pcb first, pcb second); //used to check if a pcb is equal to another pcb
pcb* dequeueTarget(pcb_ll *list, pcb *rem); //used to remove target pcb from linked list, if equals(pcb target, pcb rem) dequeue process
pcb* dequeue(pcb_ll *list);
