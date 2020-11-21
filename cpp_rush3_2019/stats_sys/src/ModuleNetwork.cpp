/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleNetwork
*/

#include "ModuleNetwork.hpp"

ModuleNetwork::ModuleNetwork()
{
    this->_name = "Network";
    this->_upload = 0;
    this->_download = 0;
}

ModuleNetwork::~ModuleNetwork()
{
}

void ModuleNetwork::Update()
{
    FILE *fp = fopen("/proc/net/dev", "r");
    char buf[200], ifname[20];
    unsigned long int r_bytes = 0;
    unsigned long int t_bytes = 0;
    unsigned long int r_bytes_new = 0;
    unsigned long int t_bytes_new = 0;
    double bytes_in = 0;
    double bytes_out = 0;

    while (strstr(ifname, "wlo1") == NULL) {
        fgets(buf, 200, fp);
        sscanf(buf, "%[^:]:", ifname);
    }
    sscanf(buf, "%[^:]: %lu %*u %*u %*u %*u %*u %*u %*u %lu", ifname, &r_bytes, &t_bytes);
    buf[0] = '\0';
    ifname[0] = '\0';
    fclose(fp);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    FILE *fp1 = fopen("/proc/net/dev", "r");
    while (strstr(ifname, "wlo1") == NULL) {
        fgets(buf, 200, fp1);
        sscanf(buf, "%[^:]:", ifname);
    }
    sscanf(buf, "%[^:]: %lu %*u %*u %*u %*u %*u %*u %*u %lu", ifname, &r_bytes_new, &t_bytes_new);
    bytes_in = ((r_bytes_new - r_bytes) / 1024);
    bytes_out = ((t_bytes_new - t_bytes) / 1024);
    this->_name = ifname;
    this->_download = bytes_in;
    this->_upload = bytes_out;
    fclose(fp1);
}

void ModuleNetwork::Display(IMonitorDisplay *iMonitorDisplay) const
{
    (void)iMonitorDisplay;
}

std::string const &ModuleNetwork::GetName() const { return this->_name; }
float ModuleNetwork::GetUpload() const { return this->_upload; }
float ModuleNetwork::GetDownload() const { return this->_download; }