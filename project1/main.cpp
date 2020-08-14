#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stdexcept>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include <fstream>
#include <jsoncpp/json/json.h>




using namespace std;
using namespace sql;
using namespace Json;

int main(int argc, char* args[]){
	if(argc != 2){
		cout << "Input file missing" << endl;
		return 0;
	}
	ifstream ifs(args[1]);

	cout << "Uploading file ........." << endl;

	Reader reader;
	Reader creader;
	Value croot;
	Value root;
	reader.parse(ifs,root);	 		//parsing
	ifstream cifs("credentials.json");
	creader.parse(cifs,croot);

	const string url = croot["url"].asString();
	const string user = croot["username"].asString();
	const string pass = croot["password"].asString();
	const string database = croot["database"].asString();

	try{
		Driver& driver = *get_driver_instance();		//getting driver
		Connection& con = *driver.connect(url,user,pass);		//entering in mysql
		con.setSchema(database);			//using database
		Statement& stmt = *con.createStatement();

		Value::Members v = root.getMemberNames();
		for(Value::Members::iterator itr1 = v.begin(); itr1 !=v.end(); itr1++){
			string s1 = *itr1;
			Value::Members v1 = root[s1].getMemberNames();
			for(Value::Members::iterator itr2 = v1.begin(); itr2 != v1.end(); itr2++){
				string s2 = *itr2;
				string s3 = root[s1][s2].asString();
	stmt.execute("insert into farelist values( (select city_id from city_master where (city_name = '"+s1+"'))"
		",(select city_id from city_master where (city_name = '"+s2+"')), '"+s3+"')");
			}
		}
	cout <<"file uploaded in database !!successfully" <<endl;
	}catch(SQLException &e){
                cout<< "Error" << e.what()<<endl;
        }
        return 0;

}
