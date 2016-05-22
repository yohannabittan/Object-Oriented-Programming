namespace BrooklynPoly {

	class Student;

	class Course {

	private:
		string name;
		vector<Student*> students;

	public:
		Course(string name);//constructor
		~Course();//destructor

		string getName();

		vector<Student*> getStudents();

		void dropStudent(Student* student);
		void addStudent(Student* student);
		

	};
}

