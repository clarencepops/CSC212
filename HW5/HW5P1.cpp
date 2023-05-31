#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class node{
    public:
    string model;
    int price;
    string owner;
    node* next;
    node(string model, int price, string owner){
        this->model = model;
        this->price = price;
        this->owner = owner;
        next = NULL;
    }

};


void printNode(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->owner << " owns the " << temp->model << " which costs " << temp->price << "$\n";
        temp = temp->next;
    }
}

node* input(){
    int price;
    string model;
    string owner;

    node* head;
    node* tail;

    head = NULL;
    tail = NULL;
    cout << "Please enter the following information for cars. (Enter a price from 7500 - C:Cadillac, T:Toyota, B:BMW)\n";

    for (int i=0; i<12; i++){
        cout << i+1 << " Owner: ";
        cin >> owner;
        
        cout << i+1 << " Model: ";
        do{
            cin >> model;

            if (model != "C" && model != "c" && model != "B" && model != "b" && model != "T" && model != "t") {
                cout << "Invalid input, try again\n";
            }
        } while(model != "C" && model != "c" && model != "B" && model != "b" && model != "T" && model != "t");
        if (model == "c" || model == "C"){
            model = "Cadillac";
        }
        else if (model == "T" || model == "t"){
            model = "Toyota";
        }
        else if (model == "B" || model == "b"){
            model = "BMW";
        }

        cout << i+1 << " Price: ";
        
        do{
            cin >> price;
            if (price > 20500 || price < 1){
                cout << "Invalid price, try again\n";
            }
        } while(price > 20500 || price < 1);

        node* newNode = new node(model, price, owner);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }

    }
    return head;
}

int findAverage(node* head){
    node* temp = head;
    int average = 0;

    while (temp != NULL){
        average = average + temp->price;
        temp = temp->next;
    }

    return average / 12;
}

void find_if(node* head) {
    node* temp = head;
    cout << "The following are cars which cost less than $7500:\n";
    while (temp != nullptr) {
        if (temp->price < 7500) {
            cout << "Owner: " << temp->owner << " || Make: " << temp->model << " || Price: " << temp->price << endl;
        }
        temp = temp->next;
    }
}


void Histogram(node* head) {
    map<int, int> histogram;

    cout << "Histogram:\n";

    // Traverse the linked list
    node* current = head;
    while (current != nullptr) {
        int roundDown = (current->price / 500) * 500;
        // Increment the count for the current price
        histogram[roundDown]++;

        // Move to the next node
        current = current->next;
    }

    // Print the histogram
    for (const auto& pair : histogram) {
        cout << "Price: " << pair.first << " - " << pair.first + 499 <<" || Count: " << pair.second << endl;
    }
}

void Expensive(node* head, int average){
    node* temp = head;
    cout << "The following are cars which cost more than the average:\n";
    while (temp != nullptr) {
        if (temp->price > average) {
            cout << "Owner: " << temp->owner << " || Make: " << temp->model << " || Price: " << temp->price << endl;
        }
        temp = temp->next;
    }
}

void remove(node* head, int average){
    node* current = head;
    node* prev = nullptr;

    average = average * 0.25;

    while (current != nullptr){
        if (current->price < average){
            head = current->next;
            if (prev == nullptr){
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;

            current = prev != nullptr ? prev->next : head;
        }
        else{
            prev = current;
            current = current->next;
        }

    }
    cout << "All cars which cost less than 25% of the average (" << average << ") cost were removed from the list:\n";
}



void modelStack(node* head){
    stack<string> Models;

    while (head != nullptr){
        Models.push(head->model);
        head = head->next;
    }

    cout << "Stack Models:\n";
    while (!Models.empty()){
        cout << "Model: " << Models.top() << endl;
        Models.pop();
    }
}



int main(){

    node* head = input();

    printNode(head);
    int average = findAverage(head);

    cout << "Average: " << average << endl;

    Expensive(head, average);

    find_if(head);

    Histogram(head);

    remove(head, average);

    printNode(head);


    modelStack(head);
}