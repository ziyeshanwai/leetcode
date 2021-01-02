//
// Created by LiyouWang on 2021/1/2.
//
#include "string"
#include "iostream"
#include "unordered_set"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> table;
        int length = s.size();
        int left_start = 0;
        int max_len = 0;
        int current_len = 0;
        for(int i=0;i<length;i++)
        {
            if(table.count(s[i]))
            {
                while(table.count(s[i]))
                {
                    table.erase(s[left_start]);
                    current_len -= 1;
                    left_start += 1;
                }
                table.insert(s[i]);
                current_len += 1;

            }
            else
            {
                table.insert(s[i]);
                current_len += 1;
            }
            if(max_len < current_len)
            {
                max_len = current_len;
            }

        }
        return max_len;

    }
};

int main3()
{
    string s = "bbbbb";
    cout<<s<<endl;
    unordered_set<char> test = {'2','3','8','2'};
    test.erase('2');
    for(auto it=test.begin();it != test.end();it++ )
    {
        cout<<*it<<endl;
    }
    cout<<test.count('2')<<endl;
    auto so = new Solution();
    int length = so->lengthOfLongestSubstring(s);
    cout <<"length is "<<length<<endl;
    return 0;
}
