#include<bits/stdc++.h>
using namespace std;

bool is_valid(int n ,int row ,int col ,int board[][100]){


	//horizontally

	for(int i=0;i<n;i++){
		if(board[row][i] == 1){
			return false;
		}
	}

	//vertically

	for(int i=0;i<n;i++){
		if(board[i][col] == 1){
			return false;
		}
	}

	int i = row -1;
	int j = col -1;

	//left diag

	while(i>=0 && j>=0){
		if(board[i][j] == 1){
			return false;
		}
		i--;
		j--;
	}


	//right diag

	i = row - 1;
	j = col + 1;

	while(i>=0 && j<n){
		if(board[i][j] == 1){
			return false;
		}

		i--;
		j++;
	}


	return true;


}

bool nquuens(int n,int row,int board[][100]){


	if(row==n){

		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		return true;
	}

	int col ;

	//1 row

	for(col = 0;col <n ;col++){

		if(is_valid(n,row,col,board)){
			board[row][col] = 1;
			bool kyanichesejawabaaya =  nquuens(n,row+1,board);

			if(kyanichesejawabaaya){
				return true;
			}
			board[row][col] = 0;

		}
	}
	return false;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
   
	int n;
	cin >>n;

	int board[100][100] = {0};

	bool is_ans = nquuens(n,0,board);
	
	if(is_ans){
		cout<<"placed";
	}
	else{
		cout<<"did not placed";
	}
return 0;
}