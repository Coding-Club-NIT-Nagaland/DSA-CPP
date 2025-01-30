#include <iostream>
#include <vector>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

   //Write a function to Insert a Linked List at Head and test 


    //Write a Print Function to Print ELement of Linked List and test 

  //Write a function to Insert a Linked List at Tail and test 


  //After fixing the code , you merge the updated code in git //



};

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    Node *node1 = new Node(arr[2]);
    
   cout << node1->data << endl;
    cout << node1->next << endl;

    cout << "............................................" << endl;

     node1->InsertAtHead(node1,2);

    cout<<node1->data<<endl;
    cout<<node1->next<<endl;  

    node1->InsertAtTail(node1,8);
    cout << node1->data << endl;
    cout << node1->next << endl;




    




   

    return 0;
}