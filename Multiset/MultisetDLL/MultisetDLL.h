//MultisetDLL.h

namespace Multiset
{
	//������� �������� ��� �� ����
	#define us unsigned short
	#define uc unsigned char
	#define n 10

	//��� multiset
	typedef us multiset[n];   
	
	//����������� ������� � ���� �����
	us max(us, us);
	//����������� ������� � ���� �����
	us min(us, us);

	//�������, �� ������ multiset �������
	__declspec(dllexport) void make_empty(multiset&);
	
	//������� �������� ����, �� ������� multiset
	__declspec(dllexport) uc _is_empty(multiset);
	
	//��������� �������� �� multiset-�
	__declspec(dllexport) void add_element(multiset&, uc);
	
	//��������� �������� � multiset-�
	__declspec(dllexport) void remove_element(multiset&, uc);
	
	//�������, �� ������� ������� ��������� �������� �� multiset-�
	__declspec(dllexport) us element_quantity(multiset, uc);

	//��'������� ���� ������������
	__declspec(dllexport) void _union(multiset, multiset, multiset&);
	
	//������� ���� ������������
	__declspec(dllexport) void _intersection(multiset, multiset, multiset&);
	
	//����������� ��������. �� ��������� �����������
	__declspec(dllexport) uc find_most_popular(multiset);
	
	//�������� ������ ���� ������������
	__declspec(dllexport) us is_equal(multiset, multiset);
}