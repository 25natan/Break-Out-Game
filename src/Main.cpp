#include <fstream>
#include <cstdlib>
#include "Controller.h"
using std::exception;
using std::ofstream;
using std::endl;


int main()
{
	ofstream errOutput("errOutput.txt");
	try
	{
		Controller controller;
		controller.run();
	}
	catch (exception excep)
	{
		errOutput << excep.what() << endl;
	}
	catch (...)
	{
		errOutput << "unkown error occured!" << endl;
	}
	return 0;
}