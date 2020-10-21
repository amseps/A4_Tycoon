//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_PROPERTY_H
#define A4_TYCOON_PROPERTY_H


class Property {
private:

public:
    enum location{NE, SE, SW, NW};
    int propertyValue;
    int mortgage;
    int mortgageDuration;
    const double propertyTax = 1.5;

    Property();
    Property(const Property & in);
    ~Property();
    Property & operator=(const Property & in);
};


#endif //A4_TYCOON_PROPERTY_H
