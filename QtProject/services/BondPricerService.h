#ifndef BONDPRICERSERVICE_H
#define	BONDPRICERSERVICE_H

#include "utils.h"

#include <QtCore/QDate>
#include <boost/timer.hpp>
#include <boost/utility.hpp>
#include <vector>
#include <Poco/TaskManager.h>

struct BondData {
    QDate issueDate;
    QDate maturity;
    double couponRate;
    double marketQuote;
};

struct BondDataList {
    QDate settlementDate;
    int fixingDays;
    int settlementDays;
    
    // ZC rates for the short end
    double zc3mQuote;
    double zc6mQuote;
    double zc1yQuote;
    
    // setup bonds
    double redemption;
    int numberOfBonds;
    
    std::vector<BondData> bondDatas;
};

#endif