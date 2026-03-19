#include<iostream>
using namespace std;

class Matrix
{
    private:
    int rows;
    int cols;
    int **data;

    public:
    Matrix(void) : rows(0), cols(0)
    {   }
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    { 
        data = new int*[rows];
        for(int i = 0; i<rows; i++)
        {
            data[i] = new int[cols];
        }

    }

    ~Matrix()
    {
        for(int i = 0; i<rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void accept(void)
    {
        cout<<"enter no. of rows : ";
        cin>>this->rows;
        cout<<"enter no. of columns : ";
        cin>>this->cols;

        for(int i = 0; i<this->rows; i++)
        {
            for(int j = 0; j<this->cols; j++)
            {
                printf("\n data[%d][%d] : ", i, j);
                cin>>data[i][j];  
            }
        }
    }

    void display(void)
    {
        cout<<"no. of rows : "<<this->rows<<endl;
        cout<<"no. of cols : "<<this->cols<<endl;

        cout<<"matrix : "<<endl;
        for(int i=0; i<this->rows; i++)
        {
            for(int j=0; j<this->cols; j++)
            {
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Matrix m1;
    m1.accept();
    m1.display();

    return 0;

}