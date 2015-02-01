#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

#define INT_MAX 2147483647
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<long long>> matrix;
    vector<long long> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long ti;
            cin >> ti;
            temp.push_back(ti);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    long long maxx = 0;
    for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                maxx = max(maxx,matrix[i][j]);
    long long k = -1;
    for (int i = 0; i < n-1; i++) // checking column wise differences
    {
        long long it = matrix[i][0] - matrix[i+1][0];
        for (int j = 0; j < m; j++)
        {
    //        cout << "difference is " << matrix[i][j] - matrix[i+1][j] << " and it is " << it << " i j is " << i << j << endl;
            if (matrix[i][j] - matrix[i+1][j] != it && k != -1 && matrix[i][j] - matrix[i+1][j] != it + k && matrix[i][j] - matrix[i+1][j] != it - k)
            {
                cout << "NO" << endl;
                return 0;
            }
            if (matrix[i][j] - matrix[i+1][j] != it && k == -1)
            {
                k = abs(it - (matrix[i][j] - matrix[i+1][j]));
    //            cout << "SETTING K AS " << k << endl;
            }
        }
    }
    cout << endl << endl;
    for (int j = 0; j < m-1; j++)
    {
        long long it = matrix[0][j] - matrix[0][j+1];
        for (int i = 0; i < n; i++)
        {
  //           cout << "difference is " << matrix[i][j] - matrix[i][j+1] << " and it is " << it << " i j is " << i << j << endl;

            if (matrix[i][j] - matrix[i][j+1] != it && k != -1 && matrix[i][j] - matrix[i][j+1] != it + k && matrix[i][j] - matrix[i][j+1] != it - k)
            {
                cout << "NO" << endl;
                return 0;
            }
            if (matrix[i][j] - matrix[i][j+1] != it && k == -1)
                k = abs(it - (matrix[i][j] - matrix[i][j+1]));
        }
    }
    if (k == -1)
        k = maxx+1;
  //  cout << "YAHAAN!!" << endl;
    vector<long long> a;
    a.push_back(0);
    for (int i = 1; i < n; i++)
    {
        long long te = matrix[i][0] - matrix[i-1][0] + a[i-1];
        if (te == k)
        {
          //  cout << "te is " << te << " .setting no" << endl;
            cout << "NO" << endl;
            return 0;
        }
        if (te < 0)
            te += k;
        a.push_back(te);
    }
    vector<long long> b;
    b.push_back(matrix[0][0]);
    for (int i = 1; i < m; i++)
    {
        long long te = matrix[0][i] - matrix[0][i-1] + b[i-1];
        if (te == k)
        {
         //   cout << "te is " << te << " .setting no" << endl;
            cout << "NO" << endl;
            return 0;
        }
        if (te < 0)
            te += k;
        b.push_back(te);
    }
    cout << "YES" << endl << k << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}
