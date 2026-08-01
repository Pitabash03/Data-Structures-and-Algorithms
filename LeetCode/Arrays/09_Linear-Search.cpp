#include<iostream>
#include<vector>
using namespace std;

//Question 09 : Finding the index of  a given element in an array

class Solution {
  public:

  //Function to return required ans
  int find(vector<int>&arr , int num){
    //using for loop to find the index of given number
    //Initialy set with -1
    int index = -1;

    for(int i=0;i<arr.size();i++){
      if(arr[i]==num){
        return index=i;
      }
    }
    //If not find return -1
    return index;
  }
};



int main(){
  //Create vector
  vector<int>arr = {6,7,8,4,1};

  //find number
  int number = 5 ;

  //Create Object
  Solution obj;

  //call the function
  if(obj.find(arr,number)!=-1){
    cout<<"Index of "<<number<<" is : " <<obj.find(arr,number);
  }
  else{
    cout<<"Not found.";
  }
  
  return 0;
}



/* 
Time Complexity :O(N)
Space Complexity :O(1) 
*/