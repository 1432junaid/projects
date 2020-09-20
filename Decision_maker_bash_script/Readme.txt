


						title: Decision Making Bash Script


==================================================================================================================================================

[How to use  :]
	run 'main' file with one command line argument that must '.json' file that have information.
		Example: ./main data.json
	then run 'app' file.

[portability]
	we have a file name credentials.json file you can edit that file in order to change credential 
	information according to user  the contain information about  database,user,password and localhost.

--------------------------------------------------------------------------------------------------------------------------------------------------

[Description :]

	In this project we are creating database that ketp tables:
	1.	city_master:
			In city_master table we have two cities names and city ID.
	2.	fare_list:
			In the fare_list table each record show source and destination city ID's and 
			cost or fare between them.

	the './main' file used to create database and and tables store the information in the table by 
	any json file the json file have the information about the fare between the cities.

	after that, './app' file ask for source and destination cities that app file get the fare_list 
	table and create a graph .

	then we apply 'Min-cost algorithm' on that graph in order to get the min fare between the cities.

	finally, the app file output a result that shows that minimum cost between the cities. 

--------------------------------------------------------------------------------------------------------------------------------------------------

[commands :]


g++ -I/home/jd/Desktop/jd/mysql/mysql-connector -o json_new json_new.cpp -L/home/jd/Desktop/jd/mysql/mysql-connector -lmysqlcppconn -ljsoncpp
								OR
g++ -I/source[mysql repo] -o filename filename.cpp -L/source[mysql repo] -lmysqlcppconn -ljsoncpp

note :
1.	-lmysqlcppconn	[use for mysql]
2.	-ljsoncpp	[use for json]

--------------------------------------------------------------------------------------------------------------------------------------------------

[Pre-Requirements :]

1.	jsoncpp setup
2.	mysql
3.	mysqlcpp-connector setup

--------------------------------------------------------------------------------------------------------------------------------------------------

[Reference :]

1.	https://linux.tips/programming/how-to-install-and-use-json-cpp-library-on-ubuntu-linux-os
