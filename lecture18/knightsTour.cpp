#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > getNeighbours(int curr[]) {
    int x = curr[0];
    int y = curr[1];
    vector<vector<int> > ans;

    // First move: x + 2, y + 1
    if (x <= 5 && y <= 6) {
        vector<int> temp;
        temp.push_back(x + 2);
        temp.push_back(y + 1);
        ans.push_back(temp);
    }

    // Second move: x + 2, y - 1
    if (x <= 5 && y >= 1) {
        vector<int> temp;
        temp.push_back(x + 2);
        temp.push_back(y - 1);
        ans.push_back(temp);
    }

    // Third move: x - 2, y + 1
    if (x >= 2 && y <= 6) {
        vector<int> temp;
        temp.push_back(x - 2);
        temp.push_back(y + 1);
        ans.push_back(temp);
    }

    // Fourth move: x - 2, y - 1
    if (x >= 2 && y >= 1) {
        vector<int> temp;
        temp.push_back(x - 2);
        temp.push_back(y - 1);
        ans.push_back(temp);
    }

    // Fifth move: x + 1, y + 2
    if (x <= 6 && y <= 5) {
        vector<int> temp;
        temp.push_back(x + 1);
        temp.push_back(y + 2);
        ans.push_back(temp);
    }

    // Sixth move: x + 1, y - 2
    if (x <= 6 && y >= 2) {
        vector<int> temp;
        temp.push_back(x + 1);
        temp.push_back(y - 2);
        ans.push_back(temp);
    }

    // Seventh move: x - 1, y + 2
    if (x >= 1 && y <= 5) {
        vector<int> temp;
        temp.push_back(x - 1);
        temp.push_back(y + 2);
        ans.push_back(temp);
    }

    // Eighth move: x - 1, y - 2
    if (x >= 1 && y >= 2) {
        vector<int> temp;
        temp.push_back(x - 1);
        temp.push_back(y - 2);
        ans.push_back(temp);
    }

    return ans;
}

void fillBoard(vector<vector<int> >& board,int curr[],int val)
{
    if(val==65)
    {
        return;
    }
    board[curr[0]][curr[1]]=val;
    vector<vector<int> > neighbours=getNeighbours(curr);
    for(int i=0;i<neighbours.size();i++)
    {
        if(board[neighbours[i][0]][neighbours[i][1]]==0)
        {
            int temp[2]={neighbours[i][0],neighbours[i][1]};
            fillBoard(board,temp,val+1);
        }
    }
}
int main()
{
    vector<vector<int> > board(8, vector<int>(8, 0));
    int val=1;
    int curr[2]={0,0};
    fillBoard(board,curr,val);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<board[i][j]<<"          ";
        }
        cout<<""<<endl;
    }
    return 0;
}
