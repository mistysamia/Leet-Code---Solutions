
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *current = list2, *endNode = NULL;
        int n = 0;

        while (current != NULL)
        {
            if (current->next == NULL)
                endNode = current;
            current = current->next;
        }

        current = list1;
        while (current != NULL)
        {
            n++;
            if (n == b + 1)
            {
                endNode->next = current->next;
                break;
            }
            current = current->next;
        }

        current = list1;
        n = 0;
        while (current != NULL)
        {
            n++;
            if (n == a)
            {
                current->next = list2;
                break;
            }
            current = current->next;
        }

        return list1;
    }
};