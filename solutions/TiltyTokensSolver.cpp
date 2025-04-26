#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

string solve(vector<vector<char>>& grid){
    vector<char> directions = { 'D','U','R','L' };
    unordered_set<string> memo; int count[5][5]; string boardStr;
    int cnt = 0; for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) count[i][j] = cnt++;
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) boardStr += grid[i + 1][j + 1];
    memo.insert(boardStr);
    
    queue<pair<int,int>> revert;
    queue<pair<vector<vector<char>>,string>> q; q.push({grid,""});
    for(int i = 0; i < 5; i++) 
        for(int j = 0; j < 5; j++) 
            if(grid[i + 1][j + 1] == 'G' || grid[i + 1][j + 1] == 'B'){
                grid[i + 1][j + 1] = '.'; 
                boardStr[count[i][j]] = '.';
            }
    while(!q.empty()){
        vector<vector<char>> board = q.front().first;
        string steps = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            bool solved = true, invalid = false; int anchor = -1;
            if     (dir == 0){
                for(int j = 1; j <= 5; j++){
                    anchor = 5;
                    for(int i = 5; i >= 1; i--){
                        if(board[i][j] == 'X' || board[i][j] == 'O') anchor = i - 1;
                        else if(board[i][j] == 'G'){
                            if(board[anchor + 1][j] == 'O') continue;
                            solved = false;
                            revert.push({anchor,j});
                            boardStr[count[anchor - 1][j - 1]] = 'G';
                            grid[anchor--][j] = board[i][j];
                        }
                        else if(board[i][j] == 'B'){
                            if(board[anchor + 1][j] == 'O'){
                                invalid = true;
                                break;
                            }
                            revert.push({anchor,j});
                            boardStr[count[anchor - 1][j - 1]] = 'B';
                            grid[anchor--][j] = board[i][j];
                        }
                    }
                    if(invalid) break;
                }
            }
            else if(dir == 1){
                for(int j = 1; j <= 5; j++){
                    anchor = 1;
                    for(int i = 1; i <= 5; i++){
                        if(board[i][j] == 'X' || board[i][j] == 'O') anchor = i + 1;
                        else if(board[i][j] == 'G'){
                            if(board[anchor - 1][j] == 'O') continue;
                            solved = false;
                            revert.push({anchor,j});
                            boardStr[count[anchor - 1][j - 1]] = 'G';
                            grid[anchor++][j] = board[i][j];
                        }
                        else if(board[i][j] == 'B'){
                            if(board[anchor - 1][j] == 'O'){
                                invalid = true;
                                break;
                            }
                            revert.push({anchor,j});
                            boardStr[count[anchor - 1][j - 1]] = 'B';
                            grid[anchor++][j] = board[i][j];
                        }
                    }
                    if(invalid) break;
                }
            }
            else if(dir == 2){
                for(int i = 1; i <= 5; i++){
                    anchor = 5;
                    for(int j = 5; j >= 1; j--){
                        if(board[i][j] == 'X' || board[i][j] == 'O') anchor = j - 1;
                        else if(board[i][j] == 'G'){
                            if(board[i][anchor + 1] == 'O') continue;
                            solved = false;
                            revert.push({i,anchor});
                            boardStr[count[i - 1][anchor - 1]] = 'G';
                            grid[i][anchor--] = board[i][j];
                        }
                        else if(board[i][j] == 'B'){
                            if(board[i][anchor + 1] == 'O'){
                                invalid = true;
                                break;
                            }
                            revert.push({i,anchor});
                            boardStr[count[i - 1][anchor - 1]] = 'B';
                            grid[i][anchor--] = board[i][j];
                        }
                    }
                    if(invalid) break;
                }
            }
            else if(dir == 3){
                for(int i = 1; i <= 5; i++){
                    anchor = 1;
                    for(int j = 1; j <= 5; j++){
                        if(board[i][j] == 'X' || board[i][j] == 'O') anchor = j + 1;
                        else if(board[i][j] == 'G'){
                            if(board[i][anchor - 1] == 'O') continue;
                            solved = false;
                            revert.push({i,anchor});
                            boardStr[count[i - 1][anchor - 1]] = 'G';
                            grid[i][anchor++] = board[i][j];
                        }
                        else if(board[i][j] == 'B'){
                            if(board[i][anchor - 1] == 'O'){
                                invalid = true;
                                break;
                            }
                            revert.push({i,anchor});
                            boardStr[count[i - 1][anchor - 1]] = 'B';
                            grid[i][anchor++] = board[i][j];
                        }
                    }
                    if(invalid) break;
                }
            }

            if(!invalid){
                if(solved) return steps + directions[dir];
                else if(memo.find(boardStr) == memo.end()){
                    memo.insert(boardStr);
                    q.push({grid,steps + directions[dir]});
                }
            }
            while(!revert.empty()){
                int i = revert.front().first, j = revert.front().second;
                grid[i][j] = '.';
                boardStr[count[i - 1][j - 1]] = '.';
                revert.pop();
            }
        }
    }
    
    return "";
}

int main(){
    vector<vector<char>> grid = {
        {'X','X','X','X','X','X','X'},
        {'X','.','.','.','.','.','X'},
        {'X','.','.','.','.','.','X'},
        {'X','.','.','.','.','.','X'},
        {'X','.','.','.','.','.','X'},
        {'X','.','.','.','.','.','X'},
        {'X','X','X','X','X','X','X'}
    };

    string res = solve(grid);
    cout<<res;
}