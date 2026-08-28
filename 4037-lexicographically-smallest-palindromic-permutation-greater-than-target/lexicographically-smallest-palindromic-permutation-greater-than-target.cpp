class Solution {
public:

    string makePalindrome(string &prefix, vector<int> freq, char mid) {
        string left = prefix;
        for (int c = 25; c >= 0; c--) {
            while (freq[c] > 0) {
                left += char('a' + c);
                freq[c]--;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());

        string res = left;
        if (mid != '#')
            res += mid;

        res += right;
        return res;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;
        int odd = 0;
        char mid = '#';
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = freq[i] / 2;
        int len = n / 2;

        string prefix = "";
        for (int pos = 0; pos < len; pos++) {

            bool found = false;
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;
                half[c]--;
                prefix += char('a' + c);
                string candidate = makePalindrome(prefix, half, mid);

                if (candidate > target) {
                    found = true;
                    break;
                }
                prefix.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }
        string ans = prefix;

        if (mid != '#')
            ans += mid;

        string right = prefix;
        reverse(right.begin(), right.end());

        ans += right;

        if (ans > target)
            return ans;

        return "";
    }
};