#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

struct Flight {
    std::string from;
    std::string to;
    int distance;
    bool skip;  // ������������ ��� ��������� ������
};

#endif // FLIGHT_H
