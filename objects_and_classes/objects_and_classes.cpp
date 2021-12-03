#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;
//functions for styling
void  highlight (string s);
void  put_line  (string s);
void  yellow    (string s);
void  grean     (string s);

class Reqtangle
{
protected:
    int length;
    int width;

public:
    Reqtangle()
    {
        grean("Reqtangle");
        length = 0;
        width  = 0;
    }

    Reqtangle(int req_length, int req_width)
    {
        grean("Reqtangle(int x, int y)");
        this->length = req_length;
        this->width  = req_width;
    }

    Reqtangle(Reqtangle &obj)
    {
        grean("Rectangle(Reqtangle &obj)");
        length = obj.length;
        width = obj.width;
    }

    ~Reqtangle()
    {
        printf("\n~Reqtangle() ");
        printf(" length = %d, width = %d\n", length, width);
    }
    void draw();
};

void Reqtangle::draw()
{
    int a, b;

    grean("draw");
    printf("\033[1;32m");
    for (a = 0; a != length; a++) 
    {
        for (b = 0; b != width; b++) 
        {
            if ((a == 0) || (a == length - 1) || (b == width - 1) || (b == 0))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\033[0m");
}

int main()
{
    yellow("====================================");
    highlight("Static allocation...................");
    {
        Reqtangle req1;
        Reqtangle req2(2, 3); 
        Reqtangle req3(req2);
    }
    yellow("====================================");

    yellow("====================================");
    highlight("Dynamic allocation..................");
    Reqtangle *req1 = new Reqtangle();
    Reqtangle *req2 = new Reqtangle(5,10);
    Reqtangle *req3 = new Reqtangle(*req2);
    req2->draw();
    delete     req1;
    delete     req2;
    delete     req3;
    yellow("====================================");

    return 0;
}


//funtions for styling the output
void grean    (string s){printf("\033[1;32m"); cout << endl << s << endl; printf("\033[0m");}
void yellow   (string s){printf("\033[1;33m"); cout << endl << s << endl; printf("\033[0m");}
void put_line (string s){printf("\033[1;4m" ); cout << endl << s << endl; printf("\033[0m");}
void highlight(string s){printf("\033[1;7m" ); cout << endl << s << endl; printf("\033[0m");}
