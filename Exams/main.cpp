#include <iostream>
#include <unordered_map>

#include "FileManager.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cerr;

typedef vector<string> row_type;
typedef vector<row_type> table_type;
typedef unordered_map<unsigned,StudentsData> students_type;

void add_students (const table_type&, students_type&);
void add_exams (const table_type&, students_type&);

int main () {

    string filename_students = "../students.txt";
    string filename_exams = "../exams.txt";

    students_type students;

    FileManager FM;

    // parse students file
    table_type fields = FM.parse_file(filename_students);

    // add students to the map
    add_students(fields, students);

    // parse exams file
    fields = FM.parse_file(filename_exams);

    // add exams to the corresponding students, if they exist in the map
    add_exams(fields, students);

    // compute and print average of students' grades
    float sum=0;

    for(const auto & student : students){
        sum+=student.second.average_grade();
    }

    float avg=sum/students.size();

    std::cout << "Average grade of all the students: " << avg << std::endl;

    for(const auto & student : students){
        std::cout << "Student id: " << student.first << " Average: " << student.second.average_grade() << std::endl;
    }

}

void add_students (const table_type& fields, students_type& students) {
    for(auto my_row : fields){
    unsigned id=std::stoul(my_row[0]);
    StudentsData new_stud(my_row[1],my_row[2],my_row[3]);
    students.insert(std::make_pair(id,new_stud));
    }
}

void add_exams (const table_type& fields, students_type& students) {
    unsigned n_start=students.size();
    for(unsigned j=n_start; j<fields.size(); j++){
        row_type my_row=fields[j];
        unsigned id=std::stoul(my_row[0]);
        auto ptr=students.find(id);
        Exam my_exam(std::stoul(my_row[1]),my_row[2],std::stoul(my_row[3]));
        if(ptr!=students.end()){
            ptr->second.add_exam(my_exam);
        }
        else
            std::cout << "Student not found" << std::endl;
    }
}


