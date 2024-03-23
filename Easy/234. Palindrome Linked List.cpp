struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    ListNode *current = head;
    int n = 0, i = 1;
    deque<ListNode *> deq;

    while (current != NULL)
    {
        n++;
        current = current->next;
    }
    if (n == 1)
        return true;

    current = head;
    while (current != NULL)
    {
        if (n % 2 == 0)
        {
            if (n / 2 >= i)
            {
                deq.push_back(current);
                i++;
            }
            else
            {
                if (deq.back()->val != current->val)
                    return false;
                else
                    deq.pop_back();
            }
        }
        else
        {
            if (n / 2 >= i)
            {
                deq.push_back(current);
                i++;

                if (n / 2 + 1 == i)
                {
                    current = current->next;
                    i++;
                }
            }
            else
            {
                if (deq.back()->val != current->val)
                    return false;
                else
                    deq.pop_back();
            }
        }

        current = current->next;
    }
    return true;
}