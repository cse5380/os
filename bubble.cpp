#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Eneter number of elements in array= ";
    cin>>n;

    int arr[n];

    // INPUT
    for(int i=0; i<n;i++){
        cout<<"Enter element in array:";
        cin>>arr[i];
    }

    // bubble sort

    for(int j=0; j<n-1 ;j++){
        for(int i=0;i<n-j-1;i++){
            if(arr[i]>arr[i+1]){
                // swap
                int temp=arr[i];
                arr[i]=arr[1+i];
                arr[i+1]=temp;
            }
        }
    }
    // output
    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
    
}
