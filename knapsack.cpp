#include <iostream>
using namespace std;

int knapsack(int n, int weights[], int profits[], int weight)
{
    int arr[n + 1][weight + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (j >= weights[i - 1])
                arr[i][j] = max(arr[i - 1][j], profits[i - 1] + arr[i - 1][j - weights[i - 1]]);
            else
                arr[i][j] = arr[i - 1][j];
        }
    }

    return arr[n][weight];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int weights[n];
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int profits[n];
    for (int i = 0; i < n; i++)
        cin >> profits[i];

    int weight;
    cin >> weight;

    cout << knapsack(n, weights, profits, weight);

    return 0;
}
