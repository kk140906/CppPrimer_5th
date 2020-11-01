/*
 * Exercise 15.13
 * Exercise 15.14
 */
#include <iostream>

using namespace std;

class Base {
public:
    Base(const string &name) : basename(name) {}

    string name() const { return basename; }

    virtual void print(ostream &os) { os << basename; }

private:
    string basename;
};

class Derived : public Base {
public:
    Derived(const string &basename, const int &ii) : Base(basename), i(ii) {}

    void print(ostream &os) override final {
        Base::print(os);
        os << " " << i;
    }

private:
    int i;
};

int main() {

    cout << "-----------------base obj-------------------" << endl;
    Base b_obj("base");
    Derived d_obj("derived", 66);
    b_obj.print(cout);
    cout << endl;
    d_obj.print(cout);
    cout << endl;
    cout << "--------------base obj pointer---------------" << endl;
    Base *bp1 = &b_obj;
    Base *bp2 = &d_obj;
    bp1->print(cout);
    cout << endl;
    cout << bp1->name();
    cout << endl;
    bp2->print(cout);
    cout << endl;
    cout << bp2->name();
    cout << endl;
    cout << "-----------------base obj reference------------" << endl;
    Base &br1 = b_obj;
    Base &br2 = d_obj;
    br1.print(cout);
    cout << endl;
    cout << br1.name();
    cout << endl;
    br2.print(cout);
    cout << endl;
    cout << br2.name();
    cout << endl;
    return 0;
}

