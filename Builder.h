#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Mechanic
{
	Mechanic(string _name, int _price) : name(_name), price(_price) {}
	string name;
	int price;
};

struct Electric
{
	Electric(string _name, int _price) : name(_name), price(_price) {}
	string name;
	int price;
};

struct Electronic
{
	Electronic(string _name, int _price) : name(_name), price(_price) {}
	string name;
	int price;
};

class WashinMachine
{
public:
	WashinMachine(Mechanic* _mech, Electric* _elec, Electronic* _electron):
		mech(_mech),
		elec(_elec),
		electron(_electron)
	{ }
	void show()const
	{
		cout << "\tWashingMachine" << endl << "Mechanic: " << mech->name << " " << mech->price << endl
			<< "Electric: " << elec->name << " " << elec->price << endl
			<< "Electronic: " << electron->name << " " << electron->price << endl;
	}
	int price()
	{
		return mech->price + elec->price + electron->price;
	}
private:
	Mechanic* mech;
	Electric* elec;
	Electronic* electron;
};

class DishWashinMachine
{
public:
	DishWashinMachine(Mechanic* _mech, Electric* _elec, Electronic* _electron) :
		mech(_mech),
		elec(_elec),
		electron(_electron)
	{
	}
	void show()const
	{
		cout << "\tDishWashingMachine" << endl << "Mechanic: " << mech->name << " " << mech->price << endl
			<< "Electric: " << elec->name << " " << elec->price << endl
			<< "Electronic: " << electron->name << " " << electron->price << endl;
	}
private:
	Mechanic* mech;
	Electric* elec;
	Electronic* electron;
};

class Microwave
{
public:
	Microwave(Mechanic* _mech, Electronic* _electron) :
		mech(_mech),
		electron(_electron)
	{
	}
	void show()const
	{
		cout << "\tMicrowave" << endl << "Mechanic: " << mech->name << " " << mech->price << endl
			<< "Electronic: " << electron->name << " " << electron->price << endl;
	}
private:
	Mechanic* mech;
	Electronic* electron;
};

class AllBuilder
{
public:
	AllBuilder(string _mech, string _elec, string _electron, int _priceMech, int _priceElect, int _priceElectron):
		mech(_mech), elec(_elec), electron(_electron),
		priceMech(_priceMech), priceElec(_priceElect), priceElectron(_priceElectron)
	{ }
	virtual Mechanic* buildMech(){ return new Mechanic(mech, priceMech); }
	virtual Electric* buildElec(){ return new Electric(elec, priceElec); }
	virtual Electronic* buildElectron() { return new Electronic(electron, priceElectron); }
private:
	string mech;
	string elec;
	string electron;
	int priceMech;
	int priceElec;
	int priceElectron;
};

//class MicrowaveBuilder : public AllBuilder
//{
//public:
//	MicrowaveBuilder(string a, string b, string c, int e, int f, int g):
//		AllBuilder(a,b,c,e,f,g)
//	{ }
//	Electric* buildElec(string, int) { return nullptr; }
//};

class Director
{
public:
	Director(AllBuilder* _builder):
		builder(_builder)
	{ }
	WashinMachine* getWashinMachine()
	{
		return (new WashinMachine(builder->buildMech(), builder->buildElec(), builder->buildElectron()));
	}
	DishWashinMachine* getDishWashinMachine()
	{
		return (new DishWashinMachine(builder->buildMech(), builder->buildElec(), builder->buildElectron()));
	}
	Microwave* getMicrowave()
	{
		return (new Microwave(builder->buildMech(), builder->buildElectron()));
	}
private:
	AllBuilder* builder;
};


