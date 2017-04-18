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
                cout << "What is the Max Power?" << endl;
                getline(cin,buffer);
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





void Shop :: list_Robot_Parts(int input)
{
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
        int j = 1;
        int k = 1;

	if (heads.size() == 0 || locomotors.size() == 0 || torsos.size() == 0 || arms.size() == 0 || batterys.size() == 0)
	{
                cout << "Not enough Components" << endl << endl;
                return;
	}


        cout << "What is the Model Name:  ";
        string name;
        getline(cin,name);

        cout << "What is the Model Number:  ";
        int model_number;
        cin >> model_number;
        cin.ignore();

        cout << "Select a Torso" << endl;

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

	int torso;	//torso Number
	cout << "Input:   ";
	cin >> torso;
	cin.ignore();
	cout << endl;
	torso--;	//increment down for the vector order


	
	j = 1;
        cout << "Select a Head" << endl;

	for (int i = 0; i < heads.size(); i++)
	{
		cout << j << ")" << endl;
		cout << "HEAD:         " << endl;
		cout << "Name:         " << heads[i].name() << endl;
		cout << "Model Number: " << heads[i].model_number() << endl;
		cout << "Cost:         " << heads[i].cost() << endl;
		cout << "Description:  " << heads[i].description() << endl;
		cout << "Power:        " << heads[i].power() << endl;

		j++;
	}


        int head;              // head Number
        cout << "Input:  ";
        cin >> head;
        cin.ignore();
        cout << endl;
	head--;



        j = 1;
        cout << "Select a Locomotor" << endl;

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


        int locomotor;              // locomotor Number
        cout << "Input:  ";
        cin >> locomotor;
        cin.ignore();
        cout << endl;
        locomotor--;


        j = 1;
        cout << "Select an Arm" << endl;

        for (int i = 0; i < arms.size(); i++)
        {
                cout << j << ")" << endl;
                cout << "ARM:         " << endl;
                cout << "Name:         " << arms[i].name() << endl;
                cout << "Model Number: " << arms[i].model_number() << endl;
                cout << "Cost:         " << arms[i].cost() << endl;
                cout << "Description:  " << arms[i].description() << endl;
                cout << "Max Power:    " << arms[i].maxpower() << endl;

                j++;
        }


        int arm;              // head Number
        cout << "Input:  ";
        cin >> arm;
        cin.ignore();
        cout << endl;
        arm--;


        j = 1;
        cout << "Select a Head" << endl;

        for (int i = 0; i < heads.size(); i++)
        {
                cout << j << ")" << endl;
                cout << "BATTERY:           " << endl;
                cout << "Name:              " << batterys[i].name() << endl;
                cout << "Model Number:      " << batterys[i].model_number() << endl;
                cout << "Cost:              " << batterys[i].cost() << endl;
                cout << "Description:       " << batterys[i].description() << endl;
		cout << "Max Energy:        " << batterys[i].max_energy() << endl;
                cout << "Power Available:   " << batterys[i].power_available() << endl;

                j++;
        }


        int battery;              // battery Number
        cout << "Input:  ";
        cin >> battery;
        cin.ignore();
        cout << endl;
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

	for (int i = 0; i < robot_models.size(); i++)
	{
                cout << j << ")" << endl;
		cout << "Robot Name:           " << robot_models[i].name() << endl;
		cout << "Robot Model Number:   " << robot_models[i].model_number() << endl << endl;

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

	cout << "What is the Customer's name:  ";
	getline(cin,name);
	cout << "What is the Customer Number:  ";
	cin >> customer_number;
	cin.ignore();
	cout << "What is the Phone Number:  ";
	getline(cin,phone_number);
	cout << "What is the email_address:  ";
	getline(cin,phone_number);

	Customer customer(name,customer_number,phone_number,email_address);
	customers.push_back(customer);
}

void Shop :: list_Customers()
{
	int j = 1;
	for (int i = 0; i < customers.size(); i++)
	{
		cout << j << ")" << endl;
		cout << "Customers Name:     " << customers[i].name() << endl;
		cout << "Customers Number:   " << customers[i].customer_number() << endl;
		cout << "Customers Phone:    " << customers[i].phone_number() << endl;
		cout << "Customers Email:    " << customers[i].email_address() << endl << endl;

		j++;
	}
}

/*************************************************************
CREATE SALES ASSOCIATE
*************************************************************/

void Shop :: create_new_sales_associate()
{
	string name;
	int employee_number;

	cout << "What is the Sales Associate's Name:   ";
	getline(cin,name);
	cout << "What is the Associate's Employee Number:   ";
	cin >> employee_number;
	cin.ignore();

	Sales_associate sales_associate(name,employee_number);
	sales_associates.push_back(sales_associate);
}


void Shop :: list_Sales_Associates()
{
	int j = 1;
	for (int i = 0; i < sales_associates.size(); i++)
	{
		cout << j << ")" << endl;
		cout << "Associates Name:              " << sales_associates[i].name() << endl;
		cout << "Associates Employee Number:   " << sales_associates[i].employee_number() << endl << endl;

		j++;
	}
}







