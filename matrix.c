#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
// 매개 변수로 A행렬 B행렬, 연산결과 행렬의 주소, 행과 열을 받아 계산한다.
// 배열형태로 접근

// 덧셈 함수
void addition_matrix(int** add, int **a_ptr, int **b_ptr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			add[i][j] = a_ptr[i][j] + b_ptr[i][j]; // A행렬과 B행렬의 원소의 각각의 값을 더해서 add가 가리키는 메모리에 넣는다.
		}
	}
}

void subtraction_matrix(int** sub, int** a_ptr, int** b_ptr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sub[i][j] = a_ptr[i][j] - b_ptr[i][j]; // A행렬과 B행렬의 원소의 각각의 값을 빼서 할당된 sub이 가리키는 메모리에 넣는다.
		}
	}

}

void multiply_matrix(int** mul, int** a, int a_rows, int a_cols, int** b, int b_cols) {

	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			for (int k = 0; k < a_cols; k++) {
				mul[i][j] += a[i][k] * b[k][j];   // A행렬은 행을 기준으로 커지고, B행렬은 열을 기준으로 커진다. A행렬의 행과 B행렬의 열에 존재하는 원소들을 각각 곱하고 줄 별로 더한다.
			}
		}
	}
}


void transpose_matrix(int** trans, int** a, int rows, int cols){ 

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			trans[j][i] = a[i][j];  // A행렬의 행과 열의 숫자를을 바꾼 것을 trans가 가리키는 메모리에 할당한다.
		}
	}
}

void print_matrix(int** ptr, int rows, int cols) {   // 이중포인터로 주소를 받고 그 위치에서부터 줄별로 가져와 출력한다.
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

// 메인함수
int main() {
	int** a_ptr, ** b_ptr;  //행렬 A와 B를 가리킬 이중포인터 선언
	int a_rows, a_cols, b_rows, b_cols;  // 행렬 A와 B의 행과 열을 각각 선언

  	printf("[----- [강수빈] [2023078011] -----]\n");

	// scanf로 각각의 행과 열을 입력받음
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

	// A+B 결과 행렬 메모리 할당
	int** add = (int**)malloc(a_rows * sizeof(int*));  // 두 행렬의 행과 열이 같아야 가능하기에 행과 열은 둘 중 아무 행렬이나 상관없다
	for (int i = 0; i < a_rows; i++) {
		add[i] = (int*)malloc(a_cols * sizeof(int));
	}


	// A-B 결과 행렬 메모리 할당
	int** sub = (int**)malloc(a_rows * sizeof(int*));   // 뺄셈도 마찬가지이다
	for (int i = 0; i < a_rows; i++) {
		sub[i] = (int*)malloc(a_cols * sizeof(int));
	}


	// 곱셈 결과 행렬 메모리 할당
	int **mul = (int**)malloc(a_rows * sizeof(int*));
	for (int i = 0; i < a_rows; i++) {
		mul[i] = (int*)malloc(b_cols * sizeof(int));
	}

	// A행렬 전치 결과 행렬 메모리 할당
	int** trans = (int**)malloc(a_cols * sizeof(int*));
	for (int i = 0; i < a_cols; i++) {
		trans[i] = (int*)malloc(a_rows * sizeof(int));
	}


	// 실행하는 시간에 따라 계속 랜덤한 숫자가 나오게 한다.
	srand(time(NULL));


	// A, B 행렬 값 할당
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < a_cols; j++) {
			a_ptr[i][j] = rand()%10+1; //1~9의 숫자로 할당되도록 하였다.
		}
	}
	for (int i = 0; i < b_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			b_ptr[i][j] = rand()%10+1; 
		}
	}


	// 함수 실행

	// 덧셈과 뺄셈은 두 행렬의 행과 열이 같아야 계산 가능하기에 조건문으로 예외를 막는다.
	if (a_rows == b_rows && a_cols == b_cols) {
		addition_matrix(add, a_ptr, b_ptr, a_rows, a_cols);
		subtraction_matrix(sub, a_ptr, b_ptr, a_rows, a_cols);
	}
   	 else   // 아닐 시 0으로 초기화
      		for(int i= 0; i< a_rows; i++){
        		  for(int j = 0; j < a_cols; j++){
         		     add[i][j] = 0;
       		     sub[i][j] = 0;
     		   }
    	  }

	// 행렬의 곱셈은 A행렬의 열과 B행렬의 행의 갯수가 같아야 가능하기에 조건문으로 예외처리한다.
 	   if(a_cols == b_rows)
		   multiply_matrix(mul, a_ptr, a_rows, a_cols, b_ptr, b_cols);
   	 else   // 아닐 시 0으로 초기화
   		  for(int i= 0; i< a_rows; i++){
      		  for(int j = 0; j < a_cols; j++){
       		   mul[i][j] = 0;
      		  }
   		}
    	// A행렬의 전치 함수를 실행한다.
	transpose_matrix(trans, a_ptr, a_rows, a_cols);


	// 결과 출력

	// A 행렬 출력
	printf("\nA matrix\n");
	print_matrix(a_ptr, a_rows, a_cols);

	// B 행렬 출력
	printf("\nB matrix\n");
	print_matrix(b_ptr, b_rows, b_cols);

	// 행렬 덧셈조건 만족시에만 출력, 조건을 만족하지않으면 문구 출력
   	 if (a_rows == b_rows && a_cols == b_cols){
	    printf("\nA + B\n");
	    print_matrix(add, a_rows, a_cols);

	    printf("\nA - B\n");
	    print_matrix(sub, a_rows, a_cols);
    	}
  	  else
                   printf("\nA + B, A - B 는 불가능합니다\n");

	// 행렬 덧셈조건 만족시에만 출력, 조건을 만족하지않으면 문구 출력
    	if(a_cols == b_rows){
        		printf("\nA * B\n");
        		print_matrix(mul, a_rows, b_cols);
   	 }
    	else
        		printf("\nA * B 는 불가능합니다\n");

	// A행렬 전치 결과 출력
	printf("\nTranspose A\n");
	print_matrix(trans, a_cols, a_rows);

	// 함수로 메모리 해제
	free_matrix(a_ptr, a_rows);
	free_matrix(b_ptr, b_rows);
	free_matrix(mul, a_rows);
	free_matrix(trans, a_cols); // trans는 전치 행렬이므로, 원본 행렬의 열 수가 행 수가 된다.
	free_matrix(add, a_rows);
	free_matrix(sub, a_rows);


	return 0;
}