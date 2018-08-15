#include<iostream>  //C++系统内部头文件故意去掉了.h。防止和用户的重名了

using namespace std;

//程序区、栈区、堆区

/**
*   www.cplusplus.com C++内部库
*   C++和标准C++
*
*
*   C++新特性学习
*   1. C++结构体内可以有成员函数
*   2. 新增bool类型，实际就是char类型
*   3. 引用型变量
*   4. 命名空间
*   5. C++输入输出
*   6. 重载
*   7. new内存申请
*   8. 内联函数inline
*   9. 结构体成员函数，class就是加入了成员函数
*/

/**  
*   输入输出和命名空间
*/
void put_out(void)
{
	int a = 100;
	cout << "hello"<<"\n"<<"a="<<a<<"\n";

	//能够自动识别类型,下面识别是一个地址
	cout << "&a=0x" << &a << "\n";
}

void get_in(void)
{
	int a = 10;

	cout << "请输入一个值，以回车结束：";
	cin >> a;
	cout << a<<"\n";
}


/**
*  int i =10 ； int &b=i;b代理了i。
*  1.引用性变量定义时必须挂在某个变量上，
*  2.引用变量和来源变量任何一个变化，另一个都会变化
*  3.引用性变量传参数,内部实际是指针变量
*/
void refrence_var(char& c)
{
	int i = 10;
	int &j = i;

	printf("i=%d,j=%d\n", i, j);
	printf("&i=0x%p,&j=0x%p\n", &i, &j);//地址是一致的
	printf("size=%d,c=%d\n", sizeof(c), c);
	c = 'A';
}

/*
* namespace命名空间
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
* 重载
* 函数名相同，参数不同(类型、名字)
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
*   堆申请 new
*   释放delete,成对使用
/************************************************************************/

struct man
{
	char  *name;
	char age;
	char *sex;
};
void new_heap(void)
{
	int *p = new int;//堆上申请一个变量
	int *p1 = new int[10];//在堆上申请一个数组
	
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
* 结构体成员函数
* 
* 1 加了成员函数的结构体，大小并不会改变！！！成员函数不占结构体大小。
* 2 类.方法 其实就是把类的地址传给该方法。该方法的内存不在该结构体内，在外部
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

	//输入输出
	put_out();
	get_in();

	//引用性变量
	refrence_var(c);//a
	printf("later c=%d\n",c);//A

	//namespace
	wangsir::print_hello();//hello
	print_hello();//hello world

	//重载
	over_load(10, 'q');
	over_load(100.1);


	//堆
	new_heap();

	//成员函数
	struct_member_function();


	getchar();
	getchar();
	return 0;
}
