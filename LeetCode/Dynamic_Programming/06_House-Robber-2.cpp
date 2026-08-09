//Question Link : https://leetcode.com/problems/house-robber-ii/description/


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
  std::vector<int>dp(n-1,-1);

  //create 2 vector , one is include first house and second is exclude first house
  std::vector<int>arr1,arr2;
  for(int i=0;i<n;i++){
    //Include first house
    if(i!=n-1){
      arr1.push_back(arr[i]);
    }
    //Exclude first house
    if(i!=0){
      arr2.push_back(arr[i]);
    }
  }

  int n1 = arr1.size();
  int n2 = arr2.size();
  

  //Remove last house and count how much amount rob
  //Overlapping subproblem reduse using dp array
  std::vector<int>dp1(n1,-1);
  int ans1 = f(n1-1,arr1,dp1);

  //Remove first house and count how much amount rob
  //Overlapping subproblem reduse using dp array
  std::vector<int>dp2(n2,-1);
  int ans2 = f(n2-1,arr2,dp2);
  //Return maximum amount rob
  return std::max(ans1,ans2);
}
};

//Time Complexity :O(2*N)
//Space Complexity : O(2*N)

*/


/*
//Tabulation Method

class Solution{
public:

//function to return maximum amount of money can rob tonight without alerting the police
int find(std::vector<int>&arr){
 
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

int solve(std::vector<int>&arr){
  int n = arr.size();
  //create 2 vector , one is include first house and second is exclude first house
  std::vector<int>arr1,arr2;
  for(int i=0;i<n;i++){
    //Include first house
    if(i!=n-1){
      arr1.push_back(arr[i]);
    }
    //Exclude first house
    if(i!=0){
      arr2.push_back(arr[i]);
    }
  }

  return std::max(find(arr1),find(arr2));
}
};

//Time Complexity :O(2*N)
//Space Complexity : O(2*N)

*/




//Space Optimization

class Solution{
public:

//function to return maximum amount of money can rob tonight without alerting the police
int find(std::vector<int>&arr){
 
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
 
//Function
  int solve(std::vector<int>&arr){
     int n = arr.size();
    //create 2 vector , one is include first house and second is exclude first house
  std::vector<int>arr1,arr2;
  for(int i=0;i<n;i++){
    //Include first house
    if(i!=n-1){
      arr1.push_back(arr[i]);
    }
    //Exclude first house
    if(i!=0){
      arr2.push_back(arr[i]);
    }
  }

  return std::max(find(arr1),find(arr2));
}

};

//Time Complexity :O(2*N)
//Space Complexity : O(1) -->Constant SPace used


int main(){
  std::vector<int>arr = {1,2,3,1};
  Solution obj;
  //call function
  std::cout<<"Total maximum amount is : "<<obj.solve(arr);
  return 0;
}