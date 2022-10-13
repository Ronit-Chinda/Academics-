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
	for (int i = row,j=col; i>=0 &&j>=0; i--,j--)
	{
		if (board[i][j])
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

void solverec(int col,vector<vector<bool>> &board,int N,vector<vector<vector<bool>>> &ans){

	if (col==N)
	{
		ans.push_back(board);
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (issafe(i,col,board,N))
		{
			board[i][col]=1;
			solverec(col+1,board,N,ans);
			board[i][col]=0;
		}
	}

}


void print(vector<vector<vector<bool>>> &ans){
	for(int it=0;it<ans.size();it++){
		cout<<"Solution : "<<it+1<<endl;
		for (int i = 0; i < ans[it].size(); ++i)
		{
			for (int j = 0; j < ans[it][0].size(); ++j)
			{
				cout<<ans[it][i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

void solve(vector<vector<bool>> &board,int N,vector<vector<vector<bool>>> &ans){
	solverec(0,board,N,ans);
	print(ans);
}

int main(){
	int N;
	cin>>N;

	std::vector<vector<bool>> board(N,vector<bool>(N));
	vector<vector<vector<bool>>> ans;

	solve(board,N,ans);

	return 0;
}