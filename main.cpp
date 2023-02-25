#include <iostream>

int main() {
    int i =3;
    int &j = i;
    int *h = &i;
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << *h << std::endl;
    return 0;
}
