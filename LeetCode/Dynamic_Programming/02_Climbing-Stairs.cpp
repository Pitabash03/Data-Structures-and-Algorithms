#include<iostream>


class Solution {
  public:

  //Function to count total number of ways
  int cnt(int n){

    if(n==1 || n==2) return n;

    int prev1 = 2 , prev2 = 1 , curri ;

    for(int i=3;i<=n;i++){
      //find ith position , total number of ways;
      curri = prev1 + prev2 ;
      //Update 
      prev2 = prev1 ;
      prev1 = curri;
    }
   
    //Total number of ways store in prev1, so return prev1 not curri
    return prev1;   
  }

};


int main(){
  std::cout<<"Enter Height of the top position : ";
  int n;
  std::cin>>n;

  Solution obj;

  //print the total number of ways
  std::cout<<"Total number of ways is : "<<obj.cnt(n);
  return 0;
}


/*
Time Complexity : O(N) 
Space Complexity : O(1) 
*/