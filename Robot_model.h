#include "Robot_part.h"

class Robot_model
{
	private:
		string _name;
		int _model_number;
		Torso _torso;
		Head _head;
		Locomotor _locomotor;
		Arm _arm;
		Battery _battery;

	public:
		Robot_model(string name,
		int model_number,
		Torso torso,
		Head head,
		Locomotor locomotor, 
		Arm arm, 
		Battery battery)
		 : _name{name}, _model_number{model_number}, 
			_torso{torso}, 
			_head{head}, 
			_locomotor{locomotor}, 
			_arm{arm}, 
			_battery{battery} {}


                double cost();
                double max_speed();
                double max_battery_life();
		string name() {return _name;}
		int model_number() {return _model_number;}
		
};
