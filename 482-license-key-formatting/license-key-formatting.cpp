class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp = "";
        for(char c : s)
        {
            if(c != '-')
            {
                temp += toupper(c);
            }
        }
        string ans = "";
        int count = 0;
        for(int i = temp.size()-1; i >= 0; i--)
        {
            if(count == k)
            {
                ans += '-';
                count = 0;
            }
            ans += temp[i];
            count++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};