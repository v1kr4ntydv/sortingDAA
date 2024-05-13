#include<iostream>
#include<ctime>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

class SortingAnalysis{
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
    //merger sort

//merger sort
void mergeSort(int arr[],int start,int end){
    if(start>=end) return;
    int mid=(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
void merge(int arr[],int s,int m,int e){
    int *a=new int[e-s+1];
    int i=s;
    int j=m+1;
    int k=0;
    while (i<=m && j<=e)
    {
        if(arr[i]<=arr[j]){
            a[k]=arr[i++];
        }
        else{
            a[k]=arr[j++];
        }
        k++;
    }
    while (i<=m)
    {
        a[k]=arr[i++];
        k++;
    }
    
    while (j<=e)
    {
        a[k]=arr[j++];
        k++;
    }
    
    for(int l=0;l<e-s+1;l++){
        arr[l+s]=a[l];
    }
    
}
//quick sort
int partition(int arr[],int low,int high){
    int s=low;
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
//heap sort
void heapify(int arr[], int n, int i) { 
    int largest = i; 
    int left = 2 * i + 1; 
   int right = 2 * i + 2; 
 
    if(left < n && arr[largest] < arr[left]) { 
        largest = left; 
    } 
 
    if(right < n && arr[largest] < arr[right]) { 
        largest = right; 
    } 
 
    if(largest != i) { 
        swap(arr[largest], arr[i]); 
        heapify(arr, n, largest); 
    } 
} 
 
void heapSort(int arr[], int n) { 
    for(int i = n / 2 - 1; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
 
    for(int i = n - 1; i > 0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
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

void tester(){
int size[]={100,500,1000,2000,5000,10000,25000,50000,100000};
 for(int j=0;j<9;j++){
    int n=size[j];
    int * arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%n;
    }
    SortingAnalysis s;
    auto before=high_resolution_clock::now();
    s.heapSort(arr,n);
    auto after=high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(after-before);
    cout<<"time for "<<n<<"="<<duration.count()<<endl;

 }
 
}

int main(){
    tester();
    
     return 0;
}