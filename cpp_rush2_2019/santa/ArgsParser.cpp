/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** ArgsParser
*/

#include <cstring>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ArgsParser.hpp"

const std::string ipMode = "-w";

ArgsParser::ArgsParser()
{
}

ArgsParser::~ArgsParser()
{
}


int ArgsParser::isDir(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int ArgsParser::setupServer(sockaddr_in *server, int *socketfd, std::string ip)
{
    socklen_t optionValue = 1;
    struct ip_mreq mreq;

    if ((*socketfd) == -1) {
        std::cerr << "Error: can't create socket!" << std::endl;
        return -1;
    }
    if (setsockopt((*socketfd), SOL_SOCKET, SO_REUSEADDR,
(char *)&optionValue, sizeof(optionValue)) == -1) {
        std::cerr << "Error: setsockopt failed!" << std::endl;
        return -1;
    }
    server->sin_family = AF_INET;
    server->sin_port = htons(54000);
    server->sin_addr.s_addr = inet_addr(ip.c_str());
    if (bind((*socketfd), (sockaddr *)server, sizeof(*server)) == -1) {
        std::cerr << "Error: can't bind socket!" << std::endl;
        return -1;
    }
    mreq.imr_multiaddr.s_addr = inet_addr(ip.c_str());
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt((*socketfd), IPPROTO_IP, IP_ADD_MEMBERSHIP,
(char *)&mreq, sizeof(mreq)) < 0) {
        std::cerr << "Error: setsockopt failed!" << std::endl;
        return -1;
    }
    return 0;
}

int ArgsParser::serverLoop(std::string ip)
{
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in server;
    socklen_t serverlen = sizeof(server);
    char buff[BuffSize];
    int bytesIn = 0;
    Object *obj;
    std::string oui;

    if (this->setupServer(&server, &socketfd, ip) == -1)
        return -1;
    while (true) {
        memset(&buff, '0', 8192);
        bytesIn = recvfrom(socketfd, buff, 8192, 0,
(sockaddr *)&server, &serverlen);
        if (bytesIn == -1) {
            std::cerr << "Error receiving from client!" << std::endl;
            continue;
        }
        buff[bytesIn] = '\0';
        oui.assign(buff);
        obj = this->xmlParser.Deserializer(oui);
        if (obj == nullptr)
            continue;
        this->santa.checkGift(obj);
    }
    close(socketfd);
    return 1;
}

int ArgsParser::fileLoop(const char **files)
{
    std::ifstream stream;
    std::string content;
    std::string buffer;
    Object *obj;

    for (int i = 1; files[i] != NULL; i++) {
        if (this->isDir(files[i]) == true)
            continue;
        stream.open(files[i]);
        if (!stream.is_open())
            continue;
        while (std::getline(stream, buffer)) {
            buffer += '\n';
            content += buffer;
            buffer.clear();
        }
        stream.close();
        obj = this->xmlParser.Deserializer(content);
        if (obj == nullptr) {
            content.clear();
            continue;
        }
        this->santa.checkGift(obj);
        content.clear();
    }
    return 0;
}

int ArgsParser::checkIp(int ac, const char **av)
{
    unsigned char buf[sizeof(struct in6_addr)] = {0};
    std::string str;
    int firstTokenNode;

    if (ipMode.compare(av[1]))
        return 0;
    if (ac != 3)
        return -1;
    if (inet_pton(AF_INET, av[2], buf) <= 0)
        return -1;
    str.assign(av[2]);
    str.assign(str.substr(0, str.find_first_of('.')));
    try {
        firstTokenNode = std::stoi(str, 0, 10);
    } catch (std::invalid_argument const &e) {
        return -1;
    }
    if (firstTokenNode < 234 || firstTokenNode > 239)
        return -1;
    return serverLoop(std::string(av[2]));
}

int ArgsParser::checkArgs(int ac, const char **av)
{
    int ret_val = 0;

    if (ac < 2)
        return -1;
    ret_val = this->checkIp(ac, av);
    if (ret_val == -1)
        return -1;
    if (ret_val == 1)
        return 0;
    return this->fileLoop(av);
}