#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addition_matrix(int** add, int **a_ptr, int **b_ptr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			add[i][j] = a_ptr[i][j] + b_ptr[i][j];
		}
	}
}

void subtraction_matrix(int** sub, int** a_ptr, int** b_ptr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sub[i][j] = a_ptr[i][j] - b_ptr[i][j];
		}
	}

}

void multiply_matrix(int** C, int** A, int aRows, int aCols, int** B, int bCols) {

	for (int i = 0; i < aRows; i++) {
		for (int j = 0; j < bCols; j++) {
			C[i][j] = 0; // 결과 행렬의 초기화
			for (int k = 0; k < aCols; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


void transpose_matrix(int** trans, int** a, int rows, int cols){

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			trans[j][i] = a[i][j];
		}
	}
}

void print_matrix(int** ptr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]); // 각 행에 대한 메모리 해제
	}
	free(matrix); // 행 포인터 배열에 대한 메모리 해제
}

int main() {
	int** a_ptr, ** b_ptr;
	int a_rows, a_cols, b_rows, b_cols;

    printf("[----- [강수빈] [2023078011] -----]\n");

	scanf("%d %d", &a_rows, &a_cols);
	scanf("%d %d", &b_rows, &b_cols);

	// A 행렬 메모리 할당
	a_ptr = (int**)malloc(a_rows * sizeof(int*));
	for (int i = 0; i < a_rows; i++) {
		a_ptr[i] = (int*)malloc(a_cols * sizeof(int));
	}

	// B 행렬 메모리 할당
	b_ptr = (int**)malloc(b_rows * sizeof(int*));
	for (int i = 0; i < b_rows; i++) {
		b_ptr[i] = (int*)malloc(b_cols * sizeof(int));
	}

	// MUL 행렬 메모리 할당
	int **mul = (int**)malloc(a_rows * sizeof(int*));
	for (int i = 0; i < a_rows; i++) {
		mul[i] = (int*)malloc(b_cols * sizeof(int));
	}

	int** trans = (int**)malloc(a_cols * sizeof(int*));
	for (int i = 0; i < a_cols; i++) {
		trans[i] = (int*)malloc(a_rows * sizeof(int));
	}

	int** add = (int**)malloc(a_rows * sizeof(int*));
	for (int i = 0; i < a_rows; i++) {
		add[i] = (int*)malloc(a_cols * sizeof(int));
	}

	int** sub = (int**)malloc(a_rows * sizeof(int*));
	for (int i = 0; i < a_rows; i++) {
		sub[i] = (int*)malloc(a_cols * sizeof(int));
	}

	srand(time(NULL));

	// A, B 행렬 값 할당
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < a_cols; j++) {
			a_ptr[i][j] = rand()%10+1;
		}
	}
	for (int i = 0; i < b_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			b_ptr[i][j] = rand()%10+1;
		}
	}

	if (a_rows == b_rows && a_cols == b_cols) {
		addition_matrix(add, a_ptr, b_ptr, a_rows, a_cols);
		subtraction_matrix(sub, a_ptr, b_ptr, a_rows, a_cols);
	}
    else
      for(int i= 0; i< a_rows; i++){
        for(int j = 0; j < a_cols; j++){
          add[i][j] = 0;
          sub[i][j] = 0;
        }
      }

	// 행렬 곱셈 수행
    if(a_cols == b_rows)
	   multiply_matrix(mul, a_ptr, a_rows, a_cols, b_ptr, b_cols);
    else
     for(int i= 0; i< a_rows; i++){
        for(int j = 0; j < a_cols; j++){
          mul[i][j] = 0;
        }
      }
    
	transpose_matrix(trans, a_ptr, a_rows, a_cols);

	// 결과 출력

	printf("\nA matrix\n");
	print_matrix(a_ptr, a_rows, a_cols);

	printf("\nB matrix\n");
	print_matrix(b_ptr, b_rows, b_cols);

    if (a_rows == b_rows && a_cols == b_cols){
	    printf("\nA + B\n");
	    print_matrix(add, a_rows, a_cols);

	    printf("\nA - B\n");
	    print_matrix(sub, a_rows, a_cols);
    }
    else
        printf("\nA + B, A - B 는 불가능합니다\n");

    if(a_cols == b_rows){
        printf("\nA * B\n");
        print_matrix(mul, a_rows, b_cols);
    }
    else
        printf("\nA * B 는 불가능합니다\n");


	printf("\nTranspose A\n");
	print_matrix(trans, a_cols, a_rows);

	// 메모리 해제
	free_matrix(a_ptr, a_rows);
	free_matrix(b_ptr, b_rows);
	free_matrix(mul, a_rows);
	free_matrix(trans, a_cols); // trans는 전치 행렬이므로, 원본 행렬의 열 수가 행 수가 된다.
	free_matrix(add, a_rows);
	free_matrix(sub, a_rows);


	return 0;
}