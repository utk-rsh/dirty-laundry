/*
 Given a number, return the number of set bits of the number if binary representation
of the number is a palindrome, else return ­1.
Condition : You can’t use array or any other data structure.
Eg . Input
  37
        Output   ­1

        Input
 165
        Output    4
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int count_bits1(int a)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((a >> i) & 1) == 1)
            ans++;
    }
    return ans;
}

int length(int a)
{
    int pos = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((a >> i) & 1) == 1)
            pos = i;
    }
    return pos;
}


int main()
{
int input = 165;
int no1 = count_bits1(input);
int len = length(input);
for (int i = 0; i <= len/2; i++)
{
    //cout << "for i equal to  " << i << " the bits are " << ((input >> i) & 1) << "  " << ((input >> (len - i)) & 1) << endl;
    if (((input >> i) & 1) == ((input >> (len - i)) & 1))
        ;
    else
        return -1;
}
return no1;
}
