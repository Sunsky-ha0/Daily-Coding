//
//  DefiniteIntegral.c
//  Pointer
//
//  Created by Sunsky on 2021/8/24.
//  Use rectangle method to calculate some easy definite integral.

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int k,n;
    float a,b;
    double fsine(float x);
    double fcosine(float x);
    double fexponent(float x);
    void IntergralReactangle(float a,float b,int n,double (* p)(float));
    printf("Please enter start and end position:\n");
    scanf("%f,%f",&a,&b);
    printf("Please choose number of intervals:\n");
    scanf("%d",&n);
    printf("Please choose k:\n");//k=1->sin(x);k=2->cos(x);k=3->exp(x)
    scanf("%d",&k);
    if (k==1)
        IntergralReactangle(a,b,n,fsine);
    else if (k==2)
        IntergralReactangle(a,b,n,fcosine);
    else if (k==3)
        IntergralReactangle(a,b,n,fexponent);
    return 0;
}

void IntergralReactangle(float a,float b,int n,double (* p)(float))
{
    int i;
    double sum=0;
    float x,interal;
    x = a;
    interal = (b-a)/n;
    for (i=1;i<=n;i++)
    {
        x += interal;
        sum += (*p)(x)*interal;
    }
    printf("Sum:%f\n",sum);
}
double fsine(float x)
{
    return sin(x);
}
double fcosine(float x)
{
    return cos(x);
}
double fexponent(float x)
{
    return exp(x);
}
