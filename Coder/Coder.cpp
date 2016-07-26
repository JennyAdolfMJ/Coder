#include "Dict.h"
#include "CustomType.h"

int main()
{
   std::vector<Type> types;
   types.push_back(Type::intType);
   types.push_back(Type::customType);

   Dict dict("path/to/file", types);

   dict.open();

   while (dict.readLine())
   {
      for (unsigned i = 0; i < types.size(), dict.next(); i++)
      {
         switch (types[i])
         {
         case Type::intType:
            dict.read<int>(); break;
         case Type::floatType:
            dict.read<float>(); break;
         case Type::charType:
            // TODO
            dict.read<char *>(); break;
         case Type::arrayType:
            // TODO
            dict.read<void *>(); break;
         case Type::customType:
            dict.read<CustomType>(); break;
         }
      }
   }

	return 0;
}