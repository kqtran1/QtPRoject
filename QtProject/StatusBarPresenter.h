#ifndef STATUSBARPRESENTER_H
#define	STATUSBARPRESENTER_H

#include "mvp/Presenter.h"
#include "StatusBarView.h"
#include "Event.h"

#include <string>

class StatusBarPresenter : public Presenter<StatusBarView>
{
public:
	StatusBarPresenter(boost::shared_ptr<StatusBarView> view, Poco::NotificationCenter & notificationCenter);
	~StatusBarPresenter();

	void handle(const Poco::AutoPtr<AddBondNotification> & notification);
};

#endif
