//2996. Smallest Missing Integer Greater Than Sequential Prefix Sum


#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
int find(int target , map<int,int>&mp){

    while(mp.find(target)!=mp.end()){
        target++;    //O(n*logn)=T.C
    }
    return target ;
}
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        //find prifix sum
        int sum =nums[0],ind=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
               sum = sum + nums[i]; //O(n)=T.C
            }
            else{
                break;
            }
        }

        int  target = sum ;

        map<int,int>mp;  //S.C= O(n)
        //store all elements in the map  
        for(int i=0;i<n;i++){
            mp[nums[i]] = 1; //O(n*logn)=T.C
        }
       
       return find(target,mp);

    }
};

int main(){
  // vector<int> nums = {38};
  vector<int> nums = {3,4,5,1,12,14,13};

    Solution obj;

    cout << "Answer: "
         << obj.missingInteger(nums);

  return 0;
}

//Time complexity : O(n*logn)
//Space Complexity :O(n)