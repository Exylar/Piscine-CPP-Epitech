/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** test_my_args_perser
*/

#include <criterion/criterion.h>
#include "ArgsParser.hpp"

Test(ip, wrong_number_args)
{
    ArgsParser argsParser;
    const char *av[] = {"./santa", "-w"};
    int ac = 2;

    cr_assert_eq(argsParser.checkArgs(ac, av), -1);
}

Test(ip, wrong_ip_1)
{
    ArgsParser argsParser;
    const char *av[] = {"./santa", "-w", "..."};
    int ac = 3;

    cr_assert_eq(argsParser.checkArgs(ac, av), -1);
}

Test(ip, wrong_ip_2)
{
    ArgsParser argsParser;
    const char *av[] = {"./santa", "-w", "235.250.250."};
    int ac = 3;

    cr_assert_eq(argsParser.checkArgs(ac, av), -1);
}

Test(ip, wrong_ip_3)
{
    ArgsParser argsParser;
    const char *av[] = {"./santa", "-w", "233.255.255.250"};
    int ac = 3;

    cr_assert_eq(argsParser.checkArgs(ac, av), -1);
}

Test(normal, good_file)
{
    ArgsParser argsParser;
    const char *av[] = {"./santa", "./gift1.xml"};
    int ac = 2;

    cr_assert_eq(argsParser.checkArgs(ac, av), 0);
}

Test(normal, wrong_file)
{
    ArgsParser argsParser;
    const char *av[] = {"./santa", "./gift1.xl"};
    int ac = 2;

    cr_assert_eq(argsParser.checkArgs(ac, av), 0);
}

Test(setup_server, all_good)
{
    ArgsParser argsParser;
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in server;

    cr_assert_eq(argsParser.setupServer(&server, &socketfd, "235.255.255.250"), 0);
}