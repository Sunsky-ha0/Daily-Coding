//
//  Transpose.c
//  Exercise
//
//  Created by Sunsky on 2021/8/22.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int n;
    int * Arr = NULL;
    void InputArr(int * pointer,int n);
    void Transpose(int * pointer,int n);
    void OutputArr(int * pointer,int n);
    
    printf("Please enter square matric dimensional:\n");
    scanf("%d",&n);
    
    Arr = realloc(Arr,sizeof(int)*n*n);
    //Input your matric arr(n-dim)
    InputArr(Arr,n);
    //Transpose
    Transpose(Arr,n);
    //Output arr.T
    OutputArr(Arr,n);
    
    return 0;
}

void Transpose(int * pointer,int n)
{
    int i,j,tep;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            tep = *(pointer+i*n+j);
            *(pointer+i*n+j) = *(pointer+j*n+i);
            *(pointer+j*n+i) = tep;
        }
}

void InputArr(int * pointer,int n)
{
    int i=0,j=0;
    printf("Please enter your matric:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d",pointer+i*n+j);
}

void OutputArr(int * pointer,int n)
{
    int i=0,j=0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            printf("\t%d",*(pointer+i*n+j));
            if (j == n-1) printf("\n");
        }
}

