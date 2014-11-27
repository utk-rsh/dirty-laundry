// SRM 322 div2 1000.

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BattleshipChecker
{
public:
    bool checkDiag( vector<string> board)
    {
        for (int i = 1; i < board.size() - 1; i++)
            for (int j = 1; j < board.size() - 1; j++)
            {

                string a = board[i];
                char b = a[j];
                string aa = board[i + 1];
                char bb = aa[j+1];
                string qq = board[i];
                char ww = qq[j+1];
                string q = board[i + 1];
                char w = q[j];
                if (((b == 'X') && (bb == 'X')) || ((w == 'X') && (ww == 'X')))
                {
                    return  false;
                }
            }
        return true;
    }

    int floodCheck(vector<string>  board, int x, int y, bool** visited)
    {
        if ((x < 0) || (x >= board.size()) || (y < 0) || (y >= board.size()) || (visited[x][y] == 1) || (board[x][y] == '.')) return 0;
        else
        {
            visited[x][y] = 1;
            return 1 + floodCheck(board, x+1, y, visited) + floodCheck(board, x-1,y,visited) + floodCheck(board,x, y-1,visited) + floodCheck(board,x,y+1,visited);
        }
    }

    string checkBoard(vector<string> board)
    {
        if (checkDiag(board) == 0)
            return "REJECTED";
        int c4 = 1*4;
        int c3 = 2*3;
        int c2 = 3*2;
        int c1 = 4*1;
        int check = c4 + c3 + c2 + c1;
        int total = 0;
        bool **visited = new bool*[10];
        for (int i = 0; i < 10; i++)
            visited[i] = new bool[10];
        cout << "YAHAAN" << endl;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                cout << "i and j are " << i  << "  " << j << endl;;
                int temp = floodCheck(board, i, j, visited);
                cout << "temp is  " << temp << endl;
                if (temp == 0) continue;
                else if (temp == 4) c4--;
                else if (temp == 3) c4--;
                else if (temp == 2) c4--;
                else if (temp == 1) c4--;
                else return "REJECTED";
                total += temp;
            }
        cout << "total was " << total << endl;
        if (total != check)
            return "REJECTED";
        cout << "REACHED ALIVE HERE" << endl;
        int RE[10] = {0};
        int CE[10] = {0};
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                string a = board[i];
                char b = a[j];
                if (b == 'X')
                {
                    CE[j] = 1;
                    RE[i] = 1;
                }
            }
        }
        int ans = 20;
        for (int i = 0; i < 10; i++)
        {
            if (CE[i] == 1)
                ans--;
            if (RE[i] == 1)
                ans--;
        }
        cout << "ans is " << ans << endl;
        string out = "ACCEPTED, ";
        out += to_string(ans);
        out += " POINTS";
        return out;
    }
};
