#include<bits/stdc++.h>
using namespace std;

//Question : Find largest elements in an array

class Solution{
  public:

  //function to return the largest element
      int largest(vector<int>&arr){

        //Assume the first element is the largest
        int maxi = arr[0];

        //Traverse the array
        for(int i=0;i<arr.size();i++){

          //Update maximum if current element is greater
          if(arr[i]>maxi){
            maxi = arr[i];
          }

        }
        //return the largest element
        return maxi;
        
      }
};


int main(){
  //Create a vector (Dynamic array)
  vector<int>arr = {2,3,1,4,7,6};

  //Create an object of Solution array
  Solution obj;

  //Call the member function using the object
  cout<<"Largest element is : "<<obj.largest(arr)<<endl;
  return 0;
}
