#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include "Parser.h"
#include  "Memory.h"
#include "Typos.h"
#include "doctest/doctest.h"
#include "Processor.h"
#include "switch_string.h"


using namespace std;


void translator()
{
	
}

void error(const int &line, const string& msg)
{
	cout << "ERROR: Line" << line << ": " << msg << ";\n";
	exit(6);
}



/* ѕарсинг строки false - при неправильном заполнении*/


int main(int argc, char *argv[])	
{
	Processor p;
	syntax::init_registers();
	//for (int i = 1; i < argc; i++)
	//{
		//cout << "File name is: " << argv[i] << " to execute\n";
		//cout << endl << endl;



		//ifstream file(argv[i]);
		ifstream file("test.txt");
		if (file)
		{
			Upload(file,p);
		}
		else
			cout << "File not open;";
	//}
	
	system("pause");
	return 0;
}