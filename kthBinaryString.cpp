/*
Two integers n, k are given s.t. 1<k<2^n. Find the kth ranked binary string of length n out of all
the possible strings such that they are sorted according to the following criteria:
lower number of 1s in the binary representation => lower rank
in case of ties, number with lower value(decimal) gets lower rank.

e.g. n=3, k=5
output = 011
how?
all possible binary strings of length 3 in sorted order are:
000, 001, 010, 100, 011, 101, 110, 111
print the 5th string. :)
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>

using namespace std;

int count1(int a, int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (((a >> i) & 1)== 1)
            counter++;
    }
    return counter;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int high = 1 << n;
    int* arr = new int[high];
    for (int i = 0; i < high; i++)
    {
        arr[i] = count1(i, n);
    }
    for (int i = 0; i < high; i++)
        cout << arr[i] << " ";
    cout << endl << endl;
    int countt = 0;
    int c = countt;
    int target = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < high; i++)
    {
        c = countt;
        for (j = 0; j < high; j++)
        {
            if (arr[j] == target)
                countt++;
        }
        if (countt > k)
            break;
        if (countt == k)
        {
            c = countt;
            break;
        }
        target++;
    }
    if (c == k)
    {
        int last = 0;
        for (int i = 0; i < high; i++)
        {
            if (arr[i] == target)
                last = i;
        }
        return last;
    }
    cout << "target is " << target << endl;
    cout << "c is " << c << endl;
    for (i = 0; i < high; i++)
    {
        if (arr[i] == target)
            c++;
        if (c == k)
            return i;
    }
    return -1;
}
