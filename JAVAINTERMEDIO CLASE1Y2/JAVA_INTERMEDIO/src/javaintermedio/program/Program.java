package javaintermedio.program;
import javax.swing.plaf.synth.SynthStyle;

import javaintermedio.entidades.Empleado;
public class Program {

	public static void main(String[] args) {
		
		Empleado e1=new Empleado("pepe",15000F);
		
		System.out.println(e1.getSalario());
		e1.setSalario(1499);
		System.out.println(e1.getSalario());
		e1.setSalario(20000);
		System.out.println(e1.getSalario());
	}

}
