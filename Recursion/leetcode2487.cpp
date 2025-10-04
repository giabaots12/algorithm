#include <iostream>
using namespace std;
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x){
            val = x;
            next = NULL;
        }
    };

    ListNode *add(int x, ListNode *head) {
        ListNode *tmp = new ListNode(x);
        if (head == nullptr) {
            return tmp;
        }
        ListNode *p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = tmp;
        return head;
    }

    ListNode *removeNodes(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode *p = head;
        ListNode *l = removeNodes(p->next);
        if(p->val < l->val){
            //delete(p);
            return l;
        }
        else{
            p->next = l;
            return p;
        }
    }

    void print(ListNode *head){
        ListNode *p = head;
        while(p != NULL){
            cout<<p->val<<" ";
            p = p->next;
        }
    }
};




int main(){
    
    Solution sol;
    int n;
    cin >> n;
    Solution::ListNode *head = nullptr; 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = sol.add(x, head);   
    }
    head = sol.removeNodes(head);
    sol.print(head);
    return 0;
}