#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;  
void findDiff(vector<int> &arr,int n,int target){
   sort(arr.begin(),arr.end());
   int i=0,j=1;
   int count=0;
   cout<<"PAIRS WITH DIFFERENCE " << target<<endl;
   while(j<n && i<n){
       if(arr[j]-arr[i]==target){
        cout<< arr[j] << "," << arr[i]<<endl;
        i++;
        j++;
        count++;
       }
       else if(arr[j]-arr[i]<target){
               j++;            //need get bigger difference 
       }

      else{
        i++;              //need a smaller difference 
        if(i==j){
            j++;         //keep j ahead
        }
      }
   }

}

int main(){
         vector<int> arr={2,6,7,3,11};
         int n=arr.size();
         int target=5;
         findDiff(arr,n,target);
         

return 0;

}