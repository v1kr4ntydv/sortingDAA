#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

class Sorting{
    public:
    
    //bubble sort
    void bubbleSort(int nums[],int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    int temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
    }
    //insertion sort
     void insertionSort(int nums[],int n){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j>0;j--){
                if(nums[j]<nums[j-1]){
                    int temp=nums[j];
                    nums[j]=nums[j-1];
                    nums[j-1]=temp;
                }
            }
        }
    }

    //selection sort
    void selecionSort(int nums[],int n){
        for(int i=0;i<n;i++){
            int max=findMax(nums,i,n);
            //lets swap the curr max with the last element
            int temp=nums[max];
            nums[max]=nums[n-i-1];
            nums[n-i-1]=temp;
        }
    }
    private:
    int findMax(int nums[],int idx,int size){
        int maxx=0;
        for(int i=0;i<=size-idx-1;i++){
            if(nums[i]>nums[maxx]) maxx=i;
        }
        return maxx;
    }
    
    

    
};

int main(){
    Sorting s;
     int * arr=new int[10];
    //int arr[]={4,3,2,1};
    
    int N=10;
    for(int i=0;i<N;i++){
        arr[i]=rand()%N;
    }
    s.bubbleSort(arr,N);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}