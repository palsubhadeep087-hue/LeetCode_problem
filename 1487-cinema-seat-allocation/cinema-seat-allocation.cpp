class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> mp;
        for(auto &x : reservedSeats)
        {
            int row = x[0];
            int seat = x[1];

            if(seat >= 2 && seat <= 5)
                mp[row] |= 1;
            if(seat >= 4 && seat <= 7)
                mp[row] |= 2;
            if(seat >= 6 && seat <= 9)
                mp[row] |= 4;
        }
        int ans = (n - mp.size()) * 2;
        for(auto &[row,mask] : mp)
        {
            if(mask == 0)
            {
                ans += 2;
            }
            else if((mask & 1) == 0 || (mask & 4) == 0)
            {
                ans += 1;
            }
            else if((mask & 2) == 0)
            {
                ans += 1;
            }
        }
        return ans;
    }
};