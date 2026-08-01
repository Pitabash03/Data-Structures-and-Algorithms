#include<iostream>
#include<vector>
using namespace std;

//Question 08 : Moving all zeros to the end of the array

class Solution{
  public:
  //Function to move all zeros at the end/right of the array
  void MoveZeros(vector<int>&arr){
      //using Two pointer to solve this problem
      int j = -1 ;

      //find the index of the first zero using for loop
      for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
          j = i;
          break;
        }
      }

      //Now scan the whole array and swap whenever i find a nonzero , start with j+1 index
      for(int i=j+1 ;i<arr.size();i++){
        if(arr[i]!=0){
          swap(arr[i],arr[j]);
          j++;
        }
      } 

  }
};


int main(){
  //Create a vector array
  //vector<int>arr = {1,0,2,3,2,0,0,4,5,1};
  // vector<int>arr = {0,1,0,3,12};
  vector<int>arr = {0};

  //Create object
  Solution obj ;

  //Call function
  obj.MoveZeros(arr);

  //Print resultant solution
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}

/* 
Time Complexity : O(N)
Space Complexity : O(1) 
*/