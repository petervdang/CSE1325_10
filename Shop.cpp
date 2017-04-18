#include "Shop.h"

/*******************************************************
CREATE NEW ROBOT PART
*******************************************************/

void Shop :: create_new_robot_part(vector<Robot_part>& rob)
{
        string name;
        int model_number;
        string type;
        double cost;
        string description;
        string buffer;
        double power;
        double max_power;
        double power_available;
        double max_energy;
        int battery_compartments;
        int max_arms;


        name = fl_input("Name?");
        buffer = fl_input("Model Number?");
        model_number = atoi(buffer.c_str());
        type = fl_input("Type?");
        buffer = fl_input("Cost?");
        cost = atof(buffer.c_str());
        description = fl_input("Description");

        if (type == "head" || type == "Head")
        {
		buffer = fl_input("Power?");
                power = atof(buffer.c_str());

                while (power < 0)
                {
			buffer = fl_input("Power?");
                       power = atof(buffer.c_str());
                }

		Head head(name,model_number,cost,description,power);
                heads.push_back(head);
        }

        if (type == "Locomotor" || type == "locomotor")
        {
                buffer = fl_input("Max Power?");
                max_power = atof(buffer.c_str());

                while (max_power < 0)
                {
			buffer = fl_input("Max Power?");
                        max_power = atof(buffer.c_str());
                }

                        Locomotor locomotor(name,model_number,cost,description,max_power);
                        locomotors.push_back(locomotor);

        }

        if (type == "Torso" || type == "torso")
        {
		buffer = fl_input("Battery Compartments?");
                battery_compartments = atoi(buffer.c_str());

                while (battery_compartments < 1 || battery_compartments > 3)
                {
			fl_message("Not Valid Answer");
			buffer = fl_input("Battery Compartments?");
                        battery_compartments = atoi(buffer.c_str());
                }

		buffer = fl_input("Maximum Arms?");
                max_arms = atoi(buffer.c_str());

                while (max_arms < 0 || max_arms > 2)
                {
                        fl_message("Not Valid Answer");
                        buffer = fl_input("Maximum Arms?");
                        max_arms = atoi(buffer.c_str());
                }

		Torso torso(name,model_number,cost,description,max_arms,battery_compartments);
		torsos.push_back(torso);
        }

        if (type == "Battery" || type == "battery")
        {
		buffer = fl_input("Power Available");  
                power_available = atof(buffer.c_str());

                while (power_available < 0)
                {
			fl_message("Not Valid Answer");
			buffer = fl_input("Power Available?");
                        power_available = atof(buffer.c_str());
                }

		buffer = fl_input("Max Power");
                max_power = atof(buffer.c_str());

                while (max_power < 0)
                {
                        fl_message("Not Valid Answer");
                        buffer = fl_input("Maximum Power?");
                        max_power = atof(buffer.c_str());

                }

		Battery battery(name,model_number,cost,description,max_energy,power_available);
		batterys.push_back(battery);

        }

        if (type == "Arm" || type == "arm")
        {
		buffer = fl_input("Maximum Power");
                max_power = atof(buffer.c_str());

                while (max_power < 0)
                {
                        fl_message("Not Valid Answer");
                        buffer = fl_input("Maximum Power?");
                        max_power = atof(buffer.c_str());
                }
        	Arm arm(name,model_number,cost,description, max_power);
	        arms.push_back(arm);

        }
}





void Shop :: list_Robot_Parts()
{
	string message = "1) Head\n2) Locomotor\n3) Torso\n4) Arm\n5) Battery\n";
	string buffer = fl_input(message.c_str());
	int input = atoi(buffer.c_str());

        int j = 1;

                if (input == 1)
                {
			for (int i = 0; i < heads.size(); i++)
			{
                                cout << j << ")" << endl;
                                cout << "HEAD:         " << endl;
                                cout << "Name:         " << heads[i].name() << endl;
                                cout << "Model Number: " << heads[i].model_number() << endl;
                                cout << "Cost:         " << heads[i].cost() << endl;
                                cout << "Description:  " << heads[i].description() << endl;
                                cout << "Power:        " << heads[i].power() << endl << endl;

                                j++;
			}
                }

                if (input == 2)
                {
                       	for (int i = 0; i < locomotors.size(); i++)
			{
		        	cout << j << ")" << endl;
                		cout << "LOCOMOTOR:    " << endl;
                		cout << "Name:         " << locomotors[i].name() << endl;
                		cout << "Model Number: " << locomotors[i].model_number() << endl;
                		cout << "Cost:         " << locomotors[i].cost() << endl;
                		cout << "Description:  " << locomotors[i].description() << endl;
                		cout << "Max Power:    " << locomotors[i].max_power() << endl;


                        	j++;
			}
                }

                if (input == 3)
                {
                        for (int i = 0; i < torsos.size(); i++)
                        {
                		cout << j << ")" << endl;
                		cout << "TORSO:                 " << endl;
                		cout << "Name:                  " << torsos[i].name() << endl;
                		cout << "Model Number:          " << torsos[i].model_number() << endl;
                		cout << "Cost:                  " << torsos[i].cost() << endl;
                		cout << "Description:           " << torsos[i].description() << endl;
        	       	 	cout << "Max Arms:              " << torsos[i].max_arms() << endl;
	               		cout << "Battery_compartments:  " << torsos[i].battery_compartments() << endl << endl;
	
                                j++;
                        }
                }

                if (input == 4)
                {
                        for (int i = 0; i < arms.size(); i++)
                        {
                                cout << "ARM:          " << endl;
                                cout << "Name:         " << arms[i].name() << endl;
                                cout << "Model Number: " << arms[i].model_number() << endl;
                                cout << "Cost:         " << arms[i].cost() << endl;
                                cout << "Description:  " << arms[i].description() << endl;
                                cout << "Max Power:    " << arms[i].maxpower() << endl << endl;

                                j++;
                        }
                }

                if (input == 5)
                {
                        for (int i = 0; i < batterys.size(); i++)
                        {
                                cout << "BATTERY:          " << endl;
                                cout << "Name:             " << batterys[i].name() << endl;
                                cout << "Model Number:     " << batterys[i].model_number() << endl;
                                cout << "Cost:             " << batterys[i].cost() << endl;
                                cout << "Description:      " << batterys[i].description() << endl;
                                cout << "Power Available:  " << batterys[i].power_available() << endl;
                                cout << "Max Energy:       " << batterys[i].max_energy() << endl;

                                j++;
                        }
                }
        


}
/*******************************************************************
CREATE NEW ROBOT MODEL
*******************************************************************/


void Shop :: create_new_robot_model()
{
	string buffer;
	string message = "";
        int j = 1;
        int k = 1;

	if (heads.size() == 0 || locomotors.size() == 0 || torsos.size() == 0 || arms.size() == 0 || batterys.size() == 0)
	{
                fl_message("Not Enough Components");
                return;
	}

	string name = fl_input("What is the Model Name?");
	buffer = fl_input("What is the Model Number?");
        int model_number = atoi(buffer.c_str());


	for (int i = 0; i < torsos.size(); i++)
	{
/*
                cout << j << ")" << endl;
                cout << "TORSO:                 " << endl;
                cout << "Name:                  " << torsos[i].name() << endl;
                cout << "Model Number:          " << torsos[i].model_number() << endl;
                cout << "Cost:                  " << torsos[i].cost() << endl;
                cout << "Description:           " << torsos[i].description() << endl;
                cout << "Max Arms:              " << torsos[i].max_arms() << endl;
                cout << "Battery_compartments:  " << torsos[i].battery_compartments() << endl << endl;
*/
		message += j;
		message += ")\n";
		message += "TORSO:\n";
		message += "Name:                  ";
		message += torsos[i].name();
		message += "\n";
		message += "Model Number:          ";
		message += torsos[i].model_number();
		message += "\n";
		message += "Cost:                  ";
		message += torsos[i].cost();
		message += "\n";
		message += "Description:           ";
		message += torsos[i].description();
		message += "\n";
		message += "Max Arms:              ";
		message += torsos[i].max_arms();
		message += "\n";
		message += "Battery Compartments:  ";
		message += torsos[i].battery_compartments();
		message += "\n\n";
		
		j++;
	}

	message += "Select a Torso";
	buffer = fl_input(message.c_str());
	int torso = atoi(buffer.c_str());	//torso Number
	
	torso--;	//increment down for the vector order


	
	j = 1;
	message = "";
	
	for (int i = 0; i < heads.size(); i++)
	{
/*		cout << j << ")" << endl;
		cout << "HEAD:         " << endl;
		cout << "Name:         " << heads[i].name() << endl;
		cout << "Model Number: " << heads[i].model_number() << endl;
		cout << "Cost:         " << heads[i].cost() << endl;
		cout << "Description:  " << heads[i].description() << endl;
		cout << "Power:        " << heads[i].power() << endl;
*/

                message += j;
                message += ")\n";
                message += "HEAD:\n";
                message += "Name:                  ";
                message += heads[i].name();
                message += "\n";
                message += "Model Number:          ";
                message += heads[i].model_number();
                message += "\n";
                message += "Cost:                  ";
                message += heads[i].cost();
                message += "\n";
                message += "Description:           ";
                message += heads[i].description();
                message += "\n";
		message += "Power:                 ";
		message += heads[i].power();
		message += "\n\n";

		j++;
	}

	message += "Select a Head";
	buffer = fl_input(message.c_str());
        int head = atoi(buffer.c_str());              // head Number
	head--;



        j = 1;
	message = "";

        for (int i = 0; i < locomotors.size(); i++)
        {
/*
                cout << j << ")" << endl;
                cout << "LOCOMOTOR:    " << endl;
                cout << "Name:         " << locomotors[i].name() << endl;
                cout << "Model Number: " << locomotors[i].model_number() << endl;
                cout << "Cost:         " << locomotors[i].cost() << endl;
                cout << "Description:  " << locomotors[i].description() << endl;
                cout << "Max Power:    " << locomotors[i].max_power() << endl;
*/
                message += j;
                message += ")\n";
                message += "LOCOMOTOR:\n";
                message += "Name:                  ";
                message += locomotors[i].name();
                message += "\n";
                message += "Model Number:          ";
                message += locomotors[i].model_number();
                message += "\n";
                message += "Cost:                  ";
                message += locomotors[i].cost();
                message += "\n";
                message += "Description:           ";
                message += locomotors[i].description();
                message += "\n";
		message += "Max Power:             ";
		message += locomotors[i].max_power();
		message += "\n\n";


                j++;
        }

	message += "Select a Locomotor";
	buffer = fl_input(message.c_str());
        int locomotor = atoi(buffer.c_str());              // locomotor Number
        locomotor--;


        j = 1;
	message = "";

        for (int i = 0; i < arms.size(); i++)
        {
/*
                cout << j << ")" << endl;
                cout << "ARM:         " << endl;
                cout << "Name:         " << arms[i].name() << endl;
                cout << "Model Number: " << arms[i].model_number() << endl;
                cout << "Cost:         " << arms[i].cost() << endl;
                cout << "Description:  " << arms[i].description() << endl;
                cout << "Max Power:    " << arms[i].maxpower() << endl;
*/
                message += j;
                message += ")\n";
                message += "ARM:\n";
                message += "Name:                  ";
                message += arms[i].name();
                message += "\n";
                message += "Model Number:          ";
                message += arms[i].model_number();
                message += "\n";
                message += "Cost:                  ";
                message += arms[i].cost();
                message += "\n";
                message += "Description:           ";
                message += arms[i].description();
                message += "\n";
		message += "Max Power:             ";
		message += arms[i].maxpower();
		message += "\n\n";


                j++;
        }

	message += "Select an Arm";
	buffer = fl_input(message.c_str());
        int arm = atoi(buffer.c_str());              // head Number
        arm--;


        j = 1;
	message = "";

        for (int i = 0; i < batterys.size(); i++)
        {
/*
                cout << j << ")" << endl;
                cout << "BATTERY:           " << endl;
                cout << "Name:              " << batterys[i].name() << endl;
                cout << "Model Number:      " << batterys[i].model_number() << endl;
                cout << "Cost:              " << batterys[i].cost() << endl;
                cout << "Description:       " << batterys[i].description() << endl;
		cout << "Max Energy:        " << batterys[i].max_energy() << endl;
                cout << "Power Available:   " << batterys[i].power_available() << endl;
*/
                message += j;
                message += ")\n";
                message += "BATTERY:\n";
                message += "Name:                  ";
                message += batterys[i].name();
                message += "\n";
                message += "Model Number:          ";
                message += batterys[i].model_number();
                message += "\n";
                message += "Cost:                  ";
                message += batterys[i].cost();
                message += "\n";
                message += "Description:           ";
                message += batterys[i].description();
                message += "\n";
		message += "Max Energy:            ";
		message += batterys[i].max_energy();
		message += "\n";
		message += "Power Available:       ";
		message += batterys[i].power_available();
		message += "\n\n";


                j++;
        }

	message += "Select a Battery";
	buffer = fl_input(message.c_str());
        int battery = atoi(buffer.c_str());              // battery Number
        battery--;


	Torso t = torsos[torso];
	Head h = heads[head];
	Locomotor l = locomotors[locomotor];
	Arm a = arms[arm];
	Battery b = batterys[battery];

	Robot_model robot_models(name,model_number,t,h,l,a,b);
	
}


void Shop :: list_Robot_Models()
{
	int j = 1;
	string message = "";

	for (int i = 0; i < robot_models.size(); i++)
	{
/*
                cout << j << ")" << endl;
		cout << "Robot Name:           " << robot_models[i].name() << endl;
		cout << "Robot Model Number:   " << robot_models[i].model_number() << endl << endl;
*/

		message += j;
		message += ")\n";
		message += "Robot Name:          ";
		message += robot_models[i].name();
		message += "\n";
		message += "Robot Model Number:  ";
		message += robot_models[i].model_number();
		message += "\n\n";
		j++;
	}
}


/*******************************************************************************
	CREATE BELOVED CUSTOMER
*******************************************************************************/

void Shop :: create_new_customer()
{
	string name;
	int customer_number;
	string phone_number;
	string email_address;
	string buffer;

	name = fl_input("What is the Customer's name?");
	buffer = fl_input("What is the Customer Number?");
	customer_number = atoi(buffer.c_str());
	phone_number = fl_input("What is the Phone Number?");
	email_address = fl_input("What is the Email Address?");

	Customer customer(name,customer_number,phone_number,email_address);
	customers.push_back(customer);
}

void Shop :: list_Customers()
{
	string message = "";
	int j = 1;
	for (int i = 0; i < customers.size(); i++)
	{
/*
		cout << j << ")" << endl;
		cout << "Customers Name:     " << customers[i].name() << endl;
		cout << "Customers Number:   " << customers[i].customer_number() << endl;
		cout << "Customers Phone:    " << customers[i].phone_number() << endl;
		cout << "Customers Email:    " << customers[i].email_address() << endl << endl;
*/
		message += j;
		message += ")\n";
		message += "Customers Name:    ";
		message += customers[i].name();
		message += "\n";
		message += "Customers Number:  ";
		message += customers[i].customer_number();
		message += "\n";
		message += "Customers Phone:   ";
		message += customers[i].phone_number();
		message += "\n";
		message += "Customers Email:   ";
		message += customers[i].email_address();
		message += "\n\n";
		j++;
	}

	fl_message(message.c_str());
}

/*************************************************************
CREATE SALES ASSOCIATE
*************************************************************/

void Shop :: create_new_sales_associate()
{
	string name;
	int employee_number;
	string buffer;
/*
	cout << "What is the Sales Associate's Name:   ";
	getline(cin,name);
	cout << "What is the Associate's Employee Number:   ";
	cin >> employee_number;
	cin.ignore();
*/
	name = fl_input("What is the Sales Associate's Name?");
	buffer = fl_input("What is the Associate's Employee Number?");
	employee_number = atoi(buffer.c_str());

	Sales_associate sales_associate(name,employee_number);
	sales_associates.push_back(sales_associate);
}


void Shop :: list_Sales_Associates()
{
	string message = "";
	int j = 1;
	for (int i = 0; i < sales_associates.size(); i++)
	{
/*
		cout << j << ")" << endl;
		cout << "Associates Name:              " << sales_associates[i].name() << endl;
		cout << "Associates Employee Number:   " << sales_associates[i].employee_number() << endl << endl;
*/
		message += j;
		message += ")\n";
		message += "Associates Name:              ";
		message += sales_associates[i].name();
		message += "\n";
		message += "Associates Employee Number:  ";
		message += sales_associates[i].employee_number();
		message += "\n\n";
		j++;
	}

	fl_message(message.c_str());
}







