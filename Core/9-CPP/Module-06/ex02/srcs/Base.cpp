#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

Base::~Base() {}

Base* generate(void)
{
	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return;
	}
	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return;
	}
	C *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}