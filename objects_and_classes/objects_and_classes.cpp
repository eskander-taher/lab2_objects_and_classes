#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;
//function for styling
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

    Reqtangle(int x, int y)
    {
        grean("Reqtangle(int x, int y)");
        this->length = x;
        this->width  = y;
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
};


int main()
{
    yellow("====================================");
    highlight("Static allocation");
    {
        Reqtangle req1;
        Reqtangle req2(2, 3); 
        Reqtangle req3(req2);
    }
    yellow("====================================");

    yellow("====================================");
    highlight("Dynamic allocation");
    Reqtangle *req1 = new Reqtangle();
    Reqtangle *req2 = new Reqtangle(4,5);
    Reqtangle *req3 = new Reqtangle(*req2);
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
