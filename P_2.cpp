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

void build_listnode(vector<unsigned int>& vector_array, ListNode& list_node)
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
   Solution* su = new Solution();
   ListNode list_1, list_2;
   ListNode* ptr;
   build_listnode(l1, list_1);
   build_listnode(l2, list_2);
   ptr = su->addTwoNumbers(&list_1, &list_2);
   while(ptr->next)
   {
       cout<<ptr->val<<endl;
       ptr=ptr->next;
   }
   cout<< ptr->val << endl;
//   cout<< ptr->next->val<<endl;
//   cout<< ptr->next->next->val<<endl;
}