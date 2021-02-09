#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Buliding{
	public:
	const int floors = 10;
	const int elevators = 2;
}

class Elevator : protected Buliding{
	private:		//private section
	Elevator(){}
	void warning(){
		cout <<"!! you can not create more than 2 elevator" <<endl;
	}

	public:			//public section
	int source;
	int destination;
	int current_floor;
	static Elevator e1 = NULL;
	static Elecator e2 = NULL;
	static Elecator objectCrator(){
		if(e1 == NULL){
			e1 = new Elevator();
		}else if(e2 == NULL){
			e2 = new Elevator();
		}else{
			warning();
		}
	}
}

class Passenger{
	int source;
	int destination;
}

int main(){

}
