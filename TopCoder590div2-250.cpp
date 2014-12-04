#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class FoxAndGomoku
{
public:
string win(vector<string> board)
    {
    int cont = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
       {
            if (board[i][j] == 'o')
                cont++;
            else
                cont = 0;
            if (cont == 5)
                return "found";
        }
        cont = 0;
    }
    cout << "No horizontal" << endl;
    cont = 0;
    for (int i = 0; i < board.size(); i++)
    {
       for (int j = 0; j < board.size(); j++)
       {
            if (board[j][i] == 'o')
                cont++;
            else
                cont = 0;
            if (cont == 5)
                return "found";
       }
       cont = 0;
    }
    cout << "No vertical" << endl;
    for (int i = 0; i < board.size(); i++)
    {    for (int j = 0; j < board.size() - 4; j++)
        {
            if (board[i][j] == 'o')
            {
                if ((i < board.size() - 4) && (board[i+1][j+1] == 'o') && (board[i+2][j+2] == 'o') && (board[i+3][j+3] == 'o') && (board[i+4][j+4] == 'o'))
                    return "found";
                if ((i >= 4)  && (board[i-1][j+1] == 'o')  && (board[i-2][j+2] == 'o')  && (board[i-3][j+3] == 'o')  && (board[i-4][j+4] == 'o'))
                    return "found";
            }
        }
    }
    return "not found";
    }
};
