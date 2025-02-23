using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode begin = ListNode();
        ListNode *end = &begin;
        int extra = 0;

        while (l1 || l2 || extra)
        {
            int value = extra;
            if (l1)
            {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                value += l2->val;
                l2 = l2->next;
            }

            extra = value / 10;
            end->next = new ListNode(value % 10);
            end = end->next;
        }

        return begin.next;
    }
};