#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class SearchingAlgo{
    int size;
    int *arr;
    map<int,int> map;
    public:
    //constructor
    SearchingAlgo(int arr[],int size){
        for(int i=0;i<size;i++){
            map[arr[i]]=i;
        }

        sort(arr,arr+size);
        // for(int i=0;i<size;i++){
        //     cout<<arr[i]<<" ";
        // }
        this->size=size;
        this->arr=new int[size];
        for(int i=0;i<size;i++){
            this->arr[i]=arr[i];
        }
    }
    //question 1
    //linerar search returning true or false
    bool linerSearch(int n){
        bool flag=0;
        for(int i=0;i<size;i++){
            if(arr[i]==n){
                flag=1;
                cout<<"element "<<n<< " at index "<<map[n]<<endl;
            }
        }
        if(flag==0) cout<<"element not found"<<endl;
        return flag;
    }
    //liner searcch recursive
    bool recursiveLinear(int n){
        
        bool check = helperLinear(0,n);
        if(!check) cout<<"element not found "<<endl;
        return check;
    }
    bool helperLinear(int idx,int n){
        if(idx==size) return false;
        if(arr[idx]==n){
             cout<<"element "<<n<< " at index "<<map[n]<<endl;
            return true;
        }
        return arr[idx]==n ||helperLinear(idx+1,n);
    }
    //binarysearch iterative
    bool binarysearch(int n){
        bool flag=0;
        int start=0;
        int end =size-1;
        int ans_index=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==n){
                flag=1;
                cout<<"element "<<n<<" found at index "<<map[n]<<endl;
            }
            if(arr[mid]<n) start=mid+1;
            else end=mid-1;
        }
        if(flag==0) cout<<"element not found"<<endl;
        return flag;
    }
    //binary search recursive
    bool recurBinarySearch(int n){
        bool check= helperBinary(0,size-1,n);
        if(!check) cout<<"element not found"<<endl;
    }
    bool helperBinary(int start,int end,int n){
        if(start>end) return false;
        int mid=start+(end-start)/2;
        if(arr[mid]==n){
            cout<<"element "<<n<<" found at index "<<map[n]<<endl;
            return true;
        }
        if(arr[mid]<n) return helperBinary(mid+1,end,n);
        return helperBinary(start,mid-1,n);
    }
};

int main(){
int arr[] = {1,2,3,4,5,-1,0};
SearchingAlgo s(arr,7);
//cout<<s.linerSearch(-1)<<endl;
s.recursiveLinear(6);
// cout<<s.binarysearch(5)<<endl;
 //cout<<s.binarysearch(-1)<<endl;
//cout<<s.recurBinarySearch(4)<<endl;
// cout<<s.recurBinarySearch(5)<<endl;
return 0;
}