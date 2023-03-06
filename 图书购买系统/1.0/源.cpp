#include<iostream>
#include<string>
#include<fstream>
#include<typeinfo>
#include<stdlib.h>
using namespace std;
class buyer; class common; class vip; class honored;
class book      //书类
{
protected:
	string book_name;
	string author;
	string publisher;
	double price;
	book* next;
public:
	book() :next(NULL) {};                  
	void addbook(book*); //管理员用，向书库中添加书籍
	void showbook(book*); //管理员用，展示书库中的书籍
	void deletbook(book*); //管理员用，删除书库中书籍
	void updatebook(book*);   //管理员用，更改库中图书信息
	void loadbook(book*); //管理员用，将文件中书籍内容读入book对象指针
	void savebook(book*);  //管理员用，保存书籍信息
	friend buyer;
	friend common;
	friend vip;
	friend honored;
	//friend admin;               函数移植需声明友元
};
void book::addbook(book* p)
{
	book* p1 = p;
	while (p->next != NULL)
	{
		p = p->next;
	}
	book* p2 = new book;
	p->next = p2;
	cout << "请输入书名：" << endl;
	cin >> p2->book_name;
	while (p1 != p)                                      //
	{
		if (p1->next->book_name == p2->book_name)  //
		{
			cout << endl << "书名重复！" << endl << endl;//
			p->next = NULL;//                          检查书名是否重复
			delete p2;
			return;
		}
		p1 = p1->next;
	}
	cout << "请输入作者：" << endl;
	cin >> p2->author;
	cout << "请输入出版社：" << endl;
	cin >> p2->publisher;
	cout << "请输入价格：" << endl;
	cin >> p2->price;
	system("cls");
	cout << "添加成功！" << endl;
}
void book::showbook(book* p)
{
	if (p->next == NULL)
	{
		cout << "目前无书籍信息！\t\t" << endl;
		return;
	}
	p = p->next;
	int n = 1;
	while (1)
	{
		cout << "NO." << n << ":" << '\t' << endl;
		cout << "书名：" << "《" << p->book_name << "》" << '\t';
		cout << "作者：" << p->author << '\t';
		cout << "出版社：" << p->publisher << '\t';
		cout << "价格：" << p->price << '\n';
		if (p->next == NULL)break;
		p = p->next;
		n++;
	}
}
void book::deletbook(book* p)
{
	if (p->next == NULL)
	{
		cout << "目前无书籍信息！\t\t" << endl;
		return;
	}
	string na; cout << "请输入要删除的书名：" << endl; cin >> na;
	while (1)
	{
		if (p->next->book_name != na)
		{
			p = p->next;
			if (p->next == NULL)
			{
				system("cls");
				cout << "没有这本书的信息！" << endl << endl;
				break;
			}
		}
		else
		{
			cout << "找到了！" << endl;
			cout << "—————————————————————————————————————————————————————————\n";
			cout << "书名：" << "《" << p->next->book_name << "》" << '\t';
			cout << "作者：" << p->next->author << '\t';
			cout << "出版社：" << p->next->publisher << '\t';
			cout << "价格：" << p->next->price << '\n';
			cout << "—————————————————————————————————————————————————————————\n\n";
			cout << "是否删除该书籍信息？" << endl;
			cout << "1) 是\t0）否" << endl;
			int a; cin >> a;
			switch (a)
			{
			case 0:
			{	break; }
			case 1:
			{
				p->next = p->next->next;
				system("cls");
				cout << "删除成功！" << endl;
				break;
			}
			default:
				cout << "ERROR！" << endl;
			}
			break;
		}
	}
}
void book::updatebook(book* p)
{
	if (p->next == NULL)
	{
		cout << "目前无书籍信息！\t\t" << endl;
		return;
	}
	string na; cout << "请输入要更改信息的书名：" << endl; cin >> na;
	while (1)
	{
		if (p->next->book_name != na)
		{
			p = p->next;
			if (p->next == NULL)
			{
				system("cls");
				cout << "没有这本书的信息！" << endl << endl;
				return;
			}
		}
		else break;
	}
	cout << "找到了！" << endl;
	cout << "—————————————————————————————————————————————————————————\n";
	cout << "书名：" << "《" << p->next->book_name << "》" << '\t';
	cout << "作者：" << p->next->author << '\t';
	cout << "出版社：" << p->next->publisher << '\t';
	cout << "价格：" << p->next->price << '\n';
	cout << "—————————————————————————————————————————————————————————\n\n";
	cout << endl << endl;
	cout << "请选择要进行的修改操作：" << endl << endl;
	cout << "1) 修改书名" << endl;
	cout << "2) 修改作者" << endl;
	cout << "3) 修改出版社" << endl;
	cout << "4) 修改价格" << endl;
	cout << "7) 退出修改" << endl << endl;
	int order; cin >> order;
	switch (order)
	{
	case 1:
	{
		cout << "请输入修改后的书名：" << endl;
		string a; cin >> a;
		p->next->book_name = a;
		system("cls"); cout << "修改成功！" << endl;
		break;
	}
	case 2:
	{
		cout << "请输入修改后的作者：" << endl;
		string a; cin >> a;
		p->next->author = a;
		system("cls"); cout << "修改成功！" << endl;
		break;
	}
	case 3:
	{
		cout << "请输入修改后的出版社：" << endl;
		string a; cin >> a;
		p->next->publisher = a;
		system("cls"); cout << "修改成功！" << endl;
		break;
	}
	case 4:
	{
		cout << "请输入修改后的价格：" << endl;
		double a; cin >> a;
		p->next->price = a;
		system("cls"); cout << "修改成功！" << endl;
		break;
	}
	case 7:
	{break; }
	default:
	{
		system("cls");
		cout << "再乱输指令，头套必须给你拽掉，必须打你脸！没你好果汁吃的，你记住了嗷！" << endl << endl;
	}
	}
}
void book::loadbook(book* p)
{
	ifstream fin;
	fin.open("book.txt", ios::in);
	if (!fin)
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	string name;
	while (fin >> name)
	{
		book* newnode = new book;
		newnode->book_name = name;
		fin >> newnode->author;
		fin >> newnode->publisher;
		fin >> newnode->price;
		p->next = newnode;
		p = p->next;
	}
	fin.close();
}
void book::savebook(book* p)
{
	ofstream fout;
	fout.open("book.txt", ios::out);
	if (!fout)
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	while (p->next != NULL)
	{
		fout << p->next->book_name << "\t";
		fout << p->next->author << "\t";
		fout << p->next->publisher << "\t";
		fout << p->next->price << "\n";
		p = p->next;
	}
	fout.close();
}
class buyer
{
protected:
	string ID;          //用户ID
	string key;              //用户密码
	string adress;             //用户地址
	double pay;
	string status;           //用户身份
	book* list;                //购物车
public:
	buyer() :list(new book) {}
	string getID() { return ID; }  //取用户ID
	string getadress() { return adress; }//取用户地址
	string getkey() { return key; }  //取用户密码
	void main_user();       //用户界面
	void main_shop_list(); //购物车管理界面
	void showbook();         //显示书籍信息
	void addbook(book*);        //向购物车中添加书籍
	void deletebook(book*);       //从购物车中删除书籍
	void load(book*);       //从文件读入购物车信息
	void save(book*);         //向文件输出购物车信息
	int signin(string i, string k)              //用户登录函数
	{
		if (i == ID && k == key) return 1;
		else return 0;
	}
	virtual void showbuyer() = 0;  //显示用户信息
	virtual void sum(book*) = 0;  //购物车结算函数
};
void buyer::addbook(book* p)
{
	book* p1 = new book;
	p1->loadbook(p1);
	p1->showbook(p1);
	if (p1->next == NULL)
	{
		cout << "购物车当前为空！" << endl;
		return;
	}
	cout << endl << "请输入要添加的书籍名称：" << endl;
	string name; cin >> name;
	while (p1->next != NULL)
	{
		if (p1->next->book_name == name)
		{
			cout << "找到了！" << endl;
			cout << "—————————————————————————————————————————————————————————\n";
			cout << "书名：" << "《" << p1->next->book_name << "》" << '\t';
			cout << "作者：" << p1->next->author << '\t';
			cout << "出版社：" << p1->next->publisher << '\t';
			cout << "价格：" << p1->next->price << '\n';
			cout << "—————————————————————————————————————————————————————————\n\n";
			cout << "是否将此书加入购物车？" << endl;
			cout << "1) 是\t0）否" << endl;
			int o; cin >> o;
			if (o == 1)
			{
				while (p->next != NULL)
					p = p->next;
				p->next = p1->next;
				p1->next->next = NULL;
				system("cls");
				cout << "添加成功！" << endl;
				break;
			}
			else if (o == 0)
			{
				break;
			}
			else
			{
				cout << "请输入正确指令！" << endl;
				break;
			}
		}
		p1 = p1->next;
	}
	if (p1->next == NULL)
	{
		cout << "未找到符合条件的书籍！" << endl;
	}
}
void buyer::deletebook(book* p)
{
	if (p->next == NULL)
	{
		cout << "购物车当前为空！" << endl;
		return;
	}
	cout << endl << "请输入要删除的书籍名称：" << endl;
	string name; cin >> name;
	int i = 0;
	while (p->next != NULL)
	{
		if (p->next->book_name == name)
		{
			i++;
			cout << "找到了！" << endl;
			cout << "—————————————————————————————————————————————————————————\n";
			cout << "书名：" << "《" << p->next->book_name << "》" << '\t';
			cout << "作者：" << p->next->author << '\t';
			cout << "出版社：" << p->next->publisher << '\t';
			cout << "价格：" << p->next->price << '\n';
			cout << "—————————————————————————————————————————————————————————\n\n";
			cout << "是否将此书从购物车中移除？" << endl;
			cout << "1) 是\t0）否" << endl;
			int o; cin >> o;
			if (o == 1)
			{
				p->next = p->next->next;
				system("cls");
				cout << "删除成功！" << endl;
				break;
			}
			else if (o == 0)
			{
				break;
			}
			else
			{
				cout << "请输入正确指令！" << endl;
				break;
			}
		}
		p = p->next;
	}
	if (i == 0)
	{
		cout << "未找到符合条件的书籍！" << endl;
	}
}
void buyer::load(book* p)
{
	if (p->next != NULL)p->next = NULL;
	string fname = this->ID + ".txt";
	ifstream fin;
	fin.open(fname, ios::in);
	if (!fin)
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	string name;
	book* p1 = new book;
	book* p2 = p1;
	list->loadbook(p1);
	while (fin >> name)
	{
		book* newnode = new book;
		newnode->book_name = name;
		fin >> newnode->author;
		fin >> newnode->publisher;
		fin >> newnode->price;
		while (p1->next != NULL)
		{
			if (p1->next->book_name == newnode->book_name)
			{
				newnode->author = p1->next->author;
				newnode->publisher = p1->next->publisher;
				newnode->price = p1->next->price;
				break;
			}
			else	p1 = p1->next;
		}
		if (p1->next != NULL)
		{
			p->next = newnode;
			p = p->next;
			p1 = p2;
		}
	}
	fin.close();
}
void buyer::save(book* p)
{
	string fname = this->ID + ".txt";
	ofstream fout;
	fout.open(fname, ios::out);
	if (!fout)
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	while (p->next != NULL)
	{
		fout << p->next->book_name << "\t";
		fout << p->next->author << "\t";
		fout << p->next->publisher << "\t";
		fout << p->next->price << "\n";
		p = p->next;
	}
	fout.close();
}
void buyer::main_user()
{
	int o;
	while (1)
	{
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t\t+-------------DoKiDoKi----------+\n");
		printf("\t\t\t\t\t|--------------用户-----------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 查看书籍\n");
		printf("\t\t\t\t\t\t2 管理购物车\n");
		printf("\t\t\t\t\t\t3 查看个人信息\n");
		printf("\t\t\t\t\t\t4 登出\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t请输入你想实现的功能前的代号：\n");
		printf("\t\t\t\t");
		cin >> o;
		switch (o)
		{
		case 1:
		{
			system("cls");
			showbook();
			break;
		}
		case 2:
		{
			main_shop_list();
			break;
		}
		case 3:
		{
			showbuyer();
			break;
		}
		case 4:
		{return;	}
		default:
		{cout << "请输入正确指令！" << endl << endl; }
		}
		system("pause");
	}
}
void buyer::main_shop_list()
{
	this->load(list);
	while (1)
	{
		system("cls");
		cout << this->getID() << "的购物车：" << endl << endl;
		list->showbook(list);
		printf("\n\n\n");
		printf("\t\t\t\t\t+-------------DoKiDoKi----------+\n");
		printf("\t\t\t\t\t|--------------购物车-----------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 向购物车中添加书籍\n");
		printf("\t\t\t\t\t\t2 从购物车中删除书籍\n");
		printf("\t\t\t\t\t\t3 结算\n");
		printf("\t\t\t\t\t\t4 退出购物车\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t请输入你想实现的功能前的代号：\n");
		printf("\t\t\t\t");
		int o;
		cin >> o;
		switch (o)
		{
		case 1:
		{
			addbook(list);
			break;
		}
		case 2:
		{
			deletebook(list);
			break;
		}
		case 3:
		{
			sum(list);
			break;
		}
		case 4:
		{
			save(list);
			return;
		}
		default:
		{cout << "再乱输指令，头套给你薅一地，必须打你脸。" << endl; }
		}
		system("pause");
	}
}
void buyer::showbook()
{
	ifstream fin;
	fin.open("book.txt", ios::in);
	if (!fin)
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	int i = 0;
	while (fin >> list->book_name)
	{
		cout << "NO." << ++i << endl;
		fin >> list->author;
		fin >> list->publisher;
		fin >> list->price;
		cout << "书名：" << "《" << list->book_name << "》" << '\t';
		cout << "作者：" << list->author << '\t';
		cout << "出版社：" << list->publisher << '\t';
		cout << "价格：" << list->price << endl;
	}
	fin.close();
}
class common :public buyer         //普通用户
{
public:
	common(string, string, string);
	void showbuyer();
	void sum(book*);
};
common::common(string I, string k, string ad)
{
	ID = I; key = k; adress = ad; status = "普通";
}
void common::showbuyer()
{
	cout << "用户名：" << getID() << endl;
	cout << "用户地址：" << getadress() << endl;
	cout << "用户身份：" << status << endl;
}
void common::sum(book* p)
{
	double pay = 0;
	while (p->next != NULL)
	{
		pay += p->next->price;
		p = p->next;
	}
	cout << "用户 " << this->getID() << " 应付" << pay << "元" << endl;
}
class vip :public buyer              //VIP用户
{
protected:
	int level;
public:
	vip(string, string, string, int);
	void showbuyer();
	void sum(book*);
};
vip::vip(string i, string k, string ad, int l)
{
	ID = i; key = k; adress = ad; level = l; status = "VIP";
}
void vip::showbuyer()
{
	cout << "用户名：" << getID() << endl;
	cout << "用户地址：" << getadress() << endl;
	cout << "用户身份：" << status << endl;
	cout << "会员等级：" << level << endl;
}
void vip::sum(book* p)
{
	double pay = 0, discount = 0;
	while (p->next != NULL)
	{
		pay += p->next->price;
		p = p->next;
	}
	if (level == 5)	discount = 0.7;
	else	discount = 1 - .05 * level;
	pay = pay * discount;
	cout << "vip用户 " << this->getID() << " 应付" << pay << "元" << endl;
}
class honored :public buyer            //贵宾
{
protected:
	float discount;
public:
	honored(string, string, string, float);
	void showbuyer();
	void sum(book*);
};
honored::honored(string i, string k, string ad, float d)
{
	ID = i; key = k; adress = ad; discount = d; status = "贵宾";
}
void honored::showbuyer()
{
	cout << "用户名：" << getID() << endl;
	cout << "用户地址：" << getadress() << endl;
	cout << "用户身份：" << status << endl;
	cout << "折扣率：" << discount << endl;
}
void honored::sum(book* p)
{
	double pay = 0;
	while (p->next != NULL)
	{
		pay += p->next->price;
		p = p->next;
	}
	cout << "贵宾用户 " << this->getID() << " 享受" << discount * 10 << "折优惠，" << "应付" << pay * discount << "元" << endl;
}
class admin    //管理员类
{
private:
	string ID;
	string key;
	string status;
	book* list;
public:
	string getID() { return ID; }  //取管理员ID
	string getkey() { return key; }  //取管理员密码
	admin(string i, string k)
	{
		ID = i; key = k; status = "ad"; list = new book;
	}
	int signin()
	{
		string i, k;
		cout << "请输入账号：";
		cin >> i;
		cout << "请输入密码：";
		cin >> k;
		if (i == ID && k == key)	return 1;
		else	return 0;
	}
	void main_ad();
};
void admin::main_ad()
{
	int o;
	list->loadbook(list);
	while (1)
	{
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t\t+-------------DoKiDoKi----------+\n");
		printf("\t\t\t\t\t|--------------管理员-----------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 查看书籍\n");
		printf("\t\t\t\t\t\t2 添加书籍\n");
		printf("\t\t\t\t\t\t3 删除书籍\n");
		printf("\t\t\t\t\t\t4 更改图书信息\n");
		printf("\t\t\t\t\t\t5 保存登出\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t请输入你想实现的功能前的代号：\n");
		printf("\t\t\t\t");
		cin >> o;
		switch (o)
		{
		case 1:
		{system("cls");
		list->showbook(list);
		break;
		}
		case 2:
		{
			list->addbook(list);
			break;
		}
		case 3:
		{
			list->deletbook(list);
			break;
		}
		case 4:
		{
			list->updatebook(list);
			break;
		}
		case 5:
		{
			list->savebook(list);
			return;
		}
		default:
		{	cout << "请输入正确指令！" << endl << endl; }
		}
		system("pause");
	}
}
int main()
{
	system("color 0A");
	
	admin A("monika", "160922");
	common B("me", "19170", "桥洞底下盖小被儿");
	vip C1("sayori", "18157", "纱世里的家", 3);
	vip C2("natsuki", "18149", "夏树的家", 5);
	honored D("yuri", "18165", "优里的家", 0.5);
	buyer* user[4] = { &B,&C1,&C2,&D };
	ifstream in;
	in.open("book.txt");
	if (!in)
	{
		ofstream out("book.txt", ios::out); out.close();
	} in.close();  //
	for (int i = 0; i < 4; i++)                                 //
	{
		string fname = user[i]->getID() + ".txt";                //检测要打开的文件是否存在，不存在就创立
		in.open(fname, ios::in);                        //
		if (!in) { ofstream ou(fname, ios::out); ou.close(); }       //
		in.close();
	}
	while (1)
	{
		system("cls");
		cout << "管理员：\n" << "  用户名：" << A.getID() << "\t密码：" << A.getkey() << endl;
		cout << "普通用户：\n" << "  用户名：" << B.getID() << "\t密码：" << B.getkey() << endl;
		cout << "VIP用户：\n" << "  用户名：" << C1.getID() << "\t密码：" << C1.getkey() << endl;
		cout << "VIP用户：\n" << "  用户名：" << C2.getID() << "\t密码：" << C2.getkey() << endl;
		cout << "贵宾用户：\n" << "  用户名：" << D.getID() << "\t密码：" << D.getkey() << endl;
		printf("\n\n\n");
		printf("\t\t\t\t\t+-------------DoKiDoKi----------+\n");
		printf("\t\t\t\t\t|-----------图书购买系统--------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 管理员登录\n");
		printf("\t\t\t\t\t\t2 用户登录\n");
		printf("\t\t\t\t\t\t3 退出\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t请输入你想实现的功能前的代号：\n");
		printf("\t\t\t\t");
		int o;
		cin >> o;
		switch (o)
		{
		case 1:
		{
			if (A.signin() == 1)
			{
				A.main_ad();
			}
			else	cout << "账号或密码错误" << endl;
			break;
		}
		case 2:
		{
			string id, k;
			cout << "请输入账号：";  cin >> id;
			cout << "请输入密码：";  cin >> k;
			int i;
			for (i = 0; i < 4; i++)
			{
				if (user[i]->signin(id, k) == 1)
				{
					user[i]->main_user();
					break;
				}
			}
			if (i > 3)
			{
				cout << "账号或密码错误" << endl;
			}
			break;
		}
		case 3:
		{	return 0; }
		default:
		{	cout << "请输入正确指令！" << endl << endl;   }
		}
		system("pause");
	}
}