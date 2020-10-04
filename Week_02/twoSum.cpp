#include<iostream>
#include"stdio.h"
#include"string.h"
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;  

class Solution {
public:
    //利用哈希表求解
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0 ; i < nums.size(); i++ ){
            auto it = hashtable.find(target-nums[i]);
            //找到满足条件的元素
            if (it != hashtable.end()) {
                return {it->second, i}; //返回满足条件的元素下标
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main() {
   Solution ob;
   vector<int> v = {2, 7, 11, 15};
   int target = 9;
   vector <int> rtnIndxes = ob.twoSum(v, target);
   for (int i = 0; i < rtnIndxes.size(); i++)
       cout << rtnIndxes[i] <<endl;
   return 0;
}