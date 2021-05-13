//
// Created by LiyouWang on 2021/5/9.
//
# include "iostream"
# include "vector"
# include "string"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int max_len = 1;
        int begin = 0;
        vector<vector<int>> dp(length,vector<int>(length));
        if(length == 1)
        {
            return s;
        }
        if(length==2)
        {
            if(s[0]==s[1])
            {
                return s;
            }
            else
            {
                string re="a";
                re = s[0];
                return re;
            }
        }
        if(length>2)
        {

            //初始化边界条件
            for(int i=0;i<length-1;i++)
            {
                if(s[i]==s[i+1])
                {
                    dp[i][i+1]=1;
                }
                else
                {
                    dp[i][i+1]=0;
                }
                dp[i][i]=1;
                if(dp[i][i+1])
                {
                    max_len = 2;
                    begin = i;
                }

            }
            //动态规划
            for(int L=2;L<length;L++) { // 回文串的长度来划分
                for (int i = 0; i < length; i++) {
                    int j = L + i;

                    if (j >= length) {
                        break;
                    }

                    if (dp[i + 1][j - 1] && s[i] == s[j]) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                    if(dp[i][j] && j-i+1>max_len)
                    {
                        max_len = j-i+1;
                        begin = i;
                    }

                }
            }
            std::cout<<"max len is "<<max_len;
            std::cout<<std::endl;
            std::cout<<"begin is "<<begin <<std::endl;

//            for(auto vec:dp) {
//                for (auto v:vec) {
//                    std::cout << v <<" ";
//                }
//                std::cout<<std::endl;
//            }
//            std::cout<<s.substr(begin, max_len)<<std::endl;
            return s.substr(begin, max_len);
            //std::cout<<dp.size()<<std::endl;
            //std::cout<< std::to_string(length)<<std::endl;
           // std::cout<<s<<std::endl;

        }
        return s;
    }

};


int main5()
{
    string test;
    test = "abcda";
    Solution so = Solution();
    string s = so.longestPalindrome(test);
    std::cout<<s<<std::endl;
    return 0;
}
