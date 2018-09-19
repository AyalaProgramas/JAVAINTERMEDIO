package program;

public class Program {

	public static void main(String[] args) {
		Object o= new Object();
		
		System.err.println(o.toString());
		//se usa mucho en interface grafica 
		Object o2=new Object()
				{
					public String toString()
					{
						return "estoy adentro de una clase anonima";
					}
				};
				
		System.out.println(o2.toString());
		
		
	}

}
