#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <windows.h>

using namespace std;

static const string EMPTY_STRING = "";
static const string ALL = "All";

static const int TYPE_LENGTH = 20;
static const int DISTRICT_LENGTH = 10;
static const int PHONE_LENGTH = 10;
static const int ADDRESS_LENGTH = 30;

static const string ID = "id";
static const string TYPE = "type";
static const string DISTRICT = "district";
static const string AREA = "area";
static const string PRICE = "price";
static const string PHONE_NUMBER = "phone number";
static const string ADDRESS = "address";

static const string IN_ACTION = "Choose action (print, printall, add, exit): ";
static const string IN_ESTATES_COUNT = "Enter number of estates: ";
static const string IN_MAX_AREA = "Enter maximum area size (/m2): ";
static const string IN_MAX_PRICE = "Enter maximum price (\x80): ";
static const string IN_TYPE = "Enter type: ";
static const string IN_DISTRICT = "Enter district: ";
static const string IN_AREA = "Enter area: ";
static const string IN_PRICE = "Enter price: ";
static const string IN_PHONE = "Enter phone number: ";
static const string IN_ADDRESS = "Enter address: ";

static const string CREATE_SUCCESS = "Estate successfully added!";

static const string INVALID_STRING = "Invalid input! Maximum length must be ";
static const string INVALID_INT = "Invalid input! Value must be bigger than 0 ";
static const string INVALID_DOUBLE = "Invalid input! Value must be bigger than 0 ";

static const string ACTION_ADD = "add";
static const string ACTION_PRINT = "print";
static const string ACTION_PRINT_ALL = "printall";
static const string ACTION_EXIT = "exit";

static const string TYPE_HOUSE = "House";
static const string TYPE_APARTMENT = "Apartment";
static const string TYPE_OFFICE = "Office";
static const string TYPE_GARAGE = "Garage";
static const string TYPE_STUDIO = "Studio";

static const string DISTRICT_LEVSKI = "Levski";
static const string DISTRICT_CHATALJA = "Chatalja";
static const string DISTRICT_ASPARUHOVO = "Asparuhovo";
static const string DISTRICT_TRAKIQ = "Trakiq";
static const string DISTRICT_GALATA = "Galata";

static const string RND_PHONE_1 = "0888273828";
static const string RND_PHONE_2 = "0897261842";
static const string RND_PHONE_3 = "087429322";
static const string RND_PHONE_4 = "0878273333";
static const string RND_PHONE_5 = "0762777123";

static const string RND_ADDRESS_1 = "Pobeda 31";
static const string RND_ADDRESS_2 = "Stranja 55";
static const string RND_ADDRESS_3 = "Maskuda 12";
static const string RND_ADDRESS_4 = "Maldost 1";
static const string RND_ADDRESS_5 = "Vuzrajdane 32";

class Estate
{
private:
    int id;
    static int current_id;
    string type;
    string district;
    int area;
    double price;
    string phoneNumber;
    string address;


public:
    Estate(const string &type, const string &district, int area, double price, const string &phoneNumber,
           const string &address) : id(current_id++), type(type), district(district), area(area), price(price), phoneNumber(phoneNumber),
                                    address(address) {
        setId(id);
        setType(type);
        setDistrict(district);
        setArea(area);
        setPrice(price);
        setPhoneNumber(phoneNumber);
        setAddress(address);
    }


public:
    int getId() const {
        return id;
    }

    void setId(int id) {
        Estate::id = id;
    }

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        string eType = type;
        if (eType.size() > TYPE_LENGTH)
            eType.resize(TYPE_LENGTH);
        Estate::type = eType;
    }

    const string &getDistrict() const {
        return district;
    }

    void setDistrict(const string &district) {
        string eDistrict = district;
        if (eDistrict.size() > TYPE_LENGTH)
            eDistrict.resize(TYPE_LENGTH);
        Estate::district = eDistrict;
    }

    int getArea() const {
        return area;
    }

    void setArea(int area) {
        Estate::area = area;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Estate::price = price;
    }

    const string &getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(const string &phoneNumber) {
        string ePhoneNumber = phoneNumber;
        if (ePhoneNumber.size() > PHONE_LENGTH)
            ePhoneNumber.resize(PHONE_LENGTH);
        Estate::phoneNumber = ePhoneNumber;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        string eAddress = address;
        if (eAddress.size() > ADDRESS_LENGTH)
            eAddress.resize(ADDRESS_LENGTH);
        Estate::address = eAddress;
    }

    void printEstate()
    {
        cout << ID << ": " << id << ", "
             << TYPE << ": " << type << ", "
             << DISTRICT  << ": " << district << ", "
             << AREA << ": " << area << "/m2, "
             << PRICE << ": " << price << "\x80, "
             << PHONE_NUMBER <<  ": " << phoneNumber << ", "
             << ADDRESS << ": " << address << endl;
    }

};

int Estate::current_id;

vector<Estate> estates;
vector<string> types = { TYPE_HOUSE, TYPE_APARTMENT,
                         TYPE_OFFICE, TYPE_GARAGE, TYPE_STUDIO };
vector<string> districts = { DISTRICT_LEVSKI, DISTRICT_CHATALJA,
                             DISTRICT_ASPARUHOVO, DISTRICT_TRAKIQ, DISTRICT_GALATA };
vector<string> phoneNumbers = { RND_PHONE_1, RND_PHONE_2, RND_PHONE_3, RND_PHONE_4, RND_PHONE_5 };
vector<string> addresses = { RND_ADDRESS_1, RND_ADDRESS_2, RND_ADDRESS_3, RND_ADDRESS_4, RND_ADDRESS_5 };

void printAllEstates(vector<Estate> estates)
{
    for (int i = 0; i < estates.size(); i++)
        estates[i].printEstate();
}

string genRandomString(vector<string> arr)
{
    random_shuffle(begin(arr), end(arr));
    return arr[0];
}

int getRandomInt(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

double getRandomDouble(int min, int max)
{
    return (double) (min + (rand() % (max - min + 1))) * 1000;
}

void createEstates()
{
    for (int i = 0; i <= 50; ++i) {
        Estate estate(genRandomString(types),
                      genRandomString(districts),
                      getRandomInt(25, 255),
                      getRandomDouble(6, 120),
                      genRandomString(phoneNumbers),
                      genRandomString(addresses));
        estates.push_back(estate);
    }
}

string validateStringInput(string message, int length)
{
    string val;

    while (true) {
        cin.clear();
        cin.sync();
        cout << message;
        getline(cin, val);
        if (val.length() <= length)
            break;
        else
            cin.clear();
        cout << INVALID_STRING << length << endl;
    }

    return val;
}

int validateArea(string message)
{
    int val;
    while (true)
    {
        cin.clear();
        cin.sync();
        cout << message;
        cin >> val;
        if (cin.good() && val > 0)
            break;
        else
            cin.clear();
        cout << INVALID_INT << endl;
    }
    return val;
}

double validatePrice(string message)
{
    double val;
    while (true)
    {
        cin.clear();
        cin.sync();
        cout << message;
        cin >> val;
        if (cin.good() && val > 0)
            break;
        else
            cin.clear();
        cout << INVALID_DOUBLE << endl;
    }
    return val;
}

void addEstate()
{
    string type = validateStringInput(IN_TYPE, TYPE_LENGTH);
    string district = validateStringInput(IN_DISTRICT, DISTRICT_LENGTH);
    int area = validateArea(IN_AREA);
    double price = validatePrice(IN_PRICE);
    string phoneNumber = validateStringInput(IN_PHONE, PHONE_LENGTH);
    string address = validateStringInput(IN_ADDRESS, ADDRESS_LENGTH);

    Estate est(type, district, area, price, phoneNumber, address);
    estates.push_back(est);
    cout << CREATE_SUCCESS << endl;
}

void printEstates(vector<Estate> estates,
                  string type, string district, int area, double price)
{
    for (int i = 0; i < estates.size(); i++)
    {
        if ((type.empty() || (!type.empty() && estates[i].getType() == type)) &&
            (district.empty() || (!district.empty() && estates[i].getDistrict() == district)) &&
            (area == 0 || (area > 0 && estates[i].getArea() < area)) &&
            (price == 0 || (price > 0 && estates[i].getPrice() < price)))
            estates[i].printEstate();
    }
}

string getChosenType(int type)
{
    switch(type) {
        case 0 :
            return EMPTY_STRING;
        case 1:
            return TYPE_HOUSE;
        case 2 :
            return TYPE_APARTMENT;
        case 3 :
            return TYPE_OFFICE;
        case 4 :
            return TYPE_GARAGE;
        case 5 :
            return TYPE_STUDIO;
        default :
            return EMPTY_STRING;
    }
}
string getChosenDistrict(int district)
{
    switch(district) {
        case 0 :
            return EMPTY_STRING;
        case 1:
            return DISTRICT_LEVSKI;
        case 2 :
            return DISTRICT_CHATALJA;
        case 3 :
            return DISTRICT_ASPARUHOVO;
        case 4 :
            return DISTRICT_TRAKIQ;
        case 5 :
            return DISTRICT_GALATA;
        default :
            return EMPTY_STRING;
    }
}
void sortAndPrintEstates()
{
    int chosenType, chosenDistrict, chosenArea, chosenPrice;
    cout << "Choose number for type (0-" << ALL <<
         ", 1-" << TYPE_HOUSE <<
         ", 2-" << TYPE_APARTMENT <<
         ", 3-" << TYPE_OFFICE <<
         ", 4-" << TYPE_GARAGE <<
         ", 5-" << TYPE_STUDIO <<"): ";
    cin >> chosenType;
    cout << "Choose number for type (0-" << ALL <<
         ", 1-" << DISTRICT_LEVSKI <<
         ", 2-" << DISTRICT_CHATALJA <<
         ", 3-" << DISTRICT_ASPARUHOVO <<
         ", 4-" << DISTRICT_TRAKIQ <<
         ", 5-" << DISTRICT_GALATA <<"): ";
    cin >> chosenDistrict;
    cout << IN_MAX_AREA;
    cin >> chosenArea;
    cout << IN_MAX_PRICE;
    cin >> chosenPrice;
    printEstates(estates, getChosenType(chosenType), getChosenDistrict(chosenDistrict), chosenArea, chosenPrice);
}

int main()
{
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    string action;
    int numberOfEstates;
    createEstates();

    while (true)
    {
        cout << IN_ACTION;
        cin >> action;

        if (action == ACTION_PRINT_ALL)
            printAllEstates(estates);
        else if (action == ACTION_PRINT)
            sortAndPrintEstates();
        else if (action == ACTION_EXIT)
            break;
        else if (action == ACTION_ADD)
        {
            cout << IN_ESTATES_COUNT;
            cin >> numberOfEstates;
            for (int i = 0; i < numberOfEstates; ++i) {
                addEstate();
            }
        }
    }

    return 0;
}