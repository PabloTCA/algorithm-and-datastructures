//
// Created by Pablo Chávez on 16/08/26.
//
#include <iostream>
#include <vector>
#include <unordered_map>

/*
 *  OOP - Review
 *  Well I add this just to review some of the basic concepts of OBJECT ORIENTED PROGRAMMING
 *  Let's begin
 */

// First Classes - A class is a blueprint for creating objects. It defines the properties and behaviors that objects of that class will have.
// In this example, I will create a class called "Employee" to represent an employee in a company.
class Employee
{
    /*
     *  Some of the properties of the class is that we can have access modifiers
     *  There are three types of access modifiers: public, private, and protected.
     *  Public: The members of a class declared as public are accessible from anywhere in the program.
     *  Private: The members of a class declared as private are only accessible within the class itself.
     *  Protected: The members of a class declared as protected are accessible within the class itself and its derived classes.
     */
public:
    int id;
    std::string name;
    std::string company;
    int age;
    // A class constructor is a special method that is called when an object of a class is created. It is used to initialize the object's properties.
    Employee(int id, std::string name, std::string company, int age)
    {
        this->id = id;
        this->name = name;
        this->company = company;
        this->age = age;
    }
    // A class have methods and properties
    void displayEmployeeInfo()
    {
        std::cout << "Employee ID: " << id << std::endl;
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee Company: " << company << std::endl;
        std::cout << "Employee Age: " << age << std::endl;
    }
};

//////////////////////////////////////////////////////////////////////////////
/*
 *  Abstraction
 *  Abstraction allows us to define what an object should do
 *  without specifying how it should do it
 *
 *  In C++, an abstract class can be created by declaring at least one pure virtual function
 *  using "virtual ... = 0"
 *
 *  The derived classes are then responsible for providing
 *  the implementation of that function
 *
 */
class Vehicle
{
public:
    virtual void move() = 0;
};
/*
 *  Plane inherits from Vehicle
 *  The ':' indicates inheritance
 *  'public' specify the type of inheritance.
 *  By inheriting from Vehicle, Plane becomes a derived class of Vehicle while Vehicle is the base class.
 */
class Helicopter : public Vehicle
{
public:
    void move()
    {
        std::cout << "Helicopter is flying" << std::endl;
    }
};
////////////////////////////////// Encapsulation ////////////////////////////////////////////
/*
 * Encapsulation is the process of hiding the internal details of an object and exposing only the necessary information
 * to the outside world.
 * Encapsulation bundles an object's data and the methods that operate on that data together, while controlling
 * how that data can be accessed.
 *
 * For this we can use the different access modifiers in C++: public, private, and protected.
 *
 * public:    Members declared as public can be accessed from outside the class.
 *
 * private:   we use private when we want to hide the methods and variables from outside the class, this means that they
 *            can only be accessed by the class itself.
 *
 * protected: Members declared as protected can be accessed from within the class and from derived classes,
 *            but not directly from unrelated code outside the class.
 *
 */
class Plane : public Vehicle
{
private:
    int speed;
    std::string manufacturer;
protected:
    std::string model;
public:
    // A way allow access the data store in the private access modifier is with setters and getters
    void setSpeed(int speed)
    {
        if (speed >= 0)
        {
            this->speed = speed;
        }
    }
    int getSpeed()
    {
        return this->speed;
    }
    void setManufacturer(std::string manufacturer)
    {
        this->manufacturer = manufacturer;
    }
    std::string getManufacturer()
    {
        return this->manufacturer;
    }
    void setModel(std::string model)
    {
        this->model = model;
    }
    std::string getModel()
    {
        return this->model;
    }
    Plane(int speed, const std::string& manufacturer, const std::string& model) :
        speed(speed),
        manufacturer(manufacturer),
        model(model)
    {
    }
    void move()
    {
        std::cout << "Plane is flying" << std::endl;
    }
    // This next line is a method that will be use to explain polymorphism
    virtual void fly()
    {
        std::cout << model << " is flying at " << speed << " mph" << std::endl;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////// Polymorphism ////////////////////////////////////////////
/* Polymorphism is the ability of an object to take on many forms. In C++,
 * Runtime polymorphism in C++ can be achieved through inheritance and virtual functions.
 * Virtual functions allow a derived class to override a function from its base class,
 * providing a different implementation for the same function name.
 * This allows objects of different classes to be treated as objects of a common base class,
 * and the appropriate function to be called based on the actual object type at runtime.
 */
class FighterJet : public Plane
{
private:
    std::string armament;
public:
    FighterJet(int speed, const std::string& manufacturer, const std::string& model, const std::string& armament) : Plane(speed, manufacturer, model)
    {
        this->armament = armament;
    }
    // The derived class overrides the virtual function inherited from the base class and provides its own implementation
    void fly() override
    {
        std::cout << model << " is flying at " << getSpeed() << " mph with " << armament << std::endl;
    }
};

int main()
{

}


