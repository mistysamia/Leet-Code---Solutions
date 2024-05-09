int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    deque<int> deq;
    int ans = students.size();

    for (int i = 0; i < students.size(); i++)
        deq.push_back(students[i]);

    for (int i = 0; i < sandwiches.size(); i++)
    {
        int temp = deq.size();
        bool taken = false;
        while (temp)
        {
            temp--;
            if (deq.front() == sandwiches[i])
            {
                deq.pop_front();
                ans--;
                taken = true;
                break;
            }
            else
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        if (!taken)
            return ans;
    }

    return ans;
}