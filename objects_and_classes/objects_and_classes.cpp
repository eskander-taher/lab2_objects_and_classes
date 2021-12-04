#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;
//functions for styling
void  highlight (string s);
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
    
    int area() 
    {
        return (length * width);
    }
};

class RoundedReqtangle : public Reqtangle
{
protected:
    int radus;

public:
    RoundedReqtangle() : Reqtangle ()
    {
        grean("RoundedReqtangle");
        radus = 0;
    }

    RoundedReqtangle(int req_length, int req_width, int req_radus) : Reqtangle(req_length, req_width)
    {
        grean("RoundedReqtangle(int x, int y, int radus)");
        this->radus = req_radus;
    }

    RoundedReqtangle(RoundedReqtangle& obj)
    {
        grean("RoundedReqtangle(RoundedReqtangle& obj)");
        length = obj.length;
        width = obj.width;
        radus = obj.radus;
    }

    ~RoundedReqtangle()
    {
        printf("\n~RoundedReqtangle() ");
        printf("\nlength = %d, width = %d, radus = %d\n", length, width, radus);
    }
    
    void changeRadus(int new_radus)
    {
        radus = new_radus;
    }
};

void Reqtangle::draw()
{
    int a, b, edge = 0;

    grean("draw");
    printf("\033[1;32m");
    for (a = 0; a != length; a++) 
    {
        for (b = 0; b != width; b++) 
        {
            if ((a == 0) || (a == length - 1) || (b == width - 1) || (b == 0)) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
    printf("\033[0m");
}

class Cubic
{
protected:
    Reqtangle *req1;
    Reqtangle *req2;
public:
    Cubic()
    {
        printf("\nCubic()\n");
        req1 = new Reqtangle();
        req2 = new Reqtangle();
    }

    Cubic(int length, int width)
    {
        printf("\nCubic(int length, int width)\n");
        req1 = new Reqtangle(length, width);
        req2 = new Reqtangle(length, width);
    }

    Cubic(const Cubic& c)
    {
        printf("\nCubic(const Cubic &c)\n");

        req1 = new Reqtangle(*(c.req1));
        req2 = new Reqtangle(*(c.req2));
    }

    ~Cubic()
    {
        printf("\n~Cubic()\n");
        delete req1;
        delete req2;
    }
};

int main()
{
    yellow("=====================================");
    yellow("..........Static allocation..........");
    {
        Reqtangle req1;
        Reqtangle req2(2, 3); 
        Reqtangle req3(req2);
    }
    yellow("=====================================");

    yellow("=====================================");
    yellow("..........Dynamic allocation.........");
    {
        Reqtangle *req1 = new Reqtangle();
        Reqtangle *req2 = new Reqtangle(4,5);
        Reqtangle *req3 = new Reqtangle(*req2);
        delete     req1;
        delete     req2;
        delete     req3;
    }
    yellow("=====================================");

    yellow("=====================================");
    yellow("..............Methods................");
    {
        Reqtangle req(19, 19);
        req.draw();
        printf("Area of reqtangle = %d\n", req.area());
    }
    yellow("=====================================");

    yellow("=====================================");
    yellow("..........Inherited class............");

    {
        RoundedReqtangle* rounded = new RoundedReqtangle(8, 9, 2);
        rounded->changeRadus(5);
        delete rounded;
    }
    yellow("=====================================");

    yellow("=====================================");
    yellow("..........class relations............");
    {
        Cubic* cub1 = new Cubic();
        Cubic* cub2 = new Cubic(10, 10);
        Cubic* cub3 = new Cubic(*cub2);
        delete cub1;
        delete cub2;
        delete cub3;
    }
    yellow("=====================================");

    system("pause");
    return 0;
}


//funtions for styling the output
void grean    (string s){printf("\033[1;32m"); cout << endl << s << endl; printf("\033[0m");}
void yellow   (string s){printf("\033[1;33m"); cout << endl << s << endl; printf("\033[0m");}
void highlight(string s){printf("\033[1;7m" ); cout << endl << s << endl; printf("\033[0m");}
