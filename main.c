#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#define MIN -15
#define MAX 100

int *MakeArr(int count);
void RandArr (int *c, int count);
int PutArr(int *c, int count);
void SwapItem (int *c, int first, int second);
void BubbleSort(int *c, int count);
void SelectSort (int *c, int count);
void IncertionSort (int *c, int count);
void ShakeSort(int *c, int count);
void FastSort(int *c, int Start, int End);
void Sort_shell(int *c, int count);
void mkHeap (int *c, int count);
void RmTopItem (int *c, int count);
void SortHeap (int *c, int count);
void SortMerge (int *c, int start,  int end);
void SortCount(int *c, int count);
void SortRandom (int *c, int count);
void OddEvenSort (int *c, int count);

void main()
{
    int num;
    int *link=NULL;
    int CountItem=10;

    setlocale(LC_ALL, "");
    srand(time(NULL));
    puts("Выберите функцию:");
    puts("1 - Создать массив");
    puts("2 - Рандомизированть массив");
    puts("3 - Вывести массив");
    puts("4 - Удалить массив");
    puts("5 - Пузырьковая сортировка");
    puts("6 - Сортировка выборкой");
    puts("7 - Сортировка вставкой");
    puts("8 - Быстрая сортировка");
    puts("9 - Сортировка Шелла");
    puts("10 - Пирамидальная сортировка");
    puts("11 - Сортировка слиянием");
    puts("12 - Сортировка подсчетом");
    puts("13 - Рандомная сортировка");
    puts("14 - Гномья сортировка");
    puts("15 - Четно-нечетная сортировка");
    puts("0 - Выход из программы");
    do
    {
        rewind(stdin);
        putchar('№');
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            {
                if(link)
                {
                    puts(".....Массив уже создан.....");
                    break;
                }
                printf("Введите кол-во элементов массва: ");
                scanf("%d", &CountItem);
                link = MakeArr(CountItem);
                break;
            }
        case 2:
            {
                if(!link)
                {
                    puts(".....Массив пуст.....");
                    break;
                }
                RandArr(link, CountItem);
                break;
            }
        case 3:
            {
                if(!link)
                {
                    puts(".....Массив пуст.....");
                    break;
                }
                PutArr(link, CountItem);
                break;
            }
        case 4:
            {
                free(link);
                puts(".....Массив удален.....");
                link=NULL;
                break;
            }
        case 5:
            {
                if(!link)
                {
                    puts(".....Массив пуст.....");
                    break;
                }
                ShakeSort(link, CountItem);
                break;
            }
        case 6:
            {
                if(!link)
                {
                    puts(".....Массив пуст.....");
                    break;
                }
                SelectSort(link, CountItem);
                break;
            }
        case 7:
            {
                if(!link)
                {
                    puts(".....Массив пуст.....");
                    break;
                }
                IncertionSort (link, CountItem);
                break;
            }
        case 8:
            {
                if(!link)
                {
                    puts(".....Массив пуст.....");
                    break;
                }
                FastSort(link, 0, CountItem-1);
                break;
            }
        case 9:
            {
            if(!link)
            {
                puts(".....Массив пуст.....");
                break;
            }
            Sort_shell (link, CountItem);
            break;
            }
        case 10:
            {
            if(!link)
            {
                puts(".....Массив пуст.....");
                break;
            }
            SortHeap(link, CountItem);
            break;
            }
        case 11:
            {
            if(!link)
            {
                puts(".....Массив пуст.....");
                break;
            }
            SortMerge(link, 0,CountItem-1);
            break;
            }
        case 12:
            {
            if(!link)
            {
                puts(".....Массив пуст.....");
                break;
            }
            SortCount(link, CountItem);
            break;
            }
        case 13:
            {
            if(!link)
            {
                puts(".....Массив пуст.....");
                break;
            }
            SortRandom(link, CountItem);
            break;
            }
        case 14:
            {
            if(!link)
            {
                puts(".....Массив пуст.....");
                break;
            }
            SortGnom(link, CountItem);
            break;
            }
        case 15:
            {
            if(!link)
            {
                puts(".....Массив пуст.....");
                break;
            }
            OddEvenSort(link, CountItem);
            break;
            }
        }
    }
    while (num!=0);
    free(link);
    exit(0);
}


int *MakeArr(int count)
{
    register int i;
    int *Arr = malloc(sizeof(int) * count);
    for (i=0; i<count; i++)
    {
        *(Arr+i)=rand()%(MAX-MIN+1)+MIN;
    }
    return Arr;
}

void RandArr (int *c, int count)
{
    register int i, j;
    for(i=0; i<count; i++)
    {
        j=rand()%(i-count)+i;
        SwapItem(c, i, j);
    }
}


int PutArr(int *c, int count)
{
    register int i;
    putchar('\n');
    for(i=0; i<count; i++)
    {
        printf("%d\n", c[i]);
    }
}


void SwapItem (int *c, int first, int second)
{
    int temp;
    temp = c[first];
    c[first]=c[second];
    c[second]=temp;
}

void BubbleSort(int *c, int count)
{
    register int mark = 1, i;
    while (mark)
    {
        mark=0;
        for(i=1; i<count; i++)
        {
            if(c[i]<c[i-1])
            {
                SwapItem(c, i, i-1);
                mark=1;
            }
        }
    }
}

void SelectSort (int *c, int count)
{
    int swap, min;
    register int i, j;
    for (i=0; i<count; i++)
    {
        min=c[i];
        swap=i;
        for(j=i; j<count; j++)
        {
            if(min>=*(c+j))
            {
                swap=j;
                min=c[j];
            }
        }
        SwapItem(c, i, swap);
    }
}


void IncertionSort (int *c, int count)
{
    register int i, j;
    int temp;

    for(i=1; i<count; i++)
    {
        temp=*(c+i);
        for(j=i-1; *(c+j)>temp && j>=0; j--)
        {
            *(c+j+1)=*(c+j);
        }
        *(c+j+1)=temp;
    }
}

void ShakeSort(int *c, int count)
{
    register int mark = 1, i;
    while (mark)
    {
        mark=0;
        for(i=1; i<count; i++)
        {
            if(c[i]<c[i-1])
            {
                SwapItem(c, i, i-1);
                mark=1;
            }
        }
        for(i=count-1; i>0; i--)
        {
            if(c[i]<c[i-1])
            {
                SwapItem(c, i, i-1);
                mark=1;
            }
        }
    }
}

void FastSort(int *c, int Start, int End)
{
    if(Start>=End) return;
    int devider = c[Start];
    int left=Start, right=End;

    while(1)
    {
        while(c[right]>=devider)
        {
            right--;
            if(right<=left) break;
        }
        if(right<=left)
        {
            c[left]=devider;
            break;
        }

        c[left]=c[right];
        left++;

         while(c[left]<devider)
        {
            left++;
            if(right<=left) break;
        }
        if(right<=left)
        {
            left=right;
            c[left]=devider;
            break;
        }
        c[right]=c[left];
    }

    FastSort(c, Start, left-1);
    FastSort(c, left+1, End);
    return;

}

void Sort_shell(int *c, int count)
{
    int i, j, step;
    int tmp;
    for (step = count / 2; step > 0; step /= 2)
        for (i = step; i < count; i++)
        {
            tmp = c[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < c[j - step])
                    c[j] = c[j - step];
                else
                    break;
            }
            c[j] = tmp;
        }
}


void mkHeap (int *c, int count)
{
    register int i;
    int index, perent;
    for(i=0; i<count; i++)
    {
        index=i;
        while (index)
        {
            perent=(index-1)/2;
            if(c[index]<=c[perent]) break;
            SwapItem(c, index, perent);
            index=perent;
        }
    }
}

void RmTopItem (int *c, int count)
{
    if(!count) return;

    register int i;
    int index=0, child_1, child_2, swap_child;

    while(1)
    {
        child_1=2*index+1;
        child_2=2*index+2;

        if(child_1>count) child_1=index;
        if(child_2>count) child_2=index;
        if(c[child_1]<=c[index] && c[child_2]<=c[index]) break;

        if(c[child_1]>c[child_2])
        {
            swap_child=child_1;
        }else swap_child=child_2;

        SwapItem(c, index, swap_child);
        index=swap_child;
    }
}

void SortHeap (int *c, int count)
{
    register int i;
    mkHeap(c, count);
    count--;
    while(count)
    {
        SwapItem(c, 0, count);
        count--;
        RmTopItem (c, count);
        }
}

void SortMerge (int *c, int start,  int end)
{
    if (start>=end) return;

    register int i=0,j=0, mid=0;
    int lo;
    mid=start +(end-start)/2;

    SortMerge (c, start,  mid);
    SortMerge (c, mid+1,  end);

    int buf[end-start+1];//создаем буффер
    for (i=start; i<=end; i++)
    {
        buf[j]=c[i]; //копируем эллементы из двух подмассивов
        j++;
    }

    lo=start; //первый индекс результирующего массива
    i=0; //первый индекс первого массива
    j=(end-start)/2+1; //первый индекс второго массива

    while (i<=((end-start)/2) && j<end-start+1)
    {
        if(buf[i]<=buf[j]) c[lo++]=buf[i++]; //если елемент в первой части массива меньше, то мы его заносим, а второй остается в буффере
        else c[lo++]=buf[j++];
    }
    while(i<=(end-start)/2) c[lo++]=buf[i++]; //Второй массив закончился, загоняем оставшиеся первого
    while(j<(end-start+1)) c[lo++]=buf[j++]; //Первый массив закончился, загоняем оставшиеся второго
    return;
}

void SortCount(int *c, int count)
{
    register int i;
    int A[MAX-MIN+1];

    for(i=0; i<MAX-MIN+1; i++) A[i]=0;//инициализируем массив нулями

    for(i=0; i<count; i++)
    {
        A[*(c+i)-MIN]++; // считаем количество каждого элемента
    }
    for(i=0; i<MAX-MIN+1; i++)
    {
        while(A[i])
        {
            *c=i;
            c++;
            A[i]--;
        }
    }
    return;
}

void SortRandom (int *c, int count)
{
    register int i;
    int mark=1, curcle=0;
    while(mark)
    {
        mark=0;
        curcle++;
        for(i=1; i<count; i++)
        {
            if(c[i]<c[i-1])
            {
                mark=1;
                RandArr(c, count);
                break;
            }
        }
    }
    printf("Количество повторений: %d\n", curcle);
}


void SortGnom(int *c, int count)
{
    register int i;
    for(i=1; i<count; i++) //проходим по всем элементам
    {
            while(c[i]<c[i-1] && (i-1)>=0)
            {
                SwapItem(c,i, i-1);
                i--;
            }
    }
}

void OddEvenSort (int *c, int count)
{
    register int i, j=0;
    int mark=1;

    while(mark)
    {
     mark=0;
     for(i=j%2+1; i<count; i+=2)
     {
      if(c[i]<c[i-1])
        {
            SwapItem(c, i, i-1);
            mark=1;
        }
    }
    j++;
}
    return;
}
