Onux Standard
=============

## Use of `auto`

During assignment when the type can easily be determined.

```c++
// OK

auto var = 0;         // int
auto var = 0u;        // unsigned int
auto var = 0.0;       // double
auto var = 0.0f;      // float
auto var = "C-string" // const char*
auto var = Object();  // Object

// NOT OK

auto var = getAnything();    // Could be anything
auto var = Object::create(); // Could be Object, could be std::unique_ptr<Object>(), etc.
```

To defer specifying the return type of a member function **only** if the type is defined in the object (e.g. typedefs, using aliases, enums, nested classes).

```c++
class Object {
public:
    using MyInt = int;

public:
    MyInt getMyInt();

private:
    MyInt m_myInt;
};

auto Object::getMyInt() -> MyInt {
    return m_myInt;
}
```

## Aliases

Use ```using``` instead of ```typedef```.

```c++
// OK

using Strings = std::vector<std::string>;

// NOT OK

typedef std::vector<std::string> Strings;
```
