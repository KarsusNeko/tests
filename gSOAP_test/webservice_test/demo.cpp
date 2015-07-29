#include "stdafx.h"

using namespace std;

int demo__AddA(struct soap*, double a, double b, double& res)
{
	res = a + b;
	return SOAP_OK;
}

int demo__AddB(struct soap*, double a, double b, struct demo__AddBResponse *out)
{
	cout << "res = " << a + b << endl;
	return SOAP_OK;
}

int demo__AddC(struct soap*, void* _, struct demo__Result *res)
{
	fstream file("demo.txt");
	file >> res->a;
	file >> res->b;
	res->res = res->a + res->b;

	file.close();
	return SOAP_OK;
}
