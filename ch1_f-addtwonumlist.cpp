/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ret;
    struct ListNode* ptr;
    int size_l1 = 1;
    int size_l2 = 1;
    int size_ret;
    int i;

 
    ptr = l1;
    while (ptr->next) {
        ptr = ptr->next;
        size_l1++;
    }
    ptr = l2;
    while (ptr->next) {
        ptr = ptr->next;
        size_l2++;
    }
    size_ret = (size_l1>size_l2) ? size_l1:size_l2;
    ret = malloc(sizeof(struct ListNode)*(size_ret+1));
    for (i=0;i<size_ret;i++) {
        if (i>size_l1)
            ret->val = l2->val;
        else if (i>size_l2)
            ret->val = l1->val;
        else
            ret->val = l1->val + l2->val;
        ret = ret->next;
    }
    //ret->val = l1->val + l2->val;
    //ret->next = NULL;
    
    return ret;
}