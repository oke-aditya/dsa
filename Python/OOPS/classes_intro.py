class Student:
    # Contructor
    def __init__(self, id: int, fees: int) -> None:
        self.id = id
        self.fees = fees
    
    # Describe the class
    def __str__(self) -> str:
        return f"Student = {student.id} and {student.fees}"

    def study(self):
        self.state = "studying"


if __name__ == "__main__":
    student = Student(id=1, fees=10)
    print(student)
    student.study()
    print(student.state)
