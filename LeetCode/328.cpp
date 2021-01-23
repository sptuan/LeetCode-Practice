/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* one = head;
        ListNode* two = head->next;

        ListNode* point1 = one;
        ListNode* point2 = two;

        ListNode* point = point2->next;
        int flag = 0;
        ListNode* lastpoint1 = one;
        ListNode* lastpoint2 = two;
        while(point!=NULL){
            if(flag == 0){
                point1->next = point;
                
                point1 = point;
                lastpoint1 = point1;
                //cout<<"ADD one "<<point->val<<" Before "<<lastpoint1->val<<endl;
                flag = 1;
            }
            else{
                point2->next = point;
                
                point2 = point;
                lastpoint2 = point2;
                //cout<<"ADD two "<<point->val<<" Before "<<lastpoint2->val<<endl;
                flag = 0;
            }
            point = point->next;

        }

        lastpoint1->next = two;
        lastpoint2->next = NULL;

        return one;

    }
};
