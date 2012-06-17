#include "MyApplication.h"

#include "BondForm.h"
#include "BondView.h"
#include "MyApplicationPresenter.h"
#include "MyCanvasPresenter.h"
#include "MyCanvasView.h"
#include "services/BondPricerService.h"
#include "utils.h"
#include "BondCalculationTask.h"
#include "BondTableModel.h"
#include "StatusBarView.h"
#include "StatusBarPresenter.h"
#include "ToolBarView.h"

#include <QtGui>

#include <boost/shared_ptr.hpp>
#include <Poco/NotificationCenter.h>
#include <Poco/Task.h>
#include <Poco/TaskManager.h>

MyApplication::MyApplication() {
    Logger::logConstructor("MyApplication");
}

MyApplication::~MyApplication() {
    Logger::logDestructor("MyApplication");
}

int MyApplication::run(int argc, char *argv[]) {
    

    QApplication app(argc, argv);

    Poco::NotificationCenter notificationCenter;

    QMainWindow mainWindow;

    BondViewPtr view(new BondView());
    MyApplicationPresenter presenter(view, notificationCenter);
    QDockWidget * bondDataDockWidget = new QDockWidget("Bond Data");
    bondDataDockWidget->setWidget(view->container());
    mainWindow.addDockWidget(Qt::LeftDockWidgetArea, bondDataDockWidget);

    BondTableModel model1(0);
    MyCanvasViewPtr canvasView(new MyCanvasView(&model1));
    MyCanvasPresenter canvasPresenter(canvasView, notificationCenter);
    QDockWidget * canvasDockWidget = new QDockWidget("My Canvas View");
    canvasDockWidget->setWidget(canvasView->container());
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, canvasDockWidget);

    BondTableModel model2(0);
    MyCanvasViewPtr canvasView2(new MyCanvasView(&model2));
    MyCanvasPresenter canvasPresenter2(canvasView2, notificationCenter);
    QDockWidget * canvasDockWidget2 = new QDockWidget("My Canvas View");
    canvasDockWidget2->setWidget(canvasView2->container());
    mainWindow.setCentralWidget(canvasDockWidget2);

    StatusBarViewPtr statusBar(new StatusBarView());
    StatusBarPresenter statusBarPresenter(statusBar, notificationCenter);
    mainWindow.setStatusBar(statusBar->statusBarWidget());

    ToolBarViewPtr toolBar(new ToolBarView());
    mainWindow.addToolBar(toolBar->toolBarWidget());

    mainWindow.show();

    return app.exec();
}
