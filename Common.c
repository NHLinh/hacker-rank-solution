    std::stringstream ss;
    for (int i = half; i < s.length(); i++)
    {
        ss << s[i];
    }
    return ss.str();


int camelcase(string s) {
    int count = 1;
    for (int i = 0; i < s.length(); i++)
        if ((s[i] >= 'A') && (s[i] <= 'Z')) count++;

    return count;
}

string removeDuplicateChar(string s)
{
    int compareLength = s.length() - 1;
    char charToRemove = ' ';
    int i = 0;
    while (i < compareLength)
    {
        if (s[i] == s[i + 1])
        {
            charToRemove = s[i];
            break;
        }
        i++;
    }
    
    if (charToRemove != ' ') // Remove Duplicate
    {
        std::stringstream ss;
        for (int i = 0; i < s.length(); i++)
            if (s[i] != charToRemove) ss << s[i];
        return removeDuplicateChar(ss.str());
    }
    return s;
}

