
#include<iostream>
#include<vector>
#include"stdio.h"
#include"string.h"

using namespace std;  

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rtnVector;
        Traversal(root, rtnVector);
        return rtnVector;
    }

 // 中序遍历 先遍历左子树->根节点->右子树
 // 通过递归遍历左子树，访问根节点，递归遍历右子树
    void Traversal(TreeNode* cur, vector<int> &res) {
        if (cur == nullptr)
            return;
        Traversal(cur->left, res);
        res.push_back(cur->val);
        Traversal(cur->right, res);
    }

};

int main() {
   Solution ob;

   //创建一棵给定例子中的二叉树
   struct TreeNode* root = new TreeNode(1); 
   root->right = new TreeNode(2);
   root->right->left = new TreeNode(3);

   //中序遍历二叉树
   vector<int> rtnRes = ob.inorderTraversal(root);

   //输出结果
   for (int i = 0; i < rtnRes.size(); i++)
       cout << rtnRes[i] <<endl;
   return 0;
}