#include "stdafx.h"
#include <iostream>


int main()
{
	//numbers of top
	const int n = 6;

	//init matrix of road
	int a[n][n] = {
		{ 0, 7, 9, 0, 0, 14 },
		{ 7, 0, 10, 15, 0, 0 },
		{ 9, 10, 0, 11, 0, 0 },
		{ 0, 15, 11, 0, 6, 9 },
		{ 0, 0, 0, 6, 0, 9 },
		{ 14, 0, 2, 0, 9, 0 }
	};

	int d[n]; //distance
	int v[n]; //visited or not

	//any large number ~ infinity
	int x = 999999;

	//init d and v 
	for (int  i = 0; i < n; i++)
	{
		d[i] = x;
		v[i] = 1; //not visited
	}

	d[0] = 0;
	while (true)
	{
		int min = x;
		int index = -1;
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 1 && d[i] < min)
			{
				min = d[i];
				index = i;
			}
		}

		if (index != -1)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[index][i] > 0)
				{
					int temp = min + a[index][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
				v[index] = 0;
			}
		}
		else
		{
			printf("min distance to every top: \n");
			for (int i = 0; i < n; i++)
			{
				printf("%10d \n", d[i]);
			}
			system("pause");
			return 0;
		}	
	}
}

