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
    void virtual printDescr()=0;
    void printData()
    {
        cout << " Method printData() of the STUDENT class" << endl;
        cout << " name surname " << name_surname_ << endl;
        cout << " id number " << id_number_ << endl;
    }
};

class coordinator {
protected:
    void inform_group();
    void inform_teacher();
    string Descr_ = "coordinator of group";
    
public:
    void printDescr(){
        cout << "Descr: " << Descr_ << endl;
    }
};

void coordinator::inform_group(){
    cout << "Informing group" << endl;
}

void coordinator::inform_teacher(){
    cout << "Informing teacher" << endl;
}


class chairman : public student, public coordinator {
private:
    string email_ = "no@noemail";

public:
    chairman(string name_surname, unsigned int id_number, string email);
    string Descr_ = "chairman of a group";
    //We could call the method inside the class
    void printDescr(){
        cout << "Descr: " << Descr_ << endl;
    }
    void inform_teacher2(){ 
        inform_teacher();
    }
};

chairman::chairman(string name_surname, unsigned int id_number, string email)
    : student(name_surname, id_number)
    , email_(email)
{
    cout << "Creating an object of the CHAIRMAN class named: " << Descr_ << endl;
    //Another way to try the protected method
    inform_group();
    
}

student::student(string name_surname, unsigned int id_number)
    : name_surname_(name_surname)
{
    id_number_ = id_number;
    cout << "Creating an object of the STUDENT class named: " << Descr_ << endl;
}

/*void student::printDescr()
{
    cout << "Descr: " << Descr_ << endl;
}*/

int main()
{
    //We can't create now an instance of this class because student is an abstract type
    student stud("Jan Kowalski", 7);
    stud.printDescr();
    chairman chair("Aleksandra Nowak", 999, "mail@nomail.dot");
    chair.printDescr();
    //We can't call the method itself, so we call a method that calll the original
    chair.inform_teacher2();
    // cout << "Data:" << chair.name_surname_ << " " << chair.id_number_ << endl;
}
