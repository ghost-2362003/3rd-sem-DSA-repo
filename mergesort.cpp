// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void merge(int a[], int p, int q, int r){
    int n1, n2, i, j, k;
    n1 = q-p+1;
    n2 = r-q;
    int L[n1], R[n2];
    
    for(i = 0; i<n1; i++)
        L[i] = a[p+i];
    
    for(j = 0; j<n2; j++)
        R[j] = a[q+j+1];
    
    i = 0, j = 0, k = p;
    while(i<n1 && j<n2){
        if(L[i]<R[j])
            a[k++] = L[i++];
            
        else if(L[i]>R[j])
            a[k++] = R[j++];
    }
    
    while(i != n1)
        a[k++] = L[i++];
    
    while(j != n2)
        a[k++] = R[j++];
    
}

void mergesort(int a[], int l, int r){
    if(l<r){
        int p = l + (r-l)/2;
        mergesort(a,l,p);
        mergesort(a,p+1,r);
        merge(a,l,p,r);
    }
}

int main() {
    int a[] = {3,23,89,7346,123,156,234234};
    mergesort(a,0,6); //enter the last index as the third parameter 
    
    for(int i = 0; i<7; i++)
        cout<<a[i]<<" ";
    
    return 0;
}
