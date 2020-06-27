#include<bits/stdc++.h>
using namespace std;
int path[1001][1001] = {0};
bool ratimaze(char maze[][1001],int i,int j,int n,int m){

	//ase condition

	if(i==n-1 && j==m-1){
		//destination

		path[i][j] = 1;

		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cout<<path[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}

	path[i][j] = 1; 

// right move

	if( i<n && j+1<m && maze[i][j+1]!='X'){
		path[i][j+1] = 1;

		bool kyarightseansaaya =  ratimaze(maze ,i ,j+1,n,m);

		if(kyarightseansaaya== true){
			return true;
		}

		
	}


//down

	if(i+1<n  && j<m  && maze[i+1][j]!='X'){
		path[i+1][j] = 1;

		bool kyadownseansaaya = ratimaze(maze,i+1,j,n,m);
		if(kyadownseansaaya){
			return true;
		}

	}


	path[i][j] = 0;

	return false;

}

/*char maze[4][4] = {
		{'o','o','x','o'},
		{'o','o','o','x'},
		{'x','x','o','o'},
		{'x','o','o','o'}
	};
*/




int main()
{
    int n, m;
	cin >> n >> m;
	char maze[1001][1001] ;
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>maze[i][j];
		}
	}
	

	 bool is_path =  ratimaze(maze,0,0,n,m);
if(is_path==false){
        cout<<"-1";
    }
	 
	
	return 0;
}