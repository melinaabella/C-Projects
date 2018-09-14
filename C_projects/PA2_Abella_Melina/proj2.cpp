//Melina Abella || CS202 || Project 2 || 9 - 12 - 18

#include <iostream>
#include <fstream>

using namespace std;

struct RentalCar
{
    int year;
    char make[10];
    char model[10];
    float price;
    bool available;
    
};
int myStringLength(const char *str);
int myStringCompare(const char *str1, const char *str2);
char *myStringCopy(char *destination, const char *source);
char *myStringCat(char *destination, const char *source);
int txtinput(RentalCar string[5], int i);
void txtoutput(RentalCar string[5], int i);
void display(RentalCar string[], int i);
void swapstruct(RentalCar *string1, RentalCar *string2);
void sortstruct(RentalCar string[]);
void pricestruct(RentalCar string[], int days);
void checking(RentalCar string[], int check);


int main()
{
    
    RentalCar carlist[4];
    
    int option;
    do
    {
        
        cout << "\nOptions:\n";
        cout << "1 - Enter input file name\n";
        cout << "2 - List of cars\n";
        cout << "3 - Enter output file name\n";
        cout << "4 - Sorting prices from low to high\n";
        cout << "5 - How many days?\n";
        cout << "6 - Which car?\n";
        cout << "7 - Exit\n";
        cin >> option;
        
        switch (option)
        {
                
                
            case 1:
                int in;
                txtinput(carlist, in);
                break;
                
            case 2:
                int dis;
                display(carlist, dis);
                break;
                
            case 3:
                int out;
                txtoutput(carlist, out);
                break;
                
            case 4:
                sortstruct(carlist);
                break;
                
            case 5:
                int day;
                cout << "How many days? ";
                cin >> day;
                pricestruct(carlist, day);
                break;
                
                
            case 6:
                int car;
                cout << "Which Car? ";
                cin >> car;
                checking(carlist, car);
                break;
                
        }}while (option != 7);
    
    
    return 0;
}

int myStringLength(char *str)
{
    int i = 0;
    while (*str != '\0')
    {
        str++;
        i++;
    }
    return i;
}

int myStringCompare(const char *str1, const char *str2)
{
    
    char *string1, *string2;
    myStringCopy(string1, str1);
    myStringCopy(string2, str2);
    
    while((*string1 != '\0') && (*string2 != '\0'))
    {
        if ((*string1 >= 65) && (*string1 <= 90))
        {
            *string1 += 32;
        }
        if ((*string2 >= 65) && (*string2 <= 90))
        {
            *string2 += 32;
        }
        if ((*string2 >= 65) && (*string2 <= 90))
        {
            *string2 += 32;
        }
        string1++;
        string2++;
    }
    
    while(*string1 != '\0' && *string2 != '\0')
    {
        if (*string1 < *string2)
            
        {
            return 1;
        }
        else if (*string1 > *string2)
            
        {
            return -1;
        }
        string1++;
        string2++;
    }
    if (*string1 == *string2)
    {return 0;}
    return 0;
}

char *myStringCopy(char *destination, const char *source)
{
    char *i;
    i = destination;
    while (*source != '\0')
    {
        *destination = *source;
        source++;
        destination++;
    } *destination = '\0';
    return i;
}

char *myStringCat(char *destination, const char *source)
{
    char *i;
    i = destination;
    while (*destination)
    {destination++;}
    
    while(*source)
    {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
    return i;
}

int txtinput(RentalCar string[5], int i)
{
    char namefile[20];
    
    
    ifstream inputstream;
    cout << "Enter input file name: ";
    cin >> namefile;
    inputstream.open(namefile);
    
    if (inputstream.fail())
    {return 0;}
    
    
    for (int i = 0; i < 5; i++)
    {
        inputstream >> string[i].year >> string[i].make >> string[i].model >> string[i].price >> string[i].available;
    }
    return 0;
}

void txtoutput(RentalCar string[5], int i)
{
    ofstream outputstream;
    char outputname[20];
    
    
    cout << "Enter output file name: ";
    cin >> outputname;
    outputstream.open(outputname);
    for (int i = 0; i < 5; i++)
    {
        outputstream << string[i].year << " " << string[i].make << " " << string[i].model << ", " << "$" << string[i].price << " " << "per day," << " Available: " << boolalpha << string[i].available <<" "<<endl;
    }
    
}

void display(RentalCar string[], int i)
{
    for (int i = 0; i < 5; i++)
    {
        cout << string[i].year <<" ";
        cout << string[i].make <<" ";
        cout << string[i].model <<", ";
        cout << "$" << string[i].price <<" " << "per day,";
        cout << " Available: " << boolalpha << string[i].available <<" " << endl;
        cout <<"\n";
    }
}

void swapstruct(RentalCar *string1, RentalCar *string2)
{
    RentalCar *temp = new RentalCar;
    *temp = *string1;
    *string1 = *string2;
    *string2 = *temp;
}

void sortstruct(RentalCar string[])
{
    while (string[0].price > string[1].price || string[1].price > string[2].price || string[2].price > string[3].price || string[3].price > string[4].price)
    {
        for (int i = 0; (i+1) < 5; i++)
        {
            if (string[i].price > string[i+1].price)
            {
                swapstruct(&string[i], &string[i+1]);
            }
        }
    }
    
}

void pricestruct(RentalCar string[], int days)
{
    
    for (int i = 0; i < 5; i++)
    {
        if (string[i].available == true)
        {
            string[i].price *= days;
            cout << "\n";
            cout << string[i].year <<" ";
            cout << string[i].make <<" ";
            cout << string[i].model <<", ";
            cout << "$" << string[i].price <<" " << "per day,";
            cout << " Available: " << boolalpha << string[i].available <<" " << endl;
            
        }
        
    }
    cout <<'\n';
}

void checking(RentalCar string[], int check)
{
    
    while (string[check].available != true)
    {
        cout << "\nOOPS! NOT AVAILABLE\n";
        cout << "\nWhich Car? ";
        cin >> check;
    }
    
    if (string[check].available == true)
    {
        cout << "\n";
        cout << string[check].year <<" ";
        cout << string[check].make <<" ";
        cout << string[check].model <<", ";
        cout << "$" << string[check].price <<" " << "per day,";
        cout << " RENTED " << endl;
    }
    string[check].available = false;
    
}





















