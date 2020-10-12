#include "ipv4.h"

#include <algorithm>

#include <QDebug>

// -------------------------------------- CONSTRUCTOR, DESTRUCTOR --------------------------------------

IPv4::IPv4() {
    std::fill(this->_octets, this->_octets + MAX_OCTETS, 0);
}

IPv4::IPv4(uchar o1, uchar o2, uchar o3, uchar o4) : _octets {o1, o2, o3, o4} {}

IPv4::IPv4(std::initializer_list<uchar> list) {
    std::fill(this->_octets, this->_octets + MAX_OCTETS, 0);

    std::size_t octIdx = 0;

    for (auto oct : list) {
        if (octIdx >= MAX_OCTETS)
            return;

        this->_octets[octIdx] = oct;
        ++octIdx;
    }
}




// -------------------------------------- OTHER --------------------------------------

QString IPv4::QStr() const {
    QString qStr = "";

    for (std::size_t octInd = 0; octInd < MAX_OCTETS; ++octInd)
        qStr.append(QString::number(this->_octets[octInd]) + '.');

    qStr.chop(1);

    return qStr;
}

IA_t IPv4::type() {
    return IA_t::IPv4;
}



// -------------------------------------- OVERLOADED OPERATORS --------------------------------------

QTextStream& IPv4::operator<<(QTextStream &ostream) {
    return ostream << this->QStr();
}

bool IPv4::operator<(const IPv4 &other) const {
    for (std::size_t octIdx = 0; octIdx < MAX_OCTETS; ++octIdx)
        if (this->_octets[octIdx] > other._octets[octIdx])
            return false;

    return this->_octets[MAX_OCTETS-1] < other._octets[MAX_OCTETS-1];
}

bool IPv4::operator<=(const IPv4 &other) const {
    return (*this < other || *this == other);
}

bool IPv4::operator>(const IPv4 &other) const {
    for (std::size_t octIdx = 0; octIdx < MAX_OCTETS; ++octIdx)
        if (this->_octets[octIdx] < other._octets[octIdx])
            return false;

    return this->_octets[MAX_OCTETS-1] > other._octets[MAX_OCTETS-1];
}

bool IPv4::operator>=(const IPv4 &other) const {
    return (*this > other || *this == other);
}

bool IPv4::operator==(const IPv4 &other) const {
    for (std::size_t octIdx = 0; octIdx < MAX_OCTETS; ++octIdx)
        if (this->_octets[octIdx] != other._octets[octIdx])
            return false;

    return true;
}