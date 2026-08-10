#include<iostream>
#include<vector>
using namespace std;

/*

//Memoization Method

class Solution{
  public:
  
  //Function to return total no. of paths from source to destination
  int f(int row , int col , vector<vector<int>>&dp){
    //Base case
    if(row==0&&col==0) return 1;
    if(row<0 || col<0) return 0;

    //Already computed
    if(dp[row][col]!=-1) return dp[row][col];

    int left = f(row,col-1,dp);
    int up = f(row-1,col,dp);
    return dp[row][col] = left + up ;
  }

  int find(int row , int column){
    //Try all possiible way to reach last position to first position using recursion
    
    //overlapping sub problem arise so emit overlapping using dp array
    vector<vector<int>>dp(row,vector<int>(column,-1));
    return f(row-1,column-1,dp);
  }

};

//Time space complexity : O(m*n)
//Space Complexity : O(m*n)--> dp array , + O(max(row,col))--> recursive stack space need

*/

/*

//Tabulation Method

class Solution{
  public:
  
  int find(int rows , int cols){
    //Try all possiible way to reach last position to first position using recursion
    
    vector<vector<int>>dp(rows,vector<int>(cols,-1));

    //Try all possible path to reach last position
    for(int row=0;row<rows;row++){
      for(int col=0;col<cols;col++){
        if(row==0&&col==0) dp[row][col]=1;
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



/*

//Space Optimization

class Solution{
  public:
  
  //Function to return total no. of paths from source to destination
  int find(int n , int m){

    vector<int>prev(m,0);
    prev[0]=1;

    //Try all possible path to reach last position
    for(int row=0;row<n;row++){
      vector<int>curr(m,0);
      curr[0]=1;
      for(int col=1;col<m;col++){
        curr[col] = prev[col] + curr[col-1];
        }
        //update prev
        prev = curr;
      }
   
    return prev[m-1];
    }
};

//Time Complexity : O(m*n)
//Space Complexity : O(2*m)

*/

//Time and Space : Both optimize using combination formula
class Solution{
public:
int find(int m , int n){
  int N = m+n-2;  // Total moves
  int r = n-1; //Total right moves

  //now use for loop to compute combination
  int ans = 1 ;
  for(int i=1;i<=r;i++){
    ans = ans*(N-r+i)/i;
  }
  
  return ans;
}
};

//Time Complexity : O(n)--> number of columns
//Space Complexity : O(1)


int main(){
  //given number of rows and columns
  int m = 3 , n = 7 ;
  Solution obj;

  //Print all possible paths
  cout<<"Total Number of possible paths is : "<<obj.find(m,n);
  return 0;
}