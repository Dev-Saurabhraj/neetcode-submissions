class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i<9; i++){
            unordered_map<int, int> mp;
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.') continue;
                if(mp.find(board[i][j])!=mp.end()){
                    return false;
                }
                mp[board[i][j]] = 0;
            }
        }
        for(int i = 0; i<9; i++){
            unordered_map<int, int> mp;
            for(int j = 0; j<9; j++){
                if(board[j][i]=='.') continue;
                if( mp.find(board[j][i])!=mp.end() ){
                    return false;
                }
                mp[board[j][i]] = 0;
            }
        }


        for(int a = 0; a<9; a+=3){
            for(int b = 0; b<9; b+=3){
                unordered_map<int, int> mp;
                for(int i = 1; i<=3; i++){
                    for(int j = 1; j<=3; j++){
                        if(board[a+i-1][b+j-1]=='.') continue;
                        if(mp.find(board[a+i-1][b+j-1])!=mp.end()){
                            return false;
                        }
                        mp[board[a+i-1][b+j-1]] = 0;
                    }
                   
                }
            }
        }

        return true;
    }
};
