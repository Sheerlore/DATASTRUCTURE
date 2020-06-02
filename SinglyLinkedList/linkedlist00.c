#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node* n);
//listの先頭に追加する
void push(struct Node** head_ref, int new_data);
//prev_nodeを得て、new_nodeをprev_nodeの後ろに挿入する関数
void insertAfter(struct Node* prev_node, int new_data);
//linkedlistの最後にnodeを追加する
void append(struct Node** head_ref, int new_data);

int main(){
    struct Node* head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    printf("\n Created Linked list is: ");
    printList(head);

    return 0;
}


void printList(struct Node* n){
    while(n != NULL){
        printf(" %d ", n -> data);
        n = n -> next;
    }
}
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
    if(prev_node == NULL){
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = prev_node -> next;
    prev_node -> next = new_node;
}
void append(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last -> next != NULL){
        last = last-> next;
    }
    last->next = new_node;
    return;
}