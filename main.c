#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct row
{
    int x;
    int y;
};

int check(struct row array[], int size, int element);

bool FIFO(int pages)
{
    int value = 0, faults = 0;
    int counter = 0;
    int Return = 0;
    int getOut = 0;
    scanf("%d",&value);
    struct row array[pages];
    for(int i=0; i<pages; i++)
    {
        array[i].x = -1;
        array[i].y = -1;
    }
    printf("Replacement Policy = FIFO\n");
    printf("-------------------------------------\n");
    printf("Page   Content of Frames");
    printf("\n----   -----------------\n");
    while(value != -1)
    {
        Return = check(array,pages,value);
        if(Return > -1)
        {
            printf("%02d ",value);
            printf("    ");
            int m = 0;
            while(m < pages)
            {
                if(array[m].x == -1 )
                    printf("");
                else
                    printf("%02d ",array[m].x);
                m++;
            }
            printf("\n");
        }
        else
        {
            array[counter].x = value;
            if(getOut < pages)
            {
                printf("%02d ",value);
                printf("    ");
                int m = 0;
                while(m < pages)
                {
                    if(array[m].x == -1 )
                        printf("");
                    else
                        printf("%02d ",array[m].x);
                    m++;
                }
                printf("\n");
            }
            else
            {
                printf("%02d ",value);
                printf("F   ");
                int m = 0;
                while(m < pages)
                {
                    if(array[m].x == -1 )
                        printf("");
                    else
                        printf("%02d ",array[m].x);
                    m++;
                }
                printf("\n");
                faults++;
            }
            counter++;
            counter = counter % pages;
            getOut++;
        }
        scanf("%d",&value);
    }
    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);
    return false;

}

bool LRU(int pages)
{

    int value = 0, faults = 0;
    int counter = 1;
    int Return = 0;
    int getOut = 0;
    scanf("%d",&value);
    struct row array[pages];
    for(int i=0; i<pages; i++)
    {
        array[i].x = -1;
        array[i].y = -1;
    }
    printf("Replacement Policy = LRU\n");
    printf("-------------------------------------\n");
    printf("Page   Content of Frames");
    printf("\n----   -----------------\n");
    while(value != -1)
    {

        Return = check(array,pages,value);
        if(Return > -1)
        {
            array[Return].y = counter;
            printf("%02d ",value);
            printf("    ");
            int m = 0;
            while(m < pages)
            {
                if(array[m].x == -1 )
                    printf("");
                else
                    printf("%02d ",array[m].x);
                m++;
            }
            printf("\n");
        }
        else
        {
            int place = 0;
            int zz = 0;
            while(zz < pages)
            {
                if(array[zz].y < array[place].y && array[place].y != -1)
                    place = zz;
                zz++;
            }
            Return = place;
            array[Return].x = value;
            array[Return].y = counter;
            if(getOut < pages)
            {
                printf("%02d ",value);
                printf("    ");
                int m = 0;
                while(m < pages)
                {
                    if(array[m].x == -1 )
                        printf("");
                    else
                        printf("%02d ",array[m].x);
                    m++;
                }
                printf("\n");
            }
            else
            {
                printf("%02d ",value);
                printf("F   ");
                int m = 0;
                while(m < pages)
                {
                    if(array[m].x == -1 )
                        printf("");
                    else
                        printf("%02d ",array[m].x);
                    m++;
                }
                printf("\n");
                faults++;
            }
            getOut++;
        }
        counter++;
        scanf("%d",&value);
    }
    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);
    return true;
}

bool CLOCK(int pages)
{
    int value = 0, faults = 0;
    int counter = 0;
    int Return = 0;
    int getOut = 0;
    scanf("%d",&value);
    struct row array[pages];
    for(int i=0; i<pages; i++)
    {
        array[i].x = -1;
        array[i].y = 0;
    }
    printf("Replacement Policy = CLOCK\n");
    printf("-------------------------------------\n");
    printf("Page   Content of Frames");
    printf("\n----   -----------------\n");
    while(value != -1)
    {

        Return = check(array,pages,value);
        if(Return > -1)
        {
            array[Return].y = 1;
            printf("%02d ",value);
            printf("    ");
            int m = 0;
            while(m < pages)
            {
                if(array[m].x == -1 )
                    printf("");
                else
                    printf("%02d ",array[m].x);
                m++;
            }
            printf("\n");
        }
        else
        {
            while(array[counter].y != 0)
            {
                array[counter].y = 0;
                counter++;
                counter = counter % pages;
            }
            array[counter].x = value;
            array[counter].y = 1;
            if(getOut < pages)
            {
                printf("%02d ",value);
                printf("    ");
                int m = 0;
                while(m < pages)
                {
                    if(array[m].x == -1 )
                        printf("");
                    else
                        printf("%02d ",array[m].x);
                    m++;
                }
                printf("\n");
            }
            else
            {
                printf("%02d ",value);
                printf("F   ");
                int m = 0;
                while(m < pages)
                {
                    if(array[m].x == -1 )
                        printf("");
                    else
                        printf("%02d ",array[m].x);
                    m++;
                }
                printf("\n");
                faults++;
            }
            counter++;
            counter = counter % pages;
            getOut++;
        }
        scanf("%d",&value);
    }
    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);
    return false;
}

int main()
{
    int pages;
    scanf("%d",&pages);
    char type[10];
    scanf("%s",type);
    if(strcmp(type,"FIFO")==0)
        FIFO(pages);
    else if(strcmp(type,"LRU")==0)
        LRU(pages);
    //else if(strcmp(type,"OPTIMAL")==0)
    //    OPTIMAL(pages);
    else if(strcmp(type,"CLOCK")==0)
        CLOCK(pages);
    return 0;
}

int check(struct row arr[], int size, int element)
{
    int i = 0;
    while(i < size)
    {
        if(arr[i].x == element)
            return i;
        i++;
    }
    return -1;
}

