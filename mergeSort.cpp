class Solution {
public:
    void merge(vector<int>& nums,int start,int mid,int end) {
        vector<int> left,right;
        for (int i=start;i<=mid;i++) left.push_back(nums[i]);
        for (int i=mid+1;i<=end;i++) right.push_back(nums[i]);
        int i=0,j=0,k=start;
        while (i<left.size()&&j<right.size()) {
            if (left[i]<right[j]) {
                nums[k++]=left[i++];
            }
            else {
                nums[k++]=right[j++];
            }
        }
        while (i<left.size()) {
            nums[k++]=left[i++];
        }
        while (j<right.size()) {
            nums[k++]=right[j++];
        }
    }
    void mergeSort(vector<int>& nums,int start,int end) {
        if (start>=end) return;
        int mid=(start+end)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
