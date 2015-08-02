#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BearCheats
{
public:
	string eyesight(int a, int b)
	{
		bool flag = 0;
		while (a != 0)
		{
			int t1 = a%10;
			int t2 = b%10;
			a = a/10;
			b = b/10;
			if (t1 != t2 && flag == 0)
				flag = 1;
			else if (t1 != t2 && flag == 1)
				return "glasses";
		}
		return "happy";
	}
};

