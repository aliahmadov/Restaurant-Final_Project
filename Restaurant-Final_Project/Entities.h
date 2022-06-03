#pragma once
#pragma once
#include<iostream>
#include<assert.h>
#include<Windows.h>
#include<vector>
#include<iomanip>
using namespace std;


void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

class Ingredient {
	string name;
	double ingredient_price;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
	int id;
	int ingredient_count;
public:
	static int ing_id;
	Ingredient() :name(" "), fats(0), protein(0), carbohydrates(0), kcal(0) {}

	Ingredient(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ing_count,
		const double& price)
	{
		SetId(++ing_id);
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetCount(ing_count);
		SetPrice(price);
	}

#pragma region IngredientGetters
	string GetName()const {
		return name;
	}

	double GetFats()const {
		return fats;
	}

	double GetProtein() {
		return protein;
	}

	double GetCarbohydrates()const {
		return carbohydrates;
	}

	int GetKcal()const {
		return kcal;
	}

	int GetId()const {
		return id;
	}

	int GetCount()const {
		return ingredient_count;
	}

	double GetPrice()const {
		return ingredient_price;
	}
#pragma endregion

#pragma region IngredientSetters

	void SetName(const string& name) {
		assert(name.length() >= 2 && "Ingredient name should include more than 2 letters");
		this->name = name;
	}

	void SetFats(const double& fats) {
		assert(fats >= 0 && "Fat Value cannot be less than 0 !!!");
		this->fats = fats;
	}

	void SetProtein(const double& protein) {
		assert(protein >= 0 && "Protein Value cannot be less than 0 !!!");
		this->protein = protein;
	}

	void SetCarbohydrates(const double& carbohydrates) {
		assert(carbohydrates >= 0 && "Carbohydrates Value cannot be less than 0 !!!");
		this->carbohydrates = carbohydrates;
	}

	void SetKcal(const int& kcal) {
		assert(kcal >= 0 && "Kcal Value cannot be less than 0 !!!");
		this->kcal = kcal;
	}

	void SetId(const int& id) {
		this->id = id;
	}

	void SetCount(const int& count) {
		assert(count >= 0 && "Count cannot be less than 0 !!!");
		this->ingredient_count = count;
	}

	void SetPrice(const double& price) {
		assert(price >= 0 && "Price Value cannot be less than 0 !!!");
		this->ingredient_price = price;
	}

	void ShowIngredient()const {

		cout << "\nIngredient ID: " << GetId() << endl;
		cout << "Ingredient Name: " << GetName() << endl;
		cout << "Ingredient Count: " << GetCount() << endl;
		cout << "================================================" << endl;
	}


#pragma endregion

	virtual ~Ingredient() = 0
	{

	}
};

int Ingredient::ing_id = 0;


class Other :public Ingredient {
public:
	Other(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price) {}


};

class Mushroom :public Ingredient {
public:
	Mushroom(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price) {}


};

class Pepper :public Ingredient {
public:
	Pepper(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price) {}
};

class Eggplant :public Ingredient {
public:
	Eggplant(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price) {}
};


class Cabbage :public Ingredient {
public:
	Cabbage(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price) {}
};


class Potato :public Ingredient {
public:
	Potato(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price) {}
};

class Meat :public Ingredient {
public:
	Meat(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price)
	{

	}

};


class Spices :public Ingredient {
public:
	Spices(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price) {}
};


class Cheese :public Ingredient {
public:
	Cheese(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price)
	{

	}
};

class Rice :public Ingredient {
public:
	Rice(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price)
	{

	}
};


class Tomatoes :public Ingredient {
public:
	Tomatoes(const string& name, const double& fats, const double& protein,
		const double& carbohydrates, const int& kcal, const int& ingredient_count,
		const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, ingredient_count, price)
	{

	}
};


struct RecipeItem {
	Ingredient* ingredient;// 2 dene ingredient
	int amount = 0;// neche dene
};


//Yemek DISH

class Dish {
	RecipeItem** items;
	int count;
	string name;
	double price;
	int id;
	int GetIngredientIndexById(int ing_id)const {
		for (size_t i = 0; i < count; i++)
		{
			if (items[i]->ingredient->GetId() == ing_id) {
				return i;
			}
		}
		return -1;
	}

	virtual double GetTotalPrice()const {
		double price_ingredient = 0;
		double total_price = 0;
		for (size_t i = 0; i < count; i++)
		{
			price_ingredient = items[i]->ingredient->GetPrice() * items[i]->amount;
			total_price += price_ingredient;
		}
		return total_price;
	}
public:
	static int dish_id;
	Dish(RecipeItem** items, const int& count, const string& name)
	{
		SetId(dish_id++);
		this->count = count;
		this->items = items;
		this->name = name;
		this->price = GetTotalPrice();
	}


	void AddIngredient(RecipeItem* item) {
		auto newitems = new RecipeItem * [count + 1]{};

		for (size_t i = 0; i < count; i++)
		{
			newitems[i] = items[i];
		}

		newitems[count] = item;
		items = newitems;
		newitems = nullptr;
		count++;
	}

	void DeleteIngredient(int id) {
		auto newitems = new RecipeItem * [count - 1]{};
		auto index = GetIngredientIndexById(id);
		for (size_t i = 0; i < index; i++)
		{
			newitems[i] = items[i];
		}

		for (size_t i = index, i2 = index + 1; i < count - 1; i++, i2++)
		{
			newitems[i] = items[i2];
		}

		items = newitems;
		newitems = nullptr;
		count--;
	}

	string GetName()const {
		return name;
	}

	int GetCount()const {
		return count;
	}

	double GetPrice()const {
		return price;

	}

	int GetId() {
		return id;
	}

	RecipeItem** GetItems()const {
		return items;
	}

	void SetId(const int& id) {
		this->id = id;
	}
	virtual void Taste() {
		cout << "I do not know what is this ? " << endl;
	}

	virtual void PrintRecipe() {
		double sum_fat = 0;
		double sum_protein = 0;
		double sum_carbohydrate = 0;
		int sum_kcal = 0;
		double fats = 0;
		double proteins = 0;
		double carbohydrates = 0;
		int kcals = 0;
		mysetcolor(15, 0);
		cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "M E A L  N A M E : ";
		mysetcolor(4, 0);
		cout << GetName() << endl;;
		mysetcolor(15, 0);
		cout << "\nM E A L   I D : " << GetId() << endl;
		mysetcolor(15, 0);
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		mysetcolor(7, 0);
		for (size_t i = 0; i < GetCount(); i++)
		{
			mysetcolor(6, 0);
			cout << "I n g r e d i e n t   n u m b e r  " << i + 1 << endl;;
			mysetcolor(7, 0);
			cout << "\nIngredient ID: " << GetItems()[i]->ingredient->GetId() << endl;
			cout << "Name: " << GetItems()[i]->ingredient->GetName() << " - " << GetItems()[i]->amount << endl;
			cout << "Ingredient Fat: " << GetItems()[i]->ingredient->GetFats() << endl;
			cout << "Ingredient Protein: " << GetItems()[i]->ingredient->GetProtein() << endl;
			cout << "Ingredient Carbohydrate: " << GetItems()[i]->ingredient->GetCarbohydrates() << endl;
			cout << "Ingredient Kcal: " << GetItems()[i]->ingredient->GetKcal() << endl;
			fats = GetItems()[i]->amount * GetItems()[i]->ingredient->GetFats();
			proteins = GetItems()[i]->amount * GetItems()[i]->ingredient->GetProtein();
			carbohydrates = GetItems()[i]->amount * GetItems()[i]->ingredient->GetCarbohydrates();
			kcals = GetItems()[i]->amount * GetItems()[i]->ingredient->GetKcal();
			sum_kcal += kcals;
			sum_fat += fats;
			sum_carbohydrate += carbohydrates;
			sum_protein += proteins;
			cout << "======================================" << endl;
		}cout << endl;
		mysetcolor(11, 0);
		cout << "Total Protein : " << sum_protein << endl;
		cout << "Total Fat : " << sum_fat << endl;
		cout << "Total Carbohydrate : " << sum_carbohydrate << endl;
		cout << "Total Kcal : " << sum_kcal << endl;
		mysetcolor(7, 0);
	};

	virtual void ShowMeal() {
		cout << GetName() << "-----------------------------------------------------------------" << GetPrice() << " $" << " (ID--> " << GetId() << ") " << endl;
	}

	virtual ~Dish() = 0 { //pure vitual destructor

	}

};

int Dish::dish_id = 1;

class Pizza :public Dish {

public:
	Pizza() = delete;

	Pizza(RecipeItem** items, const int& count, const string& name) :
		Dish(items, count, name) {}

	void Taste()override {
		cout << "Taste : Very Good" << endl;
	}

	void PrintRecipe()override {
		Dish::PrintRecipe();
	}

	void ShowMeal()override {
		Dish::ShowMeal();
	}
};


class Kabab :public Dish {
public:
	Kabab() = delete;

	Kabab(RecipeItem** items, const int& count, const string& name) :
		Dish(items, count, name) {}

	void Taste()override {
		cout << "Taste : Perfect, Soft and Delicious" << endl;
	}

	void PrintRecipe()override {
		Dish::PrintRecipe();
	}

	void ShowMeal()override {
		Dish::ShowMeal();
	}
};


class Any :public Dish {
public:
	Any(RecipeItem** items, const int& count, const string& name) :
		Dish(items, count, name) {}

	void Taste()override {
		cout << "Taste : Perfect, Soft and Delicious" << endl;
	}

	void PrintRecipe()override {
		Dish::PrintRecipe();
	}

	void ShowMeal()override {
		Dish::ShowMeal();
	}
};



class Dolma :public Dish {
public:
	Dolma() = delete;

	Dolma(RecipeItem** items, const int& count, const string& name) :
		Dish(items, count, name) {}
	void Taste()override {
		cout << "Taste : Nice, Very Tasty" << endl;
	}

	void PrintRecipe()override {
		Dish::PrintRecipe();
	}


};


class Drink {
	string name;
	int id = 0;
	double price;
	int count;
public:
	static int drink_id;
	Drink() {}
	Drink(const string& name, const double& price, const int& count)
	{
		SetId(++drink_id);
		SetName(name);
		SetPrice(price);
		SetCount(count);
	}

	int GetCount()const {
		return count;
	}

	string GetName()const {
		return name;
	}

	double GetPrice()const {
		return price;
	}

	void SetName(const string& name) {
		this->name = name;
	}

	void SetPrice(const double& price) {
		assert(price >= 0 && "Price value cannot be less than 0!!!");
		this->price = price;
	}

	void SetId(const int& id) {
		this->id = id;
	}

	void SetCount(const int& count) {
		this->count = count;
	}

	int GetId()const {
		return id;
	}

	virtual void ShowDrink()const {
		cout << setw(10) << GetName() << setw(10) << "     ----------------------------------------------------";
		cout << setw(10) << GetPrice() << " $" << " (ID--> " << GetId() << ") " << endl;
	}

	virtual void ShowDrinkForStock()const {
		cout << "\nDrink ID: " << GetId() << endl;
		cout << "Drink name: " << GetName() << endl;
		cout << "Drink Count: " << GetCount() << endl;
		cout << "==============================" << endl;
	}

	virtual ~Drink() = 0 {

	}
};

int Drink::drink_id = 0;


class HotDrink :public Drink {
public:
	HotDrink(){}
	HotDrink(const string& name, const double& price, const int& count) :Drink(name, price, count) {

	}

	void ShowDrink()const override {
		Drink::ShowDrink();
	}

	void ShowDrinkForStock()const override {
		Drink::ShowDrinkForStock();
	}
};

class ColdDrink :public Drink {
public:
	ColdDrink(){}
	ColdDrink(const string& name, const double& price, const int& count) :Drink(name, price, count) {

	}

	void ShowDrink()const override {
		Drink::ShowDrink();
	}

	void ShowDrinkForStock()const override {
		Drink::ShowDrinkForStock();
	}
};




struct Order {
	Dish* meal;
	int count;
	string date;
	int table_no;
	int order_number;
	double price;
	RecipeItem** items;
	int items_count = 0;

	void AddIngredientToDish(RecipeItem* item, Order* order) {
		auto count = order->items_count;
		auto newitems = new RecipeItem * [count + 1]{};
		for (size_t i = 0; i < count; i++)
		{
			newitems[i] = order->items[i];
		}
		newitems[count] = item;
		if (order->items != nullptr) {
			delete order->items;
		}
		order->items = newitems;
		newitems = nullptr;
		order->items_count++;
	}
};



class Table {
	int table_no;
	Order** orders;
	string messageFromKitchen;
	bool isFull;
	int order_count;
public:
	static int t_no;
	Table() {
		SetTableNo(++t_no);
	}

	Table(const string& messageFromKitchen) {
		this->messageFromKitchen = messageFromKitchen;
	}
	Order** GetOrders()const {
		return orders;
	}

	string GetKitchenMessage()const {
		return messageFromKitchen;
	}

	int GetTableNo()const {
		return table_no;
	}

	bool GetIsFull()const {
		return isFull;
	}

	void SetIsFull(const bool& isfull) {
		this->isFull = isfull;
	}

	void SetTableNo(const int& table_no) {
		this->table_no = table_no;
	}

	void SetMessage(const string& messageFromKitchen) {
		this->messageFromKitchen = messageFromKitchen;
	}

	void ShowTable()const {

		if (isFull == 0) {

			mysetcolor(2, 0);
			mysetcolor(15, 0);
			cout << "\n           Table No:  " << GetTableNo() << endl;
			mysetcolor(2, 0);
			cout << "      _______________________________ \n";
			cout << "    /||                             /| " << endl;
			cout << "   //||                            /|| " << endl;
			cout << "  // ||                           //|| " << endl;
			cout << " //  ||                          // || " << endl;
			cout << "//______________________________//     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			mysetcolor(7, 0);

		}
		else {

			mysetcolor(2, 0);
			mysetcolor(15, 0);
			cout << "\n           Table No:  " << GetTableNo() << endl;
			mysetcolor(4, 0);
			cout << "      _______________________________ \n";
			cout << "    /||                             /| " << endl;
			cout << "   //||                            /|| " << endl;
			cout << "  // ||                           //|| " << endl;
			cout << " //  ||                          // || " << endl;
			cout << "//______________________________//     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			cout << "||                              ||     " << endl;
			mysetcolor(7, 0);

		}
	}
};

#include<vector>
int Table::t_no = 0;

struct ColdDrinkOrder {
	int order_number;
	int table_no;
	vector<ColdDrink>ColdDrinks;
	int count[10] = {};
	double price;
};

struct HotDrinkOrder {
	int order_number;
	int table_no;
	vector<HotDrink>HotDrinks;
	int count[10];
	double price;
};

struct Kitchen {
	Order** orders;
	int order_count = 0;
	vector<ColdDrinkOrder>cold_orders;
	int cd_count = 0;
	vector<HotDrinkOrder>hot_orders;
	int hd_count = 0;
};

struct Stock {
	Ingredient** ingredients;
};

class Admin {
	int id;
	string name;
	string surname;
	string username;
	string password;
public:
	static int admin_id;
	Admin() {}

	Admin(const string& name, const string& surname, const string& username,
		const string& password) :name(name), surname(surname),
		username(username), password(password)
	{
		SetId(++admin_id);
	}

	int GetId()const {
		return id;
	}

	string GetName()const {
		return name;
	}

	string GetSurname()const {
		return surname;
	}

	string GetUsername()const {
		return username;
	}

	string GetPassword()const {
		return password;
	}

	void SetName(const string& name) {
		this->name = name;
	}

	void SetSurname(const string& surname) {
		this->surname = surname;
	}

	void SetUsername(const string& username) {
		this->username = username;
	}

	void SetPassword(const string& password) {
		this->password = password;
	}

	void SetId(const int& id) {
		this->id = id;
	}

};

int Admin::admin_id = 0;

class Restaurant {
	string name;
	string address;
	double budget = 0;
	vector<Admin>admins;
	int admin_count = 0;
public:
	Restaurant() :name("no name"), address("no address"), budget(0)
	{

	}
	Restaurant(const string& name, const string& address,
		const double& budget) :
		name(name), address(address), budget(budget)
	{

	}

	string GetName()const {
		return name;
	}

	string GetAddress()const {
		return address;
	}

	double GetBudget()const {
		return budget;
	}

	vector<Admin> GetAdmins()const {
		return admins;
	}

	void SetBudget(const double& budget) {
		this->budget = budget;
	}

	void AddAdmin(Admin admin) {
		admins.push_back(admin);
	}

};
