//
// Created by LiyouWang on 2021/5/13.
//
# include "iostream"
# include "vector"
# include "string"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        else
        {
            vector<vector<char>> ss(numRows, vector<char>(0));
            int len = s.size();
            int ind = 0;
            bool odd = true;
            for(int i=0;i<len;i++)
            {
                if(odd)
                {
                    ss[ind].push_back(s[i]);
                    ind += 1;
                    if(ind==numRows)
                    {
                        odd=false;
                        ind = numRows - 2;
                    }
                }
                else
                {
                    ss[ind].push_back(s[i]);
                    ind -= 1;
                    if(ind==-1)
                    {
                        odd=true;
                        ind = 1;
                    }
                }

            }
            for(int i=0; i<numRows; i++)
            {
                string tmp = "";
                for(auto str: ss[i])
                {
                    tmp = tmp + str;
                }
                std::cout<<"the "<<i<<" row is "<<tmp<<std::endl;

            }
            string result = "";
            for(int i=0; i<numRows; i++)
            {
                for(auto str: ss[i])
                {
                    result = result + str;
                }

            }
            return result;
        }
    }
};

int main()
{
    Solution so = Solution();
    string s = so.convert("AB", 1);
    std::cout<<s<<std::endl;
}
