class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int n = s.size();
        int pos = -1;
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    pos = i;
                    break;
                }
            }
            if (freq[x] > 0) {
                freq[x]--;
            }
            else {
                break;
            }
        }

        if (pos == -1)
            return "";
        fill(freq.begin(), freq.end(), 0);

        for (char c : s) {
            freq[c - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < pos; i++) {
            ans += target[i];
            freq[target[i] - 'a']--;
        }

        int x = target[pos] - 'a';

        for (int c = x + 1; c < 26; c++) {
            if (freq[c] > 0) {
                ans += char('a' + c);
                freq[c]--;
                break;
            }
        }

        for (int c = 0; c < 26; c++) {
            while (freq[c] > 0) {
                ans += char('a' + c);
                freq[c]--;
            }
        }

        return ans;
    }
};