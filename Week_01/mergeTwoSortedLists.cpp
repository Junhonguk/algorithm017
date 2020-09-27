#include<iostream>
#include"stdio.h"
#include"string.h"
#include <vector>

using namespace std;  

// Definition for singly-linked list.
 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}     
 };

class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        //递归的方法
        //得到其中较小的那个头节点
        //对自身进行递归调用
        //对特殊情况处理
        //如果链表头节点为空，则返回空
        //如果其中一个链接的头节点为空，则直接返回另外一个链表
        if (!l1)
            return l2;
        if(!l2)
            return l1;
        
        //比较两个链表的头节点, 对比较结果分别进行处理
        if (l1->val < l2->val) 
        {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        }
        else
        {
            /* code */
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        
    }
    //print the linked list 

    void printList(ListNode* node) 
    { 
        while (node != NULL) { 
            printf("%d  ", node->val); 
            node = node->next; 
        } 
    } 
};

int main() {
   Solution ob;
   ListNode* head1 = nullptr;
   ListNode* head2 = nullptr;

   head1 = new ListNode(1);
   ListNode* l1_first = new ListNode(3);
   ListNode* l1_second = new ListNode(5);

   head1->next = l1_first;
   l1_first->next = l1_second;
   l1_second->next = nullptr;
    // 1->3->5 LinkedList created 

   head2 = new ListNode(0);
   ListNode* l2_first = new ListNode(2);
   ListNode* l2_second = new ListNode(4);

   head2->next = l2_first;
   l2_first->next = l2_second;
   l2_second->next = nullptr;  
    // 0->2->4 LinkedList created 
  
    ListNode* mergedhead = ob.mergeTwoSortedLists(head1, head2);
    ob.printList(mergedhead);

    return 0;
}