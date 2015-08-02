#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;

class BearPlaysDiv2
{
private:
	bool memo[1501][1501];
	int total;
public:
	void recur(int x, int y)
	{
		int z = total - x - y;
		int arr[3] {x,y,z};
		sort(arr, arr+3);
		x = arr[0];
		y = arr[1];
		z = arr[2];
		if (memo[x][y]) return;
		memo[x][y] = 1;
		if (x != y)
			recur(x*2, y-x);
		if (x != z)
			recur(x*2, z-x);
		if (y != z)
			recur(y*2, z-y);
		return;
	}

	string equalPiles(int A, int B, int C)
	{
		memset(memo, 0, sizeof(memo[0][0])*1501*1501);
		total = A + B + C;
		if (total % 3 != 0)
			return "impossible";
		int temp[3] = {A,B,C};
		sort(temp, temp+3);
		recur(temp[0],temp[1]);
		if (memo[total/3][total/3] == 1)
			return "possible";
		else
			return "impossible";
	}
};

int main()
{
	BearPlaysDiv2 obj;
	string ans= obj.equalPiles(30, 60 ,90);
	cout << "Ans is " << ans;
	return 0;
}