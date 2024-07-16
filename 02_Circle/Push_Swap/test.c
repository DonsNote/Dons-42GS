#include <stdio.h>

int main()
{
	long long num[3] = {-2147483649, 1, 9223372036854775807};
	
	int *nums;

	nums = (int *)num;
	
	// 111111111111111111111111 1000 0000 ~ 0000
	// 1111 1111 ~ 1111        여기가 큰 바이트 
	// 0111 1111 1111 1111   1111 1111 1111 1111 -> INT_MAX   작은 바이트 
	// FF FF FF FF FF FF FF 7F (INT_MAX), FF FF FF FF FF FF FF FF (-1)  -> long -2147483649
	// FF FF FF FF FF FF FF FF 

	// 00 00 00 00 00 00 00 80 -> INT_MIN (2의 보수)
	
	// 01 00 00 00 00 00 00 00, 00 00 00 00 00 00 00 00
	// 1111111111111111111111111111111111 -1
	// INT_MAX 
	// -1
	// 1
	// INT_MAX
	// 0

	long long n = 1;
	// 0000 0000 ~~ 0001
	// 01 00 00 00 00 00 00 00 , 00 ~  

	int in;

	in = (int)n;
	printf("%d ", nums[0]);
	printf("%d ", nums[1]);
	printf("%d ", nums[2]);
	printf("%d ", nums[3]);
	printf("%d ", nums[4]);
	printf("%d \n", nums[5]);
	// printf("%d ", nums[3]);
	// 
	// printf("%d ", nums[4]);
	// printf("%d ", nums[5]);
	// printf("%d ", nums[6]);
	// printf("%d ", nums[7]);
	//printf("%d ", in);
}