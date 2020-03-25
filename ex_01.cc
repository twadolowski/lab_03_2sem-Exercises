#include <iostream>
#include <string>
using namespace std;

class student {
protected:
    string name_surname_ = "NO_NAME";
    unsigned int id_number_ = 0;

public:
    student(string name_surname, unsigned int id_number);
    string Descr_ = "student of group";
    void printDescr();
    void printData()
    {
        cout << " Method printData() of the STUDENT class" << endl;
        cout << " name surname " << name_surname_ << endl;
        cout << " id number " << id_number_ << endl;
    }
};

class coordinator {
protected:
    void inform_group(){
        cout<< "Informing group"<<endl;
    }
    void inform_teacher(){
         cout<< "Informing teacher"<<endl;
    }
   
public:
   
};

class chairman : public student, public coordinator{
private:
    string email_ = "no@noemail";

public:
    chairman(string name_surname, unsigned int id_number, string email);
    string Descr_ = "chairman of a group";
};

chairman::chairman(string name_surname, unsigned int id_number, string email)
    : student(name_surname, id_number)
    , email_(email)
{
    inform_teacher();
    inform_group();
    
    cout << "Creating an object of the CHAIRMAN class named: " << Descr_ << endl;
}

student::student(string name_surname, unsigned int id_number)
    : name_surname_(name_surname)
{
    id_number_ = id_number;
    cout << "Creating an object of the STUDENT class named: " << Descr_ << endl;
}

void student::printDescr()
{
    cout << "Descr: " << Descr_ << endl;
}

int main()
{
    student stud("Jan Kowalski", 7);
    stud.printDescr();
    chairman chair("Aleksandra Nowak", 999, "mail@nomail.dot");
    chair.printDescr();
    // cout << "Data:" << chair.name_surname_ << " " << chair.id_number_ << endl;
}
