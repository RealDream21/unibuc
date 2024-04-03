package interfaces.comparator;

public class StudentApp {

    public static void main(String[] args) {
        Student[] students = {
                new Student("Ion", "Pop", 20),
        new Student("Dan", "Popa", 11),
        new Student("Tom", "Adam", 24),
        new Student("Jerry", "Adam", 24)
        };

        System.out.println("Unsorted: " + Arrays.toString(students));
        Arrays.sort(students, new StudentSorterAscByName());

        System.out.println("Sorted by name asc: " + Arrays.toString(students));
        Arrays.sort(students, new StudentSorterDescByAge());
        System.out.println("Sorted by age desc: " + Arrays.toString(students));

        Comparator<Student> sortStudentByLastNameAndAfterByFirstName = new Comparator<Student>(){
            public int compare(Student s1, Student s2){
                int lastNameCompare = s1.getLastName().compareTo(s2.getLastName());
                int firstNameCompare = s1.getFirstName().compareTo(s2.getFirstName());

                return (lastNameCompare == 0) ? firstNameCompare : lastNameCompare;
            }
        };

        Arrays.sort(students, sortStudentByLastNameAndAfterByFirstName);
        System.out.println("Sorted by last name asc then first name asc:\n" + Arrays.toString(students));


        Comparator<Student> studentComparatorByFirstName = (s1, s2) -> s2.getFirstName().compareTo(s1.getFirstName());

//        Comparator<Student> studentComparatorByFirstName = (Student s1, Student s2) -> {return s2.getFirstName().compareTo(s1.getFirstName())};

        Arrays.sort(students, studentComparatorByFirstName);
        System.out.println("Sorted by first name\n" + Arrays.toString(students));


    }
}
