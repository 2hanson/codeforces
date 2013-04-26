#include <iostream>
using namespace std;

class Solution
{
    public:
        void test(int a, int b)
        {
            int c = a + b;
        }

        int test(int a)
        {
        }

        void test(int a, char b)
        {
            char c = b;
        }

        void test(char a, int b)
        {
            char c = a;
        }
};

int main()
{
    Solution s;
    s.test(1);
    return 0;
}
