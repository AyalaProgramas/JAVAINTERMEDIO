package archivos;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Program {

	public static void main(String[] args) {
			
//		try
//		{
//			FileInputStream littlefile=new FileInputStream("");
//			leerCompleto(littlefile);
//			
//			
//		}catch()
		
		int =0;
		try
		{
			OutputStream os=new FileOutputStream("ddd");
			for(i=97;;)
		}
		catch()
		{
			
		}
		
		
	}
	
	public static void leerCompleto(FileInputStream fis)
	{
		try
		{
			while(fis.available()>0)
			{
				System.out.println(fis.read());
				
			}
		}catch (IOException e)
		{
			e.printStackTrace();
		}
	}

}
