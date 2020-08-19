//
//  Program for checking parentheses of an input text file 
//
#include <iostream>   // for I/O facilities
#include <istream>   // for I/O facilities
#include <fstream>
#include <vector>
#include "char_stack.h" //  basic_int_stack declarations
using namespace std;

int main(int argc, char* argv[]) {
    
    int line_number = 0;
    bool error_found = false;
    int until_error = -1;
    
    char_stack c1;
    char entire_text[250];
    vector<int> placeoftab;
    bool was_tab = false;

    ifstream fs(argv[1]);

    while (cin.getline(entire_text,250)){
	until_error = -1;
	line_number++;
	//total_characters += (cin.gcount() - 1);
	placeoftab.clear();

	for(int i = 0; entire_text[i] != '\0'; i++) {

	    char look = entire_text[i];
	    until_error++;

	    switch(look){
		case '\t' :
		    placeoftab.push_back(i);
		    break;
		case '(' : 
		    c1.push('(');
		    break;
		case '{' :
		    c1.push('{');
		    break;
		case '[' :
		    c1.push('[');
		    break;

		case ')' :
		    if (c1.top() == '(') {
			c1.pop();
		    } else if (c1.top() == '{') {
			cout << "Error on line " << line_number << ": Read ), expected }";
			error_found = true;
		    } else if (c1.top() == '[') {
			cout << "Error on line " << line_number << ": Read ), expected ]";
			error_found = true;
		    } else {
			cout << "Error on line " << line_number << ": Too many )";
			error_found = true;
		    }
		    break;

		case '}' :
		    if (c1.top() == '{') {
			c1.pop();
		    } else if (c1.top() == '(') {
			cout << "Error on line " << line_number << ": Read }, expected )";
			error_found = true;
		    } else if (c1.top() == '[') {
			cout << "Error on line " << line_number << ": Read }, expected ]";
			error_found = true;
		    } else {
			cout << "Error on line " << line_number << ": Too many }";
			error_found = true;
		    }
		    break;

		case ']' :
		    if (c1.top() == '[') {
			c1.pop();
		    } else if (c1.top() == '(') {
			cout << "Error on line " << line_number << ": Read ], expected )";
			error_found = true;
		    } else if (c1.top() == '{') {
			cout << "Error on line " << line_number << ": Read ], expected }";
			error_found = true;
		    } else {
			cout << "Error on line " << line_number << ": Too many ]";
			error_found = true;
		    }
		    break;
	    }
	    
	    if (error_found == true){
		until_error++;
		cout << "\n";

		for (int j = 0; j < until_error; j++) {

		    if (placeoftab.size() > 0){
		    for(int k = 0; k < placeoftab.size(); k++) {
			if (placeoftab[k] == j){
			    cout << "\t";
			    was_tab = true;			
			} else {
			    was_tab = false;
			}
		    }
		    }

		    if (was_tab == false) {
			cout << entire_text[j];
		    }
		}

		cout << "\n";

		for (int j = 0; j < until_error; j++) {
			
		    if (placeoftab.size() > 0){
		    for(int k = 0; k < placeoftab.size(); k++) {
			if (placeoftab[k] == j){
			    cout << "\t";
			    was_tab = true;			
			} else {
			    was_tab = false;
			}
		    }
		    }

		    if (was_tab == false) {
			cout << " ";
		    }
		}
		
		for (int j = until_error; j < (cin.gcount() - 1); j++) {

		    if (placeoftab.size() > 0){
		    for(int k = 0; k < placeoftab.size(); k++) {
			if (placeoftab[k] == j){
			    cout << "\t";
			    cout << "tab";
			    was_tab = true;			
			} else {
			    was_tab = false;
			}
		    }
		    }

		    if (was_tab == false) {
			cout << entire_text[j];
		    }			
		}			

		break;
	    }
	
	}

	if (error_found == true) {
	    break;
	}

    }

    if (error_found == false && c1.empty() == false) {
	cout << "Error at end of file: Too many " << c1.top();
    } else if (error_found == false) {
	cout << "No Errors Found";
    }

return 0;

}
