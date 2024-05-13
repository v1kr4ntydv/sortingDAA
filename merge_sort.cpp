#include<iostream>
using namespace std;
void merge(long long *arr,int s,int m,int e);
void sort(long long *arr,int start,int end){
    if(start>=end) return;
    int mid=(start+end)/2;
    sort(arr,start,mid);
    sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
void merge(long long *arr,int s,int m,int e){
    long long *a=new long long[e-s+1];
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

int main(){

long long arr[]={52244275,123047899,493394237,922363607,378906890,188674257,222477309,902683641,860884025,339100162};
int size=sizeof(arr)/sizeof(arr[0]);
sort(arr,0,size-1);
for(int a:arr){
    cout<<a<<" ";
}
cout<<endl;
return 0;
}