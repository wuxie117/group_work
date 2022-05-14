#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
class Restaurant
{
private:
    char location[50];
    char phone_number[20];
    char evaluates[200];

public:
    void Search();
    void Set();
    void evaluate();
};
class Customer
{
private:
    int desk;
    char dishes[20];
    int queues;
    char write_evaluate[200];
    static int total;
public:
    Customer();
    void order();
    void write();

};
class Waiter
{
private:
    int job_number;
    char name[25];
    char sex[5];
    char phone_number[20];
public:
    void Search();
    void Set();

};

class Menus
{
private:
    static int sums;
    int number;
    int price;
    char dish_name[30];
public:
    friend void Customer::order();
    void Search();
    void Set();
    void show();
};
int Customer::total = 0;
int Menus::sums = 0;

class Material
{
private:

};


//****ȫ�ֺ���***//
void Menu()
{
    cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl;
    cout << setw(40) << "����ҵ����ϵͳ" << endl;
    cout << endl;
    cout << setw(50) << "1**************��Ϣ��ѯ*************" << endl;
    cout << endl;
    cout << setw(50) << "2**************��Ϣ¼��*************" << endl;
    cout << endl;
    cout << setw(50) << "3**************�˿͵��*************" << endl;
    cout << endl;
    cout << setw(50) << "4**************�˿�����*************" << endl;
    cout << endl;
    cout << setw(50) << "0**************�˳�����*************" << endl;
    cout << endl;
}

void Search()//��Ϣ��ѯ
{
    system("cls");
    cout << endl; cout << endl; cout << endl; cout << endl; cout << endl;

    cout << "         1   ��ѯ������Ϣ" << endl;
    cout << endl;

    cout << "         2   ��ѯ����Ա��Ϣ" << endl;
    cout << endl;

    cout << "         3   ��ѯ�˵�" << endl;
    cout << endl;
    cout << "         4    �鿴����" << endl;
    cout << endl;

    cout << "         5   ������һ���˵�" << endl;
    cout << endl;

    cout << " " << "��ѡ��" << endl;
    int choice;
    Restaurant restaurant;
    Waiter waiter;
    Menus dish;
    cin >> choice;
    switch (choice)
    {
    case 1: restaurant.Search(); break;
    case 2: waiter.Search(); break;
    case 3: dish.Search(); break;
    case 4: restaurant.evaluate(); break;
    case 5: Menu(); break;
    }
}
void Set()//��Ϣ¼��
{
    system("cls");
    cout << endl << endl << endl << endl;
    cout << "              1 ��Ӳ�Ʒ" << endl << endl;
    cout << "              2 ��ӷ���Ա" << endl << endl;
    cout << "              3 ��Ӳ�����Ϣ" << endl << endl;
    cout << "              4 ������һ���˵�" << endl << endl;
    cout << "         ��ѡ��" << endl;
    Menus dish;
    int choice;
    Waiter waiter;
    Restaurant restaurant;
    cin >> choice;
    switch (choice)
    {
    case 1:dish.Set(); break;
    case 2:waiter.Set(); break;
    case 3:restaurant.Set(); break;
    case 4: Menu(); break;
    }
}
void orderdish()//�˿͵��
{
    Customer customer;
    customer.order();
    //system("cls");
    Menu();
}
void customer_evaluate()//�˿�����
{
    char evaluate[200];
    cout << "�����ۣ�" << endl;
    cin >> evaluate;
    ofstream out("evaluate.txt", ios::app);
    out << evaluate << endl;
    out.close();
    Menu();
}
int main()
{

    Menu();
    do
    {
        cout << "���������ѡ��" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:Search(); break;
        case 2:Set(); break;
        case 3:orderdish(); break;
        case 4:customer_evaluate(); break;
        case 0:exit(1); break;
        }

    } while (1);
    return 0;
}

Customer::Customer()
{
    system("cls");
    total++;
    cout << "            �㵱ǰ�ŶӺ���Ϊ��" << total << endl << endl;
}

void Customer::order()
{
    int temp[50];
    int j = 0;
    int sum = 0;
    char flag = 'y';
    int num = 0;

    Menus menu[50];
    cout << "         �˵�" << endl << endl;

    ifstream in("Menus.txt");
    int i = 0;
    while (in >> menu[i].number >> menu[i].dish_name >> menu[i].price)
    {
        cout << "  " << menu[i].number << setw(10) << menu[i].dish_name << setw(10) << menu[i].price << endl;
        i++;
    }
    in.close();

    while (flag == 'y')
    {
        cout << "����,ѡ����Ӧ��ţ�" << endl;
        cin >> temp[num];
        num++;
        cout << "�Ƿ����y or n" << endl;
        cin >> flag;
    }
    for (j = 0; j < num; j++)
    {
        for (i = 0; i < 10; i++)
        {
            if (temp[j] == menu[i].number)
            {
                sum = sum + menu[i].price;
            }
        }
    }
    cout << "�ܼ�Ǯ��" << sum << endl;

}


void Waiter::Set()
{
    system("cls");
    char flag = 'y';
    do
    {
        cout << "�������Ա�Ĺ��ţ��������Ա𣬵绰���룺" << endl;
        cin >> job_number >> name >> sex >> phone_number;
        ofstream out("Waiter.txt", ios::app);
        out << job_number << " " << name << " " << sex << " " << phone_number << endl;
        out.close();
        cout << "�Ƿ������(y)��(n)" << endl;
        cin >> flag;
    } while (flag == 'y');
    Menu();
}
void Menus::Set()
{
    system("cls");
    char flag = 'y';
    do
    {
        sums++;
        cout << "�����ţ��������۸�" << endl;
        cin >> number >> dish_name >> price;
        ofstream out("Menus.txt", ios::app);
        out << number << "  " << dish_name << "  " << price << "  " << endl;
        out.close();
        cout << "�Ƿ������(y)��(n)" << endl;
        cin >> flag;
    } while (flag == 'y');
    Menu();
}
void Restaurant::Set()
{
    cout << "�������λ�ã��绰����" << endl;
    cin >> location >> phone_number;
    ofstream out("Restaurant.txt");
    out << location << "  " << phone_number << endl;
    out.close();
    Menu();
}
void Restaurant::Search()
{
    system("cls");
    cout << endl << endl;
    ifstream in("Restaurant.txt");
    cout << "��ַ" << "         " << "��ϵ�绰" << endl;
    while (in >> location >> phone_number)
    {
        cout << location << "  " << phone_number << endl;
    }
    in.close();
    Menu();
}
void Restaurant::evaluate()
{
    system("cls");
    cout << endl << "       ��ʷ���ۣ�" << endl << endl;
    ifstream in("evaluate.txt");
    while (in >> evaluates)
        cout << "             " << evaluates << endl << endl;
    in.close();
    Menu();
}
void Waiter::Search()
{
    system("cls");
    ifstream in("Waiter.txt");
    cout << endl << endl;
    cout << "   ����" << "  " << "����" << "    " << "�Ա�" << "  " << "�绰����" << endl;
    while (in >> job_number >> name >> sex >> phone_number)
    {
        cout << "    " << job_number << "    " << name << "    " << sex << "    " << phone_number << endl;
    }
    in.close();
    Menu();
}
void Menus::Search()
{
    system("cls");
    ifstream in("Menus.txt");
    cout << endl << endl;
    cout << "  ���" << setw(10) << "����" << setw(10) << "�۸�" << endl;
    while (in >> number >> dish_name >> price)
    {
        cout << "  " << number << "   " << setw(10) << dish_name << setw(10) << price << endl;
    }
    in.close();
    Menu();
}