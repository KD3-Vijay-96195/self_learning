
public class Student 
{
	private int id;
	private String name;
	private double marks;
	
	public Student()
	{
		
	}
	public Student(int id, String name, double marks)
	{
		this.id = id;
		this.name = name;
		this.marks = marks;
	}
	
	public int getId()
	{
		return this.id;
	}
	public void setId(int id)
	{
		this.id = id;
	}
	public String getName()
	{
		return this.name;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	public double getMarks()
	{
		return this.marks;
	}
	public void setMarks(double marks)
	{
		this.marks = marks;
	}
	
	public void displayRecord()
	{
		System.out.println("id : "+id);
		System.out.println("name : "+name);
		System.out.println("marks : "+marks);
	}
	
	@Override
	public String toString()
	{
		return String.format("id : %d, name : %s, marks : %f", id, name, marks);
	}

}
































