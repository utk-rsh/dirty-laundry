#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class EllysNumberGuessing
{
public:
int getNumber (vector<int> guesses, vector<int> answers)
{
    vector<int> pos;
    int conf = -1;
    if (guesses[0] + answers[0] < 1000000000)
        pos.push_back(guesses[0]+answers[0]);
    else
        conf = guesses[0] - answers[0];
    if (guesses[0] - answers[0] > 0)
        pos.push_back(guesses[0] - answers[0]);
    else
        conf = guesses[0] + answers[0];
    for (int i = 1; i < guesses.size(); i++)
    {
        cout << "pos size is " << pos.size() << " and 0 element is " << pos[0] << endl;
        if (conf != -1)
        {
            pos.erase(pos.begin(), pos.end());
            pos.push_back(conf);
        }
        if (pos.size() == 1)
        {
            if ((guesses[i] + answers[i] == pos[0]) || (guesses[i] - answers[i] == pos[0]));
            else
                return -2;
        }
        else
        {
           if ((guesses[i] + answers[i] == pos[0]))
           {
                cout << "first if" << endl;
                conf = pos[0];
                pos.erase(pos.begin(), pos.end());
                pos.push_back(conf);
           }
            else if (guesses[i] + answers[i] == pos[1])
           {
                cout << "second if" << endl;
                conf = pos[1];
                pos.erase(pos.begin(), pos.end());
                pos.push_back(conf);
           }
            else if (guesses[i] - answers[i] == pos[0])
            {
                cout << "third if" << endl;
                conf = pos[0];
                pos.erase(pos.begin(), pos.end());
                pos.push_back(conf);
           }
           else if (guesses[i] - answers[i] == pos[1])
           {
                cout << "fourth if" << endl;
                conf = pos[1];
                pos.erase(pos.begin(), pos.end());
                pos.push_back(conf);
           }
           else
                return -2;
        }
    }
    return conf;
}
};
