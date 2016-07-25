#pragma once
#include "Dict.h"

class DictFactory
{
public:
	Dict& createDict(void);
	DictFactory(void);
	~DictFactory(void);
};

