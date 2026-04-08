
public class ShallowCopy 
{
	public static void main(String[] args) {
		
		Student st1 = new Student(1,"a",45.5);
		System.out.println("st1 records :");
		st1.displayRecord();
		Student st2 = st1; //shallow copy
		System.out.println("st2 record : ");
		st2.displayRecord();
		
		st1.setId(5);
		System.out.println("records after changing id at st1");
		System.out.println("st1 record");
		st1.displayRecord();
		System.out.println("st2 record");
		st2.displayRecord();
		
	}

}
