#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input();
template <class T>
void output(const vector<T>& vec);
void output(const string& message);

vector<int> findIntegers(const string& str);
int myStoi(const string& str, size_t& pos, bool& flag);


int main(void) {
	string s{ input() };
	vector<int> vec{ findIntegers(s) };
	cout << endl;
	output(vec);

	return 0;
}

string input() {
	string in{};
	getline(cin, in);
	return in;
}

template <class T>
void output(const vector<T>& vec) {
	for (auto var : vec) {
		cout << var << ' ';
	}

	return;
}

void output(const string& message) {
	cout << message;
	return;
}

vector<int> findIntegers(const string& str) {
	vector<int> vec;

	size_t pos = 0;
	size_t len = str.size();
	bool flag;

	while (pos < len) {
		auto t = myStoi(str, pos, flag);
		if (flag) vec.push_back(t);

        pos++;
	}

	return vec;
}

int myStoi(const string& str, size_t& pos, bool& flag) {
	while (pos < str.size() && isspace(str[pos])) pos++;
	
	flag = pos == 0 || isspace(str[pos - 1]);
	int result = 0;
	while (pos < str.size() && isdigit(str[pos])) {
		result = result * 10 + str[pos] - '0';
		pos++;
	}

	if (pos < str.size() && !isspace(str[pos])) flag = false;

	return result;
}