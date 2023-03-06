#include<iostream>
#include<string>
#include<fstream>
#include<typeinfo>
#include<stdlib.h>
using namespace std;
class buyer; class common; class vip; class honored;
class book      //����
{
protected:
	string book_name;
	string author;
	string publisher;
	double price;
	book* next;
public:
	book() :next(NULL) {};                  
	void addbook(book*); //����Ա�ã������������鼮
	void showbook(book*); //����Ա�ã�չʾ����е��鼮
	void deletbook(book*); //����Ա�ã�ɾ��������鼮
	void updatebook(book*);   //����Ա�ã����Ŀ���ͼ����Ϣ
	void loadbook(book*); //����Ա�ã����ļ����鼮���ݶ���book����ָ��
	void savebook(book*);  //����Ա�ã������鼮��Ϣ
	friend buyer;
	friend common;
	friend vip;
	friend honored;
	//friend admin;               ������ֲ��������Ԫ
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
	cout << "������������" << endl;
	cin >> p2->book_name;
	while (p1 != p)                                      //
	{
		if (p1->next->book_name == p2->book_name)  //
		{
			cout << endl << "�����ظ���" << endl << endl;//
			p->next = NULL;//                          ��������Ƿ��ظ�
			delete p2;
			return;
		}
		p1 = p1->next;
	}
	cout << "���������ߣ�" << endl;
	cin >> p2->author;
	cout << "����������磺" << endl;
	cin >> p2->publisher;
	cout << "������۸�" << endl;
	cin >> p2->price;
	system("cls");
	cout << "��ӳɹ���" << endl;
}
void book::showbook(book* p)
{
	if (p->next == NULL)
	{
		cout << "Ŀǰ���鼮��Ϣ��\t\t" << endl;
		return;
	}
	p = p->next;
	int n = 1;
	while (1)
	{
		cout << "NO." << n << ":" << '\t' << endl;
		cout << "������" << "��" << p->book_name << "��" << '\t';
		cout << "���ߣ�" << p->author << '\t';
		cout << "�����磺" << p->publisher << '\t';
		cout << "�۸�" << p->price << '\n';
		if (p->next == NULL)break;
		p = p->next;
		n++;
	}
}
void book::deletbook(book* p)
{
	if (p->next == NULL)
	{
		cout << "Ŀǰ���鼮��Ϣ��\t\t" << endl;
		return;
	}
	string na; cout << "������Ҫɾ����������" << endl; cin >> na;
	while (1)
	{
		if (p->next->book_name != na)
		{
			p = p->next;
			if (p->next == NULL)
			{
				system("cls");
				cout << "û���Ȿ�����Ϣ��" << endl << endl;
				break;
			}
		}
		else
		{
			cout << "�ҵ��ˣ�" << endl;
			cout << "������������������������������������������������������������������������������������������������������������������\n";
			cout << "������" << "��" << p->next->book_name << "��" << '\t';
			cout << "���ߣ�" << p->next->author << '\t';
			cout << "�����磺" << p->next->publisher << '\t';
			cout << "�۸�" << p->next->price << '\n';
			cout << "������������������������������������������������������������������������������������������������������������������\n\n";
			cout << "�Ƿ�ɾ�����鼮��Ϣ��" << endl;
			cout << "1) ��\t0����" << endl;
			int a; cin >> a;
			switch (a)
			{
			case 0:
			{	break; }
			case 1:
			{
				p->next = p->next->next;
				system("cls");
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			default:
				cout << "ERROR��" << endl;
			}
			break;
		}
	}
}
void book::updatebook(book* p)
{
	if (p->next == NULL)
	{
		cout << "Ŀǰ���鼮��Ϣ��\t\t" << endl;
		return;
	}
	string na; cout << "������Ҫ������Ϣ��������" << endl; cin >> na;
	while (1)
	{
		if (p->next->book_name != na)
		{
			p = p->next;
			if (p->next == NULL)
			{
				system("cls");
				cout << "û���Ȿ�����Ϣ��" << endl << endl;
				return;
			}
		}
		else break;
	}
	cout << "�ҵ��ˣ�" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������\n";
	cout << "������" << "��" << p->next->book_name << "��" << '\t';
	cout << "���ߣ�" << p->next->author << '\t';
	cout << "�����磺" << p->next->publisher << '\t';
	cout << "�۸�" << p->next->price << '\n';
	cout << "������������������������������������������������������������������������������������������������������������������\n\n";
	cout << endl << endl;
	cout << "��ѡ��Ҫ���е��޸Ĳ�����" << endl << endl;
	cout << "1) �޸�����" << endl;
	cout << "2) �޸�����" << endl;
	cout << "3) �޸ĳ�����" << endl;
	cout << "4) �޸ļ۸�" << endl;
	cout << "7) �˳��޸�" << endl << endl;
	int order; cin >> order;
	switch (order)
	{
	case 1:
	{
		cout << "�������޸ĺ��������" << endl;
		string a; cin >> a;
		p->next->book_name = a;
		system("cls"); cout << "�޸ĳɹ���" << endl;
		break;
	}
	case 2:
	{
		cout << "�������޸ĺ�����ߣ�" << endl;
		string a; cin >> a;
		p->next->author = a;
		system("cls"); cout << "�޸ĳɹ���" << endl;
		break;
	}
	case 3:
	{
		cout << "�������޸ĺ�ĳ����磺" << endl;
		string a; cin >> a;
		p->next->publisher = a;
		system("cls"); cout << "�޸ĳɹ���" << endl;
		break;
	}
	case 4:
	{
		cout << "�������޸ĺ�ļ۸�" << endl;
		double a; cin >> a;
		p->next->price = a;
		system("cls"); cout << "�޸ĳɹ���" << endl;
		break;
	}
	case 7:
	{break; }
	default:
	{
		system("cls");
		cout << "������ָ�ͷ�ױ������ק���������������û��ù�֭�Եģ����ס��໣�" << endl << endl;
	}
	}
}
void book::loadbook(book* p)
{
	ifstream fin;
	fin.open("book.txt", ios::in);
	if (!fin)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	string ID;          //�û�ID
	string key;              //�û�����
	string adress;             //�û���ַ
	double pay;
	string status;           //�û����
	book* list;                //���ﳵ
public:
	buyer() :list(new book) {}
	string getID() { return ID; }  //ȡ�û�ID
	string getadress() { return adress; }//ȡ�û���ַ
	string getkey() { return key; }  //ȡ�û�����
	void main_user();       //�û�����
	void main_shop_list(); //���ﳵ�������
	void showbook();         //��ʾ�鼮��Ϣ
	void addbook(book*);        //���ﳵ������鼮
	void deletebook(book*);       //�ӹ��ﳵ��ɾ���鼮
	void load(book*);       //���ļ����빺�ﳵ��Ϣ
	void save(book*);         //���ļ�������ﳵ��Ϣ
	int signin(string i, string k)              //�û���¼����
	{
		if (i == ID && k == key) return 1;
		else return 0;
	}
	virtual void showbuyer() = 0;  //��ʾ�û���Ϣ
	virtual void sum(book*) = 0;  //���ﳵ���㺯��
};
void buyer::addbook(book* p)
{
	book* p1 = new book;
	p1->loadbook(p1);
	p1->showbook(p1);
	if (p1->next == NULL)
	{
		cout << "���ﳵ��ǰΪ�գ�" << endl;
		return;
	}
	cout << endl << "������Ҫ��ӵ��鼮���ƣ�" << endl;
	string name; cin >> name;
	while (p1->next != NULL)
	{
		if (p1->next->book_name == name)
		{
			cout << "�ҵ��ˣ�" << endl;
			cout << "������������������������������������������������������������������������������������������������������������������\n";
			cout << "������" << "��" << p1->next->book_name << "��" << '\t';
			cout << "���ߣ�" << p1->next->author << '\t';
			cout << "�����磺" << p1->next->publisher << '\t';
			cout << "�۸�" << p1->next->price << '\n';
			cout << "������������������������������������������������������������������������������������������������������������������\n\n";
			cout << "�Ƿ񽫴�����빺�ﳵ��" << endl;
			cout << "1) ��\t0����" << endl;
			int o; cin >> o;
			if (o == 1)
			{
				while (p->next != NULL)
					p = p->next;
				p->next = p1->next;
				p1->next->next = NULL;
				system("cls");
				cout << "��ӳɹ���" << endl;
				break;
			}
			else if (o == 0)
			{
				break;
			}
			else
			{
				cout << "��������ȷָ�" << endl;
				break;
			}
		}
		p1 = p1->next;
	}
	if (p1->next == NULL)
	{
		cout << "δ�ҵ������������鼮��" << endl;
	}
}
void buyer::deletebook(book* p)
{
	if (p->next == NULL)
	{
		cout << "���ﳵ��ǰΪ�գ�" << endl;
		return;
	}
	cout << endl << "������Ҫɾ�����鼮���ƣ�" << endl;
	string name; cin >> name;
	int i = 0;
	while (p->next != NULL)
	{
		if (p->next->book_name == name)
		{
			i++;
			cout << "�ҵ��ˣ�" << endl;
			cout << "������������������������������������������������������������������������������������������������������������������\n";
			cout << "������" << "��" << p->next->book_name << "��" << '\t';
			cout << "���ߣ�" << p->next->author << '\t';
			cout << "�����磺" << p->next->publisher << '\t';
			cout << "�۸�" << p->next->price << '\n';
			cout << "������������������������������������������������������������������������������������������������������������������\n\n";
			cout << "�Ƿ񽫴���ӹ��ﳵ���Ƴ���" << endl;
			cout << "1) ��\t0����" << endl;
			int o; cin >> o;
			if (o == 1)
			{
				p->next = p->next->next;
				system("cls");
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			else if (o == 0)
			{
				break;
			}
			else
			{
				cout << "��������ȷָ�" << endl;
				break;
			}
		}
		p = p->next;
	}
	if (i == 0)
	{
		cout << "δ�ҵ������������鼮��" << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		printf("\t\t\t\t\t|--------------�û�-----------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 �鿴�鼮\n");
		printf("\t\t\t\t\t\t2 �����ﳵ\n");
		printf("\t\t\t\t\t\t3 �鿴������Ϣ\n");
		printf("\t\t\t\t\t\t4 �ǳ�\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t����������ʵ�ֵĹ���ǰ�Ĵ��ţ�\n");
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
		{cout << "��������ȷָ�" << endl << endl; }
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
		cout << this->getID() << "�Ĺ��ﳵ��" << endl << endl;
		list->showbook(list);
		printf("\n\n\n");
		printf("\t\t\t\t\t+-------------DoKiDoKi----------+\n");
		printf("\t\t\t\t\t|--------------���ﳵ-----------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 ���ﳵ������鼮\n");
		printf("\t\t\t\t\t\t2 �ӹ��ﳵ��ɾ���鼮\n");
		printf("\t\t\t\t\t\t3 ����\n");
		printf("\t\t\t\t\t\t4 �˳����ﳵ\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t����������ʵ�ֵĹ���ǰ�Ĵ��ţ�\n");
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
		{cout << "������ָ�ͷ�׸���޶һ�أ������������" << endl; }
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
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(1);
	}
	int i = 0;
	while (fin >> list->book_name)
	{
		cout << "NO." << ++i << endl;
		fin >> list->author;
		fin >> list->publisher;
		fin >> list->price;
		cout << "������" << "��" << list->book_name << "��" << '\t';
		cout << "���ߣ�" << list->author << '\t';
		cout << "�����磺" << list->publisher << '\t';
		cout << "�۸�" << list->price << endl;
	}
	fin.close();
}
class common :public buyer         //��ͨ�û�
{
public:
	common(string, string, string);
	void showbuyer();
	void sum(book*);
};
common::common(string I, string k, string ad)
{
	ID = I; key = k; adress = ad; status = "��ͨ";
}
void common::showbuyer()
{
	cout << "�û�����" << getID() << endl;
	cout << "�û���ַ��" << getadress() << endl;
	cout << "�û���ݣ�" << status << endl;
}
void common::sum(book* p)
{
	double pay = 0;
	while (p->next != NULL)
	{
		pay += p->next->price;
		p = p->next;
	}
	cout << "�û� " << this->getID() << " Ӧ��" << pay << "Ԫ" << endl;
}
class vip :public buyer              //VIP�û�
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
	cout << "�û�����" << getID() << endl;
	cout << "�û���ַ��" << getadress() << endl;
	cout << "�û���ݣ�" << status << endl;
	cout << "��Ա�ȼ���" << level << endl;
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
	cout << "vip�û� " << this->getID() << " Ӧ��" << pay << "Ԫ" << endl;
}
class honored :public buyer            //���
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
	ID = i; key = k; adress = ad; discount = d; status = "���";
}
void honored::showbuyer()
{
	cout << "�û�����" << getID() << endl;
	cout << "�û���ַ��" << getadress() << endl;
	cout << "�û���ݣ�" << status << endl;
	cout << "�ۿ��ʣ�" << discount << endl;
}
void honored::sum(book* p)
{
	double pay = 0;
	while (p->next != NULL)
	{
		pay += p->next->price;
		p = p->next;
	}
	cout << "����û� " << this->getID() << " ����" << discount * 10 << "���Żݣ�" << "Ӧ��" << pay * discount << "Ԫ" << endl;
}
class admin    //����Ա��
{
private:
	string ID;
	string key;
	string status;
	book* list;
public:
	string getID() { return ID; }  //ȡ����ԱID
	string getkey() { return key; }  //ȡ����Ա����
	admin(string i, string k)
	{
		ID = i; key = k; status = "ad"; list = new book;
	}
	int signin()
	{
		string i, k;
		cout << "�������˺ţ�";
		cin >> i;
		cout << "���������룺";
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
		printf("\t\t\t\t\t|--------------����Ա-----------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 �鿴�鼮\n");
		printf("\t\t\t\t\t\t2 ����鼮\n");
		printf("\t\t\t\t\t\t3 ɾ���鼮\n");
		printf("\t\t\t\t\t\t4 ����ͼ����Ϣ\n");
		printf("\t\t\t\t\t\t5 ����ǳ�\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t����������ʵ�ֵĹ���ǰ�Ĵ��ţ�\n");
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
		{	cout << "��������ȷָ�" << endl << endl; }
		}
		system("pause");
	}
}
int main()
{
	system("color 0A");
	
	admin A("monika", "160922");
	common B("me", "19170", "�Ŷ����¸�С����");
	vip C1("sayori", "18157", "ɴ����ļ�", 3);
	vip C2("natsuki", "18149", "�����ļ�", 5);
	honored D("yuri", "18165", "����ļ�", 0.5);
	buyer* user[4] = { &B,&C1,&C2,&D };
	ifstream in;
	in.open("book.txt");
	if (!in)
	{
		ofstream out("book.txt", ios::out); out.close();
	} in.close();  //
	for (int i = 0; i < 4; i++)                                 //
	{
		string fname = user[i]->getID() + ".txt";                //���Ҫ�򿪵��ļ��Ƿ���ڣ������ھʹ���
		in.open(fname, ios::in);                        //
		if (!in) { ofstream ou(fname, ios::out); ou.close(); }       //
		in.close();
	}
	while (1)
	{
		system("cls");
		cout << "����Ա��\n" << "  �û�����" << A.getID() << "\t���룺" << A.getkey() << endl;
		cout << "��ͨ�û���\n" << "  �û�����" << B.getID() << "\t���룺" << B.getkey() << endl;
		cout << "VIP�û���\n" << "  �û�����" << C1.getID() << "\t���룺" << C1.getkey() << endl;
		cout << "VIP�û���\n" << "  �û�����" << C2.getID() << "\t���룺" << C2.getkey() << endl;
		cout << "����û���\n" << "  �û�����" << D.getID() << "\t���룺" << D.getkey() << endl;
		printf("\n\n\n");
		printf("\t\t\t\t\t+-------------DoKiDoKi----------+\n");
		printf("\t\t\t\t\t|-----------ͼ�鹺��ϵͳ--------|\n");
		printf("\t\t\t\t\t+-------------------------------+\n");
		printf("\t\t\t\t\t\t1 ����Ա��¼\n");
		printf("\t\t\t\t\t\t2 �û���¼\n");
		printf("\t\t\t\t\t\t3 �˳�\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t����������ʵ�ֵĹ���ǰ�Ĵ��ţ�\n");
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
			else	cout << "�˺Ż��������" << endl;
			break;
		}
		case 2:
		{
			string id, k;
			cout << "�������˺ţ�";  cin >> id;
			cout << "���������룺";  cin >> k;
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
				cout << "�˺Ż��������" << endl;
			}
			break;
		}
		case 3:
		{	return 0; }
		default:
		{	cout << "��������ȷָ�" << endl << endl;   }
		}
		system("pause");
	}
}