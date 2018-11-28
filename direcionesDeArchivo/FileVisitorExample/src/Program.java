import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
public class Program {

	public static void main(String[] args) {
		/*Path p1=Paths.get("bin/archivo.txt");
		System.out.println(p1);
		/***/
		Path p2=Paths.get("A");
		EjemploFileVisitor v = new EjemploFileVisitor();
		
		try
		{
			Files.walkFileTree(p2, v);
		}catch(IOException e)
		{
			e.printStackTrace();
		}
		
	}

}
