#include <iostream>
#include <vector>
#include "datamodel.h"
using namespace std;

//creating a vector of products, Product is a class defined in datamodel.h
vector<Product> allProducts = {
    Product(1, "apple     ", 36),
    Product(2, "banana    ", 56),
    Product(3, "orange    ", 28),
    Product(4, "grapes    ", 90),
    Product(5, "pineapple ", 80),
    Product(6, "mango     ", 150),
    Product(7, "strawberry", 200),
    Product(8, "watermelon", 60),
    Product(9, "kiwi      ", 90),
    Product(10,"guava     ", 40),
};

Product* chooseProduct(){

    //display the list of products
    string productList;
    cout<<"Available products:" <<endl;

    for(auto product : allProducts){
        productList.append(product.getDisplayName());
    }
    cout << productList <<endl;

    cout<<"-----------------------------------"<<endl;
    string choice;
    cin>>choice;

    //using linear search  algorithem to find the product choosen by the user
    for(int i=0; i<allProducts.size(); i++){
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not found. Please try again."<<endl;
    return NULL;
}

bool chcekout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"Total amount to be paid : Rs. "<<total<<endl;
    cout<<"Pay in cash : ";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change  "<<paid-total<<endl;
        cout<<"Thank you for shopping with us. \n "<<endl;
        return true;
    }
    else{
        cout<<"Insufficient amount. Please try again."<<endl;
        return false;
    }

}

int main(){

    char action;
    Cart cart;

    while(true){
        cout<<"Select an action - (a)dd item, (v)iew cart, (c)heckout" <<endl;
        cin>> action;

        if(action == 'a'){
           //TODO: Add item to cart
           //view all products + choose product + add to the cart
           Product * product = chooseProduct();
           if(product != NULL){
            cout<<"Added to the cart "<<product->getDisplayName()<<endl;
            cart.addProduct(*product);

           }

        }
        else if(action =='v'){
           //TODO: View the cart 
           cout<<"-----------------------------------"<<endl;
           cout<<cart.viewCart()<<endl;
           cout<<"-----------------------------------"<<endl;

        }
        else if(action == 'c'){
           //TODO: Checkout  
           cart.viewCart();
           if(chcekout(cart)){
                break;
            }

        }
        else{
            cout<<"Invalid action. Please try again."<<endl;
        }
    }


    return 0;

} 