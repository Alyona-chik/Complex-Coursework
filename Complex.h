#pragma once
#include<iostream>
#include<string>
#include<map>
#include<list>
#include<string>
#include<fstream>
#include<vector>
#include"Hotel.h"
using namespace std;
class Complex {
private:
	string nameComplex;
	vector <Hotel> hotels;

	friend ostream& operator<<(ostream& stream, const Complex& c) {
		if (&stream == &cout) {
			stream << "Complex: ";
		}
		stream << c.nameComplex << endl;
		stream << "**************" << endl;
		if (&stream == &cout) {
			stream << "Hotels: " << endl;
		}
		stream << "---------------------" << endl;
		for (auto ppl : c.hotels) {
			stream << ppl << endl;
			stream << "---------------------" << endl;
		}
		return stream;
	}
	friend istream& operator>>(istream& stream, Complex& c) {
		stream >> c.nameComplex;
		Hotel temp;
		stream >> temp;
		c.hotels.push_back(temp);
		return stream;
	}
public:
	Complex(string name, vector<Hotel> vet) {
		this->nameComplex = name;
		this->hotels = vet;
	}
	Complex(const string& fileName) {
		ifstream text(fileName, ios::app);
		text >> nameComplex;
		text.ignore();
		while (!text.eof()) {
			Hotel hot;
			text >> hot;
			hotels.push_back(hot);
		}
	}
	string coefBuzy() {
		int coefMax = 0;
		string category = "";
		string name = "";
		for (auto h : hotels) {
			if (coefMax >= h.coefficientBusy()) {
				coefMax = h.coefficientBusy();
				category = h.getCategory();
				name = h.getName();
			}
		}
		return name + " " + category;
	}
	int coefBuzyAllComplex() {
		int day = 0;
		int countBed = 0;
		for (auto h : hotels) {
			day += h.dayAll();
			countBed += h.getCountBed();
		}
		return day / countBed;
	}
	int countTurist(int year) {
		int count = 0;
		for (auto h : hotels) {
			list<Turist> turists = h.listTuristUpYear(year);
			count += turists.size();
		}
		return count;
	}
	Hotel averageSmaller() {
		Hotel hotelss;
		int average = 0;
		for (auto h : hotels) {
			if (average <= h.listTuristAverage()) {
				hotelss = h;
			}
		}
		return hotelss;
	}
	Turist youngerTurist() {
		list<Turist> listTur;
		Turist st;
		Turist kk;
		for (auto h : hotels) {
			map<Turist, unsigned> map = h.getMap();
			st = map.begin()->first;
			int age = st.getAge();
			for (auto it : map) {
				Turist t = it.first;
				if (t.getAge() <= age) {
					age = t.getAge();
					kk = t;
				}
			}
			listTur.push_back(kk);
		}
		int age = listTur.front().getAge();
		for (auto var : listTur) {
			if (var.getAge() <= age) {
				age = var.getAge();
				kk = var;
			}

		}
		return kk;
	}
};