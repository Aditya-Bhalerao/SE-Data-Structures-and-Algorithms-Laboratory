// Consider telephone book database of N clients. Make use of a hash table implementation
// to quickly look up client‘s telephone number. Make use of two collision handling
// techniques and compare them using number of comparisons required to find a set of
// telephone numbers

#include <iostream>

using namespace std;

class node
{
    string name;
    long int tel;
    int in;

public:
    node()
    {
        name = "";
        tel = 0;
        in = 0;
    }
    friend class hashing;
};


class hashing
{
    node data[100];
    string n;
    long int t;
    int index = 0, id;

public:
    hashing()
    {
        id = 0;
        t = 0;
    }

    void create_record_linearprobing(int sizeofarr)
    {
        for (int i = 0; i < sizeofarr; i++)
        {
            cout << "\nEnter details of Person: " << i + 1 << endl;
            cout << "Id: ";
            cin >> id;
            cout << "Name: ";
            cin >> n;
            cout << "Telephone number: ";
            cin >> t;
            index = id % sizeofarr;
            {
                if (data[index].in == 0)
                {
                    data[index].in = id;
                    data[index].name = n;
                    data[index].tel = t;
                }
                else
                    index = (index + (i + 1)) % sizeofarr;
            }
        }
        cout << "\nTelephone book Created." << endl;
    }

    void create_record_quadraticprobing(int sizeofarr)
    {
        for (int i = 0; i < sizeofarr; i++)
        {
            cout << "\nEnter details of Person: " << i + 1 << endl;
            cout << "Id: ";
            cin >> id;
            cout << "Name: ";
            cin >> n;
            cout << "Telephone number: ";
            cin >> t;
            index = id % sizeofarr;
            for (int j = 0; j < sizeofarr; j++)
            {
                if (data[index].in == 0)
                {
                    data[index].in = id;
                    data[index].name = n;
                    data[index].tel = t;
                }
                else
                    index = (index + ((j + 1) * (j + 1))) % sizeofarr;
            }
        }
        cout << "\nTelephone book Created." << endl;
    }

    void search_record_linear(int sizeofarr, int key)
    {
        int flag = 0;
        index = key % sizeofarr;
        for (int a = 0; a < sizeofarr; a++)
        {
            if (data[index].in == key)
            {
                flag = 1;
                cout << "\nRecord found: " << endl;
                cout << "Id: " << data[index].in << endl;
                cout << "Name: " << data[index].name << endl;
                cout << "Telephone: " << data[index].tel << endl;
                break;
            }
            else
                index = (index + 1) % sizeofarr;
        }
        if (flag == 0)
        {
            cout << "\nRecord not found." << endl;
        }
    }

    void search_record_quadratic(int sizeofarr, int key)
    {
        int flag = 0;
        index = key % sizeofarr;
        for (int a = 0; a < sizeofarr; a++)
        {
            if (data[index].in == key)
            {
                flag = 1;
                cout << "\nRecord found: " << endl;
                cout << "Id: " << data[index].in << endl;
                cout << "Name: " << data[index].name << endl;
                cout << "Telephone: " << data[index].tel << endl;
                break;
            }
            else
                index = (index + (a * a)) % sizeofarr;
        }
        if (flag == 0)
        {
            cout << "\nRecord not found." << endl;
        }
    }

    void display_record(int sizeofarr)
    {

        for (int a = 0; a < sizeofarr; a++)
        {
            if (sizeofarr == 0)
            {
                cout << "Telephone book empty." << endl;
                break;
            }
            else if (data[a].in != 0)
            {
                cout << "\nPerson: " << a + 1 << endl;
                cout << "Id: " << data[a].in << endl;
                cout << "Name:" << data[a].name << endl;
                cout << "Telephone: " << data[a].tel << endl;
            }
        }
    }
};

int main()
{
    int sizeofarr = 0;
    int IDl, IDq, ch, ch1;
    hashing hlin, hquad;
    do
    {
        cout << "\n----TELEPHONE BOOK MAIN MENU----" << endl;
        cout << "1. LINEAR PROBING" << endl;
        cout << "2. QUADRATIC PROBING" << endl;
        cout << "3. EXIT" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            do
            {
                cout << "\nLINEAR PROBING" << endl;
                cout << "1. CREATE" << endl;
                cout << "2. SEARCH" << endl;
                cout << "3. DISPLAY" << endl;
                cout << "4. EXIT" << endl;
                cout << "\nEnter your choice: ";
                cin >> ch1;
                switch (ch1)
                {
                case 1:
                    cout << "Enter number of people to be added: ";
                    cin >> sizeofarr;
                    hlin.create_record_linearprobing(sizeofarr);
                    break;
                case 2:
                    cout << "Enter ID to be searched: ";
                    cin >> IDl;
                    hlin.search_record_linear(sizeofarr, IDl);
                    break;
                case 3:
                    cout << "\nDisplaying contents of telephone book." << endl;
                    hlin.display_record(sizeofarr);
                    break;
                case 4:
                    cout << "Program ended." << endl;
                    exit(0);
                }
            }
            while (ch != 4);

        case 2:
            do
            {
                cout << "\nQUADRATIC PROBING" << endl;
                cout << "1. CREATE" << endl;
                cout << "2. SEARCH" << endl;
                cout << "3. DISPLAY" << endl;
                cout << "4. EXIT" << endl;
                cout << "\nEnter your choice: ";
                cin >> ch1;
                switch (ch1)
                {
                case 1:
                    cout << "Enter number of people to be added: ";
                    cin >> sizeofarr;
                    hquad.create_record_quadraticprobing(sizeofarr);
                    break;
                case 2:
                    cout << "Enter ID to be searched: ";
                    cin >> IDq;
                    hquad.search_record_quadratic(sizeofarr, IDq);
                    break;
                case 3:
                    cout << "\nDisplaying contents of telephone book." << endl;
                    hquad.display_record(sizeofarr);
                    break;
                case 4:
                    cout << "Program ended." << endl;
                    exit(0);
                }
            }
            while (ch1 != 4);
        case 3:
            cout << "Program ended." << endl;
            exit(0);
        }
    }
    while (ch != 3);
    return 0;
}
