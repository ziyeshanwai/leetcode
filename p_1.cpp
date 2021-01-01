#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size();i++)
        {
            int tmp = target - nums[i];
            for(int j=0;j<nums.size();j++)
            {
                if(i != j)
                {
                    if(nums[j] == tmp)
                    {
                        result.push_back(i);
                        result.push_back(j);
                        return result;
                    }
                }
            }
        }
        return result;
    }

};

int main1() {
    int target = 9;
    vector<int> test = {2, 7, 11, 15};
    Solution so = Solution();
    vector<int> result = so.twoSum(test, target);
    cout << result[0] << endl;
    cout<< result[1] << endl;
    return 0;
}
