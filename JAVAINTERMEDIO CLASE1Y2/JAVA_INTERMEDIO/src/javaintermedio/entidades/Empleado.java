package javaintermedio.entidades;

import java.util.Date;

public class Empleado {
	private int id;/// por default estas variables son de modificador default
					/// amenos q le pongas ej:private o public
	private String nombre = "";
	private float salario;

	// construtor por defecto siempre esta
	public Empleado(/**/String nombre, float salario) {
		super();// llama a la clase object
		this.id = (int) (Math.random() * 100000) * (int) (new Date()).getTime();
		// 2
		this.nombre = nombre;
		// 3
		this.salario = salario;
	}
	/*
	 * se usa por q una clase toda private Empleado() { super(); }
	 */
	// reglas
	// 1.el id del empleado se genera automaticamente y es un numero aleatorio
	// 2. el nombre no se cambia ,se puede leer y escribir
	// 3. el salario solo se puede subir

	public int getId() {
		return this.id;
	}

	// 2

	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public float getSalario() {
		return this.salario;
	}

	public void setSalario(float salario) {
		
		if(this.salario<salario)
		{
			this.salario = salario;
		}
		
	}
	
//	public bool comparar(float salario)
//	{
//		bool retorno=false;
//		
//		
//		
//		return retorno;
//		
//		
//	}
	
	
	
	
	
	
}
