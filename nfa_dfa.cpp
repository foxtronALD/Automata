#include <bits/stdc++.h>

using namespace std;

map<string, vector<string> > NFA;
map<string, vector<string> > DFA;
set<string> inc;

#define MAX_SYM 100
#define MAX_STATE 26

void redundancy(string &A){
	sort(A.begin(), A.end());	//10 20 20 20 30 30 20 20 20 20 20 10 10 10
	string::iterator it = unique(A.begin(),A.end());   // 10 20 30 20 10 ?  ?  ?  ?
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
	for(i = 0; i < n; i++){
		cin >> sym[i];
	}

	cout << "Enter the number of states: ";
	cin >> m;

	cout << "Enter the state names in order\n";
	cin >> stateName;

	//lets make the transition table
	for(i = 0; i < m; i++){
		string temp, temp1;
		temp.push_back(stateName[i]);

		for(j = 0; j < n; j++){
			cout << "d(" << stateName[i] << "," << sym[j] << ") = ";
			cin >> temp1;
			//cout << temp1 << endl << endl;

			redundancy(temp1);
			NFA[temp].push_back(temp1);

			cout << endl;
		}

		cout << endl;
	}

	//lets build the NFA table
	queue<string> order;
	string start;
	start = start + stateName[0];



	map<string, bool> vis;

	//insert the beginning point
	order.push(start);

	while(!order.empty()){

		//we take the state whose transition is to be found
		//called as rowid
		string rowid = order.front();
		order.pop();
		vis[rowid] = true;//mark it visited

		//lets traverse for the input symbols and generate the corresponding DFA
		for(i = 0; i < n; i++){

			string column, temp;

			//check the NFA table and generate the output string/state
			//check the number of characters and generate the column var
			for(j = 0; j < rowid.size(); j++){
				temp = rowid[j];
			    //cout << column << "\t" <<  temp << "\t" << rowid  << endl;
				column += NFA[temp][i];
			}

//			cout <<  i << "\t" << j << "\t" << column << endl;

		 	redundancy(column);

			DFA[rowid].push_back(column);

			//now lets push the new column found if it has not been visited already
			if(!vis[column])
				order.push(column);
		}
	}
	cout << "State\t|\t";
	for(i = 0; i < n; i++) cout << sym[i] << "\t";
	cout << endl;

	//lets print the output
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
