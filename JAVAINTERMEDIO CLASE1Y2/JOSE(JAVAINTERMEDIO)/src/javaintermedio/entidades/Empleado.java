package javaintermedio.entidades;

public class Empleado extends Persona{
			private String email;
			public Empleado(String nombre,String apellido/*,String email*/)
			{
				super(nombre,apellido);//si no tieneste
				
				this.email=nombre.toLowerCase()+"."+apellido.toLowerCase()+"@java.com";
				//super();
			}
			
			public String toString()
			{
				String r="Nombre:"+super.getNombre()+"\nApellido:"+super.getApellido()+"\nEmail:"+this.email;
				return r;
			}
			
			
}
