#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

#define INT_MAX 2147483647
using namespace std;

void print_seq(int n, int k)
{
    int counter = 0;
    int value = 1;
    while (counter < n)
    {
        counter++;
        cout << value << " ";
        value++;
        value = value%(k+1);
        if (value == 0)
            value = 1;
    }
    cout << endl;
    return;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> pebbles;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pebbles.push_back(temp);
    }
    int maxx = 0;
    int minn = 1000;
    for (int i = 0; i < n; i++)
    {
        maxx = max(maxx, pebbles[i]);
        minn = min(minn, pebbles[i]);
    }
    if (maxx - k > minn)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        print_seq(pebbles[i],k);
    return 0;
}
