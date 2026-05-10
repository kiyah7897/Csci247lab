#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
     struct node* next;
     struct node* previous;
};

typedef struct node node;

node* make_node(int value, node* next, node* previous);
void add_back(node** list, int value);
void print_list(node* list, int backwards);
void remove_node(node** list, int value);


int main(int argc, char** argv) {
     node* list = NULL;        // initially the tree is NULL

    add_back(&list, 42);
    add_back(&list, 13);
    add_back(&list, 50);
    add_back(&list, 15);
    add_back(&list, 2);
    print_list(list, 0);                // 42, 13, 50, 15, 2
    print_list(list, 1);   

    remove_node(&list, 15);   
    remove_node(&list, 13);   
    remove_node(&list, 42);         
    print_list(list, 0);                // 50,2 
    
    remove_node(&list, 50);
    remove_node(&list, 2);
}
 


node* make_node(int value, node* next, node* previous){
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = next;
    newNode->previous = previous;
    
    return newNode;
}
void add_back(node** list, int value){
    if(*list == NULL){
        *list = make_node(value,NULL,NULL);
        return;
    }else{
        node* current = *list;
        while(current->next != NULL){
            current = current->next;
        }
        node* newNode = make_node(value,NULL,current);
        current->next = newNode;
    }

}
void print_list(node* list, int backwards){
    node* current = list;
    if (backwards == 0){
        while(current != NULL){
        printf("%d ",current->value);
        current = current->next;
        }
    }else{
        while(current->next != NULL){
            current = current->next;
        }

        while(current != NULL){
        printf("%d ",current->value);
        current = current->previous;
        }
    }
}
void remove_node(node** list, int value){
    node* current = *list;
    while(current != NULL && current->value != value){
        current = current->next;
    }
    if(current == NULL){
        return;
    }else if(current->previous == NULL && current->next == NULL){
        *list  = NULL;
        free(current);
        return;
    }else if(current->previous == NULL){
        current->next->previous = NULL;
        *list = current->next;
        free(current);
        return; 
    }else if(current->next == NULL){
        current->previous->next = NULL;
        free(current);
        return;
    }else{
        current->previous->next = current->next;
        current->next->previous = current->previous;
        free(current);
        return;
    }
}
