bool isPalindrome(int i , int n, string s)
{
    while(i <= n)
    {
        if(s[i] !=s [n])
            return false;
        i++, n--;
    }
    return true;
}

void backtrack(string s, int indx, vector<vector<string>>& vec , vector<string>& temp)
{
    if(indx >= s.size())
    {
        vec.push_back(temp);
        return;
    }

    for(int i = indx; i<s.size() ; i++)
    {
        if(isPalindrome(indx, i ,s))
        {
            temp.push_back(s.substr(indx,  i));
            backtrack(s, i+1 , vec, temp );
            temp.pop_back();
        }
    }        
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> vec;
    vector<string> temp;

    backtrack(s, 0 , vec, temp );
    return vec;
}