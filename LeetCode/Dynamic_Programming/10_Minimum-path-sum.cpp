#include<iostream>
#include<vector>
using namespace std;

/*
//Recursive Method

class Solution {
public:

int find(int row , int col , vector<vector<int>>&grid){
  //base cases
  if(row==0 && col==0) return grid[row][col];
  if(row<0 || col<0) return INT_MAX;
  

  int left = INT_MAX;
  int up = INT_MAX;

  if(col>0) left = find(row,col-1,grid) + grid[row][col];
  if(row>0) up = find(row-1,col,grid) + grid[row][col];

  return min(left,up);
}

int minPathSum(vector<vector<int>>&grid){
  int row = grid.size();
  int col = grid[0].size();

  return find(row-1,col-1,grid);

}

};

//Time Complexity : O(2^(m+n))
//Space Complexity : O(m+n) //Recursive stack space

*/


/*
//Memoization Method (To emit overlapping sub problems)

class Solution {
public:

int find(int row , int col , vector<vector<int>>&grid , vector<vector<int>>&dp){
  //base cases
  if(row==0 && col==0) return grid[row][col];
  if(row<0 || col<0) return INT_MAX;

  //if already computed then direct return
  if(dp[row][col]!=-1) return dp[row][col];

  int left = INT_MAX;
  int up = INT_MAX;

  if(col>0) left = find(row,col-1,grid,dp) + grid[row][col];
  if(row>0) up = find(row-1,col,grid,dp) + grid[row][col];

  return dp[row][col] = min(left,up);
}

int minPathSum(vector<vector<int>>&grid){
  int row = grid.size();
  int col = grid[0].size();

  vector<vector<int>>dp(row,vector<int>(col,-1));

  return find(row-1,col-1,grid,dp);

}

};

//Time Complexity : O(m*n)
//Space Complexity : O(m*n) + O(m+n)--> Recursive stack space

*/


/*
//Tabulation Method (To reduce recursive stack space)

class Solution {
public:

int minPathSum(vector<vector<int>>&grid){
  int row = grid.size();
  int col = grid[0].size();

  vector<vector<int>>dp(row,vector<int>(col,-1));

  //base case
  dp[0][0] = grid[0][0];

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(i==0 && j==0){
        dp[i][j] = grid[i][j];
      }
      else{
        int right = INT_MAX ;
        int down = INT_MAX ;
        if(j>0) right = dp[i][j-1] + grid[i][j];
        if(i>0) down = dp[i-1][j] + grid[i][j]; 

        dp[i][j] = min(right,down);
      }
    }
  }

  return dp[row-1][col-1];

}

};

//Time Complexity : O(m*n)
//Space Complexity : O(m*n) //only dp array takes

*/


//Space Optimization Method (To reduce space)

class Solution {
public:

int minPathSum(vector<vector<int>>&grid){
  int row = grid.size();
  int col = grid[0].size();

  vector<int>prev(col,0);
  //base case
  prev[0] = grid[0][0];

  for(int i=0;i<row;i++){
    vector<int>curr(col,0);
    for(int j=0;j<col;j++){
      if(i==0 && j==0){
        curr[j] = grid[i][j];
      }
      else{
        int right = INT_MAX ;
        int down = INT_MAX ;
        if(j>0) right = curr[j-1] + grid[i][j];
        if(i>0) down = prev[j] + grid[i][j]; 

        curr[j] = min(right,down);
      }
    }
    prev = curr ;
  }

  return prev[col-1];

}

};

//Time Complexity : O(m*n)
//Space Complexity : O(2*m) //only dp array takes


int main(){
  //Enter vector
  vector<vector<int>>grid = {
    //{1,3,1},{1,5,1},{4,2,1}
    {1,2,3},{4,5,6}
  };
  
  Solution obj;

  //print minimum path sum
  cout<<"Minimum path sum is : "<<obj.minPathSum(grid);
  return 0;
}