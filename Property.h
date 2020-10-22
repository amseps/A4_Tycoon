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

    static int propID;

    enum location{NE, SE, SW, NW} loc;
    int propertyValue;
    int propertyValueWithEvent;
    int mortgageTotal;
    int mortgageDuration;
    int mortgageMonthly;
    int myID;

    const double propertyTax = .015;

    int rent;

    virtual void adjustRentTo(const int & in, const int & space);

    std::string dictateLocation() const;

    void payMortgage();
    int getPropertyTax();

    bool sameInstance(const Property & in);

    Property();
    Property(const Property & in);
    ~Property();
    Property & operator=(const Property & in);
    virtual std::ostream & operator<<(std::ostream & _stream);
    virtual operator std::string() const;
    virtual std::string ts(); //whatever
};


#endif //A4_TYCOON_PROPERTY_H
