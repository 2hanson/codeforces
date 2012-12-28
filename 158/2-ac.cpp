#include <iostream>
#include <string>
#include <vector>
using namespace std;

class yuDate
{
    public:
        yuDate(string year, string month, string day, int numcount)
        {
            y = year;
            m = month;
            d = day;
            nc = numcount;
        }
        
        string y;
        string m;
        string d;
        int nc;
};

int ans = 0;
vector<yuDate> yuDates;
vector<string> years;
vector<string> months;
vector<string> splitStrs;
string pry;
//no leap year: month form 1-12: 31 days，29days，31days，30days，31days，30days，31days，31days，30days，31days，30days，31days
int DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void init()
{
    years.clear();
    years.push_back("2013");
    years.push_back("2014");
    years.push_back("2015");
    
    months.clear();
    months.push_back("01");
    months.push_back("02");
    months.push_back("03");
    months.push_back("04");
    months.push_back("05");
    months.push_back("06");
    months.push_back("07");
    months.push_back("08");
    months.push_back("09");
    months.push_back("10");
    months.push_back("11");
    months.push_back("12");
    yuDates.clear();
    ans = 0;
}

int days(const string &month)
{
    for (int i = 0; i < months.size(); ++i)
    {
        if (months[i].compare(month) == 0)
        {
            return DAYS[i];
        }
    }

    return 0;
}

bool isYear(const string &da)
{
    if (da.length() == 0)
    {
        return false;
    }

    for (int i = 0; i < years.size(); ++i)
    {
        if (years[i].compare(da) == 0)
        {
            return true;
        }
    }

    return false;
}

bool isMonth(const string &da)
{
    if (da.length() == 0)
    {
        return false;
    }

    for (int i = 0; i < months.size(); ++i)
    {
        if (months[i].compare(da) == 0)
        {
            return true;
        }
    }

    return false;
}

bool isDay(string &day, const string &da, const string &month)
{
    int len = da.length();
    if (len == 0)
    {
        return false;
    }

    int dayLimit = days(month);
    day = da[len-1];
    int val = day[0] - '0';

    for (int i = len-2; i >= 0; --i)
    {
        if (da[i] == '0' && val != 0)
        {
            day.insert(0, 1, da[i]);
            return true;
        }

        val = (da[i]-'0')*10 + val;
        if (val > dayLimit || val <= 0)
        {
            return false;
        }

        day.insert(0, 1, da[i]);
        
        return true;
    }

    return false;
}

void checkDate(const string & year, const string &month, const string &day)
{
    //ans
    bool flag = false;
    //cout<<year<<" "<<month<<" "<<day<<endl;
    for (int index = 0; index < yuDates.size(); ++index)
    {
        if (year.compare(yuDates[index].y) != 0)
        {
            continue;
        }
        if (month.compare(yuDates[index].m) != 0)
        {
            continue;
        }
        if (day.compare(yuDates[index].d) != 0)
        {
            continue;
        }

        ++yuDates[index].nc;
        if (yuDates[index].nc > yuDates[ans].nc)
        {
            ans = index;
        }

        flag = true;
        break;
    }

    if (flag == false)
    {
        yuDate* yut = new yuDate(year, month, day, 1);
        yuDates.push_back(*yut);
    }
}

void solve()
{
    for (int i = 1; i < splitStrs.size()-1; ++i)
    {
        int mi = i;
        if (mi<=0 || isMonth(splitStrs[mi]) == false)
        {
            continue;
        }
        
        int yi = mi+1;
        if(isYear(splitStrs[yi].substr(0,4)) == false)
        {
            continue;
        }

        int di = mi - 1;
        string day;
        if (di<0 || isDay(day, splitStrs[di], splitStrs[mi]) == false)
        {
            continue;
        }

        checkDate(splitStrs[yi].substr(0, 4), splitStrs[mi], day);
    }
}

void output()
{
    if (ans < yuDates.size())
    {
        cout<<yuDates[ans].d<<"-"<<yuDates[ans].m<<"-"<<yuDates[ans].y<<endl;
    }

}

int main()
{
    init();
    cin>>pry;
    int st = 0;
    int end = 0;
    bool flag = true;
    while (flag)
    {
        end = pry.find_first_of('-', st);
        if (end == string::npos)
        {
            end = pry.length();
            flag = false;
        }

        string sub = pry.substr(st, end-st);
        splitStrs.push_back(sub);
        st = end+1;
    }

    solve();
    output();
    
    return 0;
}

