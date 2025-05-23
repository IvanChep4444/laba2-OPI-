#include <iostream>
#include <vector>
#include <memory>

/* The `If1` interface defines a method `meth1()` for base behavior. */
class If1 {
public:
    /* Executes the first method. */
    virtual void meth1() = 0;
    virtual ~If1() = default;
};

/* The `If2` interface extends `If1` and adds method `meth2()`. */
class If2 : public If1 {
public:
    /* Executes the second method. */
    virtual void meth2() = 0;
};

/* The `If3` interface defines an independent method `meth3()`. */
class If3 {
public:
    /* Executes the third method. */
    virtual void meth3() = 0;
    virtual ~If3() = default;
};

/* The `Cl3` class represents an auxiliary component with a simple output method. */
class Cl3 {
public:
    /* Displays a message indicating `Cl3` is active. */
    void show() {
        std::cout << "Cl3::show()\n";
    }
};

/* The `Cl2` class implements `If2` and stores a collection of `Cl3` objects. */
class Cl2 : public If2 {
private:
    std::vector<std::shared_ptr<Cl3>> new_attribute;  // List of associated Cl3 objects.

public:
    /* Adds a new `Cl3` object to the internal collection. */
    void addCl3(std::shared_ptr<Cl3> obj);

    /* Implements `meth1()` from `If1`. */
    void meth1() override;

    /* Implements `meth2()` from `If2` and calls `show()` for each `Cl3`. */
    void meth2() override;
};

void Cl2::addCl3(std::shared_ptr<Cl3> obj) {
    new_attribute.push_back(obj);
}

void Cl2::meth1() {
    std::cout << "Cl2::meth1()\n";
}

void Cl2::meth2() {
    std::cout << "Cl2::meth2()\n";
    for (const auto& obj : new_attribute) {
        obj->show();
    }
}

/* The `Cl1` class extends `Cl2` and maintains a list of `If1` parts. */
class Cl1 : public Cl2 {
private:
    std::vector<std::shared_ptr<If1>> parts;  // Composition of If1 parts.

public:
    /* Adds a part that implements `If1` to the internal list. */
    void addPart(std::shared_ptr<If1> part);

    /* Calls `meth1()` on all added parts. */
    void useParts();
};

void Cl1::addPart(std::shared_ptr<If1> part) {
    parts.push_back(part);
}

void Cl1::useParts() {
    for (auto& part : parts) {
        part->meth1();
    }
}

/* The `ImplIf3` class is a concrete implementation of the `If3` interface. */
class ImplIf3 : public If3 {
public:
    /* Implements `meth3()` and outputs a message. */
    void meth3() override;
};

void ImplIf3::meth3() {
    std::cout << "ImplIf3::meth3()\n";
}

/* Entry point demonstrating object creation, composition, and method execution. */
int main() {
    auto objCl3_1 = std::make_shared<Cl3>(); // Створює розумний вказівник на об'єкт "Cl3".
    auto objCl3_2 = std::make_shared<Cl3>(); // Створює розумний вказівник на об'єкт "Cl3".

    auto cl2 = std::make_shared<Cl2>(); // Створює розумний вказівник на об'єкт "Cl2".
    cl2->addCl3(objCl3_1); // Додає перший об'єкт `Cl3` до "cl2".
    cl2->addCl3(objCl3_2); // Додає другий об'єкт `Cl3` до "cl2".

    Cl1 cl1; // Створює об'єкт "Cl1".
    cl1.addPart(cl2); // Додає об'єкт `cl2` (який реалізує `If1` через успадкування) до `cl1`.
    cl1.useParts(); // Викликає метод `useParts()` об'єкта `cl1`, що призводить до виклику `meth1()` для `cl2`.

    cl2->meth2(); // Викликає метод `meth2()` об'єкта `cl2`, що виводить повідомлення та викликає `show()` для об'єктів `Cl3`.

    std::unique_ptr<If3> if3 = std::make_unique<ImplIf3>(); // Створює унікальний розумний вказівник на об'єкт `ImplIf3`.
    if3->meth3(); // Викликає метод `meth3()` об'єкта `if3`.

    return 0;
}
