string makeGood(string s)
{
    deque<char> deq;
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        if (!deq.empty() && toupper(deq.back()) == toupper(s[i]) &&
            ((isupper(deq.back()) && islower(s[i])) || (islower(deq.back()) && isupper(s[i]))))
            deq.pop_back();
        else
            deq.push_back(s[i]);
    }

    for (int i = 0; i < deq.size(); i++)
        str += deq[i];

    return str;
}