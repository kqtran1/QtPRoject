#ifndef TOOLBARVIEW_H
#define TOOLBARVIEW_H

#include "mvp/View.h"

#include <QtGui/QToolBar>
#include <boost/shared_ptr.hpp>

class ToolBarView : public View
{
public:
	ToolBarView();
	~ToolBarView();

	virtual const QWidget* container() const;
	virtual QToolBar* toolBarWidget() const;

private:
	QToolBar * toolBar;

};

typedef boost::shared_ptr<ToolBarView> ToolBarViewPtr;

#endif


