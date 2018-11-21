import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.OutputStream;

import com.sun.java_cup.internal.runtime.Scanner;

public class Program {
	
	static Scanner  s=new Scanner(System.in); 
	
	public static void main(String[] args) {
			String g ="este texto lo voy a guardar en el disco rigido";
			try
			{
				OutputStream fos=new FileOutputStream("C:/Users/Alumno/Desktop/archivouno.fafa");
				ObjectOutputStream oos=new ObjectOutputStream(fos);
				oos.writeObject(g);
				
			}catch(FileNotFoundException e)
			{
				e.printStackTrace();
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}
			finally
			{
				
			}
			
			
	}
	
	public static void ImprimirMenu()
	{
		System.out.println("escribir");
		System.out.println("");
		System.out.println("");
		System.out.println("");
	}

}
