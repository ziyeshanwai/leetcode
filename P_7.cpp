//
// Created by LiyouWang on 2021/5/16.
//
#include<iostream>
#include<math.h>

/*
 * 首先打印出2^31-1 和 -2^31
 * 确定末尾数字是多少用于确定边界
 * 比较好的思想是在差最后一位是进行比较而不是进行完全部计算后再比较，进行完全部计算再比较已经有可能溢出了 所以在还差一位时比较并通过比较最后一位来实现*/

class Solution {
public:
    int reverse(int x) {
        int m = 0;
//        int flag=1;
//        if(x<0)
//        {
//            flag = -1;
//        })
        std::cout.setf(std::ios::fixed);
        std::cout<<pow(2, 31)<<std::endl;
        std::cout<<"INT MAX "<<INT_MAX<<std::endl;
        std::cout<<"INT MIN "<<INT_MIN<<std::endl;
        while (x)
        {
            m = m * 10 + (x % 10);
            x = x / 10;
            if (m > INT_MAX / 10 && x !=0 || (m == INT_MAX / 10 && x > 7)) return 0;
            if (m < INT_MIN / 10 && x !=0 || (m == INT_MIN / 10 && x < -8)) return 0;

        }
        return m;

    }
};


int main7()
{
    int x = -2147483412;
    Solution so = Solution();
    int result = so.reverse(x);
    std::cout<<"print over !"<<std::endl;
    std::cout<<result<<std::endl;
}
