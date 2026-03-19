#include<iostream>
using namespace std;

class Product
{
    private:
    string title;
    double price;

    public:
    Product(void) : title(""), price(0.0)
    {   }
    Product(string title, double price) : title(title), price(price)
    {   }

    virtual void accept(void)
    {
        cout<<"enter title : ";
        cin>>this->title;
        cout<<"enter price : ";
        cin>>this->price;
    }

    virtual void display(void)
    {
        cout<<"title : "<<this->title<<endl;
        cout<<"price : "<<this->price<<endl;
    }
};

class Book : public Product
{
    private:
    int pages;

    public:
    Book(void) : Product(), pages(0)
    {   }
    Book(string title, double price, int pages) : Product(title, price), pages(pages)
    {   }

    int getPages(void)
    {
        return this->pages;
    }

    void accept()
    {
        Product :: accept();
        cout<<"enter number of pages : ";
        cin>>this->pages;
    }

    void display()
    {
        Product :: display();
        cout<<"pages : "<<this->pages<<endl;
    }
};

class Tape : public Product
{
    private:
    int playtime;

    public:
    Tape(void) : Product(), playtime(0.0)
    {   }
    Tape(string title, double price, int playtime) : Product(title, price), playtime(playtime)
    {   }

    int getPlaytime(void)
    {
        return this->playtime;
    }

    void accept(void)
    {
        Product :: accept();
        cout<<"enter the playtime(minutes) : ";
        cin>>this->playtime;
    }

    void display(void)
    {
        Product :: display();
        cout<<"playtime : "<<this->playtime<<endl;
    }
};

class Exception
{
    private:
    string msg;
    int value;

    public:
    Exception(string msg) : msg(msg)
    {   }
    Exception(int value) : value(value)
    {   }

    string getMsg(void)
    {
        return this->msg;
    }
    
};

int menuList(void)
{
    int choice;
    cout<<"\n 0. Exit \n 1. Add Book \n 2. Add Tape \n 3. show pages \n 4. show playtime \n";
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    int i = 0;
    int count;

    cout<<"enter the no of products to enter : ";
    cin>>count;
    Product *arr[count];

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
                try
                {
                    if(i>(count-1))
                    {
                        throw Exception(1);
                    } 
                }
                catch(Exception e)
                {
                    cout<<e.getMsg();

                    break;
                }
                
                arr[i] = new Book;
                arr[i]->accept();
                i++;

                break;
            }

            case 2:
            {
                if(i>4)
                {
                    cout<<"Array is Full"<<endl;
                    break;
                }
                arr[i] = new Tape;
                arr[i]->accept();
                i++;

                break;
            }

            case 3:
            {
                for(int j=0; j<i; j++)
                {
                    if(typeid(*arr[j]) == typeid(Book))
                    {
                        Book *bk = (Book*) arr[j];   //downcasting
                        cout<<"pages : "<<bk->getPages()<<endl;
                    }
                }
                
                break;
                
            }

            case 4:
            {
                for(int j=0; j<i; j++)
                {
                    if(typeid(*arr[j]) == typeid(Tape))
                    {
                        Tape *tp = (Tape*) arr[j];   //downcasting
                        cout<<"playtime : "<<tp->getPlaytime()<<endl;
                    }
                }

                break;

            }
        }
    }
    return 0;

}