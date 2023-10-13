#include "process_block.h"

void enqueue(pcb_ll* list, pcb* add){
        if(list->head == NULL){
                list->head = add;
                list->head->prev = NULL;
                list->head->next = NULL;
        }
        else if(list->tail == NULL){
                list->head->next = add;
                add->prev = list->head;
                add->next = NULL;
                list->tail = add;
        }
        else{
                add->next = NULL;
                add->prev = list->tail;
                list->tail->next = add;
                list->tail = add;
        }
} //used to insert pcb into linked list

int equals(pcb first, pcb second){
        if(first.processID == second.processID){
                return 1;
        }
        return 0;
} //used to check if a pcb is equal to another pcb

pcb* dequeueTarget(pcb_ll *list, pcb *rem){
        pcb *temp;
        temp = list->head;
        
        while(temp != NULL){
                if(equals(*rem, *(list->head))){
                        list->head = NULL;
                        return temp;
                }
                else if(temp->next == NULL){
                        temp->prev->next = NULL;
                        list->tail = NULL;
                        return temp;
                }
                else if(equals(*rem, *temp)){
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                }
                temp = temp->next;
        }
        return temp;
} //used to remove target pcb from linked list, if equals(pcb target, pcb rem) dequeue process

pcb* dequeue(pcb_ll *list){
        pcb* temp;
        if(list->head == NULL){
                fprintf(stderr, "Attempting to remove item from empty list\n");
                return NULL;
        }
        temp = list->head;
        if(temp->next == NULL){
                list->head = NULL;
                return temp;
        }
        list->head = list->head->next;
        return temp;
}