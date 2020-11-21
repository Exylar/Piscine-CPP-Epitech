/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** main
*/

#include <unistd.h>
#include <iostream>
#include <string.h>
#include <tuple>
#include "PapaXmasElf.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasTable.hpp"
#include "TableRand.hpp"
#include "ConveyorBeltRand.hpp"
#include "MagicalCarpet.hpp"

IElf *CreateDefaultElf(bool nullTable, bool nullBelt)
{
    ITable *table = createTable();
    IConveyorBelt *belt = createConveyorBelt();
    IElf *elf = new PapaXmasElf(!nullTable ? table : nullptr, !nullBelt ? belt : nullptr);

    return elf;
}

IElf *CreateRandomElf()
{
    ITable *table = new TableRand();
    IConveyorBelt *belt = new ConveyorBeltRand();
    IElf *elf = new PapaXmasElf(table, belt);

    return elf;
}

IElf *CreateMagicalElf(char *ip)
{
    ITable *table = createTable();
    IConveyorBelt *belt = new MagicalCarpet(ip);
    IElf *elf = new PapaXmasElf(table, belt);

    return elf;
}

IElf *CreateMagicalElfRand(char *ip)
{
    ITable *table = new TableRand();
    IConveyorBelt *belt = new MagicalCarpet(ip);
    IElf *elf = new PapaXmasElf(table, belt);

    return elf;
}

int main(int argc, char *argv[])
{
    srandom(time(NULL));
    IElf *elf;
    bool nullTable = false;
    bool nullBelt = false;

    if (argc < 2)
        return 1;
    if (strcmp(argv[1], "default") == 0) {
        if (argc >= 3)
            nullTable = argv[2][0] == '1';
        if (argc >= 4)
            nullBelt = argv[3][0] == '1';
        elf = CreateDefaultElf(nullTable, nullBelt);
    }
    else if (strcmp(argv[1], "random") == 0)
        elf = CreateRandomElf();
    else if (argc >= 3 && strcmp(argv[1], "magic") == 0)
        elf = CreateMagicalElf(argv[2]);
    else if (argc >= 3 && strcmp(argv[1], "magic_random") == 0)
        elf = CreateMagicalElfRand(argv[2]);
    else
        return 1;
    while (elf->wrapGift());
    delete elf->getConveyor();
    delete elf;
    return 0;
}
