#include <iostream>
using namespace std;
/*
ACESS MODIFIERS: private, public, protected
    private- class attributes are hidden outside of the class
    public- are accessible outside of the class
    protected - makes attributes available only to the child class of the parent (classes that inherit the main one)
by default attributes of a class are private

constructor - special type of methond thats invoked each time an object of a class is created
    i.g. when i create a new employee, default constructors are assigned to each variable

THREE RULES IN CREATING A CONSTRUCTOR:
    1. a constructor does not have a return type
    2. a constructor has the same name as the class it is assigned to
    3. a constructor must be public (for now)

FOUR PILLARS OF OBJECT ORIENTED PROGRAMMING
    1. encapsulation - the idea of tying together data using methods (getters and setters) that operate on that data
         with purpose of preventing anyone or anything outside of that class to directly access or interact with that data
    2. abstraction - hiding complex things behing a procdeure that simplifies it, essentially a user interface.
         This is done using abstract classes
    3. inheritance - creates a parent-child class system where a child class will adopt the characteristics established by the parent class.
         This allows for for more specific versions of a class with methods and properties that pertain to only that version (i.e.: Employee -> Developer)
    4. polymorphism - when a parent class reference is used to refer to a child class object. 
*/



//ABSTRACTION: serves as a contract that requires any class that signs it to have an implementation of the method "AskForPromotion"
class AbstractEmployee{ 
    //to make this function obligatory, you must make it a pure virtual function (virtual void .... = 0)
    virtual void AskForPromotion() = 0;
};


class Employee: AbstractEmployee {
private:
    string Company;
    int Age;

protected:
    string Name;

public:

    //ENCAPSLATION: setters and getters
    void setName(string name){ //setter
        Name = name;
    }
    string getName(){ //getter
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if (age >= 18)
        Age = age;
    }
    int getAge(){
        return Age;
    }


    void IntroduceYourself(){
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    //constructor:
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
    
    void AskForPromotion() {
        if (Age > 30){
            cout << Name << " got promoted!" << endl;
        } else {
            cout << Name << ", nah." << endl;
        }
    }

    //POLYMORPHISM: what this function does will change depending on the subclass that calls it
    virtual void Work(){
        cout << Name << "is checking email, task backlog, performing tasks" << endl;
    }
};


/*INHERITANCE: creates the subclass, Developer, that inherits the properties of an Employee AND allows us to create properties that are specific to Developers.
     abstract classes are private by defualt. to access them you have to specify it as public(class Developer: PUBLIC Employee)*/
class Developer: public Employee {
public:
    //attribute specific to developer
    string FavProgrammingLanguage;

    //an abstract class needs a constructor. we attatch Employee to set the format of the developers name, company, and age, and then attatch language
    Developer(string name, string company, int age, string favProgrammingLanguage): Employee(name, company, age){
        FavProgrammingLanguage = favProgrammingLanguage;
    };
    
    //function specific to developer
    void FixBug(){
        cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
    }
    void Work(){
        cout << Name << " is writing " << FavProgrammingLanguage << endl;
    }
};
class Teacher: public Employee {
public:
    string Subject;
    void PrepareLesson(){
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }

    Teacher(string name, string company, int age, string subject): Employee(name, company, age){
        Subject = subject;
    }

    void Work(){
        cout << Name << " is teaching " << Subject << endl;
    }
};


int main()
{
    /*
    THIS ONLY WORKS WHEN MEMBERS ARE PUBLIC
    Employee employee1;
    employee1.Name = "Gabriel";
    employee1.Company = "EZ Test New York";
    employee1.Age = 22;

    employee1.IntroduceYourself();

    Employee employee2;
    employee2.Name = "Jadyn";
    employee2.Company = "EZ Test New York";
    employee2.Age = 23;

    employee2.IntroduceYourself();
    */

   Employee employee1 = Employee("Gabriel", "EZ Test New York", 22);
   Employee employee2 = Employee("Jadyn", "EZ Test New York", 23);


   //employee1.IntroduceYourself();
   //employee2.IntroduceYourself();

   //employee1.setAge(40);
   //cout<<employee1.getName() << " is " << employee1.getAge() << " years old." << endl;

   //employee1.AskForPromotion();
   //employee2.AskForPromotion();


   Developer Swami = Developer("Swami", "Google", 23, "Scala");
   Swami.FixBug();
   Swami.AskForPromotion();

   Teacher G = Teacher("Mr. G", "PSMS3", 35, "Computer Science");
   G.PrepareLesson();
   G.AskForPromotion();
   
   //Swami.Work();
   //G.Work();

    //for this to function, the work method has to be virtual void
   Employee* e1 = &G;
   Employee* e2 = &Swami;
   e1 -> Work();
   e2 -> Work();
}