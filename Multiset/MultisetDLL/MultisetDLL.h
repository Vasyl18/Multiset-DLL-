//MultisetDLL.h

namespace Multiset
{
	//Макроси говорять самі за себе
	#define us unsigned short
	#define uc unsigned char
	#define n 10

	//Тип multiset
	typedef us multiset[n];   
	
	//Знаходження більшого з двох чисел
	us max(us, us);
	//Знаходження меншого з двох чисел
	us min(us, us);

	//Функція, що робить multiset порожнім
	__declspec(dllexport) void make_empty(multiset&);
	
	//Функція перевірки того, чи порожній multiset
	__declspec(dllexport) uc _is_empty(multiset);
	
	//Додавання елементу до multiset-у
	__declspec(dllexport) void add_element(multiset&, uc);
	
	//Вилучення елементу з multiset-у
	__declspec(dllexport) void remove_element(multiset&, uc);
	
	//Функція, що повертає кількість входження елемента до multiset-у
	__declspec(dllexport) us element_quantity(multiset, uc);

	//Об'єднання двох мультимножин
	__declspec(dllexport) void _union(multiset, multiset, multiset&);
	
	//Перетин двох мультимножин
	__declspec(dllexport) void _intersection(multiset, multiset, multiset&);
	
	//Знаходження елемента. що найчастіше зустрічається
	__declspec(dllexport) uc find_most_popular(multiset);
	
	//Перевірка рівності двох мультимножин
	__declspec(dllexport) us is_equal(multiset, multiset);
}