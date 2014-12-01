// SRM429. Slight bug in code. Works for all examples except the one mentioned in main. answer off by 1.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class TimeTravellingGardener
{
public:
    pair<float, float> line(vector<int> dist, vector<int> height, int a, int b)
    {
        float m;
        if (a == b)
            m = 0;
        else
            m = (1.0*(height[a] - height[b]))/((dist[a] - dist[b])*1.0);
        float c = height[a] - m*dist[a];
        cout << " for tree x and tree y equal to " << a << "  " << b << "  ";
        cout << "returning m and c as " << m <<  "  " << c  << endl;
        cout << "tree distances and heights respectively are " << dist[a] << "  " << dist[b] << "  " << height[a] << "  " << height[b] << endl;
        return make_pair(m,c);
    }

    int on_line(int x, int y, float m, float c)
    {
        cout << " for dist and height equal to " << x << "  " << y << "  ";
        cout << "y - mx - c = " << y - m*x - c << endl;
        float a = y - m*x - c;
        a = round(a);
        if (a == 0)
            return 1;
  //      if (y == m*x + c)
  //          return 1;
        else if (y < m*x + c)
            return -1;
        else if (m*x + c < 0)
            return -1;
        else
            return 0;
    }

    void print(vector<int> a)
    {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << "  ";
        cout << endl;
    }

    int determineUsage(vector<int> distance, vector<int> height)
    {
        vector<int> dist_norm;
        if (distance.size() == 1)
            return 0;
        dist_norm.push_back(0);
        dist_norm.push_back(distance[0]);
        for (int i = 1; i < distance.size(); i++)
        {
            dist_norm.push_back(distance[i] + dist_norm[i]);
        }
        cout << "the distance vector is ";
        print(distance);
        cout << endl;
        cout << "the normalised distance vector is ";
        print(dist_norm);
        cout << endl;
        int globalc = 0;
        int localc = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i; j < height.size(); j++)
            {
                pair<float, float> line_parameters = line(dist_norm, height, i, j);
                float m = line_parameters.first;
                float c = line_parameters.second;
                localc = 0;
                for (int k = 0; k < height.size(); k++)
                {
                    int df = on_line(dist_norm[k], height[k], m, c);
                    cout << "output of online is " << df << endl;
                    if (df == 1)
                    {
                        localc++;
                        cout << "inc localc for k equal to " << k << endl;
                    }
                    else if (df == -1)
                    {
                        localc = 0;
                        break;
                    }
                }
                cout << "for i and j equal to " << i << "  " << j << "  localc is " << localc << endl;
                cout << "globalc is " << globalc << "  and localc is  " << localc << endl << endl;
                globalc = max(globalc, localc);
            }
        }
        return height.size() - globalc;
    }
};

int main()
{
vector<int> distance;
distance.push_back(476);
distance.push_back(465);
distance.push_back(260);
distance.push_back(484);
vector<int> height;
height.push_back(39);
height.push_back(13);
height.push_back(8);
height.push_back(72);
height.push_back(80);
TimeTravellingGardener a;
//pair<int, int> b = a.line(norm ,height, 0, 1);
//cout << b.second;
cout << endl << a.determineUsage(distance, height);
return 0;

}
