//���������memcmp������ģ��ʵ��
//memcmp������Ҫ�����ڴ����ݵıȽϣ�
//��Ŀ���ַ��ʼ��N���ֽ���Դ��ַ��ʼ��N�ֽ������ݽ��бȽϣ�
//��ͬ����0����ͬ����Ŀ��������Դ���ݵĲ�ֵ
//��ˣ���Ҫ�������������Ŀ���ַ����ַ���������Ͳ����������void���ͣ���Դ��ַ��ͬ����void���ͣ����Լ��ֽ���N
//���0���߲�ֵ������Ϊint��


#include<stdio.h>
#include<assert.h>

int my_memcmp(const void* dest,const void* src,size_t num)
{
	assert(dest && src);
	//��������ָ��ǿ��ת��Ϊ�ַ�ָ�룬����ָ�������ݽ��бȽ�
	//��ͬ�Լ�1��������һ�ֽڲ����ֽ���num�Լ�1
	while (*((char*)dest)++ == *((char*)src)++)
	{
		num--;
		if (num < 0)
			return 0;
	}
	return *(--(char*)dest)- *(--(char*)src);//����ͬʱ������֮ǰһ�����ʱ������1�������Ҫ����ǰһ�ֽ����ݵ����
}


int main()
{
	int arr1[] = { 1,2,3,4,5,6,15,8,9 };
	int arr2[] = { 1,2,3,4,5,6,12,9 };
	int ret = my_memcmp(arr1, arr2, sizeof(arr2));//�ж�arr2�����ݺ�arr1�������Ƿ���ͬ
	printf("ret=%d\n", ret);
	return 0;
}