// https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    ifstream in ("input");
    ofstream out;
    out.open ("output.txt");
    string line;
    int count = 0;
    if (in.is_open())
    {
        string tt;
        getline(in, tt);
        int T = atoi(tt.c_str());
        while (getline (in, line))
        {
            if (T == 0)
            {
                out << line << "\n";
                while (getline(in, line))
                    out << line << "\n";
                break;
            }
            T--;
            count++;
            if (line == "0")
            {
                out << "Case #" << count << ": 0 0\n";
                continue;
            }
            char temp;
            string cc = line;
            //For smaller number
            char gmin = '9';
            for (int i = 0; i < line.length(); i++)
                if (line[i] < gmin)
                    gmin = line[i];
            int zero_check = 0;
            int other = 1;
            for (int i = 1; i < line.length(); i++)
                if ((line[i] < line[0]) && (line[i] != '0'))
                    other = 0;
            if ((gmin == '0') && (other == 1))
                zero_check = 1;
            int small = 0;
            while (line[small] == gmin)
                small++;
            gmin = '9';
            int mini = small;
            for (int i = small; i < line.length(); i++)
            {
                if ((line[i] <= gmin) && (line[i] != '0'))
                {
                    gmin = line[i];
                    mini = i;
                }
            }
            if (zero_check == 1)
            {
                int latest = 0;
                for (int i = 0; i < line.length(); i++)
                    if (line[i] == '0')
                        latest = i;
                mini = 1;
                small = latest;
            }
            temp = line[mini];
            line[mini] = line[small];
            line[small] = temp;
            out << "Case #" << count << ": " << line << " ";
            line[small] = line[mini];
            line[mini] = temp;
            // For larger number
            char gmax = '0';
            for (int i = 0; i < line.length(); i++)
                if (line[i] > gmax)
                    gmax = line[i];
            int big = 0;
            while (line[big] == gmax)
                big++;
            gmax = '0';
            int maxi = big;
            for (int i = big; i < line.length(); i++)
            {
                if (line[i] >= gmax)
                {
                    gmax = line[i];
                    maxi = i;
                }
            }
            temp = line[maxi];
            line[maxi] = line[big];
            line[big] = temp;
            out << line << "\n";
            line[big] = line[maxi];
            line[maxi] = temp;
        }
        in.close();
    }
    out.close();
    return 0;
}
