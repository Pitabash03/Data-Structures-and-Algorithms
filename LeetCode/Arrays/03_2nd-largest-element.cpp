#include<iostream>
#include<vector>
using namespace std;

//Question 02 : Find the  Second largest distinct element in the array

class Solution {
  public:

  //Function to return second largest element
  int SecondLargest(vector<int>&arr){

    //Initialize largest with first element of array  and Second largest with -1
    int largest = arr[0] , Slargest=-1;

    //traverse the array to find second largest
    for(int i=1;i<arr.size();i++){

      //Update largest and secnod largest if current element is greater
      if(arr[i]>largest){
        Slargest = largest;
        largest = arr[i];
      }

      //Update Second largset is if current element is smaller then largest but greater than second largest
      else if(arr[i]<largest && arr[i]>Slargest){
        Slargest = arr[i];
      }
    }

   //return Second largest element
    return Slargest;
    
  }
};

int main(){

  //Create a vector
  
  // vector<int>arr = {1,2,4,7,7,5};
  //vector<int>arr = {12,35,1,10,34,1};
  //vector<int>arr = {10,5,10};
  vector<int>arr = {10,10,10};

  //Create an object of solution array
  Solution obj;

  //call the member function using the object
  cout<<"Second largest element is : "<<obj.SecondLargest(arr)<<endl;

  return 0;

}


/* 
Time complexity = O(n); //n : size of an array
Space Complexity = O(1) //No need any space
*/


