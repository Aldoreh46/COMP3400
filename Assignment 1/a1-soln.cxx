#include <iostream>
#include <climits>
#include <stdlib.h>


using namespace std;

struct score {
	string fst_str;
	string snd_str; 
	unsigned int score_; 
public:
	friend ostream& operator << (ostream& out, const score& sc);
	friend struct score& operator >> (istream& in, score& sc);
};

ostream& operator << (ostream& out, const score& sc) 
{
	out << sc.fst_str << " "; 
	out << sc.snd_str << " "; 
	out << sc.score_ << endl; 
	return out; 
}

struct score& operator >> (istream& in, score& sc) 
{
	char str_input[30];
	int i, int_input;
	bool num;

	in >> sc.fst_str;
	in >> sc.snd_str; 
	in >> str_input;
	
	int_input = 0;
	num = true; 

	for (i = 0; str_input[i] != '\0'; i++) {
		
		if (str_input[i] >= '0' && str_input[i] <= '9') {
			int_input *= 10;
			int_input += (str_input[i] - 48); 
		}
		else {
			cout << "ERROR: Score is not a number \n";
			num = false;
			break;
		}
	}
	if (num)
		sc.score_ = int_input;
	else		
		sc.score_ = INT_MAX; 
	return sc; 
}

int main() 
{
	struct score result; 
	while (true) {
		cin >> result; 
		if (result.score_ == INT_MAX) 
			break; 
		cout << result; 
	}
	return 0;
}
