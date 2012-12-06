#include <iostream>
#include <stdio.h>
using namespace std;

long num[100005];

int main()
{
    long n;
    scanf("%ld", &n);
    long pre;
    long temp;
    long index;
    int flag = 0;
    //0==. 1递增, -1 递减

    long x, y;
    if (n <= 2)
    {
        flag = 0;
    }
    else
    {
        for (index = 1; index <= n; ++index)
            scanf("%ld", &num[index]);

        int isOrder = 0;
        for (index = 2; index <= n; ++index)
        {
            if (index == 1)
            {
            }
            else
            {
                if (num[index-1] < num[index])
                {
                    //unchange
                    if (isOrder == 1)
                    {
                        flag = 1;
                        break;
                    }
                    else if (isOrder == -1)
                    {
                        if (n == 3 && num[index] == num[index-2])
                        {
                            flag = 0;
                            break;
                        }

                        flag = 2;
                        if (num[index-2] != num[index])
                        {
                            x = index - 2;
                            y = index;
                            break;
                        }
                        else if (num[index + 1] == num[index])
                        {
                            x = index - 1;
                            y = index;
                        }
                        else if (num[index + 1] < num[index])
                        {
                            if ( num[index-1] == num[index+1])
                            {
                                if (n == 4)
                                {
                                flag = 0;
                                break;
                                }
                                else
                                {
                                    if (num[index + 2] != num[index])
                                    {
                                        x = index;
                                        y = index + 2;
                                        flag = 2;
                                        break;
                                    }
                                    else
                                    {
                                        x = index + 1;
                                        y = index + 2;
                                    }
                                }
                            }
                            else
                            {
                            x = index;
                            y = index + 1;
                            }
                        }
                        else
                        {
                            x = index - 2;
                            y = index + 1;
                        }

                        break;
                    }
                    //unchange
                    else if (index >= 3)
                    {
                        flag = 1;
                        break;
                    }
                    isOrder = 1;//递增
                }
                else if (num[index-1] > num[index])
                {

                    //unchange
                    if (isOrder == -1)
                    {
                        flag = 1;
                        break;
                    }
                    //change
                    else if (isOrder == 1)
                    {
                        if (n == 3 && num[index] == num[index-2])
                        {
                            flag = 0;
                            break;
                        }

                        flag = 2;
                        if (num[index-2] != num[index])
                        {
                            x = index - 2;
                            y = index;
                            break;
                        }
                        else if (num[index + 1] == num[index])
                        {
                            x = index - 1;
                            y = index;
                        }
                        else if (num[index + 1] < num[index])
                        {
                            x = index - 2;
                            y = index + 1;
                        }
                        else
                        {
                            if ( num[index-1] == num[index+1])
                            {
                                if (n == 4)
                                {
                                flag = 0;
                                break;
                                }
                                else
                                {
                                    if (num[index + 2] != num[index])
                                    {
                                        x = index;
                                        y = index + 2;
                                        flag = 2;
                                        break;
                                    }
                                    else
                                    {
                                        x = index + 1;
                                        y = index + 2;
                                    }
                                }
                            }
                            else
                            {
                            x = index;
                            y = index + 1;
                            }
                        }
                        flag = 2;
                        break;
                    }
                    //unchange
                    else if (index >= 3)
                    {
                        flag = 1;
                        break;
                    }
                    isOrder = -1;//递减
                }
                else
                {
                    //unchange
                    if (isOrder != 0)
                    {
                        flag = 3;
                        break;
                    }
                }

            }

        }
    }

    if (flag == 1)
    {
        printf("%ld %ld\n", index-1, index);
    }
    else if (flag == 2)
    {
        printf("%ld %ld\n", x, y);
    }
    else if (flag == 3)
    {
        printf("%ld %ld\n", index-2, index-1);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}

