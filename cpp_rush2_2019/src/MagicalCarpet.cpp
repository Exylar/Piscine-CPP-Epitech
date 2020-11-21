/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** MagicalCarpet
*/

#include <string>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "MagicalCarpet.hpp"
#include "Teddy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"

MagicalCarpet::MagicalCarpet(std::string ip)
{
    this->ip = ip;
    obj = nullptr;
}

MagicalCarpet::~MagicalCarpet()
{
    if (this->obj != nullptr)
        delete this->obj;
}

Object *MagicalCarpet::take()
{
    Object *save = this->obj;
    if (this->isEmpty() == true) {
        std::cerr << "ConveyorBelt takeObj: Error: There is ";
        std::cerr << "nothing on the Conveyor Belt" << std::endl;
        return nullptr;
    } else {
        this->obj = nullptr;
        return save;
    }
}

bool MagicalCarpet::put(Object *&obj)
{
    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt put: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
        return false;
    } else {
        this->obj = obj;
        obj = nullptr;
        return true;
    }
}

void MagicalCarpet::operator<<(Object *&obj)
{
    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt put: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
    } else {
        this->obj = obj;
        obj = nullptr;
    }
}

bool MagicalCarpet::in()
{
    int val = random() % 4;

    if (this->isEmpty() == false) {
        std::cerr << "ConveyorBelt in: Error: There is ";
        std::cerr << "already an object on the Conveyor Belt" << std::endl;
        return false;
    }
    if (val == 0)
        this->obj = new Box();
    if (val == 1)
        this->obj = new GiftPaper();
    if (val == 2)
        this->obj = new LittlePony();
    if (val == 3)
        this->obj = new Teddy();
    if (this->obj == nullptr) {
        std::cerr << "ConveyorBelt in: Error: The instanciation ";
        std::cerr << "of a random object failed." << std::endl;
        return false;
    }
    return true;
}

bool MagicalCarpet::sendNetwork(std::string message) const
{
    int sendOk;
    sockaddr_in server;
    int socketfd;

    server.sin_family = AF_INET;
    server.sin_port = htons(54000);
    server.sin_addr.s_addr = inet_addr(this->ip.c_str());
    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd == -1) {
        std::cerr << "Error: can't create socket!" << std::endl;
        return false;
    }
    sendOk = sendto(socketfd, message.c_str(),
message.size() + 1, 0, (sockaddr*)&server, sizeof(server));
    if (sendOk == -1) {
        std::cout << "Error: can't send message!" << std::endl;
        return false;
    }
    close(socketfd);
    return true;
}

bool MagicalCarpet::out()
{
    std::string message;

    if (this->isEmpty() == true) {
        std::cerr << "ConveyorBelt out: Error: There is ";
        std::cerr << "nothing on the Conveyor Belt" << std::endl;
        return false;
    } else {
        message = this->parser.SerializeString(this->obj);
        if (sendNetwork(message) == true) {
            this->obj = nullptr;
            return true;
        } else {
            return false;
        }
        return true;
    }
}

bool MagicalCarpet::isEmpty() const
{
    if (obj == nullptr)
        return true;
    else
        return false;
}