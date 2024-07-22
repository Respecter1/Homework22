#pragma once
/*
	6. Оголосіть дружній оператор operator== класу List.

*/

bool operator==(const List& number1, const List& number2) {
    const List* current1 = &number1;
    const List* current2 = &number2;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->value != current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return (current1 == nullptr && current2 == nullptr);
}
