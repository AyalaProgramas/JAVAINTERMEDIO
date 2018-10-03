package genericos;

public class Program {

	public static void main(String[] args) {
			CacheAny<String> c1=new CacheAny<>();
			
			c1.setValue("hola");
			
			System.out.println(c1.getValue().charAt(0));
			
			
			
			
	}

}
