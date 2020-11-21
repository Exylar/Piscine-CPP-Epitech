/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasElf
*/

#include "PapaXmasElf.hpp"
#include "ITable.hpp"
#include "Wrap.hpp"

PapaXmasElf::PapaXmasElf(ITable *table, IConveyorBelt *conveyor)
    : _hand(), _table(table), _conveyor(conveyor)
{
}

PapaXmasElf::~PapaXmasElf()
{
}

bool PapaXmasElf::putOnTable()
{
    if (this->_table == nullptr) {
        std::cerr << "o'pa ere's somin' wron' in da table!" << std::endl;
        return false;
    }
    if (this->_hand.isEmpty()) {
        std::cerr << "o'pa ere's somin' wron' wit ma hand!" << std::endl;
        return false;
    }
    if ((size_t)(*this->_table) >= 10) {
        std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
        delete this->_table;
        this->_table = nullptr;
        return false;
    }
    Object *obj = this->_hand.getObj();
    *this->_table << obj;
    return true;
}

bool PapaXmasElf::putOnConveyor()
{
    if (this->_conveyor == nullptr) {
        std::cerr << "o'pa ere's somin' wron' in da conv'y'or!" << std::endl;
        return false;
    }
    if (this->_hand.isEmpty()) {
        std::cerr << "o'pa ere's somin' wron' wit ma hand!" << std::endl;
        return false;
    }
    Object *obj = this->_hand.getObj();
    *this->_conveyor << obj;
    return true;
}

bool PapaXmasElf::takeFromTable(unsigned int idx)
{
    if (this->_table == nullptr) {
        std::cerr << "o'pa ere's somin' wron' in da table!" << std::endl;
        return false;
    }
    if (!this->_hand.isEmpty()) {
        std::cerr << "takeFromTable: error: elve hand's ";
        std::cerr << "are already taken!" << std::endl;
        return false;
    }
    Object *obj = this->_table->take(idx);
    obj->isTaken();
    this->_hand.setObj(obj);
    return true;
}

bool PapaXmasElf::takeFromConveyor()
{
    if (this->_conveyor == nullptr) {
        std::cerr << "o'pa ere's somin' wron' in da conv'y'or!" << std::endl;
        return false;
    }
    if (this->_hand.isEmpty() == false) {
        std::cerr << "takeFromTable: error: elve hand's are ";
        std::cerr << "already taken!" << std::endl;
        return false;
    }
    Object *obj = this->_conveyor->take();
    obj->isTaken();
    this->_hand.setObj(obj);
    return true;
}

bool PapaXmasElf::pressIn()
{
    if (this->_conveyor == nullptr) {
        std::cerr << "PressIn: error: the elve do not ";
        std::cerr << "have any conveyor." << std::endl;
        return false;
    }
    if (this->_hand.isEmpty() == false) {
        std::cerr << "PressIn: error: the elf's hands ";
        std::cerr << "are already taken!" << std::endl;
        return false;
    }
    return this->_conveyor->in();
}

bool PapaXmasElf::pressOut()
{
    if (this->_conveyor == nullptr) {
        std::cerr << "PressOut: error: the elve do ";
        std::cerr << "not have any conveyor." << std::endl;
        return false;
    }
    if (this->_hand.isEmpty() == false) {
        std::cerr << "PressOut: error: the elf's hands ";
        std::cerr << "are already taken!" << std::endl;
        return false;
    }
    return this->_conveyor->out();
}

ITable *PapaXmasElf::getTable() const
{
    return this->_table;
}

void PapaXmasElf::setTable(ITable *table)
{
    this->_table = table;
}

IConveyorBelt *PapaXmasElf::getConveyor() const
{
    return this->_conveyor;
}

void PapaXmasElf::setConveyor(IConveyorBelt *conveyor)
{
    this->_conveyor = conveyor;
}

bool PapaXmasElf::openWrap()
{
    Object *obj = *this->_hand;

    if (obj == nullptr) {
        std::cerr << "o'pa ere's somin' wron' wit ma hand!" << std::endl;
        return false;
    }
    if (obj->canWrap() == false) {
        std::cerr << "OpenWrap: error: this object ";
        std::cerr << "cannot be opened" << std::endl;
        return false;
    }
    ((Wrap *)obj)->openMe();
    return true;
}

bool PapaXmasElf::closeWrap()
{
    Object *obj = *this->_hand;

    if (obj == nullptr) {
        std::cerr << "o'pa ere's somin' wron' wit ma hand!" << std::endl;
        return false;
    }
    if (obj->canWrap() == false) {
        std::cerr << "OpenWrap: error: this object ";
        std::cerr << "cannot be Closed" << std::endl;
        return false;
    }
    ((Wrap *)obj)->closeMe();
    return true;
}

bool PapaXmasElf::wrapObjectFromHand(unsigned int idx)
{
    if (this->_hand.isEmpty() == true) {
        std::cerr << "o'pa ere's somin' wron' wit ma hand!" << std::endl;
        return false;
    }
    if (idx >= ITable::MaxSize) {
        std::cerr << "wrapObjectFromHand: error: ";
        std::cerr << "cannot find object" << std::endl;
        return false;
    }
    Object *newWrap = this->_table->take(idx);
    if (newWrap == nullptr) {
        std::cerr << "wrapObjectFromHand: error: ";
        std::cerr << "No object at given index." << std::endl;
        return false;
    }
    if (newWrap->canWrap() == false) {
        std::cerr << "wrapObjectFromHand: error: ";
        std::cerr << "the object can't wrap anything." << std::endl;
        return false;
    }
    newWrap->isTaken();
    std::cout << "tuuuut tuuut tuut" << std::endl;
    Object *obj = this->_hand.getObj();
    this->_hand.setObj(newWrap);
    return ((Wrap *)newWrap)->wrapMeThat(obj);
}

bool PapaXmasElf::wrapObjectToHand(unsigned int idx)
{
    Object *obj = *this->_hand;

    if (this->_hand.isEmpty() == true) {
        std::cerr << "o'pa ere's somin' wron' wit ma hand!" << std::endl;
        return false;
    }
    if (idx >= ITable::MaxSize) {
        std::cerr << "wrapObjectToHand: error: cannot find object" << std::endl;
        return false;
    }
    if (obj->canWrap() == false) {
        std::cerr << "wrapObjectToHand: error: the object in the ";
        std::cerr << "elve's hand can't wrap anything." << std::endl;
        return false;
    }
    Object *toWrap = this->_table->take(idx);
    if (toWrap == nullptr) {
        std::cerr << "wrapObjectToHand: error: ";
        std::cerr << "No object at given index." << std::endl;
        return false;
    }
    toWrap->isTaken();
    std::cout << "tuuuut tuuut tuut" << std::endl;
    return ((Wrap *)obj)->wrapMeThat(toWrap);
}

std::string **PapaXmasElf::lookTheTable() const
{
    if (this->_table == nullptr) {
        std::cerr << "o'pa ere's somin' wron' in da table!" << std::endl;
        return nullptr;
    }
    return this->_table->lookAtTheTable();
}

unsigned int PapaXmasElf::findToy(std::string **names)
{
    for (int i = 0; names[i] != nullptr; i++) {
        if (names[i]->empty())
            continue;
        else if (names[i]->compare("GiftPaper") == 0)
            continue;
        else if (names[i]->compare("Box") == 0)
            continue;
        return i;
    }
    return ITable::MaxSize;
}

unsigned int PapaXmasElf::findBox(std::string **names)
{
    for (int i = 0; names[i] != nullptr; i++) {
        if (names[i]->compare("Box") == 0)
            return i;
    }
    return ITable::MaxSize;
}

unsigned int PapaXmasElf::findPaper(std::string **names)
{
    for (int i = 0; names[i] != nullptr; i++) {
        if (names[i]->compare("GiftPaper") == 0)
            return i;
    }
    return ITable::MaxSize;
}

bool PapaXmasElf::wrapGift()
{
    std::string **names = this->lookTheTable();
    unsigned int toyIdx;
    unsigned int boxIdx;
    unsigned int paperIdx;

    if (names == nullptr)
        return false;
    toyIdx = this->findToy(names);
    boxIdx = this->findBox(names);
    paperIdx = this->findPaper(names);
    for (int i = 0; names[i] != nullptr; i++)
        delete names[i];
    delete [] names;
    if (toyIdx >= ITable::MaxSize || boxIdx >= ITable::MaxSize || paperIdx >= ITable::MaxSize)
        return this->getFromConveyor() && this->wrapGift();
    return this->sendToConveyor(toyIdx, boxIdx, paperIdx);
}

bool PapaXmasElf::sendToConveyor(unsigned int toyIdx,
unsigned int boxIdx, unsigned int paperIdx)
{
    if (this->takeFromTable(boxIdx) == false)
        return false;
    if (this->openWrap() == false)
        return false;
    if (this->wrapObjectToHand(toyIdx) == false)
        return false;
    if (this->wrapObjectFromHand(paperIdx) == false)
        return false;
    if (this->closeWrap() == false)
        return false;
    if (this->putOnConveyor() == false)
        return false;
    if (this->pressOut() == false)
        return false;
    return true;
}

bool PapaXmasElf::getFromConveyor()
{
    if (this->pressIn() == false)
        return false;
    if (this->takeFromConveyor() == false)
        return false;
    if (this->putOnTable() == false)
        return false;
    return true;
}
