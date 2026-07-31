#include<iostream>
#include<vector>
using namespace std;

//Left Rotate the array by one place and give resultant array

class Solution {
  public:
  
  //Function to rotate left side by one place
  void Rotate_Left(vector<int>&arr){
    //Store the last element
    int last = arr[0];

    //Traverse the array
    for(int i=1;i<arr.size();i++){
      //Shift all elements one step to the left
      arr[i-1] = arr[i];
    }

    //placed the first element at the last location
    arr[arr.size()-1] = last;
  }
};


int main(){
  //Create a vector
  // vector<int>arr = {1,2,3,4,5,6};
  vector<int>arr = {5,3,9,1,7,8};

  //create object
  Solution obj;

  //call function
  obj.Rotate_Left(arr);

  //Print the resultant solution
  for(int  i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}


/* 
Time Complexity : O(N) //N : size of an array
Space Complexity : O(1) 
*/