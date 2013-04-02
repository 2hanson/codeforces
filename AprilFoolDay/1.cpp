#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#define LL long long
using namespace std;

vector<string> ps;

void makeps()
{
    ps.push_back("Washington");
    ps.push_back("Adams");
    ps.push_back("Jefferson");
    ps.push_back("Madison");
    ps.push_back("Monroe");
    ps.push_back("Adams");
    ps.push_back("Jackson");
    ps.push_back("Van Buren");
    ps.push_back("Harrison");
    ps.push_back("Tyler");
    ps.push_back("Polk");
    ps.push_back("Taylor");
    ps.push_back("Fillmore");
    ps.push_back("Pierce");
    ps.push_back("Buchanan");
    ps.push_back("Lincoln");
    ps.push_back("Johnson");
    ps.push_back("Grant");
    ps.push_back("Hayes");
    ps.push_back("Garfield");
    ps.push_back("Arthur");
    ps.push_back("Cleveland");
    ps.push_back("Harrison");
    ps.push_back("Cleveland");
    ps.push_back("McKinley");
    ps.push_back("Roosevelt");
    ps.push_back("Taft");
    ps.push_back("Wilson");
    ps.push_back("Harding");
    ps.push_back("Coolidge");
    ps.push_back("Hoover");
    ps.push_back("Roosevelt");
    ps.push_back("Truman");
    ps.push_back("Eisenhower");
    ps.push_back("Kennedy");
    ps.push_back("Johnson");
    ps.push_back("Nixon");
    ps.push_back("Ford");
    ps.push_back("Carter");
    ps.push_back("Reagan");
}

int main()
{
    ps.clear();
    makeps();
    int a;
    while (cin>>a)
    {
        cout<<ps[a-1]<<endl;
    }
    return 0;
}

