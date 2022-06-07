#pragma once
#pragma once
#include<iostream>
#include<vector>
#include "Start.h"
#include<iomanip>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;
#include"Entities.h"

Admin head_admin("Ali", "Ahmadov", "admin", "admin");
Admin assistant_admin("Fred", "Jhones", "admin", "admin");


Restaurant restaurant("Cibo Matto", "28 May", 0);

Table* t_1 = new Table;
Table* t_2 = new Table;
Table* t_3 = new Table;
Table* t_4 = new Table;
Table* t_5 = new Table;
Table* t_6 = new Table;
Table* t_7 = new Table;
Table* t_8 = new Table;
Table* t_9 = new Table;
Table* t_10 = new Table;

Table** tables = new Table * [10]{ t_1,t_2,t_3,t_4,t_5,t_6,t_7,t_8,t_9,t_10 };


Ingredient* mushroom = new Mushroom("Italian Mushroom", 134.3, 12.6, 125.2, 95, 125, 0.7);
Ingredient* tomato = new Tomatoes("Khazakh Tomato", 65, 72.3, 98.7, 100, 220, 0.9);
Ingredient* cheese = new Cheese("Holland Cheese", 77, 87, 102.9, 134, 150, 1.3);
Ingredient* salt = new Spices("Salt", 12, 0, 72, 12.9, 140, 0.3);
Ingredient* meat = new Meat("Beef", 105.6, 135.9, 155.2, 200, 360, 8.6);
Ingredient* pepper = new Spices("Chili Pepper", 0, 0, 9, 40, 72, 0.45);
Ingredient* rice = new Rice("Tamasha", 5.2, 9.7, 15.3, 20, 95, 1.4);
Ingredient* salami = new Meat("Halal Salami", 123, 100, 234, 328, 150, 5.5);
Ingredient* potato = new Potato("Potato", 23, 95, 200, 222, 200, 0.95);
Ingredient* cabbage = new Cabbage("Cabbage", 12, 45, 56, 71, 150, 1.2);
Ingredient* eggplant = new Eggplant("Eggplant", 15, 43, 52, 69, 250, 1.2);
Ingredient* green_pepper = new Pepper("Green Sweet Pepper", 20, 32, 41, 23, 250, 0.5);

int ing_count = 0;
Ingredient** ingredients = new Ingredient * [ing_count] {};

Stock stock{ ingredients };


RecipeItem* cabbage1 = new RecipeItem{ cabbage,1 };
RecipeItem* eggplant1 = new RecipeItem{ eggplant,1 };
RecipeItem* green_pepper1 = new RecipeItem{ green_pepper,1 };
RecipeItem* salami1 = new RecipeItem{ salami,1 };
RecipeItem* potato1 = new RecipeItem{ potato,1 };
RecipeItem* m1 = new RecipeItem{ mushroom,1 };
RecipeItem* m2 = new RecipeItem{ mushroom,2 };
RecipeItem* t1 = new RecipeItem{ tomato,1 };
RecipeItem* t2 = new RecipeItem{ tomato,2 };
RecipeItem* c1 = new RecipeItem{ cheese,1 };
RecipeItem* c2 = new RecipeItem{ cheese,2 };
RecipeItem* me1 = new RecipeItem{ meat,1 };
RecipeItem* me2 = new RecipeItem{ meat,2 };
RecipeItem* s1 = new RecipeItem{ salt,1 };
RecipeItem* r1 = new RecipeItem{ rice,2 };
RecipeItem* s2 = new RecipeItem{ salt,2 };
RecipeItem* p1 = new RecipeItem{ pepper,1 };
RecipeItem* p2 = new RecipeItem{ pepper,2 };

auto items_margaritto = new RecipeItem * [4]{ m1,t1,c1,me1 };
auto items_chicago = new RecipeItem * [5]{ m1,me1,p1,s1,c1 };
auto items_vegetarian = new RecipeItem * [5]{ m2,s2,p2,t2,c2 };
auto items_Salami = new RecipeItem * [5]{ salami1,t2,c2,s1,me1 };
auto items_kabab = new RecipeItem * [3]{ s1,me1,t1 };
auto items_potato_mushroom = new RecipeItem * [4]{ potato1,m2,s2,t2 };
auto items_lula = new RecipeItem * [4]{ me2,t2,p2,s2 };
auto items_dolma = new RecipeItem * [4]{ r1,t2,me2,s2 };
auto items_cabbage_dolma = new RecipeItem * [5]{ cabbage1,t2,s1,p1,me1 };
auto items_threeSister_dolma = new RecipeItem * [6]{ eggplant1,t1,green_pepper1,s1,p1,me1 };

Pizza* pizza = new Pizza(items_margaritto, 4, "Margaritto Pizza");
Pizza* chicago_pizza = new Pizza(items_chicago, 5, "Chicago Pizza");
Pizza* vegetarian_pizza = new Pizza(items_vegetarian, 5, "Vegetarian Pizza");
Pizza* salami_pizza = new Pizza(items_Salami, 5, "Salami Pizza");


Dolma* dolma = new Dolma(items_dolma, 4, "National Yarpaq Dolma");
Dolma* cabbage_dolma = new Dolma(items_cabbage_dolma, 5, "National Cabbage Dolma");
Dolma* three_sister_dolma = new Dolma(items_threeSister_dolma, 6, "National Three Sister Dolma");

Kabab* kabab = new Kabab(items_kabab, 3, "Turkish Kabab");
Kabab* potato_mushroom = new Kabab(items_potato_mushroom, 4, "Potato Mushroom Kabab");
Kabab* lula_kabab = new Kabab(items_lula, 4, "Lula Kabab");


HotDrink tea("Tea", 1.5, 100);
HotDrink coffee("Coffee", 2.4, 120);
HotDrink hot_chocolate("Hot Chocolate", 3.0, 150);

ColdDrink ayran("Ayran", 1.0, 95);
ColdDrink fanta("Fanta", 1.5, 100);
ColdDrink cola("Cola", 1.5, 220);
ColdDrink fruit_juice("Apple Juice", 2.5, 140);

vector<HotDrink>hot_drinks;
vector<ColdDrink>cold_drinks;

int pizza_count = 0;
int kabab_count = 0;
int dolma_count = 0;
int drink_count = 0;
Pizza** pizzas = new Pizza * [pizza_count] {};
Kabab** kababs = new Kabab * [kabab_count] {};
Dolma** dolmas = new Dolma * [dolma_count] {};
int dish_count = 0;

Dish** dishes = new Dish * [dish_count] {};


Kitchen restaurant_kichen;


int GetIndexByColdDrink(int id) {
	for (size_t i = 0; i < cold_drinks.size(); i++)
	{
		if (cold_drinks[i].GetId() == id) {
			return i;
		}
	}
	return -1;
}

int GetIndexByHotDrink(int id) {
	for (size_t i = 0; i < hot_drinks.size(); i++)
	{
		if (hot_drinks[i].GetId() == id) {
			return i;
		}
	}
	return -1;
}

ColdDrink GetColdDrinkById(int id) {
	for (size_t i = 0; i < cold_drinks.size(); i++)
	{
		if (cold_drinks[i].GetId() == id) {
			return cold_drinks[i];
		}
	}
	return ColdDrink();
}


HotDrink GetHotDrinkById(int id) {
	for (size_t i = 0; i < hot_drinks.size(); i++)
	{
		if (hot_drinks[i].GetId() == id) {
			return hot_drinks[i];
		}
	}
	return HotDrink();
}

void DeleteColdDrink(int id) {
	if (cold_drinks.size() != 0) {
		id = GetIndexByColdDrink(id);
		auto iterator = cold_drinks.begin() + id;
		cold_drinks.erase(iterator);
	}
	else {
		cout << "No Cold Drink to be Deleted !!!" << endl;
	}
}

void DeleteHotDrink(int id) {
	if (cold_drinks.size() != 0) {
		id = GetIndexByHotDrink(id);
		auto iterator = hot_drinks.begin() + id;
		hot_drinks.erase(iterator);
	}
	else {
		cout << "No Hot Drink to be Deleted !!!" << endl;
	}
}

void KitchenMenu() {
	cout << "Show Orders                       1" << endl;
	cout << "Show Drink Orders                 2" << endl;
	cout << "Show Ingredient Stock             3" << endl;
	cout << "Show Drink Stock                  4" << endl;
}


void AddColdDrink(ColdDrink cold_drink) {
	cold_drinks.push_back(cold_drink);
}

void AddHotDrink(HotDrink hot_drink) {
	hot_drinks.push_back(hot_drink);
}


void AddColdDrinkOrderToKitchen(ColdDrinkOrder cd) {
	restaurant_kichen.cold_orders.push_back(cd);
	restaurant_kichen.cd_count++;
}


ColdDrinkOrder GetCdOrderByNumber(int order_no) {

	for (size_t i = 0; i < restaurant_kichen.cold_orders.size(); i++)
	{
		if (restaurant_kichen.cold_orders[i].order_number == order_no) {
			return restaurant_kichen.cold_orders[i];
		}
	}
	ColdDrinkOrder();
}

HotDrinkOrder GetHdOrderByNumber(int order_no) {
	for (size_t i = 0; i < restaurant_kichen.hot_orders.size(); i++)
	{
		if (restaurant_kichen.hot_orders[i].order_number == order_no) {
			return restaurant_kichen.hot_orders[i];
		}
	}
	return HotDrinkOrder();
}

int GetIndexOfCdOrderByOrderNumber(int no) {

	for (size_t i = 0; i < restaurant_kichen.cold_orders.size(); i++)
	{
		if (restaurant_kichen.cold_orders[i].order_number == no) {
			return i;
		}
	}
	return -1;
}

int GetIndexOfHdOrderByOrderNumber(int no) {

	for (size_t i = 0; i < restaurant_kichen.hot_orders.size(); i++)
	{
		if (restaurant_kichen.hot_orders[i].order_number == no) {
			return i;
		}
	}
	return -1;
}

void DeleteCdOrderByOrderNumber(int order_no) {
	if (restaurant_kichen.cold_orders.size() != 0) {
		int index = GetIndexOfCdOrderByOrderNumber(order_no);
		auto iterator = restaurant_kichen.cold_orders.begin() + index;
		restaurant_kichen.cold_orders.erase(iterator);
	}
	else {
		cout << "No Hot Drink to be Deleted !!!" << endl;
	}
}

void DeleteHdOrderByOrderNumber(int order_no) {
	if (restaurant_kichen.hot_orders.size() != 0) {
		int index = GetIndexOfHdOrderByOrderNumber(order_no);
		auto iterator = restaurant_kichen.hot_orders.begin() + index;
		restaurant_kichen.hot_orders.erase(iterator);
	}
	else {
		cout << "No Hot Drink to be Deleted !!!" << endl;
	}
}

void AddHotDrinkOrderToKitchen(HotDrinkOrder hd) {
	restaurant_kichen.hot_orders.push_back(hd);
	restaurant_kichen.hd_count++;
}

void ShowDrinkStock() {

	for (size_t i = 0; i < cold_drinks.size(); i++)
	{
		cold_drinks[i].ShowDrinkForStock();
	}

	for (size_t i = 0; i < hot_drinks.size(); i++)
	{
		hot_drinks[i].ShowDrinkForStock();
	}
}


void ShowColdDrinkOrders() {
	for (size_t i = 0; i < restaurant_kichen.cold_orders.size(); i++)
	{
		cout << "\nOrder Number: " << restaurant_kichen.cold_orders[i].order_number << endl;
		cout << "=================================================" << endl;
		cout << "\nTable Number: " << restaurant_kichen.cold_orders[i].table_no << endl;
		cout << "\nOrders: " << endl;
		for (size_t k = 0; k < restaurant_kichen.cold_orders[i].ColdDrinks.size(); k++)
		{
			cout << restaurant_kichen.cold_orders[i].ColdDrinks[k].GetName() << "  -  " << restaurant_kichen.cold_orders[i].count[k] << endl;
		}
		cout << "\nTotal Price: " << restaurant_kichen.cold_orders[i].price << " $" << endl;
		cout << "===========================================================" << endl;
	}
}

bool CheckOrderNumberForCold(int no) {

	for (size_t i = 0; i <restaurant_kichen.cold_orders.size(); i++)
	{
		if (restaurant_kichen.cold_orders[i].order_number == no) {
			return true;
		}
	}
	return false;
}

bool CheckOrderNumberForHot(int no) {

	for (size_t i = 0; i < restaurant_kichen.hot_orders.size(); i++)
	{
		if (restaurant_kichen.hot_orders[i].order_number == no) {
			return true;
		}
	}
	return false;
}

void ShowHotDrinkOrders() {
	for (size_t i = 0; i < restaurant_kichen.hot_orders.size(); i++)
	{
		cout << "\nOrder Number: " << restaurant_kichen.hot_orders[i].order_number << endl;
		cout << "=================================================" << endl;
		cout << "\nTable Number: " << restaurant_kichen.hot_orders[i].table_no << endl;
		cout << "\nOrders: " << endl;
		for (size_t k = 0; k < restaurant_kichen.hot_orders[i].HotDrinks.size(); k++)
		{
			cout << restaurant_kichen.hot_orders[i].HotDrinks[k].GetName() << "  -  " << restaurant_kichen.hot_orders[i].count[k] << endl;
		}
		cout << "\nTotal Price: " << restaurant_kichen.hot_orders[i].price << " $" << endl;
		cout << "===========================================================" << endl;
	}
}


void ShowDrinkOrderMenu() {
	cout << "\nCold Drinks   1" << endl;
	cout << "Hot Drinks    2" << endl;
}

void ShowColdDrinks() {
	mysetcolor(3, 0);
	cout << "\nCold Drinks\n" << endl;
	mysetcolor(7, 0);
	for (size_t i = 0; i < cold_drinks.size(); i++)
	{
		cold_drinks[i].ShowDrink();
	}
}

void ShowHotDrinks() {
	mysetcolor(4, 0);
	cout << "\nHot Drinks\n" << endl;
	mysetcolor(7, 0);
	for (size_t i = 0; i < hot_drinks.size(); i++)
	{
		hot_drinks[i].ShowDrink();
	}
}

void ShowOrders() {
	for (size_t i = 0; i < restaurant_kichen.order_count; i++)
	{
		if (restaurant_kichen.orders[i]->meal->GetCount() != restaurant_kichen.orders[i]->items_count) {

			cout << endl;
			mysetcolor(4, 0);
			cout << "Order Number: " << restaurant_kichen.orders[i]->order_number << endl;
			mysetcolor(7, 0);
			cout << "===============================================" << endl;
			cout << restaurant_kichen.orders[i]->meal->GetName() << " ---- > Amount: " << restaurant_kichen.orders[i]->count << endl;
			cout << "T a b l e   N o: " << restaurant_kichen.orders[i]->table_no << endl;
			cout << "Order Time: " << restaurant_kichen.orders[i]->date << endl;
			cout << "Order Price: " << restaurant_kichen.orders[i]->price << " $" << endl;
			cout << "=========================" << endl;
		}
		else {
			cout << endl;
			mysetcolor(15, 0);
			cout << "Order Number: " << restaurant_kichen.orders[i]->order_number << endl;
			mysetcolor(7, 0);
			cout << "===============================================" << endl;
			cout << restaurant_kichen.orders[i]->meal->GetName() << " ---- > Amount: " << restaurant_kichen.orders[i]->count << endl;
			cout << "T a b l e   N o: " << restaurant_kichen.orders[i]->table_no << endl;
			cout << "Order Time: " << restaurant_kichen.orders[i]->date << endl;
			cout << "Order Price: " << restaurant_kichen.orders[i]->price << " $" << endl;
			cout << "=========================" << endl;
		}
	}
}

void OrderMenu() {
	cout << "\nAccept Order           1" << endl;
	cout << "Reject Order            2" << endl;
	cout << "Show Order in Details   3" << endl;
}


Table* GetTableByTableNo(int no) {

	for (size_t i = 0; i < 10; i++)
	{
		if (tables[i]->GetTableNo() == no) {
			return tables[i];
		}
	}
	return nullptr;
}


int GetOrderIndexByOrderNumber(int order_number)
{
	for (size_t i = 0; i < restaurant_kichen.order_count; i++)
	{
		if (restaurant_kichen.orders[i]->order_number == order_number) {
			return i;
		}
	}
	return -1;
}

void DeleteOrderByOrderNumber(int order_number) {
	auto neworders = new Order * [restaurant_kichen.order_count - 1]{};
	auto index = GetOrderIndexByOrderNumber(order_number);
	for (size_t i = 0; i < index; i++)
	{
		neworders[i] = restaurant_kichen.orders[i];
	}

	for (size_t i = index, i2 = index + 1; i < restaurant_kichen.order_count - 1; i++, i2++)
	{
		neworders[i] = restaurant_kichen.orders[i2];
	}

	if (restaurant_kichen.order_count != 0) {
		delete[]restaurant_kichen.orders;
	}
	restaurant_kichen.orders = neworders;
	neworders = nullptr;
	restaurant_kichen.order_count--;
}


Order* GetOrderByOrderNumber(int order_number) {
	for (size_t i = 0; i < restaurant_kichen.order_count; i++)
	{
		if (restaurant_kichen.orders[i]->order_number == order_number) {
			return restaurant_kichen.orders[i];
		}
	}
	return nullptr;
}


void AddPizza(Pizza* pizza) {
	auto newpizzas = new Pizza * [pizza_count + 1]{};
	for (size_t i = 0; i < pizza_count; i++)
	{
		newpizzas[i] = pizzas[i];
	}
	if (pizzas != nullptr) {
		delete[]pizzas;
	}
	newpizzas[pizza_count] = pizza;
	pizzas = newpizzas;
	newpizzas = nullptr;
	pizza_count++;
}

void AddDolma(Dolma* dolma) {
	auto newdolmas = new Dolma * [dolma_count + 1]{};
	for (size_t i = 0; i < dolma_count; i++)
	{
		newdolmas[i] = dolmas[i];
	}
	if (dolmas != nullptr) {
		delete[]dolmas;
	}
	newdolmas[dolma_count] = dolma;
	dolmas = newdolmas;
	newdolmas = nullptr;
	dolma_count++;
}

void AddKabab(Kabab* kabab) {
	auto newkababs = new Kabab * [kabab_count + 1]{};
	for (size_t i = 0; i < kabab_count; i++)
	{
		newkababs[i] = kababs[i];
	}
	if (kababs != nullptr) {
		delete[]kababs;
	}
	newkababs[kabab_count] = kabab;
	kababs = newkababs;
	newkababs = nullptr;
	kabab_count++;
}

void ShowPizzas() {
	mysetcolor(3, 0);
	cout << "\nPizzas\n" << endl;
	mysetcolor(7, 0);
	for (size_t i = 0; i < pizza_count; i++)
	{
		cout << pizzas[i]->GetName() << "-----------------------------------------------------------------" << pizzas[i]->GetPrice() << " $" << " (ID--> " << pizzas[i]->GetId() << ") " << endl;

	}
}



bool isSuffix(const string& text1, const string& text2) {
	int count = 0;
	if (text1.length() > text2.length()) {
		for (size_t i = 0; i < text2.length(); i++)
		{
			if (tolower(text1[text1.length() - text2.length() + i]) == tolower(text2[i])) {
				count++;
			}
		}
		if (count == text2.length()) {
			return true;
		}

		return false;
	}

	else {
		for (size_t i = 0; i < text1.length(); i++)
		{
			if (tolower(text1[i]) == tolower(text2[text2.length() - text1.length() + i])) {
				count++;
			}
		}
		if (count == text1.length()) {
			return true;
		}

		return false;
	}
}



bool isPrefix(const string& text1, const string& text2) {
	int count = 0;
	if (text1.length() > text2.length()) {
		for (size_t i = 0; i < text2.length(); i++)
		{
			if (tolower(text1[i]) == tolower(text2[i])) {
				count++;
			}
		}
		if (count == text2.length()) {
			return true;
		}

		return false;
	}

	else {
		for (size_t i = 0; i < text1.length(); i++)
		{
			if (tolower(text1[i]) == tolower(text2[i])) {
				count++;
			}
		}
		if (count == text1.length()) {
			return true;
		}

		return false;
	}
}

void ShowDrinksBySearch(const string& text) {
	for (size_t i = 0; i < hot_drinks.size(); i++)
	{
		if (isPrefix(text, hot_drinks[i].GetName()) || isSuffix(text, hot_drinks[i].GetName())) {
			hot_drinks[i].ShowDrink();
		}
	}

	for (size_t i = 0; i < cold_drinks.size(); i++)
	{
		if (isPrefix(text, cold_drinks[i].GetName()) || isSuffix(text, cold_drinks[i].GetName())) {
			cold_drinks[i].ShowDrink();
		}
	}


}

void ShowProductBySearch(const string& text) {

	for (size_t i = 0; i < dish_count; i++)
	{
		if (isPrefix(text, dishes[i]->GetName()) || isSuffix(text, dishes[i]->GetName())) {
			dishes[i]->ShowMeal();
		}
	}
}


void ShowKababs() {
	mysetcolor(4, 0);
	cout << "\nKababs\n" << endl;
	mysetcolor(7, 0);

	for (size_t i = 0; i < kabab_count; i++)
	{
		cout << kababs[i]->GetName() << "-----------------------------------------------------------------" << kababs[i]->GetPrice() << " $" << " (ID--> " << kababs[i]->GetId() << ") " << endl;

	}
}

void ShowDolmas() {
	mysetcolor(2, 0);
	cout << "\nDolma\n" << endl;
	mysetcolor(7, 0);
	for (size_t i = 0; i < dolma_count; i++)
	{
		cout << dolmas[i]->GetName() << "-----------------------------------------------------------------" << dolmas[i]->GetPrice() << " $" << " (ID--> " << dolmas[i]->GetId() << ") " << endl;

	}
}


void AddOrdersToKitchen(Order* order) {
	auto count = restaurant_kichen.order_count;
	auto neworders = new Order * [count + 1]{};

	for (size_t i = 0; i < count; i++)
	{
		neworders[i] = restaurant_kichen.orders[i];
	}
	neworders[count] = order;
	restaurant_kichen.orders = neworders;
	neworders = nullptr;
	restaurant_kichen.order_count++;
}

void MakeTableFull(const int& no) {
	for (size_t i = 0; i < 10; i++)
	{
		if (tables[i]->GetTableNo() == no) {
			tables[i]->SetIsFull(1);
		}
	}
}

void MakeTableEmpty(const int& no) {
	for (size_t i = 0; i < 10; i++)
	{
		if (tables[i]->GetTableNo() == no) {
			tables[i]->SetIsFull(0);
		}
	}
}

void ShowTables() {

	for (size_t i = 0; i < 10; i++)
	{
		tables[i]->ShowTable();
		cout << endl;
	}
}

void MainMenu() {
	cout << "\nA D M I N        1" << endl;
	cout << "C U S T O M E R  2" << endl;
}


void CustomerMenu() {
	cout << "\nShow Menu                            1" << endl;
	cout << "Show Detailed Recipe of Any Food     2" << endl;
	cout << "Search Food in the Menu              3" << endl;
	cout << "Order Food                           4" << endl;
	cout << "Notification                         5" << endl;
	cout << "Order Drink                          6" << endl;
}


void AdminMenu() {
	cout << "S T O C K        1\n" << endl;
	cout << "K I T C H E N    2" << endl;
}

void AdminSubMenu() {
	cout << "\nAdd Ingredient to the Meal          1" << endl;
	cout << "Add dish to the Menu                2" << endl;
	cout << "Delete Ingredient                   3" << endl;
	cout << "Delete dish from Menu               4" << endl;
	cout << "Show Products in Stock              5" << endl;
	cout << "Add Product to the Stock            6" << endl;
	cout << "Show Restaurant Budget              7" << endl;
	cout << "Add Drink                           8" << endl;
	cout << "Delete Drink                        9" << endl;
	cout << "Add New Product to the Stock       10" << endl;
	cout << "Show Recipes of Dishes             11" << endl;
	cout << "Show Menu                          12" << endl;

	cout << "Enter Anything To Go Back           " << endl;
}




void DrinkMenu() {
	cout << "\nHot Drink    1" << endl;
	cout << "Cold Drink   2" << endl;
}


void AddIngredientToStock(Ingredient* ingredient) {
	auto new_ingredients = new Ingredient * [ing_count + 1]{};

	for (size_t i = 0; i < ing_count; i++)
	{
		new_ingredients[i] = ingredients[i];
	}

	delete[] ingredients;
	new_ingredients[ing_count] = ingredient;
	ing_count++;
	ingredients = new_ingredients;
}

void AddDish(Dish* dish) {
	auto new_dishes = new Dish * [dish_count] {};

	for (size_t i = 0; i < dish_count; i++)
	{
		new_dishes[i] = dishes[i];
	}

	new_dishes[dish_count] = dish;

	dishes = new_dishes;
	new_dishes = nullptr;
	dish_count++;

}

//auto dishes = new Dish * [dish_count] { pizza, kabab, dolma };

Dish* GetDishById(int id) {

	for (size_t i = 0; i < dish_count; i++)
	{
		if (dishes[i]->GetId() == id) {
			return dishes[i];
		}
	}
	return nullptr;
}


int GetDishIndexByID(int id) {

	for (size_t i = 0; i < dish_count; i++)
	{
		if (dishes[i]->GetId() == id) {
			return i;
		}
	}
	return -1;
}

void DeleteDishByID(int id) {
	int dish_index = GetDishIndexByID(id);
	auto new_dishes = new Dish * [dish_count - 1]{};
	for (size_t i = 0; i < dish_index; i++)
	{
		new_dishes[i] = dishes[i];
	}

	for (size_t i = dish_index, i2 = dish_index + 1; i < dish_count - 1; i++, i2++)
	{
		new_dishes[i] = dishes[i2];
	}
	dishes = new_dishes;
	new_dishes = nullptr;
	dish_count--;
}

Ingredient* GetIngredientById(int id) {

	for (size_t i = 0; i < ing_count; i++)
	{
		if (ingredients[i]->GetId() == id) {
			return ingredients[i];
		}
	}

	return nullptr;
}

void ShowDishes() {
	mysetcolor(15, 0);
	cout << "\nR E S T A U R A N T  M E N U" << endl;;
	mysetcolor(7, 0);
	mysetcolor(6, 0);
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	mysetcolor(7, 0);
	cout << endl;
	for (size_t i = 0; i < dish_count; i++)
	{
		cout << dishes[i]->GetName();
		for (size_t i = 0; i < 25; i++)
		{
			cout << setw(3) << " - ";
		}
		cout << setw(3) << dishes[i]->GetPrice() << " $" << " (ID --> " << dishes[i]->GetId() << ") " << endl;
		cout << "========================================================================================================================\n\n" << endl;
	}

	mysetcolor(6, 0);
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	mysetcolor(7, 0);
}



void ShowIngredients() {

	for (size_t i = 0; i < ing_count; i++)
	{
		cout << "\nID: " << ingredients[i]->GetId() << endl;
		cout << "Ingredient Name: " << ingredients[i]->GetName() << endl;
		cout << "Ingredient Price: " << ingredients[i]->GetPrice() << " $" << endl;
		cout << "Ingredient Count: " << ingredients[i]->GetCount() << endl;
		cout << "===========================" << endl;
	}
}

Dish* DefineNewDishType(Dish* dish, RecipeItem** items, int count, string name) {


	if (dish->GetId() == 1) {
		Dish* new_dish = new Pizza(items, count, name);
		return new_dish;
	}
	else if (dish->GetId() == 2) {
		Dish* new_dish = new Kabab(items, count, name);
		return new_dish;
	}
	else if (dish->GetId() == 3) {
		Dish* new_dish = new Dolma(items, count, name);
		return new_dish;
	}
	else {
		return nullptr;
	}

}




void ShowDishTypes() {
	cout << "\nP I Z Z A - - - 1" << endl;
	cout << "D O L M A - - - 2" << endl;
	cout << "K A B A B - - - 3" << endl;
}


bool CheckAddmin(vector<Admin> admins, string username, string password) {

	for (size_t i = 0; i < admins.size(); i++)
	{
		if (admins[i].GetUsername() == username && admins[i].GetPassword() == password) {
			return true;
		}
	}
	return false;
}


int GetIngredientIndexById(int id) {

	for (size_t i = 0; i < ing_count; i++)
	{
		if (stock.ingredients[i]->GetId() == id) {
			return i;
		}
	}
	return -1;
}

void UpdateIngredientInStock(Ingredient* ingredient) {

	int index = GetIngredientIndexById(ingredient->GetId());
	stock.ingredients[index] = ingredient;
}

void ShowStock() {
	for (size_t i = 0; i < ing_count; i++)
	{
		ingredients[i]->ShowIngredient();
	}
}


