#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
// vector<int> arr= { 33, 45, 40, 25, 17, 24};
vector<int> arr= {170, 45, 75, 90, 802, 24, 2, 66};

int length=arr.size();
int maxn=arr[0];
for(int i=0;i<length;i++){
    maxn=max(maxn,arr[i]);
}

int digCount=0;
while (maxn>0)
{
    digCount++;
    maxn/=10;
}

for (int i = 1; i <= digCount; i++)
{
    vector<vector<int>> radixArray={{},{},{},{},{},{},{},{},{},{}};
    for(int j=0;j<length;j++){
        int place = ((int)(arr[j]/pow(10,i-1)))%10;
        radixArray[place].push_back(arr[j]);
    }
    int arridx=0;
    for(int j=0;j<10;j++){
        for(int k=0;k<radixArray[j].size();k++){
            arr[arridx++]=radixArray[j][k];

        }
    }
    
}

for(int i=0;i<length;i++){
    cout<<arr[i]<<" "; 
}



}