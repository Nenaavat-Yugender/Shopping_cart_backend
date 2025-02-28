#include <unordered_map>
#include <string>
using namespace std;

//forward declaration of the classes
class Item;
class Cart;

class Product{
    // these all are class variables
    int id;                                               
    string name;
    int price;
 public:
    // default constructor
    Product(){}
    // constructor accessing the class variables, name, price and id
    Product(int u_id, string name, int price){
        id = u_id;
        // this->name is used to refer to the class variable name
        this->name = name;                             
        this->price = price;
    }
    //creating a method to get the display name and the price of the item in the cart
    string getDisplayName(){
        return name + " : Rs " + to_string(price) + "\n";
    }
    //creating a method to get the short name of the item in the cart
    // ex: for apple it will return a, for banana it will return b and so on
    string getShortName(){
        return name.substr(0,1);
    }
    //making item class and product class friends so that they can access each other's private variables 
    friend class Item;
    friend class Cart;
};


class Item{
    Product product;
    int quantity;                                    
public:
    //default constructor
    Item(){}
    //constructor using initialization list to access the product and quantity
    Item(Product p, int q): product(p), quantity(q){} 

    int getItemPrice(){
        return quantity * product.price;
    }
    string getItemInfo(){
        return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity * product.price) + "\n";
    }

    friend class Cart;

};

//to impliment cart will use unorderd map(i.e hashmap) in which id=key and item=value
//and will use vector to store the items in the cart
class Cart{
    //ToDo
    //Cpllection
    unordered_map<int, Item> items;
public:

    void addProduct(Product product){
        if(items.count(product.id) == 0){
            Item newItem(product,1);
            items[product.id] = newItem;
        }
        else{
            items[product.id].quantity +=1;
        }

    }

    int getTotal(){
        //todo
        int total = 0;
        for(auto itemPair : items){
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;    

    }

    string viewCart(){
        if(items.empty()){
            return "Cart is empty";
        }
        string itemizedList;
        int cart_total = getTotal();

        for(auto itemPair : items){
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }
        return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + "\n";
    }

    bool isEmpty(){
        return items.empty();
    }



};