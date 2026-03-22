// Q1.Create an application for e-commerce.

// Create a class Person with data members name.

// Create a class called as Seller with data members Seller_name, Id

// Create class Product with data members id,product_name,price

// Each Saller sells few products.

// Have proper relationships.

// Write a menu driven code which will have below menus

// 1. Add Seller

// 2. Add Product

// 3. Display products sold by specific seller

// 4. Display All Sellers

// 5. Display All Products

// use of STL(Vector) is allowed, Inheritance is compulsory.

// Marks Distribution:-

// 1 Class Person, Seller, Product

// 2 Add Seller

// 3 Add Product

// 4 Display all products sold by specific seller

// 5 Display All Sellers

// 6 Display All Products

// 7 Menu Driven Program

// 8 Code modularity+ Naming Conventions + Comments

#include<iostream>
#include<vector>
using namespace std;
 
class Product
{
    private:
    int id;
    string proname;
    double price;

    public:
    Product(void) : id(0), proname(""), price(0.0)
    {   }
    Product(int id, string proname, double price) : id(id), proname(proname), price(price)
    {   }

    int getProductId(void)
    {
        return this->id;
    }

    void addProduct(void)
    {
        cout<<"enter product id : ";
        cin>>this->id;
        cout<<"enter product name : ";
        cin>>this->proname;
        cout<<"enter product price : ";
        cin>>this->price;
    }

    void displayProduct(void)
    {
        cout<<"id : "<<this->id<<endl;
        cout<<"name : "<<this->proname<<endl;
        cout<<"price : "<<this->price<<endl;
    }
};

class Person
{
    private:
    string name;

    public:
    Person(void) : name("")
    {   }
    Person(string name) : name(name)
    {   }

    virtual void acceptRecord(void)
    {
        cout<<"enter name : ";
        cin>>this->name;
    }

    virtual void displayRecord(void)
    {
        
        cout<<"name : "<<this->name<<endl;
    }

};

class Seller : public Person
{
    private:
    int sid;
    vector<Product*> proAddress;

    public:
    Seller(void) : Person(), sid(0)
    {   }
    Seller(string name, int sid) : Person(name), sid(sid)
    {   }

    int getSellerId()
    {
        return this->sid;
    }

    void addProduct(Product* product)
    {
        proAddress.push_back(product);
    }

    void acceptRecord(void)
    {
        Person :: acceptRecord();
        cout<<"enter seller id: ";
        cin>>this->sid;
    }

    void displayRecord(void)
    {
        Person :: displayRecord();
        cout<<"seller id : "<<this->sid<<endl;
    } 

    void displayProductSold(void)
    {
        for(int i=0; i<proAddress.size(); i++)
        {
            proAddress[i]->displayProduct();
        }
    }
};



///////////////////////////////////////////////
vector<Seller*> seller_list;
vector<Product*> product_list;
///////////////////////////////////////////

void addPrductInsideSeller(void)
{
    
}

int getSellerIndexFromId(int sellid)
{
    for(int i=0; i<seller_list.size(); i++)
    {
        if(sellid == seller_list[i]->getSellerId())
            return i;
    }
    return -1;
}

int getProductIndexFromId(int proid)
{
    for(int i=0; i<product_list.size(); i++)
    {
        if(proid == product_list[i]->getProductId())
        {
            return i;
        }
    }
    return -1;
}



int menuList()
{
    int choice;
    cout<<"\n 0. Exit \n 1. Add seller \n 2. Add product \n 3. add product to seller \n 4. Display all products sold by specid=fic seller \n 5. Display all sellers \n 6. Display all products \n";
    cin>>choice;
    return choice;
}

int main()
{
    int choice;


    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            //add seller
            case 1:
            {
                Seller *s = new Seller();
                s->acceptRecord();
                seller_list.push_back(s);
                break; 
            }

            //add product
            case 2:
            {
                Product *p = new Product();
                p->addProduct();
                product_list.push_back(p);
                break;
            }

            //add product to seller
            case 3:
            {
                int sellid;
                int proid;
                cout<<"enter the product id: ";
                cin>>proid;
                cout<<"enter the seller id: ";
                cin>>sellid;

                int proIndex = getProductIndexFromId(proid);
                int sellIndex = getSellerIndexFromId(sellid);

                seller_list[sellIndex]->addProduct(product_list[proIndex]);
                break;
            }

            //product sold by specific seller
            case 4:
            {
                int sellid;
                int index;
                cout<<"enter seller id : ";
                cin>>sellid;

                index = getSellerIndexFromId(sellid);

                seller_list[index]->displayProductSold();

                break;
            }

            // display all sellers
            case 5:
            {
                for(int i=0; i<seller_list.size(); i++)
                {
                    cout<<"-------------------------------"<<endl;
                    seller_list[i]->displayRecord();
                    cout<<"------------------------------"<<endl;
                }
                break;
            }

            //display all products
            case 6:
            {
                for(int i=0; i<product_list.size(); i++)
                {
                    cout<<"--------------------------------"<<endl;
                    product_list[i]->displayProduct();
                    cout<<"---------------------------------"<<endl;
                }
                break;
            }
        }
    }
    return 0;
}
