//031620316 Zhang Shibo
//Josephus Question

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct people
{
	int num;
	int Xuhao;
	struct people *next;
};
static struct people *head = NULL;



struct people *CreatList(void)			//创建循环链表；
{
	struct people *rear;
	struct people *p;
	int m = 0;
	rear = NULL;						//不加此句将提示"使用了可能未初始化的本地指针变量rear".???
	while (1)							//构建循环链表
	{
		p = (struct people*)malloc(sizeof(struct people));		//为链节申请存储地址
		p->Xuhao = ++m;					//构建每个人的序号
		printf("\n输入每个人的数字，以-1为结束标志:");
		scanf_s("%d", &p->num);
		if (p->num == -1)break;			//以-1为结束标志，跳出循环
		if (head == NULL) head = p;		
		else rear->next = p;
		rear = p;
	}
	if (rear != NULL) rear->next = head;		//循环链表
	printf("\n建表结束\n");
	return head;
}
void Killone(struct people *p, int m)
{
	int i, k;
	struct people* r;			//辅助指针
	if (m == 1)p = p->next;
	else
	{
		for (i = 2; i<m; i++)	
			p = p->next;
	}
	r = p->next;			//删除对应节点
	k = r->num;
	printf("%d      ", k);
	printf("%d\n", r->Xuhao);
	p->next = r->next;			
	free(r);				//释放辅助r的内存，节省内存空间
	if (p != p->next)
		Killone(p->next, k);
	else
	{
		printf("%d      ", p->num);
		printf("%d\n", p->Xuhao);
	}

}
void main()
{
	printf("实验一：约瑟夫斯问题求解\n姓名：张世博\n学号：031620316\n=========Enter开始程序==========\n");
	system("pause");
	int m;
	struct people *pos;
	CreatList();
	printf("请输入初始值m:");
	scanf_s("%d", &m);
	printf("密码  顺序\n");
	pos = head;
	Killone(pos, m);
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);			//显示运行时间
	timeinfo = localtime(&rawtime);
	printf("\n");
	printf("Current local time and date: %s", asctime(timeinfo));

	system("pause");
}

