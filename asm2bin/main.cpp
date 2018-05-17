#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>

using namespace std;

ofstream outFile;
ifstream inFile;

vector<string> split(const string &str)
{
	vector<string> res;
	string delim = " ,";		//同时使用多个分割符！！!
	if (" " == str)
		return res;

	char *strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());
	char *d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	string s;
	while (p)
	{
		s = p;
		res.push_back(s);
		p = strtok(NULL, d);
	}
	/*for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	cout << "END" << endl;*/
	return res;
}

int main()
{
	inFile.open("inst.txt");
	outFile.open("bin.txt");
	
	char buf[64];
	string str;
	vector<string> res;

	while (inFile.getline(buf, sizeof(buf)))
	{
		str = buf;
		res = split(str);
	}

	inFile.close();
	outFile.close();

	system("pause");
}