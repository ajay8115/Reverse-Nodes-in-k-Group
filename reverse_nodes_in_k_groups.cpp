#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<vector<int>> v;
        ListNode *cur = head;
        vector<int> t;
        while (cur)
        {
            t.push_back(cur->val);
            cur = cur->next;
            if (t.size() == k)
            {
                reverse(t.begin(), t.end());
                v.push_back(t);
                t.clear();
            }
        }
         
        v.push_back(t);

        vector<int> u;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                u.push_back(v[i][j]);
            }
        }

        int i = 0;
        cur = head;
        while (cur)
        {
            cur->val = u[i];
            i++;
            cur = cur->next;
        }

        return head;
    }
};