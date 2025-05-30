
#include <stdexcept>

#include "Student_info.h"
#include "median.h"
#include "grade.h"


using std::domain_error;


// grade(double, double, double)
double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// grade(double, double, const vector<double>&)
double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework entered!");

	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.get_midterm(), s.get_final(), s.get_hw());
}

// 학생의 과락 여부를 결정하는 서술 함수
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
	// return grade(s) >= 60; 택 1
	return !fgrade(s); // 택 2
}