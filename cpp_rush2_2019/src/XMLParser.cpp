/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "XMLParser.hpp"
#include <sstream>

XMLParser::XMLParser() {}

XMLParser::~XMLParser() {}

std::string XMLParser::SerializeString(Object *object)
{
    int count_tab = 0;
    std::string xml_serialize_string;
    std::string tableau[5];

    xml_serialize_string = "<?xml version=\"" + this->_version +
"\" encoding=\"" + this->_enconding + "\"?>\n<Gifts>\n";
    while (object->canWrap()) {
        count_tab++;
        Wrap *wrap = (Wrap *)object;
        wrap->openMe();
        object = wrap->getContent();
        for (int i = 0; i < count_tab; i++)
            xml_serialize_string.append("\t");
        tableau[count_tab] = wrap->getTitle();
        xml_serialize_string.append("<" + tableau[count_tab] + ">\n");
        delete wrap;
    }
    for (int i = 0; i < count_tab + 1; i++)
        xml_serialize_string.append("\t");
    xml_serialize_string.append("<Toy>" + object->getTitle() + "</Toy>\n");
    delete object;
    while (count_tab > 0) {
        for (int i = 0; i < count_tab; i++)
            xml_serialize_string.append("\t");
        xml_serialize_string.append("</" + tableau[count_tab] + ">\n");
        count_tab--;
    }
    xml_serialize_string.append("</Gifts>");
    return xml_serialize_string;
}

Object *XMLParser::Deserializer(std::string string)
{
    Object *toy;
    Object *box = new Box();
    Object *paper = new GiftPaper();
    std::string toyName;
    int start = 5;
    std::stringstream lineStream(string);
    std::string line;
    std::string array[9] = { "<?xml version=\"1.0\" encoding=\"UTF-8\"?>",
"<Gifts>", "\t<GiftPaper>", "\t\t<Box>", "\t\t\t<Toy>",
"\t\t</Box>", "\t</GiftPaper>", "</Gifts>" };
    int i = 0;

    if (string.empty())
        return nullptr;
    while (std::getline(lineStream, line)) {
        if (i != 4) {
            if (array[i] != line)
                return nullptr;
        } else {
            if (line.find("<Toy>") == std::string::npos
|| line.find("</Toy>") == std::string::npos)
                return nullptr;
        }
        lineStream << line;
        i++;
    }
    start += string.find("<Toy>");
    toyName.assign(string.substr(start, string.find("</Toy>") - start));
    if (toyName == "Teddy")
        toy = new Teddy(toyName);
    else if (toyName == "LittlePony")
        toy = new LittlePony(toyName);
    else
        return nullptr;
    if (!box->canWrap())
        return nullptr;
    ((Wrap *) box)->openMe();
    ((Wrap *) box)->wrapMeThat(toy);
    ((Wrap *) box)->closeMe();
    if (!box->canWrap())
        return nullptr;
    ((Wrap *) paper)->wrapMeThat(box);
    return paper;
}