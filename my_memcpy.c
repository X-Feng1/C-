//���������memcpy������ģ��ʵ��
//memcpy���������ڴ��������Դ��ַ֮���һ���ֽ����������ݣ����Ƶ�Ŀ���ַ��
//��ˣ���������Ҫ�������������Ŀ���ַ����Ϊ��ȷ����ַ�е����ݣ������void���ͣ���Դ��ַ��ͬ����void���ͣ����ֽ�����
//���Ŀ���ַ(viod����)

#include<stdio.h>


void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*((char*)dest)++ = *((char*)src)++;//��ָ������ǿ��ת��Ϊ�ַ�ָ�룬ÿ������һ���ֽڡ���������ת��
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

	struct Stu a[] = { {"����",20},{"����",15} };
	struct Stu b[3] = { 0 };
	my_memcpy(b, a, sizeof(a));//����my_memcpy������arr2�����ݸ��Ƶ�arr1��ǰ��λ��
	return 0;
}