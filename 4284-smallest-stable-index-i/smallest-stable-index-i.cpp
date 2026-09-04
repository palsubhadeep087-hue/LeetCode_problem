class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int max = nums[0];
            int min = nums[i];
            for(int j = 0; j <= i; j++)
            {
                if(nums[j] > max)
                {
                    max = nums[j];
                }
            }
            for(int j = i; j < n; j++)
            {
                if(nums[j] < min)
                {
                    min = nums[j];
                }
            }
            if(max - min <= k)
            {
                return i;
            }
        }
        return -1;
    }
};