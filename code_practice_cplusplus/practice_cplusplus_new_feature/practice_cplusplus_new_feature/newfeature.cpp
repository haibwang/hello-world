#include<iostream>  //C++ϵͳ�ڲ�ͷ�ļ�����ȥ����.h����ֹ���û���������

using namespace std;

//��������ջ��������

/**
*   www.cplusplus.com C++�ڲ���
*   C++�ͱ�׼C++
*
*
*   C++������ѧϰ
*   1. C++�ṹ���ڿ����г�Ա����
*   2. ����bool���ͣ�ʵ�ʾ���char����
*   3. �����ͱ���
*   4. �����ռ�
*   5. C++�������
*   6. ����
*   7. new�ڴ�����
*   8. ��������inline
*   9. �ṹ���Ա������class���Ǽ����˳�Ա����
*/

/**  
*   ��������������ռ�
*/
void put_out(void)
{
	int a = 100;
	cout << "hello"<<"\n"<<"a="<<a<<"\n";

	//�ܹ��Զ�ʶ������,����ʶ����һ����ַ
	cout << "&a=0x" << &a << "\n";
}

void get_in(void)
{
	int a = 10;

	cout << "������һ��ֵ���Իس�������";
	cin >> a;
	cout << a<<"\n";
}


/**
*  int i =10 �� int &b=i;b������i��
*  1.�����Ա�������ʱ�������ĳ�������ϣ�
*  2.���ñ�������Դ�����κ�һ���仯����һ������仯
*  3.�����Ա���������,�ڲ�ʵ����ָ�����
*/
void refrence_var(char& c)
{
	int i = 10;
	int &j = i;

	printf("i=%d,j=%d\n", i, j);
	printf("&i=0x%p,&j=0x%p\n", &i, &j);//��ַ��һ�µ�
	printf("size=%d,c=%d\n", sizeof(c), c);
	c = 'A';
}

/*
* namespace�����ռ�
*/

namespace wangsir
{
	void print_hello(void)
	{
		printf("Hello\n");
	}
}

void print_hello(void)
{
	printf("hello world\n");
}


/************************************************************************
* ����
* ��������ͬ��������ͬ(���͡�����)
/************************************************************************/
void over_load(int a, char b)
{
	cout << "a=" << a << "\n" << "b=" << b << "\n";
}

void over_load(float b)
{
	cout << "sizeof(a)=" << sizeof(b)<<"\n\n";
}

/************************************************************************
*   ������ new
*   �ͷ�delete,�ɶ�ʹ��
/************************************************************************/

struct man
{
	char  *name;
	char age;
	char *sex;
};
void new_heap(void)
{
	int *p = new int;//��������һ������
	int *p1 = new int[10];//�ڶ�������һ������
	
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int i = 0;
	while ( i < _countof(a))
	{
		p1[i] = a[i++];
	}

	delete[]p1;

	man *m = new man;
	m->name = "wangxing";
	m->age = 30;
	m->sex = "boy";



	delete[]m;

}


/*
* �ṹ���Ա����
* 
* 1 ���˳�Ա�����Ľṹ�壬��С������ı䣡������Ա������ռ�ṹ���С��
* 2 ��.���� ��ʵ���ǰ���ĵ�ַ�����÷������÷������ڴ治�ڸýṹ���ڣ����ⲿ
*/

struct Stime
{
	int nHour;
	int nMin;
	int nSec;

	void set_time(int h, int m, int s)
	{
		nHour = h;
		nMin = m;
		nSec = s;
	}
	void print(void)
	{
		cout << nHour << ":" << nMin << ":" << nSec << "\n";
	}
};

void struct_member_function()
{
	Stime Morn, noon;
	Morn.set_time(10, 9, 0);
	noon.set_time(2, 2, 2);
	noon.print();
	Morn.print();
}

int main()
{
	char c = 'a';

	//�������
	put_out();
	get_in();

	//�����Ա���
	refrence_var(c);//a
	printf("later c=%d\n",c);//A

	//namespace
	wangsir::print_hello();//hello
	print_hello();//hello world

	//����
	over_load(10, 'q');
	over_load(100.1);


	//��
	new_heap();

	//��Ա����
	struct_member_function();


	getchar();
	getchar();
	return 0;
}
