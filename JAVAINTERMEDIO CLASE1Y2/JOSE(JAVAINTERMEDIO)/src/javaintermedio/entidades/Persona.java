package javaintermedio.entidades;

public class Persona {
		private String nombre,apellido;
		
		public Persona(String apellido,String nombre)
		{
			this.apellido=apellido;
			this.nombre=nombre;
		}
		
		public Persona()
		{
			
		}
		public String getNombre()
		{
			return this.nombre;
		}
		
		public void setNombre(String nombre)
		{
			this.nombre=nombre;
		}
		
		public String getApellido()
		{
			return this.apellido;
		}
		
		public void setApellido(String apellido)
		{
			this.apellido=apellido;
		}
		
}
