/*
    Christian Chacon | 6/10/2023

    CIS 230 01
*/

#include <iostream>
#include <vector>
#include <limits>

class Person{
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    long int zipCode;
    std::string phoneNumber;

public:
//mutators
    void setFirstName(std::string firstName){this->firstName = firstName;}
    void setLastName(std::string lastName){this->lastName = lastName;}
    void setAddress(std::string address){this->address = address;}
    void setZipCode(long int zipCode){this->zipCode = zipCode;}
    void setPhoneNumber(std::string phoneNumber){this->phoneNumber = phoneNumber;}

//accessors
    std::string getFirstName(){return firstName;}
    std::string getLastName(){return lastName;}
    std::string getAddress(){return address;}
    long int getZipCode(){return zipCode;}
    std::string getPhoneNumber(){return phoneNumber;}

//utility fns
    virtual void displayPerson(){
        std::cout<<firstName<<" "<<lastName<<": "<<phoneNumber<<" | "<<address<<" "<<zipCode;
    }
};
// - - - - - End Person Class - - - - - 

class Employee : public Person{
private:
    long int ssn;
    std::string department;

public:
//mutators
    void setSSN(long int ssn){this->ssn = ssn;}
    void setDepartment(std::string department){this->department = department;}

//accessors
    long int getSSN(){return ssn;}
    std::string getDepartment(){return department;}

//utility fns
    virtual void displayEmployee(){
        Person::displayPerson();
        std::cout<<" | "<<ssn<<" | "<<department;
    }
};
// - - - - - End Employee Class - - - - - 

class Customer : public Person{
private:
    double discount;
    std::string email;

public:
//mutators
    void setDiscount(double discount){this->discount = discount;}
    void setEmail(std::string email){this->email = email;}

//accessors
    double getDiscount(){return discount;}
    std::string getEmail(){return email;}

//utility fns
    virtual void displayCustomer(){
        Person::displayPerson();

    }
};
// - - - - - End Customer Class - - - - - 

void display(Person *onePerson);

int main(){
    std::vector <Person *> allPeople;

    char position, chooseAnother;

    std::string fname, lname, address, phoneNumber;
    long int zipCode;

    while(chooseAnother != 'N'){
        std::cout<<std::endl;
        std::cout<<"Enter your First Name: "; getline(std::cin, fname);
        std::cout<<"Enter your Last Name:  "; getline(std::cin, lname);
        std::cout<<"Enter your Address:    "; getline(std::cin, address);
        std::cout<<"Enter your Zip Code:   "; std::cin>>zipCode;

            while(std::cin.fail() || zipCode < 0){
                std::cout<<"\n  Invalid.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"Enter your Zip Code:   "; std::cin>>zipCode;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Enter your Phone Number: "; getline(std::cin, phoneNumber);
        std::cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<std::endl;


        std::cout<<"Please choose your position: "<<std::endl;
        std::cout<<"Are you a (E)mployee or a (C)ustomer? "; 
            std::cin>>position; position = toupper(position);

            while(std::cin.fail() || (position != 'E' && position != 'C')){
                std::cout<<"\n  Invalid.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"Welcome! Please choose your position: "<<std::endl;
                std::cout<<"Are you a (E)mployee or a (C)ustomer? "; 
                    std::cin>>position; position = toupper(position);   
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(position == 'E'){
            Employee *e = new Employee;
            long int ssn;
            std::string department;

            std::cout<<"Welcome employee "<<fname<<", enter your information below:"<<std::endl;
            std::cout<<"Enter Department: "; getline(std::cin, department);
            std::cout<<"Enter SSN: "; std::cin>>ssn;

                while(std::cin.fail() || ssn < 0 ){
                    std::cout<<"\n  Invalid.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::cout<<"Enter SSN: "; std::cin>>ssn;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            e->setFirstName(fname);
            e->setLastName(lname);
            e->setAddress(address);
            e->setZipCode(zipCode);
            e->setPhoneNumber(phoneNumber);
            e->setSSN(ssn);
            e->setDepartment(department);

            allPeople.push_back(e);
        }
        else if(position == 'C'){
            Customer *c = new Customer;
            std::string email;

            std::cout<<"Greetings "<<fname<<", please enter your email: "; getline(std::cin, email);     

            c->setFirstName(fname);
            c->setLastName(lname);
            c->setAddress(address);
            c->setZipCode(zipCode);
            c->setPhoneNumber(phoneNumber);
            c->setEmail(email);
            c->setDiscount(0.10);

            allPeople.push_back(c);
        }

        std::cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<std::endl;

        std::cout<<"Enter Another? (Y/N) "; std::cin>>chooseAnother; chooseAnother = toupper(chooseAnother);

            while(std::cin.fail() || (chooseAnother != 'Y' && chooseAnother != 'N') ){
                std::cout<<"\n  Invalid.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"Enter Another? (Y/N) "; std::cin>>chooseAnother; chooseAnother = toupper(chooseAnother);
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }//end while loop

    std::cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<std::endl;

    for(Person *onePerson : allPeople){
        display(onePerson);
        std::cout<<std::endl;
    }

    return 0;
}

void display(Person *onePerson){
    onePerson->displayPerson();
}