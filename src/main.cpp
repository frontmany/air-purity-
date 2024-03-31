#include "mainwindow.h";
#include <QProxyStyle>
#include <QStyleOptionTitleBar>

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
	mw->setMinimumSize(740, 480);
	mw->resize(740, 480);
	


	mw->show();
	return app.exec();
}