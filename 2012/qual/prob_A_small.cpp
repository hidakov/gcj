#include <iostream>
#include <string>
#include <vector>

using namespace std;

char map(char ch) {
	char result;
	switch (ch) {
		case 'y':
			result= 'a'; 
			break;
		case 'n' :
			result = 'b'; 
			break;
		case 'f' :
			result = 'c';
			break;
		case 'i' :
			result = 'd';
			break;
		case 'c' :
			result = 'e';
			break;
		case 'w' :
			result = 'f';
			break;
		case 'l' :
			result = 'g';
			break;
		case 'b' :
			result = 'h';
			break;
		case 'k' :
			result = 'i';
			break;
		case 'u':
			result = 'j'; 
			break;
		case 'o' :
			result = 'k'; 
			break;
		case 'm' :
			result = 'l';
			break;
		case 'x' :
			result = 'm';
			break;
		case 's' :
			result = 'n';
			break;
		case 'e' :
			result = 'o';
			break;
		case 'v' :
			result = 'p';
			break;
		case 'z' :
			result = 'q';
			break;
		case 'p' :
			result = 'r';
			break;
		case 'd' :
			result = 's';
			break;
		case 'r' :
			result = 't';
			break;
		case 'j' :
			result = 'u';
			break;
		case 'g' :
			result = 'v';
			break;
		case 't' :
			result = 'w';
			break;
		case 'h' :
			result = 'x';
			break;
		case 'a' :
			result = 'y';
			break;
		case 'q' :
			result = 'z';
			break;
		default:
			result = ch;
	}
	return result;
}

int main() {
	int T;
	string buf;

	getline(cin, buf); 
	T = atoi(buf.c_str());
	for (int i=1; i<=T;i++) {
		string result = "";

		getline(cin, buf);
		string::iterator it = buf.begin();
		while (it != buf.end()) {
			char ch = *it;
			if (ch == '\n') {
				break;
			}
			if (ch != ' ') {
				ch = map(ch);
			}
			result += ch;
			it++;
		}
		cout << "Case #" << i << ": ";
		cout << result << endl;
	}

	return 0;
}

