#include<iostream>
using namespace std;

class QuadraticLaw
{
public:
    long getTime(long d)
    {
        long start = 0;
        long result = 0;
        while (true)
        {
            if (result > d)
            {
                return start - 1;
            }
            result = result + (start + 1)*2;
            start++;
        }
    }
};


int main()
{
    QuadraticLaw a;
    cout << a.getTime(50);
}
