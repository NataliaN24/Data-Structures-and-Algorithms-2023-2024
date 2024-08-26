class Solution {
public:
void merge(vector<int>&nums,int left,int mid,int right)
{
    int l1=mid-left+1;
    int l2=right-mid;
    vector<int>leftArr(l1);
    vector<int>rightArr(l2);
    for(int i=0;i<l1;i++)
    {
        leftArr[i]=nums[left+i];
    }
    for(int i=0;i<l2;i++)
    {
        rightArr[i]=nums[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<l1 && j<l2)
    {
        if(leftArr[i]<=rightArr[j])
        {
            nums[k++]=leftArr[i++];
        }
        else
        {
            nums[k++]=rightArr[j++];
        }
    }
    while(i<l1)
    {
nums[k++]=leftArr[i++];
    }
    while(j<l2)
    {
nums[k++]=rightArr[j++];
    }
    
}
void mergeSort(vector<int>&nums,int left,int right)
{
if(left>=right){
    return;
}
int mid=left+(right-left)/2;
mergeSort(nums,left,mid);
mergeSort(nums,mid+1,right);
merge(nums,left,mid,right);
}

    void sortColors(vector<int>& nums) {
       mergeSort(nums,0,nums.size()-1);
    }
};
