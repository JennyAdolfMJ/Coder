#include "DictFactory.h"


DictFactory::DictFactory(void)
{
}


DictFactory::~DictFactory(void)
{
}

Dict& DictFactory::createDict(){
	 return  Dict();
}
