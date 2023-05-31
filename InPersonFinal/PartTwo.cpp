#include <iostream>
#include <list>
#include <map>
using namespace std;

int findLen(char **Words){
	int len = 0;
    while (Words[len] != nullptr) {
        len++;
    }
	len -=1;
    return len;
}

map<string, int> Encrypt(map<string, int> PlainTxt){		//Part C Function encrypt 
	for (auto& pair : PlainTxt) {
        const std::string& str = pair.first;
		int sum = 0;
		for (char c : str) {
        sum += static_cast<int>(c);
    	}
        pair.second = sum;
    }
	return PlainTxt;
}

bool IsPunct(char c) { return std::ispunct(static_cast<unsigned char>(c)); }


int main() {
    /***********************/
	cout << "Name: Christian Rasmussen" << endl;
	cout << "File: " << __FILE__ << "   " << "Date: " << __DATE__  << endl;
	/***********************/

	char *Words[] = {"double-007", "will", "arrive", "in", "Paris",
                 	  "on", "the", "9:45AM", "train", "from", "Prague",
                 	  "and", "will", "meet", "Count", "Igor", "at", "Cafe",
                 	  "Deux", "Magots", "at" , "St. Germain", "707",
                 	  "where", "he", "will", "pass", "the", "briefcase",
         	 		  "upon", "receiving", "the" , "password","Attila"
    };

	int len = findLen(Words);					//Part A create length of characters in pointer

	cout << "the size of the character pointer is " << len << endl;

	list<string> Palabra;			//Part B creat list of strings from Words
	for(int i = 0; i < len; ++i){
		Palabra.push_back(Words[i]);
	}

	map<string, int> PlainTxt;			
	for (const auto& element : Palabra) {
    PlainTxt[element] = 0;
	}		

	PlainTxt = Encrypt(PlainTxt);		//Create 

	for (const auto& pair : PlainTxt) {		//Part D print PlainTxt from Encrypt
        cout << pair.first << ": " << pair.second << endl;
    }
	
	/*							//Part e finding words that start with uppercase (bugs not working)
	int count = std::count_if(PlainTxt.begin(), PlainTxt.end(), [](const auto& pair) -> bool {
        return IsPunct(pair.first[0]);
    });

    std::cout << "Number of words starting with punctuation: " << count << std::endl;
	*/

	list<int> Cypher;					//Part Create List of ints from ascii numbers in PlainTxt
    for (const auto& pair : PlainTxt) {
        Cypher.push_back(pair.second);
    }

	cout << "The Cypher list containing ascii sum values is:\n";		//Part G Print Cypher
	for (const auto& value : Cypher) {
        cout << value << endl;
    }

	return 0;
}



/*********** Results ********
Name: Christian Rasmussen
File: PartTwo.cpp   Date: May 18 2023
the size of the character pointer is 34
707: 158
9:45AM: 362
Attila: 607
Cafe: 367
Count: 521
Deux: 406
Igor: 401
Magots: 619
Paris: 511
Prague: 612
St. Germain: 984
and: 307
arrive: 649
at: 213
briefcase: 932
double-007: 831
from: 436
he: 205
in: 215
meet: 427
on: 221
pass: 439
password: 883
receiving: 956
the: 321
train: 542
upon: 450
where: 539
will: 440
The Cypher list containing ascii sum values is:
158
362
607
367
521
406
401
619
511
612
984
307
649
213
932
831
436
205
215
427
221
439
883
956
321
542
450
539
440

*******************************/