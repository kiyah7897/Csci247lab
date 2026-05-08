#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "jagged.h"

// Initialize a jagged array object with the given number of bins.
// The array is initially unpacked.
void jagged_init(jagged_t* jagged, int bins) {
    jagged->size = 0;
    jagged->number_of_bins = bins;
    jagged->bins = malloc(bins *sizeof(entry_t*))
    for (int i = 0; i < jagged->number_of_bins;i++){
        jagged->bins[i] = NULL;
    }
    jagged->packed_values = NULL;
    jagged->offsets = NULL;
}

void jagged_free(jagged_t* jagged) {
    for (int i = 0; i < jagged->number_of_bins; i++){
        entry_t* current = jagged->bins[i];
        while(current != NULL){
        free(current);
        current = next;
        }
    }
    free(jagged->bins);
    if(jagged->packed_values != NULL){
        free(jagged->packed_values);
    }if (jagged->offsets != NULL){
        free(jagged->offsets);
    }
}

// Return the number of elements in the jagged array
int jagged_size(jagged_t* jagged) {
    return jagged->size;
}

// Return the number of bins
int jagged_bins(jagged_t* jagged) {
    return jagged->number_of_bins;
}

// Return the number of slots in the given bin
int jagged_slots(jagged_t* jagged, int bin) {
    entry_t* current = jagged->bins[bin];
    int count = 0;
    while(current != NULL){
    count++;
    current = current->next;  
    }
    return count;
}

// Return the element stored at the given bin and slot number.
// Success is set to 0 if the element was found, or -1 otherwise.
// If success is -1, 0 is returned.
int jagged_element(jagged_t* jagged, int bin, int slot, int* success) {
    
    return -1;
}

// Add an element to the bin. Return 0 is the element was
// added, or -1 if the representation is packed
int jagged_add(jagged_t* jagged, int bin, int element) {
    if (jagged->packed_values != NULL){
        return -1;
    }
    entry_t* newNode = malloc(sizeof(entry_t));
    newNode->value = element;
    newNode->next = NULL;

    entry_t* current = jagged->bins[bin];
    if(jagged->bins[bin] == NULL){
      jagged->bins[bin] = newNode;

    }else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    jagged->size++;

    return 0;
}

// Remove the element from the given bin and slot. Return 0 on success,
// or -1 if the representation was packed or element not found.
int jagged_remove(jagged_t* jagged, int bin, int slot) {
    if (jagged->packed_values != NULL){
        return -1;
    }
    if (slot == 0){
        entry_t* currentHead = jagged->bins[bin];
        jagged->bins[bin] = currentHead->next;
        free(currentHead)
        jagged->size --;
    }else{
        int i = 0;
        entry_t* current = jagges->bins[bin];
        while (i < slot -1){
            current = current->next; 
            i++;
        }
            entry_t* remove = current->next;
            current->next = current->next->next;
            free(remove);
    }
    jagged->size--;
    return 0;
}

// Unpack the jagged array. Return 0 if successful or -1 if the array is
// already unpacked.
int jagged_unpack(jagged_t* jagged) {
    return -1;
}

// Pack the jagged array. Return 0 if successful or -1 if the array is already
// packed.
int jagged_pack(jagged_t* jagged) {
    return -1;
}

// Print a jagged array out. Useful for debugging
void jagged_print(jagged_t* jagged) {
}
