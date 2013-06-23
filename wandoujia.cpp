#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    private:
        vector<int> marr;

    public:
        vector<int> getMagicArr(vector<int> input)
        {
            for (int index = 1; index < input.size(); ++index)
            {
                //
                if ((index-1) % 2 == 0)
                {
                    if (input[index-1] > input[index])
                    {
                        swap(input[index-1], input[index]);
                    }
                }
                else
                {
                    if (input[index-1] < input[index])
                    {
                        swap(input[index-1], input[index]);
                    }
                }
            }

            return input;
        }
};

int main()
{
    vector<int> input;
    for (int i = 0; i < 5; ++i)
    {
        input.push_back(i);
    }

    Solution *sl = new Solution();
    vector<int> output = sl->getMagicArr(input);
    for (int i = 0; i < 5; ++i)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}

