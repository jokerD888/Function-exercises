#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//5.7 计算组合数C(m,k)即从m个元素里选择k个元素的方法
//int Cmb(int k, int m)
//{
//	int n = m - k;
//	int sm = 1;
//	int sk = 1;
//	int sn = 1;
//	int i = 0;
//	for (i = 1; i <= k; i++)
//	{
//		sk *= i;
//	}
//	for (i = 1; i <= m; i++)
//	{
//		sm *= i;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		sn *= i;
//	}
//	return (sm / sk / sn);
//}
//int main(void)
//{
//	int k, m;
//	scanf("%d%d", &k, &m);
//	int ret=Cmb(k, m);
//	printf("%d\n", ret);
//	return 0;
//}
//


//5.11
//用下面给定的代码调用，实现函数int CommonFactors(int a,int b)计算a和b的所有公约数。
//第一次调用，返回最大公约数。以后只要再使用相同参数调用，每次返回下一个小些的公约数。 无公约数时返回-1。
int CommonFactors(int a, int b)
{
	static int count = 0;
	++count;
	int n = 0;
	int ret = 0;
	int tmp = 0;
	while (b>0)
	{
		ret = a % b;
		if (ret == 0)
		{
			n++;
			if (n == count)
			{
				return b;
			}
			else
			{
				int j = 2;
				while (n != count)
				{
					
					if (b % j == 0)
					{
						tmp=b/j;
						++n;
					}
					if (j > b)
						return -1;
					j++;
					
				}
				return tmp;
			}
		}
		a = b;
		b = ret;
	
	}
	//++counter;
	return -1;
}
//答案(暴力穷尽法）
int CommonFactors1(int a, int b)
{
	static int num1 = -1;
	static int num2 = -1;
	static int curFactor;

	if (a < 0 || b < 0)
	{
		return -1;
	}

	if (num1 != a || num2 != b)
	{
		num1 = a;
		num2 = b;
		curFactor = a > b ? b: a; //curFactor 置为两个数中较小的那个
	}

	while (curFactor > 0)
	{
		if (a % curFactor == 0 && b % curFactor == 0)
		{
			return curFactor--;
		}
		curFactor--;
	}
	return -1;
}
//改进，增强了程序健壮性，但相比较与答案函数，可读性较低，逻辑较为混乱
int CommonFactors3(int a, int b)
{
	static int num1 = -1;
	static int num2 = -1;
	static int count = 0;
	int ret = 0;
	int n = 0;
	int tmp = 0;
	++count;

	if (a < 0 || b < 0)//增强程序健壮性
	{
		return -1;
	}
	if (num1 != a || num2 != b)//判断是否是上次调用的相同参数
	{
		num1 = a;
		num2 = b;
		count = 1;
	}
	while (b > 0)
	{
		ret = a % b;
		if (ret == 0)
		{
			n++;
			if (n == count)
			{
				return b;
			}
			else
			{
				int j = 2;
				while (n != count)
				{

					if (b % j == 0)
					{
						tmp = b / j;
						++n;
					}
					if (j > b)
						return -1;
					j++;

				}
				return tmp;
			}
		}
		a = b;
		b = ret;

	}
	//++counter;
	return -1;
}
int main(void)
{
	int sub;
	while ((sub = CommonFactors3(100, 50)) > 0)
	{
		static int counter = 1;
		printf("Common factor %d is %d\n", counter++, sub);
	}
	return 0;
}