/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** MyUnitTests
*/

#include <iostream>
#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

Object **MyUnitTests_Toys()
{
    Object **objects = new Object *[2];

    objects[0] = new LittlePony("happy pony");
    objects[1] = new Teddy("cuddles");
    return objects;
}

Object *MyUnitTests_Wrap(Object **array)
{
    Object *teddy = array[0];
    Object *box = array[1];
    Object *paper = array[2];

    if (!box->canWrap())
        return nullptr;
    ((Wrap *)box)->openMe();
    ((Wrap *)box)->wrapMeThat(teddy);
    ((Wrap *)box)->closeMe();
    if (!box->canWrap())
        return nullptr;
    ((Wrap *)paper)->wrapMeThat(box);
    return paper;
}

int Create_Toys(void)
{
    Object **objects = MyUnitTests_Toys();

    std::cout << objects[0]->getTitle() << std::endl;
    delete objects[0];
    std::cout << objects[1]->getTitle() << std::endl;
    delete objects[1];
    delete [] objects;
    return 0;
}

int Wrap_Toys(void)
{
    Object *elements[4] = {new Teddy(), new Box(), new GiftPaper(), nullptr};
    Object *present = MyUnitTests_Wrap(elements);

    if (present == nullptr) {
        std::cout << "That didn't worked..." << std::endl;
        return 0;
    }
    while (present->canWrap()) {
        Wrap *wrap = (Wrap *)present;
        std::cout << "Opening wrap: " << wrap->getTitle() << std::endl;
        wrap->openMe();
        present = wrap->getContent();
        delete wrap;
    }
    std::cout << "The gift that was in the box: " << present->getTitle() << std::endl;
    delete present;
    return 0;
}

int main(void)
{
    Create_Toys();
    Wrap_Toys();
}
