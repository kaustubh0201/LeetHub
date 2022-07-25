class Solution {
public:
    
    int binarySearch(vector<int> &nums, int left, int right, int &key){
        
        if(left > right)
            return -1;
        
        int mid = (left + right) / 2;
        
        if(nums[mid] == key)
            return mid;
        else if(key > nums[mid]){
            return binarySearch(nums, mid + 1, right, key);
        }else{
            return binarySearch(nums, left, mid - 1, key);
        }       
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int index = binarySearch(nums, 0, n - 1, target);
        
        if(index == -1){
            return {-1, -1};
        }
        
        int i;
        
        vector<int> result;
        
        for(i = index; i > 0; i--){
            if(nums[i] != nums[i - 1])
                break;
        }
        
        result.push_back(i);
        
        for(i = index; i < n-1; i++){
            if(nums[i] != nums[i + 1])
                break;
        }       
        
        result.push_back(i);       
        
        return result;
        
    }
};