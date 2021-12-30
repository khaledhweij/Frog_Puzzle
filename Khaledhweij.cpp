#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Node
{
    public:
    string data;
    Node* prev; // Pointer to previous node 
};

string swap(string originalString, int left, int right);
std::vector< Node* > findSuccessor(Node* parent,int& c);
stack<string> returnPath(Node* goal);
void printPath(stack<string>  finalPath); 
void showQueue(queue<Node*> gq);

int main(){

    Node* head = new Node;
    head->data="bbb-ggg The starting position";
    head->prev=NULL;
    //head->next=NULL;
    queue<Node*> open;
    queue<Node*>closed;
    std::vector< Node* > successors;
    int counter=0;
    stack<string> finalPath;
    open.push(head);
    while(!open.empty()){
        Node* tmp = new Node;
        tmp=open.front();
        
        //showQueue(open); //print open queue
        //showQueue(closed); //print closed queue
        if(tmp->data.substr(0,7)=="ggg-bbb"){
            finalPath = returnPath(tmp);
            printPath(finalPath);
            break;
        }
        else{
            open.pop();
            closed.push(tmp);
            successors = findSuccessor(tmp,counter);
            for(int i =0;i<successors.size();i++){
                open.push(successors[i]);

            }

        }

    }
    //cout<<closed.size()<<endl; //number of expanded nodes since it is a BFS

    return 0;
}

string swap(string originalString, int left, int right) {
	string newString = originalString;                //creating new string to not change the original one.
	char tmp = originalString[left];
	newString[left] = newString[right];
	newString[right] = tmp;
	return newString;
}

std::vector< Node* > findSuccessor(Node* parent,int& c) {

	std::vector< Node* > children;

    string x =parent->data.substr(0,7);
	int i = 0;
	if (x.find("-") != 6 && x[x.find("-") + 1] == 'g') {
        Node* tmp = new Node;
        tmp->data=swap(x, x.find("-"), x.find("-") + 1)+" Green frog on place "+to_string(x.find("-")+2)+" moves left";
        tmp->prev=parent;
		children.push_back(tmp);
		i++;
	} //checking if a green frog can move one step to the left

	if (x.find("-") <= 5 && x[x.find("-") + 2] == 'g') {
        Node* tmp = new Node;
        tmp->data=swap(x, x.find("-"), x.find("-") + 2)+" Green frog on place "+to_string(x.find("-")+3)+" jumps left";
        tmp->prev=parent;
		children.push_back(tmp);
		i++;
	} //checking if a green frog can move two steps to the left

	if (x.find("-") != 0 && x[x.find("-") - 1] == 'b') {
		Node* tmp = new Node;
        tmp->data=swap(x, x.find("-"), x.find("-") - 1)+" Brown frog on place "+to_string(x.find("-"))+" moves right";
        //parent->next=tmp;  
        tmp->prev=parent;
       // tmp->next=NULL;
		children.push_back(tmp);
		i++;
	} //checking if a brown frog can move one step to the right

	if (x.find("-") >= 2 && x[x.find("-") - 2] == 'b') {
		Node* tmp = new Node;
        tmp->data=swap(x, x.find("-"), x.find("-") - 2)+ " Brown frog on place "+to_string(x.find("-")-1)+" jumps right";
        tmp->prev=parent;
		children.push_back(tmp);
		i++;
	} //checking if a brown frog can move two steps to the right

	if(i!=0)
	c++;

	return children; // return list of nodes
}

stack<string> returnPath(Node* goal){
    stack<string> finalPath;
    Node* tmp=goal;
    while(tmp->prev != NULL){
        finalPath.push(tmp->data);
        tmp=tmp->prev;
    }
    finalPath.push("bbb-ggg The starting position");
    return finalPath;

}

void printPath(stack<string> finalPath){
    while(!finalPath.empty()){
        cout<<finalPath.top()<<endl;
        finalPath.pop();
    }
}

void showQueue(queue<Node*> gq)
{
	queue<Node*> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.front()->data.substr(0,7);
		g.pop();
	}
	cout << '\n';
}
