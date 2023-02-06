// #include <stdio.h>

// int indexofmax(int *arr, int len)
// {
// 	int i;
// 	int index;
// 	int max;

// 	index = 0;
// 	i = 0;
// 	max = arr[0];
// 	while (i < len)
// 	{
// 		if (max < arr[i])
// 		{
// 			max = arr[i];
// 			index = i;
// 		}
// 		i++;
// 	}
// 	return (index);
// }

// int indexs(int *tab,int len,int num)
// {
// 	int i = 0;
// 	int ind = indexofmax(tab, len);
// 	int cnter = (len + 1) / 2;
// 	printf("%d",cnter);

// 	while (i < len)
// 	{

// 			if ((tab[i] > num && tab[i] < tab[ind]))
// 				ind = i;
// 			i++;
// 	}

// 	return ind;
// }

// int main()
// {
// 	int tab[10] = {0,1,11,3,0,5,6,8,19,10};

// int in = indexs(tab,10,9);
// printf(" index ii = %d [] ",in);
// if (in <= 6 )
// {
// 	printf("index = %d", in );
// }
// else
// {
// 	printf("index = %d",(in - 11));
// }
// }
