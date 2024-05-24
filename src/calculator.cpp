#include "calculator.h"


double Calculator::getCo2() {
	return co2;
}
std::vector<double> Calculator::getAllYearCo2() {
	return allco2;
}
int Calculator::getBodyCount() {
	return body_count;
}
int Calculator::getMark() {
	return mark;
}
QString Calculator::getMonth() {
	return QString::fromStdString(month);
}
QString Calculator::getDescription() {
	return description;
}
QString Calculator::getBuilding() {
	return build;
}
double Calculator::getDustValue() {
	return dust_value;
}

std::vector<double> Calculator::getAllYearDust(){
	std::vector<double> alldust;
	
	if (build == "Школа Компьютерных Наук") {
		for (auto j : k) {
			double monthdustvalue = idd[0] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Школа Образования") {
		for (auto j : k) {
			double monthdustvalue = idd[1] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Олимпия: Гимнастический Зал") {
		for (auto j : k) {
			double monthdustvalue = idd[2] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Олимпия: Тренажерный Зал") {
		for (auto j : k) {
			double monthdustvalue = idd[3] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Олимпия: Зал Групповых Программ") {
		for (auto j : k) {
			double monthdustvalue = idd[4] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	return alldust;
}

void Calculator::calcAllYearCo2() {
	if (build == "Школа Компьютерных Наук") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Школа Образования") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vsho * Avec_sho[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Олимпия: Гимнастический Зал") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Олимпия: Тренажерный Зал") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vtren * Avec_tren[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Олимпия: Зал Групповых Программ") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[i]);
			allco2.push_back(monthco2value);
		}
	}
	
}

double Calculator::calcCo2() {
	int monthIndex;
	if (month == "Январь") monthIndex = 0;
	else if (month == "Февраль") monthIndex = 1;
	else if (month == "Март") monthIndex = 2;
	else if (month == "Апрель") monthIndex = 3;
	else if (month == "Май") monthIndex = 4;
	else if (month == "Июнь") monthIndex = 5;
	else if (month == "Сентябрь") monthIndex = 6;
	else if (month == "Октябрь") monthIndex = 7;
	else if (month == "Ноябрь") monthIndex = 8;
	else if (month == "Декабрь") monthIndex = 9;

	if (build == "Школа Компьютерных Наук") {
		return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[monthIndex]);
	}

	if (build == "Школа Образования") {
		return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[monthIndex]);
	}

	if (build == "Олимпия: Гимнастический Зал") {
		return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[monthIndex]);
	}

	if (build == "Олимпия: Тренажерный Зал") {
		return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[monthIndex]);
	}

	if (build == "Олимпия: Зал Групповых Программ") {
		return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[monthIndex]);
	}
}

double Calculator::calcDust() {
	std::map<std::string, int> monthIndex = {
	{"Январь", 0},
	{"Февраль", 1},
	{"Март", 2},
	{"Апрель", 3},
	{"Май", 4},
	{"Июнь", 5},
	{"Сентябрь", 6},
	{"Октябрь", 7},
	{"Ноябрь", 8},
	{"Декабрь", 9}
	};



	if (build == "Школа Компьютерных Наук") {
		if (build == "Школа Компьютерных Наук" && monthIndex.find(month) != monthIndex.end()) {
			int index = monthIndex[month];
			return k[index] * idd[0];
		}
	}

	if (build == "Школа Образования") {
		if (build == "Школа Образования" && monthIndex.find(month) != monthIndex.end()) {
			int index = monthIndex[month];
			return k[index] * idd[1];
		}
	}

	if (build == "Олимпия: Гимнастический Зал") {
		if (build == "Олимпия: Гимнастический Зал" && monthIndex.find(month) != monthIndex.end()) {
			int index = monthIndex[month];
			return k[index] * idd[2];
		}
	}

	if (build == "Олимпия: Тренажерный Зал") {
		if (build == "Олимпия: Тренажерный Зал" && monthIndex.find(month) != monthIndex.end()) {
			int index = monthIndex[month];
			return k[index] * idd[3];
		}
	}

	if (build == "Олимпия: Зал Групповых Программ") {
		if (build == "Олимпия: Зал Групповых Программ" && monthIndex.find(month) != monthIndex.end()) {
			int index = monthIndex[month];
			return k[index] * idd[4];
		}
	}

}

Calculator::Calculator(QString month, int bodyCount, QString building) {
	build = building;
	body_count = bodyCount;
	this->month = month.toStdString();
	
	calcAllYearCo2();
	co2 = calcCo2();
	dust_value = calcDust();
}



Calculator::~Calculator() {

}