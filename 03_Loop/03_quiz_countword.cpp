#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int same = 1;
    cin >> a;
    for (int i = 0; i < a.length(); i++) //know that do a.length-1 times
    {
        if (a[i] == a[i + 1])
        {
            same++;
        }
        else
        {
            cout << a[i] << " " << same << " ";
            same = 1;
        }
    }
}