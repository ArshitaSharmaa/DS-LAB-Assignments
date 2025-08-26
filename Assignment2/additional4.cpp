
#include<iostream>
using namespace std;
void sort(int arr[],int size){
    int mid=0,high=size-1,low=0;                                     //Sort 0 1 AND 2
    while(mid<=high){
        if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
              low++;
              mid++;
        }
        else{
              swap(arr[high],arr[mid]);
              high--;
        }
    }
}
void printSorted(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
}

int main(){
       int arr[]={1,0,2,0,2,1};
       int size=sizeof(arr)/sizeof(arr[0]);
       sort(arr,size);
       printSorted(arr,size);
       return 0;
}
