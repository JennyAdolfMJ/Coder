#include "CustomType.h"

CustomType::CustomType(std::string str)
{
   m_str = str;
   parse();
}

CustomType::~CustomType()
{

}