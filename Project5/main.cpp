/*
		5. �����: �� ����������� � ���������� ����� ����������� ���? (���������, �� ����������� ������ ����� List, a Cat - �� ����, ���������� ������ � ��������� ������.)
		³������:
				   - CatList ����� �������� -> Cat_List
				   - (Cat_List.is_present(Felix)) ? "" : "not " -> (Cat_List.is_present(Felix) ? "" : "not ")
				   - ����� ��������������  operator== � ���� Cat
*/
	
List<Cat> Cat_List;
Cat Felix;

CatList.append(Felix);						 
cout << "Felix is "
<< (Cat_List.is_present(Felix)) ? "" : "not "
<< "present\n";								 
