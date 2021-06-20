//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/submissions/
//O(n)

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* iterNode = head;
        int cnt = 0;//���Ҹ� ���°�� �������� 1,2,3...

        int swap_val[2] = { 0,0 };//A�� B�� swap�ؾߵȴٸ� [0]:A�� val [1]:B�� val
        ListNode* swap_idx[2] = { nullptr,nullptr };//A�� B�� swap�ؾߵȴٸ� [0]:A node�� ptr [1]:B�� ptr

        int size = getSize(head);

        if (size == 2)
        {
            //swap_val array�� ������
            swap_val[0] = iterNode->val;
            iterNode = iterNode->next;
            swap_val[1] = iterNode->val;

            iterNode = head;
            //������ ���� ������� swap
            iterNode->val = swap_val[1];
            iterNode = iterNode->next;
            iterNode->val = swap_val[0];

            return head;
        }

        while (iterNode != nullptr)
        {
            cnt++;
            //swap_val, swap_idx array�� ������
            if (cnt == k)
            {
                swap_val[0] = iterNode->val;
                swap_idx[0] = iterNode;
            }
            if (cnt == size - k + 1)
            {
                swap_val[1] = iterNode->val;
                swap_idx[1] = iterNode;
            }
            iterNode = iterNode->next;
        }
        //������ ���� ������� swap
        swap_idx[0]->val = swap_val[1];
        swap_idx[1]->val = swap_val[0];

        return head;

    }

    int getSize(ListNode* head) {
        ListNode* iterNode = head;
        int size = 0;
        while (iterNode != nullptr)
        {
            size++;
            iterNode = iterNode->next;
        }
        return size;

    }
};