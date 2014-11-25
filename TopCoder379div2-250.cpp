// TopCoder SRM 379 Div2 250

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class DownloadingFiles
{
public:
    // extracts the cth integer from a string
    int extract(string input, int num)
    {
        string ans = "";
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ' ')
            {
                num--;
                if (num == 0)
                    break;
                ans = "";
            }
            else
                ans += input[i];
        }
        return atoi(ans.c_str());
    }

    double actualTime(vector<string> s)
    {
        double total_size = 0;
        double total_speed = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int temp = extract(s[i], 1);
            int speed = extract(s[i], 2);
            total_size += speed*temp;
            total_speed += temp;
            cout << "total size is " << total_size << endl;
            cout << "total speed is " << total_speed << endl;
        }
        return total_size/total_speed;
    }
};
