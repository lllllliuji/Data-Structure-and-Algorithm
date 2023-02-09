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
class Solution {
   public:
    ListNode* removeNodes(ListNode* head) {
        deque<int> q;
        for (auto p = head; p != nullptr; p = p->next) {
            while (!q.empty() && p->val > q.back()) q.pop_back();
            q.push_back(p->val);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (!q.empty()) {
            auto t = q.front();
            q.pop_front();
            auto node = new ListNode(t);
            p = p->next = node;
        }
        return dummy->next;
    }
};