#include<iostream>
#include"stdio.h"
#include"string.h"
#include <vector>

using namespace std;  

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoSums;
        for (int i = 0 ; i < nums.size() - 1; i++ )
            for (int j = i+1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target) {
                    twoSums.push_back(i);
                    twoSums.push_back(j);
                    return twoSums;
                }
        return twoSums;
    }
};

int main() {
   Solution ob;
   vector<int> v = {1,7,5,4};
   int target = 9;
   vector <int> rtnIndxes = ob.twoSum(v, target);
   for (int i = 0; i < rtnIndxes.size(); i++)
       cout << rtnIndxes[i] <<endl;
   return 0;
}