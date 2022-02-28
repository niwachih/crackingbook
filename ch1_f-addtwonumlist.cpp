/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int sizeoflist(struct ListNode* l) {
    int ret = 0;
    struct ListNode* ptr = l;
    
    while (ptr != NULL) {
        ptr = ptr->next;
        ret++;
    }
    
    return ret;
}

struct ListNode* addTwo(struct ListNode* l1, struct ListNode* l2, int carry) {
    struct ListNode* ret;
    struct ListNode* ret_more;
    int size_ret;
    int size_l1, size_l2;
    int value = carry;
    
    if (l1 == NULL && l2 == NULL && carry == 0)
        return NULL;
    if (l1 != NULL)
        size_l1 = sizeoflist(l1);
    if (l2 != NULL)
        size_l2 = sizeoflist(l2);
    size_ret = (size_l1 > size_l2) ? size_l1 : size_l2;
    ret = malloc(sizeof(struct ListNode)*(size_ret+1));
    if (l1 != NULL)
        value += l1->val;
    if (l2 != NULL)
        value += l2->val;
    
    ret->val = value % 10;
    
    if ((l1 != NULL) || (l2 != NULL)) {
        ret_more = addTwo((l1 == NULL) ? NULL : l1->next,
                          (l2 == NULL) ? NULL : l2->next,
                          (value >= 10) ? 1 : 0);
        ret->next = ret_more;
    } else {
        ret->next = NULL;
    }
    
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    return addTwo(l1, l2, 0);
}
