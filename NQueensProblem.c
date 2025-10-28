#include<stdio.h>
#include<stdbool.h>
#define MAX 15
int count=0;
int board[MAX];

bool isSafe(int row,int col){
	for(int i=0;i<row;i++){
		if(board[i]==col || board[i] -i == col-row || board[i] + i == col+row){
			return false;
		}
	}
	return true;
}

void solveNQueens(int row,int n){
	if(row ==n){
		count++;
		return;
	}for(int col=0;col<n;col++){
		if(isSafe(row,col)){
			board[row]=col;
			solveNQueens(row+1,n);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	count=0;
	solveNQueens(0,n);
	printf("%d\n",count);
	return 0;
}