#include<stdio.h>
#include<graphics.h>//EasyX
#include<stdlib.h>//动态内存分配
#include<string.h>

/*结构体目录*/
/*门店账号、员工评分、服装信息*/
/*详见20行*/

/*函数声名目录*/
/*详见114行*/

//显示全部数据的页面跳转标识
int FlagAI = -1;
//查询找到页面跳转标识
int FlagFPT = -1;

IMAGE img_bk;//背景图片

/*门店账号结构体*/
typedef struct store
{
	char name[10];//门店名称
	char ciper[20];//密码
	struct store* next;
}Store,*linkstore;

/*员工评分结构体*/
typedef struct staff
{
	char name[20];//员工姓名
	char score[20];//评分
	struct staff* next;
}Staff,*linkstaff;

/*服装信息结构体*/
typedef struct clothing
{
	char date1[8];//进货日期  例如：2020.12.12
	char date2[8];//出售日期
	char number[20];//编号
	char type[20];//类型  春/夏/秋/冬装
	char color[20];//颜色
	char size[20];//尺码  S M L XL
	char price1[20];//进价
	char price2[20];//售价
	struct clothing* next;
}Clothing,*linkclothing;



//门店账号单链表初始化函数
linkstore Init_StoreList()
{
	linkstore head;
	head = (Store*)malloc(sizeof(Store));
	head->next = NULL;
	return head;
	
}

//员工评分单链表初始化函数
linkstaff Init_StaffList()
{
	linkstaff head;
	head = (Staff*)malloc(sizeof(Staff));
	head->next = NULL;
	return head;

}

//服装信息单链表初始化函数
linkclothing Init_ClothingList()
{
	linkclothing head;
	head = (Clothing*)malloc(sizeof(Clothing));
	head->next = NULL;
	return head;

}





//bool List_PushBack();
//void List_Print();
//fptr List_find();
//List* creatlist(int n);					//产生链表的函数，n决定链表长度
//void showlist(List* L1);				//打印链表的函数, n用来控制打印的初始位置
//List* insertlist(List* L1, int m, int n);//函数实现链表元素的插入,m控制所插入元素的个数，n用来控制插入的节点
//List* deletelist(List* L1, int n);		//函数实现链表元素的，第n个节点的删除
//List* link_reversed_order(List* p_head);//函数实现链表元素的倒序输出




/*函数声明目录*/

/*初始化函数*/
void Startup();                                        //初始化数据
linkstore Init_StoreList();                            //门店账号单链表初始化
linkstaff Init_StaffList();                            //员工评分单链表初始化
linkclothing Init_ClothingList();                      //服装信息单链表初始化

/*尾插法创建链表函数*/
void creatbyrear_store(linkstore head);                //门店账号链表尾插
void creatbyrear_staff(linkstaff head);                //员工评分链表尾插
void creatbyrear_clothing(linkclothing head);          //服装信息链表尾插

/*界面设置函数*/
void AdminPage0();                                     //管理员界面 首页
void AdminPage1();                                     //管理员界面 第1页  
void AdminPage2();                                     //管理员界面 第2页
void AdminPage3();                                     //管理员界面 第3页
void enroll(linkstore head);                           //登录界面
void reddy();                                          //注册登录返回界面

/*数据操作函数*/
void buy(linkclothing head);                           //进货登记
void sell(linkclothing head);                          //售出登记
void revise();                                         //修改服装信息
void insert();                                         //插入服装信息
void cutoff();                                         //删除服装信息
void ReadInfor();                                      //读取文件



//初始化数据
void Startup()
{
	initgraph(760, 760);
	loadimage(&img_bk, "bk1.jpg", 760, 760);//读取图片
}
//首页画面  m1
void FirstPage()
{

	cleardevice();//用当前背景色清空绘图设备，并将当前点移至(0, 0)
	BeginBatchDraw();//开始批量绘图
	putimage(0, 0, &img_bk);//输出图片
	setbkmode(TRANSPARENT);//设置背景模式透明

	setfillcolor(GREEN);//填充颜色

	//大标题
	char FirstTitle[20] = { "服装销售管理系统" };
	settextstyle(60, 0, "黑体");
	outtextxy(150, 100, FirstTitle);

	//首页三个选项的背景
	fillrectangle(230, 445, 560, 490);
	fillrectangle(230, 505, 560, 550);
	fillrectangle(230, 565, 560, 610);

	setbkmode(TRANSPARENT);//输出方式

	//三个选项的文字
	settextstyle(40, 0, "黑体");

	//首页三个选项
	char FirstSelect1[20] = { "管理员操作入口" };
	char FirstSelect2[20] = { "用户浏览入口" };
	char FirstSelect3[20] = { "退出系统" };
	outtextxy(240, 450, FirstSelect1);
	outtextxy(240, 510, FirstSelect2);
	outtextxy(240, 570, FirstSelect3);

	FlushBatchDraw();
	EndBatchDraw();

	//鼠标操作1
	MOUSEMSG m1;
	//进入主界面选项操作界面
	while (1)
	{
		m1 = GetMouseMsg();//获取鼠标操作
		if (m1.x >= 230 && m1.x <= 560 && m1.y >= 445 && m1.y <= 490)
		{
			setlinecolor(RED);
			rectangle(230, 445, 560, 490);

			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				reddy();//登录注册返回界面
			}
		}
		else if (m1.x >= 230 && m1.x <= 560 && m1.y >= 505 && m1.y <= 550)//普通用户界面
		{
			setlinecolor(RED);
			rectangle(230, 505, 560, 550);
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				
			}
		}
		else if (m1.x >= 230 && m1.x <= 560 && m1.y >= 565 && m1.y <= 610)//退出
		{
			setlinecolor(RED);
			rectangle(230, 565, 560, 610);
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		//鼠标不在上面悬停
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 445, 560, 490);
			rectangle(230, 505, 560, 550);
			rectangle(230, 565, 560, 610);
		}
	}
}
//注册登录返回界面  m2
void reddy(linkstore head)
{
	initgraph(760, 760);
	cleardevice();//清屏函数
	//定义第二个鼠标操作
	MOUSEMSG m2;

	cleardevice();
	IMAGE img_bk;;
	loadimage(&img_bk, "bk1.jpg", 760, 760);
	putimage(0, 0, &img_bk);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "管" };
	char SecondTitle2[5] = { "理" };
	char SecondTitle3[5] = { "员" };
	char SecondTitle4[5] = { "操" };
	char SecondTitle5[5] = { "作" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };


	settextstyle(50, 0, "黑体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);


	setbkmode(TRANSPARENT);


	//三个选项的背景
	fillrectangle(230, 240, 560, 285);
	fillrectangle(230, 370, 560, 415);
	fillrectangle(230, 500, 560, 545);

	setbkmode(TRANSPARENT);

	//三个选项的文字
	settextstyle(40, 0, "黑体");

	//三个选项
	char SecondSelect1[20] = { "注册" };
	char SecondSelect2[20] = { "登录" };
	char SecondSelect3[20] = { "返回" };


	outtextxy(270, 240, SecondSelect1);
	outtextxy(270, 370, SecondSelect2);
	outtextxy(350, 500, SecondSelect3);

	FlushBatchDraw();
	//进入主界面选项操作界面
	while (1)
	{
		m2 = GetMouseMsg();//获取鼠标操作
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 240 && m2.y <= 285)
		{
			setlinecolor(RED);
			rectangle(230, 240, 560, 285);
			if (m2.uMsg == WM_LBUTTONDOWN)
			{
				creatbyrear_store(head);//门店账号链表尾插(注册）
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 370 && m2.y <= 415)
		{
			setlinecolor(RED);
			rectangle(230, 370, 560, 415);
			if (m2.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				enroll(head);//登录流程
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 500 && m2.y <= 545)
		{
			setlinecolor(RED);
			rectangle(230, 500, 560, 545);
			if (m2.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				FirstPage();//返回
			}
		}
		//鼠标不在上面悬停
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 240, 560, 285);
			rectangle(230, 370, 560, 415);
			rectangle(230, 500, 560, 545);
		}
	}
}
//登录流程
void enroll(linkstore head)
{
	char ReceAcctNumber[64];
	TCHAR InputAcct[] = _T("请输入用户名");
	InputBox(ReceAcctNumber, 10, InputAcct);

	char ReceAcctPassWord[64];
	TCHAR InputPass[] = _T("请输入密码");
	InputBox(ReceAcctPassWord, 10, InputPass);

	//如果用户名和密码都正确才进度到管理员界面
	//否则弹窗提示错误
	Store* p;
	p = head->next;
	int m = 0;
	while (p)
	{
		if (strcmp(p->name, ReceAcctNumber) == 0 && strcmp(p->ciper, ReceAcctPassWord) == 0)
		{
			m++;
			cleardevice();
			AdminPage1();//管理员界面
		}
	}
	if(m==0)
	{
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "用户名或密码错误!", "提示", MB_OK);
	}
}
//管理员界面 首页  m3
void AdminPage0()
{
	initgraph(760, 760);
	cleardevice();//清屏函数
	//定义第三个鼠标操作
	MOUSEMSG m3;

	cleardevice();
	IMAGE img_bk;;
	loadimage(&img_bk, "bk1.jpg", 760, 760);
	putimage(0, 0, &img_bk);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "管" };
	char SecondTitle2[5] = { "理" };
	char SecondTitle3[5] = { "员" };
	char SecondTitle4[5] = { "操" };
	char SecondTitle5[5] = { "作" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };


	settextstyle(50, 0, "黑体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);


	setbkmode(TRANSPARENT);


	//三个选项的背景
	fillrectangle(230, 240, 560, 285);
	fillrectangle(230, 370, 560, 415);
	fillrectangle(230, 500, 560, 545);

	setbkmode(TRANSPARENT);

	//三个选项的文字
	settextstyle(40, 0, "黑体");

	//三个选项
	char SecondSelect1[20] = { "进货/售出登记" };
	char SecondSelect2[20] = { "删改服装信息" };
	char SecondSelect3[20] = { "折扣活动/员工评分" };


	outtextxy(270, 240, SecondSelect1);
	outtextxy(270, 370, SecondSelect2);
	outtextxy(350, 500, SecondSelect3);

	FlushBatchDraw();
	//进入主界面选项操作界面
	while (1)
	{
		m3 = GetMouseMsg();//获取鼠标操作
		if (m3.x >= 230 && m3.x <= 560 && m3.y >= 240 && m3.y <= 285)
		{
			setlinecolor(RED);
			rectangle(230, 240, 560, 285);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				AdminPage1();//管理员界面 第1页  
			}
		}
		else if (m3.x >= 230 && m3.x <= 560 && m3.y >= 370 && m3.y <= 415)
		{
			setlinecolor(RED);
			rectangle(230, 370, 560, 415);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				AdminPage2();//管理员界面 第2页  
			}
		}
		else if (m3.x >= 230 && m3.x <= 560 && m3.y >= 500 && m3.y <= 545)
		{
			setlinecolor(RED);
			rectangle(230, 500, 560, 545);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				AdminPage3();//管理员界面 第3页  
			}
		}
		//鼠标不在上面悬停
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 240, 560, 285);
			rectangle(230, 370, 560, 415);
			rectangle(230, 500, 560, 545);
		}
	}
}
//管理员界面 第1页  m4
void AdminPage1(linkclothing head)
{
	initgraph(760, 760);
	cleardevice();//清屏函数
	//定义第三个鼠标操作
	MOUSEMSG m3;

	cleardevice();
	IMAGE img_bk;;
	loadimage(&img_bk, "bk1.jpg", 760, 760);
	putimage(0, 0, &img_bk);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "进" };
	char SecondTitle2[5] = { "货" };
	char SecondTitle3[5] = { "与" };
	char SecondTitle4[5] = { "售" };
	char SecondTitle5[5] = { "出" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };


	settextstyle(50, 0, "黑体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);


	setbkmode(TRANSPARENT);


	//三个选项的背景
	fillrectangle(230, 240, 560, 285);
	fillrectangle(230, 370, 560, 415);
	fillrectangle(230, 500, 560, 545);

	setbkmode(TRANSPARENT);

	//三个选项的文字
	settextstyle(40, 0, "黑体");

	//三个选项
	char SecondSelect1[20] = { "进货登记" };
	char SecondSelect2[20] = { "售出登记" };
	char SecondSelect3[20] = { "返回" };


	outtextxy(270, 240, SecondSelect1);
	outtextxy(270, 370, SecondSelect2);
	outtextxy(350, 500, SecondSelect3);

	FlushBatchDraw();
	//进入主界面选项操作界面
	while (1)
	{
		m3 = GetMouseMsg();//获取鼠标操作
		if (m3.x >= 230 && m3.x <= 560 && m3.y >= 240 && m3.y <= 285)
		{
			setlinecolor(RED);
			rectangle(230, 240, 560, 285);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				creatbyrear_clothing(head);//进货登记
			}
		}
		else if (m3.x >= 230 && m3.x <= 560 && m3.y >= 370 && m3.y <= 415)
		{
			setlinecolor(RED);
			rectangle(230, 370, 560, 415);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				creatbyrear_clothing(head);//售出登记
			}
		}
		else if (m3.x >= 230 && m3.x <= 560 && m3.y >= 500 && m3.y <= 545)
		{
			setlinecolor(RED);
			rectangle(230, 500, 560, 545);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				AdminPage0();//返回
			}
		}
		//鼠标不在上面悬停
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 240, 560, 285);
			rectangle(230, 370, 560, 415);
			rectangle(230, 500, 560, 545);
		}
	}
}
//管理员界面 第2页  m5
void AdminPage2()
{
	initgraph(760, 760);
	cleardevice();//清屏函数
	//定义第五个鼠标操作
	MOUSEMSG m5;

	cleardevice();
	IMAGE img_bk;;
	loadimage(&img_bk, "bk1.jpg", 760, 760);
	putimage(0, 0, &img_bk);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "改" };
	char SecondTitle2[5] = { "插" };
	char SecondTitle3[5] = { "删" };
	char SecondTitle4[5] = { "服" };
	char SecondTitle5[5] = { "装" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };


	settextstyle(50, 0, "黑体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);


	setbkmode(TRANSPARENT);


	//三个选项的背景
	fillrectangle(230, 240, 560, 285);
	fillrectangle(230, 370, 560, 415);
	fillrectangle(230, 500, 560, 545);

	setbkmode(TRANSPARENT);

	//三个选项的文字
	settextstyle(40, 0, "黑体");

	//三个选项
	char SecondSelect1[20] = { "修改服装信息" };
	char SecondSelect2[20] = { "插入服装信息" };
	char SecondSelect3[20] = { "删除服装信息" };


	outtextxy(270, 240, SecondSelect1);
	outtextxy(270, 370, SecondSelect2);
	outtextxy(350, 500, SecondSelect3);

	FlushBatchDraw();
	//进入主界面选项操作界面
	while (1)
	{
		m5 = GetMouseMsg();//获取鼠标操作
		if (m5.x >= 230 && m5.x <= 560 && m5.y >= 240 && m5.y <= 285)
		{
			setlinecolor(RED);
			rectangle(230, 240, 560, 285);
			if (m5.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				revise();//修改服装信息
			}
		}
		else if (m5.x >= 230 && m5.x <= 560 && m5.y >= 370 && m5.y <= 415)
		{
			setlinecolor(RED);
			rectangle(230, 370, 560, 415);
			if (m5.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				insert();//插入服装信息
			}
		}
		else if (m5.x >= 230 && m5.x <= 560 && m5.y >= 500 && m5.y <= 545)
		{
			setlinecolor(RED);
			rectangle(230, 500, 560, 545);
			if (m5.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				cutoff();//删除服装信息
			}
		}
		//鼠标不在上面悬停
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 240, 560, 285);
			rectangle(230, 370, 560, 415);
			rectangle(230, 500, 560, 545);
		}
	}
}
//管理员界面 第3页  m6
void AdminPage3()
{
	initgraph(760, 760);
	cleardevice();//清屏函数
	//定义第六个鼠标操作
	MOUSEMSG m6;

	cleardevice();
	IMAGE img_bk;;
	loadimage(&img_bk, "bk1.jpg", 760, 760);
	putimage(0, 0, &img_bk);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "折" };
	char SecondTitle2[5] = { "扣" };
	char SecondTitle3[5] = { "与" };
	char SecondTitle4[5] = { "评" };
	char SecondTitle5[5] = { "分" };
	char SecondTitle6[5] = { "界" };
	char SecondTitle7[5] = { "面" };


	settextstyle(50, 0, "黑体");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);


	setbkmode(TRANSPARENT);


	//三个选项的背景
	fillrectangle(230, 240, 560, 285);
	fillrectangle(230, 370, 560, 415);
	fillrectangle(230, 500, 560, 545);

	setbkmode(TRANSPARENT);

	//三个选项的文字
	settextstyle(40, 0, "黑体");

	//三个选项
	char SecondSelect1[20] = { "折扣活动设置" };
	char SecondSelect2[20] = { "员工评分" };
	char SecondSelect3[20] = { "返回" };


	outtextxy(270, 240, SecondSelect1);
	outtextxy(270, 370, SecondSelect2);
	outtextxy(350, 500, SecondSelect3);

	FlushBatchDraw();
	//进入主界面选项操作界面
	while (1)
	{
		m6 = GetMouseMsg();//获取鼠标操作
		if (m6.x >= 230 && m6.x <= 560 && m6.y >= 240 && m6.y <= 285)
		{
			setlinecolor(RED);
			rectangle(230, 240, 560, 285);
			if (m6.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				count();//折扣活动设置
			}
		}
		else if (m6.x >= 230 && m6.x <= 560 && m6.y >= 370 && m6.y <= 415)
		{
			setlinecolor(RED);
			rectangle(230, 370, 560, 415);
			if (m6.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				grade();//员工评分体系
			}
		}
		else if (m6.x >= 230 && m6.x <= 560 && m6.y >= 500 && m6.y <= 545)
		{
			setlinecolor(RED);
			rectangle(230, 500, 560, 545);
			if (m6.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				AdminPage0();
			}
		}
		//鼠标不在上面悬停
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 240, 560, 285);
			rectangle(230, 370, 560, 415);
			rectangle(230, 500, 560, 545);
		}
	}
}
//进货登记
void buy(linkclothing head)
{

}
//服装信息链表尾插
void creatbyrear_clothing(linkclothing head)
{
	Clothing* r, * s;
	char date1[8];//进货日期  例如：2020.12.12
	char date2[8];//出售日期
	char number[20];//编号
	char type[20];//类型  
	char color[20];//颜色
	char size[20];//尺码  S M L XL
	char price1[20];//进价
	char price2[20];//售价
	char discount[20];//折扣  例如：1、2、3......
	r = head;


	TCHAR InputAcct1[] = _T("请输入进货日期（例如20220202）");
	InputBox(date1, 10, InputAcct1);

	TCHAR InputAcct2[] = _T("请输入出售日期（例如20220202）");
	InputBox(date2, 10, InputAcct2);

	TCHAR InputAcct3[] = _T("请输入服装编号（自然数）");
	InputBox(number, 10, InputAcct3);

	TCHAR InputAcct4[] = _T("请输入服装类型（春装/夏装/秋装/冬装）");
	InputBox(type, 10, InputAcct4);

	TCHAR InputAcct5[] = _T("请输入服装颜色（深色/浅色）");
	InputBox(color, 10, InputAcct5);

	TCHAR InputAcct6[] = _T("请输入服装尺码（S/M/L/XL");
	InputBox(size, 10, InputAcct6);

	TCHAR InputAcct7[] = _T("请输入服装进价");
	InputBox(price1, 10, InputAcct7);

	TCHAR InputAcct8[] = _T("请输入服装售价");
	InputBox(price2, 10, InputAcct8);

	TCHAR InputAcct9[] = _T("请输入服装折扣");
	InputBox(discount, 10, InputAcct9);


	s = (Clothing*)malloc(sizeof(Clothing));
	strcpy(s->date1, date1);
	strcpy(s->date2, date2);
	strcpy(s->number, number);
	strcpy(s->type, type);
	strcpy(s->color, color);
	strcpy(s->size, size);
	strcpy(s->price1, price1);
	strcpy(s->price2, price2);
	strcpy(s->discount, discount);
	r->next = s;
	r = s;
	r->next = NULL;
}
//员工评分链表尾插
void creatbyrear_staff(linkstaff head)
{
	Staff* r, * s;
	char name[20];
	char score[20];
	r = head;

	TCHAR InputAcct[] = _T("请输入员工姓名");
	InputBox(name, 10, InputAcct);

	TCHAR InputPass[] = _T("请输入评分");
	InputBox(score, 10, InputPass);
	s = (Staff*)malloc(sizeof(Staff));
	strcpy(s->name, name);
	strcpy(s->score, score);
	r->next = s;
	r = s;
	r->next = NULL;
}
//门店账号链表尾插
void creatbyrear_store(linkstore head)//注意：每次只注册一个账号
{
	Store* r, * s;
	char name[20];
	char ciper[20];
	r = head;

	TCHAR InputAcct[] = _T("请输入门店名称");
	InputBox(name, 10, InputAcct);

	TCHAR InputPass[] = _T("请输入密码");
	InputBox(ciper, 10, InputPass);
	s = (Store*)malloc(sizeof(Store));
	strcpy(s->name, name);
	strcpy(s->ciper, ciper);
	r->next = s;
	r = s;
	r->next = NULL;
}
