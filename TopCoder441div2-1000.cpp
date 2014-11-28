// SRM 441 div2 1000.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class PerfectPermutationHard
{
public:
    bool check_permutation(vector<int> a)
    {
        int sizee = a.size();
        int* check = new int[sizee];
        for (int i = 0; i < sizee; i++)
            check[i] = 0;
        for (int i = 0; i < sizee; i++)
        {
            check[a[i]] = 1;
        }
        for (int i = 0; i < sizee; i++)
            if (check[i] != 1)
                return false;
        return true;
    }

void print(vector<int> a)
    {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " " ;
    cout << endl;
    }

vector<int> reorder(vector<int> p)
    {
        vector<int> main = p;
        sort(p.begin(), p.end());
        vector<int> toReturn;
        vector<int> toReturnChild;
        int difference = 1000;
        int gc = 0;
        do
        {
        cout << "inside do loop with global counter as " << gc << endl;
        gc++;
        vector<int> temp;
        for (int i = 0; i < p.size(); i++)
        {
            if (i == 0)
            {
                temp.push_back(0);

            }
            else
            {
                temp.push_back(p.at(temp.at(i-1)));
            }
        }
        if (check_permutation(temp) == 1)
        {
            int countt = 0;
            for (int i = 0; i < p.size(); i++)
                if (p[i] != main[i])
                    countt++;
            if (countt == difference)
            {
                if (temp < toReturnChild)
                {
                    toReturn = p;
                    toReturnChild = temp;
                }
            }
            if (countt < difference)
            {
                difference = countt;
                toReturn = p;
                toReturnChild = temp;
            }
        }
    } while (next_permutation(p.begin(), p.end()));

    return toReturn;
    }
};
