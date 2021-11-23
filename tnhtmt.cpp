
#include <stdio.h>
#include <math.h>
#include <conio.h>
#define R_MAX 100
#define C_MAX 100

void NhapMaTran(int a[][C_MAX], int &row, int &col);
float TB(int a[][C_MAX], int row, int col);
int FindMin(int a[][C_MAX], int row ,int col);
int SoLanXuatHien(int a[][C_MAX], int row, int col);
int TongDong_k(int a[][C_MAX], int row, int col, int k);
float Cau5(int a[][C_MAX], int row, int col);
long giaithua(int n);

int main(){
    int A[R_MAX][C_MAX];
    int m,  n;
    NhapMaTran(A, m, n);
    printf("Gia tri TB so duong la: %f",TB(A, m, n));
    printf("\n");
    printf("Gia tri nho nhat %d xuat hien %d lan", FindMin(A,m,n), SoLanXuatHien(A, m, n));
    printf("\n");
    printf("%d",TongDong_k(A,m,n, 2));
    printf("\n");
    printf("S=%f",Cau5(A,m,n));
    return 0;
}
void NhapMaTran(int a[][C_MAX], int &row, int &col){
    do{
        printf("Nhap so dong: ");
        scanf("%d",&row);
    }while(row<0 || row > R_MAX);
    do{
        printf("Nhap so cot: ");
        scanf("%d",&col);
    }while(col<0 || col > C_MAX);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("a[%d][%d]=", i, j);
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
   
}
float TB(int a[][C_MAX], int row, int col){
    float sum=0;
    int count=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]>0){
                count++;
                sum+=a[i][j];
            }
        }
    }
    return (sum/count);
}
int FindMin(int a[][C_MAX], int row ,int col){
    int min=a[0][0];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]<min){
                min=a[i][j];
            }
        }
    }
    return min;
}
int SoLanXuatHien(int a[][C_MAX], int row, int col){
    int count=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]==FindMin(a, row, col)){
                count++;
            }
        }
    }
    return count;
}
int TongDong_k(int a[][C_MAX], int row, int col, int k){
    int sum=0;
    for(int i=0;i<row;i++){
        sum+=a[k][i];
    }
    return sum;
}
long giaithua(int n){
    long tich=1;
    if(n<=1) tich=1;
    for(int i=1;i<=n;i++){
        tich*=i;
    }
    return tich;
}
float Cau5(int a[][C_MAX], int row, int col){
    float S=0;
    for(int i=1;i<=row;i++){
        if(i%2==0){
            S-=(pow((TongDong_k(a,row, col,i-1)),i))/(float)giaithua(i);
        }
        if(i%2!=0){
            S+=(pow((TongDong_k(a,row, col,i-1)),i))/(float)giaithua(i);

        }
    }
    return S;

}