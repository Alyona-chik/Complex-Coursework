#pragma once
#include<iostream>
#include<string>
#include<map>
#include<list>
#include"Turist.h"
using namespace std;
class Hotel {
private:
	string name_hotel;
	string category;
	int countBed;
	map<Turist, unsigned> turistStay;

	friend ostream& operator<<(ostream& stream, const Hotel& c) {
		if (&stream == &cout) {
			stream << "Name hotel: ";
		}
		stream << c.name_hotel << endl;

		if (&stream == &cout) {
			stream << "Category: ";
		}
		stream << c.category << endl;

		if (&stream == &cout) {
			stream << "Count bed: ";
		}
		stream << c.countBed << endl;

		if (&stream == &cout) {
			stream << "Turists: " << endl;
		}
		for (auto itr : c.turistStay) {
			int d = c.turistStay.size();
			stream << itr.first;
			stream << "     Count day: " << itr.second;
			stream << endl;

		}
		return stream;
	}
	friend istream& operator>>(istream& stream, Hotel& c) {
		stream >> c.name_hotel;
		stream >> c.category;
		stream >> c.countBed;
		unsigned countDay;
		int count = 0;
		Turist tur;
		stream >> count;
		for (int i = 0; i < count; i++) {
			stream >> tur;
			stream >> countDay;
			c.turistStay.insert(pair<Turist, unsigned>(tur, countDay));
		}
		return stream;
	}


public:

	Hotel() {
		name_hotel = "";
		category = "";
		countBed = 0;
	}
	Hotel(string name_hotel, string category, int countBed, map<Turist, unsigned> turistStay) {
		this->name_hotel = name_hotel;
		this->category = category;
		this->countBed = countBed;
		this->turistStay = turistStay;
	}
	int dayAll() {
		int sumDay = 0;
		for (auto it : turistStay) {
			sumDay += it.second;
		}
		return sumDay;
	}
	Turist maxDayInHotel() {
		int max = 0;
		string name = "";
		int age = 0;
		Turist st;
		for (auto it : turistStay) {
			if (it.second >= 0) {
				max = it.second;
				st = it.first;
			}
		}
		return st;
	}
	int coefficientBusy() {
		return dayAll() / countBed;
	}
	////////
	list<Turist> listTuristUpYear(int age) {
		list<Turist> listTurist;
		for (auto it : turistStay) {
			Turist t = it.first;
			if (t.getAge() > age) {
				listTurist.push_back(t);
			}
		}
		return listTurist;
	}
	//////////////////
	list<Turist> listTuristDownear(int age) {
		list<Turist> listTurist;
		for (auto it : turistStay) {
			Turist t = it.first;
			if (t.getAge() < age) {
				listTurist.push_back(t);
			}
		}
		return listTurist;
	}
	int listTuristAverage() {
		int average = 0;
		int c = 0;
		for (auto it : turistStay) {
			Turist t = it.first;
			average += t.getAge();
			c++;
		}
		return average / c;
	}

	map<Turist, unsigned> getMap() {
		return turistStay;
	}
	string getCategory() {
		return category;
	}
	string getName() {
		return name_hotel;
	}
	int getCountBed() {
		return countBed;
	}
	bool operator<(const Hotel& p) {
		return this->countBed < p.countBed;
	}

};
