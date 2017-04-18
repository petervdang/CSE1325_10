#include <iostream>
#include <string>
#include <vector>

class Customer
{
	private:
		string _name;
		int _customer_number;
		string _phone_number;
		string _email_address;

	public:
		Customer(string name, int customer_number, string phone_number, string email_address)
			: _name{name}, _customer_number{customer_number}, _phone_number{phone_number}, _email_address{email_address} {}

		string name() {return _name;}
		int customer_number() {return _customer_number;}
		string phone_number() {return _phone_number;}
		string email_address() {return _email_address;}
};
