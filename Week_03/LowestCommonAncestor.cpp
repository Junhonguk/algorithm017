#include<iostream>
#include"stdio.h"
#include"string.h"
#include<vector>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root || root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

       if (left && right) // p and q on both sides
            return root;
        
        return left ? left : right;
    }
};


int main() {
   Solution ob;

  //创建二叉树
   struct TreeNode* root = new TreeNode(3);
   root->left = new TreeNode(5); 
   root->right = new TreeNode(1);

   root->left->left = new TreeNode(6);
   root->left->right = new TreeNode(2);

   root->left->right->left = new TreeNode(7);
   root->left->right->right = new TreeNode(4);

   root->right->left = new TreeNode(0);
   root->right->right = new TreeNode(8);
  
   TreeNode* p = new TreeNode(5);
   TreeNode* q = new TreeNode(4);

   TreeNode* rtnCommonAncestor = ob.lowestCommonAncestor(root, p, q);

   int rtnTreeNodeValue = rtnCommonAncestor->val;
   cout << "The lowest common ancestor is: " << endl;
   cout << rtnTreeNodeValue;

   return 0;
}