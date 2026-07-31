#include<iostream>
#include<vector>
using namespace std;

//Question 07 :  Left rotate the array by D places

class Solution {
public:

//Reverse the array

void reverse(vector<int>&arr , int start , int end){

  while(start<end){
    //store the start element temporaly
  int temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;

  //update
  start++;
  end--;
  }

}

//Function to Rotate given array by D places

void rorate_D_place(vector<int>&arr , int D){
  //size of the array
  int n  =  arr.size();

  //Update D
  D = D % n ;

  //Reverse first D elements
  reverse(arr,0,D-1);
  
  //Reverse last n-D elements
  reverse(arr,D,n-1);

  //Reverse whole array and younfind solution , what you want
  reverse(arr,0,n-1);
}
};


int main(){
  //Create a vector
  vector<int>arr = {1,2,3,4,5,6,7};

  //Give number of Places rotate
  int D = 45;

  //Create object
  Solution obj;

  //Call the function
  obj.rorate_D_place(arr,D);

  //Print resultant solution
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}

/* 
Time Complexity : O(N)  // N : size of an array
Space complexity : O(1)
*/