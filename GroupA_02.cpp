// Implement all the functions of a dictionary (ADT) using hashing and handle collisions
// using chaining with / without replacement.
// Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
// must be unique
// Standard Operations: Insert(key, value), Find(key), Delete(key) 

#include <iostream>
#include <string.h>

using namespace std;

struct data
{
    char name[30];
    char meaning[30];
};

class hashing
{
    int n, sum, index, c;
    char na[30], na1[30];
    data d[10];

public:
    hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            strcpy(d[i].name, "\0");
        }
    }
    void insert();
    void search();
    void remove();
    void display();
};

void hashing::insert()
{
    cout << "\nEnter no. of words to be added: ";
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cout << "\nEnter the word: ";
        cin >> na;
        cout << "Enter the meaning of the word: ";
        cin >> na1;
        sum = 0;
        for (int i = 0; i < strlen(na); i++)
        {
            sum = sum + na[i];
        }
        index = (sum / strlen(na)) % 10;
        c = index;
        while (1)
        {
            if (!strcmp(d[index].name, "\0"))
            {
                strcpy(d[index].name, na);
                strcpy(d[index].meaning, na1);
                break;
            }
            index = (index + 1) % 10;
            if (c == index)
            {
                cout << "\nHash table is full." << endl;
                break;
            }
        }
    }
}

void hashing::search()
{
    cout << "\nEnter the word whose meaning you want: ";
    cin >> na;
    sum = 0;
    for (int i = 0; i < strlen(na); i++)
    {
        sum = sum + (int)na[i];
    }
    index = (sum / strlen(na)) % 10;
    c = index;
    while (1)
    {

        if (!strcmp(d[index].name, na))
        {
            cout << "\nMEANING -> " << d[index].name << " = " << d[index].meaning << endl;
            break;
        }
        index = (index + 1) % 10;
        if (c == index)
        {
            cout << "\nWord not found." << endl;
            break;
        }
    }
}

void hashing::remove()
{
    cout << "\nEnter the word which is to be removed: ";
    cin >> na;

    sum = 0;
    for (int i = 0; i < strlen(na); i++)
    {
        sum = sum + (int)na[i];
    }
    index = (sum / strlen(na)) % 10;
    c = index;
    while (1)
    {

        if (!strcmp(d[index].name, na))
        {
            cout << "\n" << d[index].name << " word removed." << endl;
            strcpy(d[index].name, "\0");
            strcpy(d[index].meaning, "\0");
            break;
        }
        index = (index + 1) % 10;
        if (c == index)
        {
            cout << "Word not found" << endl;
            break;
        }
    }
}

void hashing::display()
{
    for (int i = 0; i < 10; i++)
    {
        cout << endl
             << d[i].name << " " << d[i].meaning;
    }
}

int main()
{
    hashing h;
    int n;
    while (1)
    {
        cout<<endl;
        cout << "1.Insert word and its meaning" << endl;
        cout << "2.Find meaning" << endl;
        cout << "3.Remove the word" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter the choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.search();
            break;
        case 3:
            h.remove();
            break;
        case 4:
            exit(0);
        default:
            cout << "\nUnknown choice.";
        }
    }
    return 0;
}
