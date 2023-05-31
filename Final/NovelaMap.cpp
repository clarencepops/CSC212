#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;



map<string, int> popMap(){                  //populate the map with distinct pairs of strings and integers
    map<string, int> Novel;
    string word;
    ifstream infile ("Smileys.txt");
    while (infile >> word) {                // read each word from the file
        for (int i = 0; i < word.size(); i++) {         //populate words into the map
            if (word[i] < 'A' || word[i] > 'Z' && word[i] < 'a' || word[i] > 'z') {
                word.erase(i, 1);
                i--;
            }
        }
        
        Novel[word];
        Novel[word] = word.size();          //populate map with sizes
        
    }
    return Novel;
}


void printMap(map<string, int> Novel){      //printing the populated map of its words and respected lengths
    int size = Novel.size();
    map<string, int>::iterator it = Novel.begin();
    while (it != Novel.end()){
        string word;
        int count;
        word = it->first;
        count = it->second;
        cout << word << ": " << count << endl;
        it++;
    }
}

pair<string, int> findlongestWord(map<string, int> Novel){          //find the longest word in the map
    pair<string, int> longestWord = make_pair(" ", 0);              //longest word is stored as a pair of string (word) and int (the words size)

    map<string, int>::iterator currentEntry;
    for (currentEntry = Novel.begin(); currentEntry != Novel.end(); ++currentEntry){
        if(currentEntry->second > longestWord.second) {
            longestWord = make_pair(currentEntry->first, currentEntry->second);         //stores the largest word as it cycles through the Novel map
        }
    }
    return longestWord;
}

vector<int> makeHistogram(map<string, int> Novel, pair<string, int> longestWord){       //Making a histogram using the longest word and Novel map
    map<string, int>:: iterator currentEntry;
    vector<int> Histogram(longestWord.second);
    int wordSize = 0;

    for (currentEntry = Novel.begin(); currentEntry != Novel.end(); ++currentEntry){
        wordSize = currentEntry->second;
        Histogram[wordSize - 1]++;                                                      //adds a tally to Histagram after reading a words size, to that sizes respective place in the vector
    }

    return Histogram;
}

void lessthanEight(map<string, int> Novel){         //finds and adds all words less than 8 characters to a vector of strings
    map<string, int>:: iterator currentEntry;
    int count = 0;
    vector<string> Eight;

    for (currentEntry = Novel.begin(); currentEntry != Novel.end(); ++currentEntry){    //iterates through the Novel map, adding any words with less characters to the Eight vector
        if (currentEntry->second < 8){
            Eight.push_back(currentEntry->first);
        }
    }

    cout << "The words with less than eight characters are the following:\n";           //Printing the Eight vector
    for (int i=0; i < Eight.size(); i++){
        cout << Eight.at(i) << endl;
    }
    cout << "There are " << Eight.size() << " different words which have less than 8 characters!\n" << endl;

}

void findcharFront(map<string, int> Novel, char targetKey){                 //finding words which start with a specified char targetKey
    vector<string> targetWords;
    map<string, int>::iterator currentEntry;
    char opp;

    if (std::isupper(targetKey)) {                      //develops an instance of uppercase and lowercase versions of the target char
        opp = tolower(targetKey); 
    }
    else{
        opp = toupper(targetKey); 
    }
    
    for (currentEntry = Novel.begin(); currentEntry != Novel.end(); ++currentEntry){    //loops through Novel, and any words which begin with targetKey (upper or lowercase) are added to the target vector
        string temp = currentEntry->first;

        
        if(temp[0] == targetKey || temp[0] == opp){
            targetWords.push_back(temp);
        }
    }
    cout << "The following are words beginning with the inputted letter " << targetKey << ":\n";    //prints the target vector
    for (int i=0; i < targetWords.size(); i++){
        cout << targetWords.at(i) << endl;
    }
    cout << endl;

}

void findChar(map<string, int> Novel, char targetKey){      //finds and adds words which include a target char to a targetWords vector
    vector<string> targetWords;
    map<string, int>::iterator currentEntry;
    char opp;

    if (std::isupper(targetKey)) {              //develops an instance of uppercase and lowercase versions of the target char
        opp = tolower(targetKey); 
    }
    else{
        opp = toupper(targetKey); 
    }

    for (currentEntry = Novel.begin(); currentEntry != Novel.end(); ++currentEntry){        //finds applicable words, and populates the target vector
        string temp = currentEntry->first;

        if(temp.find(targetKey) != std::string::npos || temp.find(opp) != std::string::npos){
            targetWords.push_back(temp);
        }
    }
    cout << "The following are words including the inputted letter " << targetKey << ":\n";         //prints target vector
    for (int i=0; i < targetWords.size(); i++){
        cout << targetWords.at(i) << endl;
    }
    cout << endl;
}

void findCap(map<string, int> Novel){           //finds capitilized words and adds them to a vector targetWords
    vector<string> targetWords;
    map<string, int>::iterator currentEntry;


    for (currentEntry = Novel.begin(); currentEntry != Novel.end(); ++currentEntry){    //populates the vector from capitilized words from Novel
        string temp = currentEntry->first;

        if(temp.at(0) >= 'A' && temp.at(0) <= 'Z'){
            targetWords.push_back(temp);
        }
    }

    cout << "The following are words beginning with capital letters:\n";        //prints the upercase word vector
    for (int i=0; i < targetWords.size(); i++){
        cout << targetWords.at(i) << endl;
    }
    cout << "There are " << targetWords.size() << " capitilized words in the text!\n";
    cout << endl;
}


int main () {

    cout << "-----------------------------------------\n";
    cout << "Name: Christian Rasmussen\n";
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "-----------------------------------------\n";


    ifstream infile ("Smileys.txt");            //opens the asscociated txt file
    pair<string, int> x;
    map<string, int> Novel;
    string word;
    
    Novel = popMap();
    printMap(Novel);

    pair<string, int> longestWord = findlongestWord(Novel);
    cout << "The longest word in the text file is " << longestWord.first << " with " << longestWord.second << " letters!\n" << endl;
    
    vector<int> Histogram;
    Histogram = makeHistogram(Novel, longestWord);
    
    cout << "Histogram:\n";                         //prints the Histogram made from makeHistogram()
    for (int i = 0; i < Histogram.size(); i++){
        cout << "there are " << Histogram.at(i) << " words with " << i+1 << " letters\n";
    }
    cout << endl;


    lessthanEight(Novel);

    char targetKey = 'C';
    findcharFront(Novel, targetKey);
    findChar(Novel, targetKey);
    findCap(Novel);

    cout << "The total number of unique words are: " << Novel.size() << endl;
}

/*********** Results *********
 -----------------------------------------
Name: Christian Rasmussen
FILE: NovelaMap.cpp DATE: May 14 2023
-----------------------------------------
Called: 6
Cambridge: 9
Circus: 6
Control: 7
Czechoslovakia: 14
English: 7
George: 6
He: 2
Intelligence: 12
Jim: 3
London: 6
Prideaux: 8
Russian: 7
Secret: 6
Service: 7
Smiley: 6
Soviet: 6
Tailor: 6
Testify: 7
Tinker: 6
a: 1
affairs: 7
agent: 5
ahead: 5
an: 2
and: 3
as: 2
assigned: 8
at: 2
back: 4
because: 7
begins: 6
behind: 6
by: 2
capture: 7
chief: 5
childrens: 9
clues: 5
code: 4
codenamed: 9
continues: 9
days: 4
derived: 7
discovering: 11
doesnt: 6
ended: 5
enough: 6
failure: 7
finds: 5
five: 4
follow: 6
following: 9
for: 3
forced: 6
friend: 6
friends: 7
from: 4
had: 3
happened: 8
high: 4
his: 3
important: 9
in: 2
intelligence: 12
is: 2
issues: 6
it: 2
its: 3
kill: 4
killers: 7
know: 4
known: 5
lead: 4
living: 6
mole: 4
names: 5
of: 2
office: 6
officers: 8
old: 3
one: 3
operation: 9
or: 2
organization: 12
out: 3
overwhelmed: 11
past: 4
person: 6
pieces: 6
political: 9
put: 3
relay: 5
retirement: 10
rhyme: 5
secret: 6
senior: 6
settle: 6
so: 2
step: 4
suspected: 9
that: 4
the: 3
them: 4
to: 2
together: 8
torture: 7
unhappily: 9
up: 2
want: 4
was: 3
what: 4
which: 5
The longest word in the text file is Czechoslovakia with 14 letters!
there are 1 words with 1 letters
there are 13 words with 2 letters
there are 12 words with 3 letters
there are 16 words with 4 letters
there are 11 words with 5 letters
there are 24 words with 6 letters
there are 13 words with 7 letters
there are 5 words with 8 letters
there are 10 words with 9 letters
there are 1 words with 10 letters
there are 2 words with 11 letters
there are 3 words with 12 letters
there are 0 words with 13 letters
there are 1 words with 14 letters
The words with less than eight characters are the following:
Called
Circus
Control
English
George
He
Jim
London
Russian
Secret
Service
Smiley
Soviet
Tailor
Testify
Tinker
a
affairs
agent
ahead
an
and
as
at
back
because
begins
behind
by
capture
chief
clues
code
days
derived
doesnt
ended
enough
failure
finds
five
follow
for
forced
friend
friends
from
had
high
his
in
is
issues
it
its
kill
killers
know
known
lead
living
mole
names
of
office
old
one
or
out
past
person
pieces
put
relay
rhyme
secret
senior
settle
so
step
that
the
them
to
torture
up
want
was
what
which
There are 90 different words which have less than 8 characters!

The following are words beginning with the inputted letter C:
Called
Cambridge
Circus
Control
Czechoslovakia
capture
chief
childrens
clues
code
codenamed
continues

The following are words including the inputted letter C:
Called
Cambridge
Circus
Control
Czechoslovakia
Intelligence
Secret
Service
back
because
capture
chief
childrens
clues
code
codenamed
continues
discovering
forced
intelligence
office
officers
pieces
political
secret
suspected
which

The following are words beginning with capital letters:
Called
Cambridge
Circus
Control
Czechoslovakia
English
George
He
Intelligence
Jim
London
Prideaux
Russian
Secret
Service
Smiley
Soviet
Tailor
Testify
Tinker
There are 20 capitilized words in the text!
******************************/