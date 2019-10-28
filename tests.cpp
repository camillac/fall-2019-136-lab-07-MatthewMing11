


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "funcs.h"

TEST_CASE("Testing bad-code.cpp"){
   CHECK(indent("bad-code.cpp")=="int main(){\n\t// Hi, I'm a program!\n\tint x = 1;\n\tfor(int i = 0; i < 10; i++) {\n\t\tcout << i;\n\t\tcout << endl;\n\t}\n}\n");
}

TEST_CASE("Testing main.cpp"){
   CHECK(indent("main.cpp")=="#include <iostream>\n#define DOCTEST_CONFIG_IMPLEMENT\n#include \"doctest.h\"\n#include \"funcs.h\"\n\nint main(int argc, char *argv[])\n{\n\t// your code here\n\treturn 0;\n}\n");
}
