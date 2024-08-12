#include <iostream>
#include <algorithm>
using namespace std;
---------------------------------------------------FIRST SOLUTION---------------------------------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool found = false;

    for (int i = n - 1; i >= 0; i--) {
        int left = 0;
        int right = i - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) {
                found = true;
                break;
            } else if (sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }

        if (found) {
            break;
        }
    }

    if (found) {
        cout << "true";
    } else {
        cout << "false";
    }

    delete[] arr;

    return 0;
}
---------------------------------------------------SECOND SOLUTION---------------------------------------------------------------------------------------------------


bool binarySearch(vector<int>&arr,int left,int right,int x)
{
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        
        if(arr[mid]==x)
        {
            return true;
        }
        else if(arr[mid]<x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    std::sort(arr.begin(),arr.end());
    
    bool found=false;
    int len=arr.size();
    
    for(int i=0;i<len-1;++i)
    {
        for(int j=i+1;j<len;j++)
        {
            int sum=arr[i]+arr[j];
            if(binarySearch(arr,0,len-1,sum)){
             found=true;
                break;
            }
        }
    }

    if(found)
    {
        std::cout<<"true";
    }
    else
    {
    std::cout<<"false";
    }
}
