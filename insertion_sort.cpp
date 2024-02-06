#include <iostream>
using namespace std;

void insertionsort(int a[], int n){
    int i, j, min;
    for(i = 1; i<n; i++){
        min = a[i];
        j = i-1;
        while(j>=0 && a[j]>min){
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = min;
    }
}

int main() {
    int a[] = {2,8,3,6,36,97,312,58,69,5};
    insertionsort(a,10);
    
    for(int i = 0; i<10; i++)
        cout<<a[i]<<" ";
    return 0;
}
