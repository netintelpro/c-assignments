#include <stdio.h>
#define MAXSIZE 10

int * sort(int num, int array[]) {
	int i, j, temp;

	for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

   return array;
}


int main()
{
	int array[MAXSIZE];
    int i, j, num, temp;
    /* a pointer to an int */
   int *p;
 
    printf("How many numbers will you enter? \n");
    scanf("%d", &num);
    printf("Enter numbers one by one \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }
    

    p = sort(num,array);

    printf("Sorted: \n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", array[i]);
    }

    

    return 0;

}