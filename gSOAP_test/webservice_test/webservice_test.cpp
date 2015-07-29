// webservice_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int nPort = 12345;
	struct soap demo_soap;
	soap_init(&demo_soap);

	int nMaster = (int)soap_bind(&demo_soap, NULL, nPort, 100);
	if (nMaster < 0) {
		soap_print_fault(&demo_soap, stderr);
		return -1;
	}

	fprintf(stderr, "server binded: %d\n", nMaster);

	while (true) {
		int nSlave = (int)soap_accept(&demo_soap);
		if (nSlave < 0)
		{
			soap_print_fault(&demo_soap, stderr);
			return -2;
		}
		fprintf(stderr, "Client connected: %d\n", nSlave);

		soap_serve(&demo_soap);
	}

	return 0;
}

