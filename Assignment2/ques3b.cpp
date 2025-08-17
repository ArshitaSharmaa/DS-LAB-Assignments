#include<iostream>
using namespace std;
int findMissing(int arr[],int size){
   int start=0,end=size-1;
while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==mid+1){
        start=mid+1;
    }
    else{
        end=mid-1;
    }
}
 return start+1;
}
int main(){
    int arr[]={1,2,3,5,6};
    int size=6;
    int result=findMissing(arr,size);
    cout<<"Missing number is: "<< result;
    return 0;
}