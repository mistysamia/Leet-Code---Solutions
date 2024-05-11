vector<string> InsertIntoVec(string version)
{
    bool dot = true, zero = false;
    string s = "";
    vector<string>vec;

    for(int i = 0; i<version.size() ; i++)
    {
        if(version[i] == '.' && dot)
        {
            if(s.size()<1)
                s+="0";
            dot = false, zero = false;
            vec.push_back(s);
            s.clear();
        }
    
        if(dot && !zero && version[i]!='0')
            zero = true;
        if(zero)
            s+=version[i];
        if(version[i] == '.')
            dot = true;
    }

    if(s.size() < 1)
        s+="0";
    vec.push_back(s);
    
    return vec;
}

int compareVersion(string version1, string version2) {
    vector<string>vec1, vec2;

    vec1 = InsertIntoVec(version1);
    vec2 = InsertIntoVec(version2);

    while(vec1.size() > vec2.size())
        vec2.push_back("0");
    
    while(vec1.size() < vec2.size())
        vec1.push_back("0");
    
    for(int j = 0; j<vec1.size() ; j++)
    {
        string s1 = vec1[j];
        string s2 = vec2[j];

        if(s1.size() > s2.size())
            return 1;
    
        if(s1.size() < s2.size())
            return -1;

        for(int i = 0; i<s1.size();i++)
        {
            if(s1[i]-'0' < s2[i]-'0')
                return -1;
            else if(s1[i]-'0' > s2[i]-'0')
                return 1;
        }
    }

    return 0;
}