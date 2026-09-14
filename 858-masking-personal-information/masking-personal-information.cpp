class Solution {
public:
    string maskPII(string s) {
        if(s.find('@') != string :: npos)
        {
            for(char &c : s)
                c = tolower(c);
            int pos = s.find('@');
            string name = s.substr(0,pos);
            return name[0] + string("*****") + name.back() + s.substr(pos);
        }
        
        string digits = "";
        for(char c : s)
        {
            if(isdigit(c))
                digits += c;
        }
        int n = digits.size();
        string ans = "***-***-" + digits.substr(n - 4);
        if(n == 10)
        {
            return ans;
        }
        ans = "+" + string(n - 10, '*') + "-" + ans;

        return ans;
    }
};