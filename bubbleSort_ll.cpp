// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};
typedef struct Node node;

node * create_node(){
    node *newnode = (node *)malloc(sizeof(node));
    cout<<"enter the value of node: ";
    cin>>newnode->val;
    newnode->next = NULL;
    
    return newnode;
}

node * createList(node *head){
    int n;
    cout<<"enter the number of nodes: ";
    cin>>n;
    node *newnode;
    
    for(int i = 0; i<n; i++){
        newnode = create_node();
        if(head == NULL)
            head = newnode;
        else{
            node *ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            
            ptr->next = newnode;
        }
    }
    
    return head;
}

void display(node *head){
    if(head == NULL){
        cout<<"nothing to display"<<endl;
        return;
    }
    
    node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
}

node * bubbleSort(node *head){
    node *ptr = head;
    //cout<<"check 1"<<endl;
    while(ptr->next != NULL){
        node *ptr1 = ptr;
        while(ptr1->next != NULL)
            if(ptr->val > ptr1->val)
                swap(ptr->val, ptr1->val);
    }
    cout<<"check 2"<<endl;
    return head;
}

int main() {
   node *head = NULL;
   head = createList(head);
   cout<<"original: ";
   display(head);
   head = bubbleSort(head);
   cout<<endl<<"sorted: ";
   display(head);
}
