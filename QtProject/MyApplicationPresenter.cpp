#include "MyApplicationPresenter.h"
#include "Event.h"
#include "utils.h"

#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>

#include <QtCore>

MyApplicationPresenter::MyApplicationPresenter(boost::shared_ptr<BondView> view,
        Poco::NotificationCenter & notificationCenter) :
Presenter<BondView>(view, notificationCenter) 
{
    Logger::logConstructor("MyApplicationPresenter");

    QObject::connect(view->couponRateInput(), SIGNAL(returnPressed()), this, SLOT(logNothing()));

}

MyApplicationPresenter::~MyApplicationPresenter() {
    Logger::logDestructor("MyApplicationPresenter");
}

void MyApplicationPresenter::log(std::string msg) const {
    std::cout << msg << std::endl;
}

void MyApplicationPresenter::logNothing() {
    BondDataList data;

    data.fixingDays = 3;
    data.settlementDays = 3;
    data.settlementDate = QDate();
    data.zc3mQuote = 0.0096;
    data.zc6mQuote = 0.0145;
    data.zc1yQuote = 0.0194;

    data.redemption = 100.0;
    data.numberOfBonds = 1;

    BondData bondData;
    
    bondData.issueDate =presenterView->issueDateEdit()->date(); 
 
    bondData.maturity = presenterView->maturityDateEdit()->date(); 
    
    bondData.couponRate = presenterView->couponRateInput()->text().toDouble();
    bondData.marketQuote = presenterView->marketQuoteInput()->text().toDouble();

    notificationCenter.postNotification(new AddBondNotification(bondData));
}