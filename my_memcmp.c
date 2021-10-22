//本程序进行memcmp函数的模拟实现
//memcmp函数主要进行内存内容的比较，
//将目标地址开始的N个字节与源地址开始的N字节中内容进行比较，
//相同返回0，不同返回目标内容与源内容的插值
//因此，需要三个输入参数：目标地址（地址中内容类型不定，因此用void类型）；源地址（同理用void类型）；以及字节数N
//输出0或者差值（类型为int）


#include<stdio.h>
#include<assert.h>

int my_memcmp(const void* dest,const void* src,size_t num)
{
	assert(dest && src);
	//将无类型指针强制转换为字符指针，并对指针内内容进行比较
	//相同自加1，进入下一字节并且字节数num自减1
	while (*((char*)dest)++ == *((char*)src)++)
	{
		num--;
		if (num < 0)
			return 0;
	}
	return *(--(char*)dest)- *(--(char*)src);//当不同时，由于之前一步完成时会自增1，因此需要返回前一字节内容的相减
}


int main()
{
	int arr1[] = { 1,2,3,4,5,6,15,8,9 };
	int arr2[] = { 1,2,3,4,5,6,12,9 };
	int ret = my_memcmp(arr1, arr2, sizeof(arr2));//判断arr2中内容和arr1中内容是否相同
	printf("ret=%d\n", ret);
	return 0;
}