#include <iostream>


using namespace std;

//basic linked list node class with 3 constructors
class Node{
public:
    string data;
    Node* next;

    Node(string data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(string data1){
        data = data1;
        next = nullptr;
    }

    Node(){
        data = "";
        next = nullptr;
    }


};

//stack data structure of type string
struct StringStack{

    private:
    //Stores head element
    Node* head;

    public:
    //overloaded constructor of type StringStack
    StringStack(){
     head = new Node();
    }

    StringStack(string data1){
     head = new Node(data1);
    }

    StringStack(string data1, Node* next1){
     head = new Node(data1, next1);
    }

    //stringStack functions
    //returns the top element
    string PeekStrStack(){
        if(!IsEmpty()) return head->data;
        return "empty";
    }

    //checks if stack is empty
    bool IsEmpty(){
     if (head->data.empty()) return true;
     else return false;
    }

    //removes and outputs the first element returns "error" if empty
    string PopStack(){
        if(!IsEmpty()) {
            Node* temp = head;
            head = head->next;
            return temp->data;
        }
        else return "error";

    }

    //adds element of type string to stack
    void PushStack(string data1){
        Node* temp = head;
        head = new Node(data1, temp);
    }

    //return numbers of elements in set(int)
    int ElementsInStack(){
        if(IsEmpty()) return 0;

        int counter = 0;
        Node* temp = head;
        while(temp->next != NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    //outputs all string to console
    void ShowStack(){

        if(IsEmpty())
            cout << "empty" << endl;

        Node* temp = head;
        while(temp->next != NULL){
            if (temp->next->next == NULL) break;
            cout << temp ->data << ", ";
            temp = temp->next;
        }
        cout << temp ->data << "\n";

    }

};

int main(){

    bool running = true;
    StringStack documents = StringStack();

    while(running){
        string check = "Y";
        bool cont = true;

        //Add documents with text UI
        while(cont){
            cout << "Add any documents?(Y/N) ";
            cin >> check;

            if(check == "Y"){
                cout << "Enter document name: ";
                cin >> check;
                documents.PushStack(check);
                cout << "There is " << documents.ElementsInStack() << " document(s) left to complete." << endl;
            }
            else
            cont=false;
        }

        //Mark Completion for top document
        cont = true;
        while(cont && !documents.IsEmpty()){
            cout << "Is " << documents.PeekStrStack() << " complete?(Y/N) ";
            cin >> check;
            if(check == "Y"){
                cout << documents.PopStack() << " is completed!" << endl;
                cont == false;
                cout << "There is " << documents.ElementsInStack() << " document(s) left to complete." << endl;
            }
            else if(check == "N")
                cont = false;
        }

        //View remaining documents in stack if not empty
        if(check != "Y") cout << "There is " << documents.ElementsInStack() << " document(s) left to complete." << endl;
        cout << "Documents left to complete: " << endl;
        if(!documents.IsEmpty()) documents.ShowStack();

        //ask to close program
        cont = true;
        while(cont){
            cout << "Would you like to continue?(Y/N) ";
            cin >> check;
            if(check == "N"){
                running = false;
                cont = false;
            }
            else if(check=="Y")
                cont=false;
        }
    }


return 0;
}
