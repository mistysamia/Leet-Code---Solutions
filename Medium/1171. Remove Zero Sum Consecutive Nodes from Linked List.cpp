struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *root = new ListNode(0);
    root->next = head;

    ListNode *current = root;

    while (current != NULL)
    {
        ListNode *recent = current->next;
        long long int sum = 0;
        while (recent != NULL)
        {
            sum += recent->val;
            if (sum == 0)
                current->next = recent->next;

            recent = recent->next;
        }
        current = current->next;
    }

    return root->next;
}