#include "mainwindow.h";
#include <QProxyStyle>
#include <QStyleOptionTitleBar>

class CustomTitleBarStyle : public QProxyStyle {
public:
	void polish(QPalette& palette) override {

		palette.setColor(QPalette::Window, QColor(59, 59, 59)); // Поменяйте цвет на нужный вам
	}
};


int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	app.setStyle(new CustomTitleBarStyle);
	MainWindow* mw = new MainWindow();
	mw->setMinimumSize(740, 480);
	mw->resize(1280, 720);



	mw->show();
	return app.exec();
}