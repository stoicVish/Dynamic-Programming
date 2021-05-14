#include <iostream>
using namespace std;

int lcs(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    int arr[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
        }
    }
    return arr[n][m];
}

int main(int argc, char const *argv[])
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2);
    return 0;
}
