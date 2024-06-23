#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    //Gawa empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    //Linis queue
    ~Queue() {
        while (!isEmpty()) {
            dequeue();  //dequue all
        }
    }

    //function para magadd ng customer sa queue
    void enqueue(int value) {
        Node* newNode = new Node();  //create new node
        newNode->data = value;  //set the customer's ticket number
        newNode->next = nullptr;  //new node will be last one, so next is nullptr
        if (isEmpty()) {
            front = newNode;  //pag queue is empty, the new node is both front and rear
            rear = newNode;
        }
        else {
            rear->next = newNode;  //link the new node to the end of the queue
            rear = newNode;  //update the rear to the new node
        }
        cout << "++++Customer " << value << " added to the queue.++++\n\n";
    }

    //function para maremove and serve yung customer sa front ng queue
    void dequeue() {
        Node* temp = front;  //temporarily store the front node
        front = front->next;  //move the front pointer to the next node
        cout << "|||Serving customer " << temp->data << ".|||\n\n";
        delete temp;  //delete the old front node
        if (front == nullptr) {
            rear = nullptr;  //if the queue is now empty, set rear to nullptr
        }
    }

    //function if may laman pa yung queue
    bool isEmpty() {
        return front == nullptr;  //empty na pag front = nullptr
    }

    //function peek next customer text
    void peek() {
        if (!isEmpty()) {
            cout << "[[Next customer to be served: " << front->data << "]]\n\n";
        }
    }

    //function display currentqueue
    void display() {
        Node* temp = front;  //ftart from the front of the queue
        cout << "-- Current queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";  //print the data of each node
            temp = temp->next;  //move to the next node
        }
        cout << "--\n\n";
        if (isEmpty()) {
            cout << "[[Queue is empty]]\n\n";
        }
    }
};

//function loading effect
void loading() {
    cout << "Processing";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::seconds(1));  //delay for 1 second
    }
    cout << "\n\n";
}

//function para madisplay yung title screen
void displayTitle() {
    cout << "*************************************\n";
    cout << "*       WELCOME TO FANTALITE        *\n";
    cout << "*             CINEMAS               *\n";
    cout << "*              !!!!                 *\n";
    cout << "*************************************\n";
    cout << "Opening Ticketing System...\n";
    this_thread::sleep_for(chrono::seconds(2)); //delay for 2 seconds
}

//function ticket for each customer
int generateTicketNumber() {
    static int ticketNumber = 1000;  //starting number ticket
    return ticketNumber++;  //increment and return the ticket number
}

//function to simulate the arrival of a customer and add them to the queue
void simulateCustomerArrival(Queue& queue) {
    int ticket = generateTicketNumber();  //generate new ticket number
    queue.enqueue(ticket);  //add the customer to the queue
}

int main() {
    displayTitle();  //function title screen
    Queue cinemaQueue;  //Gawa ng empty queue

    //simulate customer arrivals and add them to the queue
    simulateCustomerArrival(cinemaQueue);
    loading();
    simulateCustomerArrival(cinemaQueue);
    loading();
    simulateCustomerArrival(cinemaQueue);
    loading();
    simulateCustomerArrival(cinemaQueue);
    loading();
    simulateCustomerArrival(cinemaQueue);
    loading();
    simulateCustomerArrival(cinemaQueue);

    //serve customers and display the state of the queue after each operation
    cinemaQueue.peek();  //show the next customer to be served
    loading(); //processing text and delay
    cinemaQueue.dequeue();  //serve the customer and dequeue
    cinemaQueue.peek();
    cinemaQueue.display();  //display the current queue
    loading();
    cinemaQueue.dequeue();
    cinemaQueue.peek();
    cinemaQueue.display();
    loading();
    cinemaQueue.dequeue();
    cinemaQueue.peek();
    cinemaQueue.display();
    loading();
    cinemaQueue.dequeue();
    cinemaQueue.peek();
    cinemaQueue.display();
    loading();
    cinemaQueue.dequeue();
    cinemaQueue.peek();
    cinemaQueue.display();
    loading();
    cinemaQueue.dequeue();
    cinemaQueue.peek();
    cinemaQueue.display();

    return 0;
}
