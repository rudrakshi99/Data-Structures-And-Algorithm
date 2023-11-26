/* You are given a 0-indexed array of positive integers nums and a positive integer limit.
In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
Return the lexicographically smallest array that can be obtained by performing the operation any number of times. 
*/

#define F first
#define S second

class Solution {
public:
    int parent[100001];
    int size[100001];

    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v) {
        if(v==parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if(a!=b) {
            if(size[a]<size[b]) {
                swap(a,b);
            }
            parent[b] = a;
            size[a]+=size[b];
        }
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            make(i);
        }

        vector<pair<int,int> > val_and_ind;
        for (int i = 0; i < n; i ++) 
            val_and_ind.push_back({nums[i], i});

        sort (val_and_ind.begin(), val_and_ind.end());

        for (int j = 0; j < n-1; j ++) {
            if (val_and_ind[j+1].F - val_and_ind[j].F <= limit)
                Union(val_and_ind[j+1].S, val_and_ind[j].S);
        }

        unordered_map<int, vector<int>> group_indexes;
        unordered_map<int, vector<int>> group_values;
        
        for (int j = 0; j < n; j ++) {
            int lead = find(j);
            
            group_indexes[lead].push_back(j);
            group_values[lead].push_back(nums[j]);
        }
        
        for (auto i : group_values) {
            int id = i.F;
            
            vector<int> indexes = group_indexes[id];
            vector<int> values  = group_values[id];
            
            sort(indexes.begin(), indexes.end());
            sort(values.begin(), values.end());
            
            for (int j = 0; j < indexes.size(); j ++) 
                nums[indexes[j]] = values[j];
        }
        
        return nums;

    }
};
