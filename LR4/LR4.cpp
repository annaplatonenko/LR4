﻿// Лабораторная работа №4
// Вариант 5
// Реализовать базовый класс Футболл и унаследовать от него 3 разных дочерних класса(на свое усмотрение), 
// каждый из которых будет добавлять разные поля и методы к базовому классу.
// В каждом классе должно быть как минимум 2 поля(в дочерних классах также должно быть как минимум 2 своих поля), характеризующие объект.
// Инициализация полей базового класса при создании объекта дочернего класса должна реализоваться через вызов конструктора базового класса.
// Реализовать возможность просмотра содержимого.
// Продемонстрировать создание, инициализацию полей и работу объектов дочерних классов.
// Также необходимо продемонстрировать диаграмму классов.

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Football
{
private:
	int* number_players;
	int* field_size;

public:
	Football(int number_players = 0, int field_size = 0)
	{
		//cout << "Конструктор Football" << endl;
		this->number_players = new int(number_players);
		this->field_size = new int(field_size);
	}

	~Football()
	{
		//cout << "Деструктор Football" << endl;
		delete number_players;
		delete field_size;
	}

	int getnumberplayers()
	{
		return *number_players;
	}

	int getfieldsize()
	{
		return *field_size;
	}

	void virtual printall()
	{
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
	}
};

class Mini_Football : public Football
{
private:
	int* collar_size;
	string* place;

public:
	Mini_Football(int number_players = 0, int field_size = 0, int collar_size = 0, string place = "no name") : Football(number_players, field_size)
	{
		//cout << "Конструктор Mini_Football" << endl;
		this->collar_size = new int(collar_size);
		this->place = new string(place);
	}

	~Mini_Football()
	{
		//cout << "Деструктор Mini_Football" << endl;
		delete collar_size;
		delete place;
	}

	int getcollarsize()
	{
		return *collar_size;
	}

	string getplace()
	{
		return *place;
	}

	void printall() override
	{
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "размер ворот " << getcollarsize() << endl;
		cout << "место " << getplace() << endl << endl;
	}
};

class Beach_Football : public Football
{
private:
	string* beach;

public:
	Beach_Football(int number_players = 0, int field_size = 0, string beach = "no name") : Football(number_players, field_size)
	{
		//cout << "Конструктор Beach_Football" << endl;
		this->beach = new string(beach);
	}

	~Beach_Football()
	{
		//cout << "Деструктор Beach_Football" << endl;
		delete beach;
	}

	string getbeach()
	{
		return *beach;
	}

	void printall() override
	{
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "пляж " << getbeach() << endl << endl;
	}
};

class Rugby_Football : public Football
{
private:
	string* stadium;
	string* team_name;

public:
	Rugby_Football(int number_players = 0, int field_size = 0, string stadium = "no name", string team_name = "no name") : Football(number_players, field_size)
	{
		//cout << "Конструктор Rugby_Football" << endl;
		this->stadium = new string(stadium);
		this->team_name = new string(team_name);
	}

	~Rugby_Football()
	{
		//cout << "Деструктор Rugby_Football" << endl;
		delete stadium;
		delete team_name;
	}

	string getstadium()
	{
		return *stadium;
	}

	string getteam_name()
	{
		return *team_name;
	}

	void printall() override
	{
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "стадион " << getstadium() << endl;
		cout << "название команды " << getteam_name() << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Mini_Football* mini = new Mini_Football(10, 70 * 100, 8 * 8, "stadium BSUIR");
	Beach_Football* beach = new Beach_Football(16, 70 * 100, "South Beach in Miami");
	Rugby_Football* rugby = new Rugby_Football(12, 70 * 100, "Twickenham", "DreamTeam");

	/*cout << "Mini_Football:"  << endl;
	cout << "количество игроков " << mini->getnumberplayers() << endl;
	cout << "размер поля " << mini->getfieldsize() << endl;
	cout << "размер ворот " << mini->getcollarsize() << endl;
	cout << "место " << mini->getplace() << endl << endl;
	cout << "Beach_Football:" << endl;
	cout << "количество игроков " << beach->getnumberplayers() << endl;
	cout << "размер поля " << beach->getfieldsize() << endl;
	cout << "пляж " << beach->getbeach() << endl << endl;
	cout << "Rugby_Football:" << endl;
	cout << "количество игроков " << rugby->getnumberplayers() << endl;
	cout << "размер поля " << rugby->getfieldsize() << endl;
	cout << "стадион " << rugby->getstadium() << endl;
	cout << "название команды " << rugby->getteam_name() << endl;*/

	mini->printall();
	beach->printall();
	rugby->printall();

	delete mini;
	delete beach;
	delete rugby;
}




