#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#include <unistd.h>
class Transaction
{
private:
    int transactionID;
    string transactionName;
    string transactionDate;

public:
    Transaction() {}
    Transaction(int id, string name, string date)
    {
        transactionID = id;
        transactionName = name;
        transactionDate = date;
    }

    // SETTERS
    void set_id(int id) { transactionID = id; }
    void set_name(string name) { transactionName = name; }
    void set_date(string date) { transactionDate = date; }
    // GETTERS
    int get_id() { return transactionID; }
    string get_name() { return transactionName; }
    string get_date() { return transactionDate; }

    void print_transaction_info()
    {

        cout << "Transaction ID is : " << get_id() << endl;
        cout << "Transaction Name is : " << get_name() << endl;
        cout << "Transaction Date is : " << get_date() << endl;
    }
};

class Client
{
private:
    // Attributes
    string clientName, clientEmail, clientPhone, clientAddress, clientPassword;
    int clientID;
    int n;
    Transaction ar[5];

public:
    // Constructor
    Client(string name, string email, string phone, string address)
    {
        clientName = name;
        clientEmail = email;
        clientPhone = phone;
        clientAddress = address;
        n = 0;
    }

    // SETTERS
    void set_name(string n) { clientName = n; }
    void set_email(string e) { clientEmail = e; }
    void set_phone(string p) { clientPhone = p; }
    void set_address(string A) { clientAddress = A; }
    void set_password(string pass) { clientPassword = pass; }
    void set_id(int id) { clientID = id; }
    void set_arr()
    {
        srand(time(NULL));
        Transaction transaction1(rand(), "Transaction 1", "01/Jan/2022");
        Transaction transaction2(rand(), "Transaction 2", "02/Jan/2022");
        Transaction transaction3(rand(), "Transaction 3", "03/Jan/2022");
        Transaction transaction4(rand(), "Transaction 4", "04/Jan/2022");
        Transaction transaction5(rand(), "Transaction 5", "05/Jan/2022");
        if (n <= 4)
        {
            if (n == 0)
                ar[n] = transaction1;
            if (n == 1)
                ar[n] = transaction2;
            if (n == 2)
                ar[n] = transaction3;
            if (n == 3)
                ar[n] = transaction4;
            if (n == 4)
                ar[n] = transaction5;
            n++;
            cout << "The Transaction was Created successfully" << endl;
            sleep(1);
        }
        else
            cout << "You cant create more than 5 Transaction" << endl;
    }

    // GETTERS

    string get_name() { return clientName; }
    string get_email() { return clientEmail; }
    string get_phone() { return clientPhone; }
    string get_address() { return clientAddress; }
    string get_password() { return clientPassword; }
    int get_id() { return clientID; }
    int get_n() { return n; }
    Transaction get_arr(int n) { return ar[n]; }

    // Print function

    void print_client_info()
    {
        cout << "Client Name: " << get_name() << endl;
        cout << "Client Email: " << get_email() << endl;
        cout << "Client Phone: " << get_phone() << endl;
        cout << "Client ID: " << get_id() << endl;
        cout << "-----" << endl;
    }

    // Delete function

    void remove_transaction(int index)
    {
        for (int i = index; i < n - 1; i++)
        {
            ar[i] = ar[i + 1];
        }
        n--;
        cout << "Number of transactions left is " << n << endl;
    }
};

Client *user;

class LinkedListNode
{
    Client *data;
    LinkedListNode *next;

public:
    // Constructor
    LinkedListNode(Client *d)
    {
        data = d;
        next = NULL;
    }
    // Getters
    Client *getData() { return data; }
    LinkedListNode *getNext() { return next; }
    // Setters
    void setData(Client *d) { data = d; }
    void setNext(LinkedListNode *n) { next = n; }
};

class ClientsLinkedList
{
    LinkedListNode *head;

public:
    // Constructor
    ClientsLinkedList() { head = NULL; }

    // Getters
    LinkedListNode *getHead() { return head; }

    // Setters
    void setHead(LinkedListNode *h) { head = h; }

    // Functions
    void addClient(Client *c)
    {
        LinkedListNode *newNode = new LinkedListNode(c);
        newNode->setNext(head);
        head = newNode;
    }
    bool checkEmail(string email)
    {
        LinkedListNode *curr = head;
        while (curr != NULL)
        {
            if (curr->getData()->get_email() == email)
                return true;
            curr = curr->getNext();
        }
        return false;
    }

    Client *login(string email, string password)
    {
        LinkedListNode *curr = head;
        while (curr != NULL)
        {
            if (curr->getData()->get_email() == email && curr->getData()->get_password() == password)
                return user = curr->getData();
            curr = curr->getNext();
        }
        return NULL;
    }
};

void mainMenu();
ClientsLinkedList clientsList;
void clientHome();
void transactionsMenu()
{
    cout << "++++++++++++++ Welcome to the Transactions system ++++++++++++++" << endl;
    cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS:" << endl;
    cout << "1) Create a new transaction" << endl;
    cout << "2) View your transactions" << endl;
    cout << "3) Delete a transaction by its ID" << endl;
    cout << "4) Return to the Home Page " << endl;

    int choice;
    while (true)
    {
        cin >> choice;
        if (choice == 1)
        {
            user->set_arr();
            transactionsMenu();
        }
        else if (choice == 2)
        {
            cout << "Your Transaction are : " << endl;
            for (int i = 0; i < user->get_n(); i++)
                user->get_arr(i).print_transaction_info();
            sleep(1);
            transactionsMenu();
        }
        else if (choice == 3)
        {
            bool check = false;
            int id;
            cout << "Enter the ID of the transaction you wish to delete: ";
            cin >> id;
            for (int i = 0; i < user->get_n(); i++)
            {
                if (user->get_arr(i).get_id() == id)
                {
                    user->remove_transaction(i);
                    cout << "Transaction successfully deleted." << endl;
                    check = true;
                    break;
                }
            }
            if (!check)
                cout << "Transaction not found" << endl;
            sleep(1);
            transactionsMenu();
        }
        else if (choice == 4)
        {
            clientHome();
        }
    }
}

void clientHome()
{
    cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS:" << endl;
    cout << "1) Transactions" << endl;
    cout << "2) View personal info" << endl;
    cout << "3) Logout" << endl;

    int choice;

    while (true)
    {
        cin >> choice;
        if (choice == 1)
            transactionsMenu();
        else if (choice == 2)
        {
            user->print_client_info();
            clientHome();
        }
        else if (choice == 3)
            mainMenu();
    }
}

void loginMenu()
{
    string email, password;
    cout << "Please enter your email: ";
    cin >> email;
    cout << "Please enter your password: ";
    cin >> password;
    Client *loggedInClient = clientsList.login(email, password);
    if (loggedInClient == NULL)
    {
        cout << "Incorrect email or password, please try again." << endl;
        mainMenu();
    }
    else
    {
        cout << "Welcome, " << loggedInClient->get_name() << "!" << endl;
        clientHome();
    }
}
LinkedListNode *arr[10];
void hashInsert(Client *c)
{
    int index = c->get_id() % 10;
    LinkedListNode *newNode = new LinkedListNode(c);
    LinkedListNode *curr = arr[index];
    if (arr[index] == NULL)
        arr[index] = newNode;
    else
    {
        while (curr->getNext() != NULL)
            curr = curr->getNext();
        curr->setNext(newNode);
    }
}
void newClientMenu()
{
    cout << "++++++++++++++ Create a new client account ++++++++++++++" << endl;
    string name, email, phone, address, password;

    // Taking the INFO
    cout << "Please Enter your Name: ";
    cin >> name;
    cout << "Please Enter your Email: ";
    cin >> email;
    if (clientsList.checkEmail(email))
    {
        cout << "This email is already in use, please try again" << endl;
        newClientMenu();
        return;
    }
    cout << "Please Enter your Phone Number: ";
    cin >> phone;
    cout << "Please Enter your Address: ";
    cin >> address;
    cout << "Please Enter your Password: ";
    cin >> password;

    // Making the data as a new node of type LinkedListNode
    Client *c = new Client(name, email, phone, address);
    srand(time(0));
    c->set_id(rand());
    c->set_password(password);
    clientsList.addClient(c);
    hashInsert(c);
    // Sending the user to the main menu
    cout << "Your Account was Created successfully ,Try to login now" << endl;
    sleep(1);
    mainMenu();
}

void forget_password()
{
    string email;
    cout << "Enter your Email: " << endl;
    cin >> email;

    cout << "1) See your current password " << endl;
    cout << "2) Change your current password " << endl;

    LinkedListNode *curr = clientsList.getHead();
    int n;
    cin >> n;
    while (n != 1 & n != 2)
    {
        cout << "Please enter 1 or 2 " << endl;
        cin >> n;
    }
    bool check = false;
    while (curr != NULL)
    {
        if (curr->getData()->get_email() == email)
        {
            if (n == 1)
            {
                cout << "Your Password is : " << curr->getData()->get_password() << endl;
                check = true;
            }
            else if (n == 2)
            {
                cout << "Please Enter your new password: " << endl;
                string pass;
                cin >> pass;
                while (pass == curr->getData()->get_password())
                {
                    cout << "You cant set your new password as the old " << endl;
                    cout << "Please Enter your new password: " << endl;
                    cin >> pass;
                }
                curr->getData()->set_password(pass);
                cout << "Your Password was Changed successfully" << endl;
                check = true;
            }
        }
        curr = curr->getNext();
    }
    if (!check)
        cout << "The Email is not found " << endl;

    sleep(1);
    mainMenu();
}
int listSize(LinkedListNode *head)
{
    int size = 0;
    LinkedListNode *current = head;
    while (current != NULL)
    {
        current = current->getNext();
        size++;
    }
    return size;
}
void swap(LinkedListNode &a, LinkedListNode &b)
{
    LinkedListNode temp = a;
    a = b;
    b = temp;
}
int partition(LinkedListNode **arr, int low, int high)
{
    int pivot = listSize(arr[high]);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (listSize(arr[j]) <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(LinkedListNode **arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


// Bonus Function
void sortLinkedLists(LinkedListNode *arr[])
{
    for (int i = 0; i < 10; i++)
    {

        LinkedListNode *curr = arr[i];
        while (curr != NULL)
        {
            LinkedListNode *min = curr;

            LinkedListNode *temp = curr->getNext();

            while (temp != NULL)
            {
                if (temp->getData()->get_id() < min->getData()->get_id())
                    min = temp;

                temp = temp->getNext();
            }
            swap(curr, min);

            curr = curr->getNext();
        }
    }
}
void print()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Number of clients in index " << i << " is " << listSize(arr[i])<<endl;
        LinkedListNode *curr = arr[i];
        if (curr == NULL)
            cout << " No Clients" << endl;
        else
            while (curr != NULL)
            {
                curr->getData()->print_client_info();
                curr = curr->getNext();
            }
    }
    mainMenu();
}
void mainMenu()
{
    cout << "++++++++++++++++++++++++WELCOME TO THE BANK SYSTEM++++++++++++++++++++++++" << endl;
    cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS " << endl;
    cout << "1) Login to your account " << endl;
    cout << "2) Add New Client " << endl;
    cout << "3) Forgot your password? " << endl;
    cout << "4) Printing All Clients" << endl;
    cout << "5) Sort clients by linked list size using the Quick Sort Algorithm " << endl;
    cout << "6) Sort clients by using their id's (Bonus Part)" << endl;
    cout << "7) Exit the program " << endl;
    int choice;
    while (true)
    {
        cin >> choice;
        if (choice == 1)
            loginMenu();
        else if (choice == 2)
            newClientMenu();
        else if (choice == 3)
            forget_password();
        else if (choice == 4)
            print();
        else if (choice == 5)
        {
            quickSort(arr, 0, 9);
            cout << "The array after sorting: " << endl;
            print();
        }
        else if (choice == 6)
        {
            sortLinkedLists(arr);
            print();
        }
        else if (choice == 7)
            exit(0);
        else
        {
            cout << "Invalid option,Please try again " << endl;
            sleep(1);
            mainMenu();
        }
    }
}

int main()
{
    mainMenu();
}