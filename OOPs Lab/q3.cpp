#include <iostream>
using namespace std;

class manager
{
public:
    string name;
    int age;
    int id;
    manager() {}
    void managerDetails()
    {
        cout << "Id = " << id << ", "
             << "Name = " << name << ", "
             << "Age = " << age << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the number of manager " << endl;
    cin >> n;
    manager *m = new manager[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the manager id " << endl;
        cin >> m[i].id;
        cout << "Enter the manager name " << endl;
        cin >> m[i].name;
        cout << "Enter the age of the manager " << endl;
        cin >> m[i].age;
    }

    cout << "The list of manager is " << endl;
    for (int i = 0; i < n; i++)
    {
        m[i].managerDetails();
    }
    return 0;
}