package interfaces.comparator;

public class StudentSorterAscByName implements Comparable<Student>{
    @java.lang.Override
    public int compareTo(Student s1, Student s2) {
        return s1.getLastName().compareTo(s2.getLastName());
    }
}
