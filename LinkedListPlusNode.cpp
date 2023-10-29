#include<iostream>
#include<vector>
#include<memory>
using namespace std;

// Declaring A Template For Node
template <typename T> 
class node{
    // Private Class Variables
    private:
    T data;

    // Public Class Variables
    public:
    node* next;
    node* prev;
    
    // Default Constructor
    node(){
        next=NULL;
        prev=NULL;
    }

    // Setter
    void set_data(T input){
        data=input;
    }

    // Getter
    T get_data(){
        return data;
    }
};

// Declaring A Template For Linked_List
template <typename T> class linked_list{
    
    // Private Class Variables
    private:
    
    // Front of the linked list Index = 0
    node<T>* head;

    // Back of the linked list Index = count
    node<T>* tail;    
    
    // Number of nodes in the linked_list
    int count;
    
    // Public Class Variables
    public:
    linked_list(){
        head=NULL;
        tail=NULL;
        count = 0;
    }
    ~linked_list(){
        node<T>* tmp = head->next;
        for(int i = 0;i<count-1;i++){
            delete tmp->prev;
            tmp = tmp -> next;
        }
    delete tail;
    }

    void popall(){
        while(count>0){
            pop();
        }
    }

    void pop(){
        remove_node(0);
    }

    // Adding node at end of list
    void add_node_at_tail(T input) {
        
        // Keeping track of the number of nodes
        count++;

        // Creating a new node
        node<T>* tmp = new node<T>;
        
        // Setting the new node's data
        tmp -> set_data(input);

        // Checking to see if this is the first element
        if(count == 1){
            
            // Setting the head and tail to the new node as it is the only one in list
            head=tmp;
            tail=tmp;
        }

        else{

            // setting the current tail's next to point towards the new node
            tail->next = tmp;

            // setting the current node's prev to point towards the current tail
            tmp->prev = tail;

            // setting the tail to be the new node
            tail = tmp;
        }
    }

    // Adding node at the beginning of the list
    void add_node_at_head(T input) {

        // Keeping track of the number of nodes
        count ++;

        // Creating a new node
        node<T>* tmp = new node<T>;

        // Setting the new node's data
        tmp -> set_data(input);

        // Checking to see if this is the first node being insterted
        if(count == 1){

            // Setting the head and tail to the new node
            head=tmp;
            tail=tmp;
        }
        else{

            // Setting the current head's prev to be the new node
            head->prev=tmp;

            // Setting the new node's next to point towards the current head
            tmp->next=head;

            // Setting the new node to be the new head
            head=tmp;
            
        }
    }

    // Removing a node at index
    void remove_node(int index) {
        
        // Checking to see if the list was indexed correctly
         if(index<0 | index>(count-1)){
            cout << "error index incorrect"<<endl;
            abort();
        }
        
        // Creating a temporary node to use head
        node<T>* tmp = head;

        // Incrementing down the list to the target node
        for(int i =0;i<index;i++){
            tmp = tmp-> next;   
        }

        // Keeping track of the number of elements
        count--;
        
        // Normal case if the node isn't the head or tail
        if((tmp != head) & (tmp != tail)){

            // Sets a temporary node to the node before(towards the head) the target node
            node<T>* before = tmp->prev;

            // Sets a temporary node to the node after(towards the tail) the target node
            node<T>* after = tmp->next;

            // Setting the next of the node before the target to point to the node after the target
            before->next = after;

            // Setting the prev of the node after the target to point to the node before the target
            after->prev = before;

            delete tmp;
            return;
        }

        // Case if the node is the tail
        if(tmp == tail){

            // Setting the current tail to the 2nd to last node
            tail = tmp -> prev;

            // Setting the new tail to point to NULL
            tail-> next = NULL;

            delete tmp;
            return;
        }

        // Case if the node is the head
        if(tmp == head){

            // Setting the new head to be the term after the current head
            head = tmp->next;

            // Setting the new head to point to NULL
            head->prev = NULL;

            delete tmp;
            return;
        }
    }
    
    // Function to get a specific data point from the list
    T get_list_data(int index){

        // Error checking to make sure list was indexed correctly
        if(index<0 | index>(count-1)){
            cout << "error index incorrect" << endl;
            abort();
        }

        // Declaring temporary node
        node<T>* tmp = head;
        
        // Incrementing thorugh list
        for(int i =0;i<index;i++){
            tmp = tmp -> next;
        }

        // Sending the data of the node back
        return(tmp -> get_data());
    }
    
    // Printing the list in reverse order
    void print_list_from_tail() {

        // Creating a temporary node starting at the tail
        node<T>* tmp = tail;

        // Tracking the number of nodes printed from the list 
        while(tmp){

            // Printing each data point of the list
            cout << (tmp -> get_data()) << endl;

            // Incremnting backwards throught the list
            tmp = tmp -> prev;
        }
    }
    
    // Printing the list in order
    void print_list_from_head() {

        // Setting a tempporary node at head
        node<T>* tmp = head;

        // Tracking the number of nodes that have been printed
        while(tmp){

            // Printing the data of each individual node
            cout << (tmp -> get_data()) << endl;

            // Advancing to the next node
            tmp = tmp -> next;
        }
    }

    // Editing an individual node
    void edit_node(int index, T input){

        // Checking to make sure the list is indexed 
         if(index<0 | index>(count-1)){
            cout << "error index incorrect"<<endl;
            abort();
        }

        // Creating a temporary node 
        node<T>* tmp = head;

        // Incrementing to the target node
        for(int i = 0;i<index;i++){
            tmp = tmp-> next;
        }

        // Setting the nodes new data
        tmp->set_data(input);
    }
};
