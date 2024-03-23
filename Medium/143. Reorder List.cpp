void reorderList(ListNode *head)
{
    deque<ListNode *> deq;
    ListNode *current = head, *recent, *ans = NULL, *tail = NULL;

    while (current != NULL)
    {
        deq.push_back(current);
        current = current->next;
    }

    bool toggle = true;
    while (!deq.empty())
    {
        if (ans == NULL)
        {
            recent = deq.front();
            tail = ans = recent;
            deq.pop_front();
            toggle = false;
        }
        else
        {
            if (toggle)
            {
                recent = deq.front();
                deq.pop_front();
                toggle = false;
            }
            else
            {
                recent = deq.back();
                deq.pop_back();
                toggle = true;
            }

            tail->next = recent;
            tail = recent;
        }

        if (deq.empty())
            tail->next = NULL;
    }

    head = ans;
}