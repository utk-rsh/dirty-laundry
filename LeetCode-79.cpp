#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>


using namespace std;

class Solution {
public:
    bool check(vector<vector<char>> &board, vector<vector<char>> &visited, int i, int j, string word, int wc)
    {
        if ((i < 0) || (i >= board.size()) || (j < 0) || (j >= board[0].size()))
            return false;
  //      cout << "board[i][j] is " << board[i][j] << " and word[wc] is " << word[wc] << endl;
  //      cout << "i j is " << i << " " << j << " and visited ij is " << visited[i][j] << endl;
        if (visited[i][j] == '1')
            return false;
        if (board[i][j] != word[wc])
            return false;
        visited[i][j] = '1';
        if (wc == word.length() - 1)
            return true;
        bool c = ((check(board,visited,i+1,j,word,wc+1)) || (check(board, visited, i-1, j, word, wc+1)) || (check(board,visited,i,j-1,word,wc+1)) || (check(board,visited,i,j+1,word,wc+1)));
        if (c == 0)
            visited[i][j] = '0';
        return c;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<char>> visited = board;
        int to_empty = 1;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (to_empty == 1)
                {
                    for (int k = 0; k < visited.size(); k++)
                        fill(visited[k].begin(), visited[k].end(), '0');
                    to_empty = 0;
                }
                bool ans = 0;
    //            cout << "MAIN loop: i j is " << i << " " << j << " and board ij is " << board[i][j] << endl;
                if (board[i][j] == word[0])
                    {
                        to_empty = 1;
      //                  cout << "!!!! board being checked for i and j eqaul to  " << i <<  " " << j << " and visited ij equal to " << visited[i][j] << endl;
                        ans = check(board, visited, i, j, word, 0);
                    }
                if (ans == 1)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
vector<char> inside;
inside.push_back('a');
inside.push_back('b');
inside.push_back('c');
inside.push_back('e');
vector<vector<char>> container;
container.push_back(inside);
inside.clear();
inside.push_back('s');
inside.push_back('f');
inside.push_back('e');
inside.push_back('s');
container.push_back(inside);
inside.clear();
inside.push_back('a');
inside.push_back('d');
inside.push_back('e');
inside.push_back('e');
container.push_back(inside);
Solution obj;
cout << obj.exist(container, "abceseeefs") << endl;
return 0;
}
