#pragma once

#include<iostream>
#include "Functions.h"
#include<string>
#include<ctime>
#include<vector>
#include<string.h>
#include"File.h"
using namespace std;



int order_number = 0;
double budget = 0;
int cd_order_number = 0;
int hd_order_number = 0;
void Start() {

	restaurant.AddAdmin(head_admin);
	restaurant.AddAdmin(assistant_admin);

	WriteAdminsToFile();

	AddHotDrink(tea);
	AddHotDrink(coffee);
	AddHotDrink(hot_chocolate);

	AddColdDrink(ayran);
	AddColdDrink(fanta);
	AddColdDrink(cola);
	AddColdDrink(fruit_juice);

	AddPizza(pizza);
	AddPizza(vegetarian_pizza);
	AddPizza(salami_pizza);
	AddPizza(chicago_pizza);

	AddKabab(lula_kabab);
	AddKabab(kabab);
	AddKabab(potato_mushroom);

	AddDolma(cabbage_dolma);
	AddDolma(dolma);
	AddDolma(three_sister_dolma);

	AddDish(pizza);
	AddDish(salami_pizza);
	AddDish(vegetarian_pizza);
	AddDish(chicago_pizza);
	AddDish(three_sister_dolma);
	AddDish(dolma);
	AddDish(cabbage_dolma);
	AddDish(kabab);
	AddDish(lula_kabab);
	AddDish(potato_mushroom);


	AddIngredientToStock(mushroom);
	AddIngredientToStock(tomato);
	AddIngredientToStock(cheese);
	AddIngredientToStock(salt);
	AddIngredientToStock(meat);
	AddIngredientToStock(pepper);
	AddIngredientToStock(rice);
	AddIngredientToStock(eggplant);
	AddIngredientToStock(potato);
	AddIngredientToStock(green_pepper);
	AddIngredientToStock(cabbage);
	AddIngredientToStock(salami);

	WriteStockToFile();
	while (true) {
		MainMenu();
		int select = 0;
		cout << "\nEnter the option: ";
		cin >> select;

		try
		{
			if (select == 1) {
				auto admins = ReadAdmins();
				cin.ignore();
				cin.clear();

				string username;
				cout << "Enter username: ";
				getline(cin, username);

				cout << "Enter the password: ";
				string password;
				getline(cin, password);
				system("cls");
				if (CheckAddmin(admins, username, password)) {

					while (true) {
						system("cls");
						AdminMenu();
						int option = 0;
						cout << "\nEnter the option: ";
						cin >> option;
						system("cls");
						if (option == 1) {
							while (true) {
								system("cls");
								AdminSubMenu();
								int option = 0;
								cout << "\nEnter the option: ";
								cin >> option;
								if (option == 1) {
									//Add Ingredient

									ShowDishes();
									int dish_id = 0;
									cout << "\nChoose the dish type for which you would like to add ingredient (BY ID) : ";
									cin >> dish_id;

									system("cls");
									auto dish = GetDishById(dish_id);
									dish->PrintRecipe();
									ShowIngredients();
									int ing_id = 0;
									cout << "Enter ingredient ID : ";
									cin >> ing_id;

									int amount = 0;
									cout << "Enter the amount : ";
									cin >> amount;

									auto ingredient = GetIngredientById(ing_id);

									auto item = new RecipeItem{ ingredient,amount };

									dish->AddIngredient(item);
									cout << "Success - - - > ";
									cout << amount << " " << ingredient->GetName() << " successfully added to the " << dish->GetName() << endl;
									system("pause");

								}
								else if (option == 2) {
									//Add Dish to the Menu
									ShowIngredients();

									int number = 0;
									cout << "The number of ingredients to be added: ";
									cin >> number;

									RecipeItem** items = new RecipeItem * [number] {};

									for (size_t i = 0; i < number; i++)
									{
										system("cls");
										ShowIngredients();
										int ing_id = 0;
										cout << "Choose ingredient (BY ID) : ";
										cin >> ing_id;

										int ing_number = 0;
										cout << "Enter amount: ";
										cin >> ing_number;
										auto ingredient = GetIngredientById(ing_id);
										RecipeItem* item = new RecipeItem{ ingredient,ing_number };
										items[i] = item;
										ingredient->SetCount(ingredient->GetCount() - ing_number);
									}

									cin.ignore();
									cin.clear();
									string dish_name;
									cout << "Enter the dish name: ";
									getline(cin, dish_name);

									Dish* new_dish = new Any(items, number, dish_name);

									AddDish(new_dish);
									cout << "\nSuccess - - - > ";
									cout << new_dish->GetName() << " successfully added to the Menu" << endl;
									system("pause");
								}
								else if (option == 3) {
									//Delete Ingredient
									for (size_t i = 0; i < dish_count; i++)
									{
										dishes[i]->PrintRecipe();
									}

									int dish_id = 0;
									cout << "Choose the dish type for which you would like to delete ingredient (BY ID) : ";
									cin >> dish_id;

									int ing_id = 0;
									cout << "Enter Ingredient (BY ID): ";
									cin >> ing_id;

									auto dish = GetDishById(dish_id);

									dish->DeleteIngredient(ing_id);

									cout << "\nSuccess - - - > ";
									cout << "Ingredient with ID " << ing_id << " successfully deleted from ";
									mysetcolor(4, 0);
									cout << dish->GetName();
									mysetcolor(7, 0);
									cout << "  recipe !!!" << endl;
									system("pause");
								}

								else if (option == 4) {
									//Delete Dish

									ShowDishes();

									int id = 0;
									cout << "Enter the dish ID: ";
									cin >> id;

									DeleteDishByID(id);
									cout << "\nSuccess - - - > ";
									cout << "Dish with ID " << id << " successfully deleted from Menu" << endl;;
									system("pause");
								}

								else if (option == 5) {
									//Show Stock
									mysetcolor(4, 0);
									cout << "\nPRODUCTS IN STOCK \n" << endl;
									mysetcolor(7, 0);

									for (size_t i = 0; i < ing_count; i++)
									{
										ingredients[i]->ShowIngredient();
										cout << "\n==========================\n";
									}
									system("pause");
								}

								else if (option == 6) {
									//Add Ingredient to Stock

									ShowIngredients();

									int id = 0;
									cout << "Enter ingredient ID: ";
									cin >> id;
									auto ingredient = GetIngredientById(id);

									int count = 0;
									cout << "Enter the amount: ";
									cin >> count;

									int new_count = ingredient->GetCount() + count;
									ingredient->SetCount(new_count);
									if (restaurant.GetBudget() >= ingredient->GetPrice() * count) {

										restaurant.SetBudget(restaurant.GetBudget() - (ingredient->GetPrice() * count));
										cout << endl;
										cout << count << " " << ingredient->GetName() << " Added Successfully !" << endl;
										cout << "=========================" << endl;

										system("pause");
										WriteStockToFile();
									}
									else {
										mysetcolor(4, 0);
										cout << "\nA lack of Budget" << endl;
										mysetcolor(7, 0);
										system("pause");
									}
								}
								else if (option == 7) {


									if (restaurant.GetBudget() > 0) {

										cout << "\nRestaurant Budget: ";
										mysetcolor(2, 0);
										cout << restaurant.GetBudget() << " $" << endl;
										mysetcolor(7, 0);
										system("pause");
									}
									else {
										cout << "\nRestaurant Budget: ";
										mysetcolor(4, 0);
										cout << restaurant.GetBudget() << " $" << endl;
										mysetcolor(7, 0);
										system("pause");
									}
								}

								else if (option == 8) {
									//AddNewDrinkToMenu}
									DrinkMenu();

									int select = 0;
									cout << "\nEnter the option: ";
									cin >> select;

									if (select == 1) {
										cin.ignore();
										cin.clear();

										string name;
										cout << "\nEnter hot drink name: ";
										getline(cin, name);

										double price;
										cout << "Price: ";
										cin >> price;

										int count = 0;
										cout << "Enter its count in the stock: ";
										cin >> count;


										HotDrink hotdrink(name, price, count);
										AddHotDrink(hotdrink);
										cout << "\n" << name << " has been successfully added to the Menu" << endl;
										system("pause");
									}

									else if (select == 2) {
										cin.ignore();
										cin.clear();

										string name;
										cout << "Enter hot drink name: ";
										getline(cin, name);

										double price;
										cout << "Price: ";
										cin >> price;

										int count = 0;
										cout << "Enter its count in the stock: ";
										cin >> count;

										ColdDrink coldrink(name, price, count);

										AddColdDrink(coldrink);
										cout << "\n" << name << " has been successfully added to the Menu" << endl;
										system("pause");
									}
									else {
										mysetcolor(4, 0);
										cout << "\nInvalid Input" << endl;
										mysetcolor(7, 0);
									}

								}

								else if (option == 9) {
									//Delete Drink From the Menu
									DrinkMenu();

									int select = 0;
									cout << "\nEnter the option: ";
									cin >> select;

									if (select == 1) {
										ShowHotDrinks();
										int id_hot = 0;
										cout << "Enter the ID: ";
										cin >> id_hot;

										DeleteHotDrink(id_hot);
										cout << "\n Successfully Deleted " << endl;
										system("pause");
									}

									else if (select == 2) {
										ShowColdDrinks();
										int id_cold = 0;
										cout << "Enter the ID: ";
										cin >> id_cold;

										DeleteColdDrink(id_cold);
										cout << "\n Successfully Deleted " << endl;
										system("pause");
									}

									else {
										mysetcolor(4, 0);
										cout << "Invalid Input" << endl;
										mysetcolor(7, 0);
									}
								}

								else if (option == 10) {
									cin.ignore();
									cin.clear();
									string name;
									cout << "Enter the name: ";
									getline(cin, name);

									double ingredient_price;
									cout << "Enter the price: ";
									cin >> ingredient_price;
									double fats;
									cout << "Enter fats: ";
									cin >> fats;

									double protein;
									cout << "Enter the protein: ";
									cin >> protein;

									double carbohydrates;
									cout << "Enter the carbohydrate: ";
									cin >> carbohydrates;

									int kcal;
									cout << "Enter the kkal: ";
									cin >> kcal;

									int ingredient_count;
									cout << "Enter the count: ";
									cin >> ingredient_count;

									if (restaurant.GetBudget() >= ingredient_count * ingredient_price) {

										Ingredient* ingredient = new Other(name, fats, protein, carbohydrates, kcal, ingredient_count, ingredient_price);
										AddIngredientToStock(ingredient);
										cout << "\n" << ingredient->GetName() << " successfully added to the Stock" << endl;
										system("pause");
										WriteStockToFile();
										restaurant.SetBudget(restaurant.GetBudget() - (ingredient_count * ingredient_price));
									}
									else {
										mysetcolor(4, 0);
										cout << "\nLack of Budget !!!" << endl;
										mysetcolor(7, 0);
										system("pause");
									}
								}

								else if (option == 11) {
									for (size_t i = 0; i < dish_count; i++)
									{
										dishes[i]->PrintRecipe();
									}
									system("pause");
								}
								else if (option == 12) {

									cout << "=======================================================================================" << endl;
									ShowDishes();
									ShowHotDrinks();
									ShowColdDrinks();
									cout << "\n=====================================================================================" << endl;
									system("pause");
								}
								else if (option == 0) {
									break;
								}

								else {
									continue;
								}
							}

						}



						else if (option == 2) {
							KitchenMenu();

							int select = 0;
							cout << "Enter the option: ";
							cin >> select;

							if (select == 1) {
								if (restaurant_kichen.order_count != 0) {

									ShowOrders();
									OrderMenu();
									int number = 0;
									cout << "Enter the option: ";
									cin >> number;
									if (number == 1) {
										system("cls");
										ShowOrders();

										int order_number = 0;
										cout << "Enter the order number: ";
										cin >> order_number;
										auto order = GetOrderByOrderNumber(order_number);
										budget += order->price;
										restaurant.SetBudget(budget);

										for (size_t i = 0; i < order->count; i++)
										{
											for (size_t k = 0; k < order->items_count; k++)
											{
												auto ingredient = GetIngredientById(order->items[k]->ingredient->GetId());
												ingredient->SetCount(order->items[k]->ingredient->GetCount() - order->items[k]->amount);
											}
										}
										WriteStockToFile();
										DeleteOrderByOrderNumber(order_number);
										cout << "Order Accepted !!!" << endl;
										system("pause");
									}
									else if (number == 2) {
										system("cls");
										ShowOrders();

										int order_number = 0;
										cout << "Enter the order number: ";
										cin >> order_number;

										auto order = GetOrderByOrderNumber(order_number);

										cin.ignore();
										cin.clear();

										string messageFromKitchen;
										cout << "Enter the reason for rejection: ";
										getline(cin, messageFromKitchen);

										int table_no = order->table_no;
										auto table = GetTableByTableNo(table_no);

										table->SetMessage(messageFromKitchen);
										mysetcolor(4, 0);
										cout << "Order with order number " << order->order_number << " has been successfully rejected " << endl;
										mysetcolor(7, 0);
										system("pause");
									}

									else if (number == 3) {
										system("cls");
										ShowOrders();

										int order_number = 0;
										cout << "Enter the order number: ";
										cin >> order_number;

										auto order = GetOrderByOrderNumber(order_number);
										for (size_t i = 0; i < order->items_count; i++)
										{
											cout << order->items[i]->ingredient->GetName() << " - " << order->items[i]->amount << endl;
											cout << "===================================" << endl;
										}
										system("pause");
									}


									else {
										break;
									}

								}
								else {
									mysetcolor(4, 0);
									cout << "\nNo orders in the list for the moment" << endl;
									mysetcolor(7, 0);
								}

							}

							else if (select == 2) {
								ShowDrinkOrderMenu();
								int option = 0;
								cout << "Enter the option: ";
								cin >> option;

								if (option == 1) {
									if (restaurant_kichen.cold_orders.size() != 0) {
										ShowColdDrinkOrders();

										int no = 0;
										cout << "Enter order number: ";
										cin >> no;
										if (CheckOrderNumberForCold(no)) {

											auto cd_order = GetCdOrderByNumber(no);
											restaurant.SetBudget(restaurant.GetBudget() + cd_order.price);
											cout << "Order number " << cd_order.order_number << " for table no " << cd_order.table_no << " has been successfully accepted" << endl;
											DeleteCdOrderByOrderNumber(no);
											system("pause");
										}
										else {
											mysetcolor(4, 0);
											cout << "\nInvalid Input" << endl;
											mysetcolor(7, 0);
											system("pause");
										}
									}
									else {
										mysetcolor(4, 0);
										cout << "\nNo Cold Drink Orders" << endl;
										mysetcolor(7, 0);
										system("pause");
									}
								}

								else if (option == 2) {
									if (restaurant_kichen.hot_orders.size() != 0) {
										ShowHotDrinkOrders();
										int no = 0;
										cout << "Enter order number: ";
										cin >> no;

										if (CheckOrderNumberForHot(no)) {

											auto hd_order = GetHdOrderByNumber(no);
											restaurant.SetBudget(restaurant.GetBudget() + hd_order.price);
											cout << "Order number " << hd_order.order_number << " for table no " << hd_order.table_no << " has been successfully accepted" << endl;
											DeleteHdOrderByOrderNumber(no);
											system("pause");
										}
										else {
											mysetcolor(4, 0);
											cout << "\nInvalid Input" << endl;
											mysetcolor(7, 0);
											system("pause");

										}
									}
									else {
										mysetcolor(4, 0);
										cout << "\nNo Hot Drink Orders" << endl;
										mysetcolor(7, 0);
										system("pause");
									}
								}

							}
							else if (select == 3) {
								ShowStock();
								system("pause");
							}
							else if (select == 4) {
								ShowDrinkStock();
								system("pause");
							}
						}
						else if (option == 0) {
							break;
						}
					}
				}

				else {
					mysetcolor(4, 0);
					cout << "\nWrong username or password" << endl;
					mysetcolor(7, 0);

					continue;
				}
			}

			else if (select == 2) {
				ShowTables();
				int table_select = 0;
				cout << "Enter the table no( RED -> FULL / GREEN -> EMPTY ): ";
				cin >> table_select;
				system("cls");
				cout << "\n                                                 Table No: " << table_select << endl;
				CustomerMenu();
				int select = 0;
				cout << "Enter the option: ";
				cin >> select;
				system("cls");
				if (select == 1) {
					//Show Food Menu to Customer
					//ShowDishes();
					cout << "=======================================================================================" << endl;
					ShowDishes();
					ShowHotDrinks();
					ShowColdDrinks();
					cout << "\n=====================================================================================" << endl;
				}
				else if (select == 2) {
					ShowDishes();

					int id = 0;
					cout << "Enter Id: ";
					cin >> id;

					for (size_t i = 0; i < dish_count; i++)
					{
						if (dishes[i]->GetId() == id) {
							dishes[i]->PrintRecipe();
							break;
						}
					}
				}

				else if (select == 3) {
					//Search Food
					while (true) {
						cout << "\nFood                      1" << endl;
						cout << "Drink                     2" << endl;
						cout << "Go Back --> Enter any number" << endl;

						int select = 0;
						cout << "\nEnter the select: ";
						cin >> select;

						system("cls");
						if (select == 1) {

							cin.ignore();
							cin.clear();

							string text;
							cout << "Enter the text: ";
							getline(cin, text);

							ShowProductBySearch(text);
						}
						else if (select == 2) {

							cin.ignore();
							cin.clear();

							string text;
							cout << "Enter the text: ";
							getline(cin, text);

							ShowDrinksBySearch(text);
						}
						else {
							break;
						}
					}
				}

				else if (select == 4) {
					//Order Food
					ShowDishes();
					while (true) {

						int id = 0;
						cout << "\nEnter ID(Go Back --> 0): ";
						cin >> id;
						if (id == 0) {
							break;
						}
						auto dish = GetDishById(id);

						int amount = 0;
						cout << "Enter the amount: ";
						cin >> amount;

						cout << "Would you like to add another ingredient ?(Yes - 1, No - 2)" << endl;

						int option = 0;
						cout << "Enter the option: ";
						cin >> option;

						if (option == 2) {
							auto items = dish->GetItems();
							double price = dish->GetPrice() * amount;
							cout << "Transaction has been implemented successfully\n" << endl;
							cout << "\nPayment: " << price << " $" << endl;
							string date = __DATE__;
							cout << "Date: " << date << endl;
							MakeTableFull(table_select);
							order_number++;
							Order* order = new Order{ dish,amount,date,table_select,order_number,price ,items };
							order->items_count = order->meal->GetCount();
							order->items = order->meal->GetItems();
							AddOrdersToKitchen(order);
							WriteOrderToFile();
						}
						else if (option == 1) {
							double price = dish->GetPrice() * amount;
							string date = __DATE__;
							double post_price = 0;
							order_number++;
							Order* order = new Order{ dish,amount,date,table_select,order_number,price };
							order->items_count = order->meal->GetCount();
							order->items = order->meal->GetItems();
							while (true)
							{
								system("cls");
								ShowIngredients();

								int id = 0;
								cout << "Enter ID(Go Back --> 0): ";
								cin >> id;
								if (id == 0) {
									break;
								}
								int amount = 0;
								cout << "Enter the amount: ";
								cin >> amount;
								auto ingredient = GetIngredientById(id);

								RecipeItem* item = new RecipeItem{ ingredient,amount };
								post_price += ingredient->GetPrice() * amount;

								order->AddIngredientToDish(item, order);
								
							}
							price += post_price;
							order->price = price;
							
							cout << "\nPayment: " << price << " $" << endl;
							cout << "Date: " << date << endl;

							cout << "Transaction has been implemented successfully" << endl;
							MakeTableFull(table_select);
							AddOrdersToKitchen(order);
							WriteOrderToFile();

						}
						else {
							mysetcolor(4, 0);
							cout << "Invalid Input" << endl;
							mysetcolor(7, 0);
						}
					}
				}

				else if (select == 5) {
					auto table = GetTableByTableNo(table_select);
					cout << "Message: " << table->GetKitchenMessage() << endl;
				}

				else if (select == 6) {
					//Order Drink
					ShowHotDrinks();
					ShowColdDrinks();

					while (true) {
						cout << "\nHot Drink    1" << endl;
						cout << "Cold Drink   2" << endl;

						int select = 0;
						cout << "Enter option: ";
						cin >> select;
						system("cls");
						vector<HotDrink>hotDrinks;
						vector<ColdDrink>coldDrinks;
						int counter[10] = {};
						size_t index = 0;
						if (select == 1) {
							while (true) {
								system("cls");
								ShowHotDrinks();
								int id = 0;
								cout << "Enter Drink ID(Go Back - 0): ";
								cin >> id;
								if (id == 0) {
									break;
								}

								int count = 0;
								cout << "Enter the count: ";
								cin >> count;


								auto hot_drink = GetHotDrinkById(id);
								hotDrinks.push_back(hot_drink);
								counter[index] = count;
								index++;
							}
							double sum_price = 0;
							for (size_t i = 0; i < hotDrinks.size(); i++)
							{
								sum_price += hotDrinks[i].GetPrice() * counter[i];
							}

							cout << "\nTransaction has been successfully implemented !!!" << endl;
							cout << "\Orders: " << endl;

							for (size_t i = 0; i < hotDrinks.size(); i++)
							{
								cout << hotDrinks[i].GetName() << " - " << hotDrinks[i].GetPrice() << " $" << endl;
								cout << "Count: " << counter[i] << endl;
								cout << "=================" << endl;

							}
							cout << "\nPayment: " << sum_price << " $" << endl;
							hd_order_number++;
							HotDrinkOrder hd;
							hd.order_number = hd_order_number;
							hd.table_no = table_select;
							hd.HotDrinks = hotDrinks;
							for (size_t i = 0; i < 10; i++)
							{
								hd.count[i] = counter[i];
							}
							hd.price = sum_price;
							AddHotDrinkOrderToKitchen(hd);
							WriteHotDrinkOrdersToFile(hd);
							MakeTableFull(table_select);
						}
						else if (select == 2) {
							ShowColdDrinks();
							//int count_order = 0;
							while (true) {
								system("cls");
								ShowColdDrinks();
								int id = 0;
								cout << "Enter Drink ID(Go Back - 0): ";
								cin >> id;
								if (id == 0) {
									break;
								}

								int count = 0;
								cout << "Enter the count: ";
								cin >> count;

								//	count_order++;
								auto cold_drink = GetColdDrinkById(id);
								coldDrinks.push_back(cold_drink);
								counter[index] = count;
								index++;
							}
							double sum_price = 0;
							for (size_t i = 0; i < coldDrinks.size(); i++)
							{
								sum_price += coldDrinks[i].GetPrice() * counter[i];
							}

							cout << "\nTransaction has been successfully implemented !!!" << endl;
							cout << "\nOrders: " << endl;

							for (size_t i = 0; i < coldDrinks.size(); i++)
							{
								cout << coldDrinks[i].GetName() << " - " << coldDrinks[i].GetPrice() << " $" << endl;
								cout << "Count: " << counter[i] << endl;
								cout << "=================" << endl;

							}
							cout << "\nPayment: " << sum_price << " $" << endl;
							cd_order_number++;
							ColdDrinkOrder cd;
							cd.order_number = cd_order_number;
							cd.table_no = table_select;
							cd.ColdDrinks = coldDrinks;
							for (size_t i = 0; i < 10; i++)
							{
								cd.count[i] = counter[i];
							}
							cd.price = sum_price;
							AddColdDrinkOrderToKitchen(cd);
							WriteColdDrinkOrdersToFile(cd);
							MakeTableFull(table_select);
						}

						else if (select == 0) {
							break;
						}
					}

				}

			}

		}
		catch (const string& ex)
		{
			cout << "Error: " << ex << endl;
		}

		catch (...) {
			continue;
		}

	}

}
