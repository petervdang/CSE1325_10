#include <iostream>
#include <string>
#include <vector>

class Sales_associate
{
	private:
		string _name;
		int _employee_number;

	public:
		Sales_associate(string name, int en) : _name{name}, _employee_number{en} {}
		string name() {return _name;}
		int employee_number() {return _employee_number;}
};
