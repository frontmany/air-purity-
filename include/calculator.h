#include <QString>
#include <QApplication>
#include <vector>

class Calculator {
public:
	Calculator(int slider_pos, int body_count, QString season, QString building);
	~Calculator();
	
	double getCo2Value();
	double getCo2();
	int getBodyCount();
	int getMark();
	QString getMonth();
	QString getDescription();
	QString getBuilding();
	double getDustValue();
	std::vector<double> getAllYearCo2();
	std::vector<double> getAllYearDust();

private:
	const double Vmatfak = 600;
	const double Vipip = 1200;
	const double Vgymnast = 1200;
	const double Vgym = 1200;
	const double Vstretch = 1200;
	const double windows_open_time = 0.546;
	const double pollution = 4;

private:
	QString month;
	QString build;
	double co2;
	int mark = 0;
	int body_count = 0;
	QString description;
	double dust_value;
};