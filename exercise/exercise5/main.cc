#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
using namespace std;
class Student
{
	private:
		string name;
		int num;
		float average;
	public:
		list <int> scores;
		Student(string name_, int num_, int average_) {name = name_; num = num_; average = average_ ;};
		~Student() {};
		string getName() const { return name; };
		float getAverage() const { return average; };
		void countAverage();
		void printScores() const;
		void sortScore();
};

void Student::countAverage()
{
	average = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
}

void Student::printScores() const
{
 	copy(begin(scores), end(scores),
	ostream_iterator<int>(cout, " "));
}

void Student::sortScore()
{
	scores.sort(greater<int>());
}

bool operator<(Student const & A, Student const & B) 
{
	float a = A.getAverage();
	float b = B.getAverage();
	return a < b;
}


int main()
{
	int schoolNum;
	cin >> schoolNum;
	for (int i=0; i<schoolNum; ++i){
		int stuNum;
		int courseNum;
		cin >> stuNum >> courseNum;
		list <Student> school;
		for (int j=0; j<stuNum; ++j){
			string stuName;
			cin >> stuName;
			Student stu(stuName, courseNum, stu.getAverage());
			for (int  k=0; k<courseNum; ++k){
		    	int score_;
				cin >> score_;
				stu.scores.push_front(score_);					
			}
			stu.countAverage();
			stu.sortScore();
			school.push_front(stu);
		}	
		school.sort();
		while (!school.empty()) {
	 		cout << school.back().getName() << ":";
			school.back().printScores();
			cout << school.back().getAverage();
		   	school.pop_back();
	   		cout << endl;
		}
		cout << "==========" << endl;
	}
}
