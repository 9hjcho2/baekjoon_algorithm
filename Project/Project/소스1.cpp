#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[40] = { 0, };
int check[40] = { 0, };
int count = 0;

void tobin(int s, int e, int k)
{
	if (s >= e)
	{
		for (int i = 0; i < s; i++)
		{
			if (arr[i] == 1)
				count++;
		}
		if (count == k)
		{
			for (int i = 0; i < s; i++)
			{
				printf("%d", arr[i]);
			}
			printf("\n");
		}
		count = 0;
	}
	else
	{
		for (int i = 1; i >= 0; i--)
		{
			if (check[s] == 0)
			{
				check[s] = 1;
				arr[s] = i;
				tobin(s + 1, e, k);
				check[s] = 0;
			}
		}
	}
}

int main() {
	//Please Enter Your Code Here
	int n, k;

	scanf("%d", &n);
	scanf("%d", &k);

	tobin(0, n, k);

	return 0;
}