#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k==0 || nums.size() == 1)
        {
            return false;
        }

        vector<int>::iterator it1 = nums.begin(), it2;
        if (nums.size() < k)
        {
            it2 = nums.end() - 1;
        }
        else
        {
            it2 = nums.begin() + k;
        }


        for(; it2 != nums.end(); it1++, it2++)
        {
            vector<int> sub_vec(it1, it2+1);
            sort(sub_vec.begin(), sub_vec.end());

            cout << *it1 << " " << *it2 <<endl;
            return true;

        }
        return false;
    }

    void insert(vector<int> &vec, int val)
    {

        if(vec.size() > 0)
        {
            int first = 0, last = vec.size() - 1;

            int mid = vec.size() / 2;
            while()
            if (vec[mid] < val)
            {

            }
        }
    }
};

int main(int argc, char** argv)
{
    // vector<int> nums = {1,2,3,1}; int k = 1, t = 0;
    vector<int> nums = {4,3,2,1}; int k = 3, t = 0;

    Solution sol;
    bool output = sol.containsNearbyAlmostDuplicate(nums, k, t);
    cout << output << endl;

    return 0;
}