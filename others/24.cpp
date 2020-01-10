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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        ListNode* temp_head = head->next;
        while(1){
            
            ListNode* temp;
            ListNode* next_node;
            next_node = node2->next;
            // check rest 2 nodes
            if(node2->next == NULL){
                temp = node2->next;
                
            }
            else if((node2->next)->next == NULL){
                temp = node2->next;
            }
            else{
                temp = (node2->next)->next;
            }
            //swap *next
            node2->next = node1;
            node1->next = temp;
            //check
            if(next_node == NULL) break;
            if((next_node->next) == NULL) break;
            //move forward
            node2 = (next_node->next);
            node1 = next_node;
        }
        return temp_head;
    }
};
