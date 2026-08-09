#include<iostream>
#include<vector>

/*

//Memoization Method

class Solution{
public:

//return maximum amount money to reach last house
int f(int ind , std::vector<int>&arr , std::vector<int>&dp){
  //Base case 
  if(ind==0) return arr[ind];

  //Already compute
  if(dp[ind]!=-1) return dp[ind];

  int Take = arr[ind] ;
  if(ind-2>=0) Take+=f(ind-2,arr,dp);

  int nonTake = 0 + f(ind-1,arr,dp);

  return dp[ind] = std::max(Take,nonTake);
}

//function to return maximum amount of money can rob tonight without alerting the police
int solve(std::vector<int>&arr){
 
  int n = arr.size();

  //Overlapping subproblem reduse using dp array
  std::vector<int>dp(n,-1);

  return f(n-1,arr,dp);
}
};

//Time Complexity :O(N)
//Space Complexity : O(N)


*/

/*
//Tabulation Method

class Solution{
public:

//function to return maximum amount of money can rob tonight without alerting the police
int solve(std::vector<int>&arr){
 
  int n = arr.size();

  //Overlapping subproblem reduse using dp array
  std::vector<int>dp(n,-1);
  
  dp[0] = arr[0];
  for(int i=1;i<n;i++){

    int Take = arr[i] ;
    if(i-2>=0) Take += dp[i-2];

    int nonTake = 0 + dp[i-1];
    //Store 
    dp[i] = std::max(Take,nonTake);
  }
   //Last index store maximum amount 
   return dp[n-1];

}
};

//Time Complexity :O(N)
//Space Complexity : O(N)

*/


//Space Optimization

class Solution{
public:

//function to return maximum amount of money can rob tonight without alerting the police
int solve(std::vector<int>&arr){
 
  int n = arr.size();
  int prev = 0 , prev2 = 0 , curri;
  for(int i=0;i<n;i++){
    int Take = arr[i] + prev2 ;
    int nonTake = 0 + prev;
    //Store 
    curri = std::max(Take,nonTake);

    //Update 
    prev2 = prev ;
    prev = curri ;
  }
 
  return prev;

}
};

//Time Complexity :O(N)
//Space Complexity : O(1) -->Constant SPace used

int main(){
  std::vector<int>arr = {1,2,3,1,5};
  Solution obj;
  //call function
  std::cout<<"Total maximum amount is : "<<obj.solve(arr);
  return 0;
}