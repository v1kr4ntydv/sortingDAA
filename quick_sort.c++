#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int s=low+1;
    int e=high;
    
    int pivot=low;
    while(s<=e){
        while(s<=e && arr[s]<=arr[pivot]) s++;
        while(s<=e && arr[e]>arr[pivot]) e--;
        if(s<e){
            swap(arr[s],arr[e]);
        }
    }
    swap(arr[pivot],arr[e]);
    pivot=e;
    return pivot;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int idx=partition(arr,low,high);
        quickSort(arr,low,idx-1);
        quickSort(arr,idx+1,high);
    }
}

int main(){

int arr[]={5,3,8,6,4,7,3,1};
// int arr[]={4,1,3,9,7};
int size=sizeof(arr)/sizeof(arr[0]);

quickSort(arr,0,size-1);
for(int a:arr){
    cout<<a<<" ";
}
return 0;
}