#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* CreateLinkList(Node* head, int* a, int n){
    // create linklist with an array
    int i;
    Node* p = head;
    for(i=0;i<n;i++){
       Node* cur = (Node*)malloc(sizeof(Node));
       cur->data = a[i];
       cur->next = NULL;
       p->next = cur;
       p = cur;
    }
    return head;
}

Node* ReverseLinkList(Node* head){
    if(head->next == NULL || head->next->next == NULL){
        return head;
    }

    Node* cur = head;
    Node* p = head->next;
    Node* q = p->next;
    while(q != NULL){
        p->next = q->next;
        q->next = cur->next;
        cur->next = q;
        q = p->next;
    }
    return head;

}

void PrintLinkList(Node* head){
    if(head->next == NULL){
        printf("empty linklist.\n");
    }
    else{
        Node* p = head->next;
        while(p != NULL){
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    // create a head point with a empty node
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;
    // create a linklist
    head = CreateLinkList(head, arr, 5);
    PrintLinkList(head);
    // reverse a linklist
    head =  ReverseLinkList(head);
    PrintLinkList(head);
    return 0;
}
