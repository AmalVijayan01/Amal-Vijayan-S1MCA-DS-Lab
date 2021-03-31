/*
 ============================================================================
 Name        : array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
   int main()
    {

        int array1[10], array2[10], array3[20], m, n, i, j, k = 0;
        setbuf(stdout,NULL);
        printf("\n Enter size of array Array 1: ");
        scanf("%d",&m);
        printf("\n Enter sorted elements of array 1: \n");
        for (i=0;i<m;i++)
        {
            scanf("%d",&array1[i]);
        }

        printf("\n Enter size of array 2: ");
        scanf("%d",&n);

        printf("\n Enter sorted elements of array 2: \n");
        for (i=0;i<n;i++)
        {
            scanf("%d",&array2[i]);
        }
        i=0;
        j=0;
        while (i<m&&j<n)
        {
            if(array1[i]<array2[j])
            {
                array3[k]=array1[i];
                i++;
            }
            else
            {
                array3[k]=array2[j];
                j++;
            }
            k++;
        }
        if (i>=m)
        {
            while(j<n)
            {
                array3[k] = array2[j];
                j++;
                k++;
            }
        }
        if (j>=n)
        {
            while(i<m)
            {
                array3[k]= array1[i];
                i++;
                k++;
            }
        }

        printf("\n merged array is : \n");
        for (i=0;i<m+n;i++)
        {
            printf("\n%d", array3[i]);
        }
    }

