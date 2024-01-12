// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int stk[100];
int top = -1;

void push(int ele){
    if(top>=99){
        cout<<"stack full"<<endl;
        return;
    }
    
    stk[++top] = ele;
}

int pop(){
    if(top<0){
        cout<<"stack empty";
        return 0;
    }
    
    return stk[top--];
}

int isDigit(char a){
    if(a>='0' && a<='9')
        return 1;
    return 0;
}

void evalpost(char post[]){
    int i = 0, val, a, b;
    char ch;
    push('(');
    
    while(post[i] != '\0'){
        ch = post[i];
        if(isDigit(ch))
            push(ch-'0');
        else if(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-'){
            a = pop();
            b = pop();
            
            switch(ch){
                case '^':
                    val = pow(b,a);
                    break;
                case '*':
                    val = b*a;
                    break;
                case '/':
                    val = b/a;
                    break;
                case '+':
                    val = b+a;
                    break;
                case '-':
                    val = b-a;
                    break;
            }
            
            push(val);
        }
        i++;
    }
    
    cout<<"result: "<<pop();
}

int main() {
    char post[100];
    cin>>post;
    
    evalpost(post);
    return 0;
}
