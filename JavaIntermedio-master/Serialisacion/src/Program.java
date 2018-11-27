import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;

//import com.sun.java_cup.internal.runtime.Scanner;



public class Program {
	
	 static Scanner  sc=new Scanner(System.in); 
	
	public static void main(String[] args) throws ClassNotFoundException {
			String g ="este texto lo voy a guardar en el disco rigido";
			int opcion;
			
			
			
			ImprimirMenu();
			opcion=sc.nextInt();
			sc.nextLine();
			
			switch(opcion)
			{
			case 1:
				System.out.println("ingresar dato");
				g=sc.nextLine();

				try
				{
					
					OutputStream fos=new FileOutputStream("C:/Users/lenovo/Desktop/prueba/sasasa.txt");
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
				
				break;
			case 2:
				
				
				break;
			case 3:
				try
				{
					String recupero;
				ObjectInputStream ios=new ObjectInputStream(new FileInputStream("C:/Users/lenovo/Desktop/prueba/sasasa.txt"));
					recupero=(String)ios.readObject();
					//g=(String)ios.readObject();
					System.out.println(recupero);
				}
				catch(FileNotFoundException e)
				{
					e.printStackTrace();
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
				break;
			case 4:
				break;
				
			
			}
			
			
			
			
	}
	
	public static void ImprimirMenu()
	{
		System.out.println("escribir");
		System.out.println("guardar");
		System.out.println("cargar");
		System.out.println("imprimir");
	}

}
