#pragma once
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
