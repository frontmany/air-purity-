#include "mainwindow.h";
using namespace std;

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow* mw = new MainWindow();
	mw->setMinimumSize(640, 480);
	mw->resize(1280, 720);
	// Toolbar
	QToolBar* toolbar = new QToolBar;
	QPushButton* build1 = new QPushButton;
	build1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build1->setMinimumSize(100, 100);
	QPushButton* build2 = new QPushButton;
	build2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build2->setMinimumSize(100, 100);
	QPushButton* build3 = new QPushButton;
	build3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build3->setMinimumSize(100, 100);
	QPushButton* build4 = new QPushButton;
	build4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build4->setMinimumSize(100, 100);
	toolbar->setOrientation(Qt::Horizontal);
	toolbar->addWidget(build1);
	toolbar->addWidget(build2);
	toolbar->addWidget(build3);
	toolbar->addWidget(build4);
	mw->addToolBar(toolbar);

	mw->show();
	return app.exec();
}