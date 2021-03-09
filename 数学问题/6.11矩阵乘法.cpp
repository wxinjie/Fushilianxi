#include<iostream>
#include<cstdio>

using namespace std;

struct Matrix{
	int matrix[3][3];
	int row, col;
	Matrix(int r, int c) : row(r), col(c) {}
};

Matrix Multiply(Matrix x, Matrix y){
	Matrix answer(x.row, y.col);
	for(int i = 0; i < answer.row; ++i){
		for(int j = 0; j < answer.col; ++j){
			answer.matrix[i][j] = 0;
			for(int k = 0; k < x.col; ++k){
				answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
			}
		}
	}
	return answer;
}

void PrintMatrix(Matrix x){
	for(int i = 0; i < x.row; ++i){
		for(int j = 0; j < x.col; ++j){
			printf("%d ",x.matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	Matrix x(2,3);
	Matrix y(3,2);
	for(int i = 0; i < x.row; ++i){
		for(int j = 0; j < x.col;++j){
			scanf("%d",&x.matrix[i][j]);
		}
	}
	for(int i = 0; i < y.row; ++i){
		for(int j = 0; j < y.col; ++j){
			scanf("%d",&y.matrix[i][j]);
		}
	}
	PrintMatrix(Multiply(x,y)); 
	return 0;
}
