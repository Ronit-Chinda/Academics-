#include<bits/stdc++.h>
using namespace std;

bool issafe(int row,int col,vector<vector<bool>> &board,int N){
	for (int i = 0; i < col; ++i)
	{
		if (board[row][i])
		{
			return false;
		}
	}
	for (int i = row,j=col; i < N && j>=0; ++i,j--)
	{
		if (board[i][j])
		{
			return false;
		}
	}
	return true;
}

bool solverec(int col,vector<vector<bool>> &board,int N){
	if (col==N)
	{
		return true;
	}
	for (int i = 0; i < N; ++i)
	{
		if (issafe(i,col,board,N))
		{
			board[i][col]=1;
			if (solverec(col+1,board,N))
			{
				return true;
			}
			board[i][col]=0;
		}
	}
	return false;
}



void print(vector<vector<bool>> &board){
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool solve(vector<vector<bool>> &board,int N){
	
	if (solverec(0,board,N)==false)
	{
		return false;
	}
	else{
		print(board);
		return true;
	}
}

int main(){
	int N;
	cin>>N;

	std::vector<vector<bool>> board(N,vector<bool>(N));
	bool ans= solve(board,N);
	if (!ans)
	{
		cout<<"No Solution Exists!"<<endl;
	}
		
	return 0;
}