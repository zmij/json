# json
C++17 JSON Parser/Serializer Library.

### Usage concept
```
#include <zmij/json.hpp>

struct my_data {
    int a;
    float f;
    std::string s;
};

zmij::json::ostream&
operator << (zmij::json::ostream& os, my_data const& value)
{
    os << "a" << value.a
        << "f" << value.f
        << "s" << value.s;
}

zmij::json::istream&
operator >> (zmij::json::istream& is, my_data& value)
{
    is >> "a" >> value.a
        >> "f" >> value.f
        >> "s" >> value.s;
}

int
main(int argc, char* argv[])
{
    zmij::json::istream json_in = zmij::json::istream::open("input.json");
    my_data data;
    json_in >> data;
    
    zmij::json::ostream json_out = zmij::json::ostream::open("output.json");
    json_out << data;
}
```

