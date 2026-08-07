#include<iostream>
#include<vector>
class Solution{
public:
/*
//Memoization : "Top to Down"

//function to determine the minimum total cost required for the frog to reach the given index stair
int f(int index , std::vector<int>&arr , std::vector<int>&dp){
  
 
  //Base case
  if(index==0) return 0;
  if(dp[index]!=-1)  return dp[index];
  
  //Allow either one step or two steps can jump
  int prev1 = f(index-1,arr,dp)+abs(arr[index]-arr[index-1]);
  int prev2 = INT_MAX ;
  if(index>1) prev2 = f(index-2,arr,dp) + abs(arr[index]-arr[index-2]);

  return dp[index] = std::min(prev1 , prev2);
  
}

//function to determine the minimum total cost required for the frog to reach the last stair

int minCost(std::vector<int>&height){
 int n = height.size();
 //Create dp array to reduce overlapping problem
 std::vector<int>dp(n,-1);
 return f(n-1,height,dp);

}

*/

 //Tabulation : "Bottom to Up"

int minCost(std::vector<int>&arr){
int n = arr.size();
int prev1 = 0 , prev2 = 0  , curri;
for(int i=1;i<n;i++){
  int jumpOne = prev1 + abs(arr[i]-arr[i-1]);
  int jumpTwo = INT_MAX ;
  if(i>1) jumpTwo = prev2 + abs(arr[i]-arr[i-2]);

  curri = std::min(jumpOne,jumpTwo);
  prev2 = prev1;
  prev1 = curri;
}

return prev1;

}
};



int main(){
  std::vector<int> height = {30, 20, 50, 10, 40};
  
  //Create object
  Solution obj;

  std::cout<<"Minimum Cost is : "<<obj.minCost(height);

  return 0;
}



//Example : Input: heights[] = [20, 30, 40, 20]
//Output: 20


// Time Complexity : O(N)
// Space Complexity : O(1)