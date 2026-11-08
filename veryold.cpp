#include <iostream>
#include <string>
#include <vector>
#include <memory> 

using namespace std;


enum class OrderState {
    Accepted,  
    Preparing, 
    Delivered  
};

class Dish {
protected:
    string name;
    double price;
public:
    Dish(string n, double p) {
        name = n;
        price = p;
    }
    
    virtual ~Dish() {} 
    
    virtual void info() const {
        cout << "- " << name << " (price: " << price << " uah)";
    }
};

class Pizza : public Dish {
public:
    Pizza() : Dish("pizaa 'margarita'", 250.0) {}
};

class Burger : public Dish {
public:
    Burger() : Dish("cheezburger", 150.0) {}
};

class Salad : public Dish {
public:
    Salad() : Dish("salat 'cezar'", 180.0) {}
};

class Order {
private:
    vector<unique_ptr<Dish>> dishes;
    OrderState state;

public:
    Order() {
        state = OrderState::Accepted;
        cout << "status: Accepted!";
    }


    void addDish(unique_ptr<Dish> dish) {
        dishes.push_back(move(dish)); 
    }

    void nextState() {
        if (state == OrderState::Accepted) {
            state = OrderState::Preparing;
            cout << "status: order cooking";
        } 
        else if (state == OrderState::Preparing) {
            state = OrderState::Delivered;
            cout << "status:order delivered";
        } 
        else if (state == OrderState::Delivered) {
            cout << "error: order already dilevered. status cant be change.";
        }
    }

    void showOrder() const {
        cout << "your order";
        if (dishes.empty()) {
            cout << "order empty" <<;
            return;
        }
        
        for (int i = 0; i < dishes.size(); i++) {
            dishes[i]->info();
        }
    }
};

int main() {
    Order myOrder;

    myOrder.addDish(make_unique<Pizza>());
    myOrder.addDish(make_unique<Burger>());
    myOrder.addDish(make_unique<Salad>());
    myOrder.showOrder();
    myOrder.nextState();
    myOrder.nextState(); 
    myOrder.nextState(); 
    return 0; 
}