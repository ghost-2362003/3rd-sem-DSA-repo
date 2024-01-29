#include <iostream>
#include <stdlib.h>
using namespace std; 

struct Node { 
	int coeff; 
	int expo; 
	struct Node* next; 
}; 
typedef struct Node node;

node * create(node *start){
    int n, i, a, b;
    node *temp, *ptr;
    
    cout<<"enter the number of terms: ";
    cin>>n;
    for(int i = 1; i<=n; i++){
        cout<<"enter the coefficient: ";
        cin>>a;
        cout<<"enter the power: ";
        cin>>b;
        
        temp = (node *)malloc(sizeof(node));
        temp->coeff = a;
        temp->expo = b;
        
        if(start == NULL || b>start->expo){
            temp->next = start;
            start = temp;
        }
        
        else{
            ptr = start;
            while(ptr->next != NULL && ptr->next->expo>=b )
                ptr = ptr->next;
            
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    
    return start;
}

void display(node *start){
    if(start == NULL){
        cout<<"nothing to display"<<endl;
        return;
    }
    
    do{
        cout<<"+("<<start->coeff<<")"<<"x^"<<start->expo;
        start = start->next;
    }while(start != NULL);
    cout<<endl;
}

void polyAdd(node *p, node *q){
    node *start = NULL, *temp, *ptr;
    while(p != NULL && q != NULL){
        if(p->expo > q->expo){
            temp = (node *)malloc(sizeof(node));
            temp->coeff = p->coeff;
            temp->expo = p->expo;
            temp->next = NULL;
            
            if(start == NULL)
                start = temp;
            else{
                ptr = start;
                while(ptr->next != NULL)
                    ptr = ptr->next;
                ptr->next = temp;
            }
            
            p = p->next;
        }
        
        else if(p->expo < q->expo){
            temp = (node *)malloc(sizeof(node));
            temp->coeff = q->coeff;
            temp->expo = q->expo;
            temp->next = NULL;
            
            if(start == NULL)
                start = temp;
            else{
                ptr = start;
                while(ptr->next != NULL)
                    ptr = ptr->next;
                
                ptr->next = temp;
            }
            
            q = q->next;
        }
        
        else if(p->expo == q->expo){
            temp = (node *)malloc(sizeof(node));
            temp->coeff = p->coeff + q->coeff;
            temp->expo = p->expo;
            temp->next = NULL;
            
            if(start == NULL)
                start = temp;
            else{
                ptr = start;
                while(ptr->next != NULL)
                    ptr = ptr->next;
                
                ptr->next = temp;
            }
            
            p = p->next;
            q = q->next;
        }
    }
    
    while(p != NULL){
        temp = (node *)malloc(sizeof(node));
        temp->expo = p->expo;
        temp->coeff = p->coeff;
        temp->next = NULL;
            
        if(start == NULL)
            start = temp;
        else{
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
                
            ptr->next = temp;
        }
            
        p = p->next;
    }
        
    while(q != NULL){
        temp = (node *)malloc(sizeof(node));
        temp->expo = q->expo;
        temp->coeff = q->coeff;
        temp->next = NULL;
            
        if(start == NULL)
           start = temp;
        else{
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            
            ptr->next = temp;
        }
            
        q = q->next;
    }
    
    display(start);
}

int main(){
    node *poly1 = NULL, *poly2 = NULL;
    cout<<"enter 1st polynomial: "<<endl;
    poly1 = create(poly1);
    cout<<"enter 2nd polynomial: "<<endl;
    poly2 = create(poly2);
    
    display(poly1);
    display(poly2);
    cout<<"result: ";
    polyAdd(poly1, poly2);
    return 0;
}
