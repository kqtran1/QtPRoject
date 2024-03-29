#include "StatusBarPresenter.h"

#include <Poco/NObserver.h>
#include <iostream>
#include <sstream>

using namespace std;

StatusBarPresenter::StatusBarPresenter(boost::shared_ptr<StatusBarView> view, Poco::NotificationCenter & notificationCenter):
Presenter(view, notificationCenter)
{
	Logger::logConstructor("StatusBarPresenter");
	notificationCenter.addObserver(Poco::NObserver<StatusBarPresenter, AddBondNotification > (*this, &StatusBarPresenter::handle));
}


StatusBarPresenter::~StatusBarPresenter()
{
	Logger::logDestructor("StatusBarPresenter");
}

void StatusBarPresenter::handle(const Poco::AutoPtr<AddBondNotification> & notification)
{
	ostringstream stringBuilder;
	stringBuilder << "Add New Bond Data: ";
	stringBuilder << notification->bondData().couponRate;
	view()->showMessage(stringBuilder.str());
}
