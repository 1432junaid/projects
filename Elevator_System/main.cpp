#include <iostream>
#include <string>
#include <vector>

using namespace std;
int _abs(int );

class Buliding{
	public:
	const int floors = 10;
	const int elevators = 2;
};

class Elevator : public Buliding{
//	private:		//private section
	Elevator(){}
	static void warning(){
		cout <<"!! you can not create more than 2 elevator" <<endl;
	}

	public:			//public section
//	int source;
	int destination;
	int current_floor = 0;
	static Elevator* objectCreator(){
		static Elevator *e1 = NULL;
		static Elevator *e2 = NULL;
		if(e1 == NULL){
			e1 = new Elevator();
			return e1;
		}else if(e2 == NULL){
			e2 = new Elevator();
			return e2;
		}else{
			Elevator::warning();
			return e1;
		}
	}
};


class Passenger{
	public:
	int destination;
	int current_floor;
	Passenger(int x){
		if(x>0 && x<9) this->current_floor = x;
		else cout << "this are only 9 floors !\n Please enter 0 - 9 \n";
	}
};

void display(Elevator *e1, Elevator *e2){
	int x = e1->current_floor;
	int y = e2->current_floor;

//	cout << x << " " << y <<endl;		// testing

	cout << endl<< endl;
	cout << "E1 | Floor | E2" << endl;
	int i = e1->floors-1;
	cout << endl;
	for(; i>=0; i--){
		if(i == x && i ==y ) cout << " *     " << i << "     *" << endl;
		else if(i == x) cout << " *    " << i << "     -" << endl;
		else if(i == y) cout << " -     " << i << "     *" << endl;
		else cout << " -     " << i << "     -" << endl;
	}
	cout << endl;
}

void min_algo(Elevator *e1, Elevator *e2, Passenger *p1);


int main(){
	Elevator *e1 = Elevator::objectCreator();
	Elevator *e2 = Elevator::objectCreator();
	cout << "== Rishab Apartment == \n";
	display(e1,e2);
	int x,destination;
	cout << "Enter your current floor : ";
	cin >>x;
	Passenger *p1  = new Passenger(x);
	cout << "Enter your destination   : ";
	cin >> destination;
	p1->destination = destination;

	e1->current_floor = 9;
//	e2->current_floor = 0;
	min_algo(e1,e2,p1);
//	display(e1,e2);
}


void min_algo(Elevator *e1, Elevator *e2, Passenger *p1){
	display(e1,e2);
	int e1_c = e1->current_floor;
	int e2_c = e2->current_floor;
	int p1_c = p1->current_floor;
	int min_e1 = _abs(e1_c - p1_c);
	int min_e2 = _abs(e2_c - p1_c);
	if(min_e1 <= min_e2){
		e1->current_floor = p1_c;
		cout << "\nWellcome in Elevator 1 " <<endl;
		display(e1,e2);
		e1->current_floor = p1->destination;
		cout << "\n Visit again" << endl;
		display(e1,e2);
	}else{
		e2->current_floor = p1_c;
		cout << "\nWellcome in Elevator 2 " <<endl;
		display(e1,e2);
		e2->current_floor = p1->destination;
		cout << "\n Visit again" << endl;
		display(e1,e2);
//		cout << min_e1 << " " << min_e2 << endl;
	}

}

int _abs(int x){
	return (x<0)?-x:x;
}
