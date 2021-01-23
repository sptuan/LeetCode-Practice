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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans;
        int nums = 0;
        ListNode* point = root;
        while(point!=NULL){
            nums++;
            point = point->next;
        }

        int much = nums % k;
        int less = nums / k;

        point = root;
        for(int i=0; i<much; i++){
            ListNode* temp = point;
            ListNode* pre;
            ans.push_back(temp);
            for(int j=0; j<less+1; j++){
                pre = point;
                if(point!=NULL)
                    point = point->next;
            }
            if(pre!=NULL)
                pre->next = NULL;
        }

        for(int i=0; i<k-much; i++){
            ListNode* temp = point;
            ListNode* pre = NULL;
            ans.push_back(temp);
            for(int j=0; j<less; j++){
                pre = point;
                if(point!=NULL)
                    point = point->next;
            }
            if(pre!=NULL){
                pre->next = NULL;
            }
        }
        return ans;
    }
};
