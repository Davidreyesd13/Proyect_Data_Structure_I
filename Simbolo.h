#pragma once
#include "Object.h"
#include <string>
using namespace std;
class Simbolo : public Object
{
protected:
	char simbolo;
public:
	Simbolo();
	~Simbolo();
	Simbolo(char simbolo);
	bool equals(const Object* otro) const override;
	string toString() const override;
};

