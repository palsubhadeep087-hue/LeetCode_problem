class Solution {
public:
    int search(vector<int>& A, int target) {
        int st  = 0, end = A.size() - 1;
        while(st <= end)
        {
            int mid = st + (end - st)/2;
            if(A[mid] < target){
                st = mid + 1;
            }else if(A[mid] > target){
                end = mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};