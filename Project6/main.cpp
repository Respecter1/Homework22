/*
	6. Оголосіть дружній оператор operator== класу List.

*/

//class Cat
//{
//public:
//	Cat(int cat_number)
//		:cat_number{ new int(cat_number) }
//	{	}
//
//	Cat(const Cat& other)
//		:cat_number{ new int(other.GetCat_number()) }
//	{	}
//
//	Cat(Cat&& other) noexcept
//		:cat_number(other.cat_number)
//	{
//		other.cat_number = nullptr;
//	}
//
//	~Cat()
//	{
//		delete cat_number;
//		cat_number = nullptr;
//	}
//
//	int GetCat_number()const
//	{
//		return cat_number != nullptr ? *cat_number : 0;
//	}
//	friend bool operator==(const Cat& number1, const Cat& number2);
//private:
//	int* cat_number;
//};
//
//bool operator==(const Cat& number1, const Cat& number2)
//{
//	return number1.GetCat_number() == number2.GetCat_number();
//}