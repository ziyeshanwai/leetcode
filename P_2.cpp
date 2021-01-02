//
// Created by LiyouWang on 2021/1/1.
//
#include "iostream"
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/*
 * 先将每个链表的数字变为正确的数字然后求和再变回链表的方式是错误的
*/
class Solution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int64_t input_0 = 0;
        int i = 1;
        ListNode* ptr;
        ptr = l1;
        while(ptr->next != nullptr)
        {
            input_0 = input_0 + ptr->val * i;
            i = i * 10;
            ptr = ptr->next;

        }
        input_0 = input_0 + ptr->val * i;
        int64_t input_1 = 0;
        i = 1;
        ptr = l2;
        while(ptr->next != nullptr)
        {
            input_1 = input_1 + ptr->val * i;
            i = i * 10;
            ptr = ptr->next;

        }
        input_1 = input_1 + ptr->val * i;
        int64_t result = input_0 + input_1;

        vector<unsigned int> re;
        if(result==0)
        {
            re.push_back(result);
        }
        else{
            while(result)
            {
                int tmp = result % 10;
                result = result / 10;
                re.push_back(tmp);

            }
        }
        ListNode* resu = new ListNode(re[0]);
        ListNode* move_ptr;
        move_ptr = resu;
        for(int i=1;i<re.size();i++)
        {
            move_ptr->next = new ListNode(re[i]);
            move_ptr = move_ptr->next;
        }

        return resu;

    }
};

/*
 * 直接使用加法的法则方式进行相加
 */
class Solution_1 {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* resu = new ListNode(0);
        int mod;
        int step;
        ListNode* move_ptr;
        move_ptr = resu;
        int i = 0;
        while(l1 || l2)
        {
            int tmp = 0;
            if(l1 == nullptr && l2 != nullptr)
            {
                tmp = l2->val;
            }
            if(l1 != nullptr && l2 == nullptr)
            {
                tmp = l1->val;
            }
            if(l1 != nullptr && l2 != nullptr)
            {
                tmp = l1->val + l2->val;
            }
           if(i==0)
           {
               if(tmp>=10)
               {
                   mod = tmp % 10;
                   step = 1;
               }
               else
               {
                   mod = tmp;
                   step = 0;
               }
               resu->val = mod;
           }
           else
           {
               if((tmp+step) >= 10)
               {
                   mod = (tmp+step) % 10;
                   move_ptr->next = new ListNode(mod);
                   move_ptr = move_ptr->next;
                   step = 1;
               }
               else
               {
                   mod = tmp + step;
                   move_ptr->next = new ListNode(mod);
                   move_ptr = move_ptr->next;
                   step = 0;
               }

           }
           if(l1 != nullptr)
           {
               l1 = l1->next;
           }
           if(l2 != nullptr)
           {
               l2 = l2->next;
           }

           i += 1;
        }
        if(step==1)
        {
            move_ptr->next = new ListNode(1);
        }
        return resu;

    }
};


void build_listnode(vector<int>& vector_array, ListNode& list_node)
{
    ListNode* list_copy;
    list_node = ListNode(vector_array[0]);
    list_copy = &list_node;
    for(int i=1;i<vector_array.size();i++)
    {
        list_copy->next = new ListNode(vector_array[i]);;
        list_copy = list_copy->next;
    }
}

int main()
{
   vector<int> l1 = vector<int>{9};
   vector<int> l2 = vector<int>{1,9,9,9,9,9,9,9,9,9};
   Solution_1* su = new Solution_1();
   ListNode list_1, list_2;
   ListNode* ptr;
   build_listnode(l1, list_1);
   build_listnode(l2, list_2);
   ptr = su->addTwoNumbers(&list_1, &list_2);
   int i = 0;
   while(ptr)
   {
       cout<< i << " "<< ptr->val<<endl;
       ptr=ptr->next;
       i += 1;
   }
//   cout<< ptr->val << endl;
//   cout<< ptr->next->val<<endl;
//   cout<< ptr->next->next->val<<endl;
}