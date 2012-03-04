// MultisetDLL.cpp

#include "MultisetDLL.h"
#include <stdexcept>
using namespace std;

namespace Multiset
{
	//������������� ������� � ������ �����
	inline us char2dig(char c)
	{
		return (c-'0');
	}
	
	//����������� ������� � ���� �����
	us max(us a1, us a2)
	{
		return a1>a2?a1:a2;
	}

	//����������� ������� � ���� �����
	us min(us a1, us a2)
	{
		return a1<a2?a1:a2;
	}

	//�������, �� ������ multiset �������
	void make_empty(multiset& param)
	{
		for (char c='0'; c<='9'; c++)
			//��������� ���� ��� ���������� ��������
			param[char2dig(c)]=0;
	}

	//������� �������� ����, �� ������� multiset
	uc _is_empty(multiset param)
	{
		for (uc c='0'; c<='9'; c++)
			//���� � ��� ���� �� �������� ��������
			if (param[char2dig(c)])
				//������������� �� �������
				return 0;
		return 1;
	}

	//��������� �������� �� multiset-�
	void add_element(multiset& param, uc el)
	{
		//�������� �������� �������� �� 1
		param[char2dig(el)]++;
	}

	//��������� �������� � multiset-�
	void remove_element(multiset& param, uc el)
	{
		//���� �������� �������� �� ����
		if (param[char2dig(el)])
			//�������� �������� �������� �� 1
			param[char2dig(el)]--;
	}

	//�������, �� ������� ������� ��������� �������� �� multiset-�
	us element_quantity(multiset param, uc el)
	{
		return param[char2dig(el)];
	}
	
	//��'������� ���� ������������
	void _union(multiset param1, multiset param2, multiset& res)
	{
		for (uc c='0'; c<='9'; c++)
		{
			res[char2dig(c)]=max(param1[char2dig(c)], param2[char2dig(c)]);
		}
	}

	//������� ���� ������������
	void _intersection(multiset param1, multiset param2, multiset& res)
	{
		for (uc c='0'; c<='9'; c++)
		{
			res[char2dig(c)]=min(param1[char2dig(c)], param2[char2dig(c)]);
		}
	}

	//����������� ��������. �� ��������� �����������
	uc find_most_popular(multiset param)
	{
		//�������������� �������
		uc pop='0';
		for (uc c='1'; c<'9'; c++)
		{
			if (param[c-'0']>param[pop-'0'])
				pop=c;
		}
		return pop;
	}
		
	//�������� ������ ���� ������������
	us is_equal(multiset param1, multiset param2)
	{
		for (uc c=0; c<10; c++)
			//���� ������� �������� �������� � 
			//���� �������������� ����
			if (param1[c]!=param2[c])
				//������������� �� ���
				return 0;
		return 1;
	}
}