#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n, count = 0;
    cin >> n;
    int in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n - 2; i++) // i<n-2!! or it will compare in[n+1],[n+2] and error
    {
        if ((in[i] < in[i + 1]) && (in[i + 1] > in[i + 2]))
        {
            count++;
        }
    }
    cout << count;
}