#include <string>
#include "Scale.h"

using namespace std;


struct TemperatureData
{
	TemperatureData();

	void CreateTemperatureDataFromUserInput();
	void PresentAllTemperatureScales();
	double GetTemperatureInKelvin();
	double GetTemperatureInCelcius();
	double GetTemperatureInFahrenheit();
	string GetScaleString();

	Scale GetScale();
	double GetTemperature();
	int GetYear();

private:
	void ObtainScale();
	void ObtainTemperature();
	void ObtainYear();

	Scale _scale;
	double _temperature;
	int _year;
};

