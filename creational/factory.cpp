#include <iostream>

/*
 * @startuml
 * object Product
 * object ProductA
 * object ProductB
 * ProductA ..|> Product
 * ProductB ..|> Product
 * 
 * object Creator
 * object CreatorA
 * object CreatorB
 * CreatorA --|> Creator
 * CreatorB --|> Creator
 * 
 * Creator -> Product
 * @enduml
 */
class Product {
    public:
    virtual void do_something(void) = 0;
};

class ProductA : public Product {
    public:
    virtual void do_something(void) override {
        std::cout << "ProductA: do_something" << std::endl;
    }
};

class ProductB : public Product {
    public:
    virtual void do_something(void) override {
        std::cout << "ProductB: do_something" << std::endl;
    }
};

class Creator {
    protected:
    virtual Product &create(void) = 0;
    public:
    void do_something(void) {
        std::cout << "Creator: do_something" << std::endl;
        Product &p = this->create();
        p.do_something();
        delete &p;
    }
};

class CreatorA : public Creator {
    protected:
    virtual Product &create(void) override {
        std::cout << "CreatorA: create" << std::endl;
        return *new ProductA();
    }
};

class CreatorB : public Creator {
    protected:
    virtual Product &create(void) override {
        std::cout << "CreatorB: create" << std::endl;
        return *new ProductB();
    }
};

int main(int argc, char* argv[]) {
    Creator &creatorA = *new CreatorA();
    Creator &creatorB = *new CreatorB();

    creatorA.do_something();
    creatorB.do_something();
    
    delete &creatorA;
    delete &creatorB;

    return 0;
}
