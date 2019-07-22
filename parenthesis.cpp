#include <iostream>
#include <stack>
using namespace std;

bool areMatchingPair(char openingBrac, char closingBrac) {
	
	bool returnValue = false;
	

	switch (openingBrac) {
		
		case '{' :
			returnValue = (closingBrac == '}') ? true : false;
			break;
		case '[' :
			returnValue = (closingBrac == ']') ? true : false;
			break;
		case '(' :
			returnValue = (closingBrac == ')') ? true : false;
			break;			
	
	}
	
	return returnValue;
	
}
bool parenthesisBalance(string exp) {
	
	stack<char> s;
	
	for(int i = 0; i<exp.length(); i++){
		
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
			
			s.push(exp[i]);
		}
		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
			
			
			if(s.empty() || !areMatchingPair(s.top(),exp[i])) {
				
				return false;
			}
			
			else {
				s.pop();
			}
			
		
		}
		
	
	}
	
	return s.empty() ? true : false;

}
int main() {

	
	string expression;
	cin >> expression;
	
	if(parenthesisBalance(expression)) {
		cout << "Balanced" << endl;
	}
	else cout << "Unbalanced"<< endl;


}
