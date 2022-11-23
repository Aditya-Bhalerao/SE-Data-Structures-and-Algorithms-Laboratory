// A book consists of chapters, chapters consist of sections and sections consist of
// subsections. Construct a tree and print the nodes. Find the time and space requirements
// of your method. 

#include <iostream>
#include <string.h>

using namespace std;

struct node
{
    char title[100];
    int count;
    node *child[20];
};

class Book
{
private:
    node *root;

public:
    void insert();
    void display();
    Book()
    {
        root = NULL;
    }
};

void Book::insert()
{
    root = new node;
    cout << "\nEnter title of book: ";
    cin >> root->title;
    cout << "\nEnter number of chapters in the book: ";
    cin >> root->count;
    for (int i = 0; i < root->count; i++)
    {
        root->child[i] = new node;
        cout << "\nEnter chapter " << i + 1 << " name: ";
        cin >> root->child[i]->title;
        cout << "Enter number of sections in Chapter " << root->child[i]->title << " : ";
        cin >> root->child[i]->count;
        for (int j = 0; j < root->child[i]->count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->title;
        }
    }
}

void Book::display()
{
    cout << "\nDisplaying book information- " << endl;
    ;
    cout << "Book title: " << root->title;
    for (int i = 0; i < root->count; i++)
    {
        cout << "\nChapter " << i + 1 << ". " << root->child[i]->title;
        cout << "\nSections - " << endl;
        for (int j = 0; j < root->child[i]->count; j++)
        {
            cout << j + 1 << ". " << root->child[i]->child[j]->title << endl;
        }
    }
}

int main()
{
    int ch;
    Book b;
    while (int flag = 1)
    {
        cout << "\n-----------------" << endl;
        cout << "1.Create a book." << endl;
        cout << "2.Display contents of the book." << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.insert();
            flag = 1;
            break;
        case 2:
            b.display();
            flag = 1;
            break;
        case 3:
            exit(1);
        default:
            cout << "\nWrong choice. Enter again." << endl;
            flag = 1;
        }
    }
}
