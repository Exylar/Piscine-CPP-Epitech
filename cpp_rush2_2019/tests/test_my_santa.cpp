/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** test_my_santa
*/

#include <criterion/criterion.h>
#include <OSRedirector.hpp>
#include "Santa.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"

Test(check_gift, good)
{
    Santa santa;
    Object *paper = new GiftPaper();
    Object *box = new Box();
    Object *toy = new Teddy();

    ((Wrap *)box)->openMe();
    ((Wrap *)box)->wrapMeThat(toy);
    ((Wrap *)box)->closeMe();

    ((Wrap *)paper)->wrapMeThat(box);
    ((Wrap *)paper)->closeMe();
    cr_assert_eq(santa.checkGift(paper), true);
}

Test(check_gift, null_ptr)
{
    Santa santa;

    cr_assert_eq(santa.checkGift(nullptr), false);
}

Test(check_gift, toy_input)
{
    Santa santa;
    Object *toy = new Teddy();

    cr_assert_eq(santa.checkGift(toy), false);
}

Test(check_gift, toy_in_box_only)
{
    Santa santa;
    Object *box = new Box();
    Object *toy = new Teddy();

    ((Wrap *)box)->openMe();
    ((Wrap *)box)->wrapMeThat(toy);
    ((Wrap *)box)->closeMe();
    cr_assert_eq(santa.checkGift(box), false);
}

Test(check_gift, box_only)
{
    Santa santa;
    Object *box = new Box();

    cr_assert_eq(santa.checkGift(box), false);
}

Test(check_gift, box_in_paper_only)
{
    Santa santa;
    Object *paper = new GiftPaper();
    Object *box = new Box();

    ((Wrap *)paper)->wrapMeThat(box);
    ((Wrap *)paper)->closeMe();
    cr_assert_eq(santa.checkGift(paper), false);
}