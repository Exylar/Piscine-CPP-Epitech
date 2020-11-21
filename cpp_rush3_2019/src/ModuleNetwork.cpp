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
    static unsigned long int r_bytes = 0;
    static unsigned long int t_bytes = 0;
    unsigned long int r_bytes_new = 0;
    unsigned long int t_bytes_new = 0;
    double bytes_in = 0;
    double bytes_out = 0;

    while (strstr(ifname, "wlo1") == NULL) {
        fgets(buf, 200, fp);
        sscanf(buf, "%[^:]:", ifname);
    }
    //sscanf(buf, "%[^:]: %lu %*u %*u %*u %*u %*u %*u %*u %lu", ifname, &r_bytes, &t_bytes);
    buf[0] = '\0';
    ifname[0] = '\0';
    fclose(fp);
    FILE *fp1 = fopen("/proc/net/dev", "r");
    while (strstr(ifname, "wlo1") == NULL) {
        fgets(buf, 200, fp1);
        sscanf(buf, "%[^:]:", ifname);
    }
    sscanf(buf, "%[^:]: %lu %*u %*u %*u %*u %*u %*u %*u %lu", ifname, &r_bytes_new, &t_bytes_new);
    bytes_in = ((r_bytes_new - r_bytes) / 1024);
    bytes_out = ((t_bytes_new - t_bytes) / 1024);
    r_bytes = r_bytes_new;
    t_bytes = t_bytes_new;
    this->_name = ifname;
    this->_download = bytes_in;
    this->_upload = bytes_out;
    fclose(fp1);
}

void ModuleNetwork::Display(IMonitorDisplay *d) const
{
    d->DisplaySeparator();
    d->DisplayTitle("Network Module (T)");
    d->DisplaySubTitle("Download :");
    d->DisplayText(std::to_string(_download) + " kb/s");
    d->DisplaySubTitle("Upload :");
    d->DisplayText(std::to_string(_upload) + " kb/s");
}

std::string const &ModuleNetwork::GetName() const { return this->_name; }
int ModuleNetwork::GetUpload() const { return this->_upload; }
int ModuleNetwork::GetDownload() const { return this->_download; }