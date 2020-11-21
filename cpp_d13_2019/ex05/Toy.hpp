/*
** EPITECH PROJECT, 2019
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D13_2019_TOY_HPP
#define CPP_D13_2019_TOY_HPP

#include <memory>
#include <sys/stat.h>
#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        class Error {
        public:
            enum ErrorType {UNKNOWN, PICTURE, SPEAK};
            Error();
            ~Error();
            std::string what() const;
            std::string where() const;
            ErrorType type;
        };

        enum ToyType { BASIC_TOY, ALIEN, BUZZ, WOODY };
        Toy();
        Toy(const Toy &toy);
        Toy &operator=(const Toy &toy);
        Toy(ToyType type, const std::string &name, const std::string filename);
        ~Toy();
        virtual void speak(const std::string statement);
        virtual bool speak_es(const std::string statement);
        Toy &operator<<(std::string string);

        // Getter
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        Error getLastError() const ;

        //setter
        void setName(const std::string &name);
        bool setAscii(const std::string &filename);

    protected:
        std::string _name;
        ToyType _type;
        std::string _filename;
        Picture *_picture;
        Error _error;
};

std::ostream &operator<<(std::ostream &out, const Toy &toy);

#endif //CPP_D13_2019_TOY_HPP
