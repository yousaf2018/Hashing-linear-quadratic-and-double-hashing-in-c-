#include <iostream>

using namespace std;

class Hashing
{
    public:
    Hashing();
    int Hashing_table[10];
    int hashing_function(int);
    int hashing_function_2(int);
    void add_value_in_hash_table(int);
    void display();
    int search_in_hash_table(int);
    int delete_in_hash_table(int);
    void is_full();
    void is_empty();
};
Hashing::Hashing()
{
    for(int a=0;a<10;a++)
    {
        Hashing_table[a]=-1;
    }
}
int Hashing::hashing_function(int data)
{
            return data%10;
}
int Hashing::hashing_function_2(int input)
{
    return 7-(input%7);
}

 void Hashing::add_value_in_hash_table(int input)
{
    int check;
    check=hashing_function(input);
    if(Hashing_table[check]==-1)
    {
        Hashing_table[check]=input;
        return;
    }
    else
    {
    int counter=1;
    while(true)
    {
    if(Hashing_table[(hashing_function(input)+counter*(hashing_function_2(input)))%10]==-1)
    {
    Hashing_table[(hashing_function(input)+counter*(hashing_function_2(input)))%10]=input;
    return;
    }
    counter++;
    if(counter>10)
    {
    return;
    }
    }
    }
}
void Hashing::display()
{
    int a;
    for(a=0;a<10;a++)
    cout << Hashing_table[a] << endl;
}
int Hashing::search_in_hash_table(int input)
{
    int check;
    check=hashing_function(input);
    if(Hashing_table[check]==input)
    {
        return 1;
    }
    else
   {
    int counter=1;
    while(true)
    {
    if(Hashing_table[(hashing_function(input)+counter*(hashing_function_2(input)))%10]==input)
    {
    return 1;
    }
    counter++;
    if(counter>10)
    {
        return -1;
    }
    }

    }
  }
int Hashing::delete_in_hash_table(int input)
{
    int check;
    check=hashing_function(input);
    if(Hashing_table[check]==input)
    {
        Hashing_table[check]=-1;
        return 1;
    }
    else
  {
    int counter=1;
    while(true)
    {
    if(Hashing_table[(hashing_function(input)+counter*(hashing_function_2(input)))%10]==input)
    {
    Hashing_table[(hashing_function(input)+counter*(hashing_function_2(input)))%10]=-1;
    return 1;
    }
    counter++;
    if(counter>10)
    {
        return -1;
    }
    }
  }
}
void Hashing::is_empty()
{
    int a;
    for(a=0;a<10;a++)
    {
        if(Hashing_table[a]!=-1)
        {
            cout << "Hash table is not empty\n";
            return;
        }
    }
    cout << "Hash table is empty\n";
    return;
}
void Hashing::is_full()
{
    int a;
    for(a=0;a<10;a++)
    {
        if(Hashing_table[a]==-1)
        {
            cout << "Hash table is not full\n";
            return;
        }
    }
    cout << "Hash table is full\n";
    return;
}
int main()
{
 Hashing object;
 int check;
        while(true)
        {
                int option,input;
                cout << "****************************************\n";
                cout << "Enter 1 for insert value in Hash table\n";
                cout << "Enter 2 for display\n";
                cout << "Enter 3 for search value in Hash table\n";
                cout << "Enter 4 for remove value in Hash\n";
                cout << "Enter 5 for check is full or not\n";
                cout << "Enter 6 for check is empty or not\n";
                cout << "****************************************\n";
                cin >> option;
                if(option==1)
                {
                        cout << "Enter value to insert in Hash table\n";
                        cin >> input;
                        object.add_value_in_hash_table(input);
                }
                else if(option==2)
                {
                        object.display();
                }
                else if(option==3)
                {
                        cout << "Enter value you want to search\n";
                        cin >> input;
                        check=object.search_in_hash_table(input);
                        if(check==-1)
                        {
                                cout << "No match value is found in Hash table\n";
                        }
                        else if(check==1)
                        {
                                cout << "Yes value is matched in Hash table\n";
                        }
                }
                else if(option==4)
                {
                        cout << "Enter value you want to remove\n";
                        cin >> input;
                        check=object.delete_in_hash_table(input);
                        if(check==-1)
                        {
                                cout << "No match value is found in Hash table\n";
                        }
                        else if(check==1)
                        {
                                cout << "Yes value is deleted in Hash table\n";
                        }
                }
                else if(option==5)
                {
                        object.is_full();
                }
                else if(option==6)
                {
                        object.is_empty();
                }

        }
}

