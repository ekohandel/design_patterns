#include <iostream>

class ProductA {
    public:
    virtual void do_something(void) = 0;
};

class ProductB {
    public:
    virtual void do_something(void) = 0;
};

class ProductA1 : public ProductA {
    public:
    virtual void do_something(void) override {
        std::cout << "ProductA1: do_something" << std::endl;
    }
};

class ProductB1 : public ProductB {
    public:
    virtual void do_something(void) override {
        std::cout << "ProductB1: do_something" << std::endl;
    }
};

class ProductA2 : public ProductA {
    public:
    virtual void do_something(void) override {
        std::cout << "ProductA2: do_something" << std::endl;
    }
};

class ProductB2 : public ProductB {
    public:
    virtual void do_something(void) override {
        std::cout << "ProductB2: do_something" << std::endl;
    }
};

class Creator {
    public:
    virtual ProductA &createA(void) = 0;
    virtual ProductB &createB(void) = 0;
};

class Creator1 : public Creator {
    protected:
    virtual ProductA &createA(void) override {
        std::cout << "Creator1: create" << std::endl;
        return *new ProductA1();
    }
    virtual ProductB &createB(void) override {
        std::cout << "Creator1: create" << std::endl;
        return *new ProductB1();
    }
};

class Creator2 : public Creator {
    protected:
    virtual ProductA &createA(void) override {
        std::cout << "Creator2: create" << std::endl;
        return *new ProductA2();
    }
    virtual ProductB &createB(void) override {
        std::cout << "Creator2: create" << std::endl;
        return *new ProductB2();
    }
};

void create_products(Creator &creator) {
    ProductA &productA = creator.createA();
    productA.do_something();
    delete &productA;

    ProductB &productB = creator.createB();
    productB.do_something();
    delete &productB;
}

int main(int argc, char* argv[]) {
    Creator &creator1 = *new Creator1();
    create_products(creator1);
    delete &creator1;

    Creator &creator2 = *new Creator2();
    create_products(creator2);
    delete &creator2;

    return 0;
}
