#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nl printf("\n");

void bestM(int n, int _n, int matrix[n][_n]);
void storeM(int rows,int cols,int (*arr)[cols]){
   int n = rows * cols;
    int nums[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = rand() % n;
            arr[i][j] = nums[index];
            nums[index] = nums[--n];
        }
    }
}

void printM(int rows,int cols,int (*arr)[cols]){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(arr[i][j]==0){
                printf("[--]");
                continue;
            }
            printf("[%02d]", arr[i][j]);
        }
        printf("\n");
    }
}

void deleteM(int rows, int cols, int (*arr)[cols]){
    int x,key=0;
    printf("Enter no to be removed: ");
    a: scanf("%d",&x);
    if(x<1||x>(rows*cols)){
        b: printf("Enter valid no: ");
        goto a;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == x) {
                arr[i][j] = 0;
                key=1;
            }
        }
    }
    if(key==0){
        goto b;
    }
}

void bingo(int x){
    char b[]="B I N G O ";
    for(int i=2*x;i<10;i++){
        if(b[i]==' ') continue;
        b[i]='X';
    }
    printf("%s",b);
    if(x==5) printf("!!!");
    else if(x>5) printf("??? [%d]",x);
    printf("\n");
}

int checkM(int n, int _no, int (*mat)[_no])
{
    int i, j, row = 0, col = 0, diag = 0;
    for(i=0; i<n; i++)
    {
        int row_flag = 1, col_flag = 1;
        for(j=0; j<n; j++)
        {
            if(mat[i][j] != 0)
            {
                row_flag = 0;
            }
            if(mat[j][i] != 0)
            {
                col_flag = 0;
            }
        }
        if(row_flag == 1)
        {
            row++;
        }
        if(col_flag == 1)
        {
            col++;
        }
    }
    int diag_flag1 = 1, diag_flag2 = 1;
    for(i=0; i<n; i++)
    {
        if(mat[i][i] != 0)
        {
            diag_flag1 = 0;
        }
        if(mat[i][n-i-1] != 0)
        {
            diag_flag2 = 0;
        }
    }
    if(diag_flag1 == 1)
    {
        diag++;
    }
    if(diag_flag2 == 1)
    {
        diag++;
    }
    int s=row+col+diag;
    bingo(s);
    return s;
}

int main() {
    int rows, cols, s=0;
    printf("Enter side: ");
    scanf("%d", &rows);
    cols=rows;
    int arr[rows][cols];
    storeM(rows,cols,arr);
    printM(rows,cols,arr);
    bingo(0);
    while(1){
    deleteM(rows,cols,arr);
    printM(rows,cols,arr);
    s=checkM(rows,cols,arr);
    if(s>=5) break;
    bestM(rows,cols,arr);
    printf("\n");
    }
return 0;}

void bestM(int n, int _n, int matrix[n][_n]){
    int i, j, k, row, col, diag1 = 0, diag2 = 0;
    int s[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            row = col = diag1 = diag2 = 0;
            if(matrix[i][j]==0){s[i][j]=-1;continue;}
            for (k = 0; k < n; k++) {
                if (matrix[i][k] == 0) {
                    row++;
                }
                if (matrix[k][j] == 0) {
                    col++;
                }
            }
            if (i == j) {
                for (k = 0; k < n; k++) {
                    if (matrix[k][k] == 0) {
                        diag1++;
                    }
                }
            }
            if (i + j == n - 1) {
                for (k = 0; k < n; k++) {
                    if (matrix[k][n - k - 1] == 0) {
                        diag2++;
                    }
                }
            }
        s[i][j]=diag1+diag2+row+col;
        }
    }
    printf("The best move is");
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s[i][j]>x?(x=s[i][j]):0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]==x){
                printf(", %d",matrix[i][j]);
            }
        }
    }
}