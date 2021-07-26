//
//  Variance.c
//  StandardLibrary
//
//  Created by Sunsky on 2021/7/26.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int *ARRAY = NULL, ARRAY_LENGTH, i,j, TEMPORARY_ELEMENT, isSorted = 0;
    float MEAN = 0,VARIANCE = 0,STAND;
//get array
    printf("Please enter the length of array: \n");
    scanf("%d",&ARRAY_LENGTH);

    ARRAY = (int *)realloc(ARRAY,sizeof(int) * ARRAY_LENGTH);
    
    srand((unsigned int)time(NULL));

    for (i = 0; i < ARRAY_LENGTH; ++i)
        ARRAY[i] = rand() % 10;

    for (i = 0; i < ARRAY_LENGTH; ++i)
        printf("%d\n",ARRAY[i]);
//Bubble sort I
//    for (i = 0; i < ARRAY_LENGTH - 1; ++i)
//    {
//        for (j = i + 1; j < ARRAY_LENGTH ; ++j)
//            if (ARRAY[i] < ARRAY[j])
//            {
//                TEMPORARY_ELEMENT = ARRAY[j];
//                ARRAY[j] = ARRAY[i];
//                ARRAY[i] = TEMPORARY_ELEMENT;
//            }
//    }
//Bubble sort II
    while (! isSorted)
    {
        isSorted = 1;
        for (i = 0; i < ARRAY_LENGTH - 1; ++i)
        {
            if (ARRAY[i]>ARRAY[i+1])
            {
                isSorted = 0;
                TEMPORARY_ELEMENT = ARRAY[i];
                ARRAY[i] = ARRAY[i+1];
                ARRAY[i+1] = TEMPORARY_ELEMENT;
            }
        }
    }

//Calculate mean,variance,stand
    for (i = 0; i < ARRAY_LENGTH;++i)
        MEAN += ARRAY[i];

    MEAN = MEAN/(float)ARRAY_LENGTH;

    for (i = 0; i < ARRAY_LENGTH;++i)
        VARIANCE += pow((ARRAY[i]-MEAN),2);

    VARIANCE = VARIANCE/(float)ARRAY_LENGTH;
    STAND = sqrt(VARIANCE);

    printf("mean:%f,variance:%f,stand:%f\n",MEAN,VARIANCE,STAND);

    return 0;
}
