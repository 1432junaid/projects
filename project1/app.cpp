
//	g++ -I/home/jd/Desktop/jd/projects/project1 -o app app.cpp -L/home/jd/Desktop/jd/projects/project1 -lmysqlcppconn
//	Use to run the program.


#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#define HOST "localhost"
#define USER "junaid"
#define PASS "junaid"
#define DB "faredb"

using namespace std;
using namespace sql;

void printer(vector<vector<int>>);
vector<int> get_id(string,string,ResultSet&);

int main(){

	const string url = HOST;
	const string user = USER;
	const string pass = PASS;
	const string database = DB;

	Driver& driver		= *get_driver_instance();
	Connection& con		= *driver.connect(url,user,pass);
	con.setSchema(database);
	Statement& stmt		= *con.createStatement();
	ResultSet& size		= *stmt.executeQuery("select  count(*) from city_master");
	ResultSet& graph	= *stmt.executeQuery("select * from farelist");
	ResultSet& id 		= *stmt.executeQuery("select * from city_master");


	int len;
	if(size.next()){
		len = size.getInt(1);
		len++;
	}
	cout << "len:\t" << len <<endl;

	vector<vector<int>>graph1(len,vector<int>(len,-1));	//creating graph
	for(int i =1; i<graph1.size(); i++)graph1[i][i] = 0;	//own city fare zero'0'

	while(graph.next()){
		int row = graph.getInt(1);
		int col = graph.getInt(2);
		int data= graph.getInt(3);
		graph1[row][col] = data;
	}

	printer(graph1);
	cout << endl;

	string s1;
	cout<< "enter city  source \t\t:";
	getline(cin,s1);

	ResultSet& name = *stmt.executeQuery("select city_name from city_master where city_name = '"+s1+"'	");
	if(name.next() ){
		string temp = name.getString(1);
		if(temp == NULL)cout << "city not not found\n";
	}
	cout << endl;
	cout << s1 << endl;
	return 0;
//		string temp = name.getString(1);
//		cout << temp;
//		if(s1 != name.getString(1) ){
//			cout << "city name does't exist\n";
//			return 0;
//		}
//	}



	string s2;
	cout << "enter city destination  \t:";
	getline(cin,s2);


	vector<int> city_id = get_id(s1,s2,id);

	cout << s1 << ":" << city_id[0] <<endl;
	cout << s2 << ":" <<city_id[1] <<endl;

	return 0;
}


void printer(vector<vector<int>>graph){
	for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph[i].size(); j++){
			cout << graph[i][j] << "\t";
		}cout << endl;
	}
}

vector<int> get_id(string city_from,string city_to,ResultSet& id){

	vector<int> city_id;
	int id1;
	int id2;

	while(id.next()){
		if(id.getString(2) == city_from)id1 = id.getInt(1);
		if(id.getString(2) == city_to)id2 =id.getInt(1);
	}
//	cout << id1 << endl;
//	cout << id2 << endl;
	city_id.push_back(id1);
	city_id.push_back(id2);

	return city_id;
}










