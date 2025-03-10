#include <iostream>

class Dan
{
    public:
        Dan(int data) : _data(data) {}
        int _data;
};

class Jed
{
    public:
        Jed(int data) : _data(data) {}
        Jed(Dan dan) : _data(dan._data) {}

        void Print()
        {
            std::cout << "My data is: " << _data << std::endl;
        }

        Jed operator+( const Jed& aRHS ) const noexcept
        {
            std::cout << "Calling the plus operation" << std::endl;
            return Jed( _data + aRHS._data * 2);
        }

    public:
        int _data;
};

int main()
{
    std::string jed2 = "hello world";
    Dan dan = 5;
    Jed jed1 = 5;
    Jed jed = jed1 + Jed(dan);
    jed.Print();
}
