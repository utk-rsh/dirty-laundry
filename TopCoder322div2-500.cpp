// SRM 322 div2 500. Submitted for 339 points.

#include<iostream>
#include<vector>

using namespace std;

class GroupWork
{
public:
    long long return_maxx(vector<int>* p, vector<int>* s)
    {
        long long maxx = 0;
        for (int i = 0; i < p->size(); i++)
        {
            if ((*s)[i] > maxx)
            {
                maxx = (*s)[i];
            }
        }
        return maxx;
    }

    long long return_maxxi(vector<int>* p, vector<int>* s)
    {
        long long maxx = 0;
        long long maxxi = 0;
        for (int i = 0; i < p->size(); i++)
        {
            if ((*s)[i] > maxx)
            {
                maxx = (*s)[i];
                maxxi = i;
            }
        }
        return maxxi;
    }


    long long bestGroup (vector<int> p, vector<int> s)
    {
        long long global_max = 0;
        long long number_of_people = 0;
        for (int i = 0; i < p.size(); i++)
        {
            long long maxx = return_maxx(&p, &s);
            long long maxxi = return_maxxi(&p, &s);
            long long temp = p[maxxi];
            long long current_prod = (number_of_people + temp)*maxx;
            if (current_prod > global_max)
                global_max = current_prod;
            number_of_people += temp;
            p.erase(p.begin() + maxxi);
            s.erase(s.begin() + maxxi);
            i--;
 /*           cout << "number of people was " << number_of_people << endl;
            cout << "maxx was " << maxx << endl;
            cout << "maxxi was " << maxxi << endl;
            cout << "temp was " << temp << endl;
            cout << "current_prod was " << current_prod << endl;
            cout << "global max is " << global_max << endl << endl << endl;
   */     }
        return global_max;
    }
};

int main()
{
vector<int> a;
a.push_back(1);
a.push_back(2);
a.push_back(1);
vector<int> b;
b.push_back(3);
b.push_back(5);
b.push_back(9);
GroupWork ii;
ii.bestGroup(a, b);
return 0;
}
