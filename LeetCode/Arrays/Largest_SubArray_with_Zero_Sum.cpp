
#include<bits/stdc++.h>
using namespace std;

//Compute Length of the longest sub array with sum 0

int solution(vector<int>&a){
  //Store best length found so far
  int maxLen = 0;
  //map prifix sum -> first time seen this sum
  unordered_map<int,int>sumIndexMap;
  //running prefix sum
  int sum = 0;
  //iterate through the array
  for(int i=0;i<a.size();i++){
    //update running sum
    sum+=a[i];
    //if sum is 0 then [0..i] has zero sum
    if(sum==0){
      //update best length
      maxLen = i+1;
    }
    else if(sumIndexMap.find(sum)!=sumIndexMap.end()){
      //maximize length using previous index
      maxLen = max(maxLen,i-sumIndexMap[i]);
    }
    else{
      //first time seeing this sum , store its index
      sumIndexMap[sum] = i ;
    }
  }

  //return best length
  return maxLen ;
}

//Program Entry
int main(){
  //sample input
  //vector<int> a = {15, -2, 2, -8, 1, 7, 10, 23};
  //vector<int> a = {9,-3,3,-1,6,-5};
  // vector<int> a = {2, 10, 4};
  vector<int> a = {1, 0, -4, 3, 1, 0};
  //print result
  cout<<solution(a)<<endl;
  //exit
  return 0;

}


