#include<iostream>
#include<string>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur_1 = headA;
        ListNode *cur_2 = headB;
        while (cur_1 != cur_2){

            if (cur_1 == NULL){
                cur_1 = headB;
                continue;

            }
            if (cur_2 == NULL){
                cur_2 = headA;
                continue;
            }
            cur_1 = cur_1->next;
            cur_2 = cur_2->next;
        }
        return cur_1;
        
    }
};

int main(){
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    Solution s;
    ListNode *res = s.getIntersectionNode(headA, headB);
    cout << res->val << endl;
}