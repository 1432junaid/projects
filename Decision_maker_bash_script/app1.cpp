
//	g++ -I/home/jd/Desktop/jd/projects/project1 -o app1 app1.cpp -L/home/jd/Desktop/jd/projects/project1 -lmysqlcppconn
// 	Use to run the program.


#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <bits/stdc++.h>

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

#define infi 1000000

using namespace std;
using namespace sql;

void printer(vector<vector<int>>);
vector<int> get_id(string,string,ResultSet&);


class City{
        public:
        int cityId;
        vector<pair<int, int> > neighbour;
        City(int cityId){
                this->cityId = cityId;
        }

        void add_neighbour(int cityId, int fare)
        {
                pair<int, int> p;
                p.first = cityId;
                p.second = fare;
                neighbour.push_back(p);
        }
};

int minFare(vector<City*>,int ,int , vector<int>&);

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
	ResultSet& fare		= *stmt.executeQuery("select * from farelist");


	int len;	//declare for assing the lenght of graph [note graph is (len x len) ]

	if(size.next()){
		len = size.getInt(1);
		len++;
	}
//	cout << "len:\t" << len <<endl;

	vector<vector<int>> graph1(len,vector<int>(len,-1));	//creating graph

	for(int i =1; i<graph1.size(); i++) graph1[i][i] = 0;	//own city fare zero'0'

	while(graph.next()){
		int row = graph.getInt(1);
		int col = graph.getInt(2);
		int data= graph.getInt(3);
		graph1[row][col] = data;		//putting data in graph
	}

	cout << "================================================================================================\n";

	cout  << "city ID \t" <<" city Name :\n\n\n";
	while(id.next() ){
		cout <<id.getInt(1) << "\t" << id.getString(2) << endl << endl;
	}

	cout << "================================================================================================\n";

//	printer(graph1);		//print the graph

	cout << endl << endl;

	int  id1;		//declare s1 for source and s2 for destination
	cout<< "enter citie source ID\t:";
	cin >> id1;
	if(id1 > (len-1) ){
		cout << id1 << ":\t";
		cout <<" !!Wrong city ID\n";
		return 0;
	}



	cout << "enter destination ID\t:" ;
	int id2;
	cin >> id2;
	if(id2 >(len - 1) ){
		cout << id2 <<":\t";
		cout << " !!Wrong city ID\n";
		return 0;
	}


//	vector<int> city_id = get_id(s1,s2,id);		//getting city_id's of city names

	vector<City*> v;
        int n = len, s = 2, e = 5;	        // Loop to create the nodes
        for (int i = 0; i < n; i++) {
                City* a = new City(i);
                v.push_back(a);
        }

	while(fare.next()){
			int row = fare.getInt(1);
                        int col = fare.getInt(2);
                        int data= fare.getInt(3);
			v[row]->add_neighbour(col,data);

	}

	vector<int> path(v.size());

        int minimumfare= minFare(v, id1, id2, path);	//store minimum fare in variable

	if(minimumfare == infi){
		cout << endl << "NO path exist\n";
	}else{
	        cout<<"minimum fare between "<< id1 <<"  and "<< id2 <<"  is: "<<minimumfare<<endl;
	}


	return 0;
}


void printer(vector<vector<int>>graph){				//function to print 2D matrix
	cout << "\n\n \t*********************Graph***********************\n\n";
	for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph[i].size(); j++){
			cout << graph[i][j] << "\t";
		}cout << endl;
	}
	cout << endl;
	for(int i = 0; i<30;i++)cout <<"==";
	cout << endl << endl;
}


vector<int> get_id(string city_from,string city_to,ResultSet& id){		//funtion to get Id along the city name's

	vector<int> city_id;
	int id1;
	int id2;

	while(id.next()){						//check line::62 for 'id' query use ctrl+/
		if(id.getString(2) == city_from)id1 = id.getInt(1);
		if(id.getString(2) == city_to)id2 =id.getInt(1);
	}
	city_id.push_back(id1);
	city_id.push_back(id2);

	return city_id;
}




int minFare(vector<City*> g,int s,int d, vector<int>& path){		//function to calculate minimum fare
        vector<int> dist(g.size());
        bool visited[g.size()];
        for (int i = 0; i < g.size(); i++) {
                visited[i] = false;
                path[i] = -1;
                dist[i] = infi;
        }
        dist[s] = 0;
        path[s] = -1;
        int current = s;
        unordered_set<int> sett;
        while (true) {
                visited[current] = true;
                for (int i = 0; i< g[current]->neighbour.size();i++) {
                        int v = g[current]->neighbour[i].first;
                        if (visited[v])continue;
                        sett.insert(v);
                        int alt= dist[current]+ g[current]->neighbour[i].second;
                        if (alt < dist[v]) {
                                dist[v] = alt;
                                path[v] = current;
                        }
                }
                sett.erase(current);
                if (sett.empty())
                        break;
                int minDist = infi;
                int index = 0;
                for (int a: sett) {
                        if (dist[a] < minDist) {
                                minDist = dist[a];
                                index = a;
                        }
                }
                current = index;
        }
        return dist[d];
}




