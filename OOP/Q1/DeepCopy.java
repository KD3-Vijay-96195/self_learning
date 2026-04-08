
public class DeepCopy 
{
	public static void main(String[] args) {
		
		Student st1 = new Student(1,"a",45.5);
		System.out.println("st1 records :");
		st1.displayRecord();
		
		Student st2 = new Student();
		st2.setId(st1.getId());
		st2.setName(st1.getName());
		st2.setMarks(st1.getMarks());
		System.out.println("st2 record");
		st2.displayRecord();
		st1.setId(5);
		System.out.println("st1 record after changing id : ");
		st1.displayRecord();
		System.out.println("st2 record after changing id of st1:");
		st2.displayRecord();
		
		
		
		
		
	}

}
