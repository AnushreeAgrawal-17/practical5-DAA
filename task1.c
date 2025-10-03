#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct { int val; char dir; } Cell;
Cell c[MAX][MAX];

void LCS(char X[], char Y[], int m, int n){
    for(int i=0;i<=m;i++){c[i][0].val=0;c[i][0].dir='H';}
    for(int j=0;j<=n;j++){c[0][j].val=0;c[0][j].dir='V';}
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){c[i][j].val=c[i-1][j-1].val+1;c[i][j].dir='D';}
            else if(c[i-1][j].val>=c[i][j-1].val){c[i][j].val=c[i-1][j].val;c[i][j].dir='U';}
            else{c[i][j].val=c[i][j-1].val;c[i][j].dir='L';}
        }
    }
}

void Print_LCS(int i,int j,char X[]){
    if(i==0||j==0)return;
    if(c[i][j].dir=='D'){Print_LCS(i-1,j-1,X);printf("%c",X[i-1]);}
    else if(c[i][j].dir=='U')Print_LCS(i-1,j,X);
    else Print_LCS(i,j-1,X);
}

int main(){
    char X[MAX]="AGCCCTAAGGGCTACCTAGCTT";
    char Y[MAX]="GACAGCCTACAAGCGTTAGCTTG";
    int m=strlen(X), n=strlen(Y);
    LCS(X,Y,m,n);
    printf("LCS: ");
    Print_LCS(m,n,X);
    printf("\nLength of LCS: %d\n",c[m][n].val);
    return 0;
}