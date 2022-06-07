#pragma once

#include<iostream>
using namespace std;

#include "Functions.h"
#include<fstream>



void WriteAdminsToFile() {
	ofstream fout("admins.txt", ios::out);

	if (fout.is_open()) {

		fout << restaurant.GetAdmins().size() << endl;

		for (size_t i = 0; i < restaurant.GetAdmins().size(); i++)
		{
			fout << restaurant.GetAdmins()[i].GetId() << endl;
			fout << restaurant.GetAdmins()[i].GetName() << endl;
			fout << restaurant.GetAdmins()[i].GetSurname() << endl;
			fout << restaurant.GetAdmins()[i].GetUsername() << endl;
			fout << restaurant.GetAdmins()[i].GetPassword() << endl;
		}

	}
	fout.close();
}

vector<Admin> ReadAdmins() {
	ifstream fin("admins.txt");
	vector<Admin> admins;

	if (fin.is_open()) {
		int count = 0;
		fin >> count;

		for (size_t i = 0; i < count; i++)
		{
			int id = 0;
			fin >> id;

			string name;
			fin >> name;

			string surname;
			fin >> surname;

			string username;
			fin >> username;

			string password;
			fin >> password;

			Admin admin;

			admin.SetId(id);
			admin.SetName(name);
			admin.SetSurname(surname);
			admin.SetUsername(username);
			admin.SetPassword(password);

			admins.push_back(admin);
		}
		return admins;
	}
	fin.close();
}


void WriteOrderToFile() {
	ofstream fout("orders.txt", ios::app);

	if (fout.is_open()) {
		fout << restaurant_kichen.order_count << endl;

		for (size_t i = 0; i < restaurant_kichen.order_count; i++)
		{
			fout << "Order number: " << restaurant_kichen.orders[i]->order_number << endl;
			fout << "Order Count: " << restaurant_kichen.orders[i]->count << endl;
			fout << "Meal Id: " << restaurant_kichen.orders[i]->meal->GetId() << endl;
			fout << "Meal Name: " << restaurant_kichen.orders[i]->meal->GetName() << endl;
			fout << "Table No: " << restaurant_kichen.orders[i]->table_no << endl;
			fout << "Order Price: " << restaurant_kichen.orders[i]->price << " $" << endl;
			fout << "Order Date: " << restaurant_kichen.orders[i]->date << endl;
			fout << "==============================================" << endl;
		}
	}

	fout.close();
}


void WriteStockToFile() {
	ofstream fout("stock.txt", ios::out);

	if (fout.is_open()) {
		fout << ing_count << endl;

		for (size_t i = 0; i < ing_count; i++)
		{
			fout << "ID: " << ingredients[i]->GetId() << endl;
			fout << "Ingredient Name: " << ingredients[i]->GetName() << endl;
			fout << "Count: " << ingredients[i]->GetCount() << endl;
			fout << "Price: " << ingredients[i]->GetPrice() << " $" << endl;
			fout << "===================================================" << endl;
		}
	}
	fout.close();
}


void WriteColdDrinkOrdersToFile(const ColdDrinkOrder& cd) {
	ofstream fout("Colddrinkorders.txt", ios::app);

	if (fout.is_open()) {


		fout << "Table No: " << cd.table_no << endl;
		fout << "Price: " << cd.price <<" $"<< endl;
		fout << "Order number: " << cd.order_number << endl;

		for (size_t k = 0; k < cd.ColdDrinks.size(); k++)
		{
			fout << cd.ColdDrinks[k].GetName() << " -  " << cd.count[k] << endl;

		}
		fout << "==============================" << endl;

		fout.close();
	}
}

void WriteHotDrinkOrdersToFile(const HotDrinkOrder& hd) {
	ofstream fout("Hotdrinkorders.txt", ios::app);

	if (fout.is_open()) {


		fout << "Table No: " << hd.table_no << endl;
		fout << "Price: " << hd.price << " $" << endl;
		fout << "Order number: " << hd.order_number << endl;

		for (size_t k = 0; k < hd.HotDrinks.size(); k++)
		{
			fout << hd.HotDrinks[k].GetName() << " -  " << hd.count[k] << endl;

		}
		fout << "==============================" << endl;

		fout.close();
	}
}



