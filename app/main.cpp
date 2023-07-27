#include "shubh.h"

int main(void)
{
    Shubham *shubh = new Shubham("Shubham Kumar", 9835);
    shubh->display_info();
    delete shubh;
    return 0;
}