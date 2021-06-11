#pragma once
#include<iostream>
using namespace std;

class Turist {
private:
	string name;
	int age;
	friend ostream& operator<<(ostream& stream, const Turist& c) {
		if (&stream == &cout) {
			stream << "     Name: ";
		}
		stream << c.name << endl;
		if (&stream == &cout) {
			stream << "     Age: ";
		}
		stream << c.age << endl;
		return stream;
	}
	friend istream& operator>>(istream& stream, Turist& c) {
		stream >> c.name;
		stream >> c.age;
		return stream;
	}
public:
	Turist() {
		name = "";
		age = 0;
	}
	Turist(string name, int age) {
		this->name = name;
		this->age = age;
	}
	int getAge() {
		return age;
	}
	string getName() {
		return name;
	}

	bool operator<(const Turist& p) const {
		return this->name < p.name;
	}
};