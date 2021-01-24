//
// Created by LiyouWang on 2021/1/24.
//
# include "iostream"
# include "vector"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double middle = 0.0;
        int length_num1 = nums1.size();
        int length_num2 = nums2.size();
        int i = 0; // num1 index
        int j = 0;  // num2 index
        vector<int> sorted_array = {};
        int count = 0;
        if((length_num2 + length_num1) % 2 == 0)
        {
            while(count<((length_num2 + length_num1)/2 + 1))
            {
                if(i<length_num1 && j<length_num2)
                {
                    if(nums1[i]<=nums2[j])
                    {
                        sorted_array.push_back(nums1[i]);
                        i += 1;
                        count += 1;
                    }
                    else
                    {
                        sorted_array.push_back(nums2[j]);
                        j += 1;
                        count += 1;
                    }

                }
                else
                {
                    if(i<length_num1)
                    {
                        sorted_array.push_back(nums1[i]);
                        i += 1;
                        count += 1;
                    }
                    if(j<length_num2)
                    {
                        sorted_array.push_back(nums2[j]);
                        j += 1;
                        count += 1;
                    }
                }
            }
//            for(int i=0 ;i<sorted_array.size();i++)
//            {
//                cout<<"sorted array is " << sorted_array[i]<<endl;
//            }
            middle = (sorted_array[count-1] + sorted_array[count-2])/2.0;
        }
        else
        {
            while(count<((length_num2 + length_num1 + 1) / 2))
            {

                if(i<length_num1 && j<length_num2)
                {
                    if(nums1[i]<=nums2[j])
                    {
                        sorted_array.push_back(nums1[i]);
                        i += 1;
                        count += 1;
                    }
                    else
                    {
                        sorted_array.push_back(nums2[j]);
                        j += 1;
                        count += 1;
                    }

                }
                else
                {
                    if(i<length_num1)
                    {
                        sorted_array.push_back(nums1[i]);
                        i += 1;
                        count += 1;
                    }
                    if(j<length_num2)
                    {
                        sorted_array.push_back(nums2[j]);
                        j += 1;
                        count += 1;
                    }
                }
            }
//            for(int i=0 ;i<sorted_array.size();i++)
//            {
//                cout<<"sorted array is " << sorted_array[i]<<endl;
//            }
            middle = sorted_array[count-1];
//            cout<<"middle is "<<middle<<endl;
        }

        return middle;

    }
};

int main4()
{
    vector<int> num1 = {2};
    vector<int> num2 = {};
    for(int i=0 ;i<num1.size();i++)
    {
        cout<<"origin array is " << num1[i] <<endl;
    }

    auto so = new Solution();
    double mid = so->findMedianSortedArrays(num1, num2);
    cout<<"middle is "<<mid<<endl;
    return 0;
}

