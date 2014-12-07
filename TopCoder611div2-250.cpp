#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class InterestingNumber
{
public:
string isInteresting(string x)
{
int arr[10] = {0};
for (int i = 0; i < x.length(); i++)
{
    char nS = x[i];
    arr[nS - 48]++;
}
cout << "a";
for (int i = 0; i < 10; i++)
{
    if ((arr[i] != 0) && (arr[i] != 2))
        return "Not interesting";
}
cout << "b";
cout << endl;
for (int i = 0 ; i < 10; i++)
    cout << arr[i] << "  ";
cout << endl;
for (int i = 0; i < 10; i++)
{
    if (arr[i] != 0)
    {
        int c = 0;
        int check = 0;
        for (int j = 0; j < x.length(); j++)
        {
            char ns = x[j];
            int number = ns - 48;
            if (check != 0)
                c++;
            if (number == i)
            {
                    check = (check+1)%2;
                    if (c > 0)
                        c--;
            }
            cout << "number is " << number << " c is " << c << " and check is " << check << " and j is " << j << " and i is " << i <<  endl;
        }
        arr[i] = c;
    }
}
cout << "c";
cout << endl;
for (int i = 0 ; i < 10; i++)
    cout << arr[i] << "  ";
cout << endl;

for (int i = 0; i < 10; i++)
{
    if (arr[i] != 0)
    if (arr[i] != i)
        return "Not interesting";
}
cout << "d";
return "Interesting";

}

};

int main()
{
string input = "2002";
InterestingNumber a;
cout << "ANSWER IS " << a.isInteresting(input);
return 0;
}
