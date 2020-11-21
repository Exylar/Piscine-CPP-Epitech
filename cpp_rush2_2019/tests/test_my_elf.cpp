/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** test_my_elf
*/

#include <criterion/criterion.h>
#include "IElf.hpp"
#include "PapaXmasElf.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "ConveyorBeltRand.hpp"
#include "TableRand.hpp"

Test(makeAGift, for_coverage)
{
    ITable *table = new PapaXmasTable();
    IConveyorBelt *conveyor = new PapaXmasConveyorBelt();
    IElf *elf = new PapaXmasElf(table, conveyor);

    cr_assert_eq(elf->wrapGift(), true);
    cr_assert_eq(elf->wrapGift(), true);
    cr_assert_eq(elf->wrapGift(), false);
}

Test(makeAGift, conveyor_belt_rand)
{
    srand(42);
    ITable *table = new PapaXmasTable();
    IConveyorBelt *conveyor = new ConveyorBeltRand();
    IElf *elf = new PapaXmasElf(table, conveyor);

    cr_assert_eq(elf->wrapGift(), true | false);
    cr_assert_eq(elf->wrapGift(), true | false);
    cr_assert_eq(elf->wrapGift(), true | false);
}

Test(makeAGift, tableRand)
{
    srand(42);
    ITable *table = new TableRand();
    IConveyorBelt *conveyor = new PapaXmasConveyorBelt();
    IElf *elf = new PapaXmasElf(table, conveyor);

    cr_assert_eq(elf->wrapGift(), true | false);
    cr_assert_eq(elf->wrapGift(), true | false);
    cr_assert_eq(elf->wrapGift(), true | false);
}