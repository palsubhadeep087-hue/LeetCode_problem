class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        int count = 0;
        while(s.size() < b.size())
        {
            s += a;
            count += 1;
        }
        if(s.find(b) != string :: npos)
            return count;
        s += a;
        count++;
        if(s.find(b) != string::npos)
            return count;
        return -1;
    }
};