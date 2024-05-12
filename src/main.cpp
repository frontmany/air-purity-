#include "mainwindow.h";
#include <QProxyStyle>
#include <QStyleOptionTitleBar>
#include "favourite.h"

class CustomTitleBarStyle : public QProxyStyle {
public:
	void polish(QPalette& palette) override {

		palette.setColor(QPalette::Window, QColor(26, 26, 26)); 
	}
};



int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	app.setStyle(new CustomTitleBarStyle);



	MainWindow* mw = new MainWindow();
	mw->setMinimumSize(1020, 830);
	mw->showMaximized();
	mw->show();
	return app.exec();
}