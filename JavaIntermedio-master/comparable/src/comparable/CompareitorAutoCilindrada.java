package comparable;
import java.util.Comparator;
//38:00
public class CompareitorAutoCilindrada implements Comparator<Auto> {
	public int compare(Auto a1,Auto a2)
	{
		//4000
		return (int)((a1.getCilindrada()*10)-(a2.getCilindrada()*10));
	}
}
