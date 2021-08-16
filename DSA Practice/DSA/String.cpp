#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int arr[10000008];

void ReverseString(string s)
{
    vector<string> TempVector;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            TempVector.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    TempVector.push_back(temp);

    for (int i = TempVector.size() - 1; i > 0; i--)
    {
        cout << TempVector[i] << ".";
    }
    cout << TempVector[0];
}

void Permute(string a, int left, int right)
{
    if (left == right)
    {
        cout << a << "\n";
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(a[left], a[i]);

            Permute(a, left + 1, right);

            swap(a[left], a[i]);
        }
    }
}

void Palindrome(string s)
{
    int i = 0;
    int n = s.size() - 1;
    int flag = 1;
    while (i < n)
    {
        if (s[i] != s[n])
        {
            flag = 0;
            break;
        }
        else
        {
            i++;
            n--;
        }
    }
    if (flag == 0)
    {
        cout << "String is not palindrome";
    }
    else
    {
        cout << "String is Palindrome";
    }
}

void LongestSubStr(string s)
{
    int max_length = 1;
    int start = 0;

    int len = s.size();

    int low, high;

    // One by one checking every character of longest even length substring i-1 and i
    for (int i = 1; i < len; i++)
    {
        int low = i - 1;
        int high = i;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > max_length)
            {
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }

        // Find the longest Palindrome Substring for odd length as centre i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > max_length)
            {
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }
    }

    cout << s.substr(start, max_length);
}

void RestrictCandyCrush(string s, int k)
{
    string ans = "";
}

void liststring(string s)
{
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ',')
        {
            temp += s[i];
        }
        else
        {
            // cout << temp<<"\n";
            int count = 0;
            for (int j = 0; j < temp.size(); j++)
            {
                if (temp[j] == 'a' || temp[j] == 'e' || temp[j] == 'i' || temp[j] == 'o' || temp[j] == 'u')
                {
                    count++;
                }
            }
            if (count == 0)
            {
                cout << temp << "\n";
                temp = " ";
            }
            else
            {
                temp = " ";
            }
        }
    }
}

int length(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    int SmallStringLenth = length(str + 1);
    return 1 + SmallStringLenth;
}

void RemoveX(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] != 'x')
    {
        RemoveX(str + 1);
    }
    else
    {
        int i = 1;
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        str[i - 1] = str[i];
        RemoveX(str);
    }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    string s;
    cin >> s;
    Permute(s, 0, s.size()-1);
    // cout << s << "\n";
    // RemoveX(s);
    // cout << s << "\n";
    // cout<<s;
    // liststring(s);
    // getline(cin, s);
    // cout<<s;
    // ReverseString(s);
    // Palindrome(s);
    // LongestSubStr(s);
    // RestrictCandyCrush(s, 2);
    return 0;
}
