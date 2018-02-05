#include <bits/stdc++.h>

using namespace std;

map<string, vector<string> > NFA;
map<string, vector<string> > DFA;
set<string> inc;

#define MAX_SYM 100
#define MAX_STATE 26

void redundancy(string &A)
{
	sort(A.begin(), A.end());	
	string::iterator it = unique(A.begin(),A.end());   
	int newsize = distance(A.begin(),it);
  	A.resize(newsize);
}

int main()
{
	int n, m, i, j;
	string sym;
	string stateName;
	cout << "Enter the number of input symbols: ";
	cin >> n;
	cout << "Enter the input symbols in order\n";
	for(i = 0; i < n; i++)
		cin >> sym[i];
	cout << "Enter the number of states: ";
	cin >> m;
	cout << "Enter the state names in order without any space as a single String\n";
	cin >> stateName;


	for(i = 0; i < m; i++)
	{
		string temp,temp1;
		temp.push_back(stateName[i]);
		for(j = 0; j < n; j++)
		{	cout << "d(" << stateName[i] << "," << sym[j] << ") = ";
			cin >> temp1;
			if(temp1=="null")
			  temp1="";

			redundancy(temp1);
			NFA[temp].push_back(temp1);

			cout << endl;
		}

	}

	queue<string> order;
	string start;
	start = start + stateName[0];

	map<string, bool> vis;

	order.push(start);

	while(!order.empty()){
		string rowid = order.front();
		order.pop();
		vis[rowid] = true;
		for(i = 0; i < n; i++){

			string column, temp;

			for(j = 0; j < rowid.size(); j++){
				temp = rowid[j];
				column += NFA[temp][i];
			}


		 	redundancy(column);

			DFA[rowid].push_back(column);

			if(!vis[column])
				order.push(column);
		}
	}
	cout << "State\t|\t";
	for(i = 0; i < n; i++) cout << sym[i] << "\t";
	cout << endl;

	map<string, vector<string> >::iterator it;
	for(it = DFA.begin(); it!=DFA.end(); it++){
		cout << it->first << "\t" << "|" << "\t";
		for(i = 0; i < n; i++){
			cout << (it->second)[i] << "\t";
		}
		cout << endl;
	}

	return 0;
}
