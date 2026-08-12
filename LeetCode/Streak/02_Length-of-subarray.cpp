#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Sliding window problems (12-08-2026)
//Length of Longest Subarray With at Most K Frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
      int n = nums.size();
        
       /*
        int maxi = 0;
        //Brute force method
        //Try all possible subarray 
        for(int i=0;i<n;i++){
            //create a map function to store frequency
            unordered_map<int,int>frq;
            int cnt = 0;
            for(int j=i;j<n;j++){
                frq[nums[j]]++;
                if(frq[nums[j]]>k){
                    break;
                }
                cnt++;
            }
          maxi = max(cnt,maxi);
        }

        return maxi;
        */


        //Susing liding window 

        int left=0;
        int maxi = 0 , cnt = 0;
        unordered_map<int,int>frq;
        for(int right=0;right<n;right++){
          frq[nums[right]]++;
          //if frequency is grater than k , then left just increase
          while(frq[nums[right]]>k){
            frq[nums[left]]--;
            left++;
          }
          maxi = max(maxi,right-left+1);
        }
       return maxi;
    }
};

//Time Complexity : O(n)
//Space Complexity : O(n)//unordered map use


int main(){
  //vector<int>nums={1,2,3,1,2,3,1,2};
  vector<int>nums={5,5,5,5,5,5,5};
  int k = 4;

  Solution obj;

  cout<<"Answer : "<<obj.maxSubarrayLength(nums,k);
  return 0;
}