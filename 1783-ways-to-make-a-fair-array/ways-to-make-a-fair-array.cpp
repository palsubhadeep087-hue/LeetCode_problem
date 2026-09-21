class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int leftEven = 0, rightEven = 0;
        int leftOdd = 0, rightOdd = 0;

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                rightEven += nums[i];
            }else{
                rightOdd += nums[i];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                rightEven -= nums[i];
            }else{
                rightOdd -= nums[i];
            }
            int evenSum = leftEven + rightOdd;
            int oddSum = leftOdd + rightEven;

            if(evenSum == oddSum)
            {
                ans++;
            }
            if(i % 2 == 0)
            {
                leftEven += nums[i];
            }else{
                leftOdd += nums[i];
            }
        }
        return ans;
    }
};