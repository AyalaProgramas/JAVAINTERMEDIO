package javaintermedio.program;
import javaintermedio.entidades.Empleado;
public class Program {

	public static void main(String[] args) {
			
		String nombre="lucas";
		String apellido="arnoso";
		String email="";
		
		//email=nombre+"."+apellido+"@java.com";
		Empleado e1=new Empleado(nombre,apellido/*,email*/);
		
		System.out.println(e1);
		
	}

}
