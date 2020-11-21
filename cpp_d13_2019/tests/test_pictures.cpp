/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "../ex06/Buzz.hpp"
#include "../ex06/Woody.hpp"
#include "../ex06/Picture.hpp"
#include "../ex06/Toy.hpp"
#include "../ex06/ToyStory.hpp"
#include <ostream>
#include <iostream>

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;


    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

Test(Toy, cpToy) {
    Toy my_toy(Toy::BASIC_TOY, "my_toy", "ex06/alien.txt");
    Toy my_toy2(Toy::BASIC_TOY, "my_toy2", "ex06/alien.txt");

    my_toy = my_toy2;

    cr_assert_str_eq(my_toy.getName().c_str(), "my_toy2");
}

Test(Toy, error_toy)
{
    Toy my_toy(Toy::BASIC_TOY, "my_toy", "ex06/alien.txt");
    Toy my_toy2(my_toy);

    my_toy.getLastError().where();
    my_toy.getLastError().what();
    my_toy.setAscii("t");
    std::cout << my_toy << std::endl;
    cr_assert_str_eq(my_toy.getLastError().where().c_str(), "setAscii");
}

Test(TellmeStory, storywrong) {
    OSRedirector oss(std::cout);
    Buzz b("buzzi");
    Woody w("wood");
    ToyStory test;

    test.tellMeAStory("histoire.txt", b, NULL, w, &Toy::speak);
    cr_assert_eq(oss.getContent(), "Bad Story\n");
}

Test(TellmeStory, storyempty)
{
    OSRedirector oss(std::cout);
    Buzz b("buzzi");
    Woody w("wood");
    ToyStory test;

    test.tellMeAStory("tests/empty.txt", b, NULL, w, &Toy::speak);
}

Test(TellmeStory, story)
{
    Buzz b("buzzi");
    Woody w("wood");
    ToyStory test;;
    test.tellMeAStory("tests/histoire.txt", b, &Toy::speak_es, w, &Toy::speak);
}

Test(Redirector, Defaultame) {

    Toy toto;

    cr_assert_str_eq(toto.getName().c_str(), "Toy");
}

Test(Redirector, getName)
{
    Toy toto;

    toto.setName("TOTO !");
    cr_assert_str_eq(toto.getName().c_str(), "TOTO !");
}

Test(Redirector, getAscii)
{
    OSRedirector oss(std::cout);
    Toy toto;

    toto.setAscii("./alien.txt");
    std::cout << toto.getAscii() << std::endl;

    cr_assert_eq(1, 1);
}



Test(Redirector, Buzz)
{

    Buzz b("Buzzi");

    cr_assert_str_eq(b.getName().c_str(), "Buzzi");
}

Test(Redirector, BuzzsetName)
{

    Buzz b("Buzzi");

    b.setName("Buzou");
    cr_assert_str_eq(b.getName().c_str(), "Buzou");
}

Test(Redirector, Buzzspeak)
{
    OSRedirector oss(std::cout);
    Buzz b("Buzzi");

    b.speak("Salut les amis");
    cr_assert_eq(oss.getContent(), "BUZZ: Buzzi \"Salut les amis\"\n");
}

Test(Redirector, BuzzSpeakEs)
{
    OSRedirector oss(std::cout);
    Buzz b("Buzzi", "../ex06/buzz.txt");

    b.speak_es("Salut les amis");
    cr_assert_eq(oss.getContent(), "BUZZ: Buzzi senorita \"Salut les amis\" senorita\n");
}

Test(Redirector, Woody)
{
    Woody w("Woodi");

    cr_assert_str_eq(w.getName().c_str(), "Woodi");
}

Test(Redirector, WoodysetName)
{
    Woody w("Woodi");

    w.setName("Woodou");
    cr_assert_str_eq(w.getName().c_str(), "Woodou");
}

Test(Redirector, Woodyspeak)
{
    OSRedirector oss(std::cout);
    Woody w("Woodi", "../ex06./woody.txt");

    w.speak("Salut les amis");
    cr_assert_eq(oss.getContent(), "WOODY: Woodi \"Salut les amis\"\n");
}



Test(Redirector, not_exists_file) {
    OSRedirector oss(std::cerr);

    std::cerr << "Hello" << std::endl;
    cr_assert_eq(oss.getContent(), "Hello\n");
}
