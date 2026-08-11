#include<iostream>
#include<vector>
using namespace std;

/*

//Recursive method

class Solution {
  public:
  //Function to return menimum cost
  int f(int row , int col ,int size , vector<vector<int>>&trig){
    //Base case
    if(row==size-1) return trig[row][col];

    int down = trig[row][col] + f(row+1,col,size,trig);
    int diagonal = trig[row][col] + f(row+1,col+1,size,trig);

    return min(down,diagonal);

  }

  int MinimumTotal(vector<vector<int>>&triangle){
    int n = triangle.size(); //Number of rows;

    return f(0,0,n,triangle);

  }

};

//Time Complexity : O(2^n)
//Space Complexity : O(n)

*/


/*
//Memoization method (To reduces overlapping sub problems)

class Solution {
  public:
  //Function to return menimum cost
  int f(int row , int col ,int size , vector<vector<int>>&trig , vector<vector<int>>&dp){
    //Base case
    if(row==size-1) return trig[row][col];
    //Already compute
    if(dp[row][col]!=-1) return dp[row][col];

    int down = trig[row][col] + f(row+1,col,size,trig,dp);
    int diagonal = trig[row][col] + f(row+1,col+1,size,trig,dp);

    return dp[row][col] = min(down,diagonal);

  }

  int MinimumTotal(vector<vector<int>>&triangle){
    int n = triangle.size(); //Number of rows;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,0,n,triangle,dp);

  }

};

//Time Complexity : O(n^2)
//Space Complexity : O(n^2) + O(n)--> recursion stack space

*/


/*
//Tabulation method (To reduces recursion stack space)

class Solution {
  public:
  //Function to return menimum cost

  int MinimumTotal(vector<vector<int>>&triangle){
    int n = triangle.size(); //Number of rows;
    vector<vector<int>>dp(n,vector<int>(n,-1));

    for(int i=0;i<n;i++){
      dp[n-1][i] = triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
      for(int j=i;j>=0;j--){
          int down = triangle[i][j] + dp[i+1][j];
          int diagonal = triangle[i][j] + dp[i+1][j+1];
          dp[i][j] = min(down , diagonal);
        }
      }
  
  return dp[0][0];
  }
};

//Time Complexity : O(n^2)
//Space Complexity : O(n^2)

*/

//Tabulation method (To reduces recursion stack space)

class Solution {
  public:
  //Function to return menimum cost

  int MinimumTotal(vector<vector<int>>&triangle){
    int n = triangle.size(); //Number of rows;
    vector<int>front(n,0);

    for(int i=0;i<n;i++){
      front[i] = triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
      vector<int>curr(n,0);
      for(int j=i;j>=0;j--){
          curr[j] = triangle[i][j] + min(front[j] , front[j+1]);
        }
        front = curr ;
      }
  
  return front[0];
  }
};

//Time Complexity : O(n^2)
//Space Complexity : O(n)



int main(){
  vector<vector<int>>triangle = {
    {2},{3,4},{6,5,7},{4,1,8,3}
    //{-10}
  };

  Solution obj;

  //Print output
  cout<<"Answer : "<<obj.MinimumTotal(triangle);

  return 0;
}