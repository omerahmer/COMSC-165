#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
typedef struct Item
{
    string name;
    int quantity;
    double whole;
    double retail;

} Item;
// function to get item input from user
bool getItemInput(string prompt, Item &item)
{
    cout << "\n" << prompt << endl;
    cout << "Enter Item Name: ";
    string name;
    int quantity;
    double whole;
    double retail;
    getline(cin, name);

    cout << "Enter Quantity: ";
    cin >> quantity;
    if (quantity <= 0)
    {
        cout << "Enter Invalid Quantity Entered\n";
        return false;
    }

    cout << "Enter Whole Sale Rate: ";
    cin >> whole;
    if (whole <= 0)
    {
        cout << "Enter Invalid Whole salre rate Entered\n";
        return false;
    }

    cout << "Enter Retail Rate: ";
    cin >> retail;
    if (retail <= 0)
    {
        cout << "Enter Invalid Retail Rate Entered\n";
        return false;
    }
    item.name = name;
    item.quantity = quantity;
    item.whole = whole;
    item.retail = retail;
    cin.clear();
    cin.ignore(1);
    return true;
}
// function to add record to the given input file

void addRecord(string filename)
{
    Item item;
    // get new item as input
    if (getItemInput("Enter Details of new item to insert: ", item))
    {
        ofstream out(filename.c_str(), std::ios_base::app);
        out << item.name << "," << item.quantity << "," << item.whole << "," << item.retail << "\n";
        out.close();
        cout << "\nSuccessfylly Added the Record to file: " << filename << endl;
    }
    else
    {
        cout << "Unable to add New Record.\n";
    }
}
// function that splits the line into fields of string array.
bool getFields(string line, string fields[])
{
    int length = line.length();
    if (line[length - 1] == '\n')
    {
        line.erase(line.length() - 1);
    }
    if (line.empty())
    {
        cout << "Line Empty\n";
        return NULL;
    }

    string del = ",";
    size_t ind = 0;
    string field;
    int pos = 0;
    while ((ind = line.find(del)) != string::npos)
    {
        if (pos == 4)
        {

            return NULL;
        }
        field = line.substr(0, ind);

        line.erase(0, ind + 1);
        fields[pos] = field;
        pos++;
    }
    fields[pos] = line;
    return true;
}
// function to display any record by record name.
void displayAnyRecord(string filename)
{
    cout << "\nEnter Full Name or the first n letters of the Item Name: ";
    string name;
    getline(cin, name);
    ifstream inp(filename.c_str());
    string line;
    bool found = false;
    while (getline(inp, line))
    {

        string fields[4];
        if (getFields(line, fields))
        {
            int length = name.length();
            string sub = fields[0].substr(0, length);
            if (sub.compare(name) == 0)
            {
                cout << "\nItem Details contained with given Name is : " << line << endl;
                found = true;
            }
        }
        else
        {
            cout << "Error: " << line << " --> has invalid number of fields\n";
        }
    }
    if (found == false)
    {
        cout << "Unable to Find given Item Name in file: " << filename << endl;
    }
    inp.close();
}
// function to change record using the filename
void changeAnyRecord(string filename)
{
    cout << "\nEnter Full Name or the first n letters of the Item Name: ";
    string name;
    getline(cin, name);

    ifstream inp(filename.c_str());
    string line;
    bool found = false;
    string data = "";
    while (getline(inp, line))
    {

        string fields[4];
        if (getFields(line, fields))
        {
            int length = name.length();
            string sub = fields[0].substr(0, length);
            if (sub.compare(name) == 0 && found == false)
            {
                cout << "\nITEM FOUND\n";
                cout << "\nItem Details contained with given Name is : " << line << endl;
                Item item;
                if (getItemInput("Enter New Details of the Item Date: ", item) == false)
                {
                    cout << "Warning: Unable to change data\n";
                    inp.close();
                    return;
                }

                found = true;
                ostringstream os;
                os << item.name << "," << item.quantity << "," << item.whole << "," << item.retail << "\n";
                data += os.str();
            }
            else
            {
                data += line + "\n";
            }
        }
        else
        {
            cout << "Error: " << line << " --> has invalid number of fields\n";
        }
    }
    inp.close();
    if (found == false)
    {
        cout << "Unable to Find given Item Name in file: " << filename << endl;
    }
    else
    {
        ofstream out(filename.c_str());
        out << data;
        out.close();
        cout << "\nSuccessfully Updated Record\n";
    }
}
// function to display all records in filename
void displayAllRecords(string filename)
{

    ifstream inp(filename.c_str());
    string line;
    int count = 0;
    cout << "\nDisplaying All Records of the Inventory in file: " << filename << endl;
    while (getline(inp, line))
    {
        cout << "\n"
             << line;
        count++;
    }
    cout << "\n";
    cout << "\nTotal " << count << " number of records are loaded from file: " << filename << "\n\n";

    inp.close();
}
// function to display report in filename.
void displayReport(string filename)
{
    ifstream inp(filename.c_str());
    string line;
    int totalQuant = 0;
    double totalWhole = 0;
    double totalRetail = 0;
    while (getline(inp, line))
    {
        string fields[4];
        if (getFields(line, fields))
        {
            int quantity;
            double whole;
            double retail;
            stringstream str(fields[1] + " " + fields[2] + " " + fields[3]);
            str >> quantity >> whole >> retail;
            totalQuant += quantity;
            totalWhole += whole;
            totalRetail += retail;
        }
        else
        {
            cout << "Error: " << line << " --> has invalid number of fields\n";
        }
    }
    cout << "\nTotal Quantity : " << totalQuant << endl;
    cout << "\nTotal Whole Sale Rate : " << totalWhole << endl;
    cout << "\nTotal Reatil Rate : " << totalRetail << endl;
    inp.close();
}
// function to display menu.
void displayPrint()
{
    cout << "\n1. Add new Record\n";
    cout << "2. Display Any Record in the file by Item Name or first n chars of Item Name\n";
    cout << "3. Change Any Record in the file\n";
    cout << "4. Display all records\n";
    cout << "5. Display Report\n";
    cout << "6. Quit\n";
    cout << "Enter your choice: ";
}
// function to get choice of menu..
int getChoice()
{
    cin.clear();

    displayPrint();
    string ch;
    getline(cin, ch);

    stringstream str(ch);
    int choice;
    str >> choice;
    while (choice <= 0 || choice > 6)
    {

        cout << "Invalid Input.Try Again\n";
        displayPrint();
        getline(cin, ch);

        stringstream str(ch);
        str >> choice;
    }

    return choice;
}
int main()
{
    int ch;
    string filename = "inventory.txt";
    while (ch != 6)
    {
        ch = getChoice();
        cout << "Selected Choice: " << ch << endl;
        switch (ch)
        {
        case 1:
            addRecord(filename);
            break;
        case 2:
            displayAnyRecord(filename);
            break;
        case 3:
            changeAnyRecord(filename);
            break;
        case 4:
            displayAllRecords(filename);
            break;
        case 5:
            displayReport(filename);
            break;
        case 6:
            cout << "Exiting..\n";
            break;
        }
    }

    return 0;
}
