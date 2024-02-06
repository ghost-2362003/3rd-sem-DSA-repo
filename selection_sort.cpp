#include <iostream>
using namespace std;

int main() {
    int arr[] = {23,56,78,1,3,6,9,21,3,58};
    
    for(int i = 0; i<10; i++){
        int min = i;
        for(int j = i+1; j<10; j++)
            if(arr[min]>arr[j])
                min = j;
        
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    
    for(int i = 0; i<10; i++)
        cout<<arr[i]<<" ";
    
    return 0;
}
