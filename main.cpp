#include "Shop.cpp"


using namespace std;
vector<Robot_part> rob;
Shop shop;
Fl_Window *win;
Fl_Menu_Bar *menubar;

class View : public Fl_Box
{
        public: View(int x, int y, int w, int h) : Fl_Box(x,y,w,h) {}
};

View *view;

void CloseCB(Fl_Widget *w, void *p)
{
        win -> hide();
}


void ComponentCB(Fl_Widget *w, void *p)
{
        shop.create_new_robot_part(rob);
}

void ModelCB(Fl_Widget *w, void *p)
{
        shop.create_new_robot_model();
}

void ListrmCB(Fl_Widget *w, void *p)
{
        shop.list_Robot_Models();
}

void CustomerCB(Fl_Widget *w, void *p)
{
	shop.create_new_customer();
}

void SalesCB(Fl_Widget *w, void *p)
{
	shop.create_new_sales_associate();
}

void ListcCB(Fl_Widget *w, void *p)
{
	shop.list_Customers();
}

void ListsCB(Fl_Widget *w, void *p)
{
	shop.list_Sales_Associates();
}



Fl_Menu_Item menuitems[] = {

        {"&File", 0, 0,0, FL_SUBMENU},
                { "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB},
                { 0 },

        {"&Create", 0,0,0, FL_SUBMENU},
                { "&Robot Model", FL_ALT + 'm', (Fl_Callback *) ModelCB},
                { "&Robot Component", FL_ALT + 'c', (Fl_Callback *) ComponentCB},
		{ "&Beloved Customer", FL_ALT + 'b', (Fl_Callback *) CustomerCB},
		{ "&Sales Associate", FL_ALT + 'a', (Fl_Callback *) SalesCB},
                { 0 },
	{"&List", 0,0,0, FL_SUBMENU},
		{ "&Robot Models", FL_ALT + 'l', (Fl_Callback *) ListrmCB},
		{ "&Customers", FL_ALT + 'z', (Fl_Callback *) ListcCB},
		{ "&Sales Associate", FL_ALT + 'x', (Fl_Callback *) ListsCB},
		{ 0 },
        { 0 }
};



int main()
{
        const int x = 640;
        const int y = 480;

        win = new Fl_Window{x,y, "Pete's Robot Shop"};

        menubar = new Fl_Menu_Bar(0,0,x,30);
        menubar -> menu(menuitems);
        view = new View{0,0,x,y};

        win -> callback(CloseCB, view);
        win -> resizable(*view);
        win -> end();
        win -> show();

        return(Fl::run());





 /*     int input;

        cout << "What Do You Want To Do:" << endl;
        cout << "0) Exit" << endl;
        cout << "1) Create Robot Part" << endl;
        cout << "2) List Robot Parts" << endl;
        cout << "3) Create Robot Model" << endl;
	cout << "4) List Robot Models" << endl;
	cout << "5) Create Beloved Customer" << endl;
	cout << "6) List Customers" << endl;
        cout << "7) Create Sales Associate" << endl;
        cout << "8) List Sales Associates" << endl;

        cin >> input;
        cin.ignore();
        cout << endl;

        while (input != 0)
        {
                if (input == 1)
                {
                        shop.create_new_robot_part(rob);
                        cout << endl;
                }

                if (input == 2)
                {


                        cout << "1) Head\n2) Locomotor\n3) Torso\n4) Arm\n5) Battery" << endl;
                        cin >> input;
                        cin.ignore();
                        if (input < 1 || input > 5) break;
                        cout << endl;

                        shop.list_Robot_Parts(input);
                        cout << endl;

		}


		if (input == 3)
                {
                        cout << endl;
                        shop.create_new_robot_model();
                        cout << endl;
                }

		if (input == 4)
		{
			cout << endl;
			shop.list_Robot_Models();
			cout << endl;
		}

		if (input == 5)
		{
			cout << endl;
			shop.create_new_customer();
			cout << endl;
		}

		if (input == 6)
		{
			cout << endl;
			shop.list_Customers();
			cout << endl;
		}

		if (input == 7)
		{
			cout << endl;
			shop.create_new_sales_associate();
			cout << endl;
		}

		if (input == 8)
		{
			cout << endl;
			shop.list_Sales_Associates();
			cout << endl;
		}

                cout << "What Do You Want To Do:" << endl;
                cout << "0) Exit" << endl;
                cout << "1) Create Robot Part" << endl;
                cout << "2) List Robot Parts" << endl;
                cout << "3) Create Robot Model" << endl;
		cout << "4) List Robot Models" << endl;
		cout << "5) Create Beloved Customer" << endl;
		cout << "6) List Customers" << endl;
		cout << "7) Create Sales Associate" << endl;
		cout << "8) List Sales Associates" << endl;
                cin >> input;
                cin.ignore();
                cout << endl;

        }

        return 0;

*/
}

