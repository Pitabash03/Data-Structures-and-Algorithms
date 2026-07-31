#include<iostream>
#include<vector>
using namespace std;

//Question 04 : Check if the array is sorted or not

class Solution {
  public:
  
  //Function to check given array is sorted or not
  void IsSorted(vector<int>&arr){

    //Traverse the array
    for(int i=1;i<arr.size();i++){
      //if current element is smaller than previous , then print false other wise true
      if(arr[i] < arr[i-1]){
        cout<<"Array is not sorted."<<endl;
        return;
      }
    }

    cout<<"Yes , Array is sorted."<<endl;
  }
};

int main(){
  //Create a vector
  // vector<int>arr = {1,2,2,3,3,4};
  // vector<int>arr = {1,2,9,3,3,4};
  // vector<int>arr = {0,1,2,-1,9};
  vector<int>arr = {5,5,5,5,5};

  //Create  object 
  Solution obj ;

  //Call function
  obj.IsSorted(arr);

  return 0;
}


/* 
Time Complexity : O(n) //n : Size of an array
Space Complexity : O(1) //No need any space 
*/