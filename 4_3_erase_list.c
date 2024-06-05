/*
*non-recursive version of the list space free function erase_list(list item *head).
*
*/

#include <stdlib.h>

int main(){
typedef struct list_item {
    int data;   
    struct list_item* next;
} list_item;
void erase_list(list_item *head) {
    list_item *current = head; 
    list_item *next_node;    

    while (current != NULL) {
        next_node = current->next; 
        free(current);            
        current = next_node;   
    }
    head = NULL;
}
}
