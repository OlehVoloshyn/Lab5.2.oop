
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Empty
{};
class Error
{
	string message;
public:
	Error(string message)
		: message(message)
	{}
	string What() { return message; }
};
class E : public exception
{
	string message;
public:
	E(string message)
		: message(message)
	{}
	string What() { return message; }
};
double TriangleP1(double x, double y, double z)
{
	if ( x == 0 || y == 0 || z==0 || (x > y + z)||(y > x + z)||(z > x + y))
		throw 1.0;

	return x+y+z;
}

double TriangleP2(double x, double y, double z)
{
	if (x == 0 || y == 0 || z == 0 || (x >= y + z) || (y >= x + z) || (z >= x + y))
		throw bad_exception();

	return x + y + z;
}
double TriangleP3(double x, double y, double z)
{
	if (x == 0 || y == 0 || z == 0 || (x >= y + z) || (y >= x + z) || (z >= x + y))
		throw '1';

	return x + y + z;
}
double TriangleP4(double x, double y, double z)
{
	if ((x == 0) || (y == 0) || (z == 0) || (x >= y + z) || (y >= x + z) || (z >= x + y))
		throw Empty();

	return x + y + z;
}
double TriangleP5(double x, double y, double z)
{
	
	if ( (x < 0)|| (y<0) || (z<0))
		throw Error("too small ");

	return x + y + z;
}
double TriangleP6(double x, double y, double z)
{
	
	if ((x < 0) || (y < 0) || (z < 0))
		throw E("too small ");

	return x + y + z;

}
void FU()
{
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void FT()
{
	cout << "unknown error! - terminate" << endl;
	abort();
}

int main()
{

	set_unexpected(FU);
	//set_terminate(FT);

	double x, y, z;
	cout << " x = "; cin >> x;
	cout << " y = "; cin >> y;
	cout << " z = "; cin >> z;
	try
	{
		 cout << TriangleP1(x, y, z) << endl;
		 cout << TriangleP2(x, y, z) << endl;
		 cout << TriangleP3(x, y, z) << endl;
		 cout << TriangleP4(x, y, z) << endl;
		 cout << TriangleP5(x, y, z) << endl;
		cout << TriangleP6(x, y, z) << endl;
	}
	catch (int)
	{
		cout << " catch (int) <= TriangleP1()" << endl;
	}
	catch (double)
	{
		cout << " catch (double) <= TriangleP2()" << endl;
	}
	catch (char)
	{
		cout << " catch (char) <= TriangleP3()" << endl;
	}
	catch (Empty)
	{
		cout << " catch (Empty) <= TriangleP4()" << endl;
	}
	catch (Error e)
	{
		cout << " catch (Error) <= TriangleP5() :" << endl;
		cout << e.What() << endl;
	}
	catch (bad_exception)
	{
		cout << " catch (bad_exception)" << endl;
	}
	//catch (exception)
	//{
	// cout << " catch (exception) <= IsVysokosny6() :" << endl;
	//}
	//catch (E e)
	//{
	// cout << " catch (E) <= IsVysokosny6() :" << endl;
	// cout << e.What() << endl;
	//}
	system("pause");
	return 0;

}