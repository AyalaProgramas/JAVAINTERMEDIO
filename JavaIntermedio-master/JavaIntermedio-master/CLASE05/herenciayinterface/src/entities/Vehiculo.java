package entities;

public class Vehiculo {
	private String model;

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model;
	}
	
	public void fly()
	{
		System.out.println("piloto automatico");
	}
	
	public void takeoff()
	{
		System.out.println("motores al 100% y despego");
	}
	
	public void land()
	{
		System.out.println("le apunto a la pista y bajo");
	}
}
