/*
 DIJKSTRA ALGORITHM
 PRIM`S ALGORITHM
 MERGE SORT
 COUNT FIBONACHI

 SEGMENT SORT
 RECURSIVE
 
 Реализация алгоритмов с предметной областью - еда/магазин

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <utility>

#define INFINITY 3435973836

using namespace std;

class ShopCart
{
public:
	ShopCart() {
		this->calories = NULL;
		this->price = NULL;
		this->distance = NULL;
		this->count = NULL;

		this->min = NULL;
		this->path = NULL;
	};

	void calcPrice(vector<int> FirstShop, vector<int> SecondShop) { //MERGE SORT

		vector<int> result; //результирующий вектор
		vector<int> temp; // временный буфер

		for (size_t i = 0; i < FirstShop.size(); i++)
		{
			if (FirstShop[i] < SecondShop[i])
			{
				result.push_back(FirstShop[i]); temp.push_back(SecondShop[i]);
			}

			else { result.push_back(SecondShop[i]); temp.push_back(FirstShop[i]); }

			if (temp.size() == 2)
			{
				if (temp[0] < temp[1])
				{
					result.push_back(temp[0]); result.push_back(temp[1]); temp.clear();
				}

				else { result.push_back(temp[1]); result.push_back(temp[0]); temp.clear(); }

			}

		}
		this->price = result[0]; //необязательно; инициализация наименьшей цены
	}
	void calcCalories(vector<vector<int>> calories)  { //PRIM

		map <short, unsigned int> key_value;

		for (size_t i = 0; i < calories.size(); i++)
		{
			min = INFINITY; //3435973836
			path = NULL;

			for (size_t j = 0; j < calories.size(); j++)
			{
				if (calories[i][j] < min && calories[i][j] > 0) {
					if (key_value[i] != calories[i][j]) { min = calories[i][j]; path = j; }
				}
			}
			this->calories += min;
			this->ccal_menu += to_string(path) + ' ';
			key_value.insert(make_pair(path, min));
		}

	}
	void calcDistance(vector<vector<int>> distance) { //DEJKSTRA

		for (size_t i = 0; i < distance.size(); i++)
		{
			min = INFINITY; //3435973836
			path = NULL;
			for (size_t j = 0; j < distance.size(); j++)
			{
				if (distance[i][j] < min && distance[i][j] > 0) { min = distance[i][j]; path = j; }
			}
			this->distance += min;
			this->way += to_string(path) + " ";
		}

	}
	int calcCount(int count) { //FIB

		if (count < 1) return 0;

		if (count == 1) return 1;

		return this->count = calcCount(count - 1) + calcCount(count - 2);

	}

	void segment_sort(vector<pair<int, int>> segment) {
		sort(begin(segment), end(segment),
			[](const auto& a, const auto& b)
			{
				return tie(a.second, a.first) < tie(b.second, b.first);
			});

		for (const auto& p : segment)
		{
			cout << "<" << p.first << ", " << p.second << "> ";
		}
		cout << endl;

	}
	void push_back_stack(int N) {

		vector<int> vec;
		vec.push_back(N);
		push_back_stack(N - 1);

	}

	void getInfo() {
		cout << "Калории: " << this->calories << ", Номер меню: " << ccal_menu
			<< "; Лучшая цена: " << this->price << "Р;\n\n"
			<< "Ближайший магазин: " << this->distance << " м." << ", Путь: " << way
			<< "; Покупателей/час: " << this->count << " чел." << endl;
	}

private:
	//локальные пер-ые для подсчетов
	unsigned int min;
	unsigned short path;

	unsigned int price; //цена продукта  (Определяется самый дешевый продукт, через merge сортировку)
	unsigned int calories; //самый низкокалорийный набор продуктов //ПРИМА
	unsigned int distance; //кратчайшее расстояние до магазина //ДЕЙКСТРА
	unsigned int count; //прогноз количества покупателей в час //ФИБ

	string way; //карта пути до магазина
	string ccal_menu; //комбинация меню с минимальным значением калорийности
};


int main() {

	setlocale(LC_ALL, "RUS");

	ShopCart Chicken;
	vector<int> price_firstShop = { 170,197,220 };
	vector<int> price_secondShop = { 165,210,225 };
	Chicken.calcPrice(price_firstShop, price_secondShop);

	Chicken.calcCount(10);

	vector<vector<int>> ways = {
		//A   B   C   D   E
		{ 0, -1, 15, 20, 15 }, //A
		{ -1, 0, 60, 50, 80 }, //B
		{ 15, 60, 0, 50, 10 }, //C
		{ 20, 50, 50, 0, 30 }, //D
		{ 15, 80, 10, 30, 0 }  //E
	}; //вектор векторов всех возможных путей до магазина
	Chicken.calcDistance(ways);

	vector<vector<int>> calories = {
		//A   B    C    D    E
		{ 0,  -1, 150, 210, 170 }, //A
		{ -1,  0, 160, 250, 280 }, //B
		{ 150, 160, 0, 225, 110 }, //C
		{ 210, 250, 225, 0, 230 }, //D
		{ 170, 280, 110, 230, 0 }  //E
	};
	vector<vector<int>> test = {
		//Д   В    А   Б   Г   Е   К
		{ 0,  20, -1, 14, -1, 19, 18 }, //Д
		{ 20,  0, 13, -1, 16, -1, 15 }, //В
		{ -1, 13,  0, 18, 15, -1, -1 }, //А
		{ 14, -1, 18,  0, 17,  12, -1}, //Б
		{ -1, 16, 15, 17, 0 ,  -1, -1}, //Г
		{ 19, -1, -1, 12, -1,  0 , -1}, //Е
		{ 18, 15, -1, -1, -1,  -1, 0 }  //К
	};
	Chicken.calcCalories(calories);

	vector<pair<int, int>> segment = {
		{ 1, 3 }, { 4, 2 }, { 6, 5 }, { 0, 2 }, { 4, 5 }
	};
	Chicken.segment_sort(segment);

	Chicken.getInfo();

	return 0;
}
