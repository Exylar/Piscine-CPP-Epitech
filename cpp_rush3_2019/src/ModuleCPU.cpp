/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/ModuleCPU.hpp"
#include "../include/const.hpp"

ModuleCPU::ModuleCPU() : _name("CPU"), _model("CPU"), _frequency(0), _nb_of_cores(0), _activity(0)
{
    Update();
}

ModuleCPU::~ModuleCPU() {}

void ModuleCPU::updateCPUUsage()
{
    static int user;
    static int nice;
    static int system_;
    std::ifstream file(CPUSTATPROC);
    if (!file.is_open()) {
        std::cout << "Unable to get CPU stats" << std::endl;
        return;
    }
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::vector<std::string> tokens;
    std::vector<std::vector<std::string>> dlist;
    size_t i = -1;
    //-------------------------- PARSING FILE -------------------------------//
    while (str.find("\n") != std::string::npos)
        str.replace(str.find("\n"), 1, " ");
    for (auto i = strtok(&str[0], " "); i != NULL; i = strtok(NULL, " ")) {
        tokens.push_back(i);
    }
    while (!tokens.empty()) {
        if (tokens[0].substr(0, 3) == (std::string)"cpu") {
            i++;
            std::vector<std::string> vec;
            dlist.push_back(vec);
            tokens.erase(tokens.begin());
            continue;
        } else if (!isdigit(tokens[0][0]))
            break;
        dlist[i].push_back(tokens[0]);
        tokens.erase(tokens.begin());
    }
    //-------------------------- GETTING ACTIVITY -------------------------------//
    int _user = std::stoi(dlist[0][0]);
    dlist[0].erase(dlist[0].begin());
    int _nice = std::stoi(dlist[0][0]);
    dlist[0].erase(dlist[0].begin());
    int _system = std::stoi(dlist[0][0]);
    _activity = (((_user - user) + (_system - system_) + (_nice - nice)));
    user = _user;
    nice = _nice;
    system_ = _system;
    file.close();
}

void ModuleCPU::updateCPUInfo()
{
    static float freq = 0;
    float tmp = 0;

    std::ifstream file(CPUINFOPROC);
    if (!file.is_open()) {
        std::cout << "Unable to get CPU information" << std::endl;
        return;
    }
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    //-------------------------- PARSING FILE -------------------------------//
    while (str.find("\t: ") != std::string::npos)
        str.replace(str.find("\t: "), 3, "|");
    Parser p(str);
    std::vector<Parser> ps = p.split('\n');
    //-------------------------- GETTING DATA -------------------------------//
    while (!ps.empty()) {
        if (ps[0].getText().substr(0, 10) == (std::string)"model name") {
            std::vector<Parser> ps2 = ps[0].split('|');
            ps2.erase(ps2.begin());
            _model = ps2[0].getText();
        }
        else if (ps[0].getText().substr(0, 9) == (std::string)"cpu cores") {
            std::vector<Parser> ps2 = ps[0].split('|');
            ps2.erase(ps2.begin());
            _nb_of_cores = std::stoi(ps2[0].getText());
        }
        else if (ps[0].getText().substr(0, 7) == (std::string)"cpu MHz") {
            std::vector<Parser> ps2 = ps[0].split('|');
            ps2.erase(ps2.begin());
            tmp += std::stoi(ps2[0].getText());
        }
        ps.erase(ps.begin());
    }
    freq = tmp;
    _frequency = (_frequency + freq) / 2;
    file.close();
}

void ModuleCPU::Update()
{
    updateCPUUsage();
    updateCPUInfo();
}

void ModuleCPU::Display(IMonitorDisplay *d) const {
    d->DisplaySeparator();
    d->DisplayTitle("CPU Module (A)");
    d->DisplaySubTitle("Model : ");
    d->DisplayText(_model);
    d->DisplaySubTitle("Cores : ");
    d->DisplayText(std::to_string(_nb_of_cores));
    d->DisplaySubTitle("Frequency : ");
    d->DisplayText(std::to_string(_frequency));
    d->DisplayGraph("Activity : ", _activity);
}

std::string const &ModuleCPU::GetName() const {return this->_name;}
std::string ModuleCPU::getModel() const {return this->_model;}
float ModuleCPU::getFrequency() const {return this->_frequency;}
size_t ModuleCPU::getNbCores() const {return this->_nb_of_cores;}
float ModuleCPU::getActivity() const {return this->_activity;}