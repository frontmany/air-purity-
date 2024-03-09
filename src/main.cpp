#include "mainwindow.h";

using namespace std;

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow* mw = new MainWindow();
	mw->setMinimumSize(640, 480);
	mw->resize(1280, 720);


	mw->show();
	return app.exec();
}