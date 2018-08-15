

#include<stdio.h>
#include<string.h>

/*
 *  ��Խӿڱ�̣���Ҫ���ʵ�ֱ��
 */

//�ӿڶ���
struct fly_interface
{
	void(*flying)();
};

struct quack_interface
{
	void(*quacking)();
};

/* 
 * �ӿڵ�ʵ�ֵĺ������ɺ���ָ��ָ����ʵ���൱��class����ķ�����
 * ֻ�����ڽṹ��ԭ�����������,java��ʵ����ֻ��Ҫnew�Ϳ����ˣ�����ʵ��ʱ��
 * ����Ҫ�󶨺���ָ�룬������ôһ��
*/
void mallard_duck_flying(void)
{
	printf("i'm a mallard duck, i can fly !\n");
}

void wooden_duck_flying(void)
{
	printf("i'm a wooden duck, i can't fly !\n");
}

void mallard_duck_quacking(void)
{
	printf("i'm a mallard duck, i can quack:ga ga ga ~~~~\n");
}

void wooden_duck_quacking(void)
{
	printf("i'm a wooden duck, i cant quack: wu wu wu ....\n");
}

//�ӿڿ�ʼʵ��
struct fly_interface fly_mallard_imp =  //�൱��new�����ǻ���Ҫ�󶨷���
{
	&mallard_duck_flying               //���ڽṹ�����治���к�����ֻ��ʹ�ú���ָ��
};
struct fly_interface fly_wooden_imp =
{
	&wooden_duck_flying
};
struct quack_interface quack_mallard_imp =
{
	&mallard_duck_quacking
};
struct quack_interface quack_wooden_imp =
{
	&wooden_duck_quacking
};


/*
 * ���ඨ��
 *
 * ���췽�����ṹ�崴������ʱ��û�й��췽������Ҫ�ڹ��췽��������ɵľͷŵ�init��������
 * ��ʵ���췽������init����
 *
 */
struct duck_t
{
	struct fly_interface     * fly_interimp;
	struct quack_interface   * quack_interimp;

	void(*performfly)(struct duck_t *);  /**< �ӿڱ�̷��� ,��ķ��������ܹ������Լ������Ժͷ�����*/
	void(*performquack)(struct duck_t *);/**< �ӿڱ�̷��� */
	void(*display)(void);                /**< ���󷽷� */
};

//����ķ���
void performfly(struct duck_t * duck)
{
	duck->fly_interimp->flying();
}

void performquack(struct duck_t * duck)
{
	duck->quack_interimp->quacking();
}

void display(void)
{
	printf("beautiful !!!\n");
}


//��������
struct duck_sub_t
{
	struct duck_t *duck;              /**< �̳г��� */
	void(*init)(struct duck_sub_t *); /**< ���๹�췽����C�������������ɴ����͵��ã�����ʾ���� */
	void(*sub_function)();
};

void sub_function(void)
{
	printf("it is subclass funion!");
}

//����Ĺ��췽��, �ڹ��췽����ʵ�ֽӿڵĶ�̬���� 
void init_mallard(struct duck_sub_t * self)
{
	self->duck->fly_interimp   = &fly_mallard_imp;     //new �ӿ���
	self->duck->quack_interimp = &quack_mallard_imp;   //new �ӿ���

	/* ����ķ�������һ���ģ��ṹ����ִ�������Ҫ�ﶨ�º���ָ�룬���ɹ��캯������*/
	self->duck->performfly   = performfly;       
	self->duck->performquack = performquack;
}
 
void init_wooden(struct duck_sub_t * self)
{
	self->duck->fly_interimp = &fly_wooden_imp;
	self->duck->quack_interimp = &quack_wooden_imp;

	/* ����ķ�������һ���ģ��ṹ����󴴽�����Ҫ�ﶨ�º���ָ�룬���ɹ��캯������*/
	self->duck->performfly = performfly;       
	self->duck->performquack = performquack;
}

//new duck����
struct duck_t mallard_duck_father;  //�����ڴ棬new��ʵ���������ڴ�
struct duck_sub_t mallard_duck =
{
	&mallard_duck_father,
	&init_mallard,
	&sub_function
};

struct duck_t wooden_duck_father;  //�����ڴ棬new��ʵ���������ڴ�
struct duck_sub_t wooden_duck =
{
	&wooden_duck_father,
	&init_wooden,
	&sub_function
};


//ѼȦ
struct duck_sub_t *ducks[] =
{
	&mallard_duck,
	&wooden_duck
};


main()
{
	int i = 0;

	wooden_duck.init(&wooden_duck);           /**< ���ù��췽�� ,���췽�������ܿ����Լ������Եģ����԰��Լ�����ȥ*/
	mallard_duck.init(&mallard_duck);     /**< ���ù��췽�� */

	mallard_duck.duck->performfly(mallard_duck.duck);
	mallard_duck.duck->performquack(mallard_duck.duck);

	wooden_duck.duck->performfly(wooden_duck.duck);
	wooden_duck.duck->performquack(wooden_duck.duck);

	/*----------------------------------------------------------------------*/
	printf("-------------------------------------------------------------\n");
	/* �������ֵĴ���ÿһ��������Խӿڣ�����Ծ���*/
	
	for (i = 0; i < sizeof(ducks) / sizeof(ducks[0]); i++)
	{
		ducks[i]->init(ducks[i]);
		ducks[i]->duck->performfly  (ducks[i]->duck);
		ducks[i]->duck->performquack(ducks[i]->duck);
	}

	getchar();
}