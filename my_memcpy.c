//本程序进行memcpy函数的模拟实现
//memcpy函数进行内存操作，将源地址之后的一定字节数量的内容，复制到目标地址中
//因此，本函数需要三个输入参数：目标地址（因为不确定地址中的内容，因此用void类型），源地址（同理用void类型），字节数量
//输出目标地址(viod类型)

#include<stdio.h>


void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*((char*)dest)++ = *((char*)src)++;//将指针类型强制转换为字符指针，每次增加一个字节。进行数据转移
	}
	return ret;
}


struct Stu
{
	char name[20];
	int age;
};


int main()
{
	//int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	//int arr2[] = { 1,2,3,5,8,6 };
	//char arr1[] = "abdjkkgkajkhg";
	//char arr2[] = "ahfdaighvi";

	struct Stu a[] = { {"张三",20},{"李四",15} };
	struct Stu b[3] = { 0 };
	my_memcpy(b, a, sizeof(a));//利用my_memcpy函数将arr2中数据复制到arr1的前面位置
	return 0;
}