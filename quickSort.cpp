class Solution {
private:
    int partition(vector<int>& nums,int start,int end) {
        int pivot=nums[end];
        int ind=start;
        for (int i=start;i<end;i++) {
            if (nums[i]<pivot) {
                swap(nums[ind],nums[i]);
                ind++;
            }
        }
        swap(nums[ind],nums[end]);
        return ind;
    }
    void quickSort(vector<int>& nums,int start,int end) {
        if (start>=end) return;
        swap(nums[end],nums[start+rand()%(end-start+1)]);
        int ind=partition(nums,start,end);
        quickSort(nums,start,ind-1);
        quickSort(nums,ind+1,end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        quickSort(nums,start,end);
        return nums;
    }
};
