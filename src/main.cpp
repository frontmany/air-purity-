#include "mainwindow.h";
using namespace std;

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow* mw = new MainWindow();
	mw->resize(1280, 720);
	// Toolbar
	QToolBar* toolbar = new QToolBar;
	QPushButton* build1 = new QPushButton;
	build1->setFixedSize(200, 100);
	QPushButton* build2 = new QPushButton;
	build2->setFixedSize(200, 100);
	QPushButton* build3 = new QPushButton;
	build3->setFixedSize(200, 100);
	toolbar->setOrientation(Qt::Horizontal);
	toolbar->addWidget(build1);
	toolbar->addWidget(build2);
	toolbar->addWidget(build3);
	mw->addToolBar(toolbar);

	mw->show();
	return app.exec();
}