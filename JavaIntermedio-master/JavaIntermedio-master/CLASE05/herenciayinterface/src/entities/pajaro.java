package entities;
import interfaces.Interface;
public class pajaro extends Animal implements Interface {
		
	public void Sing()
	{
		System.out.println("canto lalalalalalaaaaalala");
	}
	
	public void fly()
	{
		
		System.out.println("mueve las alas");
	}
	
	public void takeoff()
	{
		System.out.println("pego un salto y muevo las alas");
	}
	
	public void land()
	{
		System.out.println("dejo de mover las  alas y caigo en una rama");
	}
}
