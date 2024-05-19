#include <QString>
#include <QApplication>
#include <vector>

class Calculator {
public:
	Calculator(QString month, int body_count, QString building);
	~Calculator();
	
	double getCo2();
	int getBodyCount();
	int getMark();
	QString getMonth();
	QString getDescription();
	QString getBuilding();
	double getDustValue();
	void calcAllYearCo2();
	std::vector<double> getAllYearCo2();
	std::vector<double> getAllYearDust();

private:
	const double Vmatfak = 3000;
	const double Vsho = 2500;
	const double Vgymnast = 3200;
	const double Vtren = 1800;
	const double Vgroupp = 1500;
	const double t = 90;
	const std::vector<double> Avec_matfak{0.53, 0.541, 0.542, 0.55, 0.543, 0.544, 0.52, 0.5, 0.49, 0.51};
	const std::vector<double> Avec_sho{0.461, 0.471, 0.472, 0.48, 0.473, 0.46, 0.45, 0.43, 0.42, 0.431};
	const std::vector<double> Avec_gymnast{0.761, 0.771, 0.782, 0.79, 0.78, 0.772, 0.76, 0.723, 0.69, 0.71};
	const std::vector<double> Avec_tren{0.89, 0.901, 0.91, 0.92, 0.912, 0.90, 0.88, 0.84, 0.81, 0.83};
	const std::vector<double> Avec_groupp{0.80, 0.811, 0.821, 0.822, 0.812, 0.813, 0.79, 0.75, 0.72, 0.74};
	const double MCO2 = 350;
	// пыль
	const std::vector<double> k{ 1,	2,	3,	4,	5,	2,	5,	4,	3,	2};
	const std::vector<double> idd{5,4,4,2,2};

private:
	double calcCo2();
	double calcDust();

private:
	QString month;
	QString build;
	double co2;
	int mark = 0;
	double body_count = 0;
	QString description;
	double dust_value;
	std::vector<double> allco2;
};