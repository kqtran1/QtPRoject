#include "ToolBarView.h"

#include <QtGui/QAction>
#include <QtGui/QIcon>

ToolBarView::ToolBarView():
toolBar(new QToolBar())
{
	QAction * openFileAction = new QAction(QIcon("openFile.png"), "Open File", 0);
	toolBar->addAction(openFileAction);
}


ToolBarView::~ToolBarView()
{
}

const QWidget* ToolBarView::container() const
{
	return toolBar;
}

QToolBar* ToolBarView::toolBarWidget() const
{
	return toolBar;
}
