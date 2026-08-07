#include<iostream>
#include<vector>


class Solution{
public:
//function to find minimum cost to reach index "ind" to using at most k jumps
int f(int ind , std::vector<int>&arr, int steps , std::vector<int>&dp){
   //Base case 
   if(ind==0)  return 0;

   //Return already computed result
   if(dp[ind]!=-1) return dp[ind];

   //Initialize minimum cost at large value
   int minCost = INT_MAX ;

   //Try all possible jumps from 1 to k
   for(int i=1;i<=steps;i++){
    //check not going outside of boundary
    if(ind-i>=0){
      //cost of taking the jump
      int jump = f(ind-i,arr,steps,dp) + abs(arr[ind]-arr[ind-i]);
      //store the minimum cost
      minCost = std::min(jump , minCost);
    }
   }

   return dp[ind] = minCost;
}

//Function to get minimum cost to reach end
int solve(std::vector<int>&height , int k){
  int n = height.size();
  //dp array initialized to -1
  std::vector<int>dp(n,-1);

  return f(n-1,height,k,dp);
}
};



//Main function
int main(){
  std::vector<int>height{15,4,1,14,15};
  int k = 3;

  //create object
  Solution obj;

  std::cout<<"Total minimum Cost is : "<<obj.solve(height,k);
  
  return 0;
}



//Time Complexity : O(N*k)
//Space Complexity : O(N)
