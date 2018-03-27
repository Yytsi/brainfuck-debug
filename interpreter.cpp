#include <bits/stdc++.h>
using namespace std;

#define TAPE_SIZE 100
int tape[TAPE_SIZE];
vector<string> inputs;
string s;

int toi(const string& str) {
	// "143" => 143
	int num = 0; int p = 0;
	for (int j = (int)str.size() - 1; j >= 0; j--, p++) {
		char c = str[j];
		assert(("Parsing a number failed!", isdigit(c)));
		num += (c - 48) * pow(10, p);
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string temp;
	
	// The first line is inputs only.
	string curr = "", inp;
	getline(cin, inp);
	for (char c : inp) {
		if (c == ' ') {
			inputs.push_back(curr);
			curr = "";
		} else curr += c;
	}
	if (curr != "") inputs.push_back(curr);
	
	while (getline(cin, temp)) {
		if (temp[0] == '#') {
			// A comment.
			continue;
		}
		// Erase whitespaces and tabs.
		temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
		temp.erase(remove(temp.begin(), temp.end(), '\t'), temp.end());
		s += temp; // Add the line to the BF code.
	}
	
	// i : Instruction index.
	// n : Length of the program.
	// p : Cell pointer.
	// k : Input index.
	int i = 0, n = (int)s.size(), p = 0, k = 0;
	while (i < n) {
		switch (s[i]) {
			case '+':
				tape[p]++; break;
			case '-':
				tape[p]--; break;
			case '.':
				cout << tape[p]; break;
			case 'C':
				cout << (char)tape[i]; break;
			case ',':
				tape[p] = toi(inputs[k++]); break;
			case 'I':
				tape[p] = (char)(inputs[k++][0]); break;
			case '<':
				p--;
				if (p < 0) p = TAPE_SIZE - 1;
				break;
			case '>':
				p++;
				if (p >= TAPE_SIZE) p = 0;
				break;
			case '[':
				if (tape[p] == 0) {
					// Find the matching closure.
					int depth = 1;
					while (depth) {
						i++;
						assert(("Forward-referencing failed => ending of a loop not found!", i < n));
						if (s[i] == ']') depth--;
						else if (s[i] == '[') depth++;
					}
				}
				break;
			case 'P':
				system("pause"); break;
			case ']':
				// Find the matching start.
				int depth = 1;
				while (depth) {
					i--;
					assert(("Backreferencing failed => start of a loop not found!", i >= 0));
					if (s[i] == ']') depth++;
					else if (s[i] == '[') depth--;
				}
				i--;
				break;
		}
		i++; // Move forward.
	}
}











