// MultisetDLL.cpp

#include "MultisetDLL.h"
#include <stdexcept>
using namespace std;

namespace Multiset
{
	//Представлення символа у вигляді цифри
	inline us char2dig(char c)
	{
		return (c-'0');
	}
	
	//Знаходження більшого з двох чисел
	us max(us a1, us a2)
	{
		return a1>a2?a1:a2;
	}

	//Знаходження меншого з двох чисел
	us min(us a1, us a2)
	{
		return a1<a2?a1:a2;
	}

	//Функція, що робить multiset порожнім
	void make_empty(multiset& param)
	{
		for (char c='0'; c<='9'; c++)
			//присвоєння нуля всім лічильникам елементів
			param[char2dig(c)]=0;
	}

	//Функція перевірки того, чи порожній multiset
	uc _is_empty(multiset param)
	{
		for (uc c='0'; c<='9'; c++)
			//Якщо є хоч один не нульовий лічильник
			if (param[char2dig(c)])
				//Мультимножина не порожня
				return 0;
		return 1;
	}

	//Додавання елементу до multiset-у
	void add_element(multiset& param, uc el)
	{
		//Збільшуємо лічильник входжень на 1
		param[char2dig(el)]++;
	}

	//Вилучення елементу з multiset-у
	void remove_element(multiset& param, uc el)
	{
		//Якщо лічильник елементу не нуль
		if (param[char2dig(el)])
			//Зменшуємо лічильник входжень на 1
			param[char2dig(el)]--;
	}

	//Функція, що повертає кількість входження елемента до multiset-у
	us element_quantity(multiset param, uc el)
	{
		return param[char2dig(el)];
	}
	
	//Об'єднання двох мультимножин
	void _union(multiset param1, multiset param2, multiset& res)
	{
		for (uc c='0'; c<='9'; c++)
		{
			res[char2dig(c)]=max(param1[char2dig(c)], param2[char2dig(c)]);
		}
	}

	//Перетин двох мультимножин
	void _intersection(multiset param1, multiset param2, multiset& res)
	{
		for (uc c='0'; c<='9'; c++)
		{
			res[char2dig(c)]=min(param1[char2dig(c)], param2[char2dig(c)]);
		}
	}

	//Знаходження елемента. що найчастіше зустрічається
	uc find_most_popular(multiset param)
	{
		//Найпопулярніший елемент
		uc pop='0';
		for (uc c='1'; c<'9'; c++)
		{
			if (param[c-'0']>param[pop-'0'])
				pop=c;
		}
		return pop;
	}
		
	//Перевірка рівності двох мультимножин
	us is_equal(multiset param1, multiset param2)
	{
		for (uc c=0; c<10; c++)
			//Якщо кількість входжень елемента у 
			//двох мультимножинах різна
			if (param1[c]!=param2[c])
				//Мультимножини не рівні
				return 0;
		return 1;
	}
}