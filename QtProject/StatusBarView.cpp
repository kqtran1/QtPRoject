#include "StatusBarView.h"

#include <QtCore/QString>

StatusBarView::StatusBarView() : statusBar(new QStatusBar())
{
}


StatusBarView::~StatusBarView()
{
}

const QWidget* StatusBarView::container() const
{
	return statusBar;
}

QStatusBar* StatusBarView::statusBarWidget() const
{
	return statusBar;
}

void StatusBarView::showMessage( std::string message )
{
	statusBar->showMessage(QString::fromStdString(message));
}
