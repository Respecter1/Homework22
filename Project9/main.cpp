/*	
		9. �������� ��������� ������� �������, �� ������� �������� ����� ������, �������� ���� �� ���� ������ ��������� ������.
*/


template<typename T>
void Swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}