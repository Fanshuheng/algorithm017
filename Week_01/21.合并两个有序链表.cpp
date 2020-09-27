/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //思路：
 //1.记链表1,2
 //2.链表1前面加一个哨兵
 //3.链表2节点node2与链表节点node1对比，有四种情况
 //3.1 node1->val > node2->val,node2插到node1前面
 //3.2 node1->val <= node2->val, 则node1 = node1->next;
 //3.3 node1 == nullptr,直接将node1_pre->next = node2，然后跳出循环
 //3.4 node2 == nullptr,跳出循环
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto sentinel = new ListNode();
        sentinel->next = l1;

        auto pre = sentinel;
        auto node_2 = l2;
        while (pre->next != nullptr && node_2 != nullptr) {
            if (pre->next->val > node_2->val) {
                auto tmp = node_2->next;
                node_2->next = pre->next;
                pre->next = node_2;
                pre = node_2;
                node_2 = tmp;
            } else {
                pre = pre->next;
            }
        }
        if (!pre->next) {
            pre->next = node_2;
        } 
        return sentinel->next;
    }
};
