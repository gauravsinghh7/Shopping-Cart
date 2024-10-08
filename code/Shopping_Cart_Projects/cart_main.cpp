#include<iostream>
#include"datamodel.h"
#include<vector>
using namespace std;

vector<Product>allProducts={
    Product(1,"apple",26),
    Product(2,"guava",36),
    Product(3,"mango",16),
    Product(4,"banana",56),
    Product(5,"strawberry",29),
    Product(6,"pineApple",28)
};

Product* chooseProduct(){
    // Display the list of product

    string productList;
    cout<<"Available Products"<<endl;
    for(auto product: allProducts){
        productList.append(product.getDisplayName());
    }
    cout<< productList<<endl;
    cout<<"------------------"<<endl;
    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size();i++){
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product Not found!"<<endl;
    return NULL;
}
bool checkout( Cart &cart){
    if(cart.isEmpty())
        return false;
    int total=cart.getTotal();
    cout<<"Pay in Cash ";
    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change "<<paid-total<<endl;
        cout<<"Thankyou for Shopping.";
        return true;
    }
    else{
        cout<<"Not enough cash!"<<endl;
        return false;
    }
}


int main(){

    char action;
    Cart cart;

    while(true){
        cout<<"Select an action - (a)dd item , (v)iew cart , (c)heckout "<<endl;
        cin>>action;
        if(action=='a'){
            //ToDo:Add to cart
            // View All the Products + Choose the Product + add to the cart
            Product*product=chooseProduct();
            if(product!=NULL){
                cout<<" Added to the cart "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }
        }
        else if(action=='v'){
            // View the Cart
            cout<<"--------------"<<endl;
            cout<<cart.viewCart();
            cout<<"--------------"<<endl;
        }
        else{
            // checkout
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }

    return 0;
}