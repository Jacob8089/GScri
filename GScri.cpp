#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>

#include<windows.h> 
#include<stdlib.h> 

using namespace std;

void g_code_conv(string fn_g_code) {
    std::string g_code = fn_g_code;
    transform(g_code.begin(), g_code.end(), g_code.begin(), ::toupper);
    std::cout << "\nYour entry: " << g_code << std::endl;
    std::string input_1 = g_code.substr(0, 1);
    std::cout << "\nIdentified Code as " << input_1 << std::endl;
    std::cout << "Iteration Started for " << g_code << std::endl;
    double unit = 1000;
    float psx, psy, psz = 0.000000;
    int pos_1, pos_2;
    std::string ps_x;
    if (input_1 == "G")
    {
        std::string input_2 = g_code.substr(1, 1);
        std::cout << "Code: " << input_2 << std::endl;
        int g_cmd1 = atoi(input_2.c_str());
        switch (g_cmd1)
        {
        case 0: {
            std::cout << "--------------------------" << std::endl;
            std::cout << "Entered to G0" << std::endl;
            std::vector<std::string>g1cmds = { "X","Y","Z" };
            std::vector<int>g1cmdsindex;
            for (auto i = g1cmds.cbegin(); i != g1cmds.cend(); ++i) {
                std::string item = *i;
                std::cout << item << " is at ";
                int pos = g_code.find(item);
                g1cmdsindex.push_back(pos);
                g1cmdsindex.shrink_to_fit();
                std::cout << pos << endl;
            }
            g1cmdsindex.shrink_to_fit();
            std::cout << "Size of index vector: " << g1cmdsindex.size() << std::endl;
            for (int i = 0; i <= g1cmdsindex.size() - 1; i++) {
                //std::cout<<g1cmdsindex.size()-1<<std::endl;
                if (g1cmdsindex.at(i) == -1) {
                    std::cout << g1cmds.at(i) << " element not present for position " << i << std::endl;
                }
                else {
                    std::cout << g1cmds.at(i) << " element present for index " << i << std::endl;
                    if (i == g1cmdsindex.size() - 1) {
                        switch (i) {
                        case 0: {
                            std::cout << "Last element case at " << i << " for " << g1cmds.at(i) << std::endl;
                            int buffer = g_code.length() + 1;
                            std::cout << "Additional Buffer for Last Case 0 is " << buffer << std::endl;
                            pos_1 = g1cmdsindex.at(i);
                            pos_2 = buffer;
                            int lpos1 = pos_1 + 1;
                            int lpos2_1 = pos_2 - 1;
                            int lpos2 = lpos2_1 - lpos1;
                            std::string coordinates = g_code.substr(lpos1, lpos2);
                            float g1_coordinate = atoi(coordinates.c_str());
                            psx = g1_coordinate / unit;
                            std::string movel_value = std::to_string(psx);
                            std::cout << movel_value << std::endl;
                            break; }
                        case 1: {
                            std::cout << "Last element case at " << i << " for " << g1cmds.at(i) << std::endl;
                            int buffer = g_code.length() + 1;
                            std::cout << "Additional buffer for Last Case 1 is " << buffer << std::endl;
                            pos_1 = g1cmdsindex.at(i);
                            pos_2 = buffer;
                            int lpos1 = pos_1 + 1;
                            int lpos2_1 = pos_2 - 1;
                            int lpos2 = lpos2_1 - lpos1;
                            std::string coordinates = g_code.substr(lpos1, lpos2);
                            float g1_coordinate = atoi(coordinates.c_str());
                            psy = g1_coordinate / unit;
                            std::string movel_value = std::to_string(psy);
                            std::cout << movel_value << std::endl;
                            break; }

                        case 2: {
                            std::cout << "Last element case at " << i << " for " << g1cmds.at(i) << std::endl;
                            int buffer = g_code.length() + 1;
                            std::cout << "Additional Buffer for Last Case 0 is " << buffer << std::endl;
                            pos_1 = g1cmdsindex.at(i);
                            pos_2 = buffer;
                            int lpos1 = pos_1 + 1;
                            int lpos2_1 = pos_2 - 1;
                            int lpos2 = lpos2_1 - lpos1;
                            std::string coordinates = g_code.substr(lpos1, lpos2);
                            float g1_coordinate = atoi(coordinates.c_str());
                            psz = g1_coordinate / unit;
                            std::string movel_value = std::to_string(psz);
                            std::cout << "Value for Z: " << movel_value << std::endl;
                            break; }
                        }
                    }
                    else {
                        std::cout << "Normal Condition starting at " << i << " for " << g1cmds.at(i) << std::endl;
                        switch (i) {
                        case 0: {
                            for (int j = i + 1; j <= g1cmdsindex.size() - 1; j++) {
                                if (g1cmdsindex.at(j) == -1) {

                                    if (g1cmdsindex.at(j) = g1cmdsindex.size() - 1) {
                                        std::cout << "Normal Element Case at" << i << " " << g1cmds.at(i) << std::endl;
                                        int buffer = g_code.length() + 1;
                                        std::cout << buffer << std::endl;
                                        pos_1 = g1cmdsindex.at(i);
                                        pos_2 = buffer;
                                        int lxpos1 = pos_1 + 1;
                                        int lxpos2_1 = pos_2 - 1;
                                        int lxpos2 = lxpos2_1 - lxpos1;
                                        std::string coordinates = g_code.substr(lxpos1, lxpos2);
                                        float g1_coordinate = atoi(coordinates.c_str());
                                        psx = g1_coordinate / unit;
                                        std::string movel_value = std::to_string(psx);
                                        std::cout << "Value for X: " << movel_value << std::endl;
                                    }
                                    else { continue; }
                                }
                                else {
                                    pos_1 = g1cmdsindex.at(i);
                                    pos_2 = g1cmdsindex.at(j);
                                    int lxpos1 = pos_1 + 1;
                                    int lxpos2_1 = pos_2 - 1;
                                    int lxpos2 = lxpos2_1 - lxpos1;
                                    std::string coordinates = g_code.substr(lxpos1, lxpos2);
                                    float g1_coordinate = atoi(coordinates.c_str());
                                    psx = g1_coordinate / unit;
                                    std::string movel_value = std::to_string(psx);
                                    std::cout << "Value for X: " << movel_value << std::endl;
                                }
                            }
                            break; }
                        case 1: {
                            for (int j = i + 1; j <= g1cmdsindex.size() - 1; j++) {
                                if (g1cmdsindex.at(j) == -1) {

                                    if (g1cmdsindex.at(j) = g1cmdsindex.size() - 1) {
                                        std::cout << "Normal Element Case at" << i << " " << g1cmds.at(i) << std::endl;
                                        int buffer = g_code.length() + 1;
                                        std::cout << buffer << std::endl;
                                        pos_1 = g1cmdsindex.at(i);
                                        pos_2 = buffer;
                                        int lypos1 = pos_1 + 1;
                                        int lypos2_1 = pos_2 - 1;
                                        int lypos2 = lypos2_1 - lypos1;
                                        std::string coordinates = g_code.substr(lypos1, lypos2);
                                        float g1_coordinate = atoi(coordinates.c_str());
                                        psy = g1_coordinate / unit;
                                        std::string movel_value = std::to_string(psy);
                                        std::cout << "Value for Y: " << movel_value << std::endl;
                                        break;
                                    }
                                    else { continue; }
                                }
                                else {
                                    pos_1 = g1cmdsindex.at(i);
                                    pos_2 = g1cmdsindex.at(j);
                                    int lypos1 = pos_1 + 1;
                                    int lypos2_1 = pos_2 - 1;
                                    int lypos2 = lypos2_1 - lypos1;
                                    std::string coordinates = g_code.substr(lypos1, lypos2);
                                    float g1_coordinate = atoi(coordinates.c_str());
                                    psy = g1_coordinate / unit;
                                    std::string movel_value = std::to_string(psy);
                                    std::cout << "Value for Y: " << movel_value << std::endl;
                                }
                            }
                            break; }
                        case 2: {
                            for (int j = i + 1; j <= g1cmdsindex.size() - 1; j++) {
                                if (g1cmdsindex.at(j) == -1) {

                                    if (g1cmdsindex.at(j) = g1cmdsindex.size() - 1) {
                                        std::cout << "Normal Element Case at" << i << " " << g1cmds.at(i) << std::endl;
                                        int buffer = g_code.length() + 1;
                                        std::cout << buffer << std::endl;
                                        pos_1 = g1cmdsindex.at(i);
                                        pos_2 = buffer;
                                        int lzpos1 = pos_1 + 1;
                                        int lzpos2_1 = pos_2 - 1;
                                        int lzpos2 = lzpos2_1 - lzpos1;
                                        std::string coordinates = g_code.substr(lzpos1, lzpos2);
                                        float g1_coordinate = atoi(coordinates.c_str());
                                        psz = g1_coordinate / unit;
                                        std::string movel_value = std::to_string(psz);
                                        std::cout << "Value for Z: " << movel_value << std::endl;
                                        break;
                                    }
                                    else { continue; }
                                }
                                else {
                                    pos_1 = g1cmdsindex.at(i);
                                    pos_2 = g1cmdsindex.at(j);
                                    int lzpos1 = pos_1 + 1;
                                    int lzpos2_1 = pos_2 - 1;
                                    int lzpos2 = lzpos2_1 - lzpos1;
                                    std::string coordinates = g_code.substr(lzpos1, lzpos2);
                                    float g1_coordinate = atoi(coordinates.c_str());
                                    psz = g1_coordinate / unit;
                                    std::string movel_value = std::to_string(psz);
                                    std::cout << "Value for Z: " << movel_value << std::endl;
                                }
                            }
                            break; }
                        }
                    }
                }
            }break; }
        case 1: {
            std::cout << "--------------------------" << std::endl;
            std::cout << "Entered to G1" << std::endl;
            std::vector<std::string>g1cmds = { "X","Y","Z","E","F" };
            std::vector<int>g1cmdsindex;
            for (auto i = g1cmds.cbegin(); i != g1cmds.cend(); ++i) {
                std::string item = *i;
                std::cout << item << " is at ";
                int pos = g_code.find(item);
                g1cmdsindex.push_back(pos);
                g1cmdsindex.shrink_to_fit();
                std::cout << pos << endl;
            }
            g1cmdsindex.shrink_to_fit();
            std::cout << "Size of index vector: " << g1cmdsindex.size() << std::endl;
            for (int i = 0; i <= g1cmdsindex.size() - 1; i++) {
                //std::cout<<g1cmdsindex.size()-1<<std::endl;
                if (g1cmdsindex.at(i) == -1) {
                    std::cout << g1cmds.at(i) << " element not present for position " << i << std::endl;
                }
                else {
                    std::cout << g1cmds.at(i) << " element present for index " << i << std::endl;
                    if (i == g1cmdsindex.size() - 1) {
                        switch (i) {
                        case 0: {
                            std::cout << "Last element case at " << i << " for " << g1cmds.at(i) << std::endl;
                            int buffer = g_code.length() + 1;
                            std::cout << "Additional Buffer for Last Case 0 is " << buffer << std::endl;
                            pos_1 = g1cmdsindex.at(i);
                            pos_2 = buffer;
                            int lpos1 = pos_1 + 1;
                            int lpos2_1 = pos_2 - 1;
                            int lpos2 = lpos2_1 - lpos1;
                            std::string coordinates = g_code.substr(lpos1, lpos2);
                            float g1_coordinate = atoi(coordinates.c_str());
                            psx = g1_coordinate / unit;
                            std::string movel_value = std::to_string(psx);
                            std::cout << movel_value << std::endl;
                            break; }
                        case 1: {
                            std::cout << "Last element case at " << i << " for " << g1cmds.at(i) << std::endl;
                            int buffer = g_code.length() + 1;
                            std::cout << "Additional buffer for Last Case 1 is " << buffer << std::endl;
                            pos_1 = g1cmdsindex.at(i);
                            pos_2 = buffer;
                            int lpos1 = pos_1 + 1;
                            int lpos2_1 = pos_2 - 1;
                            int lpos2 = lpos2_1 - lpos1;
                            std::string coordinates = g_code.substr(lpos1, lpos2);
                            float g1_coordinate = atoi(coordinates.c_str());
                            psy = g1_coordinate / unit;
                            std::string movel_value = std::to_string(psy);
                            std::cout << movel_value << std::endl;
                            break; }

                        case 2: {
                            std::cout << "Last element case at " << i << " for " << g1cmds.at(i) << std::endl;
                            int buffer = g_code.length() + 1;
                            std::cout << "Additional Buffer for Last Case 0 is " << buffer << std::endl;
                            pos_1 = g1cmdsindex.at(i);
                            pos_2 = buffer;
                            int lpos1 = pos_1 + 1;
                            int lpos2_1 = pos_2 - 1;
                            int lpos2 = lpos2_1 - lpos1;
                            std::string coordinates = g_code.substr(lpos1, lpos2);
                            float g1_coordinate = atoi(coordinates.c_str());
                            psz = g1_coordinate / unit;
                            std::string movel_value = std::to_string(psz);
                            std::cout << "Value for Z: " << movel_value << std::endl;
                            break; }
                        }
                    }
                    else {
                        std::cout << "Normal Condition starting at " << i << " for " << g1cmds.at(i) << std::endl;
                        switch (i) {
                        case 0: {
                            for (int j = i + 1; j <= g1cmdsindex.size() - 1; j++) {
                                if (g1cmdsindex.at(j) == -1) {

                                    if (g1cmdsindex.at(j) = g1cmdsindex.size() - 1) {
                                        std::cout << "Normal Element Case at" << i << " " << g1cmds.at(i) << std::endl;
                                        int buffer = g_code.length() + 1;
                                        std::cout << buffer << std::endl;
                                        pos_1 = g1cmdsindex.at(i);
                                        pos_2 = buffer;
                                        int lxpos1 = pos_1 + 1;
                                        int lxpos2_1 = pos_2 - 1;
                                        int lxpos2 = lxpos2_1 - lxpos1;
                                        std::string coordinates = g_code.substr(lxpos1, lxpos2);
                                        float g1_coordinate = atoi(coordinates.c_str());
                                        psx = g1_coordinate / unit;
                                        std::string movel_value = std::to_string(psx);
                                        std::cout << "Value for X: " << movel_value << std::endl;
                                    }
                                    else { continue; }
                                }
                                else {
                                    pos_1 = g1cmdsindex.at(i);
                                    pos_2 = g1cmdsindex.at(j);
                                    int lxpos1 = pos_1 + 1;
                                    int lxpos2_1 = pos_2 - 1;
                                    int lxpos2 = lxpos2_1 - lxpos1;
                                    std::string coordinates = g_code.substr(lxpos1, lxpos2);
                                    float g1_coordinate = atoi(coordinates.c_str());
                                    psx = g1_coordinate / unit;
                                    std::string movel_value = std::to_string(psx);
                                    std::cout << "Value for X: " << movel_value << std::endl;
                                }
                            }
                            break; }
                        case 1: {
                            for (int j = i + 1; j <= g1cmdsindex.size() - 1; j++) {
                                if (g1cmdsindex.at(j) == -1) {

                                    if (g1cmdsindex.at(j) = g1cmdsindex.size() - 1) {
                                        std::cout << "Normal Element Case at" << i << " " << g1cmds.at(i) << std::endl;
                                        int buffer = g_code.length() + 1;
                                        std::cout << buffer << std::endl;
                                        pos_1 = g1cmdsindex.at(i);
                                        pos_2 = buffer;
                                        int lypos1 = pos_1 + 1;
                                        int lypos2_1 = pos_2 - 1;
                                        int lypos2 = lypos2_1 - lypos1;
                                        std::string coordinates = g_code.substr(lypos1, lypos2);
                                        float g1_coordinate = atoi(coordinates.c_str());
                                        psy = g1_coordinate / unit;
                                        std::string movel_value = std::to_string(psy);
                                        std::cout << "Value for Y: " << movel_value << std::endl;
                                        break;
                                    }
                                    else { continue; }
                                }
                                else {
                                    pos_1 = g1cmdsindex.at(i);
                                    pos_2 = g1cmdsindex.at(j);
                                    int lypos1 = pos_1 + 1;
                                    int lypos2_1 = pos_2 - 1;
                                    int lypos2 = lypos2_1 - lypos1;
                                    std::string coordinates = g_code.substr(lypos1, lypos2);
                                    int g1_coordinate = atoi(coordinates.c_str());
                                    psy = g1_coordinate / unit;
                                    std::string movel_value = std::to_string(psy);
                                    std::cout << "Value for Y: " << movel_value << std::endl;
                                }
                            }
                            break; }
                        case 2: {
                            for (int j = i + 1; j <= g1cmdsindex.size() - 1; j++) {
                                if (g1cmdsindex.at(j) == -1) {

                                    if (g1cmdsindex.at(j) = g1cmdsindex.size() - 1) {
                                        std::cout << "Normal Element Case at" << i << " " << g1cmds.at(i) << std::endl;
                                        int buffer = g_code.length() + 1;
                                        std::cout << buffer << std::endl;
                                        pos_1 = g1cmdsindex.at(i);
                                        pos_2 = buffer;
                                        int lzpos1 = pos_1 + 1;
                                        int lzpos2_1 = pos_2 - 1;
                                        int lzpos2 = lzpos2_1 - lzpos1;
                                        std::string coordinates = g_code.substr(lzpos1, lzpos2);
                                        float g1_coordinate = atoi(coordinates.c_str());
                                        psz = g1_coordinate / unit;
                                        std::string movel_value = std::to_string(psz);
                                        std::cout << "Value for Z: " << movel_value << std::endl;
                                        break;
                                    }
                                    else { continue; }
                                }
                                else {
                                    pos_1 = g1cmdsindex.at(i);
                                    pos_2 = g1cmdsindex.at(j);
                                    int lzpos1 = pos_1 + 1;
                                    int lzpos2_1 = pos_2 - 1;
                                    int lzpos2 = lzpos2_1 - lzpos1;
                                    std::string coordinates = g_code.substr(lzpos1, lzpos2);
                                    float g1_coordinate = atoi(coordinates.c_str());
                                    psz = g1_coordinate / unit;
                                    std::string movel_value = std::to_string(psz);
                                    std::cout << "Value for Z: " << movel_value << std::endl;
                                }
                            }
                            break; }
                        }
                    }
                }
            }}
        }
        if (input_2 == "0") { std::cout << "\nThe converted UR Command is-" << "\nmovej([" << psx << "," << psy << "," << psz << ",0,0,0" << "],accel_mss,speed_ms,0,0.000)" << std::endl; }
        else if (input_2 == "1") { std::cout << "\nThe converted UR Script command is-" << "\nmovel([" << psx << "," << psy << "," << psz << ",0,0,0" << "],accel_mss,speed_ms,0,0.000)" << std::endl; }
        else { system("Color 0C"); std::cout << "\n[Critical]Not sure on what happened" << std::endl; }
    }
    else { std::cout << "[Error]The entered code is not a GCode value" << std::endl; }//end of GCode

    std::cout << "\n****************************\n" << std::endl;
    std::cout << "Iteration Complete for " << g_code << std::endl;
    std::cout << "Value for X: " << psx << std::endl;
    std::cout << "Value for Y: " << psy << std::endl;
    std::cout << "Value for Z: " << psz << std::endl;
    std::cout << "--------------------------" << std::endl;
}

int main() {//driver
    std::vector<std::string> movej;
    std::vector<std::string> movel_vals;
    std::vector<std::string> movel;
    std::cout << "   ___________          _ \n";
    std::cout << "  / ____/ ___/_________(_)\n";
    std::cout << " / / __ \\__ V ___/ ___/ / \n";
    std::cout << "/ /_/ /___/ / /__/ / / /  \n";
    std::cout << "\\____//____/\\___/_/ /_/ \n";
    std::cout << "A GCODE to UR Script Command Converter | version 1.3" << std::endl;
    std::cout << "MSc. Mechatronics - Mechatronics Design Build | University of Southern Denmark" << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << "\n\t\t\t   Author: J A C O B  T H O M A S  P U T H U K E R I L\n\n";
    std::cout << "\t\t\t\t\t\t    Repo: github.com/Jacob8089" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t   Uni: sdu.dk\n\n";
    std::cout << "==============================================================================" << std::endl;

    bool op_status = true;
    int i = 0;
    string option;
    while (op_status) {

        // std::string dummy;
        std::string tcp_vals;
        std::cout << "\nEnter your TCP values in X, Y, Z, rx, ry & rz values in meters:" << std::endl;
        std::getline(std::cin, tcp_vals);
        std::string in_g_code;
        std::cout << "\nEnter your Gcode:" << std::endl;
        std::getline(std::cin, in_g_code);
        int in_len = in_g_code.length();
        try {
            if (in_len != 0) { g_code_conv(in_g_code); }
            else { throw(in_len); }
        }

        catch (int errorVal) {
            cout << "Something went wrong. The length value is " << errorVal << endl;
        }

        cout << "\nDo you want to continue.?(Y/N)" << endl;
        std::getline(std::cin, option);

        if (option == "Y" || option == "y") {
            continue;
        }
        else { op_status = false; }

    }

    cout << "\nGScri operation is terminated." << endl;
    Sleep(1500);

    return 0;
}