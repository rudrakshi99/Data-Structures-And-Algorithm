#include <bits/stdc++.h>
using namespace std;

class SearchInRotatedSortedArray {
  public:
    int search(vector<int>& nums, int target) {
        int ans =-1;
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            
            int mid = l + (r-l)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            else if(nums[mid]<=nums[r]){
                if(target>nums[mid] && target<=nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }

        }
        
    	return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums ={5, 6, 8, 1, 3, 4};

    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        int target;
        cin >> target;
        int result = SearchInRotatedSortedArray().search(nums, target);
        cout << result << "\n";
    }

    return 0;
}
