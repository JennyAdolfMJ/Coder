#include "Dict.h"
#include "Type.h"

int main()
{
   Dict dict("path/to/file");

   dict.open();

   while (dict.readLine())
   {
      while (dict.next())
      {
         dict.read<Type>();
      }
   }

	return 0;
}