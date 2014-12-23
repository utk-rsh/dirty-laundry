#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class ChooseTheBestOne
{
public:
int countNumber(int N)
{
    vector<int> players;
    for (int i = 1; i < N+1; i++)
        players.push_back(i);
    int start = 0;
    int removed = 0;
    int playing = N;
    for (int i = 1; i < N; i++)
    {
        long long check = i*i*i - 1;
        long long rem = check%playing;
        cout << "turn no is  " << i << endl;
        cout << "check is  " << check << endl;
        cout << "rem is  " << rem << endl;
        cout << "player being removed is " << players[(start+rem)%playing] << endl;
        cout << "next player being started from is " <<  players[(start+rem+1)%playing] << endl;
        cout << endl;
        players.erase(players.begin()+(start+rem)%playing);
        start = (start+rem)%playing;
        removed++;
        playing--;
    }
    return players[0];
}
};
