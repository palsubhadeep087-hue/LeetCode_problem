class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int balance = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                balance--;
            }else{
                balance++;
            }
            if(mp.find(balance) != mp.end())
            {
                ans = max(ans , i - mp[balance]);
            }else{
                mp[balance] = i;
            }
        }
        return ans;
    }
};