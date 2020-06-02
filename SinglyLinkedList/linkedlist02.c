#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node** head_ref, int position){
    //linked listが空なら何もしない
    if(*head_ref == NULL) return;

    //head nodeを保管する
    struct Node* temp = *head_ref;

    //headが指定されたら
    if(position == 0){
        *head_ref = temp -> next;
        free(temp);
        return;
    }

    //削除するnodeの前のノードを探す
    for(int i = 0; temp != NULL && i < position - 1; i++){
        temp = temp -> next;
    }
    //指定位置がposition以上であったら何もしない
    if(temp == NULL || temp -> next == NULL){
        return;
    }

    struct Node* next  = temp ->next->next;
    free(temp -> next);
    temp -> next = next;
}

void printList(struct Node *node){
    while(node != NULL){
        printf("%d | %p\n",node -> data , &(*node));
        node = node->next;
    }
}

int main(){
    struct Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    puts("Created Linked List ");
    printList(head);
    deleteNode(&head, 4);

    puts("\n Linked List after Deletion as position 4");
    printList(head);
    return 0;
}