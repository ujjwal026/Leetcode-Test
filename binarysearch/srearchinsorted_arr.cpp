class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int r=nums.size()-1,l=0,mid=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[l]){
                if(target>=nums[l]&&target<=nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
