#include<iostream>
#include<vector>
using namespace std;

/*
//Memoization

class Solution{
public :
//Recursive function to calculate maximum points in Ninja Training
int f(int day , int last , vector<vector<int>>&mat , vector<vector<int>>&dp){
  //if already compute
  if(dp[day][last]!=-1) return dp[day][last];
  //Base case
  int maxi = 0;
  if(day==0){
    for(int i=0;i<3;i++){
      if(i!=last){
        maxi = max(maxi,mat[day][i]);
      }
    }
    return maxi;
  }

  //Iterative all task
  int points = 0;
  for(int i=0;i<3;i++){
    if(i!=last){
      int activity = mat[day][i]+f(day-1,i,mat,dp);
      points = max(points , activity);
    }
  }

  return dp[day][last] = points;
}

//function to find maximum points earn to Ninja's Training
int solve(vector<vector<int>>&mat){
  int n = mat.size(); //find number of rows / days
  //Reduce overlapping sub problem using dp 2d array
  vector<vector<int>>dp(n,vector<int>(4,-1));
  return f(n-1,3,mat,dp); //f(day,last) format
}
};

//Time Complexity : O(n*4*3) 
//Space Complexity : O(n*4) + O(n) for recursion stack

*/


/*

//Tabulation

class Solution{
public :

//function to find maximum points earn to Ninja's Training
int solve(vector<vector<int>>&mat){

  int n = mat.size(); //find number of rows / days

 //Reduce overlapping sub problem using dp 2d array
  vector<vector<int>>dp(n,vector<int>(4,-1));

  //base case
  dp[0][0] = max(mat[0][1],mat[0][2]);
  dp[0][1] = max(mat[0][0],mat[0][2]);
  dp[0][2] = max(mat[0][0],mat[0][1]);
  dp[0][3] = max(mat[0][0],max(mat[0][1],mat[0][2]));//maximum points for day 0 , none of these task was done

  //Iterate through the days starting from day 1
  for(int day=1 ; day<n;day++){
    //for each day check all possible last activity {0,1,2 , or no previous activity (3)}
    for(int last=0;last<4;last++){
      dp[day][last] = 0;
      //Iterate through the activities for the current day
      for(int task=0;task<3;task++){
        if(task!=last){
          int points = mat[day][task]+dp[day-1][task];
          dp[day][last]=max(points,dp[day][last]);
        }
      }
    }
  }  

  return dp[n-1][3]; //last day store maximum points
}
};

//Time Complexity : O(n*4*3) 
//Space Complexity : O(n*4) -->No recursive stack space required

*/




//Space Optimization

class Solution{
public :

//function to find maximum points earn to Ninja's Training
int solve(vector<vector<int>>&mat){

  int n = mat.size(); //find number of rows / days

  vector<int>prev(4,0);

  //base case
  prev[0] = max(mat[0][1],mat[0][2]);
  prev[1] = max(mat[0][0],mat[0][2]);
  prev[2] = max(mat[0][0],mat[0][1]);
  prev[3] = max(mat[0][0],max(mat[0][1],mat[0][2]));//maximum points for day 0 , none of these task was done

  //Iterate through the days starting from day 1
  for(int day=1 ; day<n;day++){
    //Create current days points
    vector<int>curr(4,0);
    //for each day check all possible last activity {0,1,2 , or no previous activity (3)}
    for(int last=0;last<4;last++){
      curr[last] = 0;
      //Iterate through the activities for the current day
      for(int task=0;task<3;task++){
        if(task!=last){
          int points = mat[day][task]+prev[task];
          curr[last]=max(points,curr[last]);
        }
      }
    }
    prev = curr ;
  }  

  return prev[3]; //last day store maximum points
}
};

//Time Complexity : O(n*4*3) 
//Space Complexity : O(8) or O(1) -->Only constant space required


int main(){
  vector<vector<int>>mat = {
    {10,40,70},
    {20,50,80},
    {30,60,90}
    //{4, 2, 6}
    };

  Solution obj;
  cout<<"Total points earn : "<<obj.solve(mat)<<" points";

  return 0;
}