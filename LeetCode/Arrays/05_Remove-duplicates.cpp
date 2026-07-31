#include<iostream>
#include<vector>
using namespace std;

//Question 05 : Remove duplicates in-place from Sorted array and return the new length


class Solution {
  public:

  int Remove_deplicate(vector<int>&arr){
    //using two pointer to solve this problem
    int i=0;

    //Traverse the array
    for(int j=1;j<arr.size();j++){
      if(arr[i]!=arr[j]){
        arr[i+1] = arr[j];
        i++;
      }
    }
    
    //return length of distinct arrray
    return i+1;

  }
};


int main(){

  //Create a sorted vector

  // vector<int> arr = {1,1,2,2,2,3,3};
  // vector<int> arr = {1,2,5,5,9,13,34};
  // vector<int> arr = {6};
  vector<int> arr = {4,4,4,4,4};

  //create object
  Solution obj;

  //call function and print solution
  cout<<"Length of the new distinct array is : "<<obj.Remove_deplicate(arr)<<endl;

  return 0;
  
}

/* 
Time Complexity : O(n) //N : Size of an array
Space Complexity : O(1) //No need any space
*/ 
