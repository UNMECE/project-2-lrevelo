#include <iostream>
#include <vector>
#include <fstream>

class Student {
protected:
	std::string first_name;
	std::string last_name;
	float gpa;
	int grad_year;
	std::string grad_semester;
	int enrolled_year;
	std::string enrolled_semester;
	std::string level;

public:
	Student() {
		first_name = "First";
		last_name = "Last";
		gpa = 0.0;
		grad_year = 0;
		grad_semester = "N/A";
		enrolled_year = 0;
		enrolled_semester = "N/A";
		level = "undergrad";
	}

	virtual ~Student() {}

	void setName(const std::string& first, const std::string& last) {
		first_name = first;
		last_name = last;
	}
	void setGPA(float grade) {
		gpa = grade;
	}

	void setGradYear(int year) {
		grad_year = year;
	}

	void setGradSemester(const std::string& semester) {
		grad_semester = semester;
	}

	void setEnrolledYear(int year) {
		enrolled_year = year;	
	}

	void setEnrolledSemester(const std::string& semester){
		enrolled_semester = semester;
	}

	void setLevel(const std::string& stage) {
		level = stage;
	}

	std::string getName() const {
		return first_name + " " + last_name;
	}

	float getGPA() const {
		return gpa;
	}

	std::string getGradSemester() const {
		return grad_semester;
	}

	int getEnrolledYear() const {
		return enrolled_year;
	}

	std::string getEnrolledSemester() const {
		return enrolled_semester;
	}

	std::string getLevel() const {
		return level;
	}

	virtual void printInfo(std::ostream& out) const {
		out << "Name: " << getName() << "\n" << "GPA: " << gpa << "\n" << "Graduation: " << grad_semester << " " << grad_year << "\n" << "Enrolled: " << enrolled_semester << " " << enrolled_year << "\n" << "Level: " << level << "\n";	
	}
};

class Art_Student : public Student {
private:
	std::string art_emphasis;

public:
	Art_Student() : art_emphasis("N/A") {}

	void setArtEmphasis(const std::string& emphasis) {
		art_emphasis = emphasis;
	}

	std::string getArtEmphasis() const {
		return art_emphasis;
	}

	void printInfo(std::ostream& out) const override {
		Student::printInfo(out);
		out << "Art Emphasis: " << art_emphasis << "\n";
	}
};

class Physics_Student : public Student {
private:
	std::string concentration;

public:
	Physics_Student() : concentration("N/A") {}

	void setConcentration(const std::string& conc) {
		concentration = conc;
	}

	std::string getConcentration() const {
		return concentration;
	}

	void printInfo(std::ostream& out) const override {
		Student::printInfo(out);
		out << "Concentration: " << concentration << "\n";
	}
};

int main() {
	std::vector<Art_Student*> art_students;
	std::vector<Physics_Student*> physics_students;

	std::string artFirstNames[] = {"Emily", "Jackson", "Sophia", "Liam", "Olivia"};
	std::string artLastNames[] = {"Smith", "Brown", "Davis", "Miller", "Wilson"};
	std::string artEmphases[] = {"Art Studio", "Art History", "Art Education", "Art Studio", "Art History"};


	for (int i = 0; i < 5; i++) {
		Art_Student* artStudent = new Art_Student;
		artStudent->setName(artFirstNames[i], artLastNames[i]);
		artStudent->setGPA(3.4f + i * 0.1f);
		artStudent->setGradYear(2025 + i);
		artStudent->setGradSemester("Spring");
		artStudent->setEnrolledYear(2021 + i);
		artStudent->setEnrolledSemester("Fall");
		artStudent->setLevel("undergrad");
		artStudent->setArtEmphasis(artEmphases[i]);
		art_students.push_back(artStudent);
	}

	std::string physicsFirstNames[] = {"Ethan", "Ava", "Mason", "Isabella", "Noah"};
	std::string physicsLastNames[] = {"Anderson", "Garcia", "Martinez", "Robinson", "Lee"};
	std::string concentrations[] = {"Biophysics", "Earth and Planetary Sciences", "Biophysics", "Earth and Planetary Sciences", "Biophysics"};

	for (int i = 0; i < 5; i++) {
		Physics_Student* physicsStudent = new Physics_Student;
		physicsStudent->setName(physicsFirstNames[i], physicsLastNames[i]);
		physicsStudent->setGPA(2.4f + i * 0.15f);
		physicsStudent->setGradYear(2024 + i);
		physicsStudent->setGradSemester("Fall");
		physicsStudent->setEnrolledYear(2020 + i);
		physicsStudent->setEnrolledSemester("Spring");
		physicsStudent->setLevel("grad");
		physicsStudent->setConcentration(concentrations[i]);
		physics_students.push_back(physicsStudent);
	}

	std::ofstream outfile("student_info.dat");
	if (outfile.is_open()) {
		outfile << "--- Art Students ---\n";
		for (const auto& student : art_students) {
			student->printInfo(outfile);
			outfile << "\n";
		}

		outfile << "--- Physics Students ---\n";
		for (const auto& student : physics_students) {
			student->printInfo(outfile);
			outfile << "\n";
		}
		outfile.close();
	}
	else {
		std::cerr << "Error: Could not open file.\n";
	}

	for (auto student : art_students) delete student;
	for (auto student : physics_students) delete student;

	return 0;

}




