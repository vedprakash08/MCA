#include <iostream>
#include <unordered_map>
using namespace std;

class store
{
public:
    int code;
    int price;
    unordered_map<int, int> item;

public:
    store() {}

    store(int c, int p) : code(c), price(p) {}

    void insertItem();

    void deleteItem();

    int totalPrice();
};

void store::insertItem()
{
    bool isContinue = true;
    string str;
    int code, price;

    while (isContinue)
    {
        cout << "want to add item (yes / no): ";
        cin >> str;
        if (str == "yes")
        {
            cout << "Enter the code of the purchased item: ";
            cin >> code;
            cout << "Enter the price of the purchased item: ";
            cin >> price;
            item[code] = price;
        }
        else
        {
            isContinue = false;
        }
    }
}

void store::deleteItem()
{
    bool isContinue = true;
    int code;
    string str;

    while (isContinue)
    {
        cout << "want to delete item (yes / no): ";
        cin >> str;
        if (str == "yes")
        {
            cout << "Enter the code of the purchased item: ";
            cin >> code;
            item.erase(code);
        }
        else
        {
            isContinue = false;
        }
    }
}

int store::totalPrice()
{
    int totalSum = 0;
    for (auto i : item)
    {
        totalSum += i.second;
    }

    return totalSum;
}

int main()
{
    store item1;
    item1.insertItem();
    item1.deleteItem();
    cout << "Total Price: " << item1.totalPrice() << endl;
    return 0;
}