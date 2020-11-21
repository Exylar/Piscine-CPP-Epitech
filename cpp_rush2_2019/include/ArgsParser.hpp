/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** ArgsParser
*/

#ifndef ARGSPARSER_HPP_
#define ARGSPARSER_HPP_

#include <arpa/inet.h>
#include <string>
#include "Santa.hpp"
#include "XMLParser.hpp"

class ArgsParser {
    public:
        static const int BuffSize = 8192;

        ArgsParser();
        ~ArgsParser();

        int checkArgs(int ac, const char **av);
        int serverLoop(std::string ip);
        int fileLoop(const char **files);
        int checkIp(int ac, const char **av);
        int setupServer(sockaddr_in *server, int *socketfd, std::string ip);
        int isDir(const char *path);

    private:
        Santa santa;
        XMLParser xmlParser;
};

#endif /* !ARGSPARSER_HPP_ */
