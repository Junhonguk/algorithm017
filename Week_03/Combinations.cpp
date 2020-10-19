#include<iostream>
#include"stdio.h"
#include"string.h"
#include<vector>

using namespace std;

class Solution {
public: 
    vector<vector<int>> combine(int n, int k){
        dfs(temp,n, k, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(vector<int>& temp, int n, int k, int x){
        //terminator
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for (int i = x+1; i <= n; i++){
            //process current logic
            temp.push_back(i);

            //drill down
            dfs(temp, n, k, i);

            //reverse the state
            temp.pop_back();
        }
    }
};

int main() {
   Solution ob;
   int n =5;
   int k = 3;
   vector<vector<int>> results;

   results = ob.combine(n, k);

   for (int i = 0; i < results.size(); i++){
       for (int j = 0; j < results[i].size(); j++)
              cout << results[i][j];
       cout << endl;
   }
       
   return 0;
}