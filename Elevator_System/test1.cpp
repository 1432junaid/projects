#include <iostream>
using namespace std;

class demo{
	demo(){}
	public :int x = 10;

	public:
	static demo* CreateObject(){
		demo *d1 = new demo();
		return d1;
	}
};

int main(){
	demo *d1 = demo::CreateObject();
	cout << d1->x << endl;
	return 0;
}
