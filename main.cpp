#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 30; // Maximum value for employees

//STRUCT DEFINITION

struct Employee
{
    string EmployeeIDno;
    string EmployeeName;
    string EmployeeSurname;
    double EmployeeSalary;
    double EmployeeBenefits;
    double EmployeeDeductions;

};

//CLASS DEFINITION

class EmployeeData
{
private:
    Employee employees[MAX_EMPLOYEES]; //EMPLOYEES ARRAY
    int NumOfEmployees;

public:

    EmployeeData() : NumOfEmployees(0){} //CONSTRUCTOR FOR INTIALIZING NUMBER OF EMPLOYEES TO 0

//FUNCTION DEFITION FOR ADDING AN EMPLOYEE

    void EmployeeAddition(const string& EmployeeIDno, const string& EmployeeName,const string& EmployeeSurname, double EmployeeSalary,double EmployeeDeductions, double EmployeeBenefits)
    {
        if (NumOfEmployees < MAX_EMPLOYEES)
        {
            //STORING DATA OF THE EMPLOYEE IN THE ARRAY
            employees[NumOfEmployees] = {EmployeeIDno, EmployeeName, EmployeeSurname, EmployeeSalary, EmployeeDeductions, EmployeeBenefits};
            NumOfEmployees++;
            cout << "Employee added successfully!" << endl;
        }
        else
        {
            cout << "Limit reached" << endl;
        }
    }

//FUNCTION DEFITION FOR SHOWING THE DETAILS OF AN EMPLOYEE

void EmployeeDetails(const string& EmployeeIDno)
{
    for (int i = 0; i < NumOfEmployees; ++i)
    {
       if (employees[i].EmployeeIDno == EmployeeIDno) //CHECKING IF THE EMPLOYEE ID EXISTS
            {
                cout << "ID: " << employees[i].EmployeeIDno << ", Name: " << employees[i].EmployeeName << ", Salary: " << employees[i].EmployeeSalary << endl;
                return; // AFTER SHOWN DETAILS, EXIT
            }
    }
    cout << "Employee not found" << endl;
}
//FUNCTION DEFITION FOR CALCULATING THE EMPLOYEE PAYROLL

double Payroll() const
{
    double TotalPayroll = 0.0;
    for (int i = 0; i < NumOfEmployees; ++i)
    {
        TotalPayroll += employees[i].EmployeeSalary + employees[i].EmployeeBenefits - employees[i].EmployeeDeductions;
    }
     return TotalPayroll;
}

//FUNCTION TO SAVE EMPLOYEE DETAILS TO FILE
void SaveToFile(const string& filename) const
{
    ofstream file(filename); //OPEN FILE FOR WRITING
    if(file.is_open())
    {
        //WRITE TO FILE
        for(int k = 0; k < NumOfEmployees; ++k)
        {
            file << employees[k].EmployeeIDno << ", " << employees[k].EmployeeName << ", " << employees[k].EmployeeSurname << ", "
                     << employees[k].EmployeeSalary << ", " << employees[k].EmployeeBenefits << ", " << employees[k].EmployeeDeductions << endl;
        }
        file.close();
        cout << "Employee saved to file" << endl;
    }
    else
    {
        cout << "Unable to save" << endl;
    }
}
};

int main()
{
    EmployeeData Data; //EMPLOYEEDATA CLASS OBJECT
    int choice;

    while (true)
    {
        cout << "Payroll System\n";
        cout << "1. Add employee\n";
        cout << "2. View the details\n";
        cout << "3. Payroll calculation\n";
        cout << "4. Save to file\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();//IGNORING NEWLINE CHARACTER IN THE INPUT BUFFER

        if (choice == 1)
        {

            string EmployeeIDno;
            string EmployeeName, EmployeeSurname;
            double EmployeeSalary,EmployeeDeductions, EmployeeBenefits;

            //GET USER INPUT OF FOR THE EMPLOYEE DETAILS
            cout << "Enter employee ID: ";
            getline(cin, EmployeeIDno);
            cout << "Enter employee name: ";
            getline(cin, EmployeeName);
            cout << "Enter employee surname: ";
            getline(cin, EmployeeSurname);
            cout << "Enter employee salary: ";
            cin >> EmployeeSalary;
            cout << "Enter employee deductions: ";
            cin >> EmployeeDeductions;
            cout << "Enter employee benefits: ";
            cin >> EmployeeBenefits;

            //CALL ADD FUNCTION
            Data.EmployeeAddition(EmployeeIDno, EmployeeName, EmployeeSurname, EmployeeSalary, EmployeeDeductions, EmployeeBenefits);
        }
        else if(choice == 2)
        {
            string EmployeeIDno;
            cout << "Enter employee ID: ";
            getline(cin, EmployeeIDno);

            //DISPLAY EMPLOYEE DETAILS
            Data.EmployeeDetails(EmployeeIDno);
        }
        else if(choice == 3)
        {
            cout << "Total payroll is: R" << Data.Payroll()<< endl;
        }
        else if(choice == 4)
        {
            //SAVE TO FILE
            Data.SaveToFile("Employees.txt");
        }
        else if(choice == 5)
        {
            cout << "Existing the system" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice, try again" << endl;
        }
    }
    return 0;
}
