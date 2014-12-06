#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class EllysDirectoryListing
{
public:
vector<string> getFiles(vector<string> files)
{
    int to = files.size() - 1;
    if ((files[to - 1] == ".") && (files[to] == ".."))
        return files;
    if ((files[to - 1] == "..") && (files[to] == "."))
        return files;
    for (int i = 0; i < files.size(); i++)
    {
        cout << "i is " << i << " with element value as " << files[i] << endl;
        if ((files[files.size() - 1] == ".") && (files[files.size()-2] == ".."))
            return files;
        if ((files[files.size() - 1] == "..") && (files[files.size()-2] == "."))
            return files;
        if (i == files.size() - 2)
            return files;
        if ((files[i] == ".") || (files[i] == ".."))
        {
            string temp = files[i];
            files[i] = files[to];
            files[to] = temp;
            i = 0;
            to--;
        }
    }
    return files;

}

};
