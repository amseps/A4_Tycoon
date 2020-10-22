//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_PROPERTY_H
#define A4_TYCOON_PROPERTY_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Property {
private:

public:
    enum location{NE, SE, SW, NW} loc;
    int propertyValue;
    int propertyValueWithEvent;
    int mortgageTotal;
    int mortgageDuration;
    int mortgageMonthly;

    const double propertyTax = 1.5;

    int rent;

    virtual void adjustRentTo(const int & in, const int & space);

    std::string dictateLocation();

    void payMortgage();
    int getPropertyTax();

    Property();
    Property(const Property & in);
    ~Property();
    Property & operator=(const Property & in);
    virtual std::ostream & operator<<(std::ostream & _stream);
};


#endif //A4_TYCOON_PROPERTY_H
