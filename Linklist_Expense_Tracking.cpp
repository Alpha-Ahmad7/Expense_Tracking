#include<iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string d){
        data = d;
        next = NULL;}
};

class Master{
public:
    Node* key;      
    Master* next;
    Master() {
        key = NULL;
        next = NULL;}
};

class List{
public:
    Master* head;

    List() {
        head = NULL;}

    
    void addExpense(string type, int amount){
        
        Node* typeNode = new Node(type);
        Node* amountNode = new Node(to_string(amount));
        typeNode->next = amountNode;

        Master* newMaster = new Master();
        newMaster->key = typeNode;

        if (head==NULL) {
            head = newMaster;} 
		else {
            Master* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newMaster;
        }
        cout << "Expense added!"<<endl;
}

    
    void display() {
        if (head==NULL) {
            cout << "No expenses added"<<endl;
            return;}
            
        Master* temp = head;
        int count = 1;
        while (temp != NULL) {
            Node* t = temp->key;
            cout << count << ": ";
            while (t != NULL) {
                cout << t->data << "   ";
                t = t->next;
            }
            cout << endl;
            temp = temp->next;
            count++;
        }
        cout<<endl;
}


    void updateExpense(int pos, string newType, int newAmount) {
        Master* temp;
		temp = head;
        int i=1;
        while (temp != NULL && i<pos) {
            temp = temp->next;
            i++;}

        if (temp==NULL) {
            cout << "Invalid position!"<<endl;
            return;}
        temp->key->data = newType;                   
        temp->key->next->data = to_string(newAmount); 
        cout << "Expense updated!"<<endl;
    }};


int main() {
    List L;
    int choice;

    while (true){
        cout<<" 1- Add Expense \n 2- Update Expense \n 3- Display Expenses \n 0- Exit"<<endl;
        cin >> choice;

        if (choice == 1){
            string type;
            int amount;
            cout << "Enter Type:  ";
            cin >> type;
            cout << "Enter Amount:  ";
            cin >> amount;
            L.addExpense(type, amount);} 
		else if (choice == 2){
            L.display();
            int pos;
            cout << "Which expense you want to update: ";
            cin >> pos;
            string newType;
            int newAmount;
            cout << "New Type:  ";
            cin >> newType;
            cout << "New Amount:  ";
            cin >> newAmount;
            L.updateExpense(pos, newType, newAmount);} 
		else if (choice == 3){
            L.display();} 
		else if (choice == 0){
            break;} 
		else{
            cout << "Invalid"<<endl;}
		}
		return 0;
}


















