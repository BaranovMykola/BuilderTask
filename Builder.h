#pragma once
#include <string>

using namespace std;

struct Mechanic
{
	Mechanic(string type) : mType(type) {}
	string mType;
};

struct Electric
{
	Electric(string type) : mType(type) {}
	string mType;
};

struct Electronic
{
	Electronic(string type) : mType(type) {}
	string mType;
};

class Builder
{
public:
	Builder();
	~Builder();
};

