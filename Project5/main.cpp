/*
		5. Жучки: що неправильно у наведеному нижче програмному коді? (Припустіть, що визначається шаблон класу List, a Cat - це клас, визначений одному з попередніх занять.)
		Відповідь:
				   - CatList треба помыняти -> Cat_List
				   - (Cat_List.is_present(Felix)) ? "" : "not " -> (Cat_List.is_present(Felix) ? "" : "not ")
				   - треба перезагружений  operator== в класі Cat
*/
	
List<Cat> Cat_List;
Cat Felix;

CatList.append(Felix);						 
cout << "Felix is "
<< (Cat_List.is_present(Felix)) ? "" : "not "
<< "present\n";								 
