// SRM 441 div2 250.

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class DifferentStrings
{
public:
    int minimize(string a, string b)
    {
        int sizea = a.size();
        int sizeb = b.size();
        int global_min = 100;
        for (int i = 0; i <= sizeb - sizea; i++)
        {

            int countt = 0;
            for (int j = i; j < sizeb; j++)
            {
                if (a[j-i] != b[j])
                    countt++;
            }
            if (countt < global_min)
            {
                global_min = countt;
            }
        }
        return global_min;
    }
};
