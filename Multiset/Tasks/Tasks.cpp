#include <iostream>
#include <string>
#include "MultisetDLL.h"
using namespace std;
using namespace Multiset;

//������� ���������� ������ � ������ is
string get_str(istream& is)
{
	string temp_s;
	is >> temp_s;
	//�������� ������� �������
	for (us i=0; i<temp_s.length(); i++)
		//�� � ������ ������
		if ( (temp_s[i]<'0')||(temp_s[i]>'9') )
		{
			//���� ������ �� � ������
			cout <<"Incorrect symbol \'"<<temp_s[i]<<"\' in a string!\n";
			cout <<"position:\t"<<i+1<<endl;
			exit(1);
		}

	return temp_s;
}

//��������� ����������� ������ ���� � �������������
void create_multiset(string str_param, multiset& out)
{
	//������ multimap �������
	make_empty(out);
	for (uc c=0; c<str_param.length(); c++)
		//������ ����� ������� �� �������������
		add_element(out, str_param[c]);
}

//��������� ������ ����� ������������� �� �������
void print_multiset(multiset param)
{
	for (uc c=0; c<n; c++)
		cout <<(c-0)<<"\t"<<param[c]<<"\n";
}

//����������� �������, ���� ������� � ����� S ����������� ������� 
void task1()
{
	cout <<"\tTask 1\n\n";
	multiset M;
	string str;
	cout <<"Input string\n\t";
	str=get_str(cin);
	create_multiset(str, M);
	
	print_multiset(M);

	cout <<"\nThe most popular element: "<<find_most_popular(M)<<endl;
}

//�������� ����, �� ����������� ����� S1, S2 � ����� � ��� �� �������, �� ������� � �� ����� �������� ������� ����
void task2()
{
	cout <<"\tTask 2\n\n";
	cout <<"Input first string\n\t";
	string s1=get_str(cin);
	multiset M1, M2;
	create_multiset(s1, M1);
	print_multiset(M1);

	cout <<"Input second string\n\t";
	string s2=get_str(cin);
	create_multiset(s2, M2);
	print_multiset(M2);

	if (is_equal(M1, M2))
		cout <<"s1 and s2 have the same content\n";
	else
		cout <<"s1 and s2 have different content\n";
}

//�������� ����, �� S1 � ���������� S2.
void task3()
{
	cout <<"\tTask 3\n\n";
	cout <<"Input first string\n\t";
	string s1=get_str(cin);
	multiset M1, M2;
	create_multiset(s1, M1);
	print_multiset(M1);

	cout <<"Input second string\n\t";
	string s2=get_str(cin);
	create_multiset(s2, M2);
	print_multiset(M2);

	multiset M3;
	_intersection(M1,M2, M3);
	if (is_equal(M1, M3) )
		cout <<"s1 is subset of s2\n";
	else
		cout <<"s1 is not subset of s2\n";
}

int main()
{
	task1();
	cout <<"\n______________________________________________________________________________\n";
	task2();
	cout <<"\n______________________________________________________________________________\n";
	task3();
	cout <<"\n______________________________________________________________________________\n";

	return 0;
}
