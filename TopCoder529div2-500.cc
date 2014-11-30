#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class KingSort
{
public:
    int value(string a)
    {
        int sizea = a.length();
        int counter = 0;
        int vala = 0;
        for (counter = 0; counter < sizea; counter++)
        {
            if (a[counter] == 'I')
            {
                if (counter + 1 < sizea)
                {
                    if (a[counter+1] == 'V')
                        vala += 4;
                    if (a[counter+1] == 'X')
                        vala += 9;
                    else
                        vala += 1;
                }
                else
                    vala += 1;
            }
            if (a[counter] == 'V')
            {
                if (counter > 0)
                {
                    if (a[counter - 1] == 'I');
                    else
                        vala += 5;
                }
                else
                    vala += 5;
            }
            if (a[counter] == 'X')
            {
                if (counter > 0)
                {
                    if (a[counter - 1] == 'I')
                        continue;
                }
                if (counter + 1 < sizea)
                {
                    if (a[counter + 1] == 'L')
                        continue;
                }
                vala += 10;
            }
            if (a[counter] == 'L')
            {
                if (counter > 0)
                {
                    if (a[counter - 1] == 'X')
                        vala += 40;
                }
                vala += 50;
            }
        }
        return vala;
    }
    string get_number(string a)
    {
        string ans;
        int check = 0;
        for (int i = 0; i < a.length(); i++)
        {
  //          cout << "ai is " << a[i] << " with i as " << i << endl;
            if (check == 0);
            else
            {
    //            cout << a[i] << " being added to answer" << endl;
                ans += a[i];
            }

            if (a[i] == ' ')
                check = 1;
        }
        return ans;
    }

    string get_name(string a)
    {
        string ans;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == ' ')
                return ans;
            ans += a[i];
        }
    }

    vector<string> getSortedList (vector<string> kings)
    {
        vector<string> output;
        for (int i = 0; i < kings.size(); i++)
        {
            string name = get_name(kings[i]);
            string number = get_number(kings[i]);
            int j = 0;
            for (j = 0; j <  output.size(); j++)
            {
                if (name < get_name(output[j]))
                    {cout << name << " < " << get_name(output[j]) << endl; break;}
                else if (name > get_name(output[j]))
                    {cout << name << " > " << get_name(output[j]) << endl;}

                else if (value(number) < value(get_number(output[j])))
                    {cout << number << " < " << get_number(output[j]) << endl; break;}
                else
                    {cout << number << " > " << get_number(output[j]) << endl; }
                cout << endl;
            }
            output.insert(output.begin() + j, kings[i]);
       }
      cout << "output 0 is " << output[0] << endl;
      cout << "output 1 is " << output[1] << endl;
      return output;
    }
};

int main()
{
KingSort a;
cout << a.value("VIII");
return 0;
}
