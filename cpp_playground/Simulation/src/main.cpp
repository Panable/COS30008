#include <iostream>

template <typename T>
class Dan
{
    public:
        Dan(T data) : _data(data) {}

        ~Dan()
        {
            std::cout << "I'm being destroyed" << std::endl;
        }

        T _data;
};

class Jed
{
};

int main()
{
    Dan<int> dan = 5;


    // std::string jed2 = "hello world";
    // Dan dan = 5;
    // Jed jed1 = 5;
    // Jed jed = jed1 + Jed(dan);
    // jed.Print();
}
