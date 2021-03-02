#include <vector>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>
#include <iostream>

using namespace std;

class animal
{
public:
    virtual ~animal() {}
    virtual std::string kind() const = 0;
};
using animal_ptr = std::unique_ptr<animal>;
template <typename T>
animal_ptr make_animal(T &&t)
{
    using type = std::remove_cvref_t<T>;
    return animal_ptr{new type(std::forward<T>(t))};
}

class Cat : public virtual animal
{

public:
    string kind() const override
    {

        return "Felis catus"s;
    }
};

class Dog : public virtual animal
{
private:
    
    string str_name;

public:
    Dog() = delete;
    Dog(Dog const &) = default;
    Dog &operator=(Dog const &) = default;
    Dog(std::string const &name) : str_name{name}
    {
    }

    std::string kind() const override
    {
        using namespace std::literals;
        return "Canis lupus familiaris";
    }

    std::string const& name() const
    {
        return str_name;
    }
};

class dogcat : virtual public Dog, virtual public Cat
{
public:

    dogcat():
    Dog("hybrid"),
        Cat{}
    {
    }

    dogcat(Dog const &d, Cat const &c) : Dog(d), Cat(c)
    {
    }

    dogcat(dogcat const &) = default;
    dogcat &operator=(dogcat const &) = default;

    std::string kind() const override
    {
        return Dog::kind() + " + " + Cat::kind();
    }
};

 dogcat operator + (Dog const &d, Cat const &c)

    {
        return dogcat(d, c);
    }


int main ()
{

    std::vector<animal_ptr> v;
    Dog d("Fido");
    Cat c;

    v.push_back(make_animal(d));
    v.emplace_back(new Cat);
    v.push_back(make_animal(d + c));


    for (auto const& e: v)
    {
        cout << e->kind();
        auto p = dynamic_cast<Dog *>(e.get());
        if (p)
        {
            cout << ", name = " << p->name();
        }
        cout << '\n';
    }


    return 0;
}