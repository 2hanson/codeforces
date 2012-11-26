#include <iostream>  
#include <vector>  
#include <string> 
using namespace std;

long n;

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& result)  
{  
    int i, j, k;  
    int tmp;  
  
    for (i = 0; i < a.size(); ++i)   
    {  
        k = i;  
        for (j = 0; j < b.size(); ++j)  
        {  
            result[k++] += a[i] * b[j];  
        }  
    }  
      
    for (k = result.size() - 1;  k >= 0; --k)   
    {  
        if (result[k] > 9)   
        {  
            if (k != 0)  
            {  
                  
                result[k-1] += result[k] / 10;  
                result[k] %= 10;  
            }  
            else   //如果是第一项大于9则添加一项于头部  
            {     
                tmp = result[k] / 10;  
                result[k] %=10;  
                result.insert(result.begin(), tmp);  
            }  
        }  
    }  
}

void output(const vector<int>& c)
{
            for (int i = 0; i < c.size(); ++i)  
            {     
                cout << c[i];  
            }  
            cout <<endl;
}

int main()
{
    vector<int> a, b, d, ans;
    cin>>n;
    if (n < 3)
    {
        cout<<"-1"<<endl;
    }
    else if (n == 3)
    {
        cout<<"210"<<endl;
    }
    else
    {
        d.reserve(3);
        d.push_back(2);
        d.push_back(1);
        d.push_back(0);
    
        a.reserve(1);
        a.push_back(1);
        b.reserve(1);
        vector<int> c;
        c.reserve(1);
        c.push_back(0);
        bool flag = true;
        int index = 0;
 
        while (flag)
        {

            b.clear();
            if (index == 0)
            {
                b.push_back(2);
            }
            else if (index == 1)
            {
                b.push_back(3);
            }
            else if (index == 2)
            {
                b.push_back(5);
            }
            else if (index == 3)
            {
                b.push_back(7);
            }


	        multiply(a, b, c);
           //if (index == 3) break; 
        
            ans.clear();
            ans.reserve( c.size()+2 );
            
            for (int i = 0; i < c.size()+2; ++i)
            {
                ans.push_back(0);
            }

	        multiply(d, c, ans);
            
            output(d);
            output(c);
            output(ans);
            if (ans.size() == n)
            {
                flag = false;
                break;
            }
            else if (ans.size() > n)
            {
                break;
            }

            index += 1;
            index = index % 4;
            a.clear();
            a.reserve(c.size());
            for (int i = 0; i < c.size(); ++i)  
            {     
                a.push_back( c[i] );  
            }  

            c.clear();
            c.reserve(a.size());
            for (int i = 0; i < a.size(); ++i)  
            {     
                c.push_back(0);
            }  
        }

        if (flag == true)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            //print the result  
            for (int i = 0; i < c.size(); ++i)  
            {     
                cout << c[i];  
            }  
            cout <<endl;
        }
    }
    return 0;
}

