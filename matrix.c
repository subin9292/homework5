#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �Լ� ����
// �Ű� ������ A��� B���, ������ ����� �ּ�, ��� ���� �޾� ����Ѵ�.
// �迭���·� ����

// ���� �Լ�
void addition_matrix(int** add, int **a_ptr, int **b_ptr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			add[i][j] = a_ptr[i][j] + b_ptr[i][j]; // A��İ� B����� ������ ������ ���� ���ؼ� add�� ����Ű�� �޸𸮿� �ִ´�.
		}
	}
}

void subtraction_matrix(int** sub, int** a_ptr, int** b_ptr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sub[i][j] = a_ptr[i][j] - b_ptr[i][j]; // A��İ� B����� ������ ������ ���� ���� �Ҵ�� sub�� ����Ű�� �޸𸮿� �ִ´�.
		}
	}

}

void multiply_matrix(int** mul, int** a, int a_rows, int a_cols, int** b, int b_cols) {

	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			for (int k = 0; k < a_cols; k++) {
				mul[i][j] += a[i][k] * b[k][j];   // A����� ���� �������� Ŀ����, B����� ���� �������� Ŀ����. A����� ��� B����� ���� �����ϴ� ���ҵ��� ���� ���ϰ� �� ���� ���Ѵ�.
			}
		}
	}
}


void transpose_matrix(int** trans, int** a, int rows, int cols){ 

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			trans[j][i] = a[i][j];  // A����� ��� ���� ���ڸ��� �ٲ� ���� trans�� ����Ű�� �޸𸮿� �Ҵ��Ѵ�.
		}
	}
}

void print_matrix(int** ptr, int rows, int cols) {   // ���������ͷ� �ּҸ� �ް� �� ��ġ�������� �ٺ��� ������ ����Ѵ�.
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]); // �� �࿡ ���� �޸� ����
	}
	free(matrix); // �� ������ �迭�� ���� �޸� ����
}

// �����Լ�
int main() {
	int** a_ptr, ** b_ptr;  //��� A�� B�� ����ų ���������� ����
	int a_rows, a_cols, b_rows, b_cols;  // ��� A�� B�� ��� ���� ���� ����

  	printf("[----- [������] [2023078011] -----]\n");

	// scanf�� ������ ��� ���� �Է¹���
	scanf("%d %d", &a_rows, &a_cols);
	scanf("%d %d", &b_rows, &b_cols);

	// A ��� �޸� �Ҵ�
	a_ptr = (int**)malloc(a_rows * sizeof(int*));
	for (int i = 0; i < a_rows; i++) {
		a_ptr[i] = (int*)malloc(a_cols * sizeof(int));
	}

	// B ��� �޸� �Ҵ�
	b_ptr = (int**)malloc(b_rows * sizeof(int*));
	for (int i = 0; i < b_rows; i++) {
		b_ptr[i] = (int*)malloc(b_cols * sizeof(int));
	}

	// A+B ��� ��� �޸� �Ҵ�
	int** add = (int**)malloc(a_rows * sizeof(int*));  // �� ����� ��� ���� ���ƾ� �����ϱ⿡ ��� ���� �� �� �ƹ� ����̳� �������
	for (int i = 0; i < a_rows; i++) {
		add[i] = (int*)malloc(a_cols * sizeof(int));
	}


	// A-B ��� ��� �޸� �Ҵ�
	int** sub = (int**)malloc(a_rows * sizeof(int*));   // ������ ���������̴�
	for (int i = 0; i < a_rows; i++) {
		sub[i] = (int*)malloc(a_cols * sizeof(int));
	}


	// ���� ��� ��� �޸� �Ҵ�
	int **mul = (int**)malloc(a_rows * sizeof(int*));
	for (int i = 0; i < a_rows; i++) {
		mul[i] = (int*)malloc(b_cols * sizeof(int));
	}

	// A��� ��ġ ��� ��� �޸� �Ҵ�
	int** trans = (int**)malloc(a_cols * sizeof(int*));
	for (int i = 0; i < a_cols; i++) {
		trans[i] = (int*)malloc(a_rows * sizeof(int));
	}


	// �����ϴ� �ð��� ���� ��� ������ ���ڰ� ������ �Ѵ�.
	srand(time(NULL));


	// A, B ��� �� �Ҵ�
	for (int i = 0; i < a_rows; i++) {
		for (int j = 0; j < a_cols; j++) {
			a_ptr[i][j] = rand()%10+1; //1~9�� ���ڷ� �Ҵ�ǵ��� �Ͽ���.
		}
	}
	for (int i = 0; i < b_rows; i++) {
		for (int j = 0; j < b_cols; j++) {
			b_ptr[i][j] = rand()%10+1; 
		}
	}


	// �Լ� ����

	// ������ ������ �� ����� ��� ���� ���ƾ� ��� �����ϱ⿡ ���ǹ����� ���ܸ� ���´�.
	if (a_rows == b_rows && a_cols == b_cols) {
		addition_matrix(add, a_ptr, b_ptr, a_rows, a_cols);
		subtraction_matrix(sub, a_ptr, b_ptr, a_rows, a_cols);
	}
   	 else   // �ƴ� �� 0���� �ʱ�ȭ
      		for(int i= 0; i< a_rows; i++){
        		  for(int j = 0; j < a_cols; j++){
         		     add[i][j] = 0;
       		     sub[i][j] = 0;
     		   }
    	  }

	// ����� ������ A����� ���� B����� ���� ������ ���ƾ� �����ϱ⿡ ���ǹ����� ����ó���Ѵ�.
 	   if(a_cols == b_rows)
		   multiply_matrix(mul, a_ptr, a_rows, a_cols, b_ptr, b_cols);
   	 else   // �ƴ� �� 0���� �ʱ�ȭ
   		  for(int i= 0; i< a_rows; i++){
      		  for(int j = 0; j < a_cols; j++){
       		   mul[i][j] = 0;
      		  }
   		}
    	// A����� ��ġ �Լ��� �����Ѵ�.
	transpose_matrix(trans, a_ptr, a_rows, a_cols);


	// ��� ���

	// A ��� ���
	printf("\nA matrix\n");
	print_matrix(a_ptr, a_rows, a_cols);

	// B ��� ���
	printf("\nB matrix\n");
	print_matrix(b_ptr, b_rows, b_cols);

	// ��� �������� �����ÿ��� ���, ������ �������������� ���� ���
   	 if (a_rows == b_rows && a_cols == b_cols){
	    printf("\nA + B\n");
	    print_matrix(add, a_rows, a_cols);

	    printf("\nA - B\n");
	    print_matrix(sub, a_rows, a_cols);
    	}
  	  else
                   printf("\nA + B, A - B �� �Ұ����մϴ�\n");

	// ��� �������� �����ÿ��� ���, ������ �������������� ���� ���
    	if(a_cols == b_rows){
        		printf("\nA * B\n");
        		print_matrix(mul, a_rows, b_cols);
   	 }
    	else
        		printf("\nA * B �� �Ұ����մϴ�\n");

	// A��� ��ġ ��� ���
	printf("\nTranspose A\n");
	print_matrix(trans, a_cols, a_rows);

	// �Լ��� �޸� ����
	free_matrix(a_ptr, a_rows);
	free_matrix(b_ptr, b_rows);
	free_matrix(mul, a_rows);
	free_matrix(trans, a_cols); // trans�� ��ġ ����̹Ƿ�, ���� ����� �� ���� �� ���� �ȴ�.
	free_matrix(add, a_rows);
	free_matrix(sub, a_rows);


	return 0;
}