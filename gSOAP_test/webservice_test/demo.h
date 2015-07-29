#pragma once
//gsoap demo service name: demo
//gsoap demox service style: rpc
//gsoap demo service namespace: http://localhost:12345/demo.wsdl
//gsoap demo service location: http://localhost:12345
//gsoap demo service executable: demo.cgi
//gsoap demox service encoding: encoded
//gsoap demo schema namespace: urn:demo

struct demo__Result
{
	float	a;
	float	b;
	float	res;
};

struct demo__AddBResponse
{
};

int demo__AddA(double a, double b, double& res);

int demo__AddB(double a, double b, struct demo__AddBResponse *out);

int demo__AddC(void* _, struct demo__Result *res);
