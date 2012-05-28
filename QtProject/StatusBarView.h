#include "mvp/View.h"

#include <QtGui/QStatusBar>
#ifndef STATUSBARVIEW_H
#define	STATUSBARVIEW_H

#include <boost/shared_ptr.hpp>
#include <string>

class StatusBarView : public View
{
public:
	StatusBarView();
	~StatusBarView();

	virtual const QWidget* container() const;
	QStatusBar* statusBarWidget() const;

	void showMessage(std::string message);

private:
	QStatusBar * statusBar;
};

typedef boost::shared_ptr<StatusBarView> StatusBarViewwPtr;

#endif

