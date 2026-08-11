#include<iostream>
#include<vector>
using namespace std;

/*
//Memoization Method

class Solution{
  public:
  
  //Function to return total no. of paths from source to destination
  int f(int row , int col , vector<vector<int>>&arr , vector<vector<int>>&dp){
    //Base case
    if(row<0 || col<0) return 0;
    if(arr[row][col]) return 0;
    if(row==0&&col==0) return 1;
    
    
    //Already computed
    if(dp[row][col]!=-1) return dp[row][col];

    int left = f(row,col-1,arr,dp);
    int up = f(row-1,col,arr, dp);
    return dp[row][col] = left + up ;
  }

  int find(vector<vector<int>>&arr){
    int row=arr.size();
    int column = arr[0].size();
    //Try all possiible way to reach last position to first position using recursion
    
    //overlapping sub problem arise so emit overlapping using dp array
    vector<vector<int>>dp(row,vector<int>(column,-1));
    return f(row-1,column-1,arr,dp);
  }

};

//Time space complexity : O(m*n)
//Space Complexity : O(m*n)--> dp array , + O(max(row,col))--> recursive stack space need

*/


/*

//Tabulation Method

class Solution{
  public:
  
  int find(vector<vector<int>>&arr){
    int rows=arr.size();
    int cols = arr[0].size();
    //Try all possiible way to reach last position to first position using recursion
    
    vector<vector<int>>dp(rows,vector<int>(cols,-1));

    //Try all possible path to reach last position
    for(int row=0;row<rows;row++){
      for(int col=0;col<cols;col++){
        if(row==0&&col==0) dp[row][col]=1;
        else if(arr[row][col]==1) dp[row][col]=0;
        else{
          int up= 0 , left = 0;
          if(row>0) up = dp[row-1][col];
          if(col>0) left = dp[row][col-1];
          dp[row][col] = up + left ;
        }
      }
    }
   
    return dp[rows-1][cols-1];
  }

};

//Time Complexity : O(m*n)
//Space Complexity : O(m*n) No stack space required

*/




//Space Optimization

class Solution{
  public:
  
  int mod = 2*1e9 ; //big number reduce 2*10^9
  //Function to return total no. of paths from source to destination
  int find(vector<vector<int>>&arr){
    int n=arr.size();
    int m = arr[0].size();

    vector<int>prev(m,0);

    //Try all possible path to reach last position
    for(int row=0;row<n;row++){
      vector<int>curr(m,0);
      for(int col=0;col<m;col++){
        if(arr[row][col]==1) curr[col]=0;
        else if(row==0&&col==0) curr[col]=1;
        else{
          int left=0 , up=0;
          if(row>0) up = prev[col] ;
          if(col>0) left = curr[col-1];
          curr[col] = (left + up)%mod ;
        }
      }
      //update prev
      prev = curr;
    }
    return prev[m-1];
  }
};

//Time Complexity : O(m*n)
//Space Complexity : O(2*m)


int main(){
  //given grid
  vector<vector<int>>Obstaclegrid = {
    {0,0,0},{0,1,0},{0,0,0}
    // {0,1},{0,0}
  };
  
  Solution obj;

  //Print all possible paths
  cout<<"Total Number of possible paths is : "<<obj.find(Obstaclegrid);
  return 0;
}