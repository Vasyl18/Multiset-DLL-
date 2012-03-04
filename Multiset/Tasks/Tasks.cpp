#include <iostream>
#include <string>
#include "MultisetDLL.h"
using namespace std;
using namespace Multiset;

//Функція зчитування стрічки з потоку is
string get_str(istream& is)
{
	string temp_s;
	is >> temp_s;
	//Перевірка кожного символа
	for (us i=0; i<temp_s.length(); i++)
		//Чи є символ цифрою
		if ( (temp_s[i]<'0')||(temp_s[i]>'9') )
		{
			//Якщо символ не є цифрою
			cout <<"Incorrect symbol \'"<<temp_s[i]<<"\' in a string!\n";
			cout <<"position:\t"<<i+1<<endl;
			exit(1);
		}

	return temp_s;
}

//процедура конвертації стрічки цифр у мультимножину
void create_multiset(string str_param, multiset& out)
{
	//Робимо multimap порожнім
	make_empty(out);
	for (uc c=0; c<str_param.length(); c++)
		//додаємо новий елемент до мультимножини
		add_element(out, str_param[c]);
}

//Процедура виводу вмісту мультимножини на консоль
void print_multiset(multiset param)
{
	for (uc c=0; c<n; c++)
		cout <<(c-0)<<"\t"<<param[c]<<"\n";
}

//Знаходження символа, який входить у рядок S максимальну кількість 
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

//Перевірка того, чи складаються рядки S1, S2 з одних і тих же символів, які входять у ці рядки однакову кількість разів
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

//Перевірка того, чи S1 є підмножиною S2.
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
