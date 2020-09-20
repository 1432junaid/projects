#include<iostream>
#include <bits/stdc++.h>
#define infi 1000000000
using namespace std;

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

int minFare(vector<City*> g,int s,int d, vector<int>& path){
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

// Driver Code
int main(){
	vector<City*> v;
	int n = 8, s = 2, e = 5;
	// Loop to create the nodes
	for (int i = 0; i < n; i++) {
		City* a = new City(i);
		v.push_back(a);
	}

	v[2]->add_neighbour(3, 300);
	v[2]->add_neighbour(5, 800);
	v[2]->add_neighbour(6, 150);
	v[3]->add_neighbour(2, 300);
	v[3]->add_neighbour(4, 500);
	v[3]->add_neighbour(6, 150);
	v[4]->add_neighbour(1, 240);
	v[4]->add_neighbour(3, 500);
	v[4]->add_neighbour(7, 250);
	v[7]->add_neighbour(1, 200);
	v[7]->add_neighbour(2, 700);
	v[7]->add_neighbour(4, 250);

	vector<int> path(v.size());
	int minimumfare= minFare(v, 2, 1, path);
	cout<<"minimum fare between 2 and 1 is: "<<minimumfare<<endl;
	// Loop to print the distance of
	// every node from source vertex
	/*for (int i = 0; i < dist.size(); i++) {
		if (dist[i] == infi) {
			cout << i << " and " << s<< " are not connected"<< endl;
			continue;
		}
		cout << "Distance of " << i<< "th vertex from source vertex "<< s << " is: "<< dist[i] << endl;
	}*/
	return 0;
}

